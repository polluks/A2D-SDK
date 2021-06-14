        .include "config.inc"
	.include "inc/apple2.inc"
	.include "inc/macros.inc"
	.include "mgtk/mgtk.inc"
	.include "common.inc"
	.include "desktop/desktop.inc"

        .importzp sp
	.import _main_da
        .export _call_mgtk
	.import __MAIN_START__, __MAIN_LAST__, __HIMEM__

	.segment "LOADER"

;;; ============================================================
;;; Start of the code

main:  jmp     copy2aux

save_stack:  .byte   0

;;; ============================================================
;;; Duplicate the DA (code and data) to AUX memory,
;;; then invoke the code in AUX.

	.proc copy2aux
	tsx
	stx     save_stack

        lda     #<__HIMEM__
        ldx     #>__HIMEM__

        ; Set up the C stack.
        sta     sp
        stx     sp + 1

	;; Copy the DA to AUX memory.
	copy16  #__MAIN_START__, STARTLO
	copy16  #__MAIN_LAST__, ENDLO
	copy16  #__MAIN_START__, DESTINATIONLO
	sec                     ; main>aux
	jsr     AUXMOVE

	;; Fall through
	.endproc

	.proc init_da
	;; Run DA from Aux
	sta     RAMRDON
	sta     RAMWRTON

	jsr     _main_da
	.endproc

	.proc exit_da
	;; Return to DeskTop running in Main
	sta     RAMRDOFF
	sta     RAMWRTOFF

	ldx     save_stack
	txs
	rts
	.endproc

	.proc _call_mgtk
        sta low
        stx high
        ldy #0
        lda (sp), y
        sta code
        jsr $4000
code:   .byte $00
low:    .byte $01
high:   .byte $02
        rts
	.endproc
