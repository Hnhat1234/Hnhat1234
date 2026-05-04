section .text
    global _start
	
_start:
    xor rax, rax
	mov rbx, 2096806868855654633473938916599855
	push rbx 
	mov rdi, rsp 
	xor rsi, rsi 
	xor rdx, rdx 
	mov rax, 0x2
	syscall
	
	
	mov rdx, 128
	mov rdi, rax
	mov rsi, rsp 
	xor rax, rax
	syscall
	
	
	mov rdx, 128
	mov rdi, rax
	mov rsi, rsp 
	syscall
	
	
	
	
	