/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ                                    *
**			        BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ               *
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ                          *
**				    PROGRAMLAMAYA GİRİŞİ DERSİ                              *
**                                                                          *
**				ÖDEV NUMARASI…...: Proje                                    *
**				ÖĞRENCİ ADI...............: Yavuz ARSLAN                    *
**				ÖĞRENCİ NUMARASI.: G201210087                               *
**				DERS GRUBU…………: 2.Öğretim B grubu                           *
****************************************************************************/








#include <Windows.h>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;


// buradaki bool değerini menü seçeneklerinde bir sıkıntı yaşadığım için atadım. Belki gerek yoktur ama çözemedim boolsuz.

static bool menu = true;

int main()
{

    // istenilen saat gösterimini oluşturmak için 
    time_t simdi = time(0);
#pragma warning(suppress : 4996)
    char* tarih = ctime(&simdi);
    cout << "Tarih ve saat: " << tarih << endl;

    // kullanıcı metninde bulunacak bilgiler

    string kullaniciIsim;
    string sifre;

    // okuyucu metninde bulunacak bilgiler

    string TcNo;
    string ad;
    string soyad;
    int uyeNo;
    string telefonNo;
    string dogumTarihi;
    string gorev;
    int kitapSayi;
    string kullaniciAd;
    string kullaniciSifre;

    string gecicitc;
    //kitaplar metninde bulunacak bilgiler

    string ISBN;
    string kitapIsmi;
    string yazarAdi;
    string yazarSoyadi;
    string konu;
    string tur;
    int sayfaSayisi;

    // ödünç metninde bulunacak bilgiler

    string isbn;
    string tcno;
    string oduncTarihi;
    string donusTarihi;
    char cevap;
    int secim;
    string isbnNo;


    //kullanicilar metnindeki bilgileri okumasını istiyorum.


    ifstream dosyaOku("kullanicilar.txt");


    //gerekli bilgilerin girilmesi girilmediği takdirde tekrardan giriş yapılabilmesi için bir do while döngüsünün içine soktum.

    do
    {
        cout << "Lutfen kullanici adinizi ve sifrenizi giriniz: " << endl;
        cout << "Kullanici adi: "; cin >> kullaniciAd;
        cout << "Kullanici sifre: "; cin >> kullaniciSifre;

        dosyaOku >> kullaniciIsim >> sifre;

    } while (kullaniciAd != kullaniciIsim || kullaniciSifre != sifre);

    system("CLS");


    // bütün menülerin içine alındığı ve sürekli diğer if'lerden çıkınca bu do while döngünüse dönülmesi için yazılan do while döngüsü.

    do
    {

        cout << "Yapmak istediginiz islemin numarasini giriniz." << endl;
        cout << "1- Kayit ekleme" << endl;
        cout << "2- Okuyucu kaydi guncelleme" << endl;
        cout << "3- Okuyucu silme" << endl;
        cout << "4- Okuyucu uzerindeki kitaplar listesi" << endl;
        cout << "5- Okuyucu kitap odunc alma" << endl;
        cout << "6- Okuyucu kitap geri dondurme" << endl;
        cout << "7- Kitap ekleme" << endl;
        cout << "8- Kitap silme" << endl;
        cout << "9- Kitap duzeltme" << endl;
        cout << "0- Cikis" << endl;
        cout << "Secim : ";
        cin >> secim;
        system("CLS");

        //okuyucu menüde ki 1. seçeneceği seçerse buradaki if koşuluna geliyor.

        if (secim == 1)

        {

            cout << endl << setw(30) << " KAYIT EKLEME\n\n ";

            ofstream dosyaYaz;
            dosyaYaz.open("okuyucular.txt", ios::app);

            //okuyucular dosyasına yazması için yazılan ofstream

            //girilen bilgileri okuyucular metnine yazıp kaydetmesi için yazılan do while döngüsü.

            do
            {

                cout << "Okuyucu kaydi icin lutfen bilgilerinizi giriniz." << endl;
                cout << "TC No : ";
                cin >> TcNo; cin.ignore();
                cout << "Ad : ";
                getline(cin, ad);
                cout << "Soyad : ";
                cin >> soyad;
                cout << "Telefon Numarasi : ";
                cin >> telefonNo;
                cout << "Dogum Tarihi : ";
                cin >> dogumTarihi; cin.ignore();
                cout << "Gorev : ";
                getline(cin, gorev);
                cout << "Okuyucu numarasi giriniz: ";
                cin >> uyeNo;

                dosyaYaz << TcNo << endl << ad << endl << soyad << endl << telefonNo << endl << dogumTarihi << endl << gorev << endl << uyeNo << endl << endl;
                cout << "Kaydiniz basariyla tamamlandi.";
                cout << endl << "Baska kayit yapacak misiniz? (E/e) (H/h) " << endl;
                cin >> cevap;

                //cevaplara göre gerekli yerlere yönlendiren koşullar.

                if (cevap == 'e' || cevap == 'E')
                {
                    continue;
                }
                else if (cevap == 'H' || cevap == 'h')
                {
                    break;
                }


            } while (true);


            dosyaYaz.close();
            cout << "Kayit basariyla olusturulmustur.\n";

            system("CLS");

            //okuyucu menüde ki 2. seçeneceği seçerse buradaki if koşuluna geliyor.


        }
        if (secim == 2)
        {

            cout << "Lutfen Tc No'yu giriniz: ";
            cin >> gecicitc;


			//okuyucular dosyasını okutma
        	// gecici olarak bilgileri kaydetsin diye bir text oluşturdum
        	
            ifstream dosyaOku("okuyucular.txt");
            ofstream dosyaYaz("gecici.txt");

            while (true)
            {
                dosyaOku >> TcNo;
                dosyaOku.ignore();
                getline(dosyaOku, ad);
                dosyaOku >> soyad;
                dosyaOku >> telefonNo;
                dosyaOku >> dogumTarihi;
                dosyaOku.ignore();
                getline(dosyaOku, gorev);
                dosyaOku >> uyeNo;

                //dosyanın sonuna geldiğini anlaması için oluşturulan bir if
            	
                if (dosyaOku.eof())
                {
                    break;
                }

                // eğer doğru tc ise güncelleştirilmesi gereken bilgileri okutup yazılmasını isteyen if koşulu.
            	
                if (TcNo == gecicitc)
                {

                    cout << setw(28) << " Kayit Guncelleme" << endl << endl;
                    cout << setw(14) << "Kayitli Bilgiler " << endl;
                    cout << TcNo << endl;
                    cout << ad << endl;
                    cout << soyad << endl;
                    cout << telefonNo << endl;
                    cout << dogumTarihi << endl;
                    cout << gorev << endl;
                    cout << uyeNo << endl;
                    cout << setw(14) << "Yeni Degerler Girisi" << endl;
                    cout << "TC No : ";
                    cin >> TcNo;
                    cin.ignore();
                    cout << "Ad : ";
                    getline(cin, ad);
                    cout << "Soyad : ";
                    cin >> soyad;
                    cout << "Telefon No : ";
                    cin >> telefonNo;
                    cout << "Dogum Tarihi : ";
                    cin >> dogumTarihi;
                    cin.ignore();
                    cout << "Gorev : ";
                    getline(cin, gorev);
                    cout << "Uye No : ";
                    cin >> uyeNo;
                    cout << endl;
                    dosyaYaz << TcNo << endl << ad << endl << soyad << endl << telefonNo << endl << dogumTarihi << endl
                        << gorev << endl << uyeNo << endl << endl;


                    continue;

                }
                else
                {
                    dosyaYaz << TcNo << endl << ad << endl << soyad << endl << telefonNo << endl << dogumTarihi << endl
                        << gorev << endl << uyeNo << endl << endl;
                }
            }

            system("CLS"); //ekranı temizlemesi için
            dosyaYaz.close(); //kapatmak için
            dosyaOku.close(); // kapatmak için
            remove("okuyucular.txt"); // kaldırılacak dosya 
            rename("gecici.txt", "okuyucular.txt"); // geçici texti okuyucular olarak değiştiren satır
            cout << "Kayit basariyla guncellendi.";
        }

        if (secim == 3)
        {


            cout << "      Kullanici Silme     " << endl;
            cout << "Tc No:  ";
            cin >> gecicitc;
            ifstream dosyaOku("okuyucular.txt");
            ofstream dosyaYaz("okuyucular.tmp");

        	// dosyaOku end of file olana kadar while döngüsünde kalsın
        	
            while (!dosyaOku.eof())
            {

                dosyaOku >> TcNo >> ad >> soyad >> telefonNo >> dogumTarihi >> gorev >> uyeNo;

                //dosyanın sonuna geldiğini anlayıp ana döngüye dönsün diye
            	
                if (dosyaOku.eof())
                {
                    break;
                }

                // doğru tc ise silinecek kullanıcıyı silme
            	
                if (gecicitc == TcNo)
                {

                    cout << "Dosyadaki Kayitlar" << endl;
                    cout << TcNo << endl;
                    cout << ad << endl;
                    cout << soyad << endl;
                    cout << telefonNo << endl;
                    cout << dogumTarihi << endl;
                    cout << gorev << endl;
                    cout << uyeNo << endl << endl;

                }

                // diğer okuyucuları yazdıran blok
            	
                else
                {

                    dosyaYaz << endl << TcNo << endl << ad << endl << soyad << endl << telefonNo << endl << dogumTarihi << endl
                        << gorev << endl << uyeNo << endl << endl;

                }
            }

        	
            system("CLS");
            dosyaYaz.close();
            dosyaOku.close();
            remove("okuyucular.txt");
            rename("okuyucular.tmp", "okuyucular.txt"); 
            cout << "Kayit basariyla silindi." << endl;
        	
        	
        }


        // Kitapları ödünç textinde görebiliyorum ama ekrana yazdıramıyorum hocam o yüzden tam çalışmadığı için yorum satırlarını yazmayacağım.


        if (secim == 4)
        {

            cout << "        Okuyucu uzerineki kitaplar        " << endl << endl;
            cout << "Tc No: ";
            cin >> gecicitc;

            ifstream dosyaOku("Odunc.txt");
            while (!dosyaOku.eof())
            {


                dosyaOku >> isbn;
                dosyaOku >> TcNo;

                if (dosyaOku.eof())
                {
                    break;
                }

                if (TcNo == gecicitc)
                {

                    ifstream dosyaOku("Kitaplar.txt");
                    dosyaOku >> ISBN >> kitapIsmi >> yazarAdi >> yazarSoyadi >> konu >> tur >> sayfaSayisi;
                    if (ISBN == isbn)
                    {

                        cout << ISBN;
                        cout << kitapIsmi;
                        cout << yazarAdi;
                        cout << yazarSoyadi;
                        cout << konu;
                        cout << tur;
                        cout << sayfaSayisi;


                    }
                    else
                    {
                        cout << "Kitap bulunamadi." << endl;
                    }

                }

            }
        }

        // 5.koşul seçilirse buraya getiren kod bloğu
    	
        if (secim == 5)
        {

            ofstream dosyaYaz;
            dosyaYaz.open("Odunc.txt", ios::app);
            cout << "       KITAP ODUNC ALMA     " << endl;


        	// cevap evet olana kadar kitabın ödünç alınmasını sağlayan do while döngüsü
            do
            {

                cout << "TC No : ";
                cin >> TcNo;
                cout << "Kitabin ISBN kodu : ";
                cin >> isbn;




                ofstream dosyaYaz("Odunc.txt", ios::app);
                dosyaYaz << TcNo << endl << isbn << endl << endl;
                cout << "Odunc aldiginiz kitap kaydedildi.";
                cout << endl << "Baska kayit yapacak misiniz? (E/e) (H/h) " << endl;
                cin >> cevap;


            } while (cevap == 'e' || cevap == 'E');
            system("CLS");


        }

    	//6.koşulu seçince buraya gelmesini sağlayan if koşulu.
        
        if (secim == 6)
        {

            cout << "KITAP GERI VERME" << endl;
            cout << "TC No : ";
            cin >> gecicitc;
            ifstream dosyaOku("Odunc.txt");
            ofstream dosyaYaz("odunc.tmp");

            //dosyaOku end of file olana kadar while döngüsünde kalsın

        	while (!dosyaOku.eof())
            {
                dosyaOku >> TcNo >> isbn;


        		if (TcNo == gecicitc) // tcnin üzerinde kitap varsa direkt geri vermesi için önce tc eşleşmesi yapan kod bloğu
                {
                    cout << "DOSYADAKI KAYITLAR" << endl;
                    cout << "Kullanici TC No : " << TcNo << endl;
                    cout << "Kitap ISBN : " << isbn << endl;
                    break;

                }
                else
                {
                    dosyaYaz << TcNo << endl << isbn << endl << endl;
                }
            }
            system("CLS");
            dosyaYaz.close();
            dosyaOku.close();
            remove("Odunc.txt");
            rename("odunc.tmp", "Odunc.txt");
            cout << "Kitap geri verildi." << endl;
            


        }


        // 7.seçimi seçen kullanıcının burayya gelmesi için yazılan kod bloğu
    	
        if (secim == 7)
        {

            ofstream dosyaYaz;
            dosyaYaz.open("Kitaplar.txt", std::ios_base::app);


            // tekrardan başka kayıt yapacak mısınız cevabına evet derse kullanıcı tekrardan do while döngüsünün başına dönmesi için yazılan kod bloğu

        	do
            {
                cout << "        KITAP EKLEME        " << endl;
                cout << "Kitap eklemek icin lutfen kitap bilgilerini giriniz." << endl;
                cout << "ISBN : ";
                cin >> ISBN; cin.ignore();
                cout << "Kitap Ismi : ";
                getline(cin, kitapIsmi);
                cout << "Yazarin Adi : ";
                getline(cin, yazarAdi);
                cout << "Yazarin Soyadi : ";
                getline(cin, yazarSoyadi);
                cout << "Kitabin Konusu : ";
                getline(cin, konu);
                cout << "Kitabin Turu : ";
                getline(cin, tur);
                cout << "Kitabin Sayfa Sayisi : ";
                cin >> sayfaSayisi;

                dosyaYaz << ISBN << endl << kitapIsmi << endl << yazarAdi << endl << yazarSoyadi << endl << konu << endl << tur << endl << sayfaSayisi << endl << endl;
                cout << "Kitap, listeye basarili bir sekilde eklendi..." << endl;
                cout << endl << "Baska kayit yapacak misiniz?(e/E) (h/H) " << endl;
                cin >> cevap;

                cout << "Kitabiniz basariyla eklenmistir" << endl;
                system("CLS");

            } while (cevap == 'e' || cevap == 'E');

            dosyaYaz.close();



        }





        //kullanıcı 8.seçeneği seçtiğinde buraya gelmesi için yazılan if koşulu.

        if (secim == 8)
        {


            cout << "      Kitap Silme     " << endl;
            cout << "ISBN:  ";
            cin >> isbnNo;
            ifstream dosyaOku("Kitaplar.txt");
            ofstream dosyaYaz("gecici.txt");

            // dosyaOku end of file olana kadar while döngüsünde kalsın

            while (!dosyaOku.eof())
            {

                dosyaOku >> ISBN >> kitapIsmi >> yazarAdi >> yazarSoyadi >> konu >> tur >> sayfaSayisi;

                //dosyanın sonuna geldiğini anlayıp ana döngüye dönsün diye

                if (dosyaOku.eof())
                {
                    break;
                }

                // doğru isbn ise silinecek kullanıcının bilgileri.

                if (ISBN == isbnNo)
                {

                    cout << "Dosyadaki Kayitlar" << endl;
                    cout << ISBN << endl;
                    cout << kitapIsmi << endl;
                    cout << yazarAdi << endl;
                    cout << yazarSoyadi << endl;
                    cout << konu << endl;
                    cout << tur << endl;
                    cout << sayfaSayisi << endl << endl;

                }

                // diğer kitapları yazdıran blok

                else
                {

                    dosyaYaz << ISBN << endl << kitapIsmi << endl << yazarAdi << endl << yazarSoyadi << endl << konu << endl << tur << endl << sayfaSayisi << endl << endl;
                }
            }


            system("CLS");
            dosyaYaz.close();
            dosyaOku.close();
            remove("Kitaplar.txt");
            rename("gecici.txt", "Kitaplar.txt");
            cout << "Kayit basariyla silindi." << endl;

            
        }


        
        // 9.seçeneği seçerlerse buraya gelmesi için gerekli if bloğu.


        if (secim == 9)
        {

            cout << "Lutfen ISBN kodunu giriniz ";
            cin >> isbnNo;


            ifstream dosyaOku("Kitaplar.txt");
            ofstream dosyaYaz("gecici.txt");

            // gerekli bilgileri hedef metin belgesinden okutmak için yazılan while döngüsü
 
            while (true)
            {
                
                dosyaOku >> ISBN;
                dosyaOku.ignore();
                getline(dosyaOku, kitapIsmi);
                getline(dosyaOku, yazarAdi); 
                getline(dosyaOku, yazarSoyadi); 
                getline(dosyaOku, konu); 
                getline(dosyaOku, tur); 
                dosyaOku >> sayfaSayisi;

                // dosya end of file olunca ana menüye dönmesi için.
                
                if (dosyaOku.eof())
                {
                    

                    break;
                }

                // girilen isbn eğer doğru isbn se bilgileri düzeltmek amacıyla.

                if (ISBN==isbnNo)
                {

                    

                    cout << "        KITAP DUZELTME    " << endl << endl;
                    cout << "KAYITLI BILGILER " << endl;
                    cout << ISBN << endl;
                    cout << kitapIsmi << endl;
                    cout << yazarAdi << endl;
                    cout << yazarSoyadi << endl;
                    cout << konu << endl;
                    cout << tur << endl;
                    cout << sayfaSayisi << endl;

                    cout << "YENI DEGERLER GIRISI " << endl;
                    cout << "ISBN : ";
                    cin >> ISBN;
                	cin.ignore();   
                    cout << "Kitap Ismi : ";
                    getline(cin, kitapIsmi);
                    cout << "Yazarin Adi : ";
                    getline(cin, yazarAdi);
                    cout << "Yazarin Soyadi : ";
                    getline(cin, yazarSoyadi);
                    cout << "Kitabin Konusu : ";
                    getline(cin, konu);
                    cout << "Kitabin Turu : ";
                    getline(cin, tur);
                    cout << "Kitabin Sayfa Sayisi : ";
                    cin >> sayfaSayisi;
                    cout << endl;

                	
                    dosyaYaz << ISBN << endl << kitapIsmi << endl << yazarAdi << endl << yazarSoyadi << endl << konu << endl
                        << tur << endl << sayfaSayisi << endl << endl;



                }
                else
                {
                    dosyaYaz << ISBN << endl << kitapIsmi << endl << yazarAdi << endl << yazarSoyadi << endl << konu << endl
                        << tur << endl << sayfaSayisi << endl << endl;
                }
            }

            system("CLS");
            dosyaYaz.close();
            dosyaOku.close();
            remove("Kitaplar.txt");
            rename("gecici.txt", "Kitaplar.txt");
            cout << "Kayit basariyla guncellendi.";

        	// kullanıcı çıkış yapması için gerekli kod bloğu
        	// kullanıcının çıkış yaptığı tarihi de görebilmesi için ekrana anlık saati yazdıran kod var.

        }if (secim == 0)
        {
            menu = false;

            time_t simdi = time(0);
			#pragma warning(suppress : 4996)
            char* tarih = ctime(&simdi);
            cout << "Tarih ve saat: " << tarih << endl;

            cout << "Sistemden cikis yaptiniz." << endl;


        }

    } while (menu);

}