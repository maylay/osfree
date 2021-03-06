/*
    This file is part of SUPPL - the supplemental library for DOS
    Copyright (C) 1996-2000 Steffen Kaiser

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
/* $RCSfile$
   $Locker$	$Name$	$State$

ob(ject): longsubu
su(bsystem): longmath
ty(pe): A
sh(ort description): Subtract an unsigned 16bit integer from a 32bit number
lo(ng description): 
pr(erequistes): 
va(lue): none; \tok{num := num - (unsigned)n}
re(lated to): longsub longsubi
se(condary subsystems): portable
in(itialized by): 
wa(rning): 
bu(gs): 
co(mpilers): A function for non-32bit-aware compilers, a macro otherwise.

*/

#include "initsupl.loc"

#ifdef _MICROC_

#include "suppl.h"

#include "suppldbg.h"

#ifdef RCS_Version
static char const rcsid[] = 
	"$Id: longsubu.c 1210 2006-06-17 03:25:06Z blairdude $";
#endif

void longsubu(/*dword **/num, /*unsigned*/ n)
{	assert(num);
	LSIZE / 2;
	asm {
		mov cx, ax
		mov bx, 6[bp]		; address of number
		mov ax, 4[bp]		; number to subtract from
		sub [bx], ax
		mov ax, 0
		jnc addu1			; no overflow
		inc bx
	addu2:
		inc bx
		dec Byte Ptr [bx]	; sub carry
		mov al, [bx]
		inc al
		loope addu2
		jne addu1			; no overflow?
		inc al				; overflow
	addu1:
	}
}
#endif
