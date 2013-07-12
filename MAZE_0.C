// <copyright file="Maze_0.C" company="Rajesh">
//
// This source is subject to the Microsoft Permissive License.
// Please see the License.txt file for more information.
// All other rights reserved.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY 
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// </copyright>
// <author>Eswar Rajesh Pinapala</author>
// <email>rajesh.pinapala@gmail.com</email>
// <date>2006-06-10</date>
// <summary>C Program for Snake game</summary>

#include<dir.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<graphics.h>
#include<time.h>
#define MAXCOLOR 15
int touchscreen();
int touchsnakebody();
void rightcode();
void leftcode();
void upcode();
void downcode();
void continuecode();
void ifeat();
void graphicsprinttarget();
void graphicsprinteftarget();
void getgraphics();
void graphics1();
void graphicsprintsnake();
void showscore();
void reset();
void info();
void exit2();
int exit4();
void selectlevel();
void loading();
//void clock();
int checkvalid(char);
/* Function below is required in order to run application */
char *current_directory(char *path)
{
   strcpy(path, "X:\\");      /* fill string with form of response: X:\ */
   path[0] = 'A' + getdisk();    /* replace X with current drive letter */
   getcurdir(0, path+3);  /* fill rest of string with current directory */
   return(path);
}


struct snakebody
{
 int locx,locy;
 int dir;
 };
struct target
{ int locx;
  int locy;
};
struct eftarget
{ int locx;
  int locy;
};

struct snakebody a[300]={0,0,0} ;
struct time t;
char ch;
struct target tar={66,66};//initialise target
struct eftarget eftar={66,66};//initialise extra food target
int first=1;
int last=24;
int points=0,level=1,del=100,flag,pointflag,bgcolor,loadcolor,x=0,y=0,print,hr,min,sec;
int xt=100,yt=68,h,m,s;
char stringp[20],stringl[20],up[5]="w",down[5]="s",right[5]="d",left[5]="a";
char exit3[5]="e",pause[5]="p",feedhr[5],feedmin[5],feedsec[5]; //global variables


void main()
{   char try1='n',sth[10];
    int gd=DETECT,gm,k;  //initgraph sets *graphmode to
		    // the highest resolution available for the detected driver.
    char curdir[MAXPATH]; // Complete file name with path
    current_directory(curdir);  //to get path of current directory
    strcat(curdir,"\\BGI");
    initgraph(&gd,&gm,curdir);
    gettime(&t);
    hr=t.ti_hour;
    min=t.ti_min;
    sec=t.ti_sec;
    info();
    loading();
    start:
    reset();
    selectlevel();
    loading();
    graphics1(); //initialise graphics


    a[1].locx=48 ;
    a[1].locy=60 ;
    a[1].dir=1 ;
    a[2].locx=42 ;
    a[2].locy=60 ;
    a[2].dir=1 ;
    a[3].locx=36 ;
    a[3].locy=60 ;
    a[3].dir=1 ;
    a[4].locx=30 ;
    a[4].locy=60 ;
    a[4].dir=1 ;
 setcolor(RED);
 settextstyle(0,0,0);
 outtextxy((a[1].locx),(a[1].locy),"*");
 outtextxy((a[2].locx),(a[2].locy),"*");
 outtextxy((a[3].locx),(a[3].locy),"*");
 outtextxy((a[4].locx),(a[4].locy),"*");//for entry point of snake

 graphicsprinttarget();

while(1)
 {

  if(touchsnakebody())
  {
    settextstyle(0,0,2);
    setcolor(YELLOW);
    outtextxy(210,200,"Retry Y / N ?");
    e2:
    try1=getch();
    if((try1=='y')||(try1=='n'))
      {
	if(try1=='y')
	goto start;
	else
	flag=exit4();
	if(flag==1)
	goto e2;
      }
      else
      goto e2;
  }


 /* if(touchscreen() )
  { settextstyle(0,0,2);
    setcolor(YELLOW);
    outtextxy(210,200,"Retry Y / N ?");
    e1:
    try1=getch();
    if((try1=='y')||(try1=='n'))
      {
	if(try1=='y')
	goto start;
	else
	flag=exit4();
	if(flag==1)
	goto e2;
      }
      else
      goto e1;

   }     */

  if(print==1)
 {
  h++;
 /* itoa(h,sth,10);
  setcolor(CYAN);
  outtextxy(300,(h*5),sth); */
  if(h>160)
  {
  setcolor(bgcolor);
  outtextxy((eftar.locx),(eftar.locy),"*");
  print=0;
  randomize();
  rand2:
  eftar.locx= (random(66)*6+54); //sets new target
  eftar.locy= (random(66)*6+54);
  for(k=first;k<=last;k++)
  {
  if((a[k].locx==eftar.locx) && (a[k].locy==eftar.locy))
  {
  goto rand2;
  }
  }
 }
  }
  ifeat();

  if(kbhit())
  {
    ch=getch();
    if(ch==right[0]||ch==77) {rightcode();}
    if(ch==left[0] ||ch==75) {leftcode();}
    if(ch==up[0]   ||ch==72) {upcode();}
    if(ch==down[0] ||ch==80) {downcode();}
    if(ch==pause[0]){
		settextstyle(3,0,2);//for pause
		setcolor(YELLOW);
		outtextxy(200,160,"PAUSED....!!.. ");
		outtextxy(140,200,"Press anykey to continue..");
		ch=getch();
		if(ch==exit3[0])
		{
		exit2(1);
		}
		setcolor(bgcolor);
		outtextxy(200,160,"PAUSED....!!.. ");
		outtextxy(140,200,"Press anykey to continue..");//disable previous statement by printing same by background color

	       }
    if(ch==exit3[0])exit2(1);//to exit directly from program
  }

   continuecode();
   delay(del);
   }
} /*end of main*/





