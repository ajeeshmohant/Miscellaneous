#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string.h>
using namespace std;
int main()
{
int i,j,k,h,N,len,n,a,b,it=0,fmx,lp,ms,mp;
string word;
word="AJEESH";
cout<<"word="<<word<<endl;
len=word.size();
cout<<"len="<<len<<endl;
char tg[len+1];
strcpy(tg,word.c_str());
cout<<"tg = ";
for(i=0;tg[i]!='\0';i++)
cout<<tg[i];
cout<<endl;
N=1000; //size of population
ms=0.25*N;
char pop[N][len+1], popn[N][len+1], child[len+1];
int fit[N],fsort[N],mates[ms],mate[100000];

srand(time(0)); //Random number initialization

for(i=0;i<N;i++) //population generation
for(j=0;j<len;j++)
{
while(true)
{
n=rand()%90+65;
if((n>=65)&&(n<=90))
break;
}
pop[i][j]=n;
}
while(it<1000) // iteration loop for selection and mating
{
cout<<"Iteration number = "<<it<<endl;
for(i=0;i<N;i++)
{
fit[i]=0;
for(j=0;j<len;j++)
if(pop[i][j]==tg[j])
fit[i]++;		//fitness calculation
if(fit[i]==len)
{
cout<<"Match Found\n";  //checking perfect match (100% fitness)
for(j=0;j<len;j++)
cout<<pop[i][j];
cout<<endl;
return(0);
}
}
for(i=0;i<N;i++)
fsort[i]=fit[i];
for(j=0;j<ms;j++)
{
mates[j]=0;
fmx=0;
for(i=0;i<N;i++)
if(fsort[i]>fmx)
{
fmx=fsort[i];		//sorting DNAs based on fitness and adding the most fit DNA positions to pre-mating pool
lp=i;
}
mates[j]=lp;
fsort[lp]=-1;
}

cout<<"Maximum fitness = "<<fit[mates[0]]<<endl;
cout<<"Best match =  ";
/*
for(i=0;i<N;i++)
if(fit[mates[i]]==fit[mates[0]])
{
for(j=0;j<len;j++)
cout<<pop[mates[i]][j];
cout<<endl;
}
*/

for(j=0;j<len;j++)
cout<<pop[mates[0]][j];
cout<<endl;
cout<<endl;


//initializing mating pool
for(i=0;i<100000;i++)
mate[i]=0;

//Mating pool with probability of fitness
int sum=0,perl=0,p=0; //perl = per lakh
for(j=0;j<ms;j++)
sum+=fit[mates[j]];
cout<<"sum of fitness = "<<sum<<endl;
for(j=0;j<ms;j++)
{
perl=((fit[mates[j]]*100000)/sum);
if(perl==0)
break;
for(k=1;k<=perl;k++)
mate[p+k]=mates[j];
p+=perl;
}

//reproduction	
for(i=0;i<N;i++)
{
while(true)
{
a=rand()%100000+1;	//random number to choose first parent to mate with
if((a>=1)&&(a<=100000))
break;
}
while(true)
{
b=rand()%100000+1;	//random number to choose second parent to mate with
if((b>=1)&&(b<=100000))
break;
}

if(len%2==0)		//spliting parents to half
h=len/2;
else
h=(len-1)/2;

for(j=0;j<h;j++)	//cross over
child[j]=pop[mate[a]][j];
for(j=h;j<len;j++)
child[j]=pop[mate[b]][j];

while(true)		//mutation
{
n=rand()%100+1;
if((n>=1)&&(n<=100))
break;
}
if(n==7)
{
while(true)		
{
mp=rand()%len+1;
if((mp>=1)&&(mp<=len))
break;
}
a=0;
while(true)
{
a=rand()%90+65;
if((a>=65)&&(a<=90))
break;
}
if((a>=65)&&(a<=90))
child[mp-1]=a;
}

for(j=0;j<len;j++)
popn[i][j]=child[j];	//adding child to new population
}			//reproduction loop ends

for(i=0;i<N;i++)
for(j=0;j<len;j++)
pop[i][j]=popn[i][j];	//updating population array to the new one

it++;		//iteration variable update
}		//iteration loop ends
return(0);
}










