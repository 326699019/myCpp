/***************************************************************************************************
a、二叉树中的面试题比较常见的题型大概有下面几个：
	1、创建一颗二叉树：（先序遍历、中序遍历、后序遍历）
	2、遍历一颗二叉树：（先序遍历、中序遍历、后序遍历、层序遍历）
	3、重建二叉树：
		1）由前序和中序重建二叉树；
		2）由后序和中序重建二叉树；
	4、判断树 B 是不是树 A 的子结构；
	5、二叉树的镜像；
	6、对称的二叉树；
	7、求二叉树的深度；
	8、平衡二叉树；
	9、二叉树的下一个结点：
		1）找出节点 T 在先序遍历顺序下的下一个结点；
		2）找出节点 T 在中序遍历顺序下的下一个结点；
		3）找出节点 T 在后序遍历顺序下的下一个结点；
	10、打印二叉树：
		1）不分行从上到下打印二叉树（就是层序遍历）；
		2）分行从上到下打印二叉树；
		3）之字形打印二叉树；
		4）广义表形式打印二叉树；
		5）树状结构打印二叉树；
	11、二叉搜索树的第 k 小的结点值：给定一棵二叉搜索树，请找出其中的第 k 小的结点值；
	12、判断输入数组是不是某二叉搜索树的后序遍历结果；

	18、序列化与反序列化二叉树：序列化是指遍历二叉树为字符串，反序列化是指依据字符串重新构造成二叉树；
	20、哈夫曼编码；
	13、二叉搜索树与双向链表：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表；
	3、求二叉树中叶子节点的个数；
	5、求二叉树中两个节点的最近公共祖先；
	6、打印二叉树中和为某一值的全部路径；
	7、求某一节点是否在一个树中；


b、常见的二叉树：
	1、完全二叉树（和堆联系比较紧密）
	2、满二叉树
	3、哈夫曼树：又称为最优树，带权路径长度最短的树。
	4、平衡二叉树：所谓平衡二叉树指的是，左右两个子树的高度差的绝对值不超过 1。
	5、红黑树：红黑树是每个节点都带颜色的树，节点颜色或是红色或是黑色，红黑树是一种查找树。
	6、二叉查找树：又称二叉搜索树、二叉排序树。
	   它或者是一棵空树，或者是具有下列性质的二叉树：
	   若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
	   若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
	   它的左、右子树也分别为二叉排序树;
	   二叉搜索树，按照中序遍历，遍历的数值是递增排序的；
*******************************************************************************************************/
#include "stdafx.h" 
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

typedef struct BiTreeNode							/* 结点结构 */
{
	char data;										/* 结点数据 */
	struct BiTreeNode *lchild, *rchild, *parent;		/* 左右孩子指针,parent 指针只在求节点的下一个节点时使用 */
}BiTreeNode, *BiTree;								//BiTree 为指向二叉树结点的指针

class BinaryTree
{
public:
	/* 构造空二叉树T */
	bool initBiTree(BiTree *T)
	{
		*T = NULL;
		return true;
	}
	bool biTreeEmpty(BiTree T)
	{
		return T == NULL ? true : false;
	}
	/* 按前序输入二叉树中结点的值（一个字符） */
	/* / 表示空树，构造二叉链表表示二叉树T。 */
	// 通过键盘输入创建整型二叉树，参见：https://blog.csdn.net/why850901938/article/details/51052936
	void createBiTreeByPreOrder(BiTree *T)
	{
		char ch;
		cin >> ch;
		if(ch == '/')
			*T = NULL;
		else
		{
			*T = new BiTreeNode;
			if(!*T)
				exit(OVERFLOW);
			/* 生成根结点 ,更改该语句的顺序，使用中序或后序方式构造二叉树，输入的字符也应该做调整；*/
			(*T)->data = ch;
			createBiTreeByPreOrder(&(*T)->lchild); /* 构造左子树 */
			createBiTreeByPreOrder(&(*T)->rchild); /* 构造右子树 */
		}
	}

	void createBiTreeByInOrder(BiTree *T)
	{
		char ch;
		cin >> ch;
		if(ch == '/')
			*T = NULL;
		else
		{
			*T = new BiTreeNode;
			if(!*T)
				exit(OVERFLOW);
			createBiTreeByInOrder(&(*T)->lchild); /* 构造左子树 */
			(*T)->data = ch;
			createBiTreeByInOrder(&(*T)->rchild); /* 构造右子树 */
		}
	}

	void createBiTreeByPostOrder(BiTree *T)
	{
		char ch;
		cin >> ch;
		if(ch == '/')
			*T = NULL;
		else
		{
			*T = new BiTreeNode;
			if(!*T)
				exit(OVERFLOW);
			createBiTreeByPostOrder(&(*T)->lchild); /* 构造左子树 */
			createBiTreeByPostOrder(&(*T)->rchild); /* 构造右子树 */
			(*T)->data = ch;
		}
	}

