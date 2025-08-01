// step 1 Header File Include kerna 
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


// step 2 main () and Random seed set kerna 

int main()
{

    srand(time(0)); // Random seed


    // step 3 choice Array and Paly Again variable

    string choice[3] = {"Rock", "Paper", "Scissors"};

    char playAgain;

    // step 4 start of do while loop

    do
    {
        
        int computerChoice = rand() % 3 ; // 0,1,2

        // step 5

        int UserChoice;
        cout<<"================================="<<endl;
        cout<<"WellCome to Rock, Paper, Scissors Game\n";
        cout<<"================================="<<endl;
        cout<<"Choose opotion (0 = Rock, 1 = Paper, 2 = scissors): ";
        cin>>UserChoice;

        // step 6 input validation

        if (UserChoice < 0 || UserChoice > 2)
        {
            cout<<"Invalid choice! try again.\n";
            continue; // Restart the loop
            
        }

        // step 7 choice display 
        cout<<"You choice : "<< choice[UserChoice]<<endl;
        cout<<"Computer chose : "<<choice[computerChoice]<<endl;


        // step 8 dicide winner using game rules
        if (UserChoice == computerChoice)
        {
            cout<< "It's a tie!"<<endl;
        }
        else if ((UserChoice == 0 && computerChoice == 2) ||
                 (UserChoice == 1 && computerChoice == 0) ||
                 (UserChoice == 2 && computerChoice == 1))
        {
            cout<<"You Win!"<<endl;
        }
        else
        {
            cout<<"Computer wins!"<<endl;
        }
        
        
        cout<<"Play again ? (y/n) : ";
        cin>>playAgain;



    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout<<"Thanks For Playing! Bye."<<endl;
    return 0;
}
