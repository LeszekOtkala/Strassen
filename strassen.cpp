/* program implementuj¹cy algorytm strassena mno¿enia macierzy
	algorytm s³u¿y do przyspieszenia ykonania mno¿enia macierzyzastosowania przetarzania równoleg³ego

*/

#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#define M 2048
//#define N 512
using namespace std;
//*********************************************************************************************



//*********************************************************************************************
void mnozenie(float ** mac1,float ** mac2,float ** mac3, int rozm )
{	//zeruj(mac3, rozm);
	
	for(int k=0;k<rozm;k++)
		for(int i=0;i<rozm;i++)
			for(int j=0;j<rozm;j++)
			{
			mac3[k][i]+=mac1[k][j]*mac2[j][i];
			}
			
}
//*********************************************************************************************
void dodaj(float **mac1, float **mac2, float **mac3, int rozm)
{
	for(int i=0;i<rozm;i++)
	{
	for(int j=0;j<rozm;j++)
		{
		mac3[i][j]=mac1[i][j]+mac2[i][j];
		}
	}
}
//*********************************************************************************************
void odejmij(float **mac1, float **mac2, float **mac3, int rozm)
{
	for(int i=0;i<rozm;i++)
	{
	for(int j=0;j<rozm;j++)
		{
		mac3[i][j]=mac1[i][j]-mac2[i][j];
		}
	}
}
//*********************************************************************************************
void wypelnij (float** mac1, int rozm)
{	
	//srand(time(NULL));
	for(int i=0;i<rozm;i++)
	{
	for(int j=0;j<rozm;j++)
		{
		mac1[i][j]=rand()%9;
		}
	}
}
//*********************************************************************************************
void zeruj (float** mac1, int rozm)
{
	for(int i=0;i<rozm;i++)
	{
	for(int j=0;j<rozm;j++)
		{
		mac1[i][j]=0;
		}
	}	
}
//*********************************************************************************************
void wyswietl (float **mac, int rozm)
{ 
	for (int i=0; i<rozm; i++)
	 {		 	
 		for (int j=0; j<rozm;j++)
 		{ 
			cout<<mac[i][j]<<" ";
		}
		cout<<endl;
	}
}

void podziel (float **mac, float **mac11, float **mac12, float **mac21, float **mac22, int rozm)
{
	
 for (int i=0; i<rozm; i++)
 {	
 	for (int j=0; j<rozm;j++)
 	{ 			
			mac11[i][j]=mac[i][j]; 
			mac12[i][j]=mac[i][j+(rozm)];
			mac21[i][j]=mac[i+(rozm)][j];
			mac22[i][j]=mac[i+(rozm)][j+(rozm)];
		
	}
	
 }
 
}

//*********************************************************************************************
//*********************************************************************************************
void mnoz_str(float **tabA,float **tabB,float **tabC, int rozm)
{	srand(time(NULL));
	//system("pause");
	int N=rozm/2;
	
	

			float **tabA11 = new float *[N]; // tworzenie 4 podtablic do podzia³u tablicy A
			for(int i=0; i<N;i++)
			{
			tabA11[i]=new float[N];
			 }
	 		float **tabA12 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabA12[i]=new float[N];
			 }  
	 		float **tabA21 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabA21[i]=new float[N];
			 }
	 		float **tabA22 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabA22[i]=new float[N];
			 } 
		 
		//wyswietl(tabA,M);
		 podziel(tabA, tabA11, tabA12, tabA21,tabA22, N);
	 	//cout<<"\nMacierz A zostala podzielona!\n";
//----------------------------------------------------------------------------
	
		float **tabB11 = new float *[N]; // tworzenie 4 podtablic do podzia³u tablicy B
			for(int i=0; i<N;i++)
			{
			tabB11[i]=new float[N];
			 }
	 		float **tabB12 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabB12[i]=new float[N];
			 }  
	 		float **tabB21 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabB21[i]=new float[N];
			 }
	 		float **tabB22 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabB22[i]=new float[N];
			 } 
		 
 	podziel(tabB, tabB11, tabB12, tabB21,tabB22, N);
	//cout<<"\nMacierz B zostala podzielona\n";		 