	/* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
	void destroyBiTree(BiTree *T)
	{
		if(*T)
		{
			if((*T)->lchild) /* 有左孩子 */
				destroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
			if((*T)->rchild) /* 有右孩子 */
				destroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
			free(*T); /* 释放根结点 */
			*T = NULL; /* 空指针赋0 */
		}
	}
	int biTreeDepthRecursion(BiTree T)
	{
		int left, right;
		if(T == NULL)
			return 0;										//空树深度为0 

		left = biTreeDepthRecursion(T->lchild);			//求左子树深度 
		right = biTreeDepthRecursion(T->rchild);			//求右子树深度 
		return (left >= right ? left : right) + 1;				//加1 是加上根节点这一层；
	}
	/* 非递归求树的深度：
   （1）当树非空时，将指针p指向根节点，p为当前节点指针。
   （2）将p压入栈S中，0压入栈tag中，并令p执行其左孩子。
   （3）重复步骤（2），直到p为空。
   （4）如果tag栈中的栈顶元素为1，跳至步骤（6）。从右子树返回
   （5）如果tag栈中的栈顶元素为0，跳至步骤（7）。从左子树返回
   （6）比较treedeep与栈的深度，取较大的赋给treedeep，对栈S和栈tag出栈操作，p指向NULL，并跳至步骤（8）。
   （7）将p指向栈S栈顶元素的右孩子，弹出栈tag，并把1压入栈tag。
   （8）循环（2）~（7），直到栈为空并且p为空
   （9）返回treedeep，结束遍历*/
	int biTreeDepthNonRecursion1(BiTree T)
	{
		int treedeep = 0;
		stack<BiTree> s;
		stack<int> tag;
		BiTree p = T;
		while(p || !s.empty())
		{
			while(p)
			{
				s.push(p);
				tag.push(0);
				p = p->lchild;
			}
			if(tag.top() == 1)
			{
				treedeep = treedeep > s.size() ? treedeep : s.size();
				s.pop();
				tag.pop();
				p = NULL;
			}
			else
			{
				p = s.top();
				p = p->rchild;
				tag.pop();
				tag.push(1);
			}
		}
		return treedeep;
	}
	/*每遍历一层，depth++;
	每一层，需使用一个变量 len 记录该层的结点个数，也就是队列的当前长度，
	然后依次将队列中 len 个元素出队列，并将下一层入队列。*/
	int biTreeDepthNonRecursion2(BiTree T)
	{
		queue<BiTree> q; // 使用队列；
		int depth = 0;
		if(!T)
			return 0;
		q.push(T);
		while(!q.empty())
		{
			int len = q.size();
			depth++;
			while(len--)
			{
				BiTree tem = q.front();
				q.pop();
				if(tem->lchild)
					q.push(tem->lchild);
				if(tem->rchild)
					q.push(tem->rchild);
			}
		}
		return depth;
	}
	/* 初始条件: 二叉树T存在 */
	/* 操作结果: 层序递归遍历T */
	void levelOrderTraverse(BiTree T) //也可以用队列实现；
	{
		int i, j;
		BiTree p[100];					//树指针数组
		i = j = 0;
		if(T)
			p[j++] = T;
		while(i < j)
		{
			cout << p[i]->data << " ";
			if(p[i]->lchild)
				p[j++] = p[i]->lchild;
			if(p[i]->rchild)
				p[j++] = p[i]->rchild;
			i++;
		}
	}
	/* 初始条件: 二叉树T存在 */
	/* 操作结果: 前序递归遍历T */
	void preOrderTraverseRecursion(BiTree T)
	{
		if(T == NULL)
			return;
		cout << T->data << " ";/* 显示结点数据，可以更改为其它对结点操作 */
		preOrderTraverseRecursion(T->lchild); /* 再先序遍历左子树 */
		preOrderTraverseRecursion(T->rchild); /* 最后先序遍历右子树 */
	}
	/* 非递归先序遍历算法基本思路：使用堆栈
　　a. 遇到一个节点，访问它，然后把它压栈，并去遍历它的左子树；
　　b. 当左子树遍历结束后，从栈顶弹出该节点并将其指向右儿子，继续a步骤；
　　c. 当所有节点访问完即最后访问的树节点为空且栈空时，停止。*/
	void preOrderTraverseNonRecursion(BiTree T)
	{
		BiTree p = T;
		stack<BiTree> s;
		while(p || !s.empty())
		{
			while(p != NULL)        //一直向左并将沿途节点访问（打印）后压入堆栈 
			{
				cout << p->data << " ";
				s.push(p);
				p = p->lchild;
			}
			if(!s.empty())
			{
				p = s.top();
				s.pop();		//节点弹出堆栈
				p = p->rchild;  //转向右子树
			}
		}
	}
	/* 初始条件: 二叉树T存在 */
	/* 操作结果: 中序递归遍历T */
	void inOrderTraverseRecursion(BiTree T)
	{
		if(T == NULL)
			return;
		inOrderTraverseRecursion(T->lchild); /* 中序遍历左子树 */
		cout << T->data << " ";				 /* 显示结点数据，可以更改为其它对结点操作 */
		inOrderTraverseRecursion(T->rchild); /* 最后中序遍历右子树 */
	}
	void inOrderTraverseNonRecursion(BiTree T) //左儿子-根节点-右儿子
	{
		BiTree p = T;
		stack<BiTree> s;
		while(p || !s.empty())
		{
			while(p != NULL)		//一直向左并将沿途节点压入堆栈
			{
				s.push(p);
				p = p->lchild;
			}
			if(!s.empty())
			{
				p = s.top();
				s.pop();
				cout << p->data << " ";
				p = p->rchild;
			}
		}
	}
	/* 初始条件: 二叉树T存在 */
	/* 操作结果: 后序递归遍历T */
	void postOrderTraverseRecursion(BiTree T)
	{
		if(T == NULL)
			return;
		postOrderTraverseRecursion(T->lchild); /* 先后序遍历左子树  */
		postOrderTraverseRecursion(T->rchild); /* 再后序遍历右子树  */
		cout << T->data << " ";/* 显示结点数据，可以更改为其它对结点操作 */
	}
	/*对于一个节点而言，要实现访问顺序为左儿子-右儿子-根节点，可以利用后进先出的栈，在节点不为空的前提下，依次将根节点，右儿子，左儿子压栈。故我们需要按照根节点-右儿子-左儿子的顺序遍历树，而我们已经知道先序遍历的顺序是根节点-左儿子-右儿子，故只需将先序遍历的左右调换并把访问方式打印改为压入另一个栈即可。最后一起打印栈中的元素。*/
	void postOrderTraverseNonRecursion(BiTree T) // 左儿子 - 右儿子 - 根节点
	{
		BiTree p = T;
		stack<BiTree> s1;
		stack<BiTree> s2;
		while(p || !s1.empty())
		{
			while(p != NULL)        //一直向右并将沿途节点访问（压入S2）后压入堆栈S1 
			{
				s2.push(p);
				s1.push(p);
				p = p->rchild;
			}
			if(!s1.empty())
			{
				p = s1.top();
				s1.pop();
				p = p->lchild;
			}
		}
		while(!s2.empty())    //访问（打印）S2中元素
		{
			p = s2.top();
			s2.pop();
			cout << p->data << " ";
		}
	}
	bool isTwoBiTreeEqual(BiTree T1, BiTree T2)
	{
		if(T1 == NULL && T2 == NULL)
			return true;
		if(T1 == NULL && T2 != NULL)
			return false;
		if(T1 != NULL && T2 == NULL)
			return false;
		if(T1->data == T2->data)
			return isTwoBiTreeEqual(T1->lchild, T2->lchild) && isTwoBiTreeEqual(T1->rchild, T2->rchild);
		else
			return false;
	}


	// 自上而下，重复遍历了节点多次；
	bool isBalanceBiTree(BiTree T)
	{
		if(T == NULL)
			return true;
		int left = biTreeDepthRecursion(T->lchild);			//求左子树深度 
		int right = biTreeDepthRecursion(T->rchild);		//求右子树深度 
		if(abs(left - right) > 1)
			return false;
		return isBalanceBiTree(T->lchild) && isBalanceBiTree(T->rchild);
	}

	// 后续遍历时，遍历到一个节点，其左右子树已经遍历  依次自底向上判断，每个节点只需要遍历一次
	bool isBalanceBiTree2(BiTree T)
	{
		getDepth(T);
		return isBance;
	}


	// 使二叉树变为其镜像；
	void getMirrorOfBiTree(BiTree T)
	{
		if(T == NULL)
			return;
		BiTree p = T->lchild; // 使用 p 指针暂时指向左孩子；
		T->lchild = T->rchild;	// T 的左指针指向右孩子；
		T->rchild = p; //T 的右孩子指向左孩子；
		getMirrorOfBiTree(T->lchild); // 递归；
		getMirrorOfBiTree(T->rchild);
	}

	// 判断二叉树是不是对称树；
	bool isBiTreeSymmetry(BiTree T)
	{
		if(T == NULL)
			return true; // 约定空树是对称树；
		return isSubTreeSymmetry(T->lchild, T->rchild); // 根节点不为空，判断子树是否对称；
	}



	// 由先序和中序遍历构建二叉树;
	BiTree reConstructBiTreeFromPreAndInOrder(char* preOrder, char* inOrder, int len)
	{
		if(len == 0)
			return NULL;
		BiTree p = new  BiTreeNode;
		p->data = *preOrder;

		int root = 0; // 全局；
		for(; root < len; root++)
		{
			if(inOrder[root] == *preOrder) // 找根节点；
				break;
		}
		p->lchild = reConstructBiTreeFromPreAndInOrder(preOrder + 1, inOrder, root);
		p->rchild = reConstructBiTreeFromPreAndInOrder(preOrder + root + 1, inOrder + root + 1, len - (root + 1));
		return p;
	}
	// 由先序和中序遍历直接写出后序遍历（不存储还原后的树）；
	void getPostOrderFromPreAndInOrder(char* preOrder, char* inOrder, int len)
	{
		if(len == 0)
			return;
		char nodeValue = *preOrder;
		int root = 0;
		for(; root < len; root++)
		{
			if(inOrder[root] == *preOrder)
				break;
		}
		//left
		getPostOrderFromPreAndInOrder(preOrder + 1, inOrder, root);
		//right
		getPostOrderFromPreAndInOrder(preOrder + root + 1, inOrder + root + 1, len - (root + 1));
		cout << nodeValue << ' ';
		return;
	}

	// 由后序和中序遍历构造二叉树；
	BiTree reConstructBiTreeFromPostAndInOrder(char* postOrder, char* inOrder, int len)
	{
		if(len == 0)
			return NULL;
		BiTree p = new  BiTreeNode;
		p->data = postOrder[len - 1]; //最后一个是根节点；

		int root = 0; // 全局；
		for(; root < len; root++)
		{
			if(inOrder[root] == postOrder[len - 1]) // 找根节点；
				break;
		}
		//left
		p->lchild = reConstructBiTreeFromPostAndInOrder(postOrder, inOrder, root);
		//right
		p->rchild = reConstructBiTreeFromPostAndInOrder(postOrder + root, inOrder + root + 1, len - (root + 1));
		return p;
	}

	// 由后序和中序遍历直接写出先序遍历（不存储还原后的树）；
	void getPreOrderFromPostAndInOrder(char* postOrder, char* inOrder, int len)
	{
		if(len == 0)
			return;
		char nodeValue = postOrder[len - 1];

		int root = 0;
		for(; root < len; root++)
		{
			if(inOrder[root] == postOrder[len - 1])
				break;
		}
		cout << nodeValue << ' ';
		//left
		getPreOrderFromPostAndInOrder(postOrder, inOrder, root);
		//right
		getPreOrderFromPostAndInOrder(postOrder + root, inOrder + root + 1, len - (root + 1));
		return;
	}

	// 二叉搜索树的第k小的结点值：给定一棵二叉搜索树，请找出其中的第k小的结点值；
	// 二叉搜索树的中序遍历序列是递增的,左-根-右；
	BiTree theKthSmallestNode(BiTree T, int k)
	{
		if(T == NULL || k == 0)
			return NULL;
		else
		{
			// int count=0; //count不能在本函数里初始化，因为每次都要递归调用函数自己；
			BiTree p;
			//left
			p = theKthSmallestNode(T->lchild, k);
			if(p)
				return p;
			//visit
			count++;
			if(count == k)
				return T;
			//right
			p = theKthSmallestNode(T->rchild, k);
			if(p)
				return p;
		}
		return NULL; // 函数最后一定要有返回值，不然会报错；
	}


	// 输出中序序列中节点 T 的下一个节点
	BiTree findNextNodeByInOrder(BiTree T)
	{
		if(T == NULL)
			return NULL;

		// case1: 右子树存在；
		if(T->rchild)
		{
			T = T->rchild;
			while(T->lchild)
				T = T->lchild;
			return T;
		}

		while(T->parent)
		{
			BiTree p = T->parent;
			if(p->lchild == T)  // 是父节点的左孩子节点；
				return p;
			else                // 是父节点的右孩子节点；
				T = T->parent;
		}
		return NULL;
	}

	// 判断输入序列是不是某二叉搜索树的后序遍历序列；
	bool verifySequenceOfBST(int* sequence, int len)
	{
		if(sequence == NULL || len <= 0)
			return false;
		int root = sequence[len - 1];

		// 二叉搜索树中，左子树结点的值小于根结点的值
		int i = 0;
		for(; i < len - 1; i++)
		{
			if(sequence[i] > root) // 从头开始找到第一个大于根节点的索引 i；
				break;
		}

		int j = i;
		for(; j < len - 1; j++) // 从第一个大于根结点的索引开始，后面的值除了最后一个根节点，其他的都比根节点大；
		{
			if(sequence[j] < root) // 若小于根结点，说明不是二叉搜索树的后序遍历序列；
				return false;
		}

		// 递归判断左右子序列是不是某二叉搜索树的后序遍历序列；
		bool left = true;
		if(i > 0)
			left = verifySequenceOfBST(sequence, i);

		bool right = true;
		if(i < len - 1)
			right = verifySequenceOfBST(sequence + i, len - i - 1);

		return (left && right);
	}


	// 二叉树中和为某一值的路径；
	void findPathInBiTree(BiTree T, int expectedSum)
	{
		if(T == NULL)
			return;
		vector<int> path;
		int currentSum = 0;
		findPath(T, expectedSum, path, currentSum);
	}

	// 把 二叉搜索树转化为 double linked list 双向链表
	BiTree convertBST2DLL(BiTree T)
	{
		BiTree pTail = NULL; // pTail 指向已经转化好的双向链表的最后一个结点；
		convertNode(T, &pTail);

		BiTree pHead = pTail; // 返回头结点；
		while(pHead != NULL && pHead->lchild != NULL)
			pHead = pHead->lchild;
		return pHead;
	}


	bool hasSubTree(BiTree A, BiTree B)
	{
		bool result;
		if(A != NULL && B != NULL) //当Tree1和Tree2都不为零的时候，才进行比较。否则直接返回false
		{
			if(A->data == B->data) //如果找到了对应Tree2的根节点的点
				result = doesTreeAContainTreeB(A, B); //以这个根节点为为起点判断是否包含Tree2
			if(!result)  //如果找不到，那么就再去root的左儿子当作起点，去判断时候包含Tree2
				result = hasSubTree(A->lchild, B);
			if(!result)  //如果还找不到，那么就再去root的右儿子当作起点，去判断时候包含Tree2
				result = hasSubTree(A->rchild, B);
		}
		return result;
	}

	// 由队列实现从上到下打印二叉树（就是层序遍历）；
	void printBiTreeFromTopToBottom1(BiTree T)
	{
		if(!T)
			return;

		queue<BiTree> q;
		q.push(T);

		BiTree f;
		while(q.size())
		{
			f = q.front(); // 指向队头结点；
			q.pop(); // 队头结点出队列；
			cout << f->data << ' ';

			if(f->lchild)
				q.push(f->lchild);
			if(f->rchild)
				q.push(f->rchild);
		}
	}

	// 分行从上到下打印二叉树；
	void printBiTreeFromTopToBottom2(BiTree T)
	{
		if(T == NULL)
			return;
		queue<BiTree> q;

		q.push(T);
		int nodesOfNextLevel = 0;
		int nodesToBePrintedThisLevel = 1;

		BiTree f;
		while(!q.empty())
		{
			f = q.front();
			cout << f->data << ' ';
			if(f->lchild != NULL)
			{
				q.push(f->lchild);
				nodesOfNextLevel++;
			}
			if(f->rchild != NULL)
			{
				q.push(f->rchild);
				nodesOfNextLevel++;
			}
			q.pop();
			nodesToBePrintedThisLevel--;
			if(nodesToBePrintedThisLevel == 0)
			{
				cout << '\n';
				nodesToBePrintedThisLevel = nodesOfNextLevel;
				nodesOfNextLevel = 0;
			}
		}
	}

	// 之字形打印二叉树；
	void printBiTreeByZType(BiTree T)
	{
		if(T == NULL)
			return;
		stack<BiTree> s[2]; // s0 处理奇数层，s1 处理偶数层；
		int current = 0;
		int next = 1;

		s[current].push(T);
		BiTree t;
		while(!s[0].empty() || !s[1].empty())
		{
			t = s[current].top();
			s[current].pop();

			cout << t->data << ' ';

			if(current == 0)
			{
				if(t->lchild != NULL)
					s[next].push(t->lchild);
				if(t->rchild != NULL)
					s[next].push(t->rchild);
			}
			else
			{
				if(t->rchild != NULL)
					s[next].push(t->rchild);
				if(t->lchild != NULL)
					s[next].push(t->lchild);
			}

			if(s[current].empty())
			{
				cout << '\n';
				current = 1 - current;
				next = 1 - next;
			}
		}


	}

	void printTreeByTreeForm(BiTree T)
	{
		int row, col;
		int i, j, m, l, r;
		BiTreeNode a[100][100] = {};					//用一个足够大的矩阵按原样存储树 
		if(T)
		{
			row = biTreeDepthRecursion(T);					//总行数
			col = pow(2, row) - 1;					//总列数
			for(i = 1; i <= row - 1; i++)
			{
				for(j = 1; j <= pow(2, i - 1); j++)
				{
					m = (2 * j - 1)*pow(2, row - i);		//当前行结点相对位序 
					l = (4 * j - 3)*pow(2, row - i - 1);	//下一行结点相对位序 
					r = (4 * j - 1)*pow(2, row - i - 1);
					if(i == 1)						//初始化 
						a[i][m] = *T;
					if(a[i][m].lchild)				//下一行 
						a[i + 1][l] = *(a[i][m].lchild);
					if(a[i][m].rchild)				//下一行 
						a[i + 1][r] = *(a[i][m].rchild);
				}
			}
			for(i = 1; i <= row; i++)
			{
				for(j = 1; j <= col; j++)
				{
					if(a[i][j].data)
						cout << a[i][j].data;
					else
						cout << "+";
				}
				cout << "\n";
			}
		}
	}

	void printTreeByGeneralizedTable(BiTree T)  //以括号表示法输出二叉树
	{
		if(T)
		{
			printf("%c", T->data);
			if(T->lchild != NULL || T->rchild != NULL)
			{
				printf("(");
				printTreeByGeneralizedTable(T->lchild);
				if(T->rchild != NULL)
					printf(",");
				printTreeByGeneralizedTable(T->rchild);
				printf(")");
			}
		}
	}


