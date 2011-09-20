#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
 
typedef struct treeNode* treeNodePtr;
struct treeNode{
        int data;
        treeNodePtr left;
        treeNodePtr right;
};
 
treeNodePtr findLCA(treeNodePtr root, int p, int q) {
 
        // no root no LCA.
        if(!root) {
                return NULL;
        }
 
 
        // if either p or q are direct child of root then root is LCA.
        if(root->data==p || root->data==q) {
                return root;
        } else {
                // get LCA of p and q in left subtree.
                treeNodePtr l=findLCA(root->left , p , q);
 
                // get LCA of p and q in right subtree.
                treeNodePtr r=findLCA(root->right , p, q);
 
                // if one of p or q is in leftsubtree and other is in right
                // then root it the LCA.
                if(l && r) {
                        return root;
                }
                // else if l is not null, l is LCA.
                else if(l) {
                        return l;
                } else {
                        return r;
                }
        }
}
 
treeNodePtr newNode(int data) {
        treeNodePtr newNode = malloc(sizeof(struct treeNode));
        if(!newNode) {
                fprintf(stderr,"Error allocating memory\n");
                exit(1);
        }
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
 
        return newNode;
}
 
int main() {
 
/*
                 5
                / \
               7   6
              /\   /\
             1  2 3  4
            /\
           0  8
*/
 
        treeNodePtr root = newNode(5);
        treeNodePtr tmp;
        root->left = newNode(7);
        root->right = newNode(6);
        root->left->left = newNode(1);
        root->left->right = newNode(2);
        root->right->left = newNode(3);
        root->right->right = newNode(4);
        root->left->left->left = newNode(0);
        root->left->left->right = newNode(8);
 
        int arr[] = {0,1,2,3,4,5,6,7,8};
        int size = sizeof(arr)/sizeof(*arr);
        int i,j;
 
        for(i=0;i<size;i++) {
                for(j=i+1;j<size;j++) {
                        tmp = findLCA(root,arr[i],arr[j]);
                        printf("LCA of %d %d is %d\n",arr[i],arr[j],tmp->data);
                }
        }
 
        return 0;
}
