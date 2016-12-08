#include <cassert>
#include <typeinfo>
#include <string.h>

#include "ast.hpp"
#include "symtab.hpp"
#include "primitive.hpp"
#include "string"

using namespace std;


//This is going to be a hard project
class Codegen : public Visitor
{
  private:
    FILE* m_outputfile;
    SymTab *m_st;

    // Basic size of a character in bytes
    static const int char_size = 1;

    // Basic size of a word (integers and booleans) in bytes
    static const int wordsize = 4;

    int label_count; // Access with new_label

    // Helpers
    // This is used to get new unique labels (cleverly names label1, label2, ...)
    int new_label()
    {
        return label_count++;
    }

    void set_text_mode()
    {
        fprintf(m_outputfile, ".text\n\n");
    }

    void set_data_mode()
    {
        fprintf(m_outputfile, ".data\n\n");
    }

    // PART 1:
    // 1) get arithmetic expressions on integers working:
    //  you wont really be able to run your code,
    //  but you can visually inspect it to see that the correct
    //  chains of opcodes are being generated.
    // 2) get procedure calls working:
    //  if you want to see at least a very simple program compile
    //  and link successfully against gcc-produced code, you
    //  need to get at least this far
    // 3) get boolean operation working
    //  before we can implement any of the conditional control flow
    //  stuff, we need to have booleans worked out.
    // 4) control flow:
    //  we need a way to have if-elses and while loops in our language.
    // 5) arrays: just like variables, but with an index

    // Hint: the symbol table has been augmented to track an offset
    //  with all of the symbols.  That offset can be used to figure
    //  out where in the activation record you should look for a particuar
    //  variable


    ///////////////////////////////////////////////////////////////////////////////
    //
    //  function_prologue
    //  function_epilogue
    //
    //  Together these two functions implement the callee-side of the calling
    //  convention.  A stack frame has the following layout:
    //
    //                         <- SP (before pre-call / after epilogue)
    //  high -----------------
    //       | actual arg 1  |
    //       |    ...        |
    //       | actual arg n  |
    //       -----------------
    //       |  Return Addr  |
    //       =================
    //       | temporary 1   | <- SP (when starting prologue)
    //       |    ...        |
    //       | temporary n   |
    //   low ----------------- <- SP (when done prologue)
    //
    //
    //              ||
    //              ||
    //             \  /
    //              \/
    //
    //
    //  The caller is responsible for placing the actual arguments
    //  and the return address on the stack. Actually, the return address
    //  is put automatically on the stack as part of the x86 call instruction.
    //
    //  On function entry, the callee
    //
    //  (1) allocates space for the callee's temporaries on the stack
    //
    //  (2) saves callee-saved registers (see below) - including the previous activation record pointer (%%ebp)
    //
    //  (3) makes the activation record pointer (frmae pointer - %%ebp) point to the start of the temporary region
    //
    //  (4) possibly copies the actual arguments into the temporary variables to allow easier access
    //
    //  On function exit, the callee:
    //
    //  (1) pops the callee's activation record (temporay area) off the stack
    //
    //  (2) restores the callee-saved registers, including the activation record of the caller (%%ebp)
    //
    //  (3) jumps to the return address (using the x86 "ret" instruction, this automatically pops the
    //      return address off the stack
    //
    //////////////////////////////////////////////////////////////////////////////
    //
    // Since we are interfacing with code produced by GCC, we have to respect the
    // calling convention that GCC demands:
    //
    // Contract between caller and callee on x86:
    //    * after call instruction:
    //           o %%eip points at first instruction of function
    //           o %%esp+4 points at first argument
    //           o %%esp points at return address
    //    * after ret instruction:
    //           o %%eip contains return address
    //           o %%esp points at arguments pushed by caller
    //           o called function may have trashed arguments
    //           o %%eax contains return value (or trash if function is void)
    //           o %%ecx, %%edx may be trashed
    //           o %%ebp, %%ebx, %%esi, %%edi must contain contents from time of call
    //    * Terminology:
    //           o %%eax, %%ecx, %%edx are "caller save" registers
    //           o %%ebp, %%ebx, %%esi, %%edi are "callee save" registers
    ////////////////////////////////////////////////////////////////////////////////


