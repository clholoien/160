.globl Main

Main:
pushl %ebp
movl %esp, %ebp
subl $12, %esp 
pushl $1 
popl %eax 
movl %eax, -8(%ebp)
popl %eax 
movl %eax, -8(%ebp)
popl %eaxpushl 0(%eax)popl %eax 
movl %eax, -4(%ebp)
pushl $0 
popl %eax 
movl %eax, -12(%ebp)
pushl -12(%ebp) 
popl %eax 
movl %eax, 4(%ebp)
pushl -12(%ebp) 
popl %eax
movl %ebp, %esp
popl %ebp 
ret 
