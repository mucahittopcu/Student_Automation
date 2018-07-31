#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Eklenen kisinin bilgileri buraya ekleniyor.
struct ekle
{
    int numara;
    char ad[50];
    char soyad[50];
    int kayitsira;
    char ogretimturu[50];
    int gelogretimturu;

} yeni;

//Esit dagilim icin gerekli bilgiler buraya atiliyor.
struct dagilim2
{
    int numara[500];
    char ad[500][50];
    char soyad[500][50];
    int kayitsira[500];
    char ogretimturu[500][50];
} dagilim1ogr2[500],dagilim2ogr2[500];

//En az dagilim icin gerekli bilgiler buraya atiliyor.
struct dagilim
{
    int numara[500];
    char ad[500][50];
    char soyad[500][50];
    int kayitsira[500];
    char ogretimturu[500][50];
} dagilim1ogr[500],dagilim2ogr[500];

//dosya icindeki ogrenci bilgileri ogretim turune gore ayrılmıs bilgiler burada tutuluyor.
struct ogretim_turu_bolme
{
    int numara;
    char ad[50];
    char soyad[50];
    int kayitsira;
    char ogretimturu[3];
} ogretim1[500],ogretim2[500];

//cift kayit yapilmislar silinip ve numarası olmayanlara numara atanip bilgiler buraya ataniyor.
struct guncelleme
{
    int numara;
    char ad[50];
    char soyad[50];
    int kayitsira;
    char ogretimturu[3];
} sinif[500];


//Dosyadan cekilen bilgiler ilk olarak burda tutuluyor.
struct ogrenci
{
    char ad[50];
    char soyad[50];
    char numara[50];
    char kayitsira[50];
    char ogretimturu[3];
    int ogrnumara;
    int ogrkayitsira;
} liste[500];