    void emit_prologue(SymName *name, unsigned int size_locals, unsigned int num_args)
    {
      //use the name as a label in the output file
      fprintf(m_outputfile, "%s:\n", strdup(name->spelling())); 
      //Save base stack pointer on stack.
      fprintf(m_outputfile, "pushl %%ebp\n");
      //adjust stack pointer
      fprintf(m_outputfile, "movl %%esp, %%ebp\n");
      //allocaated space for local variabls/arguments
      fprintf(m_outputfile, "subl $%d, %%esp \n", size_locals);

      int arg_offset = 0;
      //put arguments in a stack formation
      for(int i = 0; i < num_args; i++){
        arg_offset = (i+1)*4;
        fprintf(m_outputfile, "movl %d(%%ebp) %%eax\n", arg_offset + 4 );
        fprintf(m_outputfile, "movl %%eax -%d(%%ebp)\n", arg_offset);
      }
    }

    void emit_epilogue()
    {
      //reset stack pointer after function declaration
      fprintf(m_outputfile, "movl %%ebp, %%esp\n");
      //pull base stack pointer off the stack
      fprintf(m_outputfile, "popl %%ebp \n");
      //finish by return out.
      fprintf(m_outputfile, "ret \n");
    }

  // WRITEME: more functions to emit code

  public:

    Codegen(FILE* outputfile, SymTab* st)
    {
        m_outputfile = outputfile;
        m_st = st;
        label_count = 0;
    }

    void visitProgramImpl(ProgramImpl* p)
    {
      list<Proc_ptr>:: iterator procIter;
      char *procName;

      for(procIter = p->m_proc_list->begin(); procIter != p->m_proc_list->end(); procIter++){
        //get the name of the current procedure in the iteration.
        ProcImpl *proc = (ProcImpl*)(*procIter);
        procName = strdup(proc->m_symname->spelling());
        //store name of global procedures at the top of the program.
        fprintf(m_outputfile, ".globl %s\n", procName);
      }
      //print additional new line to seperate the globals from the rest of the definitions.
      fprintf(m_outputfile, "\n");

      //once all global procedures have been declared, visit all children.
      p->visit_children(this);
      
    }

    void visitProcImpl(ProcImpl* p)
    {
      //used to track how many 
      int num_params = 0;
      list<Decl_ptr>::iterator declIter;

      for(declIter = p->m_decl_list->begin(); declIter != p->m_decl_list->end(); declIter++){
        DeclImpl *decl = (DeclImpl*)(*declIter);
        num_params = (decl)->m_symname_list->size() + num_params;
      } 
      emit_prologue(p->m_symname, m_st->scopesize(p->m_attribute.m_scope), num_params);
      p->visit_children(this);
    
      emit_epilogue();
    }

    void visitProcedure_blockImpl(Procedure_blockImpl* p){
      p->visit_children(this);
    }
    void visitNested_blockImpl(Nested_blockImpl* p){
      p->visit_children(this);
    }

    void visitAssignment(Assignment* p)
    {
      //push the value to assign on the stack.
      p->m_expr->accept(this);
      //set value to the lhs.
      p->m_lhs->accept(this);

    }

    void visitCall(Call* p)
    {
      fprintf(m_outputfile, "pushl  %%ebp \n");        //save base pointer
      fprintf(m_outputfile, "movl   %%esp, %%ebp \n"); //set new base pointer
      fprintf(m_outputfile, "movl   0x0, %%eax \n");       
      fprintf(m_outputfile, "popl   %%ebp \n");
      fprintf(m_outputfile, "retl \n");

      fprintf(m_outputfile, "pushl  %%ebp \n"); //save base pointer
      fprintf(m_outputfile, "movl   %%esp, %%ebp \n"); //set new base pointer
      fprintf(m_outputfile, "subl   0x10, %%esp \n");//creates room for local variable

      //WILL NEED A METHOD TO SEE HOW MANY PARAMETERS ARE IN METHOD CALL.
      fprintf(m_outputfile, "pushl  0x8 \n"); //save parameter on stack
      fprintf(m_outputfile, "pushl  0x6 \n"); //save parameter on stack

      //ADD FUNTIONALITY TO PUT SYMNAME OF PROCEDURE IN WHERE "foo" IS.
      fprintf(m_outputfile, "call  80483db foo"); // CALL function calls parameter on stack
      fprintf(m_outputfile, "addl  0x8, %%esp \n"); //clean the stack
      fprintf(m_outputfile, "mov  %%eax, -0x4(%%ebp) \n"); //store the return value in variable a.
      fprintf(m_outputfile, "mov  $0x0, %%eax \n"); 
      fprintf(m_outputfile, "leave \n");
      fprintf(m_outputfile, "ret \n");
    }

