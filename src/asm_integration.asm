section .text
    global rotate_left

; Funcția rotate_left: rotește bitwise la stânga o valoare pe 32 de biți
; Parametri:
; - ip (în registrul eax): valoarea de rotit (un uint32_t)
; - bits (în registrul cl): numărul de biți cu care să se rotească
; Returnează:
; - eax: valoarea rotită
rotate_left:
    ; Intrare: eax = ip, cl = bits
    rol eax, cl        ; rotește eax la stânga cu valoarea specificată în cl
    ret                ; returnează valoarea rotită în eax
