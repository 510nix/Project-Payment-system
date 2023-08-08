#include<bits/stdc++.h>
using namespace std;
class cafeteria;
class new_account;
class hall;
class academics;
class store_data;
class employee;
class dept_store;

class new_account
{
private:
    string Name;
    string Dept;
    string Hall;
    int Roll;
    string Year;
    float Amount;
    float Due;
    public:
        friend class store_data;
    new_account()
    {
    Name="Unavailable";
    Dept="Unavailable";
    Hall="Unavailable";
    Roll=0;
    Year="Unavailable";
    Amount=0;
    Due=0;
    }
    new_account(string a,string b,string c,int d,string e ,float f)
    {
    Name=a;
    Dept=b;
    Hall=c;
    Roll=d;
    Year=e;
    Amount=f;
    Due=0;
    }
    void set_name(string s)
    {
        Name=s;
    }
    void set_dept(string s)
    {
        Dept=s;
    }
    void set_hall(string s)
    {
        Hall=s;
    }
    void set_roll(int s)
    {
        Roll=s;
    }
    void set_year(string s)
    {
        Year=s;
    }
    void set_amount(float s)
    {
        Amount=s;
    }
    void set_due(float s)
    {
        Due=s;
    }
    string get_name()
    {
        return Name;
    }
    string get_dept()
    {
        return Dept;
    }
    int get_roll()
    {
        return Roll;
    }
    string get_year()
    {
        return Year;
    }
    string get_hall()
    {
        return Hall;
    }
    float get_amount()
    {
        return Amount;
    }
    float get_due()
    {
        return Due;
    }
    void update_due(float x)
    {
        if(Due+x>10000)
    {
    cout<<"Your due amount has exceeded 10000Taka"<<endl;
    cout<<"Please clear your dues first for further use"<<endl;
    }
    else
     {
        Due+=x;
     }
    }
    void update_amount(float x)
    {
        Amount+=x;
    }
    void  pay_due()
    {
        if(Amount>=Due)
        {
            cout<<"All dues are payed successfully."<<endl;
            Amount=Amount-Due;
            Due=0;

        }
        else
        {
            cout<<"some dues are payed"<<endl;
            Due=Due-Amount;
            Amount=0;
            cout<<"You still have some dues please add some more money to your account to clear all dues"<<endl;
        }
    }
};
class employee
{
private:
    int Id;
    string Name;
    string Position;
public:
    friend class store_data;
    employee()
    {
    }
    employee(int a,string b,string c)
    {
        Id=a;
        Name=b;
        Position=c;
    }
    int get_id()
    {
        return Id;
    }
    string get_name()
    {
        return Name;
    }
    string get_position()
    {
        return Position;
    }
};
class store_data
{
    vector<new_account>Student;
    vector<employee>Employee;
    static int counts;
public:
    friend class new_account;
    friend class employee;

    void create_account(new_account a)
    {
        Student.push_back(a);
    }
    void create_employee(employee a)
    {
        Employee.push_back(a);
    }
    void pay_dues_student()
    {
        cout<<"Enter Roll:"<<endl;
        int roll;
        cin>>roll;
        for(int i=0;i<Student.size();i++)
        {
            if(Student[i].get_roll()==roll)
            {
                Student[i].pay_due();
                return;
            }
        }
        cout<<"Roll not found"<<endl;
        return;
    }
    void deposit_money()
    {
        cout<<"Enter Roll:"<<endl;
        int roll;
        cin>>roll;
        for(int i=0;i<Student.size();i++)
        {
            if(Student[i].get_roll()==roll)
            {
                cout<<"Enter the amount you want to deposit"<<endl;
                float f;
                cin>>f;
                Student[i].update_amount(f);
                return;
            }
        }
        cout<<"Roll not found"<<endl;
        return;
    }