    void visitReturn(Return* p)
    {
      p->visit_children(this);
      //pop off return.
      fprintf(m_outputfile, "popl %%eax\n");
    }

    // Control flow
    void visitIfNoElse(IfNoElse* p)
    { 
      //place boolean expression onto the stack
      p->m_expr->accept(this);

      //visit children already sccepts all chilodren...
      int cond = new_label();
      
      fprintf(m_outputfile, "if_%d: \n", cond); //create if label
      fprintf(m_outputfile, "popl %%eax"); //place boolean value into var a
      fprintf(m_outputfile, "movl $0 %%ebx \n"); //place zero into var b
      fprintf(m_outputfile, "cmp %%eax, %%ebx \n"); //compare variable with false

      fprintf(m_outputfile, "je end_%d \n", cond); //if false then jump to end.
        p->m_nested_block->accept(this);
      fprintf(m_outputfile, "end_%d: \n", cond); //create end label for if with else statement.
    }

    void visitIfWithElse(IfWithElse* p)
    {
      //place boolean expression onto the stack.
      p->m_expr->accept(this);

      int cond = new_label();

      fprintf(m_outputfile, "if_%d: \n", cond); //create if label
      fprintf(m_outputfile, "popl %%eax"); //place boolean value into var a
      fprintf(m_outputfile, "movl $0 %%ebx \n"); //place zero into var b
      fprintf(m_outputfile, "cmp %%eax, %%ebx \n"); //compare variable with false

      fprintf(m_outputfile, "je else_%d \n", cond); //if false then jump to else.

        p->m_nested_block_1->accept(this);
      fprintf(m_outputfile, "j end_%d \n", cond); //if true jump to end

      fprintf(m_outputfile, "else_%d: \n", cond); //create else label
        p->m_nested_block_2->accept(this);

      fprintf(m_outputfile, "end_%d: \n", cond); //create end label for if with else statement.
      
    }

    void visitWhileLoop(WhileLoop* p)
    {
      //place boolean expression onto the stack.
      p->m_expr->accept(this);

      int loop = new_label();

      fprintf(m_outputfile, "while_%d: \n", loop); //create while loop label

      fprintf(m_outputfile, "popl %%eax"); //pop boolean variable off stack
      fprintf(m_outputfile, "movl $0 %%ebx \n"); //place zero into variable
      fprintf(m_outputfile, "cmp %%eax, %%ebx \n"); //compare variable with false

      fprintf(m_outputfile, "je end_%d \n", loop); //if false then end.

        p->m_nested_block->accept(this);
      fprintf(m_outputfile, "j while_%d \n", loop); //if true, jump to while label
      fprintf(m_outputfile, "end_%d \n", loop); //create label for when loop is finished.
    }

    void visitCodeBlock(CodeBlock *p)
    {
      p->visit_children(this);
    }

    // Variable declarations (no code generation needed)
    void visitDeclImpl(DeclImpl* p)
    {
      p->visit_children(this);

    }

    void visitTInteger(TInteger* p){}
    void visitTIntPtr(TIntPtr* p){}
    void visitTBoolean(TBoolean* p){}
    void visitTCharacter(TCharacter* p){}
    void visitTCharPtr(TCharPtr* p){}
    void visitTString(TString* p){}