/*void touchscreen()
{
 int i;
 if((a[first].locx <24)||(a[first].locx>=(636-24))||(a[first].locy<54)||(a[first].locy>=472) )
 { graphicsprintsnake();
   settextstyle(0,0,2);
   setcolor(RED+WHITE);
   outtextxy(230,150,"Game Over");
   return (1);
   if((a[first].locx <24)//
     a[first].locx=612;
  if((a[first].locx>=(636-24))
    a[first].locx=24
    if((a[first].locy<54)//
     a[first].locx=472;
  if((a[first].loc5>=(472))
    a[first].locx=54;



}

 return(0);
} */

int touchsnakebody()
{
 int i;
 //checks wheather snake face toches with any other body element
 for(i=first+1;i<=last;i++)
{

 if((a[first].locx ==a[i].locx)&&(a[first].locy==a[i].locy) )
 {
   settextstyle(0,0,2);
   setcolor(RED+WHITE);
   outtextxy(230,150,"Game Over");
   return (1);
 }
}
return (0);
}

void rightcode()
{ //changes direction variable of snake face
  if((a[first].dir !=3))
 {
  a[first].dir=1;
  }

}

void leftcode()
{
if((a[first].dir !=1))
 {
  a[first].dir=3;
  }

}

void upcode()
{
 if((a[first].dir!=2) )
 {
  a[first].dir=4;
  }

}

void downcode()
{
 if((a[first].dir!=4) )
 {
  a[first].dir=2;
  }

}

void continuecode()
{
 int i;
 graphicsprintsnake();
 for(i=last;i>=first+1;i--)
 //body elements except snake face copies the
 //direction and location variables from its precedent
  {
   a[i]=a[i-1];
  }

if(a[first].dir==1)
  a[first].locx+=6;
if(a[first].dir==2)
  a[first].locy+=6;
if(a[first].dir==3)
  a[first].locx-=6;
if(a[first].dir==4)
  a[first].locy-=6;


graphicsprinttarget();


}

void ifeat()
{//if target is eaten by snake increment takes place in snake length
 //& sets new target
  int k;
  char feed[10],feedy[10];

/* itoa(y,feedy,10);
  setcolor(bgcolor);
  setcolor(CYAN);
  outtextxy(300,(y*25),feedy);*/
 if((a[first].locx==tar.locx) &&  (a[first].locy==tar.locy))
 {
   y++;
   last++;
  a[last]=a[last-1];//copies previous end
  randomize();
  rand:
  tar.locx= (random(66)*6+54); //sets new target
  tar.locy= (random(66)*6+54);

  for(k=first;k<=last;k++)
  {
  if((a[k].locx==tar.locx) && (a[k].locy==tar.locy))
  {
  goto rand;
  }
 }
  points++;

   if(y%5==0)
  {

   graphicsprinteftarget();

  }
//  last++;
 // a[last]=a[last-1];//copies previous end

}/*setcolor(bgcolor);
 outtextxy(300,300,feed);
 setcolor(BLUE);    */
if(print==1)
   {
 if((a[first].locx==eftar.locx) &&  (a[first].locy==eftar.locy))
 {
   print=0;
   x++;
  randomize();
  rand1:
  eftar.locx= (random(66)*6+54); //sets new target
  eftar.locy= (random(66)*6+54);
  for(k=first;k<=last;k++)
  {
  if((a[k].locx==eftar.locx) && (a[k].locy==eftar.locy))
  {
  goto rand1;
  }
  /* itoa(x,feed,10);
 outtextxy(300,300,feed);*/
 }
 points=points+5;
}
}
showscore();
}

