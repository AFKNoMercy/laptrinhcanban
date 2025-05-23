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

Linkedlist *create_list()
{
    Linkedlist *list = (Linkedlist *)malloc(sizeof(Linkedlist));
    list->first = NULL;
    list->last = NULL;
    return list;
}

Node *create_node(HangHoa data)
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
    printf("%5s %10s %10s %10s %10s\n", "STT", "Ten Hang", "Don gia", "So luong", "Thanh tien");
    while (node != NULL)
    {
        printf("%5d %10s %10d %10d %10d\n", i++, node->data.TenHang, node->data.DonGia, node->data.SoLuong, node->data.ThanhTien);
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
        perror("Khong the mo file\n");
        return;
    }

    Node *node = list->first;
    while (node != NULL)
    {
        if (fwrite(&(node->data), sizeof(HangHoa), 1, output) != 1)
        {
            perror("Loi ghi du lieu\n");
            fclose(output);
            return;
        }
        node = node->next;
    }

    fclose(output);
    printf("Da ghi vao file nhi phan\n");
}

void write_text_file(Linkedlist *list, const char *filename)
{
    FILE *output = fopen(filename, "w");
    if (output == NULL)
    {
        perror("Khong the mo file\n");
        return;
    }
    int i = 1, total = 0;
    Node *node = list->first;
    fprintf(output, "%5s %10s %10s %10s %10s\n", "STT", "Ten Hang", "Don gia", "So luong", "Thanh tien");
    while (node != NULL)
    {
        fprintf(output, "%5d %10s %10d %10d %10d\n", i++, node->data.TenHang, node->data.DonGia, node->data.SoLuong, node->data.ThanhTien);
        total += node->data.ThanhTien;
        node = node->next;
    }
    fprintf(output, "%39s %10d\n", "Tong tien", total);

    fclose(output);
    printf("Da ghi vao file txt thanh cong\n");
}

void read_binary_file(const char *filename)
{
    FILE *input = fopen(filename, "rb");
    if (input == NULL)
    {
        perror("Không thể mở file");
        return;
    }

    HangHoa hang;
    int i = 1, total = 0;

    printf("%5s %10s %10s %10s %10s\n", "STT", "Tên Hàng", "Đơn Giá", "Số Lượng", "Thành Tiền");
    while (fread(&hang, sizeof(HangHoa), 1, input) == 1)
    {
        printf("%5d %10s %10d %10d %10d\n", i++, hang.TenHang, hang.DonGia, hang.SoLuong, hang.ThanhTien);
        total += hang.ThanhTien;
    }
    printf("%39s %10d\n", "Tổng Tiền", total);

    fclose(input);
    printf("Đã đọc file nhị phân thành công.\n");
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

    write_text_file(list, "output_3.txt");
    return 0;
}