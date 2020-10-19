#include <iostream>
#include <string>
using namespace std;
char in[256],out[256];
int n;
string s;
main()
{
    cout<<"message ";
    cin.getline(in,sizeof(in));
    cout<<"encrypt or decrypt? (e/d) ";
    cin>>s;
    //encryption
    if(s=="e")
    {
        for(int i=0;in[i]!=NULL;i++)
        {
            if((in[i]<97)||(in[i]>122))
                out[i]=in[i];
            else
                out[i]=(in[i]-97+13)%26+97;
            cout<<out[i];
        }
    }
    //decryption
    if(s=="d")
    {
        for(int i=0;in[i]!=NULL;i++)
        {
            if((in[i]<97)||(in[i]>122))
                out[i]=in[i];
            else
                out[i]=(in[i]-97-(13%26)+26)%26+97;
            cout<<out[i];
        }
    }
}
