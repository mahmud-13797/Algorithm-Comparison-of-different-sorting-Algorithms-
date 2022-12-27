#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void bouble();
void selection();
void insertion();
void merge_run();
void quicksort_run();
void runtime();
void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {


        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);


        merge(arr, l, m, r);
    }


}

void QuickSort1(int a[], int left, int right)
{
    int i = left;
    int j = right;
    int temp = a[i];

    if( left < right)
    {
        while(i < j)
        {
            while(a[j] >= temp && i < j)
            {
                j--;
            }
            a[i] = a[j];

            while(a[i] <= temp && i < j)
            {
                i++;
            }
            a[j] = a[i];
        }
        a[i] = temp;

        QuickSort1(a, left, i - 1);
        QuickSort1(a, j + 1, right);
    }
}

void QuickSort(int a[], int left, int right)
{
    int i = left;
    int j = right;
    int temp = a[i];

    if( left < right)
    {
        while(i < j)
        {
            while(a[j] <= temp && i < j)
            {
                j--;
            }
            a[i] = a[j];

            while(a[i] >= temp && i < j)
            {
                i++;
            }
            a[j] = a[i];
        }
        a[i] = temp;

        QuickSort(a, left, i - 1);
        QuickSort(a, j + 1, right);
    }
}

void setcolor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
//	SetConsoleTextAttributes(hStdOut,wColor);
        SetConsoleTextAttribute(hStdOut,wColor);

    }
}

void login()
{

    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
    {
        system("cls");

        printf("\n  ************************  LOGIN FORM  ************************  ");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n                       ENTER PASSWORD:-");
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i]='\0';
        //char code=pword;
        i=0;
        //scanf("%s",&pword);
        if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
        {
            printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");

            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;

            getch();

        }
    }
    while(a<=2);
    if (a>2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();

    }
    system("cls");
}


