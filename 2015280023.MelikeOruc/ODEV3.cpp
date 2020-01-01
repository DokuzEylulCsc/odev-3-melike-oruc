#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

void insertionSort(int ogrenciPuanlari[],string ogrenciNumaralari[] ,int n);

main()
{
	//soru sayýsýný aldým
	//min soru sayýsý = 1
	//max soru sayýsý = 25
	int soruSayisi = 0;
	while(true)
	{
    cout << endl<<"Soru sayisini girin : " << endl;
     cin >>soruSayisi;
     if(soruSayisi  <=25 && soruSayisi >= 1) break;
	}
   //olasý cevaplar
   char arr[4] = {'A','B','C','D'};
   //sorularýn cevap anahtarý
   char cevapAnahtari[soruSayisi];
   
    for(int i = 0; i < soruSayisi ; i++)
    {
   	// bir formül yaptým
   	 cevapAnahtari[i] = arr[ (7 * i) % ((i % 4) + (4 - (i % 4)))];
     //cout<<cevapAnahtari[i];	 	
    }
    fstream dosyayaz;
    dosyayaz.open("girdi.txt",ios::out);
    //soru sayýsýný dosyaya yazdým
    dosyayaz<<soruSayisi << endl; 
   
    //cevap anahatarýný dosyaya yazdým
    for(int i = 0; i < soruSayisi ; i ++)
    {
    	if(i == soruSayisi -1)
    	{
          	dosyayaz << cevapAnahtari[i];	
		}
		else dosyayaz << cevapAnahtari[i] << ",";	
	}
	dosyayaz<<endl;
	//ogrenci sayýsýný kullanýcýdan aldým 
	//ogrencilerin cevaplarýný rastgele oluþturdum
	//ogrencilerin cevaplarýný dosyaya yazdým
	//ogrencilerin aldýðý puanalrý hesapladým
	//ogrencilerin okul numaralarýný oluturdum
	int ogrenciSayisi = 0;
	while(true)
	{
	cout << endl<<"ogrenci sayisini gir :"<<endl;
	cin>>ogrenciSayisi;
	if(ogrenciSayisi >= 1) break;
	}

	
	//ogrenci cevaplarýný kaydettiðim yer
	char ogrenciCevaplari[ogrenciSayisi][soruSayisi];
	//ogrenci numaralarýný kaydettiðim yer
	string ogrenciNumaralari[ogrenciSayisi];
	int ogrenciPuanlari[ogrenciSayisi];
	
	srand(time(0));
	for(int i = 0; i < ogrenciSayisi ; i++)
	{
		
		
		 dosyayaz<<"N0000000" << i+3<<",";
		ogrenciNumaralari[i] = "N0000000" + to_string(i+3);
		int x; // rastgele sayý üretmek için
		int puanToplami = 0; // o öðrecinin aldýðý toplam puan
		for(int j = 0; j < soruSayisi ; j ++)
		{
			//cevabýný üretiyorum
			x = rand() % 5; // 0 = A  , 1 = B , 2 = C , 3 = D , 4 = BOÞ
			if(x == 4)
				ogrenciCevaplari[i][j] ='\0';
			else ogrenciCevaplari[i][j] = arr[x];
			
			//aldýðý puaný ekliyorum
			
			if(ogrenciCevaplari[i][j] == cevapAnahtari[j])
			 puanToplami += 4;
			else if(ogrenciCevaplari[i][j] != cevapAnahtari[j]  && ogrenciCevaplari[i][j] != '\0')
			puanToplami -=1;

			// dosyaya yazýyorum
			if(j == soruSayisi -1)
			dosyayaz <<ogrenciCevaplari[i][j];
			
		  else 	dosyayaz <<ogrenciCevaplari[i][j] << ",";	
		  
		  	
		}
		if(puanToplami < 0) puanToplami = 0;
		ogrenciPuanlari[i] = puanToplami;
		 dosyayaz<<endl;
	}
	dosyayaz.close();
	
	
	
	
   /*	for(int i = 0; i < ogrenciSayisi ; i ++)
		{
			cout << ogrenciPuanlari[i]  << " ,    ";
		 cout << ogrenciNumaralari[i] <<", ";
		for(int j = 0; j < soruSayisi ; j ++)
		 cout << ogrenciCevaplari[i][j];
		cout << endl;
		}  */
	

	
	/*	for(int i = 0; i < ogrenciSayisi ; i ++)
	{
		cout << ogrenciPuanlari[i]  << "  , " << ogrenciNumaralari[i] << endl;
     } */


		//ogrenci numalarý ve notlarýný sýraladým
	insertionSort(ogrenciPuanlari , ogrenciNumaralari, ogrenciSayisi);
	
	
    /*	for(int i = 0; i < ogrenciSayisi ; i ++)
	{
		cout << ogrenciPuanlari[i]  << "  , " << ogrenciNumaralari[i] << endl;
    } */

     // max - min - ortalama - medyan - açýklýk hesapladým
	  int max = ogrenciPuanlari[0];
	  int min = ogrenciPuanlari[ogrenciSayisi - 1];
	  int aciklik = max - min;
	  double medyan = 0.0;
	  double ort = 0.0;
	  if(ogrenciSayisi % 2 == 0)
	  {
	  	medyan = (1.0 *(ogrenciPuanlari[ogrenciSayisi/2] + ogrenciPuanlari[ogrenciSayisi/2 + 1] )) / 2.0;
	  	
	  }
	  else{
	  	medyan = ogrenciPuanlari[ogrenciSayisi/2];
	  }
	  
	  int toplam = 0;
	  for(int i = 0; i < ogrenciSayisi ; i++)
        toplam += ogrenciPuanlari[i];
        
        ort = (toplam * 1.0)/ (ogrenciSayisi * 1.0);
	//ogrencilerin sýralanmýþ notlarýný dosyaya yazdým
	
	ofstream ciktiDosyasi("cikti.txt",ios::out);
	
	for(int i = 0; i <ogrenciSayisi ; i++)
	{
		ciktiDosyasi<<ogrenciNumaralari[i] << "," << ogrenciPuanlari[i] << endl;
	}
	//  max - min - ortalama - medyan - açýklýk dosyaya yazdým
	ciktiDosyasi << max << ","  << min<< "," <<ort << "," <<medyan << ","<<aciklik;

}

//insertion sort
// O(n*2)
void insertionSort(int ogrenciPuanlari[],string ogrenciNumaralari[] ,int n)  
{  
    int i, key, j;  
    string temp;
    for (i = 1; i < n; i++) 
    {  
        key = ogrenciPuanlari[i];  
        temp = ogrenciNumaralari[i];
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && ogrenciPuanlari[j] < key)  //  ogrenciPuanlari[j] > key
        {  
            ogrenciPuanlari[j + 1] = ogrenciPuanlari[j];
			ogrenciNumaralari[j + 1] = ogrenciNumaralari[j];  
            j = j - 1;  
        }  
        ogrenciPuanlari[j + 1] = key; 
		ogrenciNumaralari[j + 1] = temp;  
    }  
}  



  

