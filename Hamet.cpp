#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

string History[100]; //this array stores chat history
int c=0,k2=0;// this are array index counters.

//function declaration
void history(int num[],int);
string encripter(string);
string decripter(string);

int main(){

int num,num_store[100];// this array store choice numbers..
string str, result;
bool isdone=false;
cout<<"                   This program(Hamet) will encrypt and decrypt any message \n";
cout<<"                 ______________________________________________________";

label1:
cout<<"\nPress"<<endl;
cout<<"1. For Encryption  \n";
cout<<"2. For Decryption  \n";
cout<<"3. To see Chat history\n";
cout<<"4. EXit"<<endl;
cin>>num;

// store if only the user choose to encript or decrypt not store when the user choose to see chat
if(num==1||num==2){
num_store[k2]=num; k2++;}

while(!isdone){

switch(num){

case 1:
    system("cls");      // clear the screen
    cout<<" Enter message you want to encrypt \n";
   cin.ignore();
    getline(cin,str);
   result=encripter(str);       // encrypted result
   History[c]=str; c++; //the normal string the user entered stored in history.
   system("cls");
   cout<<"Encrypted message is: "<<result<<endl;        // show encrypted message
   cout<<"\n_________________________________";
   goto label1;

break;

case 2:
    system("cls");
    cout<<"Enter message you want to decrypt \n";
cin.ignore();
    getline(cin,str);
   result=decripter(str);
   History[c]=result;c++;       //put the decrypted result in history.
   system("cls");
cout<<"Decrypted message is: "<<result<<endl;
 cout<<"\n_________________________________";
 goto label1;
break;
case 3:
    history(num_store,k2);
    goto label1;
break;
case 4:
    isdone=true;
break;
default:
    cin.clear();                //clears the error flag on cin for example if the user entered some string
  cin.ignore(10000,'\n');
system("cls");
    cout<<"you have entered wrong choice!! "<<endl;
   // system("cls");
goto label1;
}
}
system("cls");
cout<<"\n ************************************************"<<endl;
cout<<" Thank You For Using  Hamet. Good Bye!!!";
cout<<"\n ************************************************\n\n"<<endl;


return 0;
}

// This function is used to encrypt a message
string encripter(string str){
char temp;
int k=str.length()-1;
//swap the message
for(int i=0; i<str.length()/2 ;i++)
{
    temp= str[i];
    str[i]=str[k];
    str[k]=temp;
    k--;
}
// Add +2 for even and +3 for odd position characters
for(int i=0; i<str.length();i++)

{
    if (i%2==0)
        str[i]=str[i]+2;
    else
        str[i]=str[i]+3;

}

return str;

}

// this function decrypt the encrypted message.
string decripter(string str){

char temp;
int k=str.length()-1;

for(int i=0; i<str.length();i++)

{
    if (i%2==0)
        str[i]=str[i]- 2;
    else
        str[i]=str[i]-3;

}


for(int i=0; i<str.length()/2 ;i++)
{
    temp= str[i];
    str[i]=str[k];
    str[k]=temp;
    k--;
}

return str;
}

// this function show chat history using indentation.
void history(int num_store[],int k2)
{
    system("cls");
    cout<<"\n                          Chat History \n";
    cout<<"__________________________________________________________\n";
    for(int i= 0; i < k2; i++){
        if(num_store[i]==1){
            cout<<History[i]<<endl;
            }
         if(num_store[i]==2){
            cout<<"   "<<History[i]<<endl;
            }
    }
cout<<"__________________________________________________________\n";
}