    // Comparison operations
    void visitCompare(Compare* p)
    {
       p->visit_children(this);

      int jump = new_label();
      int end = new_label();

      fprintf(m_outputfile, "popl %%eax \n");   //pop first expr off stack
      fprintf(m_outputfile, "popl %%ebx \n");   //pop second expr off stack
      fprintf(m_outputfile, "cmpl %%eax %%ebx \n"); //do comparision
      fprintf(m_outputfile, "je  Label%d \n", jump);   //jump if true
      fprintf(m_outputfile, "pushl $0\n");   //push 0 onto stack if false
      fprintf(m_outputfile, "jmp Label%d \n", end); //jump to the end if false.
      fprintf(m_outputfile, "L%d: \n", jump);   //Create label to jump to if true
      fprintf(m_outputfile, "pushl $1 \n");   //push 1 onto the stack if true
      fprintf(m_outputfile, "L%d: \n", end);   //Create label to end 

    }

    void visitNoteq(Noteq* p)
    {
       p->visit_children(this);

      int jump = new_label();
      int end = new_label();

      fprintf(m_outputfile, "popl %%eax \n");   //pop first expr off stack
      fprintf(m_outputfile, "popl %%ebx \n");   //pop second expr off stack
      fprintf(m_outputfile, "cmpl %%eax %%ebx \n"); //do comparision
      fprintf(m_outputfile, "jne  Label%d \n", jump);   //jump if true
      fprintf(m_outputfile, "pushl $0\n");   //push 0 onto stack if false
      fprintf(m_outputfile, "jmp Label%d \n", end); //jump to the end if false.
      fprintf(m_outputfile, "L%d: \n", jump);   //Create label to jump to if true
      fprintf(m_outputfile, "pushl $1 \n");   //push 1 onto the stack if true
      fprintf(m_outputfile, "L%d: \n", end);   //Create label to end 

    }

    void visitGt(Gt* p)
    {
       p->visit_children(this);

      int jump = new_label();
      int end = new_label();

      fprintf(m_outputfile, "popl %%eax \n");   //pop first expr off stack
      fprintf(m_outputfile, "popl %%ebx \n");   //pop second expr off stack
      fprintf(m_outputfile, "cmpl %%eax %%ebx \n"); //do comparision
      fprintf(m_outputfile, "jg  Label%d \n", jump);   //jump if true
      fprintf(m_outputfile, "pushl $0\n");   //push 0 onto stack if false
      fprintf(m_outputfile, "jmp Label%d \n", end); //jump to the end if false.
      fprintf(m_outputfile, "L%d: \n", jump);   //Create label to jump to if true
      fprintf(m_outputfile, "pushl $1 \n");   //push 1 onto the stack if true
      fprintf(m_outputfile, "L%d: \n", end);   //Create label to end 

    }

    void visitGteq(Gteq* p)
    {
       p->visit_children(this);

      int jump = new_label();
      int end = new_label();

      fprintf(m_outputfile, "popl %%eax \n");   //pop first expr off stack
      fprintf(m_outputfile, "popl %%ebx \n");   //pop second expr off stack
      fprintf(m_outputfile, "cmpl %%eax %%ebx \n"); //do comparision
      fprintf(m_outputfile, "jge  Label%d \n", jump);   //jump if true
      fprintf(m_outputfile, "pushl $0\n");   //push 0 onto stack if false
      fprintf(m_outputfile, "jmp Label%d \n", end); //jump to the end if false.
      fprintf(m_outputfile, "L%d: \n", jump);   //Create label to jump to if true
      fprintf(m_outputfile, "pushl $1 \n");   //push 1 onto the stack if true
      fprintf(m_outputfile, "L%d: \n", end);   //Create label to end 

    }

