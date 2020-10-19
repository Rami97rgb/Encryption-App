#include<iostream>
#include<stdlib.h>
#include<sstream>
#include<math.h>
#include<string.h>

using namespace std;
string s;
long int x, y, n, t, i, flag,c;
long int e[100], d[100], j;
string msg;
int premier(long int);
void cles();
long int cd(long int);
void crypter(long int x,long int y,long int c);
void decrypter(long int x,long int y,long int c);

main()
{
   cout<<"generate key or encrypt or decrypt (g/e/d) ";
   getline(cin,s);
   //generate a table of public and private keys to chose from
   if (s=="g")
   cles();
   //encrypt
   if (s=="e")
    {
   crypter(x,y,c);}
   //decrypt
   if (s=="d")
    {
   decrypter(x,y,c);}
}

int premier(long int pr)
{
   int i;
   j = sqrt(pr);
   for(i = 2; i <= j; i++)
   {
      if(pr % i == 0)
         return 0;
   }
   return 1;
 }

void cles()
{
    do
  {
      cout<<"enter two distinct prime numbers ";
      cin>>x>>y;
  }
  while((premier(x)==0)||(premier(y)==0)||(x==y));
     n = x * y;
   t = (x - 1) * (y - 1);
   int k;
   k = 0;
   for(i = 2; i < t; i++)
   {
      if(t % i == 0)
         continue;
      flag = premier(i);
      if(flag == 1 && i != x && i != y)
      {
         e[k] = i;
         flag = cd(e[k]);
         if(flag > 0)
         {
            d[k] = flag;
            k++;
         }
         if(k == 99)
         break;
      }
   }
   cout << "\npub key priv key\n";

   for(i = 0; i < j - 1; i++)
      cout << "\n" << e[i] << "\t" << d[i];
}

long int cd(long int a)
{
   long int k = 1;
   while(1)
   {
      k = k + t;
      if(k % a == 0)
         return(k/a);
   }
}

void crypter(long int x,long int y,long int c)
{
     cout << "message ";
     getline(cin,msg);
     cout<<"enter the two prime numbers and the public key ";
    cin>>x>>y>>c;
     cout<<endl;
     n=x*y;

   long int pt, ct, key = c, k, len;
   i = 0;
   len = msg.size();

   while(i != len)
   {
      if (msg[i]!=' ')
     {pt = msg[i];
      pt = pt - 128;
      k = 1;
      for(j = 0; j < key; j++)
      {
         k = k * pt;
         k = k % n;
      }
      ct= k + 128;
      msg[i] = ct;}
      i++;
   }
   msg[i] = -1;
   for(i=0; msg[i] != -1; i++)
      cout <<msg[i];
   cout<<endl;

}
void decrypter(long int x,long int y,long int c)
{
     cout << "message ";
   getline(cin,msg);
   cout<<"enter the two prime numbers and the private key ";
    cin>>x>>y>>c;
   cout<<endl;
   n=x*y;
   long int pt, ct, key = c, k;
   i = 0;

   while(i!=msg.size())
   {if (msg[i]!=' ')
      {ct=(msg[i]+256)%256;
      ct=ct-128;
      k = 1;
      for(j = 0; j < key; j++)
      {
         k = k * ct;
         k = k % n;
      }
      pt = k +128;

      msg[i] = pt;}
      i++;
   }
   msg[i] = -1;
   for(i = 0; msg[i] != -1; i++)
      cout << msg[i];

  cout << endl;
}
