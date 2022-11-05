//Lib.h
int* sort(int*,int);
char* sort(char*,int);
double* sort(double*,int);
int pallin(int);
int pallind(char[]);

//Lib.cpp
#include"Lib.h"
#include<string.h>
int* sort(int*a,int n)
{
 int* b;
 b=new int[n];
 int i,j,k,temp;
 for(k=0;k<n;k++)
 {
  b[k]=a[k];
 }
 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(b[i]>b[j])
   {
    temp=b[i];
    b[i]=b[j];
    b[j]=temp;
   }
  }
 }
 return b;
}


char* sort(char*str,int m)
{
 int i,j,k; char t;
 char* r;
 r=new char[m];
   for(k=0;k<m;k++)
    {
      r[k]=str[k];
    }
   for(i=0;i<m;i++)
    {
     for(j=i+1;j<m;j++)
      {
       if(r[i]>r[j])
        {
         t=r[i];
         r[i]=r[j];
         r[j]=t;
        }
     }
   }
 return r;
}


double* sort(double*d,int size)
{
 int i,j,k; double temp;
 double* b;
 b=new double[size];
 for(i=0;i<size;i++)
 {
  b[i]=d[i];
 }
 for(i=0;i<size;i++)
 {
  for(j=i+1;j<size;j++)
  {
   if(b[i]>b[j])
   {
    temp=b[j];
    b[j]=b[i];
    b[i]=temp;
   }
  }
 }
 return b;
}

int pallin(int num)
{
 int res=0,rem=0,orig;
 orig=num;
 while(orig!=0)
 {
  rem=orig%10;
  res=res*10+rem;
  orig=orig/10;
 }
if(res==num)
 return 1;
else
 return 0;
}

int pallind(char ch[10])
{
 int i=0,c,len,l; char a[10],n[10];

  len=strlen(ch);
   strcpy(n,ch);
 while(ch[i]!='\0')
  {
   a[i]=ch[len-1];
   len--;
   i++;
  }
   a[i]='\0';
   if(strcmp(a,n)==0)
   return 1;
     else
    return 0;
  }

//App.cpp
#include"Lib.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
 int n,op,size,*result,i,len,num,ch,q,*a,*b,Size,in,check,p,res;
 char *sol,*str,*x,*r;
 char s[10];
 double *d,*y,*answer;
 do
 {
  cout<<"\nChoose any one\n1.To sort the elements\n2.To check palindrome\n3.Exit\n";
  cin>>n;
  switch(n)
  {
   case 1: do
           {
            cout<<"\nChoose any one\n1.Sort array of integer\n2.Sort array of character\n3.Sort array of double\n4.Exit\n";
            cin>>op;
            switch(op)
            {
             case 1:cout<<"Enter the size of array\n";
                    cin>>size;
                    a=new int[size];
                    cout<<"Enter the array elements\n";
                    for(i=0;i<size;i++)
                    {
                     cin>>a[i];
                    }
                    int* p;
                    p=new int[size];
                    p=sort(a,size);
                    cout<<"The sorted array is\n";
                    for(i=0;i<size;i++)
                     {
                        cout<<p[i]<<"\t";
                     }
                    break;
                
            case 2: cout<<"Enter the array size\n";
                    cin>>Size;
                    str=new char[Size];
                    cout<<"Enter the elements\n";
                    for(i=0;i<Size;i++)
                     {
                      cin>>str[i];
                     }
                    char* q;
                    q=new char[Size];
                    q=sort(str,Size);
                    cout<<"The sorted characters are ";
                    for(i=0;i<Size;i++)
                    {
                    cout<<q[i]<<'\t';
                    }
                    break;
                
            case 3: cout<<"Enter the size of array\n";
                    cin>>in;
                    d=new double[in];
                    cout<<"Enter the array elements\n";
                    for(i=0;i<in;i++)
                     {
                      cin>>d[i];
                     }
                    double* ans;
                    ans=new double[in];
                    ans=sort(d,in);
                    cout<<"Sorted elements\n";
                    for(i=0;i<in;i++)
                     {
                       cout<<ans[i]<<'\t';
                     }
                    break;
                
           case 4:exit(0);
                   break;
         }
        }
     while(op<=4);

   case 2: do
           {
            cout<<"\nChoose any one\n1.Number Pallindrome\n2.String Pallindrome\n3.Exit\n";
            cin>>ch;
            switch(ch)
             {
               case 1:cout<<"Enter the number to check\n";
                      cin>>num;
                      q=pallin(num);
                      if(q==1)
                      cout<<"Pallindrome\n";
                      else
                      cout<<"Not  Pallindrome\n";
                      break;
                
              case 2: cout<<"Enter the string\n";
                      cin>>s;
                      res=pallind(s);
                      if(res==1)
                      cout<<"Pallindrome\n";
                      else
                      cout<<"Not Pallindrome\n";
                      break;

              case 3: break;
           }
       }
         while(ch<=2);
         break;
      
  case 3: exit(0);
          break;
      }
   }
while(n<=2);
}

//makefile
out.exe:Lib.o App.o
        c++ -o out.exe Lib.o App.o
Lib.o:Lib.cpp
        c++ -c Lib.cpp
App.o:App.cpp
        c++ -c App.cpp