int main()
{
    //Saat tutulmaya baslaniyor
    clock_t basla,bitir;
    basla=clock();
    printf("\t\t\t\t\tOGRENCI EKLE - SINIF DAGIT\n");
    FILE *dosya=fopen("ogrenci_listesi.txt","r");
    FILE *dosya2=fopen("numara_sirali_liste.txt","w");

   /* int numyeni[15];
    char adyeni[50];
    char soyadyeni[50];
    int kayitsirayeni=0;
    char ogretimturuyeni[3];*/

    int ogrencisayisi=-1;
    int birinciogretiim_ogrencisayisi;
    int ikinciogretiim_ogrencisayisi;

    int i,j=0,k=0;
//dosyadan bilgiler okunuyor.
    for(i=0;!feof(dosya); i++)
    {
        fscanf(dosya,"%s %s %s %s %s",&liste[i].numara,&liste[i].ad,&liste[i].soyad,&liste[i].kayitsira,&liste[i].ogretimturu);
        ogrencisayisi++;
    }

    int dizi[ogrencisayisi];
    int kontrol[ogrencisayisi];
    int kontroldizi_index[ogrencisayisi];

    //numaralar integer a cevriliyor.
    //okunan bilgileerde integer gerekli olanlar integera donusturuluyor.
    for(i=0; i<ogrencisayisi; i++)
    {
        liste[i+1].ogrnumara=atoi(liste[i+1].numara);
        liste[i+1].ogrkayitsira=atoi(liste[i+1].kayitsira);
    }

    //numara atamasi yapiliyor.
    for(i=0; i<ogrencisayisi; i++)
    {
        if(liste[i+1].ogrnumara==0)
        {
            if(!strcmp(liste[i+1].ogretimturu,"II"))
            {
                liste[i+1].ogrnumara=1700000+liste[i+1].ogrkayitsira+2000;
            }
            if(!strcmp(liste[i+1].ogretimturu,"I"))
            {
                liste[i+1].ogrnumara=1700000+liste[i+1].ogrkayitsira+1000;
            }
        }
    }
    //ayni olanlari buluyoruz.
    printf("Tekrar eden isimler silinmistir.\nIsimler:\n");
    int silinenogrsayisi=0;
    for(i=1; i<ogrencisayisi; i++)
    {
        if(!strcmp(liste[i].ad,liste[i+1].ad) && !strcmp(liste[i].soyad,liste[i+1].soyad))
        {
            liste[i+1].ogrnumara=0;
            printf("%8s %8s\n",liste[i+1].ad,liste[i+1].soyad);
            silinenogrsayisi++;
        }
    }


    int mevcut=ogrencisayisi-silinenogrsayisi;
    //ayni olanlari silliyoruz.
    for(i=0; i<ogrencisayisi; i++)
    {
        if(liste[i+1].ogrnumara!=0)
        {
            sinif[j].numara=liste[i+1].ogrnumara;
            strcpy(sinif[j].ad,liste[i+1].ad);
            strcpy(sinif[j].soyad,liste[i+1].soyad);
            sinif[j].kayitsira=liste[i+1].ogrkayitsira;
            strcpy(sinif[j].ogretimturu,liste[i+1].ogretimturu);
            j++;
        }
    }
    //Ekeleme burda yapilmaya baslaniyor.
    //Eklenecek kisinin bilgileir fonksiyonla alinip structa atiliyor. Ordanda buraya getiriliyor.
    FILE *yeniekle=fopen("ogrenci_listesi.txt","a+");
    int tercih;
bit:
    printf("\nOgrenci mi eklemek istersiniz? Mevcut listeden mi devam etmek istersiniz?\n");
    printf("Eklemek icin => 1'e Basiniz / \Devam etmek icin => 2'ye Basiniz ...\n");
    scanf("%d",&tercih);

    if(tercih==1)
    {
        kisiekle();
//       printf("sfdg");
    }
    else if(tercih==2)
    {
        goto devam;
    }
    else
    {
        printf("Yanlis giris yaptiniz!..\n");
        goto bit;
    }
    //Kaydi yapilan ogrencinin numarasi olup olmamdigi kontrol ediliyor.
    for(i=0;i<mevcut;i++)
    {
        if(yeni.numara==sinif[i].numara)
        {
            printf("\nGiridiginiz numara kayitta olan bir ogrenci ile cakismkatadir.Kayit iptal edilmistir.\n");
            goto gec;
        }
        else
        {

        }
    }
    //Girilen ogretim turune gore deger ataniyor.
    if(yeni.gelogretimturu==1)
    {
        strcpy(yeni.ogretimturu,"I");
    }
    else if(yeni.gelogretimturu==2)
    {
        strcpy(yeni.ogretimturu,"II");
    }
    fprintf(yeniekle,"\n%d\t %s\t %s\t %d\t %s",yeni.numara,yeni.ad,yeni.soyad,yeni.kayitsira,yeni.ogretimturu);
    ogrencisayisi++;
    mevcut++;
    //Burda girile bilgiler guncellenecek listeye ataniyor.
    sinif[j].numara=yeni.numara;
    strcpy(sinif[j].ad,yeni.ad);
    strcpy(sinif[j].soyad,yeni.soyad);
    sinif[j].kayitsira=yeni.kayitsira;
    strcpy(sinif[j].ogretimturu,yeni.ogretimturu);

devam:
gec:
    fclose(yeniekle);



    //numaralar bir diziye ataniyor.
    for(i=0; i<mevcut; i++)
    {
        dizi[i]=sinif[i].numara;
    }

    //numaralar siralanmak icin bir diziye gonderiliyor.
    //sonnra siralan numaralar bir dizeye geri donduruluyor.
    numarasiralama(dizi,mevcut,kontrol);

    for(i=0; i<mevcut; i++)
    {
        for(j=0; j<mevcut; j++)
        {
            if(kontrol[i]==sinif[j].numara)
            {
                kontroldizi_index[k]=j;
                k++;
            }
        }
    }
    //siralanan numaralar dosyaya yazdigiliyor.
    fprintf(dosya2,"%10s %15s %15s %15s %15s\n",liste[0].numara,liste[0].ad,liste[0].soyad,liste[0].kayitsira,liste[0].ogretimturu);
    for(i=0; i<mevcut; i++)
    {
        fprintf(dosya2,"%10d  %15s %15s %15d %15s\n",sinif[kontroldizi_index[i]].numara,sinif[kontroldizi_index[i]].ad,sinif[kontroldizi_index[i]].soyad,sinif[kontroldizi_index
                [i]].kayitsira,sinif[kontroldizi_index[i]].ogretimturu);
    }
    printf("\nKayit Siralari Guncellenmistir.\n\n");

    birinciogretiim_ogrencisayisi=birinciogretim(mevcut);
    ikinciogretiim_ogrencisayisi=ikinciogretim(mevcut);
    printf("Dersi alan ogrenci sayisi 1.ogretim: %d   2.ogretim: %d' dir.\n",birinciogretiim_ogrencisayisi,ikinciogretiim_ogrencisayisi);

    int sinifsayisi;
    printf("Lutfen sinif sayisini girin:");
    scanf("%d",&sinifsayisi);
    printf("Lutfen sinif kapasitelerini girin(Girerken ogrenci sayisini dikkate aliniz)\n");
    int a1=birinciogretiim_ogrencisayisi;
    int a2=ikinciogretiim_ogrencisayisi;
    int sinifkapasitesi[sinifsayisi];
    for(i=0; i<sinifsayisi; i++)
    {
        printf("%d . sinif kapasitesini giriniz\n", i+1);
        scanf("%d",&sinifkapasitesi[i]);
        a1=a1-sinifkapasitesi[i];
        a2=a2-sinifkapasitesi[i];

        if(a1>=0 && a2>=0)
        {
            printf("Birinci ogretimde kalan ogrenci sayisi = %d\n", a1);
            printf("Ikinci ogretimde kalan ogrenci sayisi = %d\n", a2);
        }
    }
    if(a1>0 && a2>0)
    {
        printf("\n***Kapasite ogrenci sayisindan az  icin oldugu sinif dagitma islemi iptal edildi !!!\n");
        goto git;
    }
    sinifdagit1(sinifkapasitesi,sinifsayisi);
    sinifdagit12(sinifkapasitesi,sinifsayisi);
    sinifdagit2(sinifkapasitesi,sinifsayisi);
    sinifdagit22(sinifkapasitesi,sinifsayisi);

git:
    fclose(dosya2);
    fclose(dosya);

    bitir=clock();
    printf("\nIsleminiz %0.2f saniyede tamamlanmistir.\n",(bitir-basla)/1000.00);
}


