/*=================================================================================*\
|	NAMA APLIKASI 	: APLIKASI PERHITUNGAN RATA RATA PENGELUARAN MAHASISWA KOST		|	
|																					|
|	MATA KULIAH 	: STRUKTUR DATA													|
|																					|
|	KELOMPOK 		: 08															|
|																					|
|	ANGGOTA 		: [002] SAHID MA'ARIF											|
|																					|
|					  [014] RIZKI NUR R Y											|
|																					|
|					  [049] SUPRAYOGI BUDHI											|
\*---------------------------------------------------------------------------------*/

#include <iostream>
//#include <cstdlib>
#include <windows.h>
#include <fstream>
//#include <conio.h>
#include <iomanip>
//#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <dos.h>
#include <string>
#define max 15

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

class kost
{
	friend ostream& operator<<(ostream&, const kost&);  //belum kepikiran buat apa
	friend istream& operator>>(istream&, kost&); 
	public:
		void gotoXY(int, int);
		void menu();
		void keluar();
		void logo();
		void loading();
		void tampilData();
		void iyatidak(int, int);
		void inputbarang(int);
		void caricari();
		void atur();
		carapake();
		testdoang(int, int, int);
		tema(int);
	private:
		struct{
			string nama;		//nama mahasiswa
			string almt_rumah;	//alamat rumah mahasiswa
			string almt_kost;	//alamat kost mahasiswa
			string univ;		//nama universitas
			string jurusan;		//nama jurusan yg diambil
			int thn_kuliah;		//tahun masuk kuliah
			float harga_sewa; 	//harga sewa kost perbulan
			int atur;
		}data_siswa;
		struct{
			string nama_barang;	//nama barang yg dibeli perharinya
			int jumlah;			//jumlah dari barang yg dibeli
			int harga_satuan;	//harga satuan dari barang yang dibeli
			int total;			//total harga = satuan x jumlah
			string waktu;
		}data_kluaran[max];		//ntah ini termasuk array statis gak..
		int w;
};

garis()
{
	cout<<"-------------------------------------------------------------";
}

string aturan[] = 
{"Isi Data Mahasiswa Terlebih Dahulu",
"Tekan Sembarang Untuk Kembali (jangan tombol power)", "Kelompokkan Beberapa Barang Untuk Mempermudah Input Data",
"Gunakan Anak Panah Untuk Memilih Kemudian Tekan Enter", "Gunakan Underscore(_) Untuk Mengganti Fungsi Spasi"
};

void kost::menu()
{
	system("cls");
	kost k;
	gotoXY(24, 3);	cout<<"-= APLIKASI PERHITUNGAN RATA-RATA PENGELUARAN HARIAN MAHASISWA KOST =-";
	gotoXY(46, 4);	cout<<"TIM 08 - [002, 014, 049]";
 	gotoXY(48, 7);	cout<<"M E N U   U T A M A*";
	int menu_item = 0, run, y = 9;
	bool running = true;
	
	gotoXY(44, 9);	cout<<">>";
	while(running)
	{
		gotoXY(47, 9);	cout<<"[1] INPUT DATA";
		gotoXY(47, 10);	cout<<"[2] RATA RATA PENGELUARAN";
		gotoXY(47, 11);	cout<<"[3] PENCARIAN DATA";
		gotoXY(47, 12);	cout<<"[4] PENGATURAN";
		gotoXY(47, 13);	cout<<"[5] KELUAR";
		gotoXY(5, 28);	cout<<"*) "<<aturan[3];
		system("pause>nul");
		
		if(GetAsyncKeyState(VK_DOWN) && y != 13)
		{
			gotoXY(44, y);	cout<<"  ";	y++;
			gotoXY(44, y);	cout<<">>";	menu_item++;
			continue;
		}
		if(GetAsyncKeyState(VK_UP) && y != 9)
		{
			gotoXY(44, y);	cout<<"  ";	y--;
			gotoXY(44, y);	cout<<">>";	menu_item--;
			continue;
		}
		if(GetAsyncKeyState(VK_RETURN))
		{
			switch(menu_item)
			{
				case 0: //input mahasiswa
					cin>>k;
					running = false;
					menu();
					break;
				case 1: //perhitungan
					tampilData();
					running = false;
					menu();
					break;
				case 2: //pencarian data
					caricari();
					running = false;
					menu();
					break;
				case 3: //pengaturan
					running = false;
					atur();
					running = false;
					menu();
					running = false;
					break;
				case 4:	//menu keluar
					running = false;
					keluar();
//					menu();
					break;
			}
		}
	}
	running = false;
}

