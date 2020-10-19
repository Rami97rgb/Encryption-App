
#include <string>
#include <iostream>
using namespace std;

void crypter(string msg,string cle)
{ string ch="";char s;
  for (int i=0,k=-1; i<msg.size(); ++i)
    {
    int c=(int)msg[i];
    s=((c<'a')||(c>'z')) ? c : 'a'+(c-'a'+cle[(++k)%cle.size()]-'a')%26;
    ch=ch+s;
  }
  cout<<ch;
}

void decrypter(string msg,string cle)
{ string ch="";char s;
  for (int i=0,k=-1; i<msg.size(); ++i)
    {
    int c=(int)msg[i];
    s=(((c<'a')||(c>'z')) ? c : 'a'+(c-cle[(++k)%cle.size()]+26)%26);
    ch+=s;
  }
  cout<<ch;
}

  main() {
  string tache,cle,msg;
    cout<<"message ";
    //read message
    getline(cin,msg);
    cout<<"encrypt or decrypt(e/d) ";
    //read task
    cin>>tache;
    cout<<"key ";
    //read key
    cin>>cle;
    if (tache=="e")
        crypter(msg,cle);
    if (tache=="d")
        decrypter(msg,cle);

}
