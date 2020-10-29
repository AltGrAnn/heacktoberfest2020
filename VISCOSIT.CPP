#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#include<iomanip.h>
#define pi 3.1415
#define g 9.8
class viscous
{
float m,db,dl,r,a,a0,c,vi,vis,v,tmax,vmax,h,t,yscale,xscale;
public:
void getdata();
void graphics();
void calc();
};
void viscous::getdata()
{
ofstream outfile;
outfile.open("viscous.txt");
cout<<"\n enter the radius of ball in mm";
cin>>r;
outfile<<"\n enter the radius of ball in mm";
outfile<<r;
cout<<"\n enter the density of liquid";
cin>>dl;
outfile<<"\n enter the density of liquid";
outfile<<dl;
cout<<"\n enter the density of ball";
cin>>db;
outfile<<"\n enter the density of ball";
outfile<<db;
cout<<"\n enter the initial velocity of ball";
cin>>vi;
outfile<<"\n enter the initial velocity of ball";
outfile<<vi;
cout<<"\n enter the coefficient of viscosity";
cin>>vis;
outfile<<"\n enter the coefficient of viscosity";
outfile<<vis;
cout<<"\n enter the maximum time";
cin>>tmax;
outfile<<"\n enter the maximum time";
outfile<<tmax;
cout<<"\n enter the time step";
cin>>h;
outfile<<"\n enter the time step";
outfile<<h;
outfile.close();
}
void viscous::calc()
{
ofstream outfile;
outfile.open("viscous.txt",ios::app);
m=(4/3)*pi*pow(r,3)*pow(10,-9)*db;
c=(6*pi*vis*r*pow(10,-3))/m;
a0=((db-dl)/db)*g;
v=vi;
t=0;
cout<<"\n m="<<m;
outfile<<"\n m="<<m;
cout<<"\n c="<<c;
cout<<"\n\t"<<"time\t\t"<<"velocity\t\t"<<" acceleration";
outfile<<"\n\t"<<"time\t\t"<<"velocity\t\t"<<"acceleration";
while(t<=tmax)
{
a=a0-(c*v);
cout<<"\n\t"<<t<<"\t\t"<<v<<"\t\t"<<a;
outfile<<"\n\t"<<t<<"\t\t"<<v<<"\t\t"<<a;
v+=(a*h);
t+=h;
getch();
}
vmax=v;
cout<<"\n maximum velocity="<<vmax;
outfile<<"\n maximum velocity="<<vmax;
outfile.close();
}
void viscous::graphics()
{
t=0;
v=vi;
h=0.0001;
int drv=DETECT,mode;
initgraph(&drv,&mode,"c:\\turboc3\\bgi");
setbkcolor(WHITE);
setcolor(RED);
line(20,400,600,400);
line(20,50,20,400);
xscale=(580/tmax);
yscale=(350/vmax);
settextstyle(1,0,1);
outtextxy(19,405,"(0,0)");
outtextxy(200,405,"time");
settextstyle(1,1,1);
outtextxy(1,100,"velocity");
settextstyle(1,0,3);
outtextxy(150,10,"velocity time graph");
while(t<tmax)
{
a=a0-c*v;
putpixel(20+(t*xscale),(((vmax-v)*yscale)+50),RED);
v+=(a*h);
t+=h;
}
delay(60);
getch();
}
void main()
{
clrscr();
viscous v;
v.getdata();
v.calc();
v.graphics();
}