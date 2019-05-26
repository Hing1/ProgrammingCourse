#include "HuffmanCode1.h"
#include<string>
#define MAXSIZE 5
#define MAXDATA 5
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////�ڶ����ֹ���ʵ�ֵĴ���$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

typedef struct //���������ڵ�Ľṹ��
{
    char info;           //�����ַ���Ϣ
    unsigned int weight; //ÿ���ڵ��Ȩְ
    unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char **HuffmanCode; //�洢����������

void Select(HuffmanTree HT, int j, int &s1, int &s2)
{ //ѡ��˫�׽ڵ�Ϊ0��������С��������Ҷ�ڵ�
    int i = 1, m;
    while (HT[i].parent != 0)
        i++; //�ҵ�һ��˫�׽ڵ�Ϊ0����Ҷ���
    for (s2 = s1 = i; i < j; i++)
    {
        // ��֤s1�е�Ȩֵ��С��s2��С 
        if (HT[i].parent == 0 && HT[i].weight < HT[s1].weight)
        {
            s2 = s1;
            s1 = i;
        }
        else if (HT[i].parent == 0 && HT[i].weight >= HT[s1].weight && HT[i].weight <= HT[s2].weight)
            s2 = i;
        while (HT[i].parent == 0 && s1 == s2)
        {
            m = i;
            m++;
            while (HT[m].parent != 0)
                m++;
            s2 = m;
        }
    }
}
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n, char *info)
{ //����������
    int i, m;
    HuffmanTree p;
    if (n < 1)
        return;
    m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w, ++info)
    { //��ʼ�������Ѵ��ڵ���Ҷ��Ϣ
        p->info = *info;
        p->weight = *w;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    } //for
    for (; i <= m; ++i, ++p)
    { //��������Ҫ�Ĺ��ȸ��ڵ�
        p->weight = 0;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    } //for
    for (i = n + 1; i <= m; ++i)
    { //������������
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s2;
        HT[i].rchild = s1;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    } //for
    //����������
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    char *cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    for (i = 1; i <= n; ++i)
    {
        int f;
        unsigned int c;
        int start = n - 1;
        for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
        {
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        HC[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    } //for

    free(cd);
} //HuffmanCoding

//Y����ʵ��   ����������ַ����Ķ����Ʊ���
void CheckCoding(HuffmanTree HT, HuffmanCode HC, char *strcheck, int m, int k)
{
    ofstream ofs("BCode.txt"); //��ѯ������������Ϣ
    int p;
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; HT[j].info != strcheck[i]; j++)
            cout << HC[j]; //����������ַ����Ķ����Ʊ���
        ofs << HC[i];
    }
    cout << endl;
    cout << "�ַ����Ķ����Ʊ����Ѿ������ڡ�BCode.txt����" << endl;

    //cout<<"���뷭��õ��������ѱ����ڡ�Data.txt����"<<endl;
    cout << "*******************************************************************************" << endl;
    cout << "���ַ���Ӧ�ı���Ϊ:" << endl; //������ַ���Ӧ�Ĺ���������
    for (p = 1; p <= k; p++)
    {
        cout << HT[p].info << ": " << HC[p] << endl;
    }
} //CheckCoding

//�Լ�������Ķ����ƴ����������
void HuffmanTranslateCoding(HuffmanTree HT, int n, char *c)
{
    ofstream ofs("TransBData.txt"); //�������
    int m = 2 * n - 1;
    int i, j = 0;
    cout << "���뷭��õ��������ѱ����ڡ�TransBData.txt����" << endl;
    cout << "���뷭��õ�������Ϊ:";

    while (c[j] != '\0')
    {
        i = m;
        while (HT[i].lchild && HT[i].rchild)
        {
            if (c[j] == '0')
                i = HT[i].lchild;
            else if (c[j] == '1')
                i = HT[i].rchild;
            j++;
        }
        cout << HT[i].info; //������ַ���������ͱ���
        ofs << HT[i].info;
    }
}

//������̡�����"BCode.txt"�ı����������
void HuffmanTranslateCoding2(HuffmanTree HT, int n)
{
    ifstream ifs("BCode.txt");
    ofstream ofs("TransBData2.txt");

    string c;
    int m = 2 * n - 1;
    int i, j = 0;
    getline(ifs, c);
    cout << "���뷭��õ��������ѱ����ڡ�TransBData2.txt����" << endl;
    cout << "���뷭��õ�������Ϊ:";

    while (c[j] != '\0')
    {
        i = m;
        while (HT[i].lchild && HT[i].rchild)
        {
            if (c[j] == '0')
                i = HT[i].lchild;
            else if (c[j] == '1')
                i = HT[i].rchild;
            j++;
        }
        cout << HT[i].info; //������ַ���������ͱ���

        ofs << HT[i].info;
    }
}

