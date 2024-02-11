#include<iostream>
#include<windows.h>
using namespace std;

char arr[3][3]= {'1','2','3','4','5','6','7','8','9'};
char player ='x';
char position;
string a,b;

//****************************

void print()
{
    system("cls");

    cout<<"\n"<<a<<" is X\n"<<b<<" is O ";
    cout<<"\n\n";

    cout<<"----------------\n";
    for(int i=0 ; i<3 ; i++)
    {
        cout<<"|";
        for(int j=0 ; j<3 ; j++)
        {
            cout<<"  "<<arr[i][j]<<" ";
            cout<<"|";
        }
        cout<<endl<<"----------------\n";
    }
}

//****************************
void name()
{
    cout<<"please enter your name of the first player: ";
    cin>>a;
    cout<<"\nplease enter the name of the second player: ";
    cin>>b;
}

//****************************

void change()
{

    cout<<"\nenter the position "<<player<<"\n";
    cin>>position;
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(arr [i][j]==position)
                arr [i][j]=player;
        }
    }
    if (player=='x')
        player=('o');
    else
        player='x';
}

//*************************

char win()
{
    char x = 'x', o='o';
    int counterx=0, countero=0, counter=0;
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(arr[i][j]=='x')

                counterx++;

            else if(arr[i][j]=='o')

                countero++;

            if(counterx==3)
                return x;
            else if(countero==3)
                return o;
        }
        counterx=0;
        countero=0;
    }

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(arr[j][i]=='x')
                counterx++;
            else if(arr[j][i]=='o')
                countero++;
            if(counterx==3)
                return x;
            else if(countero==3)
                return o;
        }
        counterx=0;
        countero=0;
    }

    if(arr[0][0]=='x' && arr[1][1]=='x' && arr[2][2]=='x')
        return 'x';
    else if(arr[0][0]=='o' && arr[1][1]=='o' && arr[2][2]=='o')
        return 'o';
    else if (arr[0][2]=='x' && arr[1][1]=='x' && arr[2][0]=='x')
        return 'x';
    else if(arr[0][2]=='o' && arr[1][1]=='o' && arr[2][0]=='o')
        return 'o';
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(arr[i][j] !='x' && arr[i][j]!='o')
                counter++;
        }
    }
    if(counter == 0)
        return 'y';
    return '*';
}
//****************************
void who()
{
    if(win()=='x')
        cout<<"\ncongratulation the winner is  "<<a<<endl;
    if(win()=='o')
        cout<<"\ncongratulation the winner is  "<<b<<endl;
    if(win()=='y')
        cout<<"\ndraw between two player "<<a<<" and "<<b<<endl;
}
//****************************

int main()
{
        name();
while(win()=='*')
{
        print();
        change();
        win();
}
   print();
   who();
    return 0;
}