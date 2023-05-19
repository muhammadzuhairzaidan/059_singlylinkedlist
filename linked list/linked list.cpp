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
