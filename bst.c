#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
} NODE;

NODE*create(int ele){
    NODE *nn = malloc(sizeof(NODE));
    nn->data = ele;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

NODE*insert(NODE*root,int ele){
    if(root==NULL){
        return create(ele);
    }
    if(ele > root->data )
       root->right= insert(root->right, ele);
    else{
        root->left=insert(root->left, ele);
    }
    return root;
}

void preOrder(NODE*root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(NODE*root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void postOrder(NODE*root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

NODE*find_min(NODE*root){
    if(root==NULL){
      return NULL;    
    }
    else if (root->left!=NULL){
        return find_min(root->left);
    }
    return root;
}

NODE*search(NODE*root,int sElem){
    if(root==NULL){
        return NULL;
    }
    if(root->data == sElem){
        return root;
    }
    if(sElem > root->data){
        return search(root->right, sElem);
    }else{
        return search(root->left, sElem);
    }
}
NODE*delete(NODE*root,int ele){
    if(root==NULL){
        return NULL;
    }
    if(root->data > ele){
        root->left=delete(root->left, ele);
    }else if(root->data < ele){
        root->right=delete(root->right, ele);
    }else{
        if(root->left== NULL){
            NODE *temp = root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            NODE *temp = root->left;
            free(root);
            return temp;
        }else{
            NODE *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}
  

int main(){
    NODE*root=NULL;
    int ch, ele, pos;
    printf("BST Operations:");
    while (1){
        printf("\n1.Insert");
        printf("\n2.Search");
        printf("\n3.Delete");
        printf("\n4.Preorder");
        printf("\n5.Inorder");
        printf("\n6.Postorder");
        printf("\n7.Minimun Element");
        printf("\nEnter Choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("\nEnter Element:");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;
            case 2:
                printf("\nEnter Element to Search:");
                scanf("%d", &ele);
                 {
                    NODE* found = search(root, ele);
                    if (found)
                        printf("Element found: %d\n", found->data);
                    else
                        printf("Element not found\n");
                }
            case 3:
                printf("\nEnter Element to be Delete:");
                scanf("%d", &ele);
                root = delete(root,ele);
                printf("Deleted Element: %d", ele);
                break;
            case 4:
                printf("\nPreOrder Traversal:");
                preOrder(root);
                printf("\n ");
                break;
            case 5:
                printf("\nInorder Traversals:");
                inOrder(root);
                printf("\n ");
                break;
            case 6:
                printf("\nPostOrder Traversals:");
                postOrder(root);
                printf("\n ");
                break;
            case 7:
                {
                    NODE *minNode = find_min(root);
                    if(minNode != NULL){
                        printf("\nMinimum Number: %d", minNode->data);
                    }else{
                        printf("\nTree is empty");
                    }
                }
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid Choice");
        }
    }
    return 0;
}
    
    
    


