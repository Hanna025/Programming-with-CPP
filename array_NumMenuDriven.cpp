//numlibHead.h
int Isprime(int);
int occurence(int,int);
int rev(int);
int check(int);
int encrypt(int);

//arraylibHead.h
int sum(int [],int);
int occur(int [],int,int);
float mean(int [],int);

//numlibImp.cpp
#include"numlibHead.h"
int Isprime(int n)
{
 	int i,c=0;
 	for(i=1;i<=n;i++)
	 {
 		 if(n%i==0)
 		 c++;
 	 }
  	if(c==2)
  		 return 0;
 	else
   		 return 1;
}


int occurence(int num,int k)
{
 	int c=0,rem;
 	while(num>0)
	 {
  		rem=num%10;
  		if(rem==k)
 		c++;
  		num=num/10;
	 }
 	return c;
}


int rev(int n)
{
 	int rem,res=0;
	while(n>0)
 	{
 	  	rem=n%10;
  		res=res*10+rem;
  		n=n/10;
 	}
	 return res;
}


int check(int num)
{
 	if(num%10==0)
 		 return 1;
 	else
  		 return 0;
}


int encrypt(int num)
{
 	int b,f,res,c,d;
 	res=check(num);
 	if(res==0)
 	{
 		 b=rev(num);
  	     while(b>0)
  			{
  				 c=b%10;
   				 d=(d*10)+((b+7)%10);
  				 b=b/10;
  			}
	 }
	 return d;
}



//arraylibImp.cpp
#include"arraylibHead.h"
int sum(int a[10],int size)
{
 	int i,res=0;
 	for(i=0;i<size;i++)
 	{
 		 res=res+a[i];
 	}
	 return res;
}


int occur(int a[10],int size,int x )
{
 	int i,c=0;
	for(i=0;i<size;i++)
 	{
 		 if(a[i]==x)
 		 c++;
 	}
    return c;
}


float mean(int a[10],int size)
{
 	float avg,ans;
 	ans=sum(a,size);
 	avg=ans/size;
 	return avg;
}

//App.cpp
#include<iostream>
#include"numlibHead.h"
#include"arraylibHead.h"
#include<stdlib.h>
using namespace std;
int main()
{
 	int a[10],num,i,n,ans,result,t,op,res,k,size,ch,x,d,answer;float m;
 	do
 	{
  		cout<<"\nChoose  any one\n1.Numeric Operation\n2.Array Operation\n3.Exit\n";
  		cin>>op;
  		switch(op)
   			{
    			case 1:cout<<"Enter a number\n";
           			   cin>>num;
          
				do
           		 {
             		cout<<"\nChoose any one\n1.To check prime or not\n2.Occurence\n3.Encryption\n4.Exit\n";
             		cin>>n;
             		switch(n)
              		 {
               			case 1: res=Isprime(num);
                       			if(res==0)
                        			cout<<"Prime\n";
                       			else
                        			cout<<"Not prime\n";
                       			break;

               		   case 2: cout<<"Enter a key\n";
                       		   cin>>k;
                       		   ans=occurence(num,k);
                       		   cout<<"The key occurs "<<ans<<" times";
                               break;

                       case 3: d=encrypt(num);
                               cout<<"The encrypted number is "<<d;
                               break;

                      case 4: break;
                   }
                  while(n<=3);
              }
                  break;
				
               case 2: cout<<"Enter the number of elements\n";
            		   cin>>size;
                       cout<<"Enter array elements\n";
                       for(i=0;i<size;i++)
                        {
                          cin>>a[i];
                        }
                       do
                        {
                          cout<<"\nChoose any one\n1.Sum of array elements\n2.Occurence\n3.Mean\n4.Exit\n";
                          cin>>ch;
                          switch(ch)
                           {
                               case 1:answer=sum(a,size);
                                      cout<<"Sum is "<<answer;
                                      break;

                               case 2:cout<<"Enter a key\n";
                                      cin>>x;
                                      t=occur(a,size,x);
                                      cout<<"Occurence is "<<t<<" times";
                                      break;

                               case 3:m=mean(a,size);
                                      cout<<"The mean is "<<m;
                                      break;

                               case 4:
                                      break;
                         }
                    }
                    while(ch<=3);
                    break;
               case 3: exit(0);
                       break;
           }
       }
       while(op<=2);
   }

//makefile
out.exe:numlibImp.o arraylibImp.o App.o
        c++ -o out.exe numlibImp.o arraylibImp.o App.o
numlibImp.o:numlibImp.cpp
        c++ -c numlibImp.cpp
arraylibImp.o:arraylibImp.cpp
        c++ -c arraylibImp.cpp
App.o:App.cpp
        c++ -c App.cpp
