#include <iostream>
#include <fstream>
using namespace std;
int balance=5000000;
typedef struct
{
	long int n1;
	int n2;
	int n3;
}atm;
void header()
{
	
	cout<<"\n\t\t ------------------------------------------------------\n";
	cout<<"\t\t|                                                       |\n";
	cout<<"\t\t|              ATM Bank Rakyat Jelata                   |\n";
	cout<<"\t\t|                  Pecahan 50.000                       |\n";
	cout<<"\t\t -------------------------------------------------------"<<endl;
}
void footer()
{
	cout<<"\n\t\t ------------------------------------------------------\n";
	cout<<"\t\t|              Terima kasih atas kunjungan anda         |\n";
	cout<<"\t\t|             Pastikan kartu dan uang anda tidak        |\n";
	cout<<"\t\t|                      tertinggal                       |\n";
	cout<<"\t\t -------------------------------------------------------"<<endl;
}
void ceksaldo()
{
	
		cout<<"\n\t Sisa saldo anda : Rp. "<<balance<<"\n";
	
}
void tarik(atm tarik)
{
	char pilih;
	tarik : 
	
		cout<<"\n\t Masukkan nominal penarikan : ";cin>>tarik.n1;
		if(tarik.n1 < 50000 || tarik.n1 > 10000000)
		{
			cout<<"\tBatas Tarik Tunai Minimal Sebesar Rp.50.000 dan Maksimal Rp.10.000.000."<<endl;
			goto tarik;
		}
		else if(balance < tarik.n1)
		{
			cout<<"\tSaldo Anda Tidak Mencukupi"<<endl;
		}
		else
		{
			balance-=tarik.n1;
			cout<<"\t Transaksi berhasil "<<endl;
			cout<<"\t Jumlah penarikan    : Rp. "<<tarik.n1<<endl;
			cout<<"\t Sisa saldo anda     : Rp. "<<balance<<endl;
			cout<<"\t Cetak struk [y/t] ? : ";cin>>pilih;
			if (pilih=='y'||pilih=='Y')
			{
				ofstream tarikuang;
				tarikuang.open("struct_penarikan.txt",ios::app);
				tarikuang.close();
				tarikuang.open("struct_penarikan.txt",ios::in);
				tarikuang<<"\n\t\t ------------------------------------------------------\n";
				tarikuang<<"\t\t|                                                       |\n";
				tarikuang<<"\t\t|              ATM Bank Rakyat Jelata                   |\n";
				tarikuang<<"\t\t|                                                       |\n";
				tarikuang<<"\t\t -------------------------------------------------------"<<endl;
				tarikuang<<"\t\t\t Transaksi Penarikan  "<<endl;
				tarikuang<<"\t Jumlah Penarikan    : Rp. "<<tarik.n1<<endl;
				tarikuang<<"\t Sisa saldo anda     : Rp. "<<balance<<endl;
				tarikuang<<"\n\t\t ------------------------------------------------------\n";
				tarikuang<<"\t\t|              Terima kasih atas kunjungan anda         |\n";
				tarikuang<<"\t\t|             Pastikan kartu dan uang anda tidak        |\n";
				tarikuang<<"\t\t|                      tertinggal                       |\n";
				tarikuang<<"\t\t -------------------------------------------------------"<<endl;
				tarikuang.close();
			}
			else
			{
				cout<<endl;
			}
		}	
}
void setor(atm setor)
{
	char pilih;
	setorulang : 
		cout<<"\n\t Masukkan nominal yang ingin di setor : Rp. ";cin>>setor.n2;
		if(setor.n2 < 50000 || setor.n2 > 5000000)
		{
			cout<<"\tBatas setor tunai minimal Rp. 50.000 dan maksimal Rp. 5.000.000."<<endl;
			goto setorulang;
		}
		else
		{
			balance += setor.n2;
			cout<<"\t Transaksi berhasil "<<endl;
			cout<<"\t Jumlah setor tunai    : Rp. "<<setor.n2<<endl;
			cout<<"\t Sisa saldo anda       : Rp. "<<balance<<endl;
			cout<<"\t Cetak struk [y/t] ?   : ";cin>>pilih;
			if (pilih=='y'||pilih=='Y')
			{
				ofstream setoruang;
				setoruang.open("struct_setor_tunai.txt",ios::app);
				setoruang.close();
				setoruang.open("struct_setor_tunai.txt",ios::in);
				setoruang<<"\n\t\t ------------------------------------------------------\n";
				setoruang<<"\t\t|                                                       |\n";
				setoruang<<"\t\t|              ATM Bank Rakyat Jelata                   |\n";
				setoruang<<"\t\t|                                                       |\n";
				setoruang<<"\t\t -------------------------------------------------------"<<endl;
				setoruang<<"\t\t\t Transaksi Setor Tunai  "<<endl;
				setoruang<<"\t Jumlah setor tunai    : Rp. "<<setor.n2<<endl;
				setoruang<<"\t Sisa saldo anda       : Rp. "<<balance<<endl;
				setoruang<<"\n\t\t ------------------------------------------------------\n";
				setoruang<<"\t\t|              Terima kasih atas kunjungan anda         |\n";
				setoruang<<"\t\t|             Pastikan kartu dan uang anda tidak        |\n";
				setoruang<<"\t\t|                      tertinggal                       |\n";
				setoruang<<"\t\t -------------------------------------------------------"<<endl;
				setoruang.close();
			}
			else
			{
				cout<<endl;
			}
			
			
		}
}
void transfer(atm kirim)
{
	int admin=2500;
	char pilih;
	trf :
	cout<<"\n\t Masukkan No. Rekening : ";cin>>kirim.n1;
	cout<<"\n\t Masukkan kode bank    : ";cin>>kirim.n3;
	cout<<"\n\t Masukkan nominal      : Rp. ";cin>>kirim.n2;
		if (kirim.n3 == 113)
		{
			admin-=2500;
		}
		else 
		{
			kirim.n2 += admin;	
		}
	if(kirim.n2 > 5000000)
		{
			cout<<"\tBatas Transfer Maksimal Rp.5.000.000."<<endl;
			goto trf;
		}
	else if(balance < kirim.n2)
		{
			cout<<"\tSaldo Anda Tidak Mencukupi"<<endl;
		}
	else
	{
		balance -= kirim.n2;
		cout<<"\t Transaksi berhasil "<<endl;
		cout<<"\t Jumlah Transfer       : Rp. "<<kirim.n2<<endl;
		cout<<"\t Admin                 : Rp. "<<admin<<endl;
		cout<<"\t Sisa saldo anda       : Rp. "<<balance<<endl;
		cout<<"\t Cetak struk [y/t] ?   : ";cin>>pilih;
		if (pilih=='y'||pilih=='Y')
			{
				ofstream kirimuang;
				kirimuang.open("struct_transfer.txt",ios::app);
				kirimuang.close();
				kirimuang.open("struct_transfer.txt",ios::in);
				kirimuang<<"\n\t\t ------------------------------------------------------\n";
				kirimuang<<"\t\t|                                                       |\n";
				kirimuang<<"\t\t|              ATM Bank Rakyat Jelata                   |\n";
				kirimuang<<"\t\t|                                                       |\n";
				kirimuang<<"\t\t -------------------------------------------------------"<<endl;
				kirimuang<<"\t\t\t Transaksi Transfer  "<<endl;
				kirimuang<<"\t Jumlah Transfer       : Rp. "<<kirim.n2<<endl;
				kirimuang<<"\t Biaya admin           : Rp. "<<admin<<endl;
				kirimuang<<"\t Sisa saldo anda       : Rp. "<<balance<<endl;
				kirimuang<<"\n\t\t ------------------------------------------------------\n";
				kirimuang<<"\t\t|              Terima kasih atas kunjungan anda         |\n";
				kirimuang<<"\t\t|             Pastikan kartu dan uang anda tidak        |\n";
				kirimuang<<"\t\t|                      tertinggal                       |\n";
				kirimuang<<"\t\t -------------------------------------------------------"<<endl;
				kirimuang.close();
			}
			else
			{
				cout<<endl;
			}
		
	}
		
}
int main()
{
	int x,z,salah=0;
	char pilih, pilihan;
	atm tunai;
	ulang :
	system("cls");
	cout<<"\n\t\t --------------------------------------------------------\n";
	cout<<"\t\t|                  Selamat Datang                        |\n";
	cout<<"\t\t|              Di ATM Bank Rakyat Jelata                 |\n";
	cout<<"\t\t|                                                        |\n";
	cout<<"\t\t --------------------------------------------------------\n";
	cout<<"\t\t    Masukkan Pin anda : ";cin>>x;cout<<"                \n";
	if(x==131100)
	{
		system("cls");
		goto menu;
	}
	else
	{
		salah += 1;
		cout<<"\n\n\t\tPin anda salah \n";
		if (salah <3 )
		{
			goto coba;
		}
		else if (salah==3)
		{
			cout<<"\tAnda telah salah memasukkan PIN sebanyak 3 kali, kartu ATM anda di blokir";
			goto selesai;
		}
		coba :
		cout<<"\tMasukkan pin kembali [y/t] : ";cin>>pilih;
		if (pilih=='y'||pilih=='Y')
		{
			goto ulang;
		}
		else if (pilih=='t'||pilih=='T')
		{
			goto selesai;
		}
	}
	menu :
	system("cls");
	cout<<"\n\t\t ------------------------------------------------------\n";
	cout<<"\t\t|                      Menu                             |\n";
	cout<<"\t\t|              ATM Bank Rakyat Jelata                   |\n";
	cout<<"\t\t|                                                       |\n";
	cout<<"\t\t -------------------------------------------------------\n";
	cout<<"\n\t1. Tarik Tunai \n";
	cout<<"\t2. Setor Tunai  \n";
	cout<<"\t3. Transfer  \n";
	cout<<"\t4. Cek Saldo \n";
	cout<<"\t5. Exit \n";
	cout<<"\n\t Masukkan Pilihan [1-4]: ";cin>>z;
	switch (z) 
		{
			case 1 :
				{
					system("cls");
					header();
					tarik(tunai);
					footer();
						cout<<"\n\tIngin melakukan transaksi yang lain [y/t] : ";cin>>pilihan;
						if (pilihan=='y'||pilihan=='Y')
						{
							goto menu;
						}
						else
						{
							goto selesai;
						}
					
				}
			break;
			case 2 :
				{
					system("cls");
					header();
					setor(tunai);
					footer();
						cout<<"\n\tIngin melakukan transaksi yang lain [y/t] : ";cin>>pilihan;
						if (pilihan=='y'||pilihan=='Y')
						{
							goto menu;
						}
						else
						{
							goto selesai;
						}
					
				}
			break;
			case 3 :
				{
					system("cls");
					header();
					transfer(tunai);
					footer();
					cout<<"\n\tIngin melakukan transaksi yang lain [y/t] : ";cin>>pilihan;
						if (pilihan=='y'||pilihan=='Y')
						{
							goto menu;
						}
						else
						{
							goto selesai;
						}
					
				}
			break;
			case 4 :
				{
					system("cls");
					header();
							ceksaldo();
					footer();
						cout<<"\n\tIngin melakukan transaksi yang lain [y/t] : ";cin>>pilihan;
						if (pilihan=='y'||pilihan=='Y')
						{
							goto menu;
						}
						else
						{
							goto selesai;
						}	
				}
			break;
			default : 
			{
				goto selesai;
			}
			break;
		}
	selesai :
		cout<<endl;
		
	return 0;
}
