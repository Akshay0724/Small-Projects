#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <dos.h>
union REGS in,out;
int X,Y,BU,x,y,count=0,num=0,num1=0,result=0;
char *ch[3][6]={"1","2","3","4","-","+","5","6","7","8","*","/","9","0",".","CLR","="};
char c[18]={'1','2','3','4','-','+','5','6','7','8','*','/','9','0','.','l','='},opr,str[40];
void initmouse()
{
	in.x.ax=0;
	int86(0x33,&in,&out);
       //	return(o.x.ax);
}

int showmouse()
{
    in.x.ax=1;
    int86(51,&in,&out);
    return 1;
}

void mousepos(int *xpos,int *ypos,int *click)
{
    in.x.ax=3;
    int86(51,&in,&out);
   * click=out.x.bx;
   * xpos=out.x.cx;
   * ypos=out.x.dx;
}
void button_3d(int x1,int y1,int x2,int y2,int check,char* text,int color)
{
int up,low;
setfillstyle(1,7);
bar(x1,y1,x2,y2);
if(check==0)    //Unclicked
up=15,low=8;
else
up=8,low=15;     //Clicked
setcolor(low);
line(x2,y1,x2,y2);
line(x2-1,y1,x2-1,y2);
line(x1,y2,x2,y2);
line(x1+1,y2-1,x2,y2-1);

setcolor(up);
line(x1,y1,x2,y1);
line(x1+1,y1+1,x2-1,y1+1);
line(x1,y1,x1,y2);
line(x1+1,y1+1,x1+1,y2-1);
setcolor(color);

settextjustify(CENTER_TEXT,CENTER_TEXT);
outtextxy(x1+(x2 - x1)/2,(y1+(y2 - y1)/2)-2, text);


}
void addnum(int getnum)
{
	num=((num*10)+getnum);
}

void disp(float dig)
{
    setfillstyle(1,10);
    bar(x-195,y-95,x+145,y-60);
    gcvt(dig,9,str);
    outtextxy(x-150,y-75,str);
}

void structure()
{
	int i,j,k=0;
    setfillstyle(1,7);
    x=getmaxx()/2;
    y=getmaxy()/2;
    y-=80;
    bar(x-200,y-100,x+150,y+100);
    setfillstyle(1,10);
    bar(x-195,y-95,x+145,y-60);
    setfillstyle(1,9);//printf("%d%d",x-160,y-20);
    for(i=20;i>=-100;i-=50){
    for(j=160;j>=-20;j-=50)
    {
    button_3d(x-j-30,y-i-30,x-j,y-i,0,ch[0][0]+k,4);//  printf("%d %d",x-j,x-j-30);
   k+=2;
    }
   if(i==-80)
     button_3d(x-j+10,y-i-30,x-j+100,y-i,0,ch[0][0]+k+2,4);
   else
    for(j=-80;j>=-180;j-=60)
    {
     button_3d(x-j-30,y-i-30,x-j,y-i,0,ch[0][0]+k,4);
     k+=2;
    }
 }
    // settextstyle(1,0,3);
   //  outtextxy(x-150,y-75,"1234");

}

void calcu(char input)
{
    switch(input)
	 {
	 case '1':
		 addnum(1);
		disp(num);

		 break;
	 case '2':
		 addnum(2);
		disp(num);

		 break;
	  case '3':
		 addnum(3);
		disp(num);

		 break;
	   case '4':
		 addnum(4);
		disp(num);

		 break;
	 case '5':
		 addnum(5);
		disp(num);

		 break;
	 case '6':
		 addnum(6);
		disp(num);

		 break;
	 case '7':
		 addnum(7);
		disp(num);

		 break;
   case '8':
		 addnum(8);
		disp(num);

		 break;
   case '9':
		 addnum(9);
		disp(num);

		 break;
   case '0':
		 addnum(0);
		disp(num);

		 break;
	case '+':
		 num1=num;
		 num=0;
		 opr='+';

		 break;
	 case '-':
		 num1=num;
		 num=0;
		 opr='-';

		break;
	 case '*':
		 num1=num;
		 num=0;
		 opr='*';

		break;
	 case '/':
		 num1=num;
		 num=0;
		 opr='/';
		break;
	 case 'l':
		 num=0;
		 num1=0;
		 result=0;
		 count=0;
		disp(num);

		 break;
	 case '=':
		 switch(opr)
		 {
		   case '+':
				 if(count<1)
				 {
				   result=num+num1;
				 }
				 else
				 {
				   result=result+num;
				 }
				disp(result);

				 count+=1;
				 break;
		   case '-':
				 if(count<1)
				 {
				   result=num1-num;
				 }
				 else
				 {
				   result=result-num;
				 }
				disp(result);

				 count+=1;
				 break;
		   case '*':
				 if(count<1)
				 {
				  result=num1*num;
				 }
				 else
				 {
				  result=result*num;
				 }
				disp(result);

				 count+=1;
				 break;
		   case '/':
				 if(count<1)
				 {
				  result=num1/num;
				 }
				 else
				 {
				  result=result/num;
				 }
				disp(result);

				 count+=1;
				 break;
		 }
	     //	 defualt : outtextxy(x-150,y-75,"akshay");
}

}


void main()
{
    int gd=DETECT,gm,i,j,k=0,t,e=1;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    structure();
    initmouse();
    showmouse();

    while(!kbhit())
    {
     mousepos(&X,&Y,&BU); // delay(1000);
     //	button_3d(x-j,y-i,x-j-30,y-i-30,1,ch[0][0]+k,4);
     //	delay(250);
     //	button_3d(x-j,y-i,x-j-30,y-i-30,0,ch[0][0]+k,4);
	if(BU)
	{
	k=0;
    for(i=20;i>=-100;i-=50){
    for(j=160;j>=-20;j-=50)
    {e=1; // if(e)  printf("%d ",x-j);  e=0;
    if(X>=(x-j-30)&&Y>=(y-i-30)&&X<=(x-j)&&Y<=(y-i)){
	button_3d(x-j-30,y-i-30,x-j,y-i,1,ch[0][0]+k,4);
	delay(250);  //     printf("aksjay");
	button_3d(x-j-30,y-i-30,x-j,y-i,0,ch[0][0]+k,4);
	t=k;break;// outtextxy(x-150,y-75,ch[0][0]+t);
    }
   k+=2;
    }
   if(i==-80){
   if(X<=(x-j+100) && Y>=(y-i-30) && X>=(x-j+10) && Y<=(y-i)){
     button_3d(x-j+10,y-i-30,x-j+100,y-i,1,ch[0][0]+k+2,4);
     delay(250);
     button_3d(x-j+10,y-i-30,x-j+100,y-i,0,ch[0][0]+k+2,4);
     t=32;
     }}
   else
    for(j=-80;j>=-180;j-=60)
    {
    if(X>(x-j-30)&&Y>(y-i-30)&&X<(x-j)&&Y<(y-i)){
	button_3d(x-j-30,y-i-30,x-j,y-i,1,ch[0][0]+k,4);
	delay(250);
	button_3d(x-j-30,y-i-30,x-j,y-i,0,ch[0][0]+k,4);
	t=k;
    }
     k+=2;
    }   e=0;
 }
 calcu(*(c+t/2));
	}
    }
  //  getch();
}

