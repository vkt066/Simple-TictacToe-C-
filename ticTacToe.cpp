#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int gameGuide();
void printBoard(const vector<vector<char>>& a);
void updateBoard(vector<vector<char>>& a,const char c,const char q);
void askForInput(vector<vector<char>>& a,int& k);
int winCheck(const vector<vector<char>>& a,const int draw=0);
int horizontalCheck(const vector<vector<char>>& a);
int verticalCheck(const vector<vector<char>>& a);
int diagonalCheck(const vector<vector<char>>& a);
int finalCheck(const vector<vector<char>>& a);
int reEnterCheck(const vector<vector<char>>& a,const char& k);
void MultiInput(vector<vector<char>>& a,const int& k);
int main()
{
	int n=3,k;
	char c;
	vector<vector<char>> b(n);
	while(1)
	{
	    k=0;
	    c='1';
	    if(gameGuide()) break;
	    for(int i{0};i<n;i++)
	    {
		    b[i]=vector<char>(n);
		    for(int j{0};j<n;j++)
		    {
			    b[i][j]=c;
			    c++;	
		    }
	    }
    
   
        printBoard(b);
        k++;
	    while(winCheck(b))
	    {
	        askForInput(b,k);
	        k++;
	        
	    
	    }
	    if(k%2!=0) cout<<"X is the winner"<<'\n';
	    else cout<<"0 is the winner"<<'\n';
	}
}
int gameGuide()
{
    string status;
    cout<<setw(20)<<"THE TIC TAC TOE GAME"<<'\n'<<'\n';
    cout<<"Hey there how are you"<<"\n";
    cout<<"C++ brings you the TicTacToe game"<<'\n';
    cout<<"Type play to play the game:\n";
    
    while(1)
    {
        cin>>status;
        
        if(status=="play")
        {
            cout<<"Press Ctrl+c to stop the game at any time";
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
void printBoard(const vector<vector<char>>& a)
{
    cout<<"-----------------------------"<<'\n';
	for(int i{0};i<a.size();i++)
	{
		for(int j{0};j<a[i].size();j++)
			cout<<"|  "<<a[i][j]<<setw(4)<<"|";
		cout<<'\n';
		cout<<"-----------------------------"<<'\n';
	}
	
}
void updateBoard(vector<vector<char>>& a,const char c,const char q)
{
    for(int i{0};i<a.size();i++)
	{
	    
		for(int j{0};j<a[i].size();j++)
			if(c==a[i][j])
			    a[i][j]=q;
			    
		cout<<'\n';
	}
	printBoard(a);
	
}
void askForInput(vector<vector<char>>& a,int& k)
{
    char choice;
    int draw=finalCheck(a);
    if(draw)
    {
       winCheck(a,draw);
        cout<<"Press crtl+c to exit"<<'\n';
        
    } 
    
    if(k%2==0) 
    {
        cout<<"X's choice"<<'\n';        
        cin>>choice;
        if(reEnterCheck(a,choice)) updateBoard(a,choice,'x');
        else MultiInput(a,k);
        
    }
    else
    {
        cout<<"O's choice"<<'\n';        
        cin>>choice;
        if(reEnterCheck(a,choice)) updateBoard(a,choice,'o');
        else MultiInput(a,k);
        
    }
    
}   
void MultiInput(vector<vector<char>>& a,const int& k)
{
    char c,q;
    
    while(1)
    {
       
        if(k%2==0) 
        {
            cout<<"X's choice"<<'\n'; 
            c='x';
            cin>>q;
            if(reEnterCheck(a,q)) break;
        }
        else
        {
            cout<<"O's choice"<<'\n';  
            c='o';
            cin>>q;
            if(reEnterCheck(a,q)) break;
        }
        
    }
    
    updateBoard(a,q,c);
}
int winCheck(const vector<vector<char>>& a,const int d)
{
    if(horizontalCheck(a)) return 0;
    if(verticalCheck(a)) return 0;
    if(diagonalCheck(a)) return 0;
    if(d)
    {
        cout<<"the game is draw"<<'\n';
        return 0;
    }
    return 1;
}
int horizontalCheck(const vector<vector<char>>& a)
{
    for(int i{0};i<a.size();i++)
	{
		if(a[i][0]==a[i][1] && a[i][1]==a[i][2]) return 1;
	}
	return 0;
}
int verticalCheck(const vector<vector<char>>& a)
{
     for(int i{0};i<a.size();i++)
	{
		if(a[0][i]==a[1][i] && a[1][i]==a[2][i]) return 1;
	}
	return 0;
}
int diagonalCheck(const vector<vector<char>>& a)
{
    
    
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[2][2]==a[0][0])
    {
        
            return 1;
    }
    if(a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[2][0]==a[0][2])
    {
        
            return 1;
    }
    return 0;
   
}
int reEnterCheck(const vector<vector<char>>& a,const char& k)
{
    int i,j;
    for(i=0;i<a.size();i++)
	{
		for( j=0;j<a[i].size();j++)
		{
		    if(a[i][j]==k)
		    {
                
		        return 1;
		    }
	    }
	} 
	return 0;
}
int finalCheck(const vector<vector<char>>& a)
{
    int i,j,k=0;
    for(i=0;i<a.size();i++)
	{
		for( j=0;j<a[i].size();j++)
		{
		    if(a[i][j]=='x') k++;
		    if(a[i][j]=='o') k++;
	    }
	} 
	if(k==9) return 1;
	else return 0;
}
