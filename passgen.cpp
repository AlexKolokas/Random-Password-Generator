

#include <iostream>
#include <string>
#include<time.h>
#include<vector>
#include <algorithm>
#include <random>

using namespace std;

int AskMin(); //ask for the min length of the password
int AskMax(); // ask for the max length of the password
int returnPasssize(int, int ); //return the random password length
vector<string> AskWhatCodeStrings(); //ask for what your password want to have(e.x. lower,upper and sympols
vector<string> PasswordFun(string,string,string,string );   //function to call if the pass need for categories
vector<string>PasswordFun(string,int  );
vector<string> PasswordFun(string,string, int );
vector<string> PasswordFun(string,string,string, int );
vector<string> PasswordFun(string,string,string,string, int );

int main()
{
    vector<string> veccheck;
    vector<string> password4;
    int minnumber,maxnumber,sizeofpass,rangeofpass;
       char doagain;
    do
    {

        srand(time(0));

        string letterslower,lettersupper,numbers,symbols,genpassword;
        letterslower="qwertyuiopasdfghjklzxcvbnm";
        lettersupper="QWERTYUIOPASDFGHJKLZXCVBNM";
        numbers="0123456789";
        symbols="!@#$%^&*-";

        do
        {
            minnumber=AskMin();// asking for the minimum numbers of characters in password
            maxnumber=AskMax();// asking for the max numbers of characters in password
            if(minnumber>maxnumber)//check if min >max to print message
                cout<<"your minimum number is bigger than the maximum. Try again "<<endl;
        }
        while(minnumber>maxnumber );  //if min>max loop to try again

        rangeofpass=(maxnumber-minnumber )+1; //used for the rand() to find the "random" length of the password


        sizeofpass=returnPasssize(rangeofpass,minnumber);//the size of the password
        //cout<<endl;
        //cout<<"random password length is : "<<sizeofpass<<endl;
        cout<<endl;
        veccheck = AskWhatCodeStrings(); // the vector toy check of the choices for what you need for the code
        switch(veccheck.size())
        {
        case 1:
            if(veccheck[0]=="l")
            {

                //cout<<"your password will have only lower letters"<<endl;
                password4=PasswordFun(letterslower,sizeofpass);
            }
            else if(veccheck[0]=="u")
            {
                //cout<<"your password will have only upper letters"<<endl;
                password4=PasswordFun(lettersupper,sizeofpass);
            }
            else if(veccheck[0]=="n")
            {
                //cout<<"your password will have only numbers"<<endl;
                password4=PasswordFun(numbers,sizeofpass);
            }
            else if(veccheck[0]=="s")
            {
                //cout<<"your password will have only symbols"<<endl;
                password4=PasswordFun(symbols,sizeofpass);
            }
            break;

        case 2:
            if(veccheck[0]=="l" &&veccheck[1]=="u" )
            {

                //cout<<"your password will have lower and upper letters "<<endl;
                password4=PasswordFun(letterslower,lettersupper,sizeofpass);

            }
            else if(veccheck[0]=="l" &&veccheck[1]=="n")
            {
                //cout<<"your password will have lower letters and numbers"<<endl;
                password4=PasswordFun(letterslower,numbers,sizeofpass);
            }
            else if(veccheck[0]=="l" &&veccheck[1]=="s")
            {
                //cout<<"your password will have lower letters and symbols"<<endl;
                password4=PasswordFun(letterslower,symbols,sizeofpass);
            }
            else if(veccheck[0]=="u" &&veccheck[1]=="n")
            {
                //cout<<"your password will have upper letters and numbers"<<endl;
                password4=PasswordFun(lettersupper,numbers,sizeofpass);
            }
            else if(veccheck[0]=="u" &&veccheck[1]=="s")
            {
                //cout<<"your password will have upper letters and symbols"<<endl;
                password4=PasswordFun(lettersupper,symbols,sizeofpass);
            }
            else if(veccheck[0]=="n" &&veccheck[1]=="s")
            {
                //cout<<"your password will have  numbers and symbols"<<endl;
                password4=PasswordFun(numbers,symbols,sizeofpass);
            }
            break;
        case 3:
            cout<<"your password will include three categories. "<<endl;
            if(veccheck[0]=="l" && veccheck[1]=="u" && veccheck[2]=="n"  )
            {

                //cout<<"your password will have lower,upper letters and numbers"<<endl;

                password4=PasswordFun(letterslower,lettersupper,numbers,sizeofpass);
            }
            else if(veccheck[0]=="l"&& veccheck[1]=="u" && veccheck[2]=="s")
            {
               // cout<<"your password will have lower,upper letters and symbols "<<endl;
                password4=PasswordFun(letterslower,lettersupper,symbols,sizeofpass);
            }
            else if(veccheck[0]=="l"&& veccheck[1]=="n" && veccheck[2]=="s")
            {
               // cout<<"your password will have lower letters,numbers and symbols"<<endl;
                password4=PasswordFun(letterslower,numbers,symbols,sizeofpass);
            }
            else if(veccheck[0]=="u"&& veccheck[1]=="n" && veccheck[2]=="s")
            {
                //cout<<"your password will have upper letters, numbers and symbols"<<endl;
                password4=PasswordFun(lettersupper,numbers,symbols,sizeofpass);
            }
            break;

        case 4:
            //cout<<"your password will include lower letters,upper letters,numbers and symbols. "<<endl;
            password4=PasswordFun(letterslower,lettersupper,numbers,symbols,sizeofpass);
            break;
        }
        cout<<endl;
        cout<<"YOUR RANDOM PASSWORD IS:";
        for (vector<string>::const_iterator i = password4.begin(); i != password4.end(); ++i) //print the vector
            cout <<*i;
        cout<<endl;
        cout<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"you want new password? (Y/N) : ";
        cin>>doagain;
    }
    while(doagain=='y' || doagain== 'Y' );   // stop asking for password when max=0 (used just for the testing)
}
//------------------END OF MAIN-----------------------