int main()      // MAIN FUNCTION
{
    int i=0;

    time_t t;
    time(&t);
    char choice;

    system("cls");   // FOR CLEARING SCREEN
    setcolor(15);
    printf(" -------------------------------------------------------------------------\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
    printf("|  O        O    O O      O        O      O    O O    O O        O        |\n");
    printf("|  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
    printf("|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
    printf("|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
    printf("|                                                                         |\n");
    printf(" -------------------------------------------------------------------------\n");
    printf("\t\t*************************************************\n");
    printf("\t\t*                                               *\n");
    printf("\t\t*      ------------------------------           *\n");
    printf("\t\t*        WELCOME TO Sorting Algorithm           *\n");
    printf("\t\t*      ------------------------------           *\n");
    printf("\t\t*               Yousuf,Heera                    *\n");
    printf("\t\t*               Joya,Bristy                     *\n");

    printf("\t\t*************************************************\n\n\n");
    for(i=0; i<80; i++)
        printf("-");
    printf("\nCurrent date and time : %s",ctime(&t));
    for(i=0; i<80; i++)
        printf("-");
    printf(" \n Press any key to continue:");

    getch();
    system("cls");
    login();
    system("cls");
    while (1)      // INFINITE LOOP
    {
        system("cls");
        setcolor(10);
        for(i=0; i<80; i++)
            printf("-");
        printf("\n");
        printf("   ****************************  |MAIN MENU|  *************************** \n");
        for(i=0; i<80; i++)
            printf("-");
        printf("\n");
        setcolor(10);
        printf("\t\t Please enter your choice for menu:");
        printf("\n\n");
        printf(" \n Enter 1 -> Bubble");
        printf("\n------------------------");
        printf(" \n Enter 2 -> Selection");
        printf("\n----------------------------------");
        printf(" \n Enter 3 -> Insertion");
        printf("\n-----------------------------------");
        printf(" \n Enter 4 -> Merge");
        printf("\n-----------------------------------");
        printf(" \n Enter 5 -> Quicksort");
        printf("\n-----------------------------------");
        printf(" \n Enter 6 -> Runtime(Insertion)");
        printf("\n--------------------------------");
        printf(" \n Enter 7 -> Exit");
        printf("\n----------------------------");
        printf("\n");
        for(i=0; i<80; i++)
            printf("-");
        printf("\nCurrent date and time : %s",ctime(&t));
        for(i=0; i<80; i++)
            printf("-");

        choice=getche();
        choice=toupper(choice);
        switch(choice)           // SWITCH STATEMENT
        {
        case '1':
            bouble();
            break;
        case '2':
            selection();
            break;
        case '3':
            insertion();
            break;
        case '4':
            merge_run();
            break;

        case '5':
            quicksort_run();
            break;

        case '6':
            runtime();
            break;

        case '7':
            system("cls");
            printf("\n\n\t ****THANK YOU****");
            printf("\n\t FOR TRUSTING OUR SERVICE");
            //	Sleep(2000);
            exit(0);
            break;
        default:
            system("cls");
            printf("Incorrect Input");
            printf("\n Press any key to continue");
            getch();
        }
    }
}
void bouble()
{
    FILE *f;
    char test;
    f=fopen("add.txt","a+");
    if(f==0)
    {
        f=fopen("add.txt","w+");
        system("cls");
        printf("Please hold on while we set our database in your computer!!");
        printf("\n Process completed press any key to continue!! ");
        getch();
    }
    while(1)
    {
        system("cls");
        int n,i,j,key,temp,min;
        printf("Enter number of elements:");
        scanf("%d",&n);
        int arr[n];
        printf("Enter elements:");
        for(i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n-1; j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        printf("\n\n");
        printf("Ascending Sorted list using bubble: ");
        for(i=0; i<n; i++)
        {
            printf("%d ",arr[i]);
        }
        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n-1; j++)
            {
                if(arr[j]<arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        printf("\n\nDesending Sorted list using bubble: ");
        for(i=0; i<n; i++)
        {
            printf("%d ",arr[i]);
        }
        for(i=0; i<n-1; i++)
        {
            min=i;
            for(j=i+1; j<n; j++)
            {
                if(arr[j]<arr[min])
                    min=j;
                temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
        }


        fflush(stdin);
        printf("\n\nSuccess!!");
        printf("\n Press esc key to exit");
        test=getche();

        break;


    }
    fclose(f);
}

void selection()
{
    FILE *f;
    char test;
    f=fopen("add.txt","a+");
    if(f==0)
    {
        f=fopen("add.txt","w+");
        system("cls");
        printf("Please hold on while we set our database in your computer!!");
        printf("\n Process completed press any key to continue!! ");
        getch();
    }
    while(1)
    {
        system("cls");
        int n,i,j,key,temp,min;
        printf("Enter number of elements:");
        scanf("%d",&n);
        int arr[n];
        printf("Enter elements:");
        for(i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=0; i<n-1; i++)
        {
            min=i;
            for(j=i+1; j<n; j++)
            {
                if(arr[j]<arr[min])
                    min=j;
                temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
        }



        printf("\nAscending Sorted List using selection: ");
        for( i=0; i<n; i++)
        {
            printf("%d ",arr[i]);
        }
        for(i=0; i<n-1; i++)
        {
            min=i;
            for(j=i+1; j<n; j++)
            {
                if(arr[j]>arr[min])
                    min=j;
                temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
        }
        printf("\nDesending Sorted List using selection: ");
        for(i=0; i<n; i++)
        {
            printf("%d ",arr[i]);
        }
        fflush(stdin);
        printf("\n\nSuccess!!");
        printf("\n Press esc key to exit");
        test=getche();

        break;

    }
    fclose(f);
}
void insertion()
{
    FILE *f;
    char test;
    f=fopen("add.txt","a+");
    if(f==0)
    {
        f=fopen("add.txt","w+");
        system("cls");
        printf("Please hold on while we set our database in your computer!!");
        printf("\n Process completed press any key to continue!! ");
        getch();
    }
    while(1)
    {
        system("cls");
        int n,i,j,key,temp,min;
        printf("Enter number of elements:");
        scanf("%d",&n);
        int arr[n];
        printf("Enter elements:");
        for(i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }

        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        printf("\nAsending Sorted List using insertion: ");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);


        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        printf("\nDesending Sorted List using insertion: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        fflush(stdin);
        printf("\n\nSuccess!!");
        printf("\n Press esc key to exit");
        test=getche();

        break;

    }
    fclose(f);
}


void merge_run()
{
    FILE *f;
    char test;
    f=fopen("add.txt","a+");
    if(f==0)
    {
        f=fopen("add.txt","w+");
        system("cls");
        printf("Please hold on while we set our database in your computer!!");
        printf("\n Process completed press any key to continue!! ");
        getch();
    }
    while(1)
    {
        system("cls");
        int n,i;
        printf("Enter no of elements:");

        scanf("%d",&n);
        int a[n];
        printf("Enter array elements:");
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        mergeSort(a, 0, n - 1);
        printf("Asscending mergesort: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        fflush(stdin);
        printf("\n\nSuccess!!");
        printf("\n Press any key to exit");
        test=getche();

        break;

    }
    fclose(f);
}

void insertion1()
{
    int n,i,j,key,temp,min;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("\nAsending Sorted List using insertion: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);


    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("\nDesending Sorted List using insertion: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void quicksort_run()
{
    FILE *f;
    char test;
    f=fopen("add.txt","a+");
    if(f==0)
    {
        f=fopen("add.txt","w+");
        system("cls");
        printf("Please hold on while we set our database in your computer!!");
        printf("\n Process completed press any key to continue!! ");
        getch();
    }
    while(1)
    {
        system("cls");


        int n,i;
        printf("Enter no of elements:");

        scanf("%d",&n);
        int a[n];
        printf("Enter array elements:");
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }


        QuickSort1(a, 0, n-1);

        printf("Asscending Quicksort: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        QuickSort(a, 0, n-1);
        printf("Descending Quicksort: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        fflush(stdin);
        printf("\n\nSuccess!!");
        printf("\n Press any key to exit");
        test=getche();

        break;

    }
    fclose(f);

}

void runtime()
{
    FILE *f;
    char test;
    f=fopen("add.txt","a+");
    if(f==0)
    {
        f=fopen("add.txt","w+");
        system("cls");
        printf("Please hold on while we set our database in your computer!!");
        printf("\n Process completed press any key to continue!! ");
        getch();
    }
    while(1)
    {
        system("cls");
        int A[100000];
        int i;
        for(i=0; i<100000; i++)
        {
            A[i]=100000-i;
            clock_t start,end;
            start=clock();
            insertion1(A,100000);
            end=clock();
            double timeuse = ((double)(end-start))/CLOCKS_PER_SEC;
            printf("\n%lf Milliseconds with the insertion Sort\n",timeuse*1000);
            break;

        }
        fflush(stdin);
        printf("\n\nSuccess!!");
        printf("\n Press any key to exit");
        test=getche();
        break;
    }
    fclose(f);
}







