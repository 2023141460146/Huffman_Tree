#include <iostream>
#include <string.h>
#include "Huffman.h"
using namespace std;

extern struct Tree huffman[300];
extern struct Arr arr[100];

int Sort() 
{
	
	int i = 0;
	while (arr[i].weight != 0)
	{
		
		char c;
		int weight;
		int loc;
		int j = i;
		int min = j;
		while (arr[j].weight!=0)
		{
			if (arr[j].weight <= arr[min].weight)	min = j;
			j++;
		}

		c = arr[min].c;
		weight = arr[min].weight;
		loc = arr[min].loc;
		arr[min].c = arr[i].c;
		arr[min].weight = arr[i].weight;
		arr[min].loc = arr[i].loc;
		arr[i].c = c;
		arr[i].weight = weight;
		arr[i].loc = loc;

		i++;
	}

	return 0;
}

int BuildTree()
{
	Arr a = arr[0], b = arr[1];
	int p = 0;
	while (huffman[p].weight!=0)
	{
		p++;
	}

	if (a.c > 0 && b.c > 0)
	{
		huffman[p].weight = a.weight + b.weight;
		huffman[p].lch = p + 1;
		huffman[p].rch = p + 2;

		huffman[p + 1].weight = a.weight;
		huffman[p + 1].c = a.c;
		huffman[p + 1].lch = -1;
		huffman[p + 1].rch = -1;
		huffman[p + 1].parent = p;


		huffman[p + 2].weight = b.weight;
		huffman[p + 2].c = b.c;
		huffman[p + 2].lch = -1;
		huffman[p + 2].rch = -1;
		huffman[p + 2].parent = p;
	}
	else if ((a.c==-1&&b.c!=-1))
	{
		huffman[p].weight = b.weight+a.weight;
		huffman[p].lch = a.loc;
		huffman[p].rch = p + 1;

		huffman[p + 1].weight = b.weight;
		huffman[p + 1].c = b.c;
		huffman[p + 1].lch = -1;
		huffman[p + 1].rch = -1;
		huffman[p + 1].parent = p;

		huffman[a.loc].parent = p;
	}
	else if (a.c != -1 && b.c == -1)
	{
		huffman[p].weight = b.weight + a.weight;
		huffman[p].rch = b.loc;
		huffman[p].lch = p + 1;

		huffman[p + 1].weight = a.weight;
		huffman[p + 1].c = a.c;
		huffman[p + 1].lch = -1;
		huffman[p + 1].rch = -1;
		huffman[p + 1].parent = p;

		huffman[b.loc].parent = p;
	}
	else if (a.c == -1 && b.c == -1)
	{
		huffman[p].weight = a.weight + b.weight;
		huffman[p].lch = a.loc;
		huffman[p].rch = b.loc;

		huffman[a.loc].parent = p;
		huffman[b.loc].parent = p;
	}

	arr[0].weight = huffman[p].weight;
	arr[0].loc = p;
	arr[0].c = -1;

	arr[1].weight = 9999;
	arr[1].c = 0;
	arr[1].loc = -1;

	while (huffman[p].weight!=0)
	{
		p++;
	}

	return 0;
}

int Encode(char c,char* ans)
{
	int i = 0;
	int top = 0;
	while (huffman[i].c != c)
	{
		i++;
	}

	while (huffman[i].parent != -1)
	{
		int j = huffman[i].parent;
		if (huffman[j].lch == i)
		{
			ans[top] = '0';
		}
		else
		{
			ans[top] = '1';
		}

		top++;
		i = j;
	}

	return 0;
}

int Count(char* input) 
{
	for (int i =0;i<strlen(input);i++)
	{
		char c = input[i];
		int j = 0;
		while (arr[j].c != c && arr[j].c!=0  )
		{
			j++;
		}
		arr[j].c = c;
		arr[j].weight++;
	}

	return 0;
}