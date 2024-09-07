org 00h
sjmp basla
org 0Bh
sjmp timer1
org 13h
sjmp kesme1
basla: mov tmod,#10010000b
mov dptr,#15535d
mov tl1,dpl
mov th1,dph
setb ex1
setb it1
setb et1
setb ea
setb pt1
clr p2.0
clr p2.1
setb tr1
clr 00h
kesme1:mov tl1,dpl
mov th1,dph
jnb 00h,uygun
clr 00h
setb p2.1
clr p2.1
reti
uygun:setb p2.0
clr p2.0
reti
timer1:setb 00h
reti
end






;org 00h
;sjmp basla
;org 13h
;sjmp kesme1
;basla: mov tmod,#10010000b ;harici start\top timer1;16 bit timer ayari
;mov tl1,#00h
;mov th1,#00h
;setb ex1
;setb ea
;clr p2.0
;clr p2.1
;setb tr1
;mov dptr,#50000d ;50 ms degeri
;mov 40h,dpl
;mov 41h,dph
;x:sjmp x
;kesme1 : mov 42h,tl1
;mov a,th1
;mov tl1,#00h
;mov th1,#00h
;cjne a,41h,x1
;mov a,42h
;cjne a,42h,x1
;uygun:setb p2.0
;clr p2.0
;reti
;x1: jc uygun
;hata:setb p2.1
;clr p2.1
;reti 
;end
