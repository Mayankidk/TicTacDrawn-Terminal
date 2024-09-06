#include<iostream>
char place[9]={};
char r;
int n,i,a,b;
int check()
{
    for(i=0;i<7;i++)
    {
        if(i%3==0)
        {
            if((place[i]==place[i+1])&&(place[i]==place[i+2]))
            {
                return 1;
            }
        }
        if(i<3)
        {
            if((place[i]==place[i+3])&&(place[i]==place[i+6]))
            {
                return 1;
            }
        }
        if(i==0)
        {
            if((place[i]==place[i+4])&&(place[i]==place[i+8]))
            {
                return 1;
            }
        }
        if(i==2)
        {
            if((place[i]==place[i+2])&&(place[i]==place[i+4]))
            {
                return 1;
            }
        }
    }
    return 0;
}
void draw()
{
    system("cls");
    std::cout<<"========TicTacToe========"<<"\n";
    std::cout<<" _______________________ ";
    for(b=0;b<3;b++)
    {
        std::cout<<"\n|";
        for(a=0;a<3;a++)
        {
            if(place[a+3*b]=='X')
            {
                std::cout<<"       |";
            }
            else if(place[a+3*b]=='O')
            {
                std::cout<<"  ___  |";
            }
            else
            {
                std::cout<<"       |";
            }
        }
        std::cout<<"\n|";
        for(a=0;a<3;a++)
        {
            if(place[a+3*b]=='X')
            {
                std::cout<<"  \\\\/  |";
            }
            else if(place[a+3*b]=='O')
            {
                std::cout<<" /   \\ |";
            }
            else
            {
                std::cout<<"   "<<place[a+3*b]<<"   |";
            }
        }
        std::cout<<"\n|";
        for(a=0;a<3;a++)
        {
            if(place[a+3*b]=='X')
            {
                std::cout<<"__/\\\\__|";
            }
            else if(place[a+3*b]=='O')
            {
                std::cout<<"_\\___/_|";
            }
            else
            {
                std::cout<<"_______|";
            }
        }
    }
    std::cout<<"\n\n";

    /*std::cout<<"       |       |       "<<"\n";
    std::cout<<"   "<<place[0]<<"   |   "<<place[1]<<"   |   "<<place[2]<<"   "<<"\n";
    std::cout<<"_______|_______|_______"<<"\n";
    std::cout<<"       |       |       "<<"\n";
    std::cout<<"   "<<place[3]<<"   |   "<<place[4]<<"   |   "<<place[5]<<"   "<<"\n";
    std::cout<<"_______|_______|_______"<<"\n";
    std::cout<<"       |       |       "<<"\n";
    std::cout<<"   "<<place[6]<<"   |   "<<place[7]<<"   |   "<<place[8]<<"   "<<"\n";
    std::cout<<"       |       |       "<<"\n";
    std::cout<<"\n";*/

    /*std::cout<<"       |  ___  |       "<<"\n";
    std::cout<<"  \\\\/  | /   \\ |       "<<"\n";
    std::cout<<"__/\\\\__|_\\___/_|_______"<<"\n";
    std::cout<<"       |  ___  |       "<<"\n";
    std::cout<<"  \\\\/  | /   \\ |       "<<"\n";
    std::cout<<"__/\\\\__|_\\___/_|_______"<<"\n";
    std::cout<<"       |  ___  |       "<<"\n";
    std::cout<<"  \\\\/  | /   \\ |       "<<"\n";
    std::cout<<"__/\\\\__|_\\___/_|_______"<<"\n";*/

}
void print()
{
    for(n=0;n<9;n++)
    {
        std::cout<<"choose a number between 1 and 9\n";
        if(n%2==0)
        {
            std::cout<<"player 1(X) turn: ";
            do
            {
                std::cin>>i;
            } while ((place[i-1]=='X')||(place[i-1]=='O'));
            place[--i]='X';
        }
        else
        {
            std::cout<<"player 2(O) turn: ";
            do
            {
                std::cin>>i;
            } while ((place[i-1]=='X')||(place[i-1]=='O'));
            place[--i]='O';
        }
        draw();
        if(check())
        {
            std::cout<<"======== "<<place[i]<<" Wins. ========\n";
            n=9;
        }
        if(n==8)
        {
            std::cout<<"=========Draw.========="<<"\n";
        }
    }
}
int main()
{
    do{
        for(n=0,i=49;n<9;n++)
        {
            place[n]=i++;
        }
        draw();
        print();
        std::cout<<"press 'r' to restart: ";
        std::cin>>r;
    }while(r=='r');
    return 0;
}