    void show_due_student()
    {
        bool c=false;
        cout<<"Enter Roll:"<<endl;
        int a;
        cin>>a;
        for(int i=0;i<Student.size();i++)
        {
            if(a==Student[i].get_roll())
            {
                cout<<"Due amount for roll "<<a<<" is: "<<Student[i].get_due()<<endl;
                char s;
                cout<<"Do you want do see all info of that student?\nPress Y to see all the info."<<endl;
                cin>>s;
                if(s=='Y')
                {
                    cout<<"Students information:"<<endl;
                    cout<<"Name:"<<Student[i].get_name()<<endl;
                    cout<<"Roll:"<<Student[i].get_roll()<<endl;
                    cout<<"Department:"<<Student[i].get_dept()<<endl;
                    cout<<"Hall:"<<Student[i].get_hall()<<endl;
                    cout<<"Year:"<<Student[i].get_year()<<endl;
                    cout<<"Due Amount:"<<Student[i].get_due()<<endl;
                    cout<<"Current Balance:"<<Student[i].get_amount()<<endl;
                }
            }
        }
    }
        void update_due(float y)
      {
          bool b=false;
        cout<<"Enter Roll"<<endl;
        int z;
        cin>>z;
        for(int i=0;Student.size();i++)
        {
            if(Student[i].get_roll()==z)
            {
                b=true;
                cout<<"Due has been Updated"<<endl;
                Student[i].update_due(y);
                break;
            }
        }
        if(b==false)
        {
            cout<<"Invalid User"<<endl;
        }
        }
        string get_prof(int xx)
        {
            for(int i=0;i<Employee.size();i++)
            {
                if(xx==Employee[i].get_id())
                {
                    return Employee[i].get_position();
                }
            }
            cout<<"Id Unavailable"<<endl;
            return "NULL";
        }
};

