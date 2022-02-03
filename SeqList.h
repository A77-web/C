#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_
#define _CRT_SECURE_NO_WARNINGS
#include"Common.h"
#define INC_SIZE 3
#define ElemType int//�����������
//���ݽṹ�Ķ���
typedef struct SeqList
{
	ElemType* base;
	size_t capacity;
	size_t size;
}SeqList;
//��������
bool _Inc(SeqList* pst);
bool _IsFull(SeqList* pst);
bool _IsEmpty(SeqList* pst);
void SeqlistInit(SeqList* pst, size_t capacity);
void SeqListPushBack(SeqList* pst, ElemType v);
void SeqListShow(SeqList* pst);
void SeqListPushFront(SeqList* pst, ElemType v);
void SeqListPopBack(SeqList* pst);
void SeqListPopFront(SeqList* pst);
void SeqListInsertByPos(SeqList* pst, int pos, ElemType v);
void SeqListInsertByVal(SeqList* pst, ElemType v);
void SeqListEraseByPos(SeqList* pst, int pos);
void SeqListEraseByVal(SeqList* pst, ElemType key);
ElemType SeqListFindByPos(SeqList* pst, int pos);
int SeqListFindByVal(SeqList* pst, ElemType key);
void SeqListSort(SeqList* pst);
void SeqListReverse(SeqList* pst);
size_t SeqListCapacity(SeqList* pst);
size_t SeqListLength(SeqList* pst);
void SeqListClear(SeqList* pst);
void SeqListDestroy(SeqList* pst);


//����ʵ��
bool _Inc(SeqList* pst)
{
	pst->base = (ElemType*)realloc(pst->base, sizeof(ElemType) * (pst->capacity + INC_SIZE));
	if (pst->base == NULL)
		return false;
	pst->capacity += INC_SIZE;
	return true;
}
bool _IsFull(SeqList* pst)
{
	return pst->size >= pst->capacity;
}
bool _IsEmpty(SeqList* pst)
{
	return pst->size == 0;
}
void SeqListInit(SeqList* pst, size_t capacity)
{
	pst->capacity = capacity;
	pst->base = (ElemType*)malloc(sizeof(ElemType) * pst->capacity);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType) * pst->capacity);
	pst->size = 0;
}
void SeqListPushBack(SeqList* pst, ElemType v)
{
	if (_IsFull(pst) && !_Inc(pst))
	{
		printf("˳����������ܲ���%d\n", v);
		return;
	}
	pst->base[pst->size++] = v;
}
void SeqListPushFront(SeqList* pst, ElemType v)
{
	if (_IsFull(pst) && !_Inc(pst))
	{
		printf("˳����������ܲ���%d\n", v);
		return;
	}
	for (int i = pst->size; i > 0; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[0] = v;
	pst->size++;
}
void SeqListPopBack(SeqList* pst)
{
	if (pst->size == 0)
	{
		printf("˳����ѿղ���ɾ��\n");
			return;
	}
	//ɾ������
	pst->size--;
}
void SeqListPopfront(SeqList* pst)
{

	if (pst->size == 0)
	{
		printf("˳����ѿղ���ɾ��\n");
		return;
	}
	for (int i = 0; i < pst->size - 1; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

void SeqListShow(SeqList* pst)
{
	for (int i = 0; i < pst->size; i++)
		printf("%d ", pst->base[i]);
	printf("\n");
}
void SeqListInsertByPos(SeqList* pst, int pos, ElemType v)
{
	if (_IsFull(pst) && !_Inc(pst))
	{
		printf("˳����������ܲ���%d\n", v);
		return;
	}
	if (pos<0 || pos>pst->size)
	{
		printf("�����λ�÷Ƿ��� %d ���ܲ���.\n", v);
		return;
	}
	for (int i = pst->size; i > pos; --i)
		pst->base[i] = pst->base[i - 1];
	pst->base[pos] = v;
	pst->size++;
}
void SeqListInsertByVal(SeqList* pst, ElemType v)
{
	int pos = 0;
	//����ҵ���λ�õ���ֵС��v pos++
	while (pos<pst->size && v>pst->base[pos])
		pos++;
	//���posλ�õ�ֵ����v ��v����
	SeqListInsertByPos(pst, pos, v);
}
void SeqListEraseByPos(SeqList* pst, int pos)
{
	//���λ��
	if (pos < 0 || pos >= pst->size)
	{
		printf("ɾ����λ�÷Ƿ�������ɾ������.\n");
		return;
	}

	//ɾ������
	for (int i = pos; i < pst->size - 1; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}
void SeqListEraseByVal(SeqList* pst, ElemType key)
{
	//���ҹؼ�ֵ
	int pos = SeqListFindByVal(pst, key);
	if (pos == -1)
	{
		printf("Ҫɾ�������ݲ�����.\n");
		return;
	}

	//ɾ������
	SeqListEraseByPos(pst, pos);
}

ElemType SeqListFindByPos(SeqList* pst, int pos)
{
	//���λ��
	assert(pos >= 0 && pos < pst->size);
	return pst->base[pos];
}
int SeqListFindByVal(SeqList* pst, ElemType key)
{
	for (int i = 0; i < pst->size; ++i)
	{
		if (key == pst->base[i])
		return i;
	}
	return -1;
}
void SeqListSort(SeqList* pst)
{
	for (int i = 0; i < pst->size - 1; i++)
	{
		bool is_swap = false;
		for (int j = 0; j < pst->size - 1 - i; j++)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				Swap(&(pst->base[j]), &(pst->base[j + 1]));
				is_swap = true;
			}
		}
		if (!is_swap)
			break;
	}
}
void SeqListReverse(SeqList* pst)
{
	int left = 0;
	int right = pst->size - 1;

	while (left < right)
	{
		Swap(&(pst->base[left]), &(pst->base[right]));
		left++;
		right--;
	}
}
size_t SeqListLength(SeqList* pst)
{
	return pst->size;
}
size_t SeqListCapacity(SeqList* pst)
{
	return pst->capacity;
}

void SeqListClear(SeqList* pst)
{
	pst->size = 0;
}
void SeqListDestroy(SeqList* pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}









#endif /*_SEQ_LIST_H_*/