void sinifdagit1(int sinifkapasitesi1[],int sinifsayisi1)
{
    //En az dagilim;
    int i,j,k=0;
    int enbuyuk_kapasite[sinifsayisi1];
    buyuktenkucuge_sirala(sinifkapasitesi1,sinifsayisi1,enbuyuk_kapasite);
    //Burada program onceden kulanilmis ise onceden acdigi dosyalari siliyor.
    for(i=0; i<30; i++)
    {
        char sinifadi1[60];
        sprintf(sinifadi1,"%d",i+1);
        char dosyaadi1[60]="En az dagilim ogr1sinif";
        char gercekad1[60];
        strcpy(gercekad1,strcat(dosyaadi1,sinifadi1));
        char ekle1[5]=".txt";
        strcat(gercekad1,ekle1);
        FILE *dosya1=fopen(gercekad1,"w");
        fclose(dosya1);
        remove(gercekad1);
    }

    for(i=0; i<sinifsayisi1; i++)
    {
        //her sinifa yeni dosya aciliyor.
        char sinifadi[60];
        sprintf(sinifadi,"%d",i+1);
        char dosyaadi[60]="En az dagilim ogr1sinif";
        char gercekad[60];
        strcpy(gercekad,strcat(dosyaadi,sinifadi));
        char ekle[5]=".txt";
        strcat(gercekad,ekle);
        FILE *dosya11=fopen(gercekad,"w");
        //Burda en buyuk kapasiteden baslanip tek tek siniflar dolduruluyor.
        for(j=0; j<enbuyuk_kapasite[i]; j++,k++)
        {
            dagilim1ogr[i].numara[j]=ogretim1[k].numara;
            strcpy(dagilim1ogr[i].ad[j],ogretim1[k].ad);
            strcpy(dagilim1ogr[i].soyad[j],ogretim1[k].soyad);
            dagilim1ogr[i].kayitsira[j]=ogretim1[k].kayitsira;
            strcpy(dagilim1ogr[i].ogretimturu[j],ogretim1[k].ogretimturu);

           if(dagilim1ogr[i].numara[j]!=0)
            {
                fprintf(dosya11,"%10d %15s %15s %15d %15s\n",dagilim1ogr[i].numara[j],dagilim1ogr[i].ad[j],dagilim1ogr[i].soyad[j],dagilim1ogr[i].kayitsira[j],dagilim1ogr[i].ogretimturu[j]);
            }
        }
        fclose(dosya11);
    }
}

