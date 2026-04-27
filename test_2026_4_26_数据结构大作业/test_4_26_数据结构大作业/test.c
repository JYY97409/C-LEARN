#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128

typedef struct Book
{
    int id;
    char category[MAX_LEN];
    char title[MAX_LEN];
    char author[MAX_LEN];
    char isbn[MAX_LEN];
    char publisher[MAX_LEN];
    char pubDate[MAX_LEN];
    double price;
    int count;
    int borrowed;
    struct Book* next;
} Book;

Book* create_list(void)
{
    Book* head = (Book*)malloc(sizeof(Book));
    if (!head)
    {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    return head;
}

void trim_newline(char* s)
{
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') s[len - 1] = '\0';
}

void read_line(const char* prompt, char* buffer, size_t size)
{
    printf("%s", prompt);
    if (fgets(buffer, (int)size, stdin) == NULL)
    {
        buffer[0] = '\0';
        return;
    }
    trim_newline(buffer);
}

int read_int(const char* prompt)
{
    char buffer[MAX_LEN];
    read_line(prompt, buffer, sizeof(buffer));
    return atoi(buffer);
}

double read_double(const char* prompt)
{
    char buffer[MAX_LEN];
    read_line(prompt, buffer, sizeof(buffer));
    return atof(buffer);
}

Book* create_book(int id)
{
    Book* book = (Book*)malloc(sizeof(Book));
    if (!book)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    book->id = id;
    read_line("输入类别: ", book->category, MAX_LEN);
    read_line("输入书名: ", book->title, MAX_LEN);
    read_line("输入作者: ", book->author, MAX_LEN);
    read_line("输入ISBN: ", book->isbn, MAX_LEN);
    read_line("输入出版社: ", book->publisher, MAX_LEN);
    read_line("输入出版日期: ", book->pubDate, MAX_LEN);
    book->price = read_double("输入价格: ");
    book->count = read_int("输入册数: ");
    book->borrowed = 0;
    book->next = NULL;
    return book;
}

void append_book(Book* head, Book* book)
{
    Book* p = head;
    while (p->next) p = p->next;
    p->next = book;
}

Book* find_by_isbn(Book* head, const char* isbn)
{
    Book* p = head->next;
    while (p)
    {
        if (strcmp(p->isbn, isbn) == 0) return p;
        p = p->next;
    }
    return NULL;
}

Book* find_by_id(Book* head, int id)
{
    Book* p = head->next;
    while (p)
    {
        if (p->id == id) return p;
        p = p->next;
    }
    return NULL;
}

void print_book(const Book* book)
{
    if (!book) return;
    printf("%-4d %-10s %-20s %-15s %-15s %-15s %-12s %-8.2f %-4d %-4d\n",
        book->id, book->category, book->title, book->author,
        book->isbn, book->publisher, book->pubDate,
        book->price, book->count, book->borrowed);
}

void print_header(void)
{
    printf("ID   类别       书名                 作者            ISBN            出版社          出版日期     价格     册数 已借\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
}

void list_books(Book* head)
{
    Book* p = head->next;
    if (!p)
    {
        printf("当前无图书记录。\n");
        return;
    }
    print_header();
    while (p) {
        print_book(p);
        p = p->next;
    }
}

void list_books_by_condition(Book* head) {
    printf("1. 按类别查询\n");
    printf("2. 按书名查询\n");
    printf("3. 按作者查询\n");
    printf("4. 按出版社查询\n");
    printf("5. 按ISBN查询\n");
    int choice = read_int("请选择查询方式 (1-5): ");
    if (choice < 1 || choice > 5) {
        printf("无效的查询方式。\n");
        return;
    }
    char keyword[MAX_LEN];
    read_line("请输入查询关键词: ", keyword, MAX_LEN);
    if (strlen(keyword) == 0) {
        printf("关键词不能为空。\n");
        return;
    }
    Book* p = head->next;
    int found = 0;
    print_header();
    while (p) {
        int match = 0;
        if (choice == 1 && strstr(p->category, keyword)) match = 1;
        if (choice == 2 && strstr(p->title, keyword)) match = 1;
        if (choice == 3 && strstr(p->author, keyword)) match = 1;
        if (choice == 4 && strstr(p->publisher, keyword)) match = 1;
        if (choice == 5 && strstr(p->isbn, keyword)) match = 1;
        if (match) {
            print_book(p);
            found = 1;
        }
        p = p->next;
    }
    if (!found) printf("未找到匹配记录。\n");
}

void swap_books(Book* a, Book* b) {
    if (!a || !b) return;
    int id = a->id;
    char category[MAX_LEN], title[MAX_LEN], author[MAX_LEN], isbn[MAX_LEN], publisher[MAX_LEN], pubDate[MAX_LEN];
    double price = a->price;
    int count = a->count;
    int borrowed = a->borrowed;

    strcpy(category, a->category);
    strcpy(title, a->title);
    strcpy(author, a->author);
    strcpy(isbn, a->isbn);
    strcpy(publisher, a->publisher);
    strcpy(pubDate, a->pubDate);

    a->id = b->id;
    strcpy(a->category, b->category);
    strcpy(a->title, b->title);
    strcpy(a->author, b->author);
    strcpy(a->isbn, b->isbn);
    strcpy(a->publisher, b->publisher);
    strcpy(a->pubDate, b->pubDate);
    a->price = b->price;
    a->count = b->count;
    a->borrowed = b->borrowed;

    b->id = id;
    strcpy(b->category, category);
    strcpy(b->title, title);
    strcpy(b->author, author);
    strcpy(b->isbn, isbn);
    strcpy(b->publisher, publisher);
    strcpy(b->pubDate, pubDate);
    b->price = price;
    b->count = count;
    b->borrowed = borrowed;
}

void sort_books(Book* head) {
    if (!head->next || !head->next->next) {
        printf("记录太少，无需排序。\n");
        return;
    }
    printf("1. 按类别排序\n");
    printf("2. 按书名排序\n");
    printf("3. 按作者排序\n");
    printf("4. 按ISBN排序\n");
    int choice = read_int("请选择排序方式 (1-4): ");
    if (choice < 1 || choice > 4) {
        printf("无效的排序方式。\n");
        return;
    }
    Book* p, * q;
    for (p = head->next; p; p = p->next) {
        for (q = p->next; q; q = q->next) {
            int cmp = 0;
            if (choice == 1) cmp = strcmp(p->category, q->category);
            else if (choice == 2) cmp = strcmp(p->title, q->title);
            else if (choice == 3) cmp = strcmp(p->author, q->author);
            else cmp = strcmp(p->isbn, q->isbn);
            if (cmp > 0) swap_books(p, q);
        }
    }
    printf("排序完成。\n");
}

void insert_book(Book* head, int* nextId) {
    Book* book = create_book((*nextId)++);
    if (!book) return;
    append_book(head, book);
    printf("图书已插入，ID=%d。\n", book->id);
}

void delete_book(Book* head) {
    char isbn[MAX_LEN];
    read_line("请输入要删除图书的ISBN: ", isbn, MAX_LEN);
    if (strlen(isbn) == 0) {
        printf("ISBN不能为空。\n");
        return;
    }
    Book* prev = head;
    Book* p = head->next;
    while (p) {
        if (strcmp(p->isbn, isbn) == 0) {
            prev->next = p->next;
            free(p);
            printf("图书已删除。\n");
            return;
        }
        prev = p;
        p = p->next;
    }
    printf("未找到指定ISBN的图书。\n");
}

void modify_book(Book* head) {
    char isbn[MAX_LEN];
    read_line("请输入要修改图书的ISBN: ", isbn, MAX_LEN);
    Book* book = find_by_isbn(head, isbn);
    if (!book) {
        printf("未找到指定图书。\n");
        return;
    }
    printf("当前图书信息:\n");
    print_header();
    print_book(book);
    read_line("输入新类别（回车保持不变）: ", isbn, MAX_LEN);
    if (strlen(isbn) > 0) strcpy(book->category, isbn);
    read_line("输入新书名（回车保持不变）: ", isbn, MAX_LEN);
    if (strlen(isbn) > 0) strcpy(book->title, isbn);
    read_line("输入新作者（回车保持不变）: ", isbn, MAX_LEN);
    if (strlen(isbn) > 0) strcpy(book->author, isbn);
    read_line("输入新ISBN（回车保持不变）: ", isbn, MAX_LEN);
    if (strlen(isbn) > 0) strcpy(book->isbn, isbn);
    read_line("输入新出版社（回车保持不变）: ", isbn, MAX_LEN);
    if (strlen(isbn) > 0) strcpy(book->publisher, isbn);
    read_line("输入新出版日期（回车保持不变）: ", isbn, MAX_LEN);
    if (strlen(isbn) > 0) strcpy(book->pubDate, isbn);
    char buffer[MAX_LEN];
    read_line("输入新价格（回车保持不变）: ", buffer, MAX_LEN);
    if (strlen(buffer) > 0) book->price = atof(buffer);
    read_line("输入新册数（回车保持不变）: ", buffer, MAX_LEN);
    if (strlen(buffer) > 0) book->count = atoi(buffer);
    printf("修改完成。\n");
}

void borrow_book(Book* head) {
    char isbn[MAX_LEN];
    read_line("请输入要借阅图书的ISBN: ", isbn, MAX_LEN);
    Book* book = find_by_isbn(head, isbn);
    if (!book) {
        printf("未找到指定图书。\n");
        return;
    }
    if (book->borrowed >= book->count) {
        printf("该书已全部借出。\n");
        return;
    }
    book->borrowed++;
    printf("借阅成功。当前已借出 %d 本。\n", book->borrowed);
}

void return_book(Book* head) {
    char isbn[MAX_LEN];
    read_line("请输入要归还图书的ISBN: ", isbn, MAX_LEN);
    Book* book = find_by_isbn(head, isbn);
    if (!book) {
        printf("未找到指定图书。\n");
        return;
    }
    if (book->borrowed <= 0) {
        printf("当前没有借出的副本。\n");
        return;
    }
    book->borrowed--;
    printf("归还成功。当前已借出 %d 本。\n", book->borrowed);
}

void list_available_books(Book* head) {
    Book* p = head->next;
    int found = 0;
    print_header();
    while (p) {
        if (p->borrowed < p->count) {
            print_book(p);
            found = 1;
        }
        p = p->next;
    }
    if (!found) printf("当前没有可借图书。\n");
}

void list_borrowed_books(Book* head) {
    Book* p = head->next;
    int found = 0;
    print_header();
    while (p) {
        if (p->borrowed > 0) {
            print_book(p);
            found = 1;
        }
        p = p->next;
    }
    if (!found) printf("当前没有借出的图书。\n");
}

void count_by_author(Book* head) {
    char author[MAX_LEN];
    read_line("输入要统计的作者: ", author, MAX_LEN);
    if (strlen(author) == 0) {
        printf("作者名不能为空。\n");
        return;
    }
    Book* p = head->next;
    int total = 0;
    while (p) {
        if (strcmp(p->author, author) == 0) {
            total += p->count;
        }
        p = p->next;
    }
    printf("作者 '%s' 的图书总册数: %d\n", author, total);
}

void count_by_category(Book* head) {
    char category[MAX_LEN];
    read_line("输入要统计的类别: ", category, MAX_LEN);
    Book* p = head->next;
    int total = 0;
    while (p) {
        if (strcmp(p->category, category) == 0) {
            total += p->count;
        }
        p = p->next;
    }
    printf("类别 '%s' 的图书总册数: %d\n", category, total);
}

void save_to_file(Book* head, const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("文件无法打开: %s\n", filename);
        return;
    }
    Book* p = head->next;
    while (p) {
        fprintf(fp, "%d|%s|%s|%s|%s|%s|%s|%.2f|%d|%d\n",
            p->id, p->category, p->title, p->author,
            p->isbn, p->publisher, p->pubDate,
            p->price, p->count, p->borrowed);
        p = p->next;
    }
    fclose(fp);
    printf("已保存到文件: %s\n", filename);
}

int load_from_file(Book* head, const char* filename, int nextId) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        return nextId;
    }
    char line[512];
    while (fgets(line, sizeof(line), fp)) {
        trim_newline(line);
        Book* book = (Book*)malloc(sizeof(Book));
        if (!book) break;
        book->next = NULL;
        sscanf(line, "%d|%127[^|]|%127[^|]|%127[^|]|%127[^|]|%127[^|]|%127[^|]|%lf|%d|%d",
            &book->id, book->category, book->title, book->author,
            book->isbn, book->publisher, book->pubDate,
            &book->price, &book->count, &book->borrowed);
        append_book(head, book);
        if (book->id >= nextId) nextId = book->id + 1;
    }
    fclose(fp);
    return nextId;
}

