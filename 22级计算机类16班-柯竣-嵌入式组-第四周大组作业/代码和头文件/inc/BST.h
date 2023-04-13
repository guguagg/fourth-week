#pragma once
#include <cstddef>


#ifndef BST_H
#define BST_H


#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

typedef struct Node
{
    ElemType value;
    struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree 
{
    NodePtr root ;
} BinarySortTree, * BinarySortTreePtr;


/**   ��ʼ�����ڵ�
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr r);


/**  �����½ڵ�
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr r, ElemType v);


/**   ɾ���ڵ�
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr r, ElemType v);


/**   ���ҽڵ�
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr r, ElemType v);


/**       Ԥ�����  ���ݹ�
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr r, void (*visit)(NodePtr));


/**         �������  ���ݹ�
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr r, void (*visit)(NodePtr));


/**        �������  ���ݹ�
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr r, void (*visit)(NodePtr));


//����ڵ�����
void Tprint(NodePtr n);





#endif