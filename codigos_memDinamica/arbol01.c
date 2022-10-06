#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
	struct treeNode *leftPtr;
	int data;
	struct treeNode *rightPtr;
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;

void insertNode( TREENODEPTR *treePtr, int value );
void inOrder(TREENODEPTR);
void preOrder(TREENODEPTR);
void postOrder(TREENODEPTR);

int main( void ) {
	int i, item;
	TREENODEPTR rootPtr = NULL;

	srand(time(NULL));

	printf( "\n\nLos numeros que se colocaran en el arbol son: \n" );

	for( i = 1; i <= 20; i++ ) {
		item = rand() % 25;
		printf( "%3d", item);
	insertNode( &rootPtr, item);
	}

	/* Atravesando el arbol en preOrder */
	printf( "\n\nAtravensando en PreOrden:\n" );
	preOrder( rootPtr );

	/* Atravesando el arbol en InOrder */
	printf( "\n\nAtravensando en EnOrden:\n" );
	inOrder( rootPtr );

	/* Atravesando el arbol en PosOrder */
	printf( "\n\nAtravensando en PosOrden:\n" );
	postOrder( rootPtr );
	printf( "\n\n" );
	return 0;
}

void insertNode( TREENODEPTR *treePtr, int value ) {
	if( *treePtr == NULL ) {
		*treePtr = (TREENODEPTR) malloc( sizeof( TREENODE ) );
		if( *treePtr != NULL ) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else
			printf( "%d no fue insertado (Sin memoria) \n", value );
	}
	else
		if( value < (*treePtr)->data)
			insertNode(&((*treePtr)->leftPtr), value);
		else
			if( value > (*treePtr)->data)
				insertNode(&((*treePtr)->rightPtr), value);
			else
				printf( " dup" );
}

void inOrder( TREENODEPTR treePtr ) {
	if( treePtr != NULL ) {
		inOrder( treePtr->leftPtr);
		printf( "%3d", treePtr->data);
		inOrder( treePtr->rightPtr);
	}
}

void preOrder( TREENODEPTR treePtr ) {
	if( treePtr != NULL ) {
		printf( "%3d", treePtr->data);
		preOrder( treePtr->leftPtr);
		preOrder( treePtr->rightPtr);
	}
}

void postOrder( TREENODEPTR treePtr ) {
	if( treePtr != NULL ) {
		postOrder( treePtr->leftPtr);
		postOrder( treePtr->rightPtr);
		printf( "%3d", treePtr->data);
	}
}
