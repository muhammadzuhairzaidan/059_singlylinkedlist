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
bool List::delNode(int nim)
{
	Node* current, * previous;
	if (search(nim, &previous, &current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = START->next;

	delete current;
	return true;
}
/*Check apakah node yang dimaksud ada didalam list atau tidak*/
bool List::search(int nim, Node** previous, Node** current)
{
	*previous = START;
	*current = START;
	while ((*current != NULL) && (nim != (*current)->noMhs))
	{
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}
void List::traverse()
{
	if (listempty())
		cout << "\nList Kosong\n";
	else
	{
		cout << endl << "Data didalam list adalah:" << endl;
		Node* currentNode;
		for (currentNode = START; currentNode != NULL; currentNode = currentNode->next)
		{
			cout << currentNode->noMhs << "  " << currentNode->nama << "\n";
		}
		cout << endl;
	}
}
int main()
{
	List mhs;
	int nim;
	char ch;
	while (1)
	{
		cout << endl << "Menu";
		cout << endl << "1. Menambahkan data kedalam list" << endl;
		cout << "2. Menghapus data dari dalam list" << endl;
		cout << "3. Menampilkan semua data didalam list" << endl;
		cout << "5. Keluar" << endl;
		cout << endl << "Masukkan piliha (1-5): ";
		cin >> ch;
		switch (ch)
		{
		case '1':
		{
			mhs.addNode();

		}
		break;
		case '2':
		{
			if (mhs.listempty())
			{
				cout << endl << "List Kosong" << endl;
				break;
			}
			cout << endl << "\nMasukkan no mahasiswa yang akan dihapus : ";
			cin >> nim;
			if (mhs.delNode(nim) == false)
				cout << endl << "Data tidak ditemukan " << endl;
			else
				cout << endl << "Data dengan nomor mahasiswa " << nim << "berhasil dihapus";

		}
		break;
		