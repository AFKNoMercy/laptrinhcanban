#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char HoTen[201];
    int Tuoi;
    double DiemTB;
} SinhVien;

typedef struct Node
{
    SinhVien data;
    struct Node *next;
} Node;

Node *previous_node;

typedef struct
{
    Node *first;
    Node *last;
} Linkedlist;

Linkedlist* create_list()
{
    Linkedlist *list = (Linkedlist *)malloc(sizeof(Linkedlist));
    list->first = NULL;
    list->last = NULL;
    return list;
}

Node* create_node(SinhVien data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void add_first_node(Linkedlist *list, Node *node)
{
    list->first = node;
    list->last = node;
}

void insert_to_last(Linkedlist *list, Node *node)
{
    if (list->first == NULL)
    {
        add_first_node(list, node);
    }
    else
    {
        list->last->next = node;
        list->last = node;
    }
}

Node* search_node(Linkedlist *list, char HoTen[201])
{
    previous_node = NULL;
    Node *node = list->first;
    while(node != NULL)
    {
        if(strcmp(node->data.HoTen,HoTen)==0)
        {
            return node;
        }
        previous_node = node;
        node = node->next;
    }
    return NULL;
}

void insert_before(Linkedlist *list, char HoTen[201], Node *node)
{
    Node *found = search_node(list, HoTen);
    if (found != NULL)
    {
        if (found == list->first)
        {
            node->next = list->first;
            list->first = node;
        }
        else
        {
            previous_node->next = node;
            node->next = found;
        }
    }
    else
    {
        printf("Khong tim thay sinh vien: %s\n", HoTen);
    }
}


void delete_node(Linkedlist *list, char HoTen[201])
{
    Node *found = search_node(list,HoTen);
    if(found != NULL)
    {
        if(list->first == found)
        {
            list->first = found->next;
        }
        else if(list->last == found)
        {
            previous_node->next = NULL;
            list->last = previous_node;
        }
        else
        {
            previous_node->next = found->next;
        }
        free(found);
    }
    else
    {
        printf("Khong tim thay sinh vien: %s\n",HoTen);
    }
}


void input_SinhVien(SinhVien *SV)
{
    printf("Nhap ho ten sinh vien: ");
    fgets(SV->HoTen, 201, stdin);
    SV->HoTen[strcspn(SV->HoTen, "\n")] = '\0';

    printf("Nhap tuoi: ");
    scanf("%d", &SV->Tuoi);

    printf("Nhap diem trung binh: ");
    scanf("%lf", &SV->DiemTB);

    getchar();
}

void input_list(Linkedlist *list, int n)
{
    int i;
    Node *node;
    SinhVien SV_buffer;

    for (i = 0; i < n; i++)
    {
        printf("Sinh vien %d:\n", i + 1);
        input_SinhVien(&SV_buffer);
        node = create_node(SV_buffer);
        insert_to_last(list, node);
    }
}

void print_list(Linkedlist *list)
{
    int i = 1, total = 0;
    Node *node = list->first;
    printf("%5s %10s %10s %10s\n", "STT", "Ho ten", "Tuoi", "Diem TB");
    while (node != NULL)
    {
        printf("%5d %10s %10d %10.f\n", i++, node->data.HoTen, node->data.Tuoi, node->data.DiemTB);
        node = node->next;
    }
}

int main()
{
    int n;
    char HoTen[201];
    Linkedlist *list = create_list();
    printf("So luong sinh vien can nhap: ");
    scanf("%d", &n);
    getchar();
    input_list(list, n);
    print_list(list);

    printf("Nhap ten sinh vien can chen phia truoc: ");
    fgets(HoTen,201,stdin);
    HoTen[strcspn(HoTen,"\n")] = '\0';
    SinhVien new_SV;
    printf("Thong tin sinh vien can chen:\n");
    input_SinhVien(&new_SV);
    Node *node = create_node(new_SV);
    insert_before(list, HoTen, node);
    print_list(list);

    printf("Nhap ten sinh vien can xoa: ");
    fgets(HoTen,201,stdin);
    HoTen[strcspn(HoTen,"\n")] = '\0';
    delete_node(list,HoTen);
    print_list(list);

    return 0;
}
