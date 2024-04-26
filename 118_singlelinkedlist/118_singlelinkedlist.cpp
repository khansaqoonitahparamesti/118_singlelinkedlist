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
	}
}

