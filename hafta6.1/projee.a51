org 00h
sjmp basla
org 0Bh
sjmp timer0
basla: mov tmod, #00000001b ; 16bit, zamanlayici0 ayari
mov dptr,#65530d;65535-1000
mov th0,dph
mov tl0,dpl
mov ie,#130d
;setb et0
;setb ea
setb tr0
x: sjmp x
timer0:cpl p2.0
mov tl0,dpl
mov th0,dph
reti;
end