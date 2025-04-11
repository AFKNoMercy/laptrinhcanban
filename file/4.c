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

typedef struct
{
    Node *first;
    Node *last;
} Linkedlist;

Linkedlist *create_list()
{
    Linkedlist *list = (Linkedlist *)malloc(sizeof(Linkedlist));
    list->first = NULL;
    list->last = NULL;
    return list;
}

Node *create_node(SinhVien data)
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

Node *search_node(Linkedlist *list, char HoTen[201])
{
    Node *node = list->first;
    while (node != NULL)
    {
        if (strcmp(node->data.HoTen, HoTen) == 0)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
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
    int i = 1;
    Node *node = list->first;
    printf("%5s %20s %10s %10s\n", "STT", "Ho ten", "Tuoi", "Diem TB");
    while (node != NULL)
    {
        printf("%5d %20s %10d %10.2f\n", i++, node->data.HoTen, node->data.Tuoi, node->data.DiemTB);
        node = node->next;
    }
}

void write_binary_file(Linkedlist *list, const char *filename)
{
    FILE *output = fopen(filename, "wb");
    if (output == NULL)
    {
        perror("Khong the mo file");
        return;
    }

    Node *node = list->first;
    while (node != NULL)
    {
        if (fwrite(&(node->data), sizeof(SinhVien), 1, output) != 1)
        {
            perror("Loi ghi du lieu");
            fclose(output);
            return;
        }
        node = node->next;
    }

    fclose(output);
    printf("Da ghi vao file nhi phan");
}
void update_student(Linkedlist *list, char HoTen[201])
{
    Node *found = search_node(list, HoTen);
    if (found != NULL)
    {
        int choice;
        printf("1. Sua tuoi\n");
        printf("2. Sua diem trung binh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            printf("Nhap tuoi moi: ");
            scanf("%d", &found->data.Tuoi);
        }
        else if (choice == 2)
        {
            printf("Nhap diem trung binh moi: ");
            scanf("%lf", &found->data.DiemTB);
        }
        else
        {
            printf("Lua chon khong hop le.\n");
        }
    }
    else
    {
        printf("Khong tim thay sinh vien: %s\n", HoTen);
    }
}

void add_student_to_end(Linkedlist *list)
{
    SinhVien new_SV;
    printf("Nhap thong tin sinh vien can them:\n");
    input_SinhVien(&new_SV);
    Node *node = create_node(new_SV);
    insert_to_last(list, node);
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

    write_binary_file(list, "sinhvien.bin");

    printf("Nhap ten sinh vien can sua: ");
    fgets(HoTen, 201, stdin);
    HoTen[strcspn(HoTen, "\n")] = '\0';
    update_student(list, HoTen);
    print_list(list);

    add_student_to_end(list);
    print_list(list);

    write_binary_file(list, "sinhvien.bin");

    return 0;
}