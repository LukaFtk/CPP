
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int main() {
    int a; int round;
    int PScore = 0, CScore = 0, Ties = 0;
    string Name;
    
    cout<<"Enter Your Name: "; cin>>Name;
    cout<<endl;
    cout<<"Hello "<<Name<<"! Welcome to Rock, Paper, Scissors Game!"<<endl; cout<<endl;
    cout<<Name<<", How Many Rounds Do You Want To Play? : "; cin>>round;
    system("cls");
    
    for(int R = 1; R<=round; R++){
    	cout<<"Round: "<<R<<"/"<<round<<endl;
        cout<<endl;
    	
    
    
	    cout<<"Choose One Of The Options Below!"<<endl; cout<<endl;
	    cout<<"Choose '1' For Rock."<<endl;
	    cout<<"Choose '2' For Paper."<<endl;
	    cout<<"Choose '3' For Scissors."<<endl;
	    cin>>a;
	
	    cout<<endl;
	    srand((unsigned) time(NULL));
	
	    int b = rand() % 3;
		system("cls");
		
		if((a==1) && (b==0)){
			cout<<"You Choosed Rock."<<endl;
			cout<<endl;
			cout<<"Computer Choosed Rock."<<endl;
			cout<<endl;
			cout<<"It's A Tie!";
			Ties++; 
		}

		else if((a==1) && (b==1)){
			cout<<"You Choosed Rock."<<endl;
			cout<<endl;	
			cout<<"Computer Choosed Paper"<<endl;
			cout<<endl;
			cout<<"Computer Won The Game!"; 
			CScore++; 
		}
		
		else if((a==1) && (b==2)){
			cout<<"You Choosed Rock."<<endl;
			cout<<endl;	
			cout<<"Computer Choosed Scissors"<<endl;
			cout<<endl;
			cout<<"You Won The Game!";
			PScore++; 
		}
		
		else if ((a==2) && (b==0)){
			cout<<"You Choosed Paper"<<endl;
			cout<<endl;
			cout<<"Computer Choosed Rock"<<endl;
			cout<<endl;
			cout<<"You Won The Game!";
			PScore++; 
		}
		
		else if((a==2) && (b==1)){
			cout<<"You Choosed Paper"<<endl;
			cout<<endl;
			cout<<"Computer Choosed Paper"<<endl;
			cout<<endl;
			cout<<"It's A Tie!";
			Ties++; 
		}
		
		else if((a==2) && (b==2)){
			cout<<"You Choosed Paper"<<endl;
			cout<<endl;
			cout<<"Computer Choosed Scissors"<<endl;
			cout<<endl;
			cout<<"Computer Won The Game!"; 
			CScore++; 
		}
		
		else if((a==3) && (b==0)){
			cout<<"You Choosed Scissors"<<endl;
			cout<<endl;
			cout<<"Computer Choosed Rock."<<endl;
			cout<<endl;
			cout<<"Computer Won The Game!"; 
			CScore++; 
		}
		
		else if((a==3) && (b==1)){
			cout<<"You Choosed Scissors"<<endl;
			cout<<endl;
			cout<<"Computer Choosed Paper"<<endl;
			cout<<endl;
			cout<<"You Won The Game!"; 
			PScore++; 
		}
		
		else if((a==3) && (b==2)){
			cout<<"You Choosed Scissors"<<endl;
			cout<<endl;
			cout<<"Computer Choosed Scissors"<<endl;
			cout<<endl;
			cout<<"It's A Tie!";
			Ties++; 
		}
		
		else
			cout<<"Wrong Number!";
		
		cout<<endl; cout<<endl;
		cout<<Name<<" Score: "<<PScore<<endl;
	    cout<<"Computer Score: "<<CScore<<endl;
	    cout<<"Number Of Ties: "<<Ties<<endl;
	    cout<<endl;
	    
		    
	}
}