void graphicsprinttarget()
{
  setcolor(CYAN);
  outtextxy((tar.locx),(tar.locy),"*");
}


void graphicsprinteftarget()
{
  setcolor(BLUE);
  outtextxy((eftar.locx),(eftar.locy),"*");
  print=1;
  h=0;
}
void graphics1()
{
 clrscr();
 clearviewport();
 settextstyle(1,0,2);
 setcolor(CYAN);
 outtextxy(260,10,"SNAKE");
 setcolor(WHITE);
 outtextxy(500,25,"score");
  settextstyle(3,0,2);
 outtextxy(100,25,"by P E S P Rajesh");
 if(loadcolor==bgcolor)
 {
 randomize();
 loadcolor=random(MAXCOLOR);
 }
 setcolor(loadcolor);
 rectangle(23,54,(636-23),478);
 setbkcolor(WHITE+RED);
  settextstyle(0,1,2);
  outtextxy(20,40,"press E to Exit at any time");
}

void graphicsprintsnake()
{
  settextstyle(0,0,1);
  setcolor(bgcolor);           //one * is deducted  i.e.one * mixed with
  outtextxy((a[last].locx),(a[last].locy),"*");    //bg color(last),crashed head will go into red
   if((a[first].locx<24))
     a[first].locx=606;
  if((a[first].locx>=(636-24)))
  a[first].locx=24;
    if((a[first].locy<54))
     a[first].locy=468;
  if((a[first].locy>=474))
    a[first].locy=54;

  setcolor(RED);
  outtextxy((a[first].locx),(a[first].locy),"*");

  }


void showscore()
{

     setcolor(bgcolor);
     settextstyle(0,0,2);
     itoa(pointflag,stringp,10);
     outtextxy(530,10,stringp);//disables previous score from screen
     setcolor(WHITE);
     settextstyle(0,0,2);
     itoa(points,stringp,10);
     outtextxy(530,10,stringp);//shows score
     pointflag=points;
 }

void reset()
{//resets all global variable for restarting the game
 int j;
 first=1;
 last=24;
 points=0,level=1,del=100;
 xt=46,yt=34;
 x=0;
 y=0;
 for(j=0;j<=300;j++)
 {  a[j].locx=0;
    a[j].locy=0;
 }


 tar.locx=66;
 tar.locy=66;
  randomize();
  tar.locx=random(tar.locx)*6+54;
  tar.locy=random(tar.locy)*6+54;
}

void info()
{  char ext,opt;
   int extcolor;
   clrscr();
   clearviewport();
   settextstyle(0,0,12);
   setcolor(YELLOW);
   outtextxy(15,35, " SNAKE");
   settextstyle(1,0,2);
   outtextxy(90,150," P.E.S.P.Rajesh,3rd Btech,CSE,JNTU");
   settextstyle(0,0,1);
   setcolor(WHITE);
   outtextxy(230,190," Controls");
   outtextxy(230,220," UP ");     outtextxy(340,220, up);
   outtextxy(230,250," DOWN");    outtextxy(340,250,down);
   outtextxy(230,280," RIGHT");   outtextxy(340,280,right);
   outtextxy(230,310," LEFT");    outtextxy(340,310,left);
   outtextxy(230,340," Pause");   outtextxy(340,340,pause);
   outtextxy(230,370," Exit");    outtextxy(340,370,exit3);
   outtextxy(100,400,"Press any key to continue");
   ext=getch();
   if(ext=='e')
   {
    clrscr();
    clearviewport();
 settextstyle(0,0,2);
 setcolor(RED);
 outtextxy(100,350,"Do you really want to exit? Y/N");
 opt=getch();
 if(opt=='y')
 {
 clrscr();
 clearviewport();
 setbkcolor(bgcolor++);
 settextstyle(1,0,2);
 randomize();
 extcolor=random(MAXCOLOR);
 setcolor(extcolor);
 outtextxy(100,150,"Thanx for Using my SNAKE ");
 outtextxy(120,190,"P.E.S.P.Rajesh,CSE,JNTU");
 delay(1000);

 closegraph();
 restorecrtmode();
 exit(1);
 }else
  setcolor(bgcolor);
 outtextxy(100,350,"Do you really want to exit? Y/N");
 return;
}
}


