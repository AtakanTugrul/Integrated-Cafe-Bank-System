# Integrated-Cafe-Bank-System
C ile geliştirdiğim bu projede, birbiriyle haberleşen iki farklı sistem tasarladım. Amaç, sadece kod yazmak değil, iki farklı programın aynı veri kaynağını (bakiye.txt) kullanarak nasıl senkronize çalışabileceğini simüle etmekti.

Kart.c (Banka): Buradan hesabınıza para yatırıp çekebiliyorsunuz. Bakiyeniz anlık olarak kaydediliyor.

Cafe.c : Buradan sipariş veriyorsunuz. Ödeme kısmında "Kredi Kartı" seçerseniz, program gidip ATM'nin oluşturduğu dosyayı okuyor ve parayı oradan tahsil ediyor.

bakiye.txt: İki programın ortak kullandığı hafıza. Veriler RAM'de değil, bu dosyada tutulduğu için programı kapatsanız bile bakiyeniz silinmiyor.


Önce atm_sistemi.c kodunu çalıştırın ve hesabınıza biraz para yatırın (Dosya oluşması için bu şart).

Daha sonra cafe_otomasyonu.c kodunu çalıştırın ve dilediğiniz siparişi verin.

Ödeme ekranında kartı seçtiğinizde, bakiyenizin otomatik olarak düştüğünü göreceksiniz.

Neler Kullandım?
C Programlama Dili

File Handling (Dosya İşlemleri): fopen, fprintf, fscanf fonksiyonları ile veri okuma/yazma.

Entegre Sistem Mantığı: Farklı modüllerin veri paylaşımı.
