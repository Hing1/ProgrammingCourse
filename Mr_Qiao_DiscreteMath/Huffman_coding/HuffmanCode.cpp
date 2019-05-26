#include "iostream"
#include <stdio.h>
#include "math.h"
#include "stdlib.h"
#include "HuffmanCode1.h"
#include <string>
using namespace std;
#define MAXDATA 10000 //��ַ���
#define MAXSIZE 150   //�����Ҷ��
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////��һ���ֹ��ܣ�W��ʵ�ֵĴ���$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

HuffmanTree1::HuffmanTree1()
{
    Node = NULL;
} //��������ʼ��Ϊ��

HuffmanTree1::~HuffmanTree1()
{
    delete[] Node;
} //�ͷŽ��ռ�

void HuffmanTree1::CreateHfmTree(char Str[], int m[], int n) //������������
{
    int i, j, m1, m2, x1, x2;
    HuffmanNode *HfmNode = new HuffmanNode[2 * n - 1];
    HuffmanCode1 *HfmCode = new HuffmanCode1[n];
    for (i = 0; i < 2 * n - 1; i++)
    {
        HfmNode[i].weight = 0;
        HfmNode[i].parent = 0;
        HfmNode[i].flag = 0;
        HfmNode[i].lchild = -1;
        HfmNode[i].rchild = -1;
    }
    for (i = 0; i < n; i++)
    {
        HfmNode[i].weight = m[i];
        HfmCode[i].Leaf = Str[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        m1 = m2 = 32767;
        x1 = x2 = 0;
        for (j = 0; j < n + i; j++)
        {
            if (HfmNode[j].weight <= m1 && HfmNode[j].flag == 0)
            {
                m2 = m1;
                x2 = x1;
                m1 = HfmNode[j].weight;
                x1 = j;
            }
            else if (HfmNode[j].weight <= m2 && HfmNode[j].flag == 0)
            {
                m2 = HfmNode[j].weight;
                x2 = j;
            }
        }
        HfmNode[x1].parent = n + i;
        HfmNode[x2].parent = n + i;
        HfmNode[x1].flag = 1;
        HfmNode[x2].flag = 1;
        HfmNode[n + i].weight = HfmNode[x1].weight + HfmNode[x2].weight;
        HfmNode[n + i].lchild = x1;
        HfmNode[n + i].rchild = x2;
    }
    CodeHuf(HfmNode, HfmCode, n);
    TransCode(HfmCode, n);
    //TranslateArtcle(HfmCode,n);
    hf = HfmCode;
    f = n;
}
void HuffmanTree1::CodeHuf(HuffmanNode a[], HuffmanCode1 b[], int n) //�Թ����������б���
{
    HuffmanCode1 Hfd;
    int c, p;
    for (int i = 0; i < n; i++)
    {
        Hfd.Start = n - 1;
        c = i;
        p = a[c].parent;
        while (p != 0)
        {
            if (a[p].lchild == c)
                Hfd.Info[Hfd.Start] = '0';
            else
                Hfd.Info[Hfd.Start] = '1';
            Hfd.Start--;
            c = p;
            p = a[c].parent;
        }
        printf("%c :", b[i].Leaf);
        for (int j = Hfd.Start + 1; j < n; j++)
        {
            b[i].Info[j] = Hfd.Info[j];
            printf("%c", Hfd.Info[j]);
        }
        printf("\n");
        b[i].Start = Hfd.Start;
    }
}
void HuffmanTree1::TransCode(HuffmanCode1 b[], int n) //�����½��з��벢����
{
    ifstream ifs("WData.txt");
    ofstream ofs("WCode.txt");
    char s[1000];
    int t = 0;
    char ch;
    cout << "*******************************************************************************" << endl;
    printf("���ĵı���Ϊ��\n");
    while (ifs.get(ch))
    {
        if (ch != '\n')
            s[t] = ch;
        for (int i = 0; i < n; i++)
        {
            if (s[t] == b[i].Leaf)
                for (int j = b[i].Start + 1; j < n; j++)
                {
                    printf("%c", b[i].Info[j]);
                    ofs << b[i].Info[j];
                }
        }
        t++;
    }
    printf("\n");
    printf("���ĵı����Ѿ�������WCode.txt��\n");
    cout << "*******************************************************************************" << endl;
}
void HuffmanTree1::TranslateArtcle(HuffmanCode1 b[], int n) //��������뷭������²�����
{
    int t = 0;
    ifstream ifs("WCode.txt");
    ofstream ofs("TransWData.txt");
    string s;
    getline(ifs, s);
    for (t = 0; s[t] != '\0'; t++)
        ;
    int l = 0;
    int j = 0;

    printf("���ĵ�������Ϊ��\n");
    while (l < t)
    {
        while (j < n)
        {
            int hu = b[j].Start + 1;
            int k = 0;
            while (hu < n)
            {
                if (s[l] == b[j].Info[hu])
                {
                    l++;
                    hu++;
                    k++;
                }
                else
                {

                    break;
                }
            }
            if (hu == n)
            {
                printf("%c", b[j].Leaf);
                ofs << b[j].Leaf;
                j = 0;
                break;
            }
            else
            {
                l = l - k;
                j++;
                continue;
            }
        }
    }
    printf("\n");
    printf("����Ľ���Ѿ����浽TransWData.txt��\n");
    cout << "*******************************************************************************" << endl;
}

void HuffmanTree1::TranslatedCode()
{
    ifstream ifs("WData.txt");
    char str[1000];
    char Str[100];
    int i = 0, j, m[100], h, k = 0;
    int n = 0;
    cout << "*******************************************************************************" << endl;
    printf("�ļ�����ȡ�������ַ����ǣ�\n");
    char ch;
    while (ifs.get(ch))
    {
        printf("%c", ch);
        if (ch != '\n')
        {
            str[n++] = ch;
        }
    }
    printf("\n");
    printf("�ַ����й������ַ�%d��\n", n);
    for (i = 0; i < n; i++)
    {
        j = 0;
        h = 0;
        while (str[i] != str[j])
            j++;
        if (j == i)
        {
            Str[k] = str[i];
            printf("�ַ�%c����", Str[k]);
        }
        else
            continue;
        for (j = i; j < n; j++)
        {
            if (str[i] == str[j])
                h++;
        }
        printf("%d��\n", h);
        m[k] = h;
        k++;
    }
    cout << "*******************************************************************************" << endl;
    printf("�ַ������ַ�������%d��\n", k);
    cout << "*******************************************************************************" << endl;
    printf("ÿ���ַ���Ӧ�Ĺ����������ǣ�\n");
    CreateHfmTree(Str, m, k);
    cin.get();

    //	printf("\n");
}