//esit dailim
void sinifdagit12(int sinifkapasitesi12[],int sinifsayisi12)
{
    int m,z=0;
    int i,j;
    int sinif_kapasite_kontrol[sinifsayisi12];
    int enbuyuk_sinifkapasitesi[sinifsayisi12];
    numarasiralama(sinifkapasitesi12,sinifsayisi12,enbuyuk_sinifkapasitesi);
//her sinif icin sayaclar olusturuluyor.
    for(i=0; i<sinifsayisi12; i++)
    {
        sinif_kapasite_kontrol[i]=0;
    }
    //Kapasitasi en kucuk siniftan balaniyor.
    //her sinifa tek tek ogrenci atiliyor.
    //Eger sayac sinif kapasitesini asiyorsa o zaman o sinifa ogrenci atamiyor.
    for(i=0;i<enbuyuk_sinifkapasitesi[sinifsayisi12-1];i++)
    {
        for(m=0; m<sinifsayisi12; m++)
        {
            if(sinif_kapasite_kontrol[m]<sinifkapasitesi12[m])
            {
                dagilim1ogr2[m].numara[i]=ogretim1[z].numara;
                strcpy(dagilim1ogr2[m].ad[i],ogretim1[z].ad);
                strcpy(dagilim1ogr2[m].soyad[i],ogretim1[z].soyad);
                dagilim1ogr2[m].kayitsira[i]=ogretim1[z].kayitsira;
                strcpy(dagilim1ogr2[m].ogretimturu[i],ogretim1[z].ogretimturu);

                sinif_kapasite_kontrol[m]++;
                z++;
            }
        }
    }
    for(i=0; i<30; i++)
    {
        char sinifadi12[60];
        sprintf(sinifadi12,"%d",i+1);
        char dosyaadi12[60]="Esit dagilim ogr1sinif";
        char gercekad12[60];
        strcpy(gercekad12,strcat(dosyaadi12,sinifadi12));
        char ekle12[5]=".txt";
        strcat(gercekad12,ekle12);
        FILE *dosya12=fopen(gercekad12,"w");
        fclose(dosya12);
        remove(gercekad12);
    }
    for(i=0; i<sinifsayisi12; i++)
    {
        char sinifadi123[60];
        sprintf(sinifadi123,"%d",i+1);
        char dosyaadi123[60]="Esit dagilim ogr1sinif";
        char gercekad123[60];
        strcpy(gercekad123,strcat(dosyaadi123,sinifadi123));
        char ekle123[5]=".txt";
        strcat(gercekad123,ekle123);
        FILE *dosya123=fopen(gercekad123,"w");

        for(j=0;j<enbuyuk_sinifkapasitesi[sinifsayisi12-1];j++)
        {
            if(dagilim1ogr2[i].numara[j]!=0)
            {
                fprintf(dosya123,"%10d %15s %15s %15d %15s\n",dagilim1ogr2[i].numara[j],dagilim1ogr2[i].ad[j],dagilim1ogr2[i].soyad[j],dagilim1ogr2[i].kayitsira[j],dagilim1ogr2[i].ogretimturu[j]);
            }
        }
        fclose(dosya123);
    }
}

