#include <stdio.h>

int main(){
    int secim = 0;
    float anaBakiye;

    FILE *dosya = fopen("bakiye.txt", "r");

    if(dosya == NULL){
        anaBakiye = 100;
    }else{
        fscanf(dosya, "%f", &anaBakiye);
        fclose(dosya);
    }



    float cekilecekTutar = 0;
    float yatirilacakTutar = 0;
    float gonderilecekTutar = 0;
    int islemSecimi = 0;

e:
    printf("\nMerhaba Mehmet Bey. Lutfen yapmak istediginiz islemi secin\n");
    printf("1-Para Cekmek\n2-Para Yatirma\n3-Para Gonderme\n4-Durumum");
    scanf("%d", &secim);

    if(secim == 1){
        printf("Suan ki hesap bakiyeniz: %.2f TL'dir. Ne kadar para cekmek istersiniz", anaBakiye);
        scanf("%f", &cekilecekTutar);

        if(cekilecekTutar > anaBakiye){
            printf("Hesabinizda %.2f TL tutarinda para bulunmamaktadir\nAna menuye aktariliyorsunuz", cekilecekTutar);
            goto e;
        }else{
            anaBakiye -=cekilecekTutar;
            printf("Hesabinizdan basariyla para cekildi.\nSuan ki hesap bakiyeniz: %.2f TL'dir\n", anaBakiye);
            printf("Islem yapmaya devam etmek ister misiniz(1-Evet, 2-Hayir)");
            scanf("%d", &islemSecimi);
            if(islemSecimi == 1){
                printf("Ana menuye yonlendiriliyorsunuz.\n");
                goto e;
            }else{
                printf("Bizi tercih ettiginiz icin tesekkur ederiz.");
            }

        }

    }else if(secim == 2){
        printf("Ne kadar para yatirmak istiyorsunuz: ");
        scanf("%f", &yatirilacakTutar);
        anaBakiye +=yatirilacakTutar;
        printf("Hesabiniza %.2f TL para yatirildi\nGuncel hesap bakiyeniz: %f TL'dir\n", yatirilacakTutar, anaBakiye);
                    printf("Islem yapmaya devam etmek ister misiniz(1-Evet, 2-Hayir)");
            scanf("%d", &islemSecimi);
            if(islemSecimi == 1){
                printf("Ana menuye yonlendiriliyorsunuz.\n");
                goto e;
            }else{
                printf("Bizi tercih ettiginiz icin tesekkur ederiz.");
            }
    }else if(secim == 3){
        printf("Ne kadar para gondermek istyorsunuz: ");
        scanf("%f", &gonderilecekTutar);

        if(gonderilecekTutar > anaBakiye){
           printf("Hesabinizda %.2f TL tutarinda para bulunmamaktadir\nAna menuye aktariliyorsunuz", cekilecekTutar);
            goto e;
        }else{
            anaBakiye -=gonderilecekTutar;
            printf("%f TL tutarinda para istediginiz hesaba gonderilmistir\n", gonderilecekTutar);
            printf("Guncel hesap bakiyeniz %.2f TL'dir", anaBakiye);
                        printf("Islem yapmaya devam etmek ister misiniz(1-Evet, 2-Hayir)");
            scanf("%d", &islemSecimi);
            if(islemSecimi == 1){
                printf("Ana menuye yonlendiriliyorsunuz.\n");
                goto e;
            }else{
                printf("Bizi tercih ettiginiz icin tesekkur ederiz.");
            }

        }

    }else if(secim == 4){
        printf("\n\nGUNCEL DURUMUNUZ\n\n");
        printf("ANA BAKIYE: %.2f TL\n", anaBakiye);
                    printf("Islem yapmaya devam etmek ister misiniz(1-Evet, 2-Hayir)");
            scanf("%d", &islemSecimi);
            if(islemSecimi == 1){
                printf("Ana menuye yonlendiriliyorsunuz.\n");
                goto e;
            }else{
                printf("Bizi tercih ettiginiz icin tesekkur ederiz.");
            }
    }

    

    dosya = fopen("bakiye.txt", "w");
    fprintf(dosya, "%.2f", anaBakiye);
    fclose(dosya);

    return 0; 
}