//--------------------------------------------------------------------------------------			 
	float **tabpom1 = new float *[N]; // tworzenie 2 podtablic tymczasowych do obliczeñ
			for(int i=0; i<N;i++)
			{
			tabpom1[i]=new float[N];
			 }
	 		float **tabpom2 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabpom2[i]=new float[N];
			 }

			float **tabP1 = new float *[N]; // tworzenie 7 podtablic do obliczeñ tablic C11, C12, C21, C22
			for(int i=0; i<N;i++)
			{
			tabP1[i]=new float[N];
			 }
	 		float **tabP2 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabP2[i]=new float[N];
			 }  
	 		float **tabP3 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabP3[i]=new float[N];
			 }
	 		float **tabP4 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabP4[i]=new float[N];
			 }
			float **tabP5 = new float *[N]; 
			for(int i=0; i<N;i++)
			{
			tabP5[i]=new float[N];
			 }
	 		float **tabP6 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabP6[i]=new float[N];
			 }  
	 		float **tabP7 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabP7[i]=new float[N];
			 }	 
			 


			float **tabC11 = new float *[N]; // tworzenie 4 podtablic do obliczeñ tablicy C
			for(int i=0; i<N;i++)
			{
			tabC11[i]=new float[N];
			 }
	 		float **tabC12 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabC12[i]=new float[N];
			 }  
	 		float **tabC21 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabC21[i]=new float[N];
			 }
	 		float **tabC22 = new float *[N];
			for(int i=0; i<N;i++)
			{
			tabC22[i]=new float[N];
			 }
	if(N<256)
	{
	//cout<<"\nZaczynamy mnozenie\n";
	//P1--------------------------------
	zeruj(tabP1,N);
	dodaj(tabA11, tabA22, tabpom1,N);
	dodaj(tabB11, tabB22, tabpom2,N);
	mnozenie(tabpom1,tabpom2,tabP1,N);
	//wyswietl(tabP1,N);
	//P2--------------------------------
	zeruj(tabP2,N);
	dodaj(tabA21, tabA22, tabpom1,N);
	mnozenie(tabpom1, tabB11, tabP2,N);
	//wyswietl(tabP2,N);
	//P3---------------------------------
	zeruj(tabP3,N);
	odejmij(tabB12,tabB22,tabpom1,N);
	mnozenie(tabA11, tabpom1, tabP3,N);
	//wyswietl(tabP3,N);
	//P4---------------------------------
	zeruj(tabP4,N);
	odejmij(tabB21, tabB11, tabpom1,N);
	mnozenie(tabA22, tabpom1, tabP4,N);
	//wyswietl(tabP4,N);
	//P5---------------------------------
	zeruj(tabP5,N);
	dodaj(tabA11, tabA12, tabpom1,N);
	mnozenie(tabpom1, tabB22, tabP5,N);
	//wyswietl(tabP5,N);
	zeruj(tabP6,N);
	odejmij(tabA21, tabA11, tabpom1,N);
	dodaj(tabB11, tabB12, tabpom2,N);
	mnozenie(tabpom1, tabpom2, tabP6,N);
	//wyswietl(tabP6,N);
	zeruj(tabP7,N);
	odejmij(tabA12, tabA22, tabpom1,N);
	dodaj(tabB21, tabB22, tabpom2,N);
	mnozenie(tabpom1, tabpom2, tabP7,N);
	//wyswietl(tabP7,N);
	}
	else
	{
	//	cout<<"\nZaczynamy mnozenie\n";
	//P1--------------------------------
	zeruj(tabP1,N);
	dodaj(tabA11, tabA22, tabpom1,N);
	dodaj(tabB11, tabB22, tabpom2,N);
	mnoz_str(tabpom1,tabpom2,tabP1,N);
	//wyswietl(tabP1,N);
	//P2--------------------------------
	zeruj(tabP2,N);
	dodaj(tabA21, tabA22, tabpom1,N);
	mnoz_str(tabpom1, tabB11, tabP2,N);
	//wyswietl(tabP2,N);
	//P3---------------------------------
	zeruj(tabP3,N);
	odejmij(tabB12,tabB22,tabpom1,N);
	mnoz_str(tabA11, tabpom1, tabP3,N);
	//wyswietl(tabP3,N);
	//P4---------------------------------
	zeruj(tabP4,N);
	odejmij(tabB21, tabB11, tabpom1,N);
	mnoz_str(tabA22, tabpom1, tabP4,N);
	//wyswietl(tabP4,N);
	//P5---------------------------------
	zeruj(tabP5,N);
	dodaj(tabA11, tabA12, tabpom1,N);
	mnoz_str(tabpom1, tabB22, tabP5,N);
	//wyswietl(tabP5,N);
	zeruj(tabP6,N);
	odejmij(tabA21, tabA11, tabpom1,N);
	dodaj(tabB11, tabB12, tabpom2,N);
	mnoz_str(tabpom1, tabpom2, tabP6,N);
	//wyswietl(tabP6,N);
	zeruj(tabP7,N);
	odejmij(tabA12, tabA22, tabpom1,N);
	dodaj(tabB21, tabB22, tabpom2,N);
	mnoz_str(tabpom1, tabpom2, tabP7,N);
	//wyswietl(tabP7,N);
	}
	//cout<<"\ntablice czesciowe wymnozone\n";
	//cout<<"\nskladanie tablicy C\n";
	// C11 -----------------------------------------------------------
	dodaj(tabP1,tabP4,tabpom1,N);
	odejmij(tabpom1,tabP5, tabpom2,N);
	dodaj(tabpom2, tabP7, tabC11, N);
	// C12 -----------------------------------------------------------
	dodaj(tabP3,tabP5,tabC12,N);
	// C21 -----------------------------------------------------------
	dodaj(tabP2,tabP4,tabC21,N);
	// C22 -----------------------------------------------------------
	dodaj(tabP3, tabP1, tabpom1,N);
	odejmij(tabpom1,tabP2, tabpom2,N);
	dodaj(tabpom2, tabP6,tabC22,N);
	
	for(int i=0; i<rozm;i++)
	{
		for(int j=0; j<rozm;j++)
			{
				if((i<N)&&(j<N))
				tabC[i][j]=tabC11[i][j];
				if((i<N)&&(j>=N))
				tabC[i][j]=tabC12[i][j-N];
				if((i>=N)&&(j<N))
				tabC[i][j]=tabC21[i-N][j];
				if((i>=N)&&(j>=N))
				tabC[i][j]=tabC22[i-N][j-N];
			}
	 }
	
	//zeruj(tabC,M);
	//cout<<"\nZerowanie tablicy C zakonczone\n";
	//wyswietl(tabC,M);
	//mnozenie(tabA, tabB, tabC, M);
	//cout<<"Mnozenie zakonczone\n";
	//wyswietl(tabC,N);


