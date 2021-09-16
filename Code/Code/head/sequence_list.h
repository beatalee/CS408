#include <cstdio>
#include <cstdlib>
#include "head.h"

// ��̬˳���
typedef struct {
    element_type data[MAXSIZE];
    int length;
} StaticSequenceList;

// ��̬˳���
typedef struct {
    element_type *data;
    int max_size, length;
} DynamicSequenceList;

// ��ʼ��
bool InitSequenceList(StaticSequenceList &list) {
    list.length = 0;
    return true;
}

bool InitSequenceList(DynamicSequenceList &list) {
    list.length = 0;
    list.data = new element_type[MAXSIZE];
    list.max_size = MAXSIZE;
    return true;
}

// ��ӡ
template<class List>
bool PrintSequenceList(List list) {
    for (int i = 0; i < list.length; i++) {
        printf("��%d��Ԫ��ֵΪ%c\n", i + 1, list.data[i]);
    }
    return true;
}

// �������鳤��
bool IncreaseSequenceList(DynamicSequenceList &list, int length) {
    if (length <= 0) {
        printf("IncreaseSequenceList:����ռ�Ӧ�ô���0��\n");
        return false;
    }
    // ����һƬ�����Ĵ洢�ռ�
    int new_length = list.max_size + length;
    void *pointer = realloc(list.data, new_length * sizeof(element_type));
    if (pointer == nullptr) {
        printf("IncreaseSequenceList:����ʧ�ܣ�\n");
        return false;
    }
    return true;
}

// �п�
template<class List>
bool EmptySequenceList(List list) {
    return list.length == 0;
}

// ����
bool InsertSequenceList(StaticSequenceList &list, int index, element_type elem) {
    // ����̬˳����Ѿ����˾Ͳ��ܲ����κ�Ԫ��
    if (list.length >= MAXSIZE) {
        printf("InsertSequenceList:��̬˳����ռ䲻�㣬����ʧ�ܣ�\n");
        return false;
    }
    // ����λ�ô�0��ʼ�����Կ��Բ���ķ�Χ��0��list->length
    if (index > list.length || index < 0) {
        printf("InsertSequenceList:��������%d����������Χ��\n", index);
        return false;
    }
    // �����һ��Ԫ�ؿ�ʼ�������ƣ�list->length�ǿյ�
    for (int i = list.length; i > index; i--) {
        list.data[i] = list.data[i - 1];
    }
    list.data[index] = elem;
    list.length++;
    return true;
}

bool InsertSequenceList(DynamicSequenceList &list, int index, element_type elem) {
    if (index > list.length || index < 0) {
        printf("InsertDynamicSequenceList:��������%d����������Χ��\n", index);
        return false;
    }
    // ����̬˳����Ѿ����ˣ���Ҫ����һ��λ��
    // Ϊ�˱���������Ч��������һ���ռ䣬���Է��ڼ������ֵ�ĺ���
    if (list.length >= MAXSIZE) {
        bool result = IncreaseSequenceList(list, 1);
        if (!result) {
            printf("InsertDynamicSequenceList:����ռ�ʧ�ܣ�\n");
            return false;
        }
    }
    for (int i = list.length; i > index; i--) {
        list.data[i] = list.data[i - 1];
    }
    list.data[index] = elem;
    list.length++;
    return true;
}

// ѭ������
template<class List>
bool LoopInsertSequenceList(List &list, element_type *elem, int start, int end) {
    for (int i = 0; i < end; i++) {
        bool result = InsertSequenceList(list, i, elem[i + start]);
        if (!result) {
            printf("LoopInsertSequenceList:ѭ������ʧ�ܣ�\n");
            return false;
        }
    }
    return true;
}

// ɾ��
template<class List>
bool DeleteSequenceList(List &list, int index, element_type &elem) {
    if (index >= list.length || index < 0) {
        printf("DeleteStaticSequenceList:ɾ����������������Χ��\n");
        return false;
    }
    elem = list.data[index];
    for (int i = index; i < list.length; i++) {
        list.data[i] = list.data[i + 1];
    }
    list.length--;
    return true;
}

// ɾ�����Ԫ��
template<class List>
int MultiDeleteSequenceList(List &list, int index, int length, element_type *elem) {
    if (index + length >= list.length || index < 0) {
        printf("MultiDeleteSequenceList:ɾ����������������Χ��\n");
        return 1;
    }
    for (int i = index; i < list.length - length; i++) {
        if (i < index + length) {
            elem[i - index] = list.data[i];
        }
        list.data[i] = list.data[i + length];
    }
    list.length -= length;
    return 0;
}

// ��λ����˳���Ԫ��
template<class List>
element_type GetSequenceListElem(List list, int index) {
    if (index >= list.length || index < 0) {
        printf("GetSequenceListElement:��������%d����������Χ��\n", index);
        return DEFAULTELEM;
    }
    return list.data[index];
}

// ��ֵ����˳�������
template<class List>
int LocateSequenceList(List list, element_type elem) {
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == elem) {
            return i;
        }
    }
    printf("LocateSequenceListElement:δ�ܶ�λ����Ӧֵ%c��Ԫ�أ�\n", elem);
    return -1;
}

// ���ٶ�̬˳���
int DestroyDynamicSequenceList(DynamicSequenceList &list) {
    delete(list.data);
    return 0;
}


