#include<iostream>
#include<fstream>

using namespace std;

// creating class and declaring variables

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void reciept();
};

//menu function
void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t______________________________________\n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t         Supermarket Main Menu        \n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t______________________________________\n";
    cout<<"\t\t\t\t                                      \n";

//menu to select whether the user is Administrator or buyer
    cout<<"\t\t\t\t|  1)  Administrator    |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\t\t\t\t|  2)  Buyer            |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\t\t\t\t|  3)  Exit             |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\t\t\t\t Please select! ";
    cin>>choice;

// for making choice among choices    
    switch(choice)
    {
        case 1:
        cout<<"\t\t\t Please Login    \n";
        cout<<"\t\t\t Enter Email     \n";
        cin>>email;
        cout<<"\t\t\t Enetr Password  \n";
        cin>>password;

        //condition for only admin login(setting password if it is admin)
        if(email=="varsha@email.com" && password=="varsha@123")
        {
            administrator();
        }
        else{
            cout<<"Invalid Email/Password";
        }
        break;

        case 2: {
        buyer();
    }
    case 3:
{
    exit(0);
}
    break;

    default:
    {
        cout<<"Please Select from the given option";
    }

    }
    

//goto is a jump statement so it will help in jumping on the main menu again
goto m;
}

//administrator function
void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t |________1) Add the Product___________|";
    cout<<"\n\t\t\t |                                     |";
    cout<<"\n\t\t\t |________2) Modify the Product________|";
    cout<<"\n\t\t\t |                                     |";
    cout<<"\n\t\t\t |________3) Delete the Product________|";
    cout<<"\n\t\t\t |                                     |";
    cout<<"\n\t\t\t |________4) Back to Main Menu________ |";
    
    cout<<"\n\n\tPlease Enter your choice";
    cin>>choice;

    switch(choice)
    {
        case 1:
            add();
            break;

        case 2:
            edit();
            break;

        case 3:
            rem();
            break;

        case 4:
            menu();
            break;

        default:
            cout<<"Invalid Choice";

    }
    goto m;
}

//buyer function

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t  Buyer  \n";
    cout<<"_____________________  \n";
    cout<<"                       \n";
    cout<<"\t\t\t 1) Buy Product  \n";
    cout<<"                       \n";
    cout<<"\t\t\t 2) Go Back      \n";
    cout<<"\t\t\t Enter your choice";
    cin>>choice;

    switch(choice)
    {
        case 1:
             reciept();
             break;

        case 2:
             menu();
             break;
             
        default: 
        cout<<"Invalid Choice";

    }
    goto m;

}

//add function- using some file handling operations

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new Product";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the Product";
    cin>>pname;
    cout<<"\n\n\t Price of the Product";
    cin>>price;
    cout<<"\n\n\t Discount on the Product";
    cin>>dis;

    data.open("database.txt", ios::in); //ios::in will open the file in reading mode and ios::out will open the file in writing mode
    
    if(!data)  //if the file do not exist
    {
        data.open("database.txt", ios::app |ios::out); //ios::app stands for append mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

        data.close();
    }
    else{ // if the file exist
        data>>c>>n>>p>>d;  //read from the file  here we are initializing the index of file cause after this we have to use the while loop to iterate through this file

        while(data >> c >> n >> p >> d)
        {
            if(c == pcode)
            {
                token++;
            }
        }
        data.close();
    
    if(token==1) //if there is a duplicacy then it will go back to the menu
    goto m;
    else{        // if the token value is not incremented or if the product code is unique
        data.open("database.txt", ios::app |ios::out); //ios::app stands for append mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
}
    cout<<"\n\n\t\t Record inserted!";
     system("pause");
    return;
}

//edit function

void shopping :: edit()
{
    fstream data, data1;  //2 objects of fstream class
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t Modify the Record";
    cout<<"\n\n\t\t Enter the product code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File does not exist! ";
    }
    else{
        data1.open("database1.txt", ios::app | ios::out);

        data>>pcode>>pname>>price>>dis;
        while(data >> pcode >> pname >> price >> dis)
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Products new code";
                cin>>c;
                cout<<"\n\n\t Name of theProduct";
                cin>>n;
                cout<<"\n\n\t Price of the Product";
                cin>>p;
                cout<<"\n\n\t discount";
                cin>>d;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t Record edited!";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt"); 
        
        if(token==0)
        {
            cout<<"\n\t\t Record not found !";
        }
    }

}

//remove function

void shopping :: rem()
{
    fstream data, data1;
    int pkey;
    int token=0;
    cout<<"\n\t\t Delete Product";
    cout<<"\n\n\t Enter the product code ";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\t\t File does not exist ! ";
    }
    else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(data >> pcode >> pname >> price >> dis)
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt","database.txt");

            if (token==0)
            {
                cout<<"\n\n Record can not be found !";
            }
    }
}
void shopping :: list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n______________________________________________\n";
    cout<<"ProNo<<\t\t Name\t\t Price\n";
    cout<<"\n\n______________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(data >> pcode >> pname >> price >> dis)
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

//reciept function

void shopping :: reciept()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RRECIEPT ";
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else{
        data.close();

        list();
        cout<<"\n____________________________________________\n";
        cout<<"\n|                                           \n";
        cout<<"\n           Please palce the order           \n";
        cout<<"\n|                                           \n";
        cout<<"\n____________________________________________\n";

        do
        {
            m:
            cout<<"\n\n Enter Product code :";
            cin>>arrc[c];
            cout<<"\n\n Enter the quantity :";
            cin>>arrq[c];
            for(int i=0; i<c; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate Product code. PLease try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? if yes press y else n if no.";
            cin>>choice;
        }
        while (choice =='y');

        cout<<"\n\n\t\t\t_________________________________RECIEPT___________________________________\n";
cout<<"\n Product No \t Product Name \t Quantity \t Price \t Amount \t Amount after Discount\n";

for(int i=0; i<c; i++)
{
    data.open("database.txt", ios::in);

    while(data >> pcode >> pname >> price >> dis)
    {
        if(pcode == arrc[i])
        {
            amount = price * arrq[i];
            float discountAmount = amount - (amount * dis / 100);
            total = total + discountAmount;

            cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]
                <<"\t\t"<<price<<"\t\t"<<amount
                <<"\t\t"<<discountAmount;
        }
    }

    data.close();
}

    cout<<"\n\n__________________________________________________________________";
    cout<<"\n Total amount :"<<total;
}
}

int main()
{
    shopping s;
    s.menu();
}