private:

	int count = 0; // theKthSmallestNode()函数的计数器；
	int isBance = true; // 判断平衡二叉树

	// 二叉搜索树转化为双向链表；
	void convertNode(BiTree T, BiTree* pTail)
	{
		if(T == NULL)
			return;
		BiTree pCurrent = T; // 当前指针指向根结点；

		// 先递归转化左子树；
		if(pCurrent->lchild != NULL)
			convertNode(pCurrent->lchild, pTail);  // 左子树转化完，尾指针指向左子树最大的结点，也就是书中的结点 8；

		pCurrent->lchild = *pTail;
		if(*pTail != NULL)
			(*pTail)->rchild = pCurrent;

		*pTail = pCurrent;

		if(pCurrent->rchild != NULL)
			convertNode(pCurrent->rchild, pTail);
	}

	void findPath(BiTree T, int expectedSum, vector<int>& path, int currentSum)
	{
		currentSum += T->data;
		path.push_back(T->data);

		bool isLeaf = (T->lchild == NULL && T->rchild == NULL);
		if(currentSum == expectedSum && isLeaf)
		{
			cout << "A path is found：";
			vector<int>::iterator iter = path.begin(); // 可以把迭代器理解为一个指针，指向了第一个元素；
			for(; iter != path.end(); iter++) // 指针一直向后移；
				cout << *iter << ' ';
			cout << '\n';
		}

		//先序遍历方式处理，最后处理左右子树；
		if(T->lchild != NULL)
			findPath(T->lchild, expectedSum, path, currentSum);
		if(T->rchild != NULL)
			findPath(T->rchild, expectedSum, path, currentSum);

		path.pop_back();
	}

	bool doesTreeAContainTreeB(BiTree A, BiTree B)
	{
		if(B == NULL) //如果Tree2已经遍历完了都能对应的上，返回true
			return true;
		if(A == NULL)   //如果Tree2还没有遍历完，Tree1却遍历完了。返回false
			return false;
		if(A->data != B->data)  //如果其中有一个点没有对应上，返回false
			return false;

		//如果根节点对应的上，那么就分别去子节点里面匹配
		return doesTreeAContainTreeB(A->lchild, B->lchild) && doesTreeAContainTreeB(A->rchild, B->rchild);
	}

	// 判断平衡二叉树
	int getDepth(BiTree T)
	{
		int left, right;
		if(T == NULL)
			return 0;										//空树深度为0 
		left = biTreeDepthRecursion(T->lchild);			//求左子树深度 
		right = biTreeDepthRecursion(T->rchild);			//求右子树深度 
		if(abs(left - right) > 1)
			isBance = false;
		return (left >= right ? left : right) + 1;				//加1 是加上根节点这一层；
	}

	// 判断二叉树是不是对称树；
	bool isSubTreeSymmetry(BiTree left, BiTree right)
	{
		if(left == NULL && right == NULL)
			return true;
		if(left != NULL && right != NULL)
			return     left->data == right->data \
			&& isSubTreeSymmetry(left->lchild, right->rchild) \
			&& isSubTreeSymmetry(left->rchild, right->lchild);
		else
			return false;
	}
};



