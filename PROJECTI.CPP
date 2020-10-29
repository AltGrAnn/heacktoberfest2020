#include<fstream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<iomanip.h>
#include<process.h>
#include<iostream.h>
#include<graphics.h>
const float pi=3.14156,g=9.8;
class proj
{
public:
double v0,fi,x,y,h,r,tmax,f,t,vx,vy,v;
void read();
void cal();
void fun();
void chart();
void draw();
};
void proj::read()
{
ofstream outfile;
outfile.open("projectile.txt");
cout<<"\n enter the velocity of projection in m/s";
cin>>v0;
outfile<<"enter the velocity of projection in m/s";
outfile<<v0;
cout<<"\n enter the angle of projection in degree";
cin>>f;
outfile<<"\n enter the angle of projection in degree";
outfile<<f;
outfile.close();
}
void proj::cal()
{
fi=pi*f/180;
tmax=2*v0*sin(fi)/g;
h=(v0*v0*sin(fi)*sin(fi))/(2*g);
r=v0*cos(fi)*tmax;
}
void proj::fun()
{
x=(v0*cos(fi)*t);
y=v0*sin(fi)*t-.5*g*pow(t,2);
vx=v0*cos(fi);
vy=v0*sin(fi)-g*t;
v=sqrt(vx*vx*+vy*vy);
}
void proj::chart()
{
read();
cal();
ofstream outfile;
outfile.open("projectile.txt",ios::app);
cout<<"\nt(sec)"<<setw(10)<<"x(m)"<<setw(10)<<"y(m)"<<setw(10)<<"v(m/s)"<<setw(10)
<<"vx(m/s)"<<setw(10)<<"vy(m/s)\n";
outfile<<"\nt(sec)"<<setw(10)<<"x(m)"<<setw(10)<<"y(m)"<<setw(10)<<"v(m/s)"<<setw(10)
<<"vx(m/s)"<<setw(10)<<"vy(m/s)\n";
t=0;
cout<<"\n";
outfile<<"\n";
while(t<=tmax)
{
fun();
cout<<setprecision(2)<<t<<"\t"<<setw(10)<<x<<setw(10)<<y<<setw(10)<<vx<<setw(10)
<<vy<<setw(10)<<v<<endl;
outfile<<setprecision(2)<<t<<"\t"<<setw(10)<<x<<setw(10)<<y<<setw(10)<<vx<<setw(10)
<<vy<<setw(10)<<v<<endl;
t+=0.5;
}
outfile.close();
}
void proj::draw()
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
cal();
gotoxy(15,3);
cout<<"\n\n\t\tvelocity of projection\t="<<v0<<"m/s"<<"\n\t\tangle of projection\t="<<f
<<"degree"<<"\n\t\ttime of flight\t="<<tmax<<"sec"<<"\n\t\tmaximum height\t="<<h<<"m"
<<"\n\t\thorizontal range\t="<<r<<"m";
settextstyle(1,0,3);
setcolor(10);
outtextxy(230,30,"projectile motion");
setcolor(3);
line(80,50,80,400);
line(80,400,630,400);
settextstyle(1,0,1);
outtextxy(110,400,"horizontal displacement");
settextstyle(1,1,1);
outtextxy(40,100,"vertical displacement");
float x1,y1;
t=0;
while(t<=tmax)
{
fun();
x1=(x+80);
y1=(400-y);
putpixel(x1,y1,10);
t+=0.001;
}
getch();
closegraph();
}
void main()
{
clrscr();
proj p;
p.chart();
getch();
p.draw();
getch();
}