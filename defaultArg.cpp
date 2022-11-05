//Lib.h
int Min(int*,int,bool=0);
int** trans(int**,int=3,int=2);

//cat Lib.cpp
#include"Lib.h"
int  Min(int *a,int m,bool s)
 {
   int i,j,min;
   int *b=new int[m];
  // int min=b[0];
   for(i=0;i<m;i++)
   {
    if(a[i]>0)
      break;
   }
   if(s==0)
   {
    for(i=0;i<m;i++)
     {
      if(b[i]>0)
      {
       if(min>b[i])
        min=b[i];
      }
      else
        return -1;
     }
   }
  else
    min=a[0];
    for(i=0;i<m;i++)
     {
       min=b[i];
       if(min>b[i])
         min=b[i];
     }
  return min;
  }

int** trans(int**x,int r1,int c1)
{
 int i,j;
 int**y;
 y=new int*[r1];
 for(i=0;i<r1;i++)
  {
   y[i]=new int[c1];
  }

 for(i=0;i<r1;i++)
  {
   for(j=0;j<c1;j++)
     {
       y[i][j]=x[j][i];
     }
  }
 return y;
}

//App.cpp
#include<iostream>
#include"Lib.h"
#include<stdlib.h>
using namespace std;

int main()
{
 int *a, n,size,j,i,op,sol,ans,r,c,**x,**y,ch,rows,columns,matrix[5][5],row,mat[5][5],col, matx[5][5];
 int**res;
 bool sign;
 do
 {
 cout<<"Choose any one\n1.To find minimum\n2.To find Transpose\n3.Exit\n";
 cin>>n;
 switch(n)
  {
   case 1: cout<<"Enter the array size\n";
           cin>>size;
           cout<<"Enter the array elements\n";
           a=new int[size];
           for(i=0;i<size;i++)
           {
            cin>>a[i];
           }
           do
           {
            cout<<"\nChoose one\n1.With sign\n2.Without sign\n3.Exit\n";
            cin>>op;
            switch(op)
             {
              case 1:cout<<"Enter the sign\n";
                     cin>>sign;
                     sol=Min(a,size,sign);
                     if(sol==-1)
                        cout<<"NO POSITIVE NUMBER\n";
                     else
                      cout<<"The min element is "<<sol;
                     break;
              case 2:ans=Min(a,size);
                     cout<<"The min element is "<<ans;
                     break;
              case 3:exit(0);
                     break;
            }
         }
        while(op<3);
  case 2: cout<<"Enter the rows and columns for the matrix\n";
          cin>>r>>c;
          cout<<"Enter the matrix elements\n";
           y=new int*[r];
           for(i=0;i<r;i++)
            {
             y[i]=new int[c];
            }
           for(i=0;i<r;i++)
           {
            for(j=0;j<c;j++)
            {
             cin>>y[i][j];
            }
           }
            res=new int*[r];
            for(i=0;i<r;i++)
             {
              res[i]=new int[c];
             }
            cout<<"The Entered Matrix is\n";
            for(i=0;i<r;i++)
            {
             for(j=0;j<c;j++)
             {
              cout<<y[i][j]<<" ";
             }
             cout<<"\n";
           }

          do
          {
           cout<<"\nChoose any one\n1.With row and column\n2.With row without column\n 3.Without row and column\n4.Exit\n";
           cin>>ch;
           switch(ch)
            {
             case 1:cout<<"Enter the rows and columns needed\n ";
                    cin>>rows>>columns;
                    res=trans(y,rows,columns);
                    cout<<"The matrix is\n";
                    for(i=0;i<rows;i++)
                    {
                     for(j=0;j<columns;j++)
                     {
                      cout<<res[i][j]<<" ";
                     }
                    cout<<"\n";
                    }
                    break;
               
             case 2:cout<<"Enter the rows\n";
                    cin>>row;
                    res=trans(y,row,c);
                    cout<<"The matrix is\n";
                    for(i=0;i<row;i++)
                    {
                     for(j=0;j<2;j++)
                     {
                      cout<<res[i][j]<<" ";
                     }
                     cout<<"\n";
                    }
                    break;

              case 3: res=trans(y,r,c);
                      cout<<"The matrix is\n";
                      for(i=0;i<3;i++)
                      {
                       for(j=0;j<2;j++)
                       {
                        cout<<res[i][j]<<" ";
                       }
                      cout<<"\n";
                      } 
                      break;

            case 4: break;
                }
             }
        while(ch<3);
      }
   } 
    while(n<=3);
  }

//makefile
out.exe:Lib.o App.o
        c++ -o out.exe Lib.o App.o
Lib.o:Lib.cpp
        c++ -c Lib.cpp
App.o:App.cpp
        c++ -c App.cpp