//-----------------------FUNCTIONS----------------------
vector<string> PasswordFun(string category,string category2,string category3,string category4, int passsize)
{
    int firstcategnum,leftover,thesi,secondcategnum,thirdcategnum,leftover2,leftover3;
    string letter;
    vector<string> password;
firstcategnum= rand()%(passsize-3) + 1; //digits of the first category
    leftover=passsize-firstcategnum;
    secondcategnum=rand()%(leftover-2) + 1;//digits for the second category
    leftover2=leftover-secondcategnum;
    thirdcategnum=rand()%(leftover2-1)+1;
    leftover3=leftover2-thirdcategnum;
    for(int i=1; i<=firstcategnum; i++) //password only with the first category
    {
        thesi=rand()%(category.length()) + 1 ;
        letter=category[thesi];
        password.push_back(letter);
    }

    for(int i=1; i<=secondcategnum; i++)//password with first and second category
    {
        thesi=rand()%(category2.length()) + 1 ;
        letter=category2[thesi];
        password.push_back(letter);
    }
     for(int i=1; i<=thirdcategnum; i++)//password with first and second category
    {
        thesi=rand()%(category3.length()) + 1 ;
        letter=category3[thesi];
        password.push_back(letter);
    }
    for(int i=1; i<=leftover3; i++)//password with first and second category
    {
        thesi=rand()%(category4.length()) + 1 ;
        letter=category4[thesi];
        password.push_back(letter);
    }
    //--------shuffle the already password-------
    random_device rd;
    mt19937 g(rd());
    shuffle(password.begin(), password.end(), g);

    return password;
}
vector<string> PasswordFun(string category,string category2,string category3, int passsize) //function for 3 categories
{
    bool errorflag=false;
    int firstcategnum,leftover,leftover2,thesi,secondcategnum;
    string letter,error="";
    vector<string> password;

    firstcategnum= rand()%(passsize-2) + 1; //if the size of code is 6 the first category will get 1 to 4 digits
    leftover=passsize-firstcategnum;//the digits that are for the second category
    secondcategnum=rand()%(leftover-1) + 1; // the digits for the second category
    leftover2=leftover-secondcategnum;


    for(int i=1; i<=firstcategnum; i++) //password only with the first category
    {
        thesi=rand()%(category.length()) + 1 ;
        letter=category[thesi];
        password.push_back(letter);
    }

    for(int i=1; i<=secondcategnum; i++)//password with first and second category
    {
        thesi=rand()%(category2.length()) + 1 ;
        letter=category2[thesi];
        password.push_back(letter);
    }
    for(int i=1; i<=leftover2; i++)//password with first and second category
    {
        thesi=rand()%(category3.length()) + 1 ;
        letter=category3[thesi];
        password.push_back(letter);
    }
//--------shuffle the already password-------
    random_device rd;
    mt19937 g(rd());
    shuffle(password.begin(), password.end(), g);
//--------------------------------



    return password;
}