void Menushow()
{
    cout << "  ||************************************************************************||" << endl;
    cout << "  ||                HuffmanCode and HUffmanTranslate  System                ||" << endl;
    cout << "  ||             ***********����������/����ϵͳ*************                ||" << endl;
    cout << "  ||             *************��ӭʹ�ñ�ϵͳ****************                ||" << endl;
    cout << "  ||             ����������ѧ ��Ϣ����ѧԺ �ƻ�093�� ��ȤС��               ||" << endl;
    cout << "  ||                 �����ˣ�����ǿ���鳤�� ���� ������                     ||" << endl;
    cout << "  ||************************************************************************||" << endl;
    cout << "  ||�ڱ�ϵͳ�������Խ������²�����                                          ||" << endl;
    cout << "  ||��һ���ֹ��ܣ�                                                          ||" << endl;
    cout << "  ||          A :���ļ���ȡ�ַ�����Ȼ�����ȡ���ַ������б���               ||" << endl;
    cout << "  ||          B :����W�����ԡ�WCode.txt����Ķ����Ʊ����������             ||" << endl;
    cout << "  ||�ڶ����ֹ��ܣ�                                                          ||" << endl;
    cout << "  ||          C :����������ַ������б���                                   ||" << endl;
    cout << "  ||          D:��BCode.txt��ı����������                                 ||" << endl;
    cout << "  ||          E :��������Ķ����Ʊ����������                               ||" << endl;
    cout << "  ||�������ֹ��ܣ�                                                          ||" << endl;
    cout << "  ||          F :�˳���ϵͳ                                                 ||" << endl;
    cout << "  ||************************************************************************||" << endl;
    cout << "  ||��ܰ��ʾ��                                                              ||" << endl;
    cout << "  ||    ִ��A���뽫�������ݴ洢��ͬĿ¼����Ϊ��WData���ı��ĵ���            ||" << endl;
    cout << "  ||    ��ִ��C����ʱ�������������ַ�������ϡ�#��                        ||" << endl;
    cout << "  ||    B��A�Ƕ�Ӧ��   B��A������                                           ||" << endl;
    cout << "  ||    D/E��C�Ƕ�Ӧ�ģ���B/C�Ǹ���C�����������                            ||" << endl;
    cout << "  ||    ����D/EӦ�ڱ���C����ܽ���                                          ||" << endl;
    cout << "  ||***********************     Copyright by FanFan     ********************||" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//main().cpp

int main()
{
    int n = 0, i = 0, k = 0, j, h, *w;
    FILE *fp;
    char ch2, str[MAXDATA], choose, name[] = "BData.txt";
    w = new int[MAXSIZE];
    char *info;
    char *strcheck = str;
    info = new char[MAXSIZE];
    char *ch = new char[MAXSIZE];
    HuffmanTree HT = new HTNode[MAXSIZE];
    HuffmanCode HC = NULL;
    HuffmanTree1 HuffmanNode;
    Menushow();

    while (1)
    {
        cout << endl;
        cout << "*******************************************************************************" << endl;
        cout << "*******************************************************************************" << endl;
        cout << "��������Ҫ���еĲ�����W/F/B/C/Y/T)(�����ִ�Сд)��" << endl;
        cin >> choose;
        cout << "*******************************************************************************" << endl;
        switch (choose)
        {
        case 'A':
        case 'a':
            HuffmanNode.TranslatedCode();
            break;
        case 'B':
        case 'b':
            HuffmanNode.TranslateArtcle(HuffmanNode.hf, HuffmanNode.f);
        case 'D':
        case 'd':
            HuffmanTranslateCoding2(HT, n);
            break;

        case 'E':
        case 'e': //�����������
            cout << "����������Ҫ����Ķ����Ʊ���: " << endl;
            cin >> ch;
            HuffmanTranslateCoding(HT, n, ch);
            break;
        case 'T':
        case 't': //�˳�ϵͳ
            return 0;

        case 'C':
        case 'c': //���б������

            cout << "��������Ҫ������ַ�����" << endl;
            //�Ӽ��������ַ���   ������ַ�����str[1000]��
            /*if ((fp=fopen(name,"w"))==NULL)
	   {cout<<"cannot open file"<<endl;
	
           exit(0);
	   }*/
            fp = fopen(name, "w");
            ch2 = getchar(); //������һ�μ�������Ļ��з�
            ch2 = getchar();
            while (ch2 != '#')
            {
                fputc(ch2, fp);
                str[n++] = ch2;
                putchar(str[n - 1]);
                ch2 = getchar();
            }

            putchar(10);
            fclose(fp);

            cout << endl;

            cout << "����������Ѿ������ڡ�BData.txt����" << endl;
            cout << "*******************************************************************************" << endl;
            cout << "�ַ����й������ַ�" << n << "��" << endl;
            cout << "*******************************************************************************" << endl;
            for (i = 0; i < n; i++) // ͳ�ƴӼ���������ַ�������Ϣ
            {
                j = 0;
                h = 0;
                while (str[i] != str[j])
                    j++;
                if (j == i)
                {
                    info[k] = str[i];
                    cout << "�ַ�" << info[k] << "����";
                }
                else
                    continue;
                for (j = i; j < n; j++)
                {
                    if (str[i] == str[j])
                        h++;
                }
                cout << h << "��" << endl;
                w[k] = h;
                k++;
            }
            cout << "*******************************************************************************" << endl;
            cout << "�ַ������ַ�������" << k << "��" << endl;
            cout << "*******************************************************************************" << endl;

            HuffmanCoding(HT, HC, w, n, info);
            //��������ַ������б���

            *strcheck = str[0];
            cout << "��������ַ�������Ϊ��" << endl;
            CheckCoding(HT, HC, strcheck, n, k);
            break;

        default:
            cout << "�Բ����������벻��ȷ������������" << endl;
        } //switch
    }     //while

} //main