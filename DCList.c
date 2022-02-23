#include"DCList.h"
int main(int argc, char* argv[])
{
	//˳���
	//SeqList mylist;
	//SeqListInit(&mylist, 8);

	//������
	//List mylist;
	//ListInit(&mylist);

	//��ѭ������
	//SCList mylist;
	//SCListInit(&mylist);

	//˫ѭ������
	DCList mylist;
	DCListInit(&mylist);

	ElemType item, value, key;
	DCListNode* p = NULL;
	int pos;
	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1] push_back           [2] push_front   *\n");
		printf("* [3] show_list           [0] quit_system  *\n");
		printf("* [4] pop_back            [5] pop_front    *\n");
		printf("* [*6] insert_pos         [7] insert_val   *\n");
		printf("* [*8] erase_pos          [9] erase_val    *\n");
		printf("* [*10] find_pos          [11] find_val    *\n");
		printf("* [12] sort               [13] reverse     *\n");
		printf("* [14] length             [*15] capacity   *\n");
		printf("* [16] clear              [*17] destroy    *\n");
		printf("********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;

		switch (select)
		{
		case 1:
			printf("������Ҫ���������<��-1����>:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫ���������<��-1����>:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			//SeqListEraseByPos(&mylist, pos);
			break;
		case 9:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			DCListErase(&mylist, key);
			break;
		case 10:
			break;
		case 11:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = DCListFind(&mylist, key);
			if (p == NULL)
				printf("Ҫ���ҵ�%d���ݲ�����.\n", key);
			else
				printf("%d�����ѱ����ҵ�.\n", key);
			break;
		case 12:
			DCListSort(&mylist);
			break;
		case 13:
			DCListReverse(&mylist);
			break;
		case 14:
			printf("˫��ѭ������ĳ���Ϊ:> %d\n", DCListLength(&mylist));
			break;
		case 15:
			break;
		case 16:
			DCListClear(&mylist);
			break;
		default:
			break;
		}
	}

	DCListDestroy(&mylist);
	printf("GoodBye.\n");
	return 0;
}