#pragma once
struct Tree
{
	char c=0;
	int weight = 0;
	int parent = -1 , lch= -1 , rch = -1;
};

struct Arr 
{
	char c = 0;//0��ʾ�޴��룬-1��ʾΪ��;
	char loc = -1;//���Ǹ������huffman�еĵ�ַ;
	int weight = 0;
};

int Sort();

int BuildTree();

int Encode(char c,char* ans);

int Count(char* input);