istream& operator>>(istream& in, kost& x) //input data mahasiswa
{
	system("cls");
	int qq = 0;
	x.gotoXY(29, 2);	garis();
	x.gotoXY(29, 3);	cout<<"||\t\t\t   MENU INPUT DATA\t\t\t||";
	x.gotoXY(29, 4);	garis();
	x.gotoXY(29, 6);	cout<<"Masukkan Data Mahasiswa Terlebih Dahulu";	
	ifstream file2;
	file2.open("inputdata.txt");
	if (!file2)
	{	
		file2.close();
	ofstream wer;
	wer.open("inputdata.txt");
	
		x.gotoXY(29, 8);	cout<<"Nama Mahasiswa\t\t: ";			getline(in, x.data_siswa.nama);
		x.gotoXY(29, 9);	cout<<"Alamat Rumah\t\t: ";				getline(in, x.data_siswa.almt_rumah);
		x.gotoXY(29, 10);	cout<<"Alamat Kost\t\t: ";				getline(in, x.data_siswa.almt_kost);
		x.gotoXY(29, 11);	cout<<"Nama Universitas\t\t: ";			getline(in, x.data_siswa.univ);
		x.gotoXY(29, 12);	cout<<"Nama Jurusan\t\t: ";				getline(in, x.data_siswa.jurusan);
		x.gotoXY(29, 13);	cout<<"Tahun Ajaran Masuk Kuliah\t: ";	in>>x.data_siswa.thn_kuliah;
		x.gotoXY(29, 14);	cout<<"Harga Sewa Kost Per Bulan\t: ";	in>>x.data_siswa.harga_sewa;
	x.w = 1;
	wer<<x.w<<" "<<x.data_siswa.nama<<" "<<x.data_siswa.almt_rumah<<" "<<x.data_siswa.almt_kost<<" "
	<<x.data_siswa.univ<<" "<<x.data_siswa.jurusan<<" "<<x.data_siswa.thn_kuliah<<" "
	<<x.data_siswa.harga_sewa<<" ";
	wer.close();
	
		x.gotoXY(29, 16);	cout<<"Lanjutkan Mengisi Data Pengeluaran."<<endl;		Sleep(490);
		x.gotoXY(29, 16);	cout<<"Lanjutkan Mengisi Data Pengeluaran.."<<endl;		Sleep(490);
		x.gotoXY(29, 16);	cout<<"Lanjutkan Mengisi Data Pengeluaran..."<<endl;	Sleep(490);
		cin.ignore();		x.inputbarang(qq);
	}
	else{
		x.inputbarang(qq);
	}
	return in;
}

void kost::tampilData() //menampilkan data
{
	system("cls");
	ifstream files("barang.txt");
	if(!files)
	{
		gotoXY(43, 8);	cout<<aturan[0];
		Sleep(2000);
		menu();
	}
	string data, data4;
	int data1, data2, data3;
	int rata;
	int x = 9, i = 0, qq = 0, tot = 0;
	
	gotoXY(34, 4);	cout<<"DATA PENGELUARAN HARIAN MAHASISWA KOST SELAMA 1 MINGGU";
	gotoXY(29, 6);	cout<<"+====+=====================+======+=============+=============+";
	gotoXY(29, 7);	cout<<"| NO |     Nama Barang     |Jumlah|    Harga    |    Total    |";
	gotoXY(29, 8);	cout<<"+====+=====================+======+=============+=============+";
	while(files >> data >> data1 >> data2 >> data3 >> data4 )
	{	
		data_kluaran[qq].nama_barang = data;
		data_kluaran[qq].jumlah = data1;
		data_kluaran[qq].harga_satuan = data2;
		data_kluaran[qq].total = data3;
		data_kluaran[qq].waktu = data4;
		gotoXY(29, x);	cout<<setiosflags(ios::left)<<"| "<<setw(2)<<i+1<<" | "<<setiosflags(ios::left)
		<<setw(19)<<data_kluaran[qq].nama_barang<<" | "<<setw(4)<<data_kluaran[qq].jumlah<<" | Rp."
		<<setw(8)<<data_kluaran[qq].harga_satuan<<" | Rp."<<setw(8)<<data_kluaran[qq].total<<" |"<<endl;
		x++;	i++;	qq++;
		tot += data3;
	}
	rata = (tot / 7 )/ qq;
	gotoXY(29, x);	cout<<"+----+---------------------+------+-------------+-------------+";	x++;
	gotoXY(29, x);	cout<<"Rata Rata Pengeluaran Harian = Rp."<<rata<<",-";
	gotoXY(5, 28);	cout<<"*) "<<aturan[1];
	files.close();
	
	system("pause>nul");
}