    void visitLt(Lt* p)
    {
       p->visit_children(this);

      int jump = new_label();
      int end = new_label();

      fprintf(m_outputfile, "popl %%eax \n");   //pop first expr off stack
      fprintf(m_outputfile, "popl %%ebx \n");   //pop second expr off stack
      fprintf(m_outputfile, "cmpl %%eax %%ebx \n"); //do comparision
      fprintf(m_outputfile, "jl  Label%d \n", jump);   //jump if true
      fprintf(m_outputfile, "pushl $0\n");   //push 0 onto stack if false
      fprintf(m_outputfile, "jmp Label%d \n", end); //jump to the end if false.
      fprintf(m_outputfile, "L%d: \n", jump);   //Create label to jump to if true
      fprintf(m_outputfile, "pushl $1 \n");   //push 1 onto the stack if true
      fprintf(m_outputfile, "L%d: \n", end);   //Create label to end 

    }

    void visitLteq(Lteq* p)
    {
      p->visit_children(this);

      int jump = new_label();
      int end = new_label();

      fprintf(m_outputfile, "popl %%eax \n");   //pop first expr off stack
      fprintf(m_outputfile, "popl %%ebx \n");   //pop second expr off stack
      fprintf(m_outputfile, "cmpl %%eax %%ebx \n"); //do comparision
      fprintf(m_outputfile, "jle  Label%d \n", jump);   //jump if true
      fprintf(m_outputfile, "pushl $0\n");   //push 0 onto stack if false
      fprintf(m_outputfile, "jmp Label%d \n", end); //jump to the end if false.
      fprintf(m_outputfile, "L%d: \n", jump);   //Create label to jump to if true
      fprintf(m_outputfile, "pushl $1 \n");   //push 1 onto the stack if true
      fprintf(m_outputfile, "L%d: \n", end);   //Create label to end 

    }

    // Arithmetic and logic operations
    void visitAnd(And* p)
    {
      p->visit_children(this);
      fprintf(m_outputfile, "popl %%eax \n");   //pop first expr off stack
      fprintf(m_outputfile, "popl %%ebx \n");   //pop second expr off stack
      fprintf(m_outputfile, "andl %%eax %%ebx \n"); //do operation
      fprintf(m_outputfile, "pushl %%ebx \n");  //push item back onto the stack
    }

    void visitOr(Or* p)
    {
      p->visit_children(this);
      fprintf(m_outputfile, "popl   %%eax \n");   //pop first expr off stack
      fprintf(m_outputfile, "popl   %%ebx \n");   //pop second expr off stack
      fprintf(m_outputfile, "orl    %%eax %%ebx \n"); //do operation
      fprintf(m_outputfile, "pushl  %%ebx \n");  //push item back onto the stack
    }

    void visitMinus(Minus* p)
    {
      p->visit_children(this);
      fprintf(m_outputfile, "popl   %%eax \n");   //pop first expr off stack
      fprintf(m_outputfile, "popl   %%ebx \n");   //pop second expr off stack
      fprintf(m_outputfile, "subl   %%eax %%ebx \n"); //do operation
      fprintf(m_outputfile, "pushl  %%ebx \n");  //push item back onto the stack
    }
    void visitPlus(Plus* p)
    {
      p->visit_children(this);
	    fprintf(m_outputfile, "popl %%eax \n");//pop first expr off stack
      fprintf(m_outputfile, "popl   %%ebx \n");//pop second expr off stack
      fprintf(m_outputfile, "addl   %%eax %%ebx \n"); //do operation
      fprintf(m_outputfile, "pushl  %%ebx \n"); //push item back onto the stack
    }
    void visitTimes(Times* p)
    {
      p->visit_children(this);
      fprintf(m_outputfile, "popl   %%eax \n");//pop first expr off stack
      fprintf(m_outputfile, "popl   %%ebx \n");//pop second expr off stack
      fprintf(m_outputfile, "imul  %%eax %%ebx \n"); //do operation
      fprintf(m_outputfile, "pushl  %%ebx \n"); //push item back onto the stack
    }
    void visitDiv(Div* p)
    {
      p->visit_children(this);
      fprintf(m_outputfile, "popl   %%eax \n");//pop first expr off stack
      fprintf(m_outputfile, "popl   %%ebx \n");//pop second expr off stack
      fprintf(m_outputfile, "idivl   %%eax %%ebx \n"); //do operation
      fprintf(m_outputfile, "pushl  %%ebx \n"); //push item back onto the stack
    }