//usuwanie
for(int i=0; i<N;i++)
	{
		delete [] tabA11[i];
		delete [] tabA12[i];
		delete [] tabA21[i];
		delete [] tabA22[i];
		delete [] tabB11[i];
		delete [] tabB12[i];
		delete [] tabB21[i];
		delete [] tabB22[i];
		delete [] tabC11[i];
		delete [] tabC12[i];
		delete [] tabC21[i];
		delete [] tabC22[i];
		delete [] tabpom1[i];
		delete [] tabpom2[i];
		delete [] tabP1[i];
		delete [] tabP2[i];
		delete [] tabP3[i];
		delete [] tabP4[i];
		delete [] tabP5[i];
		delete [] tabP6[i];
		delete [] tabP7[i];
	}
		delete [] tabA11;
		delete [] tabA12;
		delete [] tabA21;
		delete [] tabA22;
	
		delete [] tabB11;
		delete [] tabB12;
		delete [] tabB21;
		delete [] tabB22;
		
		delete [] tabC11;
		delete [] tabC12;
		delete [] tabC21;
		delete [] tabC22;	
		
		delete [] tabpom1;
		delete [] tabpom2;
		delete [] tabP1;
		delete [] tabP2;
		delete [] tabP3;
		delete [] tabP4;
		delete [] tabP5;
		delete [] tabP6;
		delete [] tabP7;
 

	//cout<<"\n Usuwanie tablic zakonczone!\n";
	//system("pause");

}
int main()
{
	float **tabA = new float *[M];
	for(int i=0; i<M;i++)
	{
		tabA[i]=new float[M];
	 } 
	wypelnij(tabA,M);
	cout<<"\nWypelnianie tablicy A zakonczone\n";	
	
		float **tabB = new float *[M];
	for(int i=0; i<M;i++)
	{
		tabB[i]=new float [M];
	 } 
	
	wypelnij(tabB,M);
	cout<<"\nWypelnianie tablicy B zakonczone\n";
	//wyswietl(tabB,M);	
	
	float **tabC = new float *[M];
	for(int i=0; i<M;i++)
	{
		tabC[i]=new float[M];
	 } 	
	clock_t start, stop;
	float czas;
	start=clock();	
	mnoz_str(tabA,tabB,tabC,M);	
	stop=clock();
	czas=(stop-start);
	cout<<"\nMnozenie wykonane! Czas to:"<<(czas/1000)<<" s "<<endl;
	//wyswietl(tabC,M);
	
/*	
	cout<<"\nMnozenie tradycyjne:\n";
	zeruj(tabC,M);
	start=clock();
	mnozenie(tabA,tabB,tabC,M);
	stop=clock();
	czas=(stop-start);
	cout<<"\nMnozenie wykonane! Czas to:"<<(czas/1000)<<" s "<<endl;
	//wyswietl(tabC,M);	*/
//----------------------------------------------------------------------------------
	for(int i=0; i<M;i++)		//usuwanie tablicy A 
		{
			delete [] tabA[i];
		}
		delete[] tabA;
	cout<<"\nMacierz A zostala usunieta!\n";	
	for(int i=0; i<M;i++)		//usuwanie tablicy B 
	{
		delete [] tabB[i];
	}
	delete[] tabB;	
	cout<<"\nMacierz B zostala usunieta!\n";
	
		 for(int i=0; i<M;i++)
	{
		delete [] tabC[i];
	 }
	cout<<"\nMacierz C usunieta!\n";
	
	delete[] tabC;
	
	system("pause");
	}