kost::testdoang(int o, int z, int zz)
{
	ifstream filex("barang.txt");
	string data, data4;
	int data1, data2, data3;
	int x = 13, qq = 0;
	while(filex >> data >> data1 >> data2 >> data3 >> data4)
	{	
		data_kluaran[qq].nama_barang = data;
		data_kluaran[qq].jumlah = data1;
		data_kluaran[qq].harga_satuan = data2;
		data_kluaran[qq].total = data3;
		data_kluaran[qq].waktu = data4;
		qq++;
	}
	gotoXY(29, 10);	cout<<"+====+=====================+======+=============+=============+";
	gotoXY(29, 11);	cout<<"| NO |     Nama Barang     |Jumlah|    Harga    |    Total    |";
	gotoXY(29, 12);	cout<<"+====+=====================+======+=============+=============+";
	for(int i=0;i<qq;i++){
		if(data_kluaran[i].jumlah == z && o == 1){
			gotoXY(29, x);	cout<<setiosflags(ios::left)<<"| "<<setw(2)<<i+1<<" | "<<setiosflags(ios::left)
			<<setw(19)<<data_kluaran[i].nama_barang<<" | "<<setw(4)<<data_kluaran[i].jumlah<<" | Rp."
			<<setw(8)<<data_kluaran[i].harga_satuan<<" | Rp."<<setw(8)<<data_kluaran[i].total<<" |"<<endl;
			x++;
		}
		if(data_kluaran[i].harga_satuan >= z && data_kluaran[i].harga_satuan <= zz && o == 2){
			gotoXY(29, x);	cout<<setiosflags(ios::left)<<"| "<<setw(2)<<i+1<<" | "<<setiosflags(ios::left)
			<<setw(19)<<data_kluaran[i].nama_barang<<" | "<<setw(4)<<data_kluaran[i].jumlah<<" | Rp."
			<<setw(8)<<data_kluaran[i].harga_satuan<<" | Rp."<<setw(8)<<data_kluaran[i].total<<" |"<<endl;
			x++;
		}
	}
	gotoXY(29, x);	cout<<"+----+---------------------+------+-------------+-------------+";
	filex.close();
}

void kost::caricari() //mencari data
{
	system("cls");
	ifstream files("barang.txt");
	if(!files)
	{
		gotoXY(43, 8);	cout<<aturan[0];
		Sleep(2000);
		menu();
	}
	files.close();
	gotoXY(5, 29);	cout<<"*) "<<aturan[3];
	gotoXY(29, 2);	garis();
	gotoXY(29, 3);	cout<<"||\t\t     MENU PENCARIAN DATA PENGELUARAN\t\t||";
	gotoXY(29, 4);	garis();
	gotoXY(29, 6);	cout<<"Cari Berdasarkan* : JUMLAH / harga";
	gotoXY(5, 28);	cout<<"-) "<<aturan[1];
	
	int menu_item = 0;
	bool running = true;
	
	while(running)
	{
		system("pause>nul");
		if(GetAsyncKeyState(VK_RETURN))
		{
			switch(menu_item)
			{
				case 0:
					int jml;
					gotoXY(29, 8);	cout<<"JUMLAH = ";
					cin>>jml;
					cin.ignore();
					running = false;
					testdoang(1, jml, 0);
					break;
				case 1:
					int hrg, hrg2;
					gotoXY(29, 8);	cout<<"HARGA >= ";	cin>>hrg;
					gotoXY(47, 8);	cout<<"s.d. ";	cin>>hrg2;
					cin.ignore();
					running = false;
					testdoang(2, hrg, hrg2);
					break;
			}
		}
		if(GetAsyncKeyState(VK_RIGHT) && menu_item != 1)
		{
			gotoXY(29, 6);	cout<<"Cari Berdasarkan* : jumlah / HARGA";
			menu_item++;
			continue;
		}
		if(GetAsyncKeyState(VK_LEFT) && menu_item != 0)
		{
			gotoXY(29, 6);	cout<<"Cari Berdasarkan* : JUMLAH / harga";
			menu_item--;
			continue;
		}
	}
	
	system("pause>nul");
}

