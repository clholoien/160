.globl Main

Main:
pushl %ebp
movl %esp, %ebp
subl $0, %esp 
pushl $0 
popl %eax
movl %ebp, %esp
popl %ebp 
ret 