//en az dailim ikinci ogretimler icin
void sinifdagit2(int sinifkapasitesi2[],int sinifsayisi2)
{
   int i,j,k=0;
    int enbuyuk_kapasite2[sinifsayisi2];
    buyuktenkucuge_sirala(sinifkapasitesi2,sinifsayisi2,enbuyuk_kapasite2);

    for(i=0; i<30; i++)
    {
        char sinifadi2[60];
        sprintf(sinifadi2,"%d",i+1);
        char dosyaadi2[60]="En az dagilim ogr2sinif";
        char gercekad2[60];
        strcpy(gercekad2,strcat(dosyaadi2,sinifadi2));
        char ekle2[5]=".txt";
        strcat(gercekad2,ekle2);
        FILE *dosya26=fopen(gercekad2,"w");
        fclose(dosya26);
        remove(gercekad2);
    }

    for(i=0; i<sinifsayisi2; i++)
    {
        char sinifadi22[60];
        sprintf(sinifadi22,"%d",i+1);
        char dosyaadi22[60]="En az dagilim ogr2sinif";
        char gercekad22[60];
        strcpy(gercekad22,strcat(dosyaadi22,sinifadi22));
        char ekle22[5]=".txt";
        strcat(gercekad22,ekle22);
        FILE *dosya23=fopen(gercekad22,"w");

        for(j=0; j<enbuyuk_kapasite2[i]; j++,k++)
        {
            dagilim2ogr[i].numara[j]=ogretim2[k].numara;
            strcpy(dagilim2ogr[i].ad[j],ogretim2[k].ad);
            strcpy(dagilim2ogr[i].soyad[j],ogretim2[k].soyad);
            dagilim2ogr[i].kayitsira[j]=ogretim2[k].kayitsira;
            strcpy(dagilim2ogr[i].ogretimturu[j],ogretim2[k].ogretimturu);

            if(dagilim2ogr[i].numara[j]!=0)
            {
                fprintf(dosya23,"%10d %15s %15s %15d %15s\n",dagilim2ogr[i].numara[j],dagilim2ogr[i].ad[j],dagilim2ogr[i].soyad[j],dagilim2ogr[i].kayitsira[j],dagilim2ogr[i].ogretimturu[j]);
            }
        }
        fclose(dosya23);
    }
}
void sinifdagit22(int sinifkapasitesi22[],int sinifsayisi22)
{
    int m,z=0;
    int i,j;
    int sinif_kapasite_kontrol22[sinifsayisi22];
    int enbuyuk_sinifkapasitesi22[sinifsayisi22];
    numarasiralama(sinifkapasitesi22,sinifsayisi22,enbuyuk_sinifkapasitesi22);

    //her sinif icin sayaclar olusturuluyor.
    for(i=0; i<sinifsayisi22; i++)
    {
        sinif_kapasite_kontrol22[i]=0;
    }
    //Kapasitasi en kucuk siniftan balaniyor.
    //her sinifa tek tek ogrenci atiliyor.
    //Eger sayac sinif kapasitesini asiyorsa o zaman o sinifa ogrenci atamiyor.

    for(i=0;i<enbuyuk_sinifkapasitesi22[sinifsayisi22-1];i++)
    {
        for(m=0; m<sinifsayisi22; m++)
        {
            if(sinif_kapasite_kontrol22[m]<sinifkapasitesi22[m])
            {
                dagilim2ogr2[m].numara[i]=ogretim2[z].numara;
                strcpy(dagilim2ogr2[m].ad[i],ogretim2[z].ad);
                strcpy(dagilim2ogr2[m].soyad[i],ogretim2[z].soyad);
                dagilim2ogr2[m].kayitsira[i]=ogretim2[z].kayitsira;
                strcpy(dagilim2ogr2[m].ogretimturu[i],ogretim2[z].ogretimturu);

                sinif_kapasite_kontrol22[m]++;
                z++;
            }
        }
    }
    for(i=0; i<30; i++)
    {
        char sinifadi22[60];
        sprintf(sinifadi22,"%d",i+1);
        char dosyaadi22[60]="Esit dagilim ogr2sinif";
        char gercekad22[60];
        strcpy(gercekad22,strcat(dosyaadi22,sinifadi22));
        char ekle22[5]=".txt";
        strcat(gercekad22,ekle22);
        FILE *dosya22=fopen(gercekad22,"w");
        fclose(dosya22);
        remove(gercekad22);
    }
    for(i=0; i<sinifsayisi22; i++)
    {
        char sinifadi223[60];
        sprintf(sinifadi223,"%d",i+1);
        char dosyaadi223[60]="Esit dagilim ogr2sinif";
        char gercekad223[60];
        strcpy(gercekad223,strcat(dosyaadi223,sinifadi223));
        char ekle223[5]=".txt";
        strcat(gercekad223,ekle223);
        FILE *dosya223=fopen(gercekad223,"w");

        for(j=0;j<enbuyuk_sinifkapasitesi22[sinifsayisi22-1];j++)
        {
            if(dagilim1ogr2[i].numara[j]!=0)
           {
                fprintf(dosya223,"%10d %15s %15s %15d %15s\n",dagilim2ogr2[i].numara[j],dagilim2ogr2[i].ad[j],dagilim2ogr2[i].soyad[j],dagilim2ogr2[i].kayitsira[j],dagilim2ogr2[i].ogretimturu[j]);
           }
        }
        fclose(dosya223);
    }
}

