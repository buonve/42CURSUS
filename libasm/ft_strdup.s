;char	*ft_strdup(char *src)
;{
;	char *dst;
;
;	dst = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
;	if (!dst)
;		return (0);
;	ft_strcpy(dst, src);
;	return (dst);
;}

		section .text
		global _ft_strdup
		extern _malloc
		extern _ft_strcpy
		extern _ft_strlen
		extern ___error

_ft_strdup:
		mov rax, 0					; azzero rax
		cmp rdi, 0					; controllo che la stringa non sia vuota
		je _return					; se lo e' esco e ritorno 0
		call _ft_strlen				; chiamo strlen mandandogli rdi
		push rdi					; salvo rdi sul top della stack
		mov rdi, rax				; do il valore di ritorno di strlen a rdi
		inc rdi						; aumento di uno il valore di rdi (aggiungo l'endoffile)
		call _malloc				; alloco mandando la quantita' rdi
		cmp rax, 0					; comparo rax di ritorno da malloc con 0
		je _errore					; se ritorna, 0 balzo ad errore
		mov rdi, rax				; sposto rax di ritorno da malloc in rdi
		pop rsi						; prendo il vecchio rdi dal top della stack e lo salvo in rsi
		call _ft_strcpy				; chiamo strcpy con rsi e rdi appena ottenuti
		mov rax, rdi
		ret							; ritorno.

_errore:
		mov r10, 12				; codice errore ENOMEM(cannot allocate memory) dentro r10
		call ___error			; mette indirizzo di errno in rax
		mov [rax], r10
		mov rax, 0
		ret

_return:
		mov rax, 0
		ret
		