    void visitNot(Not* p)
    {
      p->visit_children(this);
      fprintf(m_outputfile, "popl   %%eax \n");//pop first expr off stack
      fprintf(m_outputfile, "notl   %%eax \n");//do operation
      fprintf(m_outputfile, "addl $2 %%eax"); //reset the negative offset.
      fprintf(m_outputfile, "pushl  %%eax \n"); //push item back onto the stack
    }

    void visitUminus(Uminus* p)
    {
      p->visit_children(this);
      fprintf(m_outputfile, "popl   %%eax \n");//pop first expr off stack
      fprintf(m_outputfile, "neg   %%eax \n"); //do operation
      fprintf(m_outputfile, "pushl  %%eax \n"); //push item back onto the stack
    }

    // Variable and constant access
    void visitIdent(Ident* p)
    {
      p->visit_children(this);

      //find the offset for the variable to assign to.
      Symbol *ident_sym = m_st->lookup(p->m_attribute.m_scope, p->m_symname->spelling());
      int ident_offset = ident_sym->get_offset();
      //int ident_size = ident_sym->get_size();

      //push value of identifier on stack 
      fprintf(m_outputfile, "pushl -%d(%%ebp) \n", ident_offset + 4);
    }

    void visitBoolLit(BoolLit* p)
    {
      //visit primitive node
      p->visit_children(this);
    }

    void visitCharLit(CharLit* p)
    {
      //visit primitive node
      p->visit_children(this);
    }

    void visitIntLit(IntLit* p)
    {
      //visit primitive node
      p->visit_children(this);
    }

    void visitNullLit(NullLit* p)
    {
      //NULL is represented as 0 in x86
      fprintf(m_outputfile, "pushl $0\n");
    }

    void visitArrayAccess(ArrayAccess* p)
    {

      //find the offset for the variable to assign to.
      Symbol *array_sym = m_st->lookup(p->m_attribute.m_scope, p->m_symname->spelling());
      int array_offset = array_sym->get_offset();
      int array_size = array_sym->get_size();

      //puts expression on stack
      p->m_expr->accept(this);
      // Pop expr off stack...
      fprintf(m_outputfile, "popl %%eax \n");
      // Convert index to bytes...
      fprintf(m_outputfile, "imul $%d, %%eax \n", char_size);
      // Place base pointer to our other variable to be used for the string assignment.
      fprintf(m_outputfile, "movl %%ebp, %%ebx \n");
      // set variable b to be pointing at the 0 cell of the array, with it's current size.
      fprintf(m_outputfile, "subl $%d, %%ebx \n", array_offset + array_size);
      //set the pointer to the location where we should index...
      fprintf(m_outputfile, "addl %%eax, %%ebx \n");
      //push item that is at this location onto the stack to be used.
      fprintf(m_outputfile, "push 0(%%ebx) \n");
    }

    // LHS
    void visitVariable(Variable* p)
    {
      //  var x, y :integer;
      //  x = y;
      Symbol *var_sym = m_st->lookup(p->m_attribute.m_scope, p->m_symname->spelling());
      int var_offset = var_sym->get_offset();
      int var_size = var_sym->get_size();

      if(var_sym->m_basetype!= bt_string){

        //variable is not a string.
        //pop value to assign to variable off the stack.
        fprintf(m_outputfile, "popl %%eax \n");
        //place the value in the locataion of the variable to assign.
        fprintf(m_outputfile, "movl %%eax, -%d(%%ebp)\n", var_offset + var_size);

      }else{
        //STRING PRIMITIVE NOT WORKING AT ALL

        //set second variable to base pointer
        fprintf(m_outputfile, "movl %%ebp %%ebx \n");
        // set variable b to be pointing at the 0 cell of the array, with it's current size.
        fprintf(m_outputfile, "subl $%d, %%ebx \n", var_offset + var_size);

        //used for a label in control flow.
        int label = new_label();
        fprintf(m_outputfile, "string_%d \n", label);

        fprintf(m_outputfile, "addl -$4,  %%ebx\n");
        //put a character into %eax
        fprintf(m_outputfile, "popl %%eax \n");

        //see if end of string was reached.
        fprintf(m_outputfile, "movl $0, %%ecx\n");  
        fprintf(m_outputfile, "cmp %%ecx, %%eax \n");
        fprintf(m_outputfile, "je end_%d",label);
        //else continue pushing string on.

        fprintf(m_outputfile, "movl %%eax, -%d(%%ebx) \n", var_offset);


        //set the pointer to the location where we should index...
        fprintf(m_outputfile, "addl %%eax, %%ebx \n");
        //push item that is at this location onto the stack to be used.
        fprintf(m_outputfile, "movl %%0(%%ebx) \n");
        fprintf(m_outputfile, "end_%d\n", label);        
      }
    }