//------------------------------------------------
//Birinci ve ikinci ogretimleri iki farkli txt de yazdiriyoruz.
int  birinciogretim(int mevcut)
{
    FILE *birinci=fopen("abirinciOgretimListe.txt","w");
    int i,j=0,k=0;
    int say1=0;
    for(i=0; i<mevcut; i++)
    {
        if(!(strcmp(sinif[i].ogretimturu,"I")))
        {
            ogretim1[j].numara=sinif[i].numara;
            strcpy(ogretim1[j].ad,sinif[i].ad);
            strcpy(ogretim1[j].soyad,sinif[i].soyad);
            ogretim1[j].kayitsira=sinif[i].kayitsira;
            strcpy(ogretim1[j].ogretimturu,sinif[i].ogretimturu);
            k=j++;
            say1++;
        }
    }

    fprintf(birinci,"%10s %15s %15s %15s %15s\n",liste[0].numara,liste[0].ad,liste[0].soyad,liste[0].kayitsira,liste[0].ogretimturu);
    for(j=0; j<=k; j++)
    {
        fprintf(birinci,"%10d %15s %15s %15d %10s\n",ogretim1[j].numara,ogretim1[j].ad,ogretim1[j].soyad,ogretim1[j].kayitsira,ogretim1[j].ogretimturu);
    }
    return say1;
    fclose(birinci);
}

int ikinciogretim(int mevcut)
{
    int say2=0;
    FILE *ikinci=fopen("aikinciOgretimListe.txt","w");
    int i,j=0,k=0;
    for(i=0; i<mevcut; i++)
    {
        if(!(strcmp(sinif[i].ogretimturu,"II")))
        {
            ogretim2[j].numara=sinif[i].numara;
            strcpy(ogretim2[j].ad,sinif[i].ad);
            strcpy(ogretim2[j].soyad,sinif[i].soyad);
            ogretim2[j].kayitsira=sinif[i].kayitsira;
            strcpy(ogretim2[j].ogretimturu,sinif[i].ogretimturu);
            k=j++;
            say2++;
        }
    }
    fprintf(ikinci,"%10s %15s %15s %15s %15s\n",liste[0].numara,liste[0].ad,liste[0].soyad,liste[0].kayitsira,liste[0].ogretimturu);
    for(j=0; j<=k; j++)
    {
        fprintf(ikinci,"%10d %15s %15s %15d %10s\n",ogretim2[j].numara,ogretim2[j].ad,ogretim2[j].soyad,ogretim2[j].kayitsira,ogretim2[j].ogretimturu);
    }
    return say2;
    fclose(ikinci);
}

void numarasiralama(int sayi[],int mevcut,int *kontrol)
{
    int i,j;
    int gecici;
    for(i=0; i<mevcut; i++)
    {
        for(j=0; j<mevcut; j++)
        {
            if(sayi[i]<=sayi[j])
            {
                gecici=sayi[i];
                sayi[i]=sayi[j];
                sayi[j]=gecici;
            }
        }
    }

    for(i=0; i<mevcut; i++)
    {
        kontrol[i]=sayi[i];
    }
}
void buyuktenkucuge_sirala(int sayi1[],int mevcut1,int *kontrol1)
{
    int i,j;
    int gecici;
    for(i=0; i<mevcut1; i++)
    {
        for(j=0; j<mevcut1; j++)
        {
            if(sayi1[i]>=sayi1[j])
            {
                gecici=sayi1[i];
                sayi1[i]=sayi1[j];
                sayi1[j]=gecici;
            }
        }
    }

    for(i=0; i<mevcut1; i++)
    {
        kontrol1[i]=sayi1[i];
    }
}

void kisiekle(int numara,char ad[50],char soyad[50],int ogretimturu)
{

        printf("Lutfen ogrenci numarsini giriniz:");
        scanf("%d",&numara);
        printf("Lutfen ogrenci adini giriniz:");
        scanf("%s",ad);
        printf("Lutfen ogrenci soyadini giriniz:");
        scanf("%s",soyad);
        printf("Lutfen ogrencinin ogretim turunu giriniz:");
        scanf("%d",&ogretimturu);

        yeni.numara=numara;
        strcpy(yeni.ad,ad);
        strcpy(yeni.soyad,soyad);
        yeni.kayitsira=0;
        yeni.gelogretimturu=ogretimturu;
}

