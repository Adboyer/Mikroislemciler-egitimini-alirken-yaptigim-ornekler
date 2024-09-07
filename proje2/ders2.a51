Org 00h
sjmp XX1

XX1:
mov r0,#FFh;RAM sifirlama
mov a,#00h
tekrar:mov @r0,a
djnz r0,tekrar 

XX2:mov a,p1
mov 00h,p2
mov @r0,a;dolayli adresleme r0 in gösterdigi adrese akümülatörün içerigini yaz
mov p3,a
sjmp XX2

end
