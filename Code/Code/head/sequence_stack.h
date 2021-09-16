#include <cstdio>
#include <cstdlib>
#include "head.h"

// ˳��ջ
typedef struct {
    // ջ��Ԫ��
    element_type data[MAXSIZE];
    // ջ��ָ��
    int top;
    // �������
    int max_size;
} SequenceStack;

// ��ʼ��
bool InitSequenceStack(SequenceStack &stack) {
    stack.top = -1;
    stack.max_size = MAXSIZE;
    return true;
}

// �п�
bool EmptySequenceStack(SequenceStack stack) {
    return stack.top == -1;
}

// ����
bool FullSequenceStack(SequenceStack stack) {
    return stack.top == stack.max_size - 1;
}

// ջ��
int LengthSequenceStack(SequenceStack stack) {
    return stack.top + 1;
}

// ��ջ
bool PushSequenceStack(SequenceStack &stack, element_type elem){
    if(FullSequenceStack(stack)){
        printf("PushSequenceStack:ջ���޷���ջ��\n");
        return false;
    }
    // ���Լ��ٽ�ջ
    stack.data[++stack.top] = elem;
    return true;
}

// ��ջ
element_type PopSequenceStack(SequenceStack &stack){
    if(EmptySequenceStack(stack)){
        printf("PopSequenceStack:ջ���޷���ջ��\n");
        return DEFAULTELEM;
    }
    // �ȳ�ջ���Լ�
    return stack.data[stack.top--];
}

// ��ջ��
element_type TopSequenceStack(SequenceStack stack){
    if(EmptySequenceStack(stack)){
        printf("TopSequenceStack:ջ���޷���ջ��Ԫ�أ�\n");
        return DEFAULTELEM;
    }
    return stack.data[stack.top];
}