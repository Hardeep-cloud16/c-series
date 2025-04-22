#include<iostream>
using namespace std;


int main()
{
    //kine log vote dene wale input liya gya 
int n;
cout<<"Enter number of voter : ";
cin>>n;


int votes[n];//dynamic array to store votes
int result[3] = {0}; //har candidate1,2,3 k  liye vote count store 



for (int  i = 0; i < n; i++)
{
    cout<<"Voter"<<i+1<<":";
    cin>>votes[i];

    if (votes[i] >= 1 && votes[i] <=3)
    {
        result[votes[i] - 1]++;
    }else{
        cout<<"Invalid vote! skipping..\n";
    }
    
}
//Har voter se votes liye ja rha hai(1,2,3)
//Agar input valid hai to result array me vote count update hata hai 
//Agar koi galat number dalta hai (jaise 5 ya 0 ) "invcalid vote"


for (int i = 0; i < 3; i++)
{
    cout<<"candidate "<<i+1<<" : "<<result[i]<<"votes\n";
}
//sabhi cadidate 3 ke toatal  votes yahan print kiye jayenge 


// assume candidate 1 is winner 
int maxvotes = result[0]; //candidate 1 ke votes ko max maan lo
int winner = 1;// candidate 1 ko winner maan lp

for (int  i = 1; i < 3; i++)//compare remaning candidate votes
{
    if (result[i] > maxvotes)  //Agar current candiate ke votes zyada h 
    {
        maxvotes = result[i];  //update maxvotes
        winner = i + 1  ;       //updates winner number
    }
    
}

cout<<"\n🎉Winner is Candidate "<<winner<<" With "<< maxvotes<<" votes!\n";

//finaly , jeetna wal candidate ka name aur unke votes count ko print kiya gya hai

}
