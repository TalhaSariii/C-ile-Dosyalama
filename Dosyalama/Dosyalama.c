#include <stdio.h>
#include <conio.h>
#include <windows.h>

void clrscr() { system("CLS"); }

void gotoxy(short s,short k) { COORD pos = {s,k};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); }
	
	void Baslik()
	{system("CLS");
	gotoxy(1,1); printf("-----------------------DOSYALAMA----------------------");
	}
	void menu()
	{ Baslik();
	gotoxy(11,5);printf("---MENU---");
	gotoxy(11,6);printf("1.Yaz");
	gotoxy(11,7);printf("2.Ara");
	gotoxy(11,8);printf("3.Sil");
	gotoxy(11,9);printf("4.Duzelt");
	gotoxy(11,10);printf("5.Listele");
	gotoxy(11,11);printf("0.Cikis");
	gotoxy(11,15);printf("Bir secenek giriniz");
	}
	void BlgEk()
	{ Baslik();
	gotoxy(5,4);printf("---Ogrenci Bilgileri---");
	gotoxy(5,5);printf("Numara:");
	gotoxy(5,6);printf("Ad:");
	gotoxy(5,7);printf("Soyad :");
	gotoxy(5,8);printf("Telefon :");
	gotoxy(5,9);printf("Yas:");
	}
	
	void BlgGos(int nmr,char adi[20],char syd[20],char tlf[11],int yas)
	{ Baslik();
	gotoxy(22,5);printf("%d",nmr);
	gotoxy(22,6);printf("%s",adi);
	gotoxy(22,7);printf("%s",syd);
	gotoxy(22,8);printf("%s",tlf);
	gotoxy(22,9);printf("%d",yas);
	}
	
	void main(){
		FILE*OgrD,*GecD;
		struct KayTip{int nmr; char adi[20];char syd[20]; char tlf[11]; int yas; 
		}ODBlg;
		int Anmr,sec,bul=0;
		Bsl:
			system("CLS");
		Menu:
		Baslik(); menu();
		Miste:
		gotoxy(33,15);scanf("%d",&sec);
		if(sec==0) goto Son;
		if(sec>5){gotoxy(11,20); printf("Hatali Secim Yapildi,Tekrar giriniz."); goto Miste;}
		if(sec==1) goto DkYaz;
		if(sec==2) goto DkOku;
		if(sec==3) goto DkSil;
		if(sec==4) goto DkDuz;
		if(sec==5) goto DkLst;
		goto Miste;


DkYaz:
	BlgEk();
	gotoxy(11,20); printf("Lutfen Bilgileri giriniz "); 
	gotoxy(20,5); scanf("%d",&ODBlg.nmr);
	gotoxy(20,6); scanf("%s",&ODBlg.adi);
	gotoxy(20,7); scanf("%s",&ODBlg.syd);
	gotoxy(20,8); scanf("%s",&ODBlg.tlf);
	gotoxy(20,9); scanf("%d",&ODBlg.yas);
	gotoxy(44,4); printf("--Girilenler--");
	gotoxy(44,5); printf("%d",ODBlg.nmr);
	gotoxy(44,6); printf("%s",ODBlg.adi);
	gotoxy(44,7); printf("%s",ODBlg.syd);
	gotoxy(44,8); printf("%s",ODBlg.tlf);
	gotoxy(44,9); printf("%d",ODBlg.yas);
	OgrD=fopen("ogr.dat","a");
	fprintf(OgrD,"\n%d %s %s %s %d",ODBlg.nmr,ODBlg.adi,ODBlg.syd,ODBlg.tlf,ODBlg.yas);
	fclose(OgrD);
	gotoxy(11,21); printf("Kayit Yazildi ");
	gotoxy(11,22); printf("Menu icin enter tuslayiniz :"); getch();
DKYcik: 
goto Menu;
DkOku:
	Baslik();
	gotoxy(11,11); printf("Aranan kisinin Numarasini giriniz :");
	scanf("%d",&Anmr);
	if(Anmr==0) goto DKOcik;
	OgrD=fopen("ogr.dat","r");
	bul=0;
	while(!feof(OgrD))
	{fscanf(OgrD,"%d %s %s %s %d",&ODBlg.nmr,&ODBlg.adi,&ODBlg.syd,&ODBlg.tlf,&ODBlg.yas);
	if(Anmr==ODBlg.nmr)
	{bul=1;
	BlgEk(); gotoxy(5,4); printf("----Okunan bilgiler----");
	BlgGos(ODBlg.nmr,ODBlg.adi,ODBlg.syd,ODBlg.tlf,ODBlg.yas);
	}
	}
	fclose(OgrD);
	if(bul==0){gotoxy(11,20); printf("Bulunamadi");}
	gotoxy(11,22);printf("Menu icin Enter tuslayiniz:"); getch();
	DKOcik:
		goto Menu;
DkSil:
	Baslik(); gotoxy(11,11); printf("Silinicek kisinin numarasini giriniz:");
	scanf("%d",&Anmr);
	if(Anmr==0) goto DKScik;
	OgrD=fopen("ogr.dat","r"); GecD=fopen("gecici.dat","w");
	bul=0;
	while(!feof(OgrD))
	{fscanf(OgrD,"%d %s %s %s %d",&ODBlg.nmr,&ODBlg.adi,&ODBlg.syd,&ODBlg.tlf,&ODBlg.yas);
	if(Anmr==ODBlg.nmr){bul=1;
	BlgEk(); gotoxy(5,4); printf("---silinecek bilgiler---");
	BlgGos(ODBlg.nmr,ODBlg.adi,ODBlg.syd,ODBlg.tlf,ODBlg.yas);
	gotoxy(22,20); printf("Silindi");}
	else fprintf(GecD,"\n%d %s %s %s %d",ODBlg.nmr,ODBlg.adi,ODBlg.syd,ODBlg.tlf,ODBlg.yas);
	}
	fclose(OgrD); fclose(GecD);
	remove("ogr.dat"); rename("gecici.dat","ogr.dat");
	if (bul==0){gotoxy(11,20); printf("Bulunamadý");}
	gotoxy(11,22); printf("Menu icin Enter Tuslayiniz "); getch();
DKScik:
	goto Menu;
DkDuz:
	Baslik(); gotoxy(11,11); printf("Duzeltilecek kisinin numarasini giriniz ");
	scanf("%d",&Anmr);	
	if(Anmr==0) goto Dkcik;
	OgrD=fopen("ogr.dat","r"); GecD=fopen("gecici.dat","w");
	bul=0;
	while(!feof(OgrD))
{ fscanf(OgrD,"%d %s %s %s %d",&ODBlg.nmr,&ODBlg.adi,&ODBlg.syd,&ODBlg.tlf,&ODBlg.yas);
if(Anmr==ODBlg.nmr)
{bul=1; 
BlgEk(); gotoxy(5,4); printf("---Okunan Bilgiler---");
BlgGos(ODBlg.nmr,ODBlg.adi,ODBlg.syd,ODBlg.tlf,ODBlg.yas);
gotoxy(55,4); printf("---Yenilerini giriniz---");
gotoxy(55,5); scanf("%d",&ODBlg.nmr);
gotoxy(55,6); scanf("%s",&ODBlg.adi);
gotoxy(55,7); scanf("%s",&ODBlg.syd);
gotoxy(55,8); scanf("%s",&ODBlg.tlf);
gotoxy(55,9); scanf("%d",&ODBlg.yas);
gotoxy(22,19); printf("Duzeltildi");
			  }
			  	
			  fprintf(GecD,"\n %d %s %s %s %d",ODBlg.nmr,ODBlg.adi,ODBlg.syd,ODBlg.tlf,ODBlg.yas);
	}
	fclose(OgrD); fclose(GecD);
	remove("ogr.dat"); rename("gecici.dat","ogr.dat");
	if (bul==0){gotoxy(11,20); printf("Bulunamadý");}
	gotoxy(11,22); printf("Menu icin Enter Tuslayiniz "); getch();
Dkcik:	
		goto Menu;
DkLst:
	Baslik(); OgrD=fopen("ogr.dat","r"); GecD=fopen("gecici.dat","w");
	while(!feof(OgrD))
	{fscanf(OgrD,"%d %s %s %s %d",&ODBlg.nmr,&ODBlg.adi,&ODBlg.syd,&ODBlg.tlf,&ODBlg.yas);
	BlgEk(); gotoxy(5,4); printf("---Okunan bilgiler---");
	BlgGos(ODBlg.nmr,ODBlg.adi,ODBlg.syd,ODBlg.tlf,ODBlg.yas);
	gotoxy(11,20); printf("Sonraki kayýt için Enter tuslayiniz:"); getch();
	}
fclose(OgrD);
gotoxy(11,22); printf("Menu icin Enter Tuslayiniz :"); getch();
DKLcik:
	goto Menu;
	Son:
printf("bitti");		




	

	
}
