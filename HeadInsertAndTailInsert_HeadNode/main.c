//
//  main.c
//  HeadInsertAndTailInsert_HeadNode
//
//  Created by chenyufeng on 16/3/1.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  使用头插法和尾插法来构建带头结点的单链表
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *next;
}Node;

//初始化带头结点的单链表
void InitialList(Node **pNode){

    //个人建议每一次malloc分配内存空间后，都要进行判断分配是否成功，也即判断是否为空；
    //此时的这个pNode就是一个头结点；
    //初始化成功后，其实相当于是一个正常的链表了；
    *pNode = (Node *)malloc(sizeof(Node));
    if (*pNode == NULL) {
        printf("%s函数执行，内存分配失败，初始化单链表失败",__FUNCTION__);
    }else{

        (*pNode)->next = NULL;
        printf("%s函数执行，带头结点的单链表初始化完成\n",__FUNCTION__);
    }
}

//创建带头结点的单链表（尾插法）
void CreateListTailInsert(Node *pNode){

    /**
     *  就算一开始输入的数字小于等于0，带头结点的单链表都是会创建成功的，只是这个单链表为空而已，也就是里面除了头结点就没有其他节点了。
     */
    Node *pInsert;
    Node *pMove;
    pInsert = (Node *)malloc(sizeof(Node));//需要检测分配内存是否成功 pInsert == NULL  ?
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pNode;
    while (pInsert->element > 0) {

        pMove->next = pInsert;
        pMove = pInsert;//pMove始终指向最后一个节点

        pInsert = (Node *)malloc(sizeof(Node)); //需要检测分配内存是否成功 pInsert == NULL  ?
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行,带头结点的单链表使用尾插法创建成功\n",__FUNCTION__);
}

//创建带头结点的单链表（头插法）
void CreateListHeadInsert(Node *pNode){

    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    while (pInsert->element > 0) {
        pInsert->next = pNode->next;
        pNode->next = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行，带头结点的单链表使用头插法创建成功\n",__FUNCTION__);
}

//打印带头结点的单链表
void PrintList(Node *pNode){
    /**
     *  注意这里，如果单链表为空（只有一个头结点），我也让它打印（打印成功）。只是里面没有元素，打出来是空的而已,所以在控制台上就是一行空的；
     */
    Node *pMove;
    pMove = pNode->next;
    while (pMove != NULL) {
        printf("%d ",pMove->element);
        pMove = pMove->next;
    }

    printf("\n%s函数执行，打印带头结点的单链表成功\n",__FUNCTION__);
}


int main(int argc, const char * argv[]) {

    Node *pList;

    InitialList(&pList);

    CreateListTailInsert(pList);
    PrintList(pList);

    CreateListHeadInsert(pList);
    PrintList(pList);

    return 0;
}

