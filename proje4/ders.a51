Org 08h
mov DPTR,#sayigoster
movc a,@a + DPTR
MOV p1,a
sayigoster: DB 3FH,0BH,05H,04H,6BH,6DH,7DH,07H,7FH,6FH,77H,7CH,39H,5EH,79H,71H