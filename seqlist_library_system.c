#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

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
        printf("[%d] %s | %s | %.2f\n", i+1, L->data[i].name, L->data[i].author, L->data[i].price);
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
    printf("error!\n");
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
    Seqlist *L=(Seqlist *)malloc(sizeof(Seqlist));
    if(L==NULL)
    {
        printf("error!");
        return 1;
    }
    InitList(L);
    Book b;
    FILE *fp=fopen("book.txt","r");
    if(fp != NULL)
    {
        while(fscanf(fp,"%49s %29s %f",b.name,b.author,&b.price)==3)
        {
            InsertBook(L,L->length+1,b);
        }
        fclose(fp);
    }
    int choice;
    while(1)
    {
        printf("\n---Library-Management-System---\n");
        printf("1.add book\n");
        printf("2.delete book\n");
        printf("3.search book\n");
        printf("4.modify book\n");
        printf("5.show all books\n");
        printf("0.out\n");
        printf("your choice:");
        if(scanf("%d",&choice) != 1)
                {
                    printf("please enter the number!\n");
                    while(getchar() != '\n');
                    continue;
                }

        if(choice==0)
        {
            printf("exit the system.\n");
            break;
        }
        switch(choice)
        {
            case 1:
            {
            Book a;
            printf("name:");
            scanf("%49s",a.name);
            printf("author:");
            scanf("%29s",a.author);
            printf("price:");
            if(scanf("%f",&a.price) != 1)
                {
                    printf("please enter the number!\n");
                    while(getchar() != '\n');
                    break;
                }
            if(InsertBook(L,L->length+1,a))printf("OK\n");
            else printf("error!");
            break;
            }
            case 2:
            {
            int m;
            printf("the number:");
            if(scanf("%d",&m) != 1)
                {
                    printf("please enter the number!\n");
                    while(getchar() != '\n');
                    break;
                }
            if(DeleteBook(L,m))printf("OK\n");
            else printf("error!\n");
            break; 
            }
            case 3:
            {
                char name[50];
                printf("the name:");
                scanf("%49s",name);
                FindBook(L,name);
                break;
            }
            case 4:
            {
                int n;
                Book newbook;
                printf("name:");
                scanf("%49s",newbook.name);
                printf("author:");
                scanf("%29s",newbook.author);
                printf("price:");
                if(scanf("%f",&newbook.price) != 1)
                {
                    printf("please enter the number!\n");
                    while(getchar() != '\n');
                    break;
                }
                printf("modify which one:");
                if(scanf("%d",&n) != 1)
                {
                    printf("please enter the number!\n");
                    while(getchar() != '\n');
                    break;
                }
                if(ModifyBook(L,n,newbook))printf("OK\n");
                else printf("error!\n");
                printf("after modify:\n");
                print(L);
                break;
            }
            case 5:
            {
                print(L);
                break;
            }
            default:
            printf("error!\n");
        }
    }
    fp=fopen("book.txt","w");
    if(fp != NULL)
    {
        for(int i=0;i<L->length;i++)
        {
            fprintf(fp,"%s %s %.2f\n",L->data[i].name,L->data[i].author,L->data[i].price);
        }
        fclose(fp);
    }
    free(L);
    return 0;
}