void exit2()
{

 char opt;
 int extcolor;
 settextstyle(0,0,2);
 setcolor(RED);
 outtextxy(100,350,"Do you really want to exit? Y/N");
 opt=getch();
 if(opt=='y')
 {
 clrscr();
 clearviewport();
 setbkcolor(bgcolor++);
 settextstyle(1,0,2);
 randomize();
 extcolor=random(MAXCOLOR);
 setcolor(extcolor);
 outtextxy(100,150,"Thanx for Using my SNAKE ");
 outtextxy(120,190,"P.E.S.P.Rajesh,CSE,JNTU");
 delay(1000);

 closegraph();
 restorecrtmode();
 exit(1);
 }else
  setcolor(bgcolor);
 outtextxy(100,350,"Do you really want to exit? Y/N");

 return;
}

int exit4()
{
 char opt;
 int extcolor;
  settextstyle(0,0,2);
    setcolor(bgcolor);
    outtextxy(210,200,"Retry Y / N ?");
 settextstyle(0,0,2);
 setcolor(RED);
 outtextxy(100,350,"Do you really want to exit? Y/N");
 opt=getch();
 if(opt=='y')
 {
 clrscr();
 clearviewport();
 setbkcolor(bgcolor++);
 settextstyle(1,0,2);
 randomize();
 extcolor=random(MAXCOLOR);
 setcolor(extcolor);
 outtextxy(100,150,"Thanx for Using my SNAKE ");
 outtextxy(120,190,"P.E.S.P.Rajesh,CSE,JNTU");
 delay(1000);

 closegraph();
 restorecrtmode();
 exit(1);
 }else
  setcolor(bgcolor);
 outtextxy(100,350,"Do you really want to exit? Y/N");
  settextstyle(0,0,2);
    setcolor(YELLOW);
    outtextxy(210,200,"Retry Y / N ?");
 return(1);
}

void selectlevel()
{
 char levelchoice[1],ynchoice;
 int intlevel;
 clrscr();
 clearviewport();
 setbkcolor(BLACK);     //final bg color
 bgcolor=getbkcolor();
 settextstyle(0,0,2);
 setcolor(YELLOW);
 outtextxy(90,200,"Do you want to set level Y/N ?");
 s1:
 ynchoice=getch();
 if((ynchoice=='y')||(ynchoice=='n'))//if 1
   {
     if(ynchoice=='y')//if 2
     {
       clearviewport();
       setcolor(YELLOW);
       outtextxy(100,200,"Select level between 1 to 9");
       s2:
       levelchoice[0]=getch();
       intlevel=atoi(levelchoice);
	if((intlevel<1)||(intlevel>9)) //if 3
       {
	 goto s2;
	}//end if 3
       else
       {   //else 3
	 level=intlevel;
	 del=100-(level-1)*10;
       } //end else 3


     }//end if 2
  }//end if 1
else
    { //else 1
     goto s1;
    } //end else 1

}

void loading()
{
    clearviewport();
    randomize();
    loadcolor=random(MAXCOLOR);
    setbkcolor(bgcolor);

    if(bgcolor==loadcolor)
    {
    loadcolor++;
    }
    setcolor(loadcolor);
    settextstyle(1,0,3);
     outtextxy(40,90,"Loading .. please wait ...");
     settextstyle(3,0,3);
     outtextxy(80,390,"P.E.S.P.Rajesh,3rd Btech,CSE,JNTU");
     delay(300);
     settextstyle(0,0,1);
    outtextxy(100,200,"|||||");
     delay(100);

    settextstyle(0,0,1);
    outtextxy(100,200,"|||||||||||");
     delay(300);

    settextstyle(0,0,1);
    outtextxy(100,200,"||||||||||||||||||");
    delay(300);

    settextstyle(0,0,1);
    outtextxy(100,200,"|||||||||||||||||||||||||||");
    delay(100);


     settextstyle(0,0,1);
    outtextxy(100,200,"||||||||||||||||||||||||||||||||||||||||||||||");
    delay(500);
 }

/*void clock()
{
setcolor(bgcolor);
  settextstyle(2,0,2);
 itoa(h,feedhr,10);
  setcolor(CYAN);
  outtextxy(50,30,feedhr);
   itoa(m,feedmin,10);
  setcolor(CYAN);
  outtextxy(80,30,feedmin);
   itoa(s,feedsec,10);
  setcolor(CYAN);
  outtextxy(120,30,feedsec);
 settextstyle(2,0,2);
 itoa(h,feedhr,10);
  setcolor(CYAN);
  outtextxy(50,30,feedhr);
   itoa(m,feedmin,10);
  setcolor(CYAN);
  outtextxy(80,30,feedmin);
   itoa(s,feedsec,10);
  setcolor(CYAN);
  outtextxy(120,30,feedsec);
}  */

/*start=clock();
 key=getch();
   end=clock();
    r=end-start;
   if(r>=15)*/