class academics
{
    static int reg_fee;
    vector<pair<string,vector<pair<string,float>>>>subject_book={{"EEE",{{"Basic_Electrical_Engineering",100},{"Fundemental_Circuit",80}}},{"CSE",{{"Let_Us_C",120},{"Let_Us_C++",130},{"ANCI_C",100}}},{"MATH",{{"Coordinate_geometry",100},{"Differential_calculus",110},{"Integral_Calcusus",100}}}};
    public:
    void add_books()
    {
        bool m=false;
        cout<<"Enter Subject name:"<<endl;
        string s1;
        cin>>s1;
        cout<<"Enter Book name:"<<endl;
        string s2;
        cin>>s2;
        cout<<"Enter Amount:"<<endl;
        float ff;
        cin>>ff;
        for(int i=0;i<subject_book.size();i++)
        {
            if(s1==subject_book[i].first)
            {
                m=true;
                subject_book[i].second.push_back({s2,ff});
            }
        }
        if(m==false)
        {
            vector<pair<string,float>>temp;
            //pair<string,vector<pair<string,float>>>temp1;
            temp.push_back({s2,ff});
            subject_book.push_back({s1,temp});

        }
    }
    void show_books()
    {
        for(int i=0;i<subject_book.size();i++)
        {
            cout<<"subject is :"<<subject_book[i].first<<endl;
            cout<<"related books are:"<<endl;
            for(auto it : subject_book[i].second)
            {
                cout<<it.first<<" and price is "<<it.second<<" taka."<<endl;
            }
        }
    }
    float value_books()
    {
        bool x1=false;
        cout<<"Enter Subject name:"<<endl;
        string s;
        cin>>s;
        cout<<"Enter Book name:"<<endl;
        string s1;
        cin>>s1;
        for(int i=0;i<subject_book.size();i++)
        {
            if(s==subject_book[i].first)
            {
                for(auto it:subject_book[i].second)
                {
                    if(it.first==s1)
                    {
                        x1=true;
                        cout<<"The value of the book is "<<it.second<<endl;
                        cout<<"Want to take it? \nPress Y to take it"<<endl;
                        char s2;
                        cin>>s2;
                        if(s2=='Y')
                        {
                            cout<<"Price added to your Due Money"<<endl;
                            return it.second;
                        }
                        else
                        {
                            cout<<"Sorry for the inconvenience"<<endl;
                            return 0.0;
                        }
                    }
                }
            }
        }
        if(x1==false)
        {
            cout<<"Book is not available at this moment"<<endl;

        }
        return 0.0;
    }
    float reg_fee_func()
    {
        cout<<"Your Registration fee is "<<reg_fee<<" taka"<<endl;
        cout<<"Want to pay it? \nPress Y to pay"<<endl;
                        char a;
                        cin>>a;
                        if(a=='Y')
        {
            float ff=reg_fee;
            return ff;
        }
        else
        {
        return 0.0;
        }
    }
    void update_reg_fee()
    {
        cout<<"Current registration fee is "<<reg_fee<<" taka"<<endl;
      cout<<"Do you want to change\nPress Y to take it"<<endl;
                        char s2;
                        cin>>s2;
                        if(s2=='Y')
        {
            cout<<"Enter amount"<<endl;
            int a;
            cin>>a;
            reg_fee=a;
            cout<<"Updated"<<endl;
        }

    }

};
class hall
{
    static int hall_fee;
    pair<float,vector<string>>avail_items ={40,{"rice","chicken","lentil","vegetable"}};
    public:
          vector<string>h_name={{"Lalan_shah_hall"},{"Khan_jahan_ali_hall"},{"Dr_a_k_fozlul_haque_hall"},{"Bongobondhu_sheikh_mujibur_rahamn_hall"},{"Amar_ekushe_hall"},{"Dr_m_a_roshid_hall"},{"Rokeya_hall"}};
    friend void show_hall(hall &);
    void av_meal()
    {
        cout<<"Meal price "<<avail_items.first<<endl;
        cout<<"items are:"<<endl;
        for(int i=0;i<avail_items.second.size();i++)
        {
            cout<<i+1<<". "<<avail_items.second[i]<<endl;
        }
    }
    void add_item()
    {
        string s;
        cout<<"Enter item name:"<<endl;
        cin>>s;
        cout<<"Enter price of that item:"<<endl;
        float f;
        cin>>f;
        avail_items.first+=f;
        avail_items.second.push_back(s);

    }
    void remove_item()
    {
        string s;
        cout<<"Enter item name:"<<endl;
        cin>>s;
        cout<<"Enter price of that item:"<<endl;
        float f;
        cin>>f;
        for(int i=0;i<avail_items.second.size();i++)
        {
            if(avail_items.second[i]==s)
            {
                avail_items.second.erase(avail_items.second.begin()+i);
                avail_items.first-=f;
                cout<<"successfully done"<<endl;
                break;
            }
        }
    }
    float hall_fee_func()
    {
        cout<<"Your Hall fee is "<<hall_fee<<" Taka"<<endl;
        cout<<"Do you want to pay it? To pay press Y"<<endl;
        char s;
        cin>>s;
        if(s=='Y')
        {
            float ff=hall_fee;
            return ff;
        }
        else
        {
        return 0.0;
        }
    }
    void update_hall_fee()
    {
        cout<<"Fee is "<<hall_fee<<" taka"<<endl;
        cout<<"Do you want to change it ?To update hall fee press Y"<<endl;
        char s;
        cin >>s;
        if(s=='Y')
        {
            cout<<"Enter amount"<<endl;
            int a;
            cin>>a;
            hall_fee=a;
            cout<<"Updated and the amount."<<endl;
        }

    }
    float get_price()
    {
            return avail_items.first;
    }

};
void show_hall(hall &asds)
    {
        for(int i=0;i<asds.h_name.size();i++)
        {
            cout<<i+1<<". "<<asds.h_name[i]<<endl;
        }
        cout<<endl;
    }
class cafeteria
{
    vector<pair<string,float>>item={{"tea",15},{"coffee",30},{"somocha",5},{"soup",50},{"chicken_fry",80},{"chips",10},{"biscuits",20},{"drinks",25},{"cake",20}};
    public:
    void display_1()
    {
        cout<<"Available items:"<<endl;
        for(int i=0;i<item.size();i++)
        {
            cout<<i+1<<"."<<item[i].first<<" $ "<<item[i].second<<" Taka."<<endl;
        }
    }
    void add_item(string s,float f)
    {
        item.push_back({s,f});
    }
    void update_item(string s,float f)
    {
        for(int i=0;i<item.size();i++)
        {
            if(item[i].first==s)
            {
                item[i].second=f;
                cout<<"Price updated"<<endl;

            }
        }
    }
    void remove_item(string s)
    {
        for(int i=0;i<item.size();i++)
        {
            if(item[i].first==s)
            {
                item.erase(item.begin()+i);

            }
        }
    }
float get_price_cafe(string s)
{
    for(int i=0;item.size();i++)
    {
        if(s==item[i].first)
        {
            return item[i].second;
        }
    }
    cout<<"Item not found"<<endl;
    return 0.0;
}
};

