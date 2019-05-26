#include "HuffmanCode1.h"
#include<string>
#define MAXSIZE 5
#define MAXDATA 5
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////第二部分功能实现的代码$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

typedef struct //哈弗曼树节点的结构体
{
    char info;           //关联字符信息
    unsigned int weight; //每个节点的权职
    unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char **HuffmanCode; //存储哈弗曼编码

void Select(HuffmanTree HT, int j, int &s1, int &s2)
{ //选择双亲节点为0，并且最小的两个子叶节点
    int i = 1, m;
    while (HT[i].parent != 0)
        i++; //找第一个双亲节点为0的子叶结点
    for (s2 = s1 = i; i < j; i++)
    {
        // 保证s1中的权值最小，s2次小 
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
{ //哈弗曼编码
    int i, m;
    HuffmanTree p;
    if (n < 1)
        return;
    m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w, ++info)
    { //初始化所有已存在的子叶信息
        p->info = *info;
        p->weight = *w;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    } //for
    for (; i <= m; ++i, ++p)
    { //构造所需要的过度根节点
        p->weight = 0;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    } //for
    for (i = n + 1; i <= m; ++i)
    { //建立哈弗曼树
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s2;
        HT[i].rchild = s1;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    } //for
    //哈弗曼编码
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

//Y功能实现   输出并保存字符串的二进制编码
void CheckCoding(HuffmanTree HT, HuffmanCode HC, char *strcheck, int m, int k)
{
    ofstream ofs("BCode.txt"); //查询哈弗曼编码信息
    int p;
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; HT[j].info != strcheck[i]; j++)
            cout << HC[j]; //输出并保存字符串的二进制编码
        ofs << HC[i];
    }
    cout << endl;
    cout << "字符串的二进制编码已经保存在“BCode.txt”中" << endl;

    //cout<<"译码翻译得到的文章已保存在“Data.txt”中"<<endl;
    cout << "*******************************************************************************" << endl;
    cout << "各字符对应的编码为:" << endl; //输出各字符对应的哈夫曼编码
    for (p = 1; p <= k; p++)
    {
        cout << HT[p].info << ": " << HC[p] << endl;
    }
} //CheckCoding

//对键盘输入的二进制代码进行译码
void HuffmanTranslateCoding(HuffmanTree HT, int n, char *c)
{
    ofstream ofs("TransBData.txt"); //译码过程
    int m = 2 * n - 1;
    int i, j = 0;
    cout << "译码翻译得到的文章已保存在“TransBData.txt”中" << endl;
    cout << "译码翻译得到的文章为:";

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
        cout << HT[i].info; //翻译成字符串并输出和保存
        ofs << HT[i].info;
    }
}

//译码过程、、对"BCode.txt"的编码进行译码
void HuffmanTranslateCoding2(HuffmanTree HT, int n)
{
    ifstream ifs("BCode.txt");
    ofstream ofs("TransBData2.txt");

    string c;
    int m = 2 * n - 1;
    int i, j = 0;
    getline(ifs, c);
    cout << "译码翻译得到的文章已保存在“TransBData2.txt”中" << endl;
    cout << "译码翻译得到的文章为:";

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
        cout << HT[i].info; //翻译成字符串并输出和保存

        ofs << HT[i].info;
    }
}

void Menushow()
{
    cout << "  ||************************************************************************||" << endl;
    cout << "  ||                HuffmanCode and HUffmanTranslate  System                ||" << endl;
    cout << "  ||             ***********哈夫曼编码/译码系统*************                ||" << endl;
    cout << "  ||             *************欢迎使用本系统****************                ||" << endl;
    cout << "  ||             东北电力大学 信息工程学院 计机093班 兴趣小组               ||" << endl;
    cout << "  ||                 制作人：范辉强（组长） 李哲 周兴宇                     ||" << endl;
    cout << "  ||************************************************************************||" << endl;
    cout << "  ||在本系统中您可以进行如下操作：                                          ||" << endl;
    cout << "  ||第一部分功能：                                                          ||" << endl;
    cout << "  ||          A :从文件提取字符串，然后对提取的字符串进行编码               ||" << endl;
    cout << "  ||          B :根据W操作对“WCode.txt”里的二进制编码进行译码             ||" << endl;
    cout << "  ||第二部分功能：                                                          ||" << endl;
    cout << "  ||          C :对您输入的字符串进行编码                                   ||" << endl;
    cout << "  ||          D:对BCode.txt里的编码进行译码                                 ||" << endl;
    cout << "  ||          E :对您输入的二进制编码进行译码                               ||" << endl;
    cout << "  ||第三部分功能：                                                          ||" << endl;
    cout << "  ||          F :退出本系统                                                 ||" << endl;
    cout << "  ||************************************************************************||" << endl;
    cout << "  ||温馨提示：                                                              ||" << endl;
    cout << "  ||    执行A，请将您的数据存储在同目录下名为“WData”文本文档里            ||" << endl;
    cout << "  ||    在执行C操作时务必在您输入的字符串后加上“#”                        ||" << endl;
    cout << "  ||    B与A是对应的   B在A后运行                                           ||" << endl;
    cout << "  ||    D/E与C是对应的，即B/C是根据C来进行译码的                            ||" << endl;
    cout << "  ||    译码D/E应在编码C后才能进行                                          ||" << endl;
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
        cout << "请输入您要进行的操作（W/F/B/C/Y/T)(不区分大小写)：" << endl;
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
        case 'e': //进行译码操作
            cout << "请您输入您要编译的二进制编码: " << endl;
            cin >> ch;
            HuffmanTranslateCoding(HT, n, ch);
            break;
        case 'T':
        case 't': //退出系统
            return 0;

        case 'C':
        case 'c': //进行编码操作

            cout << "请输入您要编码的字符串：" << endl;
            //从键盘输入字符串   存放在字符数组str[1000]中
            /*if ((fp=fopen(name,"w"))==NULL)
	   {cout<<"cannot open file"<<endl;
	
           exit(0);
	   }*/
            fp = fopen(name, "w");
            ch2 = getchar(); //接收上一次键盘输入的换行符
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

            cout << "输入的数据已经保存在“BData.txt”中" << endl;
            cout << "*******************************************************************************" << endl;
            cout << "字符串中共含有字符" << n << "个" << endl;
            cout << "*******************************************************************************" << endl;
            for (i = 0; i < n; i++) // 统计从键盘输入的字符串的信息
            {
                j = 0;
                h = 0;
                while (str[i] != str[j])
                    j++;
                if (j == i)
                {
                    info[k] = str[i];
                    cout << "字符" << info[k] << "出现";
                }
                else
                    continue;
                for (j = i; j < n; j++)
                {
                    if (str[i] == str[j])
                        h++;
                }
                cout << h << "次" << endl;
                w[k] = h;
                k++;
            }
            cout << "*******************************************************************************" << endl;
            cout << "字符串中字符种类有" << k << "种" << endl;
            cout << "*******************************************************************************" << endl;

            HuffmanCoding(HT, HC, w, n, info);
            //对输入的字符串进行编码

            *strcheck = str[0];
            cout << "您输入的字符串编码为：" << endl;
            CheckCoding(HT, HC, strcheck, n, k);
            break;

        default:
            cout << "对不起，您的输入不正确！请重新输入" << endl;
        } //switch
    }     //while

} //main