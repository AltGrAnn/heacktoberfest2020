#include <fstream.h>
#include<conio.h>
#include<iomanip.h>
#include<math.h>
class bis
{
float x0,x1,x2,x,fun(float),f0,f1,f2,n,xmax,xmin,al;
int a;
public:
void sol();
void cal();
};
float bis::fun(float x)
{
return((x*x)+(4*x)-10);
}
void bis::sol()
{
ofstream outfile;
outfile.open("bis.txt");
cout<<"\n enter the value of xmax:";
outfile<<"\n enter the value of xmax:";
cin>>xmax;
outfile<<xmax;
cout<<"\n x"<<"\t \t"<<"f(x)"<<"\n";
outfile<<"\n x"<<"\t \t"<<"f(x)"<<"\n";
for (float i=xmin; i<=xmax; i+=0.25)
{
cout<<i<<"\t \t"<<fun(i)<<"\n";
outfile<<i<<"\t \t"<<fun(i)<<"\n";
}
getch();
outfile.close();
}void bis::cal()
{
ofstream outfile;
outfile.open("bis.txt",ios::app);
cout<<"\n enter the 1st value: ";
outfile<<"\n enter the 1st value:";
cin>>x1;
outfile<<x1;
cout<<"\n enter the 2nd value: ";
outfile<<"\n enter the 2nd value:";
cin>>x2;
outfile<<x2;
f1=fun(x1);
f2=fun(x2);
a=0;
if(f1*f2<0)
{
cout<<"\n enter the limit of accuracy(al):";
outfile<<"\n enter the limit of accuracy(al):";
cin>>al;
outfile<<al;
do
{
a++;
x0=(x1+x2)/2;
f0=fun(x0);
if ((f1*f0)==0)
break;
else if((f1*f0)<0)
{
x2=x0;
f2=f0;
}
else
{
x1=x0;
f1=f0;
}
n=fabs((x1-x2)/x1);
}
while (n>al);
x0=(x1+x2)/2;
cout<<"\n one rrot is:"<<x0;
outfile<<"\n one root is:"<<x0;
cout<<"\n no of itrations:"<<a;
outfile<<"\n no fo itrations:"<<a;
}
else
{
cout<<"\n starting values do not bracket any roots.:";
outfile<<"\n starting values do not bracket any roots.:";
}
getch();
outfile.close();
}
void main()
{
clrscr();
bis b;
b.sol();
b.cal();
getch();
}