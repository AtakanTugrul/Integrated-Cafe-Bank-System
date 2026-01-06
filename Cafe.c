#include <stdio.h>
#include <string.h>

#define ESPRESSO 20
#define AMERICANO 30 
#define LATTE 40
#define ICEDLATTE 45
#define SANDVIC 90 
#define OMLET 100
#define BROWNIE 50
#define MUFFIN 60


void odeme(int fiyat){
    char odemeTercihi[30];
    printf("Ne sekilde odemek istersiniz?\n1-Nakit\n2-Kredi Karti");
    fgets(odemeTercihi, sizeof(odemeTercihi), stdin);
    odemeTercihi[strcspn(odemeTercihi, "\n")] = '\0';

    if(strcasecmp(odemeTercihi, "nakit") == 0){
        printf("Nakit odeyebilirsiniz. Borcunuz %d TL", fiyat);
    }else{
        printf("Kartla odeyebilirsiniz. Borcunuz %d TL\n", fiyat);
         FILE *dosya_oku = fopen("bakiye.txt", "r");
                float bakiye;
                if(dosya_oku == NULL){
                    printf("Bankayla iletisim kurulamadi.");
                    
                    return;
                }else{
                     fscanf(dosya_oku, "%f", &bakiye);
                     fclose(dosya_oku);
        if(bakiye < fiyat){
            printf("Odeme alinamadi!\n");
        }else{
            bakiye -=fiyat;
            FILE *dosya_yaz = fopen("bakiye.txt", "w");
            if(dosya_yaz == NULL){
                perror("DOSYA YAZMA HATASI");
                return;
            }

            fprintf(dosya_yaz, "%.2f", bakiye);
            fclose(dosya_yaz);
            printf("Odeme alindi. Bizi tercih ettiginiz icin tesekkur ederiz.\n");
        }

                }
       
       
    }
    
}




int main(){
    //!! CAFE UYGULAMASI
    char siparis[50];
    int siparisDongusu = 0;
    int fiyat = 0;
    char devamMi[20];
        printf("Merhaba Coffee Cafe'ye hosgeldiniz. Siparisiniz nedir?");

    //! MENU

    printf("\n\n\tKAHVELER\n1-Espresso(Fiyat 20 TL)\n2-Americano(Fiyat 30 TL)\n3-Latte(Fiyat 40 TL)\n4-Iced Latte(Fiyat 45 TL)\n\tYIYECEKLER\n1-Sandvic(Fiyat 90 TL)\n2-Omlet(Fiyat 100 TL)\n3-Brownie(Fiyat 50 TL)\n4-Muffin(Fiyat 60 TL)\n");
   do
   {
     printf("Almak istediginiz urunu yazin: ");
    fgets(siparis, sizeof(siparis), stdin);

    siparis[strcspn(siparis, "\n")] = '\0';

       if (strcasecmp(siparis, "espresso") == 0) {
        fiyat += ESPRESSO;
        printf("Espresso secildi. Afiyet olsun!\n");
    } else if (strcasecmp(siparis, "americano") == 0) {
        fiyat += AMERICANO;
        printf("Americano secildi. Afiyet olsun!\n");
    } else if (strcasecmp(siparis, "latte") == 0) {
        fiyat += LATTE;
        printf("Latte secildi. Afiyet olsun!\n");
    } else if (strcasecmp(siparis, "iced latte") == 0) {
        fiyat += ICEDLATTE;
        printf("Iced Latte secildi. Afiyet olsun!\n");
    } else if (strcasecmp(siparis, "sandvic") == 0) {
        fiyat += SANDVIC;
        printf("Sandvic secildi. Afiyet olsun!\n");
    } else if (strcasecmp(siparis, "omlet") == 0) {
        fiyat += OMLET;
        printf("Omlet secildi. Afiyet olsun!\n");
    } else if (strcasecmp(siparis, "brownie") == 0) {
        fiyat += BROWNIE;
        printf("Brownie secildi. Afiyet olsun!\n");
    } else if (strcasecmp(siparis, "muffin") == 0) {
        fiyat += MUFFIN;
        printf("Muffin secildi. Afiyet olsun!\n");
    } else {
        printf("Boyle bir urun bulunamadi. Lutfen menuden secim yapin.\n");
    }

    printf("Suan ki odemeniz gereken tutar: %d\nSiparise devam etmek ister misiniz?", fiyat);
    fgets(devamMi, sizeof(devamMi), stdin);
    devamMi[strcspn(devamMi, "\n")] = '\0';

    if(strcasecmp(devamMi, "evet") == 0){ 
        siparisDongusu = 1;
    }else{
        siparisDongusu = 0;
        printf("Odeme ekranina aktariliyorsunuz");
    }


   } while (siparisDongusu == 1);

   odeme(fiyat);
   



    return 0;
}
