#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;


BTNode* BuyNode(BTDataType x);
BTNode* BinaryTreeCreate(BTDataType* a, int n);