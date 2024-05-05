/*
A library database maintains the following information about books:book_id, name, author,
no_of_copies. Write a program to sort the books based on the decreasing order of number of copies available.
*/
#include <stdio.h>
struct library {
    int bookId;
    char name[40];
    char author[50];
    int copies;
};
void main()
{
    int n;
    printf("Enter number of books:\n");
    scanf("%d",&n);
    struct library bk[n],temp;
    for(int i=0; i<n; i++)
    {
        printf("Enter details of the book %d\n",i+1);
        printf("Book Id:\n");
        scanf("%d",&bk[i].bookId);
        printf("Name of the book:\n");
        scanf("%s",bk[i].name);
        printf("Author:\n");
        scanf("%s",bk[i].author);
        printf("Number of copies:\n");
        scanf("%d",&bk[i].copies);
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(bk[j].copies>bk[j+1].copies){
                temp=bk[j];
                bk[j]=bk[j+1];
                bk[j+1]=temp;
            }
        }
    }
    printf("Sorted details of the books \n");
    for(int i=0; i<n; i++)
    {
        printf("Id of the Book:%d\n",bk[i].bookId);
        printf("Name of the book:%s\n",bk[i].name);
        printf("Name of the Author:%s\n",bk[i].author);
        printf("Number of copies:%d\n",bk[i].copies);
    
    }
}

/*
Output
Enter number of books:
3
Enter details of the book 1
Book Id:
22
Name of the book:
ab
Author:

zx
Number of copies:
41
Enter details of the book 2
Book Id:
68
Name of the book:
cd
Author:
wv
Number of copies:
23
Enter details of the book 3
Book Id:
98
Name of the book:
ef
Author:
io
Number of copies:
17
Sorted details of the books
Book Id:98
Name of the book:ef
Name of the Author:io
Number of copies:17
Book Id:68
Name of the book:cd
Name of the Author:wv
Number of copies:23
Book Id:22
Name of the book:ab
Name of the Author:zx
Number of copies:41
*/