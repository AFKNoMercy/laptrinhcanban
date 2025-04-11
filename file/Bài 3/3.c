#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char TenHang[201];
    int DonGia;
    int SoLuong;
    int ThanhTien;
} HangHoa;

typedef struct Node
{
    HangHoa data;
    struct Node *next;
} Node;

typedef struct
{
    Node *first;
    Node *last;
} Linkedlist;

Linkedlist* create_list()
{
    Linkedlist *list = (Linkedlist *)malloc(sizeof(Linkedlist));
    if (list == NULL)
    {
        perror("Không thể cấp phát bộ nhớ");
        exit(EXIT_FAILURE);
    }
    list->first = NULL;
    list->last = NULL;
    return list;
}

Node* create_node(HangHoa data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        perror("Không thể cấp phát bộ nhớ cho Node");
        exit(EXIT_FAILURE);
    }
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

void input_HangHoa(HangHoa *Hang)
{
    printf("Nhap ten hang: ");
    fgets(Hang->TenHang, 201, stdin);
    Hang->TenHang[strcspn(Hang->TenHang, "\n")] = '\0';

    printf("Nhap don gia: ");
    scanf("%d", &Hang->DonGia);

    printf("Nhap so luong: ");
    scanf("%d", &Hang->SoLuong);

    Hang->ThanhTien = Hang->SoLuong * Hang->DonGia;
    getchar();
}

void input_list(Linkedlist *list, int n)
{
    int i;
    Node *node;
    HangHoa Hang_buffer;

    for (i = 0; i < n; i++)
    {
        printf("Hang hoa %d:\n", i + 1);
        input_HangHoa(&Hang_buffer);
        node = create_node(Hang_buffer);
        insert_to_last(list, node);
    }
}

void print_list(Linkedlist *list)
{
    int i = 1, total = 0;
    Node *node = list->first;
    printf("%5s %10s %10s %10s  %10s\n", "STT", "Ten Hang", "Don gia", "So luong", "Thanh tien");
    while (node != NULL)
    {
        printf("%5d %10s %10d %-10d  %10d\n", i++, node->data.TenHang, node->data.DonGia, node->data.SoLuong, node->data.ThanhTien);
        total += node->data.ThanhTien;
        node = node->next;
    }
    printf("%39s %10d\n", "Tong tien", total);
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
        if (fwrite(&(node->data), sizeof(HangHoa), 1, output) != 1)
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

int main()
{
    int n;
    Linkedlist *list = create_list();

    printf("So loai hang can nhap: ");
    scanf("%d", &n);
    getchar();

    input_list(list, n);

    printf("\n=== Danh sach hang hoa ===\n");
    print_list(list);

    write_binary_file(list, "output_3.bin");

    return 0;
}