vector<string> PasswordFun(string category,string category2, int passsize) //function for 2 categories
{
    int firstcategnum,leftover,thesi;
    string letter;
    vector<string> password;
    firstcategnum= rand()%(passsize-1) + 1; //if the size of code is 6 the first category will get 1 to 5 digits

    leftover=passsize-firstcategnum;//the digits that are for the second category

    for(int i=1; i<=firstcategnum; i++) //password only with the first category
    {
        thesi=rand()%(category.length()) + 1 ;
        letter=category[thesi];
        password.push_back(letter);
    }

    for(int i=1; i<=leftover; i++)//password with first and second category
    {
        thesi=rand()%(category2.length()) + 1 ;
        letter=category2[thesi];
        password.push_back(letter);
    }
//--------shuffle the already password-------
    random_device rd;
    mt19937 g(rd());
    shuffle(password.begin(), password.end(), g);
//--------------------------------
    return password;
}

vector<string> PasswordFun(string category,int passsize) //the function if the password has only one category
{
    int thesi;
    string letter;
    vector<string> password;
    for(int i=1; i<=passsize; i++)
    {
        thesi=rand()%(category.length()+1  - 1) + 1 ;
        letter=category[thesi];

        password.push_back(letter);
    }


    return password;
}



vector<string> AskWhatCodeStrings() //vector for choices if luns that means you want lower letters,upper,number,symbols
{
    vector<string> result;
    char answer;
    cout<<"You want your code to have Upper,Lower letters, numbers and symbols?\nAnswer with Yes(y) OR No(N) on the questions;"<<endl;
    cout<<endl;
    cout<<"1: You want Lower Letters ? (Y/N) ";
    cin >> answer;
    if(answer=='Y' || answer=='y')
        result.push_back("l");
    //lower letters // choice=choice+1;

    cout<<"2: You want Upper Letters ? (Y/N) ";
    cin >> answer;
    if(answer=='Y' || answer=='y')
        result.push_back("u");// choice=choice+2;

    cout<<"3: You Want  Numbers ? (Y/N) ";
    cin >> answer;
    if(answer=='Y' || answer=='y')
        result.push_back("n");// choice=choice+3;

    cout<<"4: You Want Symbols ? (Y/N) ";
    cin >> answer;
    if(answer=='Y' || answer=='y')
        result.push_back("s"); // choice=choice+4;

    return result; // if choice==10 then we need them all ....
}


int returnPasssize(int range,int minnum)
{
    int passzise;

    passzise= rand()%range+minnum;
    return passzise;
}


int AskMin()
{
    int minchar;


  cout<<"What is the minimum of characters that you want?  ";
    cin>>minchar;
if (minchar==isalpha(minchar)){
    cout<<"You gave letter instead of intiger try again!"<<endl;
    exit(0);
}

    return minchar;
}


int AskMax()
{
    int maxchar;
    cout<<"what is the maximum of the characters that you want?  ";
    cin>>maxchar;
    if (maxchar==isalpha(maxchar)){
    cout<<"You gave letter instead of intiger try again!"<<endl;
    exit(0);
}
    return maxchar;
}

