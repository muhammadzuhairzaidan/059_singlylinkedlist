#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
	int noMhs;
	char nama[20];
	Node* next;
};
class List
{
	Node* START;
public:
	List();
	void addNode();
	bool search(int nim, Node** current, Node** previous);
	bool listempty();
	bool delNode(int element);
	void traverse();
};
List::List()
{
	START = NULL;
}

void List::addNode()
{
	int nim;
	char nm[20];
	cout << "\nMasukkan Nomor Mahasiswa: ";
	cin >> nim;
	cout << "\nMasukkan Nama: ";
	cin >> nm;

	Node* nodeBaru = new Node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm);
	if (START == NULL || nim <= START->noMhs)
	{
		if ((START != NULL) && (nim == START->noMhs))
		{
			cout << "\nDuplikasi noMhs tidak diizinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	Node* previous, * current;


	current = START;
	previous = START;



	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "\nDuplikasi noMhs tidak diizinkan\n";
			return;
		}
		previous = current;
		current = current->next;

	}
	/*Jika loop diatas dieksekusi, previous dan current akan menempati posisi dimana */
	nodeBaru->next = current;
	previous->next = nodeBaru;
}
bool List::listempty()
{
	if (START == NULL)
		return true;
	else
		return false;
}
