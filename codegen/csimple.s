.globl Main

Main:
pushl %ebp
movl %esp, %ebp
subl $4, %esp 
pushl $5 
popl %eax 
movl %eax, -4(%ebp)
pushl -4(%ebp) 
popl %eax
movl %ebp, %esp
popl %ebp 
ret 