void kost::inputbarang(int qq)  //input data pengeluaran
{
	system("cls");
	
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	
	gotoXY(29, 2);	garis();
	gotoXY(29, 3);	cout<<"||\t\t\t   MENU INPUT DATA\t\t\t||";
	gotoXY(29, 4);	garis();
	gotoXY(29, 6);	cout<<"Masukkan Data Pengeluaran Mahasiswa Selama 1 Minggu";
	gotoXY(5, 28);	cout<<"-) "<<aturan[4];
	gotoXY(5, 29);	cout<<"*) "<<aturan[2];
	gotoXY(29, 8);	cout<<"Nama Barang\t\t: ";				getline(cin, data_kluaran[qq].nama_barang);
	gotoXY(29, 9);	cout<<"Jumlah Barang\t\t: ";			cin>>data_kluaran[qq].jumlah;
	gotoXY(29, 10);	cout<<"Harga Satuan\t\t: ";				cin>>data_kluaran[qq].harga_satuan;
	cin.ignore();
	data_kluaran[qq].total = data_kluaran[qq].jumlah * data_kluaran[qq].harga_satuan;
	cout<<"Total Harga\t: "<<data_kluaran[qq].total;
	
	system("cls");
	gotoXY(40, 10);	cout<<"Ingin Memasukkan Lagi Data Pengeluaran?";

	strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
	string str(buffer);
	data_kluaran[qq].waktu = str;

	iyatidak(3, qq);
}

void kost::logo() //tambahan tampilan awal
{
gotoXY(46,5);	cout<<" %%%%%%%%%%%%%%%%%%%%%%%%%%%%/";                                           
gotoXY(46,6);	cout<<"/@                           /@";                               
gotoXY(46,7);	cout<<"/@      S T R U K T U R      /@";                               
gotoXY(46,8);	cout<<"/@                           /@";                               
gotoXY(46,9);	cout<<"/@          D A T A          /@";                               
gotoXY(46,10);	cout<<"/@                           /@";                               
gotoXY(46,11);	cout<<"/@        T I M   0 8        /@";                               
gotoXY(46,12);	cout<<"/@                           /@";                               
gotoXY(46,13);	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*";                               
gotoXY(43,14);	cout<<"@////////////###########///////////(@  "<<endl;                           
gotoXY(41,15);	cout<<"/////////////////@@@@@@#////////////////&"<<endl;
}

void kost::loading() //bawahnya logo
{
	char a = 177, b = 219;
	ifstream files;
	files.open("inputdata.txt");
	int m;
	
	if (!files)
   		w = 1;
	else
	{
		files >> m;
		w = m;
	}
		
	files.close();
	
	switch(w)
	{
		case 1:
			system("color 0f");
			break;
		case 2:
			system("color 03");
			break;
		case 3:
			system("color 09");
			break;
		case 4:
			system("color 0C");
			break;
		case 5:
			system("color 0E");
			break;
		case 6:
			system("color 2f");
			break;
		case 7:
			system("color 90");
			break;
		case 8:
			system("color 0a");	
			break;
	}
	
	logo();
	
	gotoXY(41,17);
	for(int i=0;i<41;i++)
	{
		cout<<a;
	}
	
	cout<<"\r";
	gotoXY(41,17);
	for(int i=0;i<41;i++)
	{
		cout<<b;
		Sleep(80);
	}
}

