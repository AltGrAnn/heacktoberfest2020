#include<fstream.h>
#include<conio.h>
#include<iostream.h>
class G
{
private:
int status,n,i,j;
float a[10][10],b[10],x[10];
public:
void getdata();
void elimination();
void display();
};
void G::getdata()
{
ofstream outfile;
outfile.open("GEM.txt");
cout<<"\n\n\t\t Gauss Elimination Method\n";
outfile<<"\n\n\t\t Gauss Elimination Method\n";
cout<<"\nWhat is the size of the system?\n\n";
outfile<<"\nWhat is the size of the system?\n\n";
cin>>n;
outfile<<n;
cout<<"\nInput the coeff. a[i][j] row wise, one row on each line\n";
outfile<<"\nInput the coeff. a[i][j] row wise, one row on each line\n";
for (i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cin>>a[i][j];
outfile<<a[i][j];
}
}
cout<<"\nINput vector b\n";
outfile<<"\nInput vector b\n";
for(i=1;i<=n;i++)
{
cin>>b[i];
outfile<<b[i]<<"\n";
}
}
void G::display()
{
ofstream outfile;
outfile.open("GEM.txt",ios::app);
if(status!=0)
{
cout<<"\nSolution vecctor x\n";
outfile<<"\nSolution vector x\n";
for(i=1;i<=n;i++)
{
cout<<"\n"<<x[i]<<"\n";
outfile<<"\n"<<x[i]<<"\n";
}
}
else
{
cout<<"\nsingular matrix. Reorder equation.\n";
outfile<<"\nSingular matrix.Reorder equation\n";
}
outfile.close();
}
void G::elimination()
{
int i,j,k;
float pivot,factor,sum;
for(k=1;k<=n-1;k++)
{
pivot=a[k][k];
if (pivot<0.000001)
{
status=0;
}
else
{
status=1;
}
for(i=k+1;i<=n;i++)
{
factor=a[i][k]/pivot;
for(j=k+1;j<=n;j++)
{
a[i][j]=a[i][j]-factor*b[k];
}
}
x[n]=b[n]/a[n][n];

for(k=n-1;k>=1;k--)
{
sum=0.0;
for(j=k+1;j<=n;j++)
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
G g;
g.getdata();
g.elimination();
g.display();
getch();
}