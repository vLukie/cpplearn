堆,一种二叉树的表现形式

完全二叉树的节点数量范围：[pow(2,h-1),pow(2,h)-1]

h=log(2,n)

            0
        1       2
    1    4     5   6

parent=(child-1)/2;
leftchild=parent*2+1;
leftchild=parent*2+2;