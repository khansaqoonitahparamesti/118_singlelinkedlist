// 118_singlelinkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
	int noMhs;
	string name;
	node* next;
};

node* START = NULL;

void addnode() {
	int nim;
	string nama;
	node* nodebaru = new node;
	cout << " masukkan NIM:";
	cin >> nim;
	cout << "masukkan Nama";
	cin >> nama;
	nodebaru->noMhs = nim;
	nodebaru->name = nama;
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << " NIM sudah ada " << endl;
			return;
		}

		node* previous = START;
		node* current = START;
		while ((current != NULL) && (nim >= current->noMhs)) 
		{
			if (nim == current->noMhs) 
			{
				cout << "NIM sudah ada " << endl;
				return;
			}
			previous = current;
			current = current->next;
		}
		nodebaru->next = current;
		previous->next = nodebaru;
	}
}

bool serachnode(int nim, node* current, node* previous) {
	previous = START;
	current = START;
	while (current != NULL && nim > current->noMhs)
	{
		previous = current;
		current = current->next;
	}
	if (current == NULL) 
	{
		return false;
	}
	else if (current->noMhs == nim) 
	{
		return false;
	}
	else 
	{
		return false;
	}
}

bool deletenode(int nim) {
	node* current = START;
	node* previous = START;
	if (serachnode(nim, previous, current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = current->next;
	return true;

}

bool listempty() {
	if (START == NULL)
		return true;
	else
		return false;
}

void traverse() {
	if (listempty()) {
		cout << "List kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		node* currentnode= START;
		while (currentnode != NULL) {
			cout << "NIM:" << currentnode->noMhs << ",nama;" << currentnode->name << endl;
			currentnode = currentnode->next;
		}
	}
}

void searchdata() {
	if (listempty()) {
		cout << "List kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		cout << "masukkan nim:";
		cin >> nim;
		node* currentnode = START;
		while (currentnode != NULL) {
			if (currentnode->noMhs == nim) {
				cout << "nim:" << currentnode->noMhs << ",nama:" << currentnode->name << endl;
				return;

			}
			currentnode = currentnode->next;
		}
		cout << "data tidak ditemukan" << endl;
	}
}

int main() {
	int pilihan;
	do {
		try
		{
			cout << "1.tambah data " << endl;
			cout << "2.hapus data " << endl;
			cout << "3.tampilkan data " << endl;
			cout << "4. cari data " << endl;
			cout << "5. keluar " << endl;
			cout << "pilihan " << endl;
			cin >> pilihan;
			switch (pilihan)
			{
				case 1:
				addnode();
				cout << "data berhasil ditambahkan" << endl;
					system("pause");
					system("cls");
					break;
				case 2:
					if (listempty()) {
						cout << "List kosong" << endl;
						system("pause");
						system("cls");
						break;
					}

					int nim;
					cout << "masukkan nim:";
					cin >> nim;
					if (deletenode(nim)) {
						cout << "nim:" << nim << "berhasil dihapus" << endl;
						system("pause");
						system("cls");
					}
					else cout << "data tidak ditemukan" << endl;
					break;
				case 3:
					traverse();
					break;
				case 4:
					searchdata();
					break;
				case 5:
					break;
				default:
					cout << "pilihan tidak ada" << emdl;
					break;
			}
		}
		catch (exception e) 
		{
			cout << "terjadi kesalahan" << endl;
		}
	} while (pilihan != 5);
}