#pragma once
struct Tree
{
	char c=0;
	int weight = 0;
	int parent = -1 , lch= -1 , rch = -1;
};

struct Arr 
{
	char c = 0;//0表示无存入，-1表示为树;
	char loc = -1;//若是根则存入huffman中的地址;
	int weight = 0;
};

int Sort();

int BuildTree();

int Encode(char c,char* ans);

int Count(char* input);