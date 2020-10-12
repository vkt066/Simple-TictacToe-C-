#include<cstdio>
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int gameGuide();
void printBoard(const vector<vector<char>>& a);
void updateBoard(vector<vector<char>>& a,const char c,const char q);
int askForInput(vector<vector<char>>& a,int& k);
int winCheck(const vector<vector<char>>& a,const int draw=0);
int horizontalCheck(const vector<vector<char>>& a);
int verticalCheck(const vector<vector<char>>& a);
int diagonalCheck(const vector<vector<char>>& a);
int finalCheck(const vector<vector<char>>& a);
int reEnterCheck(const vector<vector<char>>& a,const char& k);

int main()
{
	int n=3,k,t;
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
	    	t=askForInput(b,k);
	        if(t) break; 
	        k++;
	        
	    
	    }
	    if(t){
	    	printf("STARTING NEW GAME:::.........\n\n\n\n\n");
	    	continue;
		} 
	    if(k%2!=0) printf("X is the winner\n\n\n");
	    else printf("0 is the winner\n\n\n\n");
	    printf("STARTING NEW GAME:::.........\n\n\n\n\n");
	}
}
int gameGuide()
{
    int t;
    printf("THE TIC TAC TOE GAME\n\n");
    printf("Hey there how are yo\n");
    printf("C++ brings you the TicTacToe game\n");
    printf("Enter 1 to play the game:\n");
    printf("Enter 0 to Exit\n ");
	scanf("%d",&t);
	if(t) return 0;
	else return 1;
}
void printBoard(const vector<vector<char>>& a)
{
    printf("-----------------------------\n");
	for(int i{0};i<a.size();i++)
	{
		for(int j{0};j<a[i].size();j++)
			printf("|  %4c",a[i][j]);
			printf("|   ");
		printf("\n");
		printf("-----------------------------\n");
	}
	
}
void updateBoard(vector<vector<char>>& a,const char c,const char q)
{
    for(int i{0};i<a.size();i++)
	{
	    
		for(int j{0};j<a[i].size();j++){
		
			if(c==a[i][j])
			    a[i][j]=q;
		}
			
	}
	printBoard(a);
	
}
int  askForInput(vector<vector<char>>& a,int& k)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    char choice;
    int draw=finalCheck(a);
    if(draw)
    {
       winCheck(a,draw);
    	return 1;
    } 
    
    if(k%2==0) 
    {
       	printf("X's choice\n"); 
	  
        cin>>choice;
       
        if(reEnterCheck(a,choice)){
        	updateBoard(a,choice,'x');
		} 
        else{
        	printf("Might have Enter the same place which was enter before\nRENTER THE PLACE\n\n");
        	askForInput(a,k);
		} 
        
    }
    else
    {
       	printf("O's choice\n");
	    
        cin>>choice;
     
        if(reEnterCheck(a,choice)){
        	updateBoard(a,choice,'o');
		} 
        else{
        	printf("Might have Enter the same place which was enter before\nRENTER THE PLACE\n\n");
        	askForInput(a,k);
		} 
        
    }
    
}   

    
int winCheck(const vector<vector<char>>& a,const int d)
{
    if(horizontalCheck(a)) return 0;
    if(verticalCheck(a)) return 0;
    if(diagonalCheck(a)) return 0;
    if(d)
    {
        printf("THE GAME IS DRAW------\nBOTH HAVE WON\n\n\n\n\n");
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
