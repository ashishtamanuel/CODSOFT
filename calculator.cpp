#include<iostream>
using namespace std ;

int main()
{
    float num_1, num_2, result;
    int opt;
    do
    {
        cout<<"1. Add\n";
        cout<<"2. Subtrat\n";
        cout<<"3. Multiply\n";
        cout<<"4. Divide\n";
        cout<<"Enter 5 to exit\n";
        cout<<"Enter Your Choice: ";
        cin>>opt;
        if(opt>=1 && opt<=4)
        {
            cout<<"\nEnter any two Numbers: ";
            cin>>num_1>>num_2;
        }
        switch(opt)
        {
            case 1:
                result = num_1+num_2;
                cout<<"\nResult = "<<result;
                break;
            case 2:
                result = num_1-num_2;
                cout<<"\nResult = "<<result;
                break;
            case 3:
                result = num_1*num_2;
                cout<<"\nResult = "<<result;
                break;
            case 4:
                result = num_1/num_2;
                cout<<"\nResult = "<<result;
                break;
            
            default:
                cout<<"\nretry!";
                break;
        }
        cout<<"\n------------------------\n";
    }while(opt!=5);
    cout<<endl;
    return 0;
}