void free_list(Book* head) {
    Book* p = head;
    while (p) {
        Book* next = p->next;
        free(p);
        p = next;
    }
}

int main(void) {
    Book* head = create_list();
    int nextId = 1;
    nextId = load_from_file(head, "books.txt", nextId);
    while (1) {
        printf("\n图书管理系统菜单:\n");
        printf("1. 新增图书\n");
        printf("2. 删除图书\n");
        printf("3. 修改图书\n");
        printf("4. 查询全部图书\n");
        printf("5. 条件查询图书\n");
        printf("6. 排序图书\n");
        printf("7. 借书\n");
        printf("8. 还书\n");
        printf("9. 按类别统计册数\n");
        printf("10. 查询可借图书\n");
        printf("11. 查询已借出图书\n");
        printf("12. 按作者统计册数\n");
        printf("0. 保存并退出\n");
        int choice = read_int("请选择操作: ");
        switch (choice) {
        case 1: insert_book(head, &nextId); break;
        case 2: delete_book(head); break;
        case 3: modify_book(head); break;
        case 4: list_books(head); break;
        case 5: list_books_by_condition(head); break;
        case 6: sort_books(head); break;
        case 7: borrow_book(head); break;
        case 8: return_book(head); break;
        case 9: count_by_category(head); break;
        case 10: list_available_books(head); break;
        case 11: list_borrowed_books(head); break;
        case 12: count_by_author(head); break;
        case 0:
            save_to_file(head, "books.txt");
            free_list(head);
            return 0;
        default:
            printf("无效选项，请重新选择。\n");
            break;
        }
    }
    return 0;
}