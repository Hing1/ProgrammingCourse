#ifndef HUFFMAMCODE_H
#define HUFFMAMCODE_H
#include <iostream>
#include <fstream>
using namespace std;
struct HuffmanNode //����������������
{
    int weight;
    int parent;
    int lchild, rchild;
    int flag;
};
class HuffmanCode1 //������������
{
public:
    char Info[100];
    int Start;
    char Leaf;
};
class HuffmanTree1 //��������������
{
private:
    HuffmanNode *Node;

public:
    int f;
    HuffmanCode1 *hf;
    HuffmanTree1();
    ~HuffmanTree1();
    void TranslatedCode();
    void CodeHuf(HuffmanNode a[], HuffmanCode1 b[], int n);
    void CreateHfmTree(char Str[], int m[], int n);

    void TransCode(HuffmanCode1 b[], int n);
    void TranslateArtcle(HuffmanCode1 b[], int n);
};
#endif //HUFFMAMCODE