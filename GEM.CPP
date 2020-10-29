#include<fstream.h>
#include<conio.h>
#include<iostream.h>
class g
{
private:
int status,n,i,j;
float a[10][10],b[10],x[10];
public:
void getdata();
void elimination();
void display();
};

void g::getdata()
{
ofstream outfile;
outfile.open("gem.txt");
cout<<"\n\n\t\t Gauss Elimination Method \n";
outfile<<"\n\n\t\t Gauss Elimination Method \n";
cout<<"\nsize of the system \n\n";
outfile<<"\nsize of the system \n\n";
cin>>n;
outfile<<n;
cout<<"\nInput the coeff a[i][j] row wise \n \n one row on each line \n";
outfile<<"\nInput the coef a[i][j] row wise \n\n one row on each line \n";
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{

cin>>a[i][j];
outfile<<a[i][j];
}
}
cout<<"\nInput vector b \n\n";
outfile<<"\nInput vector b \n\n";
for(i=1;i<=n;i++)
{
cin>>b[i];
outfile<<b[i]<<"\n";
}
}
void g::display()
{
ofstream outfile;
outfile.open("gem.txt",ios::app);
if(status!=0)
{
cout<<"\nSolution vector x \n";
outfile<<"\nSolution vector x \n";
for(i=1;i<=n;i++)
{
cout<<"\n"<<x[i]<<"\n";
outfile<<"\n"<<x[i]<<"\n";
}

}
else
{
cout<<"\n singuular matrix. reorder eq \n";
outfile<<"\n singular matrix. reorder eq \n";
}
outfile.close();
}
void g::elimination()
{
int i,j,k;
float p,factor,sum;
for(k=1;k<=n-1;k++)
{
p=a[k][k];
if(p<0.000001){
status=0;
}
else
{
status=1;
}
for(i=k+1;i<=n;i++)
{
factor=a[i][k]/p;
for(j=k+1;j<=n;j++)
{
a[i][j]=a[i][j]-factor*a[k][j];
}
b[i]=b[i]-factor*b[k];
}
}
x[n]=b[n]/a[n][n];

for(k=n-1;k>=1;k--)
{
sum=0.0;
for(j=k+1;j<=n;j++)
{
sum=sum+a[k][j]*x[j];
}
x[k]=(b[k]-sum)/a[k][k];
}
}
void main()
{
clrscr();
g G;
G.getdata();
G.elimination();
G.display();
getch();
}