class dept_store
{
    public:
    vector<pair<string,float>>item_1={{"pencil",15.0},{"pen",5},{"scale",30},{"eraser",12},{"lab_report",50},{"mechanical_drawing_set",500},{"architecture_set",800}};
    public:
    void display_1()
    {
        for(int i=0;i<item_1.size();i++)
        {
            cout<<i+1<<"."<<item_1[i].first<<" $ "<<item_1[i].second<<" Taka."<<endl;
        }
    }
    void add_item(string s,float f)
    {
        item_1.push_back({s,f});
    }
    void update_item(string s,float f)
    {
        for(int i=0;i<item_1.size();i++)
        {
            if(item_1[i].first==s)
            {
                item_1[i].second=f;
                cout<<"Price updated"<<endl;

            }
        }
    }
    void remove_item(string s)
    {
        for(int i=0;i<item_1.size();i++)
        {
            if(item_1[i].first==s)
            {
                item_1.erase(item_1.begin()+i);

            }
        }
    }
    float get_price(string s)
{
    for(int i=0; item_1.size();i++)
    {
        if(s==item_1[i].first)
        {
            return item_1[i].second;
        }
    }
    cout<<"Item not found"<<endl;
    return 0.0;
}
};
int store_data::counts;
int hall :: hall_fee;
int academics :: reg_fee;