void kost::iyatidak(int ex, int qq) //pilihan
{
	gotoXY(55, 11);	cout<<"IYA / tidak";
	
	int menu_item = 0;
	bool running = true;
	
	while(running)
	{
		system("pause>nul");
		if(GetAsyncKeyState(VK_LEFT) && menu_item != 0)
		{
			gotoXY(55, 11);	cout<<"           ";
			gotoXY(55, 11);	cout<<"IYA / tidak";
			menu_item--;
			continue;
		}
		if(GetAsyncKeyState(VK_RIGHT) && menu_item != 1)
		{
			gotoXY(55, 11);	cout<<"           ";
			gotoXY(55, 11);	cout<<"iya / TIDAK";
			menu_item++;
			continue;
		}
		if(GetAsyncKeyState(VK_RETURN))
		{
			switch(menu_item)
			{
				case 0:
					if(ex == 1)
					{
						running = false;
						cout<<"\n\n\n\n\n\n\n";
						system("exit");
						exit(0);
					}
					else if(ex == 3)
					{
						qq++;
						running = false;
						inputbarang(qq);
					}
					else if(ex == 2)
					{
						system("cls");
						gotoXY(43, 10);	cout<<"Berhasil Mengatur Ulang Pengaturan";
						gotoXY(49, 11);	cout<<"Seluruh Data Dihapus!..";
						remove("inputdata.txt");
						remove("barang.txt");
						system("color 0f");
						Sleep(2000);
						running = false;
						running = false;
//						menu();
					}
					break;
				case 1:
					if(ex == 1)
					{
						running = false;
						running = false;
//						menu();
					}
					else if(ex == 3)
					{
						ofstream file;
						file.open("barang.txt",ios::app);
						for(int i=0;i<=qq;i++){
							file<<data_kluaran[i].nama_barang<<" "<<data_kluaran[i].jumlah<<" "	//save to file
							<<data_kluaran[i].harga_satuan<<" "<<data_kluaran[i].total<<" "<<data_kluaran[i].waktu<<" ";	//save to file
						}
						file<<endl;	//save to file
						file.close();
						running = false;
						running = false;
//						menu();
					}
					else if(ex == 2)
					{
						running = false;
						running = false;
//						menu();
					}
					break;
			}
		}
	}
}

kost::tema(int w)
{
	system("cls");
cout<<w;
	gotoXY(29, 2);	garis();
	gotoXY(29, 3);	cout<<"||\t\t        MENU PENGATURAN APLIKASI\t\t||";
	gotoXY(29, 4);	garis();
	int menu_item = w-1, am = w, amd = w;
	bool running = true;	string asd;
	ifstream qwe;	qwe.open("inputdata.txt");
	if(!qwe)
	{
		gotoXY(43, 8);cout<<aturan[0];
		Sleep(2000);
		running = false;
//		menu();
	}
	else
	{
		getline(qwe, asd);
		asd.erase(0, 1);	qwe.close();
	}
	gotoXY(16, 6); 	cout<<"Tema 01   Tema 02   Tema 03   Tema 04   Tema 05   Tema 06   Tema 07   Tema 08   PAKAI";
	gotoXY(21, 8);	cout<<"Tema Saat Ini = Tema 0"<<w;
	gotoXY(21, 10);	cout<<"- Gunakan Anak Panah Untuk Memilih";
	gotoXY(21, 11); cout<<"- Tekan Enter Untuk Melihat Perubahan";
	gotoXY(21, 12); cout<<"- Pilih 'PAKAI' Untuk Menyimpan Perubahan";

	while(running)
	{
		system("pause>nul");
		if(GetAsyncKeyState(VK_RIGHT) && menu_item != 7 && menu_item < 8)
		{
			am++;
			gotoXY(21, 8);	cout<<"Tema Saat Ini = Tema 0"<<am<<"           ";
			menu_item++;
			continue;
		}
		if(GetAsyncKeyState(VK_RIGHT) && menu_item == 7 && menu_item < 8)
		{
			am++;
			gotoXY(21, 8);	cout<<"Tema Saat Ini = Tema 0"<<amd<<" Terpilih";
			menu_item++;
			continue;
		}
		if(GetAsyncKeyState(VK_LEFT) && menu_item != 0 && menu_item <= 8)
		{
			am--;
			gotoXY(21, 8);	cout<<"Tema Saat Ini = Tema 0"<<am<<"           ";
			menu_item--;
			continue;
		}
		if(GetAsyncKeyState(VK_RETURN))
		{
			switch(menu_item)
			{
				case 0:
					system("color 0f");
					amd = 1;
					break;
				case 1:
					system("color 03");
					amd = 2;
					break;
				case 2:
					system("color 09");
					amd = 3;
					break;
				case 3:
					system("color 0C");
					amd = 4;
					break;
				case 4:
					system("color 0E");
					amd = 5;
					break;
				case 5:
					system("color 2f");
					amd = 6;
					break;
				case 6:
					system("color 90");
					amd = 7;
					break;
				case 7:
					system("color 0a");	
					amd = 8;
					break;
				case 8:
					remove("inputdata.txt");
					running = false;
					ofstream files; files.open("inputdata.txt");
					w = amd;
					files<<w<<" "<<asd;
					files.close();
					break;
			}
		}
	}
}

