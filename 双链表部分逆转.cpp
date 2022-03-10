#include <stdio.h>
#include <stdlib.h>
typedef struct line{
    struct line * prior;
    int data;
    struct line * next;
}line;
line *l[100] = {NULL};
line *r[100] = {NULL};
int size = 0;
//输出链表的功能函数,用于debug
void display(line * head){
    line * temp=head;
    while (temp) {
        if (temp->next==NULL) {
            printf("%d\n",temp->data);
        }else{
            printf("%d ",temp->data);
        }
        temp=temp->next;
    }
}
//左右语义已经发生了变化,此时左变成了右、右变成了左
void display2(line * head){
    line * temp=head;
    while (temp) {
        if (temp->prior==NULL) {
            printf("%d\n",temp->data);
        }else{
            printf("%d ",temp->data);
        }
        temp=temp->prior;
    }
}
//记录双链表分部后头尾数组,交换指针,最后左右定义反转即可,时间复杂度O(1)
void reverse_k(line *head,int k,int num){
    //若k==1,返回原链表即可
    if(k==1)
        ;
    line *p = head;
    int j = 0;
    for (int i = 0; i<num; i++) {
        if(i%k==0)
            l[j] = p;
        if(i%k==k-1||p->next==NULL)
            r[j++] = p;
        p = p->next;
    }
    // l,r指针数组有效长度
    size = j;
    r[0]->next = NULL;
    l[size-1]->prior = NULL;
    for (int i = 0; i<size-1; i++) {
        l[i]->prior = r[i+1];
        r[i+1]->next = l[i];
    }
}
int main() {
    int num;
    scanf("%d",&num);
    line * head;
    head=(line*)malloc(sizeof(line));
    head->prior=NULL;
    head->next=NULL;
    scanf("%d",&(head->data));
    line * list=head;
    for (int i = 0; i<num-1; i++) {
        line * body=(line*)malloc(sizeof(line));
        body->prior=NULL;
        body->next=NULL;
        scanf("%d",&(body->data));
        list->next=body;
        body->prior=list;
        list=list->next;
    }
    int k = 0;
    scanf("%d",&k);
    if(k==1)
        display(head);
    else{
        reverse_k(head, k, num);
        head = r[0];
        display2(r[0]);
    }
    return 0;
}
