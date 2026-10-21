#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
//Hello deepseek!
typedef struct{
    char name[50];
    char author[30];
    float price;
}Book;

typedef struct{
    Book data[MAXSIZE];
    int length;
}Seqlist;

void InitList(Seqlist *L)
{
    L->length=0;
}

int InsertBook(Seqlist *L,int i,Book a)
{
    if(i<1 || i>L->length+1)return 0;
    if(L->length==MAXSIZE)return 0;
    for(int j=L->length;j>i-1;j--)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=a;
    L->length++;
    return 1;
}

void print(Seqlist *L)
{
    for(int i=0;i<L->length;i++)
    {
        printf("%s %s %.2f\n",L->data[i].name,L->data[i].author,L->data[i].price);
    }
}

void FindBook(Seqlist *L,char *name)
{
    for(int i=0;i<L->length;i++)
    {
        if (strcmp(L->data[i].name, name) == 0)
        {
        printf("find:%s %s %.2f\n",L->data[i].name,L->data[i].author,L->data[i].price);
        return;
        }
    }
    printf("error!");
}

int DeleteBook(Seqlist *L,int i)
{
    if(i<1 || i>L->length)return 0;
    for(int j=i;j<L->length;j++)
    {
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return 1;
}

int ModifyBook(Seqlist *L,int i,Book newbook)
{
    if(i<1 || i>L->length)return 0;
    L->data[i-1]=newbook;
    return 1;
}

int main()
{
    int m,n;
    Seqlist *L=(Seqlist *)malloc(sizeof(Seqlist));
    InitList(L);
    for(int i=0;i<2;i++)
    {
        Book a;
        printf("name:");
        scanf("%s",&a.name);
        printf("author:");
        scanf("%s",&a.author);
        printf("price:");
        scanf("%f",&a.price);
        InsertBook(L,L->length+1,a);
    }
    printf("after insert:");
    print(L);
    char searchName[50];
    printf("find which book:");
    scanf("%s",searchName);
    FindBook(L,searchName);
    printf("delete which one:");
    scanf("%d",&m);
    DeleteBook(L,m);
    printf("after delete:");
    print(L);
    Book newbook;
    printf("--modify--\n");
    printf("name:");
    scanf("%s",&newbook.name);
    printf("author:");
    scanf("%s",&newbook.author);
    printf("price:");
    scanf("%f",&newbook.price);
    printf("modify which one:");
    scanf("%d",&n);
    ModifyBook(L,n,newbook);
    printf("after modify:");
    print(L);
    free(L);
    return 0;
}