void kost::atur()
{
	system("cls");
	gotoXY(29, 2);	garis();
	gotoXY(29, 3);	cout<<"||\t\t        MENU PENGATURAN APLIKASI\t\t||";
	gotoXY(29, 4);	garis();
	int menu_item = 0, run, y = 7;
	bool running = true;
	string asd;
	ifstream qwe;	qwe.open("inputdata.txt");
	
	gotoXY(44, 7);	cout<<">>";
	while(running)
	{
		gotoXY(47, 7);	cout<<"[1] TEMA TAMPILAN";
		gotoXY(47, 8);	cout<<"[2] PENYIMPANAN DATA";
		gotoXY(47, 9);	cout<<"[3] PETUNJUK PENGGUNAAN";
		gotoXY(47, 10);	cout<<"[4] ATUR ULANG PENGATURAN";
		gotoXY(47, 11);	cout<<"[5] KEMBALI";
		gotoXY(5, 28);	cout<<"*) "<<aturan[3];
		system("pause>nul");
		
		if(GetAsyncKeyState(VK_DOWN) && y != 11)
		{
			gotoXY(44, y);	cout<<"  ";	y++;
			gotoXY(44, y);	cout<<">>";	menu_item++;
			continue;
		}
		if(GetAsyncKeyState(VK_UP) && y != 7)
		{
			gotoXY(44, y);	cout<<"  ";	y--;
			gotoXY(44, y);	cout<<">>";	menu_item--;
			continue;
		}
		if(GetAsyncKeyState(VK_RETURN))
		{
			switch(menu_item)
			{
				case 0: 
					running = false;
					tema(w);
					running = false;
//					menu();
					break;
				case 1: //perhitungan
					system("cls");
					running = false;
					gotoXY(43, 8);	cout<<"Hanya Tersedia Di Versi Premium";	Sleep(2000);
//					menu();
					break;
				case 2: //cara pake
					carapake();
					running = false;
//					menu();
					break;
				case 3:
					if(!qwe)
					{
						system("cls");
						gotoXY(29, 2);	garis();
						gotoXY(29, 3);	cout<<"||\t\t        MENU PENGATURAN APLIKASI\t\t||";
						gotoXY(29, 4);	garis();
						gotoXY(43, 8);	cout<<aturan[0];
						Sleep(2300);
						running = false;
//						menu();
					}
					else
					{
//						getline(qwe, asd);
//						asd.erase(0, 1);	
						qwe.close();
						system("cls");
						gotoXY(43, 10);	cout<<"Apakah Anda Yakin Ingin Mengatur Ulang?";
						running = false;
						iyatidak(2, 0);
					}
					qwe.close();
					running = false;
//					menu();
					break;
				case 4:	//menu kembali
					running = false;
//					menu();
					break;
			}
		}
	}
}

kost::carapake()
{
	system("cls");
	gotoXY(29, 2);	garis();
	gotoXY(29, 3);	cout<<"||\t\t        MENU PETUNJUK PENGGUNAAN\t\t||";
	gotoXY(29, 4);	garis();
	int x = 7;
	gotoXY(5, 28);	cout<<"*) "<<aturan[1];
	for(int i=0;i<5;i++){
		gotoXY(29, x);	cout<<"["<<i+1<<"] "<<aturan[i]<<endl;
		x++;
	}
	system("pause>nul");
//	menu();
}

void kost::keluar() //keluar
{
	system("cls");
	gotoXY(45, 10);	cout<<"Apakah Anda Yakin Ingin Keluar?";
	iyatidak(1,0);
}

void kost::gotoXY(int X, int Y)
{
	CursorPosition.X = X;
	CursorPosition.Y = Y;
	SetConsoleCursorPosition(console, CursorPosition);
}

int main()
{
	kost k;
	k.loading();
	k.menu();
}