int main()
{
    store_data aa;
    dept_store bb;
    cafeteria cc;
    dept_store dd;
    cafeteria ee;
    hall ff;
    academics gg;
    cout<<"------------------------------------------WELCOME TO KUET PAYMENT SYSTEM-------------------------------------\n\n\n"<<endl;
    cout<<"                                 I am here to help you with all kinds of payment\n\n\n"<<endl;
    cout<<"                                              For any action press Y"<<endl;
    char ch;
    cin>>ch;
    while('Y')
    {
        cout<<"Operations:"<<endl;
        cout<<"1.Create Account & Payments"<<endl;
        cout<<"2.Academic Bills"<<endl;
        cout<<"3.Hall Bills"<<endl;
        cout<<"4.Cafeteria Bills"<<endl;
        cout<<"5.Departmental Store Bills"<<endl;
        cout<<"6.Update Information"<<endl;
        int a;
        cout<<"\n\nEnter your choice : ";
        cin>>a;
        switch(a)
        {
        case 1:
            {
                int xx=1;
                do
            {
            cout<<"\n\n1.Create New Account for student"<<endl;
            cout<<"2.Create New Account for Employee"<<endl;
            cout<<"3.Show Due Money of a Student"<<endl;
            cout<<"4.Pay dues"<<endl;
            cout<<"5.Deposit amount"<<endl;
            int a1;
            cout<<"\n\nEnter your choice"<<endl;
            cin>>a1;


           if(a1==1)
              {
                cout<<"Student's information:"<<endl;
                    cout<<"Name:"<<endl;
                    string n1;
                    cin>>n1;
                    cout<<"Roll:"<<endl;
                    int r1;
                    cin>>r1;
                    cout<<"Department:"<<endl;
                    string d1;
                    cin>>d1;
                    cout<<"Hall:"<<endl;
                    string h1;
                    cin>>h1;
                    cout<<"Year:"<<endl;
                    string y1;
                    cin>>y1;
                    cout<<"Amount you want to deposit:"<<endl;
                    float dd;
                    cin>>dd;
                    new_account xx(n1,d1,h1,r1,y1,dd);
                    aa.create_account(xx);
                    cout<<"Account Created"<<endl;
              }
         else if(a1==2)
                {
                cout<<"Employee's Information:"<<endl;
                cout<<"ID:"<<endl;
                int i1;
                cin>>i1;
                cout<<"Name:"<<endl;
                string n1;
                cin>>n1;
                cout<<"Position:"<<endl;
                string s1;
                cin>>s1;
                employee xx(i1,n1,s1);
                aa.create_employee(xx);
                }
            else if(a1==3)
                {

                aa.show_due_student();

                }
            else if(a1==4)
                {
                    aa.pay_dues_student();

                }
            else if(a1==5)
                {
                    aa.deposit_money();

                }
            else
                {
                cout<<"Invalid Response"<<endl;

                }
                cout<<"To exit from this function press 0"<<endl;
                cin>>xx;

            }while(xx!=0);


            break;
        }
            case 2:
                {
                    int xy=1;
                    do{
                             cout<<"1.Show books"<<endl;
                    cout<<"2.Pay registration bills"<<endl;
                    cout<<"3.Get Books and Pay"<<endl;
                    cout<<"Enter Your Choice"<<endl;
                    int a2;
                    cin>>a2;

            if(a2==1)

                {
                    gg.show_books();

                }
            else if(a2==2)
                {
                    float ff;
                    ff=gg.reg_fee_func();
                    aa.update_due(ff);

                }
            else if(a2==3)
                {
                    float ff;
                    ff=gg.value_books();
                    aa.update_due(ff);

                }
           else
                {
                    cout<<"Invalid Response"<<endl;

                }
                cout<<"To exit from this function press 0"<<endl;
                cin>>xy;

                    }while(xy!=0);

                break;
                    }

                case 3:
                    {
                        int yy=1;
                        do{
                        cout<<"1.Available Meal"<<endl;
                        cout<<"2.Show all Halls"<<endl;
                        cout<<"3.Pay Hall fees"<<endl;
                        cout<<"4.Pay And Get Meal"<<endl;
                        int a3;
                        cout<<"Enter your choice"<<endl;
                        cin>>a3;


                        if(a3==1)
                            {
                                ff.av_meal();

                            }
                            else if(a3==2)
                            {
                                show_hall(ff);
                            }

                        else if(a3==3)
                            {
                                float f;
                                f=ff.hall_fee_func();
                                aa.update_due(f);

                            }
                         else if(a3==4)
                            {
                                float f;
                                f=ff.get_price();
                                aa.update_due(f);
                            }
                        else
                            {
                                cout<<"Invalid Response"<<endl;

                            }
                            cout<<"To exit from this function press 0"<<endl;
                cin>>yy;

                        }while(yy!=0);

                            break;
                        }


                        case 4:
                            {

                 int yz=1;
                 do{
                           cout<<"1.Available Food"<<endl;
                        cout<<"2.Pay And Get Food"<<endl;
                        int a3;
                        cout<<"Enter your choice"<<endl;
                        cin>>a3;

                        if(a3==1)
                            {
                                ee.display_1();

                            }
                        else if(a3==2)
                            {
                                cout<<"Enter food Name:"<<endl;
                                string sss;
                                cin>>sss;
                                float ff;
                                ff=ee.get_price_cafe(sss);
                                aa.update_due(ff);

                            }
                        else
                            {
                                cout<<"Invalid Response"<<endl;

                            }
                              cout<<"To exit from this function press 0"<<endl;
                cin>>yz;

                 }while(yz!=0);

                        break;
                            }
                            case 5:
                            {
             int zz=1;
             do{
                           cout<<"1.Available Items"<<endl;
                        cout<<"2.Pay And Get Items"<<endl;
                        int a3;
                        cout<<"Enter your choice"<<endl;
                        cin>>a3;
                        if(a3==1)
                            {
                                dd.display_1();

                            }
                        else if(a3==2)
                            {
                                cout<<"Enter Item Name:"<<endl;
                                string sss;
                                cin>>sss;
                                float ff;
                                ff= dd.get_price(sss);
                                aa.update_due(ff);

                            }
                        else
                            {
                                cout<<"Invalid Response"<<endl;

                            }
                               cout<<"To exit from this function press 0"<<endl;
                cin>>zz;

             }while(zz!=0);
                              break;
                        }


                        case 6:
                            {
                                  cout<<"For updating any information you must be a shop_keeper or butler or office_assistant or hall_manager in the departmental store or cafeteria or academy or hall respectively."<<endl;
                                int xz=1;
                                do{
                                cout<<"Enter your id:"<<endl;
                                int aaa;
                                cin>>aaa;
                                string st1;
                                st1=aa.get_prof(aaa);
                                if(st1=="hall_manager")
                                {
                                    cout<<"Update info for hall"<<endl;
                                     cout<<"1. Add Item"<<endl;
                                     cout<<"2.Remove Item"<<endl;
                                     cout<<"3.Update  hall fee"<<endl;
                                     int abc;
                                     cout<<"Enter your choice"<<endl;
                                     cin>>abc;
                                     if(abc==1)
                                     {
                                         ff.add_item();
                                     }
                                     else if(abc==2)
                                     {
                                         ff.remove_item();
                                     }
                                     else if(abc==3)
                                     {
                                         ff.update_hall_fee();
                                     }
                                     else
                                     {
                                         cout<<"Invalid Response"<<endl;
                                     }
                                }
                                else if(st1=="office_assistant")
                                {
                                    cout<<"Update Academic info "<<endl;
                                     cout<<"1.Add Books"<<endl;
                                     cout<<"2.Update registration fee"<<endl;
                                     int abc;
                                     cout<<"Enter your choice"<<endl;
                                     cin>>abc;
                                     if(abc==1)
                                     {
                                         gg.add_books();
                                     }
                                     else if(abc==2)
                                     {
                                         gg.update_reg_fee();
                                     }
                                     else
                                     {
                                         cout<<"Invalid Response"<<endl;
                                     }
                                }
                                else if(st1=="butler")
                                {
                                    cout<<"Update Food info in Cafeteria"<<endl;
                                     cout<<"1.Add items"<<endl;
                                     cout<<"2.Remove items"<<endl;
                                     cout<<"3.Update items"<<endl;
                                     int abc;
                                     cout<<"Enter your choice"<<endl;
                                     cin>>abc;
                                     if(abc==1)
                                     {
                                         cout<<"Enter name of the food:"<<endl;
                                         string ffs;
                                         cin>>ffs;
                                         cout<<"Enter Price"<<endl;
                                         float fff;
                                         cin>>fff;
                                         cc.add_item(ffs,fff);
                                     }
                                     else if(abc==2)
                                     {
                                         cout<<"Enter name of the food:"<<endl;
                                         string ffs;
                                         cin>>ffs;
                                         cc.remove_item(ffs);
                                     }
                                     else if(abc==3)
                                     {
                                         cout<<"Enter name of the food:"<<endl;
                                         string ffs;
                                         cin>>ffs;
                                         cout<<"Enter Price"<<endl;
                                         float fff;
                                         cin>>fff;
                                         cc.update_item(ffs,fff);
                                     }
                                     else
                                     {
                                         cout<<"Invalid Response"<<endl;
                                     }
                                }
                                else if(st1=="shop_keeper")
                                {
                                    cout<<"Update item info in Departmental store"<<endl;
                                     cout<<"1.Add items"<<endl;
                                     cout<<"2.Remove items"<<endl;
                                     cout<<"3.Update items"<<endl;
                                     int abc;
                                     cout<<"Enter your choice"<<endl;
                                     cin>>abc;
                                     if(abc==1)
                                     {
                                         cout<<"Enter name of the Item:"<<endl;
                                         string ffs;
                                         cin>>ffs;
                                         cout<<"Enter Price"<<endl;
                                         float fff;
                                         cin>>fff;
                                         dd.add_item(ffs,fff);
                                     }
                                     else if(abc==2)
                                     {
                                         cout<<"Enter name of the Item:"<<endl;
                                         string ffs;
                                         cin>>ffs;
                                         dd.remove_item(ffs);
                                     }
                                     else if(abc==3)
                                     {
                                         cout<<"Enter name of the Item:"<<endl;
                                         string ffs;
                                         cin>>ffs;
                                         cout<<"Enter Price"<<endl;
                                         float fff;
                                         cin>>fff;
                                         dd.update_item(ffs,fff);
                                     }
                                     else
                                     {
                                         cout<<"Invalid Response"<<endl;
                                     }
                                }
                                else
                                {
                                    cout<<"You cannot perform any changes!"<<endl;
                                }
                                   cout<<"To exit from this function press 0"<<endl;
                cin>>xz;

                                }while(xz!=0);

                                break;
                            }
                        default:
                            {
                                cout<<"Invalid Response"<<endl;
                                break;
                            }
                }
                cout<<"To exit enter N else press any other key!!"<<endl;
                char ssa;
                cin>>ssa;
                if(ssa=='N')
                {
                    cout<<"\n\n\nThank you for your cooperation"<<endl;
                    break;
                }
    }
    return 0;
}
