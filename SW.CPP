#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#define pi 3.141592
class sw                                 //sw=standing wave//
{
private:
float l,v,tmax,xmax;                   //l=lambda,v=velocity//
public:
sw();
float fnf(float x,float t);
void graph();
};

float sw::fnf(float x,float t)
{
return(sin(2*pi*(x+v*t)/l)+sin(2*pi*(x-v*t)/l)); //sw eq//
}
sw::sw()
{
v=6,tmax=10,xmax=6;
}
void sw::graph()
{
for(l=3;l<=12;)
{
float tp=l/v;                  //tp=time period//
float xmin=0;
float h=0.02,ht=0.02;
float ymin=-2.3,ymax=2.7;
int drv,mode;
drv=DETECT;
initgraph(&drv,&mode,"c:\\turboc3\\bgi");
setbkcolor(BLACK);
setcolor(WHITE);
float xscale=650/(xmax-xmin);
float yscale=400/(ymax-ymin);
cout<<"\n wavelength= "<<l;
gotoxy(6,26);
cout<<"\n velocity= "<<v;
gotoxy(6,27);
cout<<"\n xmax= "<<xmax;
float x,y,t=0;
while(t<tp)
{
x=xmin;
y=(ymax-fnf(x,t))*yscale;
delay(70);
line(0,215,650,215);
settextstyle(1,0,3);
outtextxy(170,15,"Stationary Wave");
moveto(x*xscale,y);
while(x<=xmax)
{
y=fnf(x,t);
y=(ymax-y)*yscale;
x+=h;
lineto(x*xscale,y);
}
t=t+ht;
}
getch();
l=l+3;
}
closegraph();
}
void main()
{
clrscr();
sw s;
s.graph();
getch();
}