int main()
{
	BinaryTree t;
	{
		//BiTree T;
		//cout << "初始化二叉树...\n";
		//t.initBiTree(&T);
		//cout << "判断二叉树是否为空...\n";
		//t.biTreeEmpty(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		//cout << "按先序序列创建二叉树...\n";
		//cout << "作为示范，录入先序序列：ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T);
		//cout << "\n按二叉树的结构打印树：T=\n";
		//t.printTreeByTreeForm(T);
		//cout << "\n递归法求树的深度：" << t.biTreeDepthRecursion(T);
		//cout << "\n非递归法求树的深度1：" << t.biTreeDepthNonRecursion1(T);
		//cout << "\n非递归法求树的深度2：" << t.biTreeDepthNonRecursion2(T);
		//cout << "\n层序遍历二叉树：";
		//t.levelOrderTraverse(T);
		//cout << "\n递归前序遍历二叉树：";
		//t.preOrderTraverseRecursion(T);
		//cout << "\n非递归前序遍历二叉树：";
		//t.preOrderTraverseNonRecursion(T);
		//cout << "\n递归中序遍历二叉树：";
		//t.inOrderTraverseRecursion(T);
		//cout << "\n非递归中序遍历二叉树：";
		//t.inOrderTraverseNonRecursion(T);
		//cout << "\n递归后序遍历二叉树：";
		//t.postOrderTraverseRecursion(T);
		//cout << "\n非递归后序遍历二叉树：";
		//t.postOrderTraverseNonRecursion(T);
		//cout << "\n销毁二叉树...\n";
		//t.destroyBiTree(&T);
		//if(t.biTreeEmpty(T))
		//cout << "T 已被清空!\n";
	}

	{
		//BiTree T1,T2;
		//t.initBiTree(&T1);
		//cout << "输入 T1 先序序列，如：ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T1);
		//t.printTreeByTreeForm(T1);

		//t.initBiTree(&T2);
		//cout << "输入 T2 先序序列，如：ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T2);
		//t.printTreeByTreeForm(T2);

		//if(t.isTwoBiTreeEqual(T1, T2))
		//	cout << "T1 和 T2 相等\n";
		//else
		//	cout << "T1 和 T2 不相等\n";


		//if(t.hasSubTree(T1,T2))
		//	cout << "T2 是 T1 的子树\n";
		//else
		//	cout << "T2 不是 T1 的子树\n";


		//t.destroyBiTree(&T1);
		//t.destroyBiTree(&T2);
	}

	{
		//BiTree T;
		//cout << "初始化二叉树...\n";
		//t.initBiTree(&T);
		//cout << "判断二叉树是否为空...\n";
		//t.biTreeEmpty(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		//cout << "按先序序列创建二叉树...\n";
		//cout << "作为示范，录入先序序列：ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T);
		//cout << "\n按二叉树的结构打印树：T=\n";
		//t.printTreeByTreeForm(T);

		//if(t.isBalanceBiTree2(T))
		//	cout<<"T 是平衡二叉树\n";
		//else
		//	cout<<"T 不是平衡二叉树\n";


		//t.getMirrorOfBiTree(T);
		//cout << "\n按二叉树的结构打印树的镜像：T'=\n";
		//t.printTreeByTreeForm(T);

		//if(t.isBiTreeSymmetry(T))
		//	cout<<"T 是对称二叉树\n";
		//else
		//	cout<<"T 不是对称二叉树\n";
	}

	{
		//BiTree	p;
		//
		//char* preOrder = "GDAFEMHZ";
		//char* inOrder  = "ADEFGHMZ";
		//char* postOrder = "AEFDHZMG";

		//cout << "由先序和中序序列构造二叉树......\n";
		//cout << "\n先序序列：" << preOrder << endl;
		//cout << "\n中序序列：" << inOrder << endl;
		//p = t.reConstructBiTreeFromPreAndInOrder(preOrder, inOrder, strlen(preOrder));
		//cout << "\n广义表表示法 ：" << endl;
		//t.printTreeByGeneralizedTable(p);
		//cout << "\n\n树状结构表示法 ：" << endl;
		//t.printTreeByTreeForm(p);
		//cout << "\n\n";

		//cout << "\n由先序和中序序列直接写出后序序列......\n";
		//t.getPostOrderFromPreAndInOrder(preOrder,inOrder,strlen(preOrder));
		//cout << "\n\n";


		//cout << "\n由后序和中序序列构造二叉树......\n";
		//cout << "\n后序序列：" << postOrder << endl;
		//cout << "\n中序序列：" << inOrder << endl;
		//p = t.reConstructBiTreeFromPostAndInOrder(postOrder, inOrder, strlen(inOrder));
		//cout << "\n广义表表示法 ：" << endl;
		//t.printTreeByGeneralizedTable(p);
		//cout << "\n\n树状结构表示法 ：" << endl;
		//t.printTreeByTreeForm(p);
		//cout << "\n\n";


		//cout << "\n由后序和中序序列直接写出先序序列......\n";
		//t.getPreOrderFromPostAndInOrder(postOrder,inOrder,strlen(inOrder));
		//cout << "\n\n";

		//t.destroyBiTree(&p);
	}


	// 二叉搜索树
	{
		BiTree T, p;
		cout << "初始化二叉树...\n";
		t.initBiTree(&T);
		cout << "判断二叉树是否为空...\n";
		t.biTreeEmpty(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		cout << "按先序序列创建二叉树...\n";
		cout << "构建二叉搜索树，示例：532//4//76//8//\n";
		t.createBiTreeByPreOrder(&T);
		cout << "\n按二叉树的结构打印树：T=\n";
		t.printTreeByTreeForm(T);

		int k = 3;
		p = t.theKthSmallestNode(T, k);
		cout << "二叉搜索树中第 " << k << " 小的节点的值：" << p->data << " \n\n";


		BiTree pNode = t.convertBST2DLL(T);
		cout << "The nodes from left to right are:\n";
		while(pNode != NULL)
		{
			cout << pNode->data << ' ';
			if(pNode->rchild == NULL)
				break;
			pNode = pNode->rchild;
		}
		cout << "\nThe nodes from right to left are:\n";
		while(pNode != NULL)
		{
			cout << pNode->data << ' ';
			if(pNode->lchild == NULL)
				break;
			pNode = pNode->lchild;
		}
		cout << "\n";
	}

	{
		//BiTree T, p1,p2,p3;
		//cout << "初始化二叉树...\n";
		//t.initBiTree(&T);
		//cout << "判断二叉树是否为空...\n";
		//t.biTreeEmpty(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		//cout << "按先序序列创建二叉树...\n";
		//cout << "构建二叉树，示例：124//5//36//7//\n";
		//t.createBiTreeByPreOrder(&T);
		//cout << "\n按二叉树的结构打印树：T=\n";
		//t.printTreeByTreeForm(T);


		//p1 = t.findNextNodeByInOrder(T);
		//p2 = T->rchild;
		//cout << "T 节点的值：" << T->data << " \n\n";
		//cout << "输出中序序列中节点 T 的下一个节点：" << p1->data << " \n\n";
		//cout << "p2 节点的值：" << p2->data << " \n\n";
		//p3 = t.findNextNodeByInOrder(p2);
		//cout << "输出中序序列中节点 p2 的下一个节点：" << p3->data << " \n\n";
	}

	{
		//BiTree T1,T2;

		//t.initBiTree(&T1);
		//cout << "输入 T1 先序序列，如：ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T1);
		//t.printTreeByTreeForm(T1);

		//cout << "\n从上到下打印二叉树 T1：\n" << endl;
		//t.printBiTreeFromTopToBottom1(T1);
		//cout << "\n\n";
		//t.printBiTreeFromTopToBottom2(T1);
		//cout << "\n\n";
		//t.printBiTreeByZType(T1);

		//t.initBiTree(&T2);
		//cout << "输入 T2 先序序列，如：ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T2);
		//t.printTreeByTreeForm(T2);


		//cout << "\n从上到下打印二叉树 T2：\n" << endl;
		//t.printBiTreeFromTopToBottom1(T2);
		//cout << "\n\n";
		//t.printBiTreeFromTopToBottom2(T2);
		//cout << "\n\n";
		//t.printBiTreeByZType(T2);
	}

	{
		//int sequence[] = {5,7,6,9,11,10,8};
		//int len = sizeof(sequence) / sizeof(sequence[0]);
		//
		//cout << "判断序列{5,7,6,9,11,10,8}是否为某二叉搜索树的后序遍历序列......\n\n";
		//if(t.verifySequenceOfBST(sequence, len))
		//	cout << "True\n\n";
		//else
		//	cout << "False\n\n";
	}

	{
		/* 注意：
		 1、结构体的 data 需要是int 型
		 2、通过键盘输入创建整型二叉树，需要更改：
			int ch;
			cin >> ch;
			if(ch == 0)
				*T = NULL;
		 参见：https://blog.csdn.net/why850901938/article/details/51052936  */

		 //BiTree T;
		 //cout << "初始化二叉树...\n";
		 //t.initBiTree(&T);
		 //cout << "判断二叉树是否为空...\n";
		 //t.biTreeEmpty(T) ? printf("T 为空！\n") : printf("T 不为空！\n");
		 //cout << "按先序序列创建二叉树...\n";
		 //cout << "作为示范，录入先序序列：221//4//3//\n";
		 //t.createBiTreeByPreOrder(&T);
		 //cout << "\n按二叉树的结构打印树：T=\n";
		 //t.printTreeByTreeForm(T);

		 //int sum = 3;
		 //cout << "输出和为 "<<sum<< " 的路径：\n\n";
		 //t.findPathInBiTree(T, sum);
	}
	system("pause");
	return 0;
}