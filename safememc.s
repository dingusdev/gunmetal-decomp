safememc 
	PUSH       EAX
	PUSH       EBX
	PUSH       ECX
	PUSH       EDX
	PUSH       ESI
	PUSH       EDI
	PUSH       EBP
	MOV        EDI,dword ptr [ESP + param_1]
	MOV        ESI,dword ptr [ESP + param_2]
	MOV        ECX,dword ptr [ESP + param_3]
	PUSH       ES
	PUSH       DS
	POP        ES
	PUSH       ECX
	SHR        ECX,0x2
	MOVSD.REP  ES:EDI,ESI
	POP        ECX
	AND        ECX,0x3
	MOVSB.REP  ES:EDI,ESI
	POP        ES
	POP        EBP
	POP        EDI
	POP        ESI
	POP        EDX
	POP        ECX
	POP        EBX
	POP        EAX
	RET
