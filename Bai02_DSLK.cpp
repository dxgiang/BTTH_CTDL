#include<iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
}*start;
 

class single_llist
{
    public:
        node* create_node(int);
        void insert_begin();
        void insert_pos();
        void insert_last(); 
        void delete_pos();
        void sort();
        void search();
        void update();
        void reverse();
        void display();
        single_llist() 
        {
            start = NULL;
        }
};
 

main()
{
    int choice, nodes, element, position, i;
    single_llist sl;
    start = NULL;
    while (1)
    {
        cout<<"[1].  Insert node o dau"<<endl;
        cout<<"[2].  Insert node o cuoi"<<endl;
        cout<<"[3].  Insert node tai vi tri"<<endl;
        cout<<"[4].  Sap xep DSLK"<<endl;
        cout<<"[5].  Delete node"<<endl;
        cout<<"[6].  Update gia tri cua node"<<endl;
        cout<<"[7].  Tim kiem phan tu"<<endl;
        cout<<"[8].  Hien thi DSLK"<<endl;
        cout<<"[9].  Dao nguoc DSLK "<<endl;
        cout<<"[10]. Exit "<<endl;
        cout<<"Nhap lua chon : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Insert node o dau: "<<endl;
            sl.insert_begin();
            cout<<endl;
            break;
        case 2:
            cout<<"Insert node o cuoi: "<<endl;
            sl.insert_last();
            cout<<endl;
            break;
        case 3:
            cout<<"Insert node tai vi tri:"<<endl;
            sl.insert_pos();
            cout<<endl;
            break;
        case 4:
            cout<<"Sort Link List: "<<endl;
            sl.sort();
            cout<<endl;
            break;
        case 5:
            cout<<"Delete node: "<<endl;
            sl.delete_pos();
            break;
        case 6:
            cout<<"Update gia tri cua node:"<<endl;  
            sl.update();
            cout<<endl;
            break;
        case 7:
            cout<<"Tim kiem phan tu trong DSLK: "<<endl;
            sl.search();
            cout<<endl;
            break;
        case 8:
            cout<<"Hien thi cac phan tu tron DSLK"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 9:
            cout<<"Dao nguoc cac phan tu tron DSLK"<<endl;
            sl.reverse();
            cout<<endl;
            break;
        case 10:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Nhap sai lua chon! Moi nhap lai!!!"<<endl;
        }
    }
}
 
//Tao node
node *single_llist::create_node(int value)
{
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"Chua phan vung bo nho "<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;     
        return temp;
    }
}
 
//Insert node o dau
void single_llist::insert_begin()
{
    int value;
    cout<<"Nhap gia tri: ";
    cin>>value;
    struct node *temp, *p;
    temp = create_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;          
    } 
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"Da them phan tu vao vi tri dau"<<endl;
}
 
//Insert node o cuoi
void single_llist::insert_last()
{
    int value;
    cout<<"Nhap gia tri: ";
    cin>>value;
    struct node *temp, *s;
    temp = create_node(value);
    s = start;
    while (s->next != NULL)
    {         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp;
    cout<<"Da them phan tu vao vi tri cuoi"<<endl;  
}
 
//Insert node tai 1 vi tri chi dinh
void single_llist::insert_pos()
{
    int value, pos, counter = 0; 
    cout<<"Nhap gia tri: ";
    cin>>value;
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    cout<<"Nhap vi tri cua node duoc chen: ";
    cin>>pos;
    int i;
    s = start;
    while (s != NULL)
    {
        s = s->next;
        counter++;
    }
    if (pos == 1)
    {
        if (start == NULL)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter)
    {
        s = start;
        for (i = 1; i < pos; i++)
        {
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s;
    }
    else
    {
        cout<<"Phan tu khong ton tai"<<endl;
    }
}
 
//Sap xep danh sach liet ket
void single_llist::sort()
{
    struct node *ptr, *s;
    int value;
    if (start == NULL)
    {
        cout<<"DS rong!"<<endl;
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->info > s->info)
            {
                value = ptr->info;
                ptr->info = s->info;
                s->info = value;
            }
        }
        ptr = ptr->next;
    }
}
 
//Delete node tai vi tri
void single_llist::delete_pos()
{
    int pos, i, counter = 0;
    if (start == NULL)
    {
        cout<<"DS rong!"<<endl;
        return;
    }
    cout<<"Nhap vi tri cua node muon xoa: ";
    cin>>pos;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"Phan tu khong ton tai"<<endl;
        }
        free(s);
        cout<<"Da xoa phan tu"<<endl;
    }
}
 
//Update node
void single_llist::update()
{
    int value, pos, i;
    if (start == NULL)
    {
        cout<<"DS rong!"<<endl;
        return;
    }
    cout<<"Nhap vi tri cua node muon update: ";
    cin>>pos;
    cout<<"Nhap gia tri moi: ";
    cin>>value;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start->info = value; 
    }
    else
    {
        for (i = 0;i < pos - 1;i++)
        {
            if (s == NULL)
            {
                cout<<"Co it hon "<<pos<<" phan tu";
                return;
            }
            s = s->next;
        }
        s->info = value;  
    }
    cout<<"Node Updated"<<endl;
} 
 
//Tim kiem
void single_llist::search()
{
    int value, pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"DS rong!"<<endl;
        return;
    }
    cout<<"Nhap gia tri cua node muon tim kiem: ";
    cin>>value;
    struct node *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->info == value)
        {
            flag = true;
            cout<<"Phan tu "<<value<<" thuoc vi tri thu "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Khong tim thay phan tu "<<value<<" trong danh sach"<<endl;  
}
 
//Dao nguoc DSLK
void single_llist::reverse()
{
    struct node *ptr1, *ptr2, *ptr3;
    if (start == NULL)
    {
        cout<<"DS rong!"<<endl;
        return;
    }
    if (start->next == NULL)
    {
        return;
    }  
    ptr1 = start;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;         
    }
    start = ptr2;
}
 
//Hien thi cac phan tu cua DSLK
void single_llist::display()
{
    struct node *temp;
    if (start == NULL)
    {
        cout<<"DS rong!"<<endl;
        return;
    }
    temp = start;
    cout<<"Cac phan tu cua DS la: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}