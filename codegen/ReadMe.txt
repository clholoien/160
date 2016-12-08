Carson Holoien
8549677
Compilers Fall 2016

What is currently working:
     -All operations between expressions
     -Procedure calls with and without arguments
     -Variable assignment

What is Not working:
     -Anything to do with strings
     -Variable Deref
     -Address of

Starting from the begining 
emit_prologue():
	-uses the name as a label in the output file 
	-Save base stack pointer on stack.
	-allocates space for local variabls/arguments
  -put arguments in a stack formation

emit_epilogue():
	-reset stack pointer after function declaration
	-pull base stack pointer off the stack
	-finish by return out.

visitProgramImpl():
	-iterates over each of the procedures  
	-adds all procedures to the .globl list.
	-once the space has been allocated visit all children of the program.

visitProcImpl():
	-iterate over each of the the declarations and allocate space by calling emit_prologue.
	-then visiting all the children of the procedure, followed by emit epilogue to close out the procedure.

visitProcedure_blockImpl():
	-simply call visit children

visitNested_blockImpl():
	-simply call visit children

visitCall():
	-iterate over each of the expressions and call accept to push them onto the stack.
	-count how many expressions there are, and multiply by 4 to give the value in bytes.
	-accept the left hand side to then set the lhs to the return of call

visitReturn():
	-visits it's children 
	-simply pops eax off the stack

visitIfNoElse():
	-place boolean expression onto the stack
	-create if label
	-place boolean value into var a
	-place zero into var b
	-compare variable with false
	-if false then jump to end.
	-create end label for if with else statement.

visitIfWithElse():
	-place boolean expression onto the stack.
	-create if label
	-place boolean value into var a
	-place zero into var b
	-compare variable with false
	-if false then jump to else.
	-if true jump to end
	-create else label
	-create end label for if with else statement.

visitWhileLoop():
	-place boolean expression onto the stack.
	-create while loop label
	-pop boolean variable off stack
	-place zero into variable
	-compare variable with false
	-if false then end.
	-if true, jump to while label
	-create label for when loop is finished.

visitCodeBlock():
	-simply calls visit children

visitDeclImpl():
	-simply calls visit children

visitCompare(), visitNoteq(), visitGt(), visitGteq(), visitLt(), visitLteq():
	-pop first expr off stack
	-pop second expr off stack
	-do comparision
	-jump if true
	-push 0 onto stack if false
	-jump to the end if false.
	-Create label to jump to if true
	-push 1 onto the stack if true
	-Create label to end 

visitAnd(), visitOr(), visitMinus(), visitPlus(), visitTimes(), visitDiv():
	-pop first expr off stack
	-pop second expr off stack
	-do operation
	-push item back onto the stack

visitNot():
	-pop first expr off stack
	-do operation
	-push item back onto the stack

visitIdent():
	-find the offset for the variable to assign to.
	-push value of identifier on stack 

visitArrayAccess():
	-find the offset for the variable to assign to.
	-compute expression for index and on stack
	-Pop expr off stack...
	-Convert index to bytes
	-Place base pointer to our other variable to be used for the string assignment.
  -set variable b to be pointing at the 0 cell of the array, with it's current size.
  -set the pointer to the location where we should index...
  -push item that is at this location onto the stack to be used.
 
 visitVariable():
 	-lookup up variable and get the offset and size
 	-if the variable is not a string
 		-pop value to assign to variable off the stack.
 		-place the value in the locataion of the variable to assign.
 	-else
 		-set second variable to base pointer
 		-set variable b to be pointing at the 0 cell of the array, with it's current size.
 		-label used for a control flow in for loop to do string assign.
 		-foreach char in the string set it to %eax and place it into the location of the stack where the variable is located.
 		-during the loop look for the null termintor, and exit if found.
 		- place null terminator at the end of this newly added string.

visitDerefVariable():
 	-lookup up variable and get the offset and size
 	-pop value to assign to variable off the stack.
 	-place the value in the locataion of the variable to assign.

visitArrayElement():
	-lookup up variable and get the offset and size
	-pop value to assign to variable off the stack.
	-find the index
	-put index into byte form.
	-get location where string starts in memory.
	-place the value in the locataion of the variable to assign.

visitPrimitive():
	-push data ont stack to be used later.

visitStringAssignment():
	-place the string primitive on the stack, by calling accept on m_stringprimitive
	-place it into a string variable, by calling accept on lhs.

visitStringPrimitive():
	-push string onto the stack in reverse order
	-and start this by pushing the null determinator onto the stack.

visitAbsoluteValue():
	-check if the value is negative
	-if not then just return the value
	-if it is then multiply by 1.

visitAddressOf():
	-lookup the variable from the symbol table with the offset
	-push the address onto the stack

visitDeref():
	-accept the expression to get rhs value
	-push the actual value of the address onto the stack

	




