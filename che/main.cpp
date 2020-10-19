#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
string t[]={"6","38","32","4","8","30","36","34","39","31","78","72","70","76","9","79","71","58","2","0","52","50","56","54","1","59"};
void crypter(string msg,string cle)
{
    string ch="",ch1="";
    for(int i=0;i<msg.size();i++)
    {
       if ((msg[i]<'a')||(msg[i]>'z'))
        ch=ch+msg[i];
       else
        ch=ch+t[int(msg[i])-97];
    }
    int j=0;
    for(int i=0;i<ch.size();i++)
    {
       if ((ch[i]<'0')||(ch[i]>'9'))
        ch1=ch1+ch[i];
       else
       {

        stringstream ss;
        ss<<(((ch[i]-'0')+(cle[j%cle.size()]-'0'))%10);
        ch1=ch1+ss.str();
        j=j+1;
      }
}
cout<<ch1;
}
void decrypter(string msg,string cle)
{
    string ch="",ch1="";int j=0;
    for(int i=0;i<msg.size();i++)
    {
       if ((msg[i]<'0')||(msg[i]>'9'))
        ch=ch+msg[i];
       else
       {

        stringstream ss;
        ss<<(((msg[i]-'0')-(cle[j%cle.size()]-'0')+10)%10);
        ch=ch+ss.str();
        j=j+1;
      }
    }
    string ch2="";
    for(int i=0;i<ch.size();i++)
    {
       if ((ch[i]<'0')||(ch[i]>'9'))
        ch1=ch1+ch[i];
       else
        for(j=0;j<26;j++)
       {
         if((ch[i]+ch2)==t[j])
         {
            ch1=ch1+char(j+97);
            break;
         }
         if((ch[i]+ch2+ch[i+1])==t[j])
         {
            i++;
            ch1=ch1+char(j+97);
            break;

         }

       }
    }

cout<<ch1;


}

main()
{


    string tache,cle,msg;
    cout<<"message ";
    //read message
    getline(cin,msg);
    cout<<"encrypt or decrypt (e/d) ";
    //read task
    cin>>tache;
    cout<<"key ";
    //read key
    cin>>cle;
    //encrypt
    if (tache=="e")
        crypter(msg,cle);
    //decrypt
    if (tache=="d")
        decrypter(msg,cle);





}
