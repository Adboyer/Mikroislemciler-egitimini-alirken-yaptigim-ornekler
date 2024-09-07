;p0  portunu s�rekli tara , p0 portunda deger ff den farkli ise subrout u �agir degeri 10d ile �arp  p1 yaz
;	org 00h
;	again:
;		mov p0,#0ffh
;	loop: 
;		mov a,p0
;		cjne a,#0ffh,dat
;		sjmp loop
;	dat:
;		acall multi
;		sjmp again
;	multi:
;		mov b,#10d
;		mul ab
;		mov p1,a
;		ret
;	end

;;-----------------------------------------------------------------------------------------
;;int 1 gelenleri saysin ,saya� tasdiginda dursun ve kesmeyi devre disi biraksin
;org 00h
;	mov r2,#00h
;	mov ie,#84h
;here: sjmp here
;	Org 0013h
;	inc r2
;	cjne r2,#00h,out
;	mov ie,#00h
;	clr p0.0
;	out:reti
;	



;;-----------------------------------------------------------------------------------------
;100h-200h arasindaki degerlerin 
;r2 den b�y�k
;r3 den k���k olan sayi var ise r4 1 arttir
;org 00h
;	mov dptr,#0100h
;	mov r7,#0ffh ;counter sonu sayacin sonu
;	mov r4,#00h ;sonu� ka� tane var ise "saya�"
;	mov 20h,r2 ;alt limit
;	mov 21h,r3 ;�st limit
;devam:  
;	movx a,@dptr
;	cjne a,21h,lower
;	sjmp out
;lower: 			;�st limit kontrol�
;	clr c
;	subb a,21h
;	jnc out
;	cjne a,20h,limit
;	sjmp out
;limit: 			;alt limit kontrol�
;	clr c
;	subb a,20h ;elde olmamali olursa jc ile �ikicak
;	jc out
;	inc r4 ;elde yok ise bir attir
;out:
;	inc dptr 
;	djnz r7,devam ;sonunu da bir azalt
;end



;-----------------------------------------------------------------------------------------
;10h-20h ve 20h-30h araliklarindaki degerlerin ka� tanesi esittir ve ka� tanedir
;yani tek tek degerli karsilastir ve saydir

;org 00h
;	mov r7,#0ah ;ka� sayi kiyaslicaz bunu arttirabiliriz
;	mov r0,#010h ;baslangi� degerleri
;	mov r1,#020h ;baslangic degerleri
;	mov r6,#00h ;karsilastirma sonucunda ka� sayi ayni
;	
;Nxt: mov a,@r0
;mov b,a
;mov a,@r1
;cjne a,b,nomatch   ;a ile b ayni ise alt satirda r6 1 arttir degil ise nomatch git
;  Inc r6 ; 
;nomatch:
;	inc r0 ;bir sonraki degere ge� yani 1 arttir
;	inc r1 ;bir sonraki degere ge� yani 1 arttir
;	djnz r7,nxt ;DJNZ <byte>, <adres> ; (DJNZ: decrement and jump if not zero) <byte> degerini 1 azalt, yeni 
;                ;degeri 0 ;degil ise <adres>�e dallan. Bu komut ile C�deki gibi i� i�e d�ng�ler olusturulabilinir.
;	end




;-----------------------------------------------------------------------------------------
;r6,r7 degerleri r4-r5 birbirinden �ikar ve 21h,20h yaz 
;2 baytlik veri,16 bit lik
;org 00h
;	clr c ;elde bitini temizle
;	mov a,r6
;	subb a,r4
;	mov 20h,a
;	
;	clr c
;	mov a,r7
;	subb a,r5
;	mov 21h,a
;	
;	end
;	
	

;-----------------------------------------------------------------------------------------
;;ffh(internul) daki veriyi ff00h (externul)a aktar,karsilikli aktarma
;org 00h
;	mov dptr,#0ff00h
;	movx a,@dptr
;	mov r0,0ffh
;	mov 050h,a ;yada komut mov 0ffh,a da olabilir 
;	mov a,r0
;	movx @dptr,a
;	end



-----------------------------------------------------------------------------------------
;�nce r7 nin r6 daki �st yarimini alacagiz sonra r7 ye yazacagiz
org 00h
mov r7,#2fh
mov a,r7
anl a,#0f0h
mov r6,a
swap a
orl a,r6
mov r6,a
end



;-----------------------------------------------------------------------------------------
;;led i yakip s�nd�rme swap komutu ile
;org 00h
;	start: mov p1,#0x0f
;	call wait
;	mov a,p1
;	swap a
;	mov p1,a
;	call wait
;	sjmp start
;wait:mov r2,#10
;wait1:mov r3,#200	
;wait2:mov r4,#200	
;djnz r4,$
;djnz r3,wait2
;djnz r2,wait1
;ret
;end


;;lled yakip s�nd�rme kodu
;org 00h
;	start:mov p1,#0x0F
;	call wait
;	mov a,p1
;	cpl a
;	mov p1,a
;	call wait ;bekletme fonksiyonu
;	sjmp start	
;wait: mov r2,#10
;wait1:mov r3,#200
;wait2:mov r4,#200
;djnz r4,$
;djnz r3,wait2
;djnz r2,wait1
;ret
;end