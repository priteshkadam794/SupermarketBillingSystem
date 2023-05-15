#include<iostream>
#include<fstream>
using namespace std;


class Shopping{
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
        void receipt();
};

void Shopping :: menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t___________________________________\n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t      Supermarket Main Menu        \n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t___________________________________\n";
    cout;
    cout<<"\t\t\t\t|     1) Administrator     |\n";     
    cout<<"\t\t\t\t|                          |\n";     
    cout<<"\t\t\t\t|     2) Buyer             |\n";  
    cout<<"\t\t\t\t|                          |\n";     
    cout<<"\t\t\t\t|     3) Exit              |\n"; 
    cout<<"\t\t\t\t|                          |\n";     
    cout<<"\n\t\t\t Please Select!";
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t\t Enter email  \n";
            cin>>email;
            cout<<"\t\t\t Password     \n";
            cin>>password;
            if(email == "user@gmail.com" && password == "user@123"){
                administrator();
            }
            else{
                cout<<"invalid email/password";
            }
            break;
        case 2:
            buyer();
        case 3:
            exit(0);
        default:
            cout<<"Please select from the given option";

    }
    goto m;

}


void Shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Admistrator menu";
    cout<<"\n\t\t\t|____1) Add the product____|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____2) Modify the product_|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____3) Delete the product_|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____4) Back to main menu__|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;
    switch(choice){
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
            cout<<"Invalid choice!";

    }

    goto m;


}

void Shopping :: buyer(){
    m:
    int choice;
    cout<<"\t\t\t____ Buyer ____\n";
    cout<<"\t\t\t               \n";
    cout<<"\t\t\t 1)Buy Product \n";
    cout<<"\t\t\t               \n";
    cout<<"\t\t\t 2)Go Back     \n";
    cout<<"\t\t\t               \n";

    cout<<"\t\t\t Enter your Choice : ";
    cin>>choice;
    switch(choice){

        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"invalid choice";
    }   
    goto m;
}

void Shopping :: add(){
    m:
    fstream data;
    int code;
    int token = 0;
    float price;
    float discount;
    string name;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t name of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product ";
    cin>>price;
    cout<<"\n\n\t Discount on the product";
    cin>>dis;

    data.open("database.txt", ios::in);
    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>code>>name>>price>>discount;

        while(!data.eof()){
            if(code== pcode){
                token++;
            }
            data>>code>>name>>price>>discount;
        }
        data.close();

    }
    if(token == 1){
        goto m;
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    cout<<"\n\n\t\t Record Inserted !";

}


void Shopping :: edit(){
    fstream data;
    fstream data1;

    int pkey;
    int token0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record ";
    cout<<" \n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt" , ios::in);
    if(!data){
        cout<<"\n\n File doesn't exist!";
    }
    else{
        data1.open("database1.txt" , ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey == pcode){
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product";
                cin>>n;
                cout<<"\n\t\t Price of the product";
                cin>>p;
                cout<<"\n\t\t Discount on the product";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t Record Edited";
                token0++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt" , "database.txt");

        if(token0 == 0){
            cout<<"\n\t\t\t Record not found!";
        }

    }

}

void Shopping :: rem(){

    fstream data , data1;
    int pkey;
    int token0;
    cout<<"\n\t\t Delete Product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt" , ios::in);
    if(!data){
        cout<<"file doesn't exists";
    }else{
        data1.open("database1.txt ", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey == pcode){
                cout<<"\n\t\t Product deleted successfully";
                token0++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt" , "database.txt");
        if(token0 == 0){
            cout<<"Record not found";
        }
    }
}


void Shopping :: list(){
    fstream data;
    data.open("database.txt" , ios::in);
    cout<<"\n\n|_____________________________________________\n";
    cout<<"ProdNo\t\tName\t\tPrice\t\n";
    cout<<"\n\n|_____________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}

void Shopping :: receipt(){
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    int choice;
    int counter;
    float dis = 0;
    float amount = 0;
    float total = 0;
    cout<<"\n\n]\t\tRECEIPT ";
    data.open("database.text" , ios::in);
    if(!data){
        cout<<"\n\t\t Empty Database";
    }
    else{
        data.close();
        list();
        cout<<"\n____________________________________\n";
        cout<<"\n|                                  |\n";
        cout<<"\n    Please place your order          \n";
        cout<<"\n|                                  |\n";

        do
        {
            cout<<"\nEnter the product code";
            cin>>arrc[counter];
            cout<<"\nEnter product quantity";
            cin>>arrq[counter];
            for(int i = 0;i<counter;i++){
                if(arrc[counter] == arrc[i]){
                    cout<<"\n\t Duplicate product code! Please try again";
                    goto m;
                }
            }
            counter++;
            cout<<"\n\n Do you want to buy another product or not press y for yes and n for no";
            cin>>choice;
        } while (choice == 'y');
        cout<<"\n\n\t\t\t______________________RECEIPT__________________\n";
        cout<<"\nProduct-No\t  Qty \t Price \t Amount \t Amount with discount \n";
        for(int i = 0; i<counter ;i++){
            data.open("database.txt" , ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode == arrc[i]){
                    amount = price*arrq[i];
                    dis = amount- (amount*dis/100);
                    total = total + dis;
                    cout<<"\n "<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<dis;
                    data>>pcode>>pname>>price>>dis;

                }data.close();
            }

            cout<<"\n\n___________________________________\n";
            cout<<"\n Total Amount :"<<total;

        }

    }

}

int main(){
    Shopping s;
    s.menu();
    return 0;
}