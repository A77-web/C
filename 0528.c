#include <stdio.h>

void bubblingSort(int arr[], int n) {
    int i, j, temp;
    // ÿ�ν�һ��Ԫ���͵�ĩβ��n��Ԫ�أ�ִ��n��
    for (i = 0; i < n; ++i) {
        // ֮ǰ��ѭ���Ѿ���i��Ԫ���͵�ĩβ������Ҫ�ٴαȽϣ��ʼ�ȥ����Ϊ����һ��Ԫ�رȽϣ�Ϊ�˱���������ʼ�һ
        for (j = 0; j < n - i - 1; ++j) {
            // �����ǰ��Ԫ�رȺ�һ��Ԫ��С���ͽ���
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i;
    int arr[10] = { 5, 2, 3, 8, 1, 2, 6, 9, 3, 7 };
    bubblingSort(arr, 10);
    for (i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}