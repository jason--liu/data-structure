#include "seqlist.h"

SequenList* lPtr;

SequenList* InitSeq()
{
    SequenList* pList = NULL;

    pList = (SequenList*)malloc(sizeof(SequenList));
    if (pList != NULL)
        pList->last = 0;

    return pList;
}

int GetSizeSeq(SequenList* pList)
{
    return pList->last;
}

int GetEleSqList(SequenList* pList, int pos, EleType* e)
{
    if (pos < 0 || pos > pList->last)
        return FALSE;

    if (pList->last <= 0)
        return FALSE;

    *e = pList->data[pos];
    return TRUE;
}

int LocateEleSqList(SequenList* pList, EleType key)
{
    int i;
    for (i = 0; i < pList->last; i++)
    {
        if (pList->data[i] == key)
            return i;
    }
    return -1;
}

int InsertEleSqList(SequenList* pList, EleType x, int pos)
{
    int j;
    if (pList->last >= LIST_SIZE - 1)
        return FALSE;

    if (pos < 0 || pos > pList->last)
        return FALSE;

    for (j = pList->last; j >= pos; j--)
    {
        pList->data[j + 1] = pList->data[j];
    }
    pList->data[pos] = x;
    pList->last++;
    return TRUE;
}

int DelEleSqList(SequenList* pList, int pos)
{
    int j;
    if ((pos >= 0 && pos <= pList->last) && (pList->last != 0))
    {
        for (j = pos; j <= pList->last; j++)
        {
            pList->data[j] = pList->data[j + 1];
        }
        pList->last--;
        return TRUE;
    }
    return FALSE;
}

void showSeqList(SequenList* pList)
{
    int i;
    for (i = 0; i < pList->last; i++)
        printf(" %d", pList->data[i]);
}

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    int ret = -1;
    lPtr    = InitSeq();
    int i;
    if (lPtr)
    {
        for (i = 0; i < 10; i++)
            InsertEleSqList(lPtr, i + 1, i);
    }
    printf("InitSeqList, lase=%d\n", lPtr->last);
    showSeqList(lPtr);
    printf("\n");
    printf("Insert 200 end\n");
    ret = InsertEleSqList(lPtr, 200, 9);
    if (!ret)
    {
        printf("Insert Error\n");
        return -1;
    }
    showSeqList(lPtr);
    printf("\n");

    printf("delete element\n");
    DelEleSqList(lPtr, 8);

    showSeqList(lPtr);
    printf("\n");

    return 0;
}
