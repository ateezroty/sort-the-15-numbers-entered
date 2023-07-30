#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("******************************************************************\n");
    printf("* Disaridan girilen 15 tane sayiyi siralama programina geldiniz! *\n");
    printf("******************************************************************\n");

    while (true) {
        printf("************** MENU ***************\n");
        printf("* 1- 15 tane sayi gir.            *\n");
        printf("* 2- Programdan cikmak istiyorum. *\n");
        printf("***********************************\n");

        int islem ;
        printf("  Islem seciniz: ");
        scanf("%d", &islem);

        if (islem == 1) {

            printf("-----------------------------------\n");
            int arrayLen = 15;
            int array[arrayLen];
            for (int i = 0 ; i < arrayLen ; ++i) {
                printf("  %d. sayiyi giriniz: ", i+1);
                scanf("%d", &array[i]);
                printf("-----------------------------------\n");
            }
            //Gerekli degiskenleri tanimliyorum.
            bool hepsindenBuyukMu;
            bool hepsindenKucukMu;
            bool hepsiEsitMi;
            int enBuyukSayi;
            int sayac = 0;
            int kucuktenBuyugeSiralanmisDizi[arrayLen];
            int siralanmisDiziIndisi = 0;
            //Ic ice dongu ile en buyuk sayiyi buluyorum.
            for (int i = 0 ; i < arrayLen ; ++i) {
                hepsindenBuyukMu = true;
                for (int j = 0 ; j < arrayLen ; ++j) {
                    if (array[i] < array[j]) {
                        hepsindenBuyukMu = false;
                    }
                }
                if (hepsindenBuyukMu) {
                    enBuyukSayi = array[i];
                }
            }
            //Ic ice dongu ile en kucuk sayiyi buluyorum. Sonra en kucuk sayiyi yeni bir diziye kaydedip en büyük sayiya esitliyorum.
            //Bu islem tekrar calistiginda yeni en kucuk sayiyi buluyorum. Sonra sayiyi diziye kaydedip en buyuk sayiya esitliyorum.
            //Bu islemler tum sayilar en buyuk sayiya esit olana kadar devam ediyor. Ve yeni dizimizde artik kucukten buyuge siralanmis sayilar var.
            while (true) {
                for (int i = 0 ; i < arrayLen ; ++i) {
                    hepsindenKucukMu = true;
                    for (int j = 0 ; j < arrayLen ; ++j) {
                        if (array[i] > array[j]) {
                            hepsindenKucukMu = false;
                        }
                    }
                    if (hepsindenKucukMu) {
                        //printf("%d", array[i]);
                        kucuktenBuyugeSiralanmisDizi[siralanmisDiziIndisi] = array[i];
                        array[i] = enBuyukSayi;
                        ++sayac;
                        ++siralanmisDiziIndisi;
                    }
                }
                if (sayac >= arrayLen) {
                    break;
                }
            }
            //Burda kullanici tercihini yaziyor. 2 girerse direkt siralanmis diziyi yazdiriyorum. 1 Girerse siralanmis diziyi tersten yazdiriyorum.
            while (true) {
                printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
                printf("| Sayilar nasil siralansin istersiniz? |\n");
                printf("| 1- Buyukten Kucuge                   |\n");
                printf("| 2- Kucukten Buyuge                   |\n");
                printf("| 3- Geri Donmek istiyorum.            |\n");
                printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
                int islemTercihi = 0;

                printf("| Lutfen islem tercihinizi giriniz: ");
                scanf ("%d", &islemTercihi);
                Sleep(200);

                if(islemTercihi == 1) {
                    int a = 0;
                    for (int i = arrayLen -1 ; i >= 0 ; --i) {
                        ++a;
                        printf("| %d. ", a);
                        if (a < 10) {           // Burada sayilarin düzenli durmasini sagliyorum.
                            printf(" ");        // \t kullaninca aralari cok aciliyor.
                        }                       // =)
                        printf("--> %d\n", kucuktenBuyugeSiralanmisDizi[i]);
                    }
                }
                else if(islemTercihi == 2) {
                    for (int i = 0 ; i < arrayLen ; i++) {
                        printf("| %d. ", i+1);
                        if (i+1 < 10) {
                            printf(" ");
                        }
                        printf("--> %d\n", kucuktenBuyugeSiralanmisDizi[i]);
                    }
                }
                else if(islemTercihi == 3) {
                    printf("| Geri donuluyor..\n");
                    break;
                }
                else {
                    printf("| Gecersiz islem tercihi!\n");
                }
            }
        }

        else if (islem == 2) {
            printf("***********************************\n");
            printf("* Programdan cikiliyor..          *\n");
            printf("* Kaliniz selametle =)            *\n");
            printf("***********************************\n");
            break;
        }
        else {
            printf("  Gecersiz islem!\n");
        }
    }
    return 0;
}
// Aslinda burda asil yapilmasi gereken dizinin elemanlarini dizi boyutunun karesi kez diger elemanlarla kontrol ettirip duruma gore elemlarin yerlerini
// degistirmekti sanirim. Ama ben boyle yapmayi daha hos buldum.
