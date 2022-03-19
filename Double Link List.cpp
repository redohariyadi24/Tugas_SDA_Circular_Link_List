#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;
 
class double_list
{
    public:
        void buat_list(int value);
        void tambahkan_elemen(int value);
        void tambahkan_setelah(int value, int position);
        void hapus_elemen(int value);
        void tampilkan_list();
        double_llist()
        {
            start = NULL;  
        }
};
 

int main()
{
    int choice, element, position;
    double_list dl;
    while (1)
    {
        cout<<endl<<"\n**** Single Linked List ****"<<endl;        
        cout<<"1.Buat List"<<endl;
        cout<<"2.Tambahkan Data Baru"<<endl;
        cout<<"3.Tambahkan Data Baru setelah elemen tertentu"<<endl;
        cout<<"4.Hapus Elemen"<<endl;
        cout<<"5.Tampilkan List"<<endl;
        cout<<"6.Keluar"<<endl;
        cout<<"Masukkan pilihan anda : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Masukkan elemen: ";
            cin>>element;
            dl.buat_list(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Masukkan elemen: ";
            cin>>element;
            dl.tambahkan_elemen(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Masukkan elemen: ";
            cin>>element;
            cout<<"Masukkan elemen setelah posisi ke: ";
            cin>>position;
            dl.tambahkan_setelah(element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {                      
                cout<<"List sudah kosong"<<endl;   
                break;
            }
            cout<<"Masukkan elemen yang ingin dihapus: ";
            cin>>element;
            dl.hapus_elemen(element);
            cout<<endl;
            break;
        case 5:
            dl.tampilkan_list();
            cout<<endl;
            break;
        case 6:
            exit(1);
        default:
            cout<<"Pilihan yang anda dimasukkan salah"<<endl;
        }
    }
    return 0;
}
 
void double_list::buat_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node); 
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
 
void double_list::tambahkan_elemen(int value)
{
    if (start == NULL)
    {
        cout<<"List pertama yang dibuat"<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Elemen dimasukkan"<<endl;
}
 
void double_list::tambahkan_setelah (int value, int pos)
{
    if (start == NULL)
    {
        cout<<"List pertama yang dibuat"<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"Elemen sudah kurang dari ";
            cout<<pos<<" element."<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Elemen dimasukkan"<<endl;
}

void double_list::hapus_elemen(int value)
{
    struct node *tmp, *q;
    if (start->info == value)
    {
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Elemen terhapus"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {   
        if (q->next->info == value)  
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Elemen terhapus"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
    if (q->next->info == value)    
    { 	
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Elemen terhapus"<<endl;
        return;
    }
    cout<<"Elemen "<<value<<" tidak ditemukan"<<endl;
}
 
void double_list::tampilkan_list()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"List kosong, tidak ada yang bisa ditampilkan"<<endl;
        return;
    }
    q = start;
    cout<<"Double Link Listnya adalah :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}
 
