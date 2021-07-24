#include <stdio.h>
#include <conio.h>
#define MaxLength 50
typedef int ElementType;
typedef int Position;

typedef struct List
{
    ElementType Elements[MaxLength];
    Position Last;
};

void MakeNullList(List &L)
{
    L.Last = 0;
}

int EmptyList(List L)
{
    return (L.Last == 0);
}

void InsertList(ElementType X, Position P, List &L)
{
    if (L.Last == MaxLength)
        printf("danh sach day roi!!\n");
    else if (P < 1 || P > L.Last + 1)
        printf("vi tri them k hop le!!\n");
    else
    {
        for (int i = L.Last; i >= P; i--)
            L.Elements[i] = L.Elements[i - 1];
        L.Elements[P - 1] = X;
        L.Last = L.Last + 1;
    }
}
void DeleteList(Position P, List &L)
{
    if (P >= 1 && P <= L.Last && !EmptyList(L))
    {
        for (int i = P - 1; i < L.Last - 1; i++)
            L.Elements[i] = L.Elements[i + 1];
        L.Last = L.Last - 1;
    }
}
ElementType Retrieve(Position P, List L)
{
    return L.Elements[P - 1];
}

Position Locate(ElementType X, List L)
{
    for (int i = 0; i < L.Last; i++)
    {
        if (L.Elements[i] == X)
            return i + 1;
    }
    return L.Last + 1;
}

void PrintList(List L)
{
    for (int i = 0; i < L.Last; i++)
        printf("%d  ", L.Elements[i]);
    printf("\n");
}
void swap(ElementType &a, ElementType &b)
{
    ElementType t = a;
    a = b;
    b = t;
}
void ReverseList(List &L)
{
    int n = L.Last - 1;
    int loop = L.Last / 2;
    for (int i = 0; i < loop; i++)
        swap(L.Elements[i], L.Elements[n - i]);
}
void SortList(List &L)
{
    int n = L.Last - 1;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (L.Elements[i] > L.Elements[j])
                swap(L.Elements[i], L.Elements[j]);
}
int main()
{
    List L;
    MakeNullList(L);

    InsertList(3, 1, L);
    InsertList(4, 1, L);
    InsertList(2, 2, L);
    InsertList(5, 3, L);
    InsertList(6, 2, L);
    InsertList(7, 1, L);
    InsertList(8, 2, L);
    InsertList(4, 2, L);
    InsertList(6, 3, L);
    InsertList(6, 2, L);
    PrintList(L);
    printf("Locate(3,L) = %d\n", Locate(3, L));
    printf("Retrieve(3,L) = %d\n", Retrieve(3, L));
    DeleteList(5, L);
    printf("Danh sach sau khi xoa phan tu o vi tri 5:\n");
    PrintList(L);
    printf("Danh sach sau khi xoa cac so 6:\n");
    while (Locate(6, L) != L.Last + 1)
        DeleteList(Locate(6, L), L);
    PrintList(L);
    ReverseList(L);
    printf("Danh sach sau khi dao: \n");
    PrintList(L);
    SortList(L);
    printf("Danh sach sau khi sap xep:\n");
    PrintList(L);
    return 0;
}