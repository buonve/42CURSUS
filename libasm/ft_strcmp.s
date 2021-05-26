;int		ft_strcmp(char *s1, char *s2)
;{
;	int index;
;
;	index = 0;
;	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
;	{
;		index++;
;	}
;	return (s1[index] - s2[index]);
;}


		section .text
		global _ft_strcmp

_ft_strcmp:
		xor rax, rax				; azzero index


_compare:
		mov r10b, BYTE[rdi] 		; salvo src char in temp var 1
		mov r11b, BYTE[rsi]			; salvo dst char in temp var 2
		cmp r10b, 0					; comparo il char con 0
		je _return					; se e' uguale a zero vai a return
		cmp r11b, 0					; compraro il char con 0
		je _return					; se e' uguale a zero vai a return
		cmp r10b, r11b				; comparo le due var temporanee				
		jne _return					; se sono uguali vado al ritono per la sottrazione
		inc rdi						; aumento dest
		inc rsi						; aumento src
		jmp _compare				; ricomincio il ciclo

_return:
		movzx rax, r10b 			; copia un registro di grandezza inferiore(r10b) in uno di grandezza superiore(rax), fillando il resto dei bit con 0
		movzx rbx, r11b				; stessa cosa di sopra per rbx
		sub rax, rbx				; sottraggo source da dest
		ret							; ritorno rax

