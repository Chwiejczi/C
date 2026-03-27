#ifndef Tree_H
#define Tree_H

typedef struct TagTreeItem
{
	int key; //pola z informacj¹
	TagTreeItem* pLeft; 
	TagTreeItem* pRight; 

} TreeItem,*LP_TreeItem;

void inOrder( TreeItem* pRoot ); 
void postOrder( TreeItem* pRoot ); 
void preOrder( TreeItem* pRoot ); 
TreeItem* TreeFinalyBalanced( int n );//buduje drzewo dok³adnie wywa¿one z n elementow 
                                      //elementy wczytane z we 


//zwalnainie drzewa w postorder
void FreeTree1( TreeItem* pRoot );//nie nulluje drzewa
void FreeTree2( TreeItem** pRoot );
TreeItem* FreeTree3( TreeItem* pRoot ); 

void FindInsert( TreeItem** pRoot );//BST-binary search tree 
                                    //dla kazdego wêz³a na lewo sa mniejsze, a na prawo wieksze 
TreeItem* FindInsert2( TreeItem* pRoot,int x );

#endif 