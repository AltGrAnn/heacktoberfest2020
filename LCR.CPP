#include<fstream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<iomanip.h>
#include<dos.h>
class lcr
{
float l,c,r,i,v0,w;
public:
void read();
void display();
float fun(float w);
void graph();
};
void lcr::read()
{
ofstream outfile;
outfile.open("lcr,txt");
cout<<"L(H)=";
cin>>l;
outfile<<"L(H)=";
outfile<<l;
cout<<"\nC(uF)=";
cin>>c;
outfile<<"\nC(uF)=";
outfile<<c;
cout<<"\nV0(volt)=";
cin>>v0;
outfile<<"\nV0(volt)=";
outfile<<v0;
outfile.close();
}
float lcr::fun(float w)
{
return(v0/sqrt(pow(r,2)+pow((l*w)-(1/(c*w)),2)));
}
void lcr::display()
{
ofstream outfile;
outfile.open("lcr.txt",ios::app);
cout<<"\n"<<setw(20)<<"W"<<setw(20)<<"I"<<"\n";
outfile<<"\n"<<setw(20)<<"W"<<setw(20)<<"I"<<"\n";
for(r=0.2,w=0.1;w<=2;w+=0.1)
{
i=fun(w);
cout<<setw(20)<<w<<setw(20)<<i<<"\n";
outfile<<setw(20)<<w<<setw(20)<<i<<"\n"; }
outfile.close();
getch();
}
void lcr::graph()
{
int drv=DETECT,mode;
initgraph(&drv,&mode,"c:\\turboc3\\bgi");
setbkcolor(BLACK);
setcolor(YELLOW);
line(50,50,50,450);
line(50,450,650,450);
settextstyle(1,0,3);
outtextxy(210,15,"Series LCR Resonance");
rectangle(200,20,480,45);
settextstyle(1,0,1);
outtextxy(40,450,"(0,0)");
settextstyle(1,0,1);
outtextxy(100,450,"\n\n\t\t Angular Frequency(W)");
settextstyle(1,1,1);
outtextxy(20,200,"\n\t Peak current(Io)");
getch();
int n;
for(r=0.2,n=2;r<1,n<=5;)
{
gotoxy(0,n+3);
cout<<"\n Resistance="<<r;
for(w=0.10;w<=2;)
{
i=fun(w);
w+=0.001;
putpixel((50+(w*290)),450-(i*40),n);
delay(2);
}
r+=0.2;
n+=1;
getch();
}
float w0;
w0=1/sqrt(l*c);
gotoxy(50,9);
cout<<"resonantfrequency(w0)="<<w0;
getch();
}
void main()
{
lcr res;
clrscr();
res.read();
res.display();
res.graph();
getch();
}