    void visitDerefVariable(DerefVariable* p)
    { 
      //  var x: intptr;
      //  var y : integer;  
      //  ^x = y

      Symbol *var_sym = m_st->lookup(p->m_attribute.m_scope, p->m_symname->spelling());
      int var_offset = var_sym->get_offset() + 4;

      //pop value to assign to variable off the stack.
      fprintf(m_outputfile, "popl %%eax \n");

      //place the value in the locataion of the variable to assign.
      fprintf(m_outputfile, "movl %%eax, %d(%%ebp)\n", var_offset);
    }

    void visitArrayElement(ArrayElement* p)
    {
      //  var s: string[5];
      //  s[2] = 'b';

      Symbol *array_sym = m_st->lookup(p->m_attribute.m_scope, p->m_symname->spelling());
      // FIGURE OUT IF PLUS 4 SHOULD HAPPEN.
      int array_offset = array_sym->get_offset() + 4;

      //pop value to assign to variable off the stack.
      fprintf(m_outputfile, "popl %%eax \n");

      //find the index
      p->m_expr->accept(this);
      fprintf(m_outputfile, "popl %%ebx \n");
      //put index into byte form.
      fprintf(m_outputfile, "imul $4 %%ebx \n");

      //get location where string starts in memory.
      fprintf(m_outputfile, "movl %%ebp %%ecx \n");
      fprintf(m_outputfile, "subl $%d %%ecx \n", array_offset);
      //add
      fprintf(m_outputfile, "subl %%ecx %%ebx \n");
      //place the value in the locataion of the variable to assign.
      fprintf(m_outputfile, "movl %%eax, $0(%%ebx)\n");
    }

    // Special cases
    void visitSymName(SymName* p)
    { 
    }

    void visitPrimitive(Primitive* p)
    {
      //push data ont stack to be used later.
      fprintf(m_outputfile, "pushl $%d \n", p->m_data);
    }

    // Strings
    void visitStringAssignment(StringAssignment* p)
    {
      //place string onto the stack.
      p->m_stringprimitive->accept(this);

      p->m_lhs->accept(this);

    }
    void visitStringPrimitive(StringPrimitive* p)
    {
      //push string onto the stack
      string input_string = "";
      string cur_char = "";
      fprintf(m_outputfile, "pushl $0 \n");

      //push string prim onto stack in reverse order.
      for(int i = 0; i >= strlen(p->m_string); i++){
        fprintf(m_outputfile, "pushl  %c \n", p->m_string[strlen(p->m_string)- 1 - i ]);
      }
    }

    void visitAbsoluteValue(AbsoluteValue* p)
    {
      p->visit_children(this);

      if (p->m_attribute.m_basetype == bt_integer){
        //print the return positive value of integer in codegen.
        //check if the integer is negative, if so then return the positive version.
	
      }
      else{
        //print size of string.
        
      }
    }
      
    // Pointer
    void visitAddressOf(AddressOf* p)
    {
      fprintf(m_outputfile, "popl %%eax");
      fprintf(m_outputfile,"pushl 0(%%eax)");

    }

    void visitDeref(Deref* p)
    {
      p->visit_children(this);
      fprintf(m_outputfile, "popl %%eax");
      fprintf(m_outputfile,"pushl 0(%%eax)");
    }
};


void dopass_codegen(Program_ptr ast, SymTab* st)
{
    Codegen* codegen = new Codegen(stdout, st);
    ast->accept(codegen);
    delete codegen;
}
