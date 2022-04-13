/***********************************************************************************************************************************
************************************************************************************************************************************
************************************************************************************************************************************
*****************************       Ogrenci Adi  :   Deniz Berfin TAŞTAN            ************************************************
*****************************       Ogrenci Numarasi   : B181210010                 ************************************************
*****************************       Ders Grubu     :     D                          ************************************************
************************************************************************************************************************************
************************************************************************************************************************************
************************************************************************************************************************************/

#include<iostream>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
using namespace std;



void gotoxy(int x, int y)
{
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
} // Koordinat Atamak için oluşturulan fonksiyon

struct Sahne
{
	int yukseklik;
	int genislik;
	char kose;
}sahne1; //Sahne Yapısı

void sahneOlustur()
{
	int RastGenislik;
	srand(time(0));
	int x[] = { 30,40,50 };
	RastGenislik = rand() % 3;
	sahne1.genislik = x[RastGenislik];
	char RastKarakter;
	char y[] = { '*','#','$','+','@' };
	RastKarakter = rand() % 5;
	sahne1.kose = y[RastKarakter];
	sahne1.yukseklik = rand() % 11 + 20;
	
} //Sahnenin genişliğini, karakterini ve yüksekliğini random atamak için yazılan fonksiyon


void sahneCiz()
{


	for (int i = 0; i < sahne1.genislik; i++)
	{
		cout << sahne1.kose;

	}
	for (int k = 0; k < sahne1.yukseklik; k++)
	{
		gotoxy(sahne1.genislik - 1, k);
		cout << sahne1.kose;

	}
	for (int m = 0; m < sahne1.genislik; m++)
	{
		gotoxy(sahne1.genislik - m - 1, sahne1.yukseklik - 1);
		cout << sahne1.kose;

	}
	for (int n = 0; n < sahne1.yukseklik; n++)
	{
		gotoxy(0, sahne1.yukseklik - 1 - n);
		cout << sahne1.kose;

	}

} //Bu fonksiyon sahne çizimi için kullanılır.

struct Lsekil
{
	int Lboyut;
	char Lsekil;
	int Lkoordinat;
	 int y;
	
}Lsekil1; //L sekil yapısıdır.

void LsekilOlustur()
{
	int RastLBoyut;
	srand(time(0));
	int x[] = { 2,3,4,5,6,7 };
	RastLBoyut = rand() % 6;
	Lsekil1.Lboyut = x[RastLBoyut];
	char RastLKarakter;
	char y[] = { '*','#','$','+','@' };
	RastLKarakter = rand() % 5;
	Lsekil1.Lsekil = y[RastLKarakter];
	int RastLkonum;
	int z[] = {5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	RastLkonum = rand() % 21;
	Lsekil1.Lkoordinat = z[RastLkonum];
	Lsekil1.y = 3;
}//L şeklinin boyutunu, karakterini ve bulunacak konumu random atamak için yazılan fonksiyon


void Lciz()
{
	
	int i, j, k, m, n, p, o;
	for (i = 0; i < Lsekil1.Lboyut; i++)
	{
		gotoxy(Lsekil1.Lkoordinat + i, Lsekil1.y);
		cout << Lsekil1.Lsekil;
	} //L seklinin sol üst genişliğini çizer

	for (j = 0; j < Lsekil1.Lboyut; j++)
	{
		gotoxy(Lsekil1.Lkoordinat + i, Lsekil1.y + j);
		cout << Lsekil1.Lsekil;
	} // L şeklinin aşağı doğru uzanan orta yüksekliği çizer
	
	for (k = 0; k < Lsekil1.Lboyut; k++)
	{
		gotoxy(Lsekil1.Lkoordinat + i + k, Lsekil1.y + j);
		
		cout << Lsekil1.Lsekil;
	}// L şeklinin sağ üst genişliğini çizer
	
	for (m = 0; m < Lsekil1.Lboyut; m++)
	{
		gotoxy(Lsekil1.Lkoordinat + i + k, Lsekil1.y + j + m);
		cout << Lsekil1.Lsekil;
	}//L şeklinin sağ yüksekliğini çizer
	
	for (n = 0; n < Lsekil1.Lboyut; n++)
	{
		gotoxy(Lsekil1.Lkoordinat + n + n, Lsekil1.y + j + m - 1);
		cout << Lsekil1.Lsekil;
	}// L şeklinin alt genişliğini çizer

	for (p = 0; p < Lsekil1.Lboyut; p++)
	{

		gotoxy(Lsekil1.Lkoordinat, Lsekil1.y + p + 1);
		cout << Lsekil1.Lsekil;
	}
	for (o = 0; o < Lsekil1.Lboyut; o++)
	{

		gotoxy(Lsekil1.Lkoordinat, Lsekil1.y + p + o);
		cout << Lsekil1.Lsekil;
	}// Üstterki 2 fonksiyon L şeklinin sağ yüksekliğini çizer

} // L çizmek için yazılan fonksiyon


void lAsagiindir()
{
		Lsekil1.y = Lsekil1.y + 1;
}// L şeklinin aşağı kaymasını sağlayan fonksiyon


int main()
{   
	sahneOlustur();
	LsekilOlustur();
    while (1)
	{
		system("cls");
		sahneCiz();
		Lciz();
		lAsagiindir();
	
		if (sahne1.yukseklik <= ((Lsekil1.Lboyut ) + Lsekil1.y)+Lsekil1.Lboyut)
			LsekilOlustur(); // L şekli sahnenin sonuna geldiğinde tekrar başa almasını ve sahne dışına çıkmamasını sağlayan koşul.

		Sleep(100);
	}
	
	
	cin.get();
	
} // Tüm fonksiyonların ve yapıların ekrana basılmasını sağlayan alan.
