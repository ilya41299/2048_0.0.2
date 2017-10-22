#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	cout << "To start the game, fill the 4x4 game board." << endl; 
	cout << "Use numbers that are a multiple of 2, 4..." << endl; 
	cout << "Numbers are separated by a space.To enter a new line, use enter"<<endl;
    int matrix[4][4], i=0, j=0, k=0;
    char op;
    for(i=0; i<4; ++i){
        for(j=0; j<4; ++j){
            cin>>matrix[i][j];
        }
    }
    cout<<endl<<"To shift the field, use the following keys: 'h' to the left, 'l' to the right, 'k' up and 'j' down. Have a good game!"<<endl;
    for(i=0; i<4; ++i){
        for(j=0; j<4; ++j){
            if(matrix[i][j]==0){
                cout<<"* ";
            }
            else{
                cout<<matrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    srand(time(NULL));
    int sum=0;
    while(true){
        cin>>op;
        bool p=0;
        for(i=0; i<3; ++i){
            for(j=0; j<3; ++j){
                if(matrix[i][j]==matrix[i+1][j]||matrix[i][j]==matrix[i][j+1]||matrix[i][j]==0){
                    p=1;
                    break;
                }
            }
            if(p){break;}
        }
        switch(op){
            case 'j':
            {
            int z=0;
            for(j=0; j<4; ++j){
                for(i=3; i>=0; --i){
                    if(matrix[i][j]!=0){
                        for(k=i-1; k>=0; --k){
                            if(matrix[k][j]!=0){
                                if(matrix[k][j]==matrix[i][j]){
                                    matrix[i][j]=matrix[i][j]+matrix[k][j];
                                    matrix[k][j]=0;
                                    sum+=matrix[i][j];
                                    z+=1;
                                }
                                break;
                            }
                        }
                        while(matrix[i+1][j]==0){
                            if(i<3){
                                matrix[i+1][j]=matrix[i][j];
                                matrix[i][j]=0;
                                i=i+1;
                                z+=1;
                            }
                            else{break;}
                        }
                        i=k+1;
                    }
                }
            }
            if(z==0){
                cout<<"Enter another key"<<endl;
                p=0;
            }
            break;
            }
            case 'k':
            {
            int z=0;
            for(j=0; j<4; ++j){
                for(i=0; i<4; ++i){
                    if(matrix[i][j]!=0){
                        for(k=i+1; k<4; ++k){
                            if(matrix[k][j]!=0){
                                if(matrix[k][j]==matrix[i][j]){
                                    matrix[i][j]=matrix[i][j]+matrix[k][j];
                                    matrix[k][j]=0;
                                    sum+=matrix[i][j];
                                    z+=1;
                                }
                                break;
                            }
                        }
                        while(matrix[i-1][j]==0){
                            if(i>0){
                                matrix[i-1][j]=matrix[i][j];
                                matrix[i][j]=0;
                                i=i-1;
                                z+=1;
                            }
                            else{break;}
                        }
                        i=k-1;
                    }
                }
            }
            if(z==0){
                cout<<"Enter another key"<<endl;
                p=0;
            }
            break;
            }
            case 'h':
            {
            int z=0;
            for(i=0; i<4; ++i){
                for(j=0; j<4; ++j){
                    if(matrix[i][j]!=0){
                        for(k=j+1; k<4; ++k){
                            if(matrix[i][k]!=0){
                                if(matrix[i][k]==matrix[i][j]){
                                    matrix[i][j]=matrix[i][j]+matrix[i][k];
                                    matrix[i][k]=0;
                                    sum+=matrix[i][j];
                                    z+=1;
                                }
                                break;
                            }
                        }
                        while(matrix[i][j-1]==0){
                            if(j>0){
                                matrix[i][j-1]=matrix[i][j];
                                matrix[i][j]=0;
                                j=j-1;
                                z+=1;
                            }
                            else{break;}
                        }
                        j=k-1;
                    }
                }
            }
            if(z==0){
                cout<<"Enter another key"<<endl;
                p=0;
            }
            break;
            }
            case 'l':
            {
            int z=0;
            for(i=0; i<4; ++i){
                for(j=3; j>=0; --j){
                    if(matrix[i][j]!=0){
                        for(k=j-1; k>=0; --k){
                            if(matrix[i][k]!=0){
                                if(matrix[i][k]==matrix[i][j]){
                                    matrix[i][j]=matrix[i][j]+matrix[i][k];
                                    matrix[i][k]=0;
                                    sum+=matrix[i][j];
                                    z+=1;
                                }
                                break;
                            }
                        }
                        while(matrix[i][j+1]==0){
                            if(j<3){
                                matrix[i][j+1]=matrix[i][j];
                                matrix[i][j]=0;
                                j=j+1;
                                z+=1;
                            }
                            else{break;}
                        }
                        j=k+1;
                    }
                }
            }
            if(z==0){
                cout<<"Enter another key"<<endl;
                p=0;
            }
            break;
            }
            case 'q':
            {
            system("pause");
            cout<<"game over, your score : "<<sum<<endl;
			return -1;
            }
        }
        if(p){
            while(1){
                i=rand()%4;
                j=rand()%4;
                if(matrix[i][j]==0){
                    if(rand()%11<10){
                        matrix[i][j]=2;
                    }
                    else{
                        matrix[i][j]=4;
                    }
                    break;
                }
            }
            for(i=0; i<4; ++i){
                for(j=0; j<4; ++j){
                    if(matrix[i][j]==0){
                        cout<<"* ";
                    }
                    else{
                        cout<<matrix[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
        }
    }
    cout<<"game over, your score : "<<sum<<endl;
    return 0;
}
