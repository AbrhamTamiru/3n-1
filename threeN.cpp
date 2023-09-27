// Name Abrham Tamiru
// Class (CECS 325-02)
// Project Name (Prog 6 – 3n+1(integer))
// Due Date (4/18/2023)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct nums
{
    int steps=0;
    int evens=0;
    int max=0;
    int odds=0;
    int last_n=0;
};

void threeN(int n, nums& value )
{
    cout<<"->"<<"("<<n<<")";
    if(n<=0)
    {
        throw value.last_n;
    }
        
    else if (n==1)
    {
        return;
    }  
    else if (n%2==0)
    {
        if(value.max<n)
        {
            value.max=n;
        }
        value.steps+=1; 
        value.evens+=1; 
        threeN(n/2, value);  
    }

    else
    {
        if(value.max<n)
        {
            value.max=n;
        }
        value.steps+=1;
        value.odds+=1;
        value.last_n=n;
        threeN(3*n+1,value);
    }
}

int main(int argc, char* argv[])
{
    if(argc==1)
    {
        int n;
        cout<<"enter a numbe: ";
        cin>>n;
        cout<<"solving 3n+1 - starting value : "<<n<<endl;
        nums value;
        try
        {
            threeN(n,value);
            cout<<"\nstart: "<<n<<endl;
            cout<<"steps: "<<value.steps<<endl;
            cout<<"max: "<<value.max;
            cout<<"\nevens: "<<value.evens;
            cout<<"\nodds: "<<value.odds<<endl;
            cout<<endl;
        }
        catch(int last_n)
        {
            cout<<"\noverflow ditected for n: "<<n<<endl;
            cout<<"3n+1:"<<3*last_n+1<<endl;
            cout<<"some thing wrong"<<endl;
            cout<<"overflow"<<endl;
            cout<<endl;
        }
    }
    else
    {
        for (int i=1;i<argc;i++)
        {
            int n = stoi(argv[i]);
            nums value;
            cout<<"solving 3n+1 - starting value : "<<n<<endl;
            try
            {
                
                threeN(n,value);
                cout<<"\nstart: "<<n<<endl;
                cout<<"steps: "<<value.steps<<endl;
                cout<<"max: "<<value.max;
                cout<<"\nevens: "<<value.evens;
                cout<<"\nodds: "<<value.odds<<endl;
                cout<<endl;

            }
            catch(int last_n)
            {
                cout<<"\noverflow ditected for n: "<<n<<endl;
                cout<<"3n+1:"<<3*last_n+1<<endl;
                cout<<"some thing wrong"<<endl;
                cout<<"overflow"<<endl;
                cout<<endl;
            }
        }
        
    }

    return 0;
}

