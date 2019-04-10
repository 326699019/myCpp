/***************************************************************************************************
a���������е�������Ƚϳ��������ʹ�������漸����
	1������һ�Ŷ������������������������������������
	2������һ�Ŷ���������������������������������������������
	3���ؽ���������
		1����ǰ��������ؽ���������
		2���ɺ���������ؽ���������
	4���ж��� B �ǲ����� A ���ӽṹ��
	5���������ľ���
	6���ԳƵĶ�������
	7�������������ȣ�
	8��ƽ���������
	9������������һ����㣺
		1���ҳ��ڵ� T ���������˳���µ���һ����㣻
		2���ҳ��ڵ� T ���������˳���µ���һ����㣻
		3���ҳ��ڵ� T �ں������˳���µ���һ����㣻
	10����ӡ��������
		1�������д��ϵ��´�ӡ�����������ǲ����������
		2�����д��ϵ��´�ӡ��������
		3��֮���δ�ӡ��������
		4���������ʽ��ӡ��������
		5����״�ṹ��ӡ��������
	11�������������ĵ� k С�Ľ��ֵ������һ�ö��������������ҳ����еĵ� k С�Ľ��ֵ��
	12���ж����������ǲ���ĳ�����������ĺ�����������

	18�����л��뷴���л������������л���ָ����������Ϊ�ַ����������л���ָ�����ַ������¹���ɶ�������
	20�����������룻
	13��������������˫����������һ�ö��������������ö���������ת����һ�������˫������
	3�����������Ҷ�ӽڵ�ĸ�����
	5����������������ڵ������������ȣ�
	6����ӡ�������к�Ϊĳһֵ��ȫ��·����
	7����ĳһ�ڵ��Ƿ���һ�����У�


b�������Ķ�������
	1����ȫ���������Ͷ���ϵ�ȽϽ��ܣ�
	2����������
	3�������������ֳ�Ϊ����������Ȩ·��������̵�����
	4��ƽ�����������νƽ�������ָ���ǣ��������������ĸ߶Ȳ�ľ���ֵ������ 1��
	5����������������ÿ���ڵ㶼����ɫ�������ڵ���ɫ���Ǻ�ɫ���Ǻ�ɫ���������һ�ֲ�������
	6��������������ֳƶ�����������������������
	   ��������һ�ÿ����������Ǿ����������ʵĶ�������
	   ���������������գ��������������н���ֵ��С�����ĸ�����ֵ��
	   ���������������գ��������������н���ֵ���������ĸ�����ֵ��
	   ������������Ҳ�ֱ�Ϊ����������;
	   ���������������������������������ֵ�ǵ�������ģ�
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

typedef struct BiTreeNode							/* ���ṹ */
{
	char data;										/* ������� */
	struct BiTreeNode *lchild, *rchild, *parent;		/* ���Һ���ָ��,parent ָ��ֻ����ڵ����һ���ڵ�ʱʹ�� */
}BiTreeNode, *BiTree;								//BiTree Ϊָ�����������ָ��

class BinaryTree
{
public:
	/* ����ն�����T */
	bool initBiTree(BiTree *T)
	{
		*T = NULL;
		return true;
	}
	bool biTreeEmpty(BiTree T)
	{
		return T == NULL ? true : false;
	}
	/* ��ǰ������������н���ֵ��һ���ַ��� */
	/* / ��ʾ������������������ʾ������T�� */
	// ͨ���������봴�����Ͷ��������μ���https://blog.csdn.net/why850901938/article/details/51052936
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
			/* ���ɸ���� ,���ĸ�����˳��ʹ����������ʽ�����������������ַ�ҲӦ����������*/
			(*T)->data = ch;
			createBiTreeByPreOrder(&(*T)->lchild); /* ���������� */
			createBiTreeByPreOrder(&(*T)->rchild); /* ���������� */
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
			createBiTreeByInOrder(&(*T)->lchild); /* ���������� */
			(*T)->data = ch;
			createBiTreeByInOrder(&(*T)->rchild); /* ���������� */
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
			createBiTreeByPostOrder(&(*T)->lchild); /* ���������� */
			createBiTreeByPostOrder(&(*T)->rchild); /* ���������� */
			(*T)->data = ch;
		}
	}

	/* ��ʼ����: ������T���ڡ��������: ���ٶ�����T */
	void destroyBiTree(BiTree *T)
	{
		if(*T)
		{
			if((*T)->lchild) /* ������ */
				destroyBiTree(&(*T)->lchild); /* ������������ */
			if((*T)->rchild) /* ���Һ��� */
				destroyBiTree(&(*T)->rchild); /* �����Һ������� */
			free(*T); /* �ͷŸ���� */
			*T = NULL; /* ��ָ�븳0 */
		}
	}
	int biTreeDepthRecursion(BiTree T)
	{
		int left, right;
		if(T == NULL)
			return 0;										//�������Ϊ0 

		left = biTreeDepthRecursion(T->lchild);			//����������� 
		right = biTreeDepthRecursion(T->rchild);			//����������� 
		return (left >= right ? left : right) + 1;				//��1 �Ǽ��ϸ��ڵ���һ�㣻
	}
	/* �ǵݹ���������ȣ�
   ��1�������ǿ�ʱ����ָ��pָ����ڵ㣬pΪ��ǰ�ڵ�ָ�롣
   ��2����pѹ��ջS�У�0ѹ��ջtag�У�����pִ�������ӡ�
   ��3���ظ����裨2����ֱ��pΪ�ա�
   ��4�����tagջ�е�ջ��Ԫ��Ϊ1���������裨6����������������
   ��5�����tagջ�е�ջ��Ԫ��Ϊ0���������裨7����������������
   ��6���Ƚ�treedeep��ջ����ȣ�ȡ�ϴ�ĸ���treedeep����ջS��ջtag��ջ������pָ��NULL�����������裨8����
   ��7����pָ��ջSջ��Ԫ�ص��Һ��ӣ�����ջtag������1ѹ��ջtag��
   ��8��ѭ����2��~��7����ֱ��ջΪ�ղ���pΪ��
   ��9������treedeep����������*/
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
	/*ÿ����һ�㣬depth++;
	ÿһ�㣬��ʹ��һ������ len ��¼�ò�Ľ�������Ҳ���Ƕ��еĵ�ǰ���ȣ�
	Ȼ�����ν������� len ��Ԫ�س����У�������һ������С�*/
	int biTreeDepthNonRecursion2(BiTree T)
	{
		queue<BiTree> q; // ʹ�ö��У�
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
	/* ��ʼ����: ������T���� */
	/* �������: ����ݹ����T */
	void levelOrderTraverse(BiTree T) //Ҳ�����ö���ʵ�֣�
	{
		int i, j;
		BiTree p[100];					//��ָ������
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
	/* ��ʼ����: ������T���� */
	/* �������: ǰ��ݹ����T */
	void preOrderTraverseRecursion(BiTree T)
	{
		if(T == NULL)
			return;
		cout << T->data << " ";/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
		preOrderTraverseRecursion(T->lchild); /* ��������������� */
		preOrderTraverseRecursion(T->rchild); /* ���������������� */
	}
	/* �ǵݹ���������㷨����˼·��ʹ�ö�ջ
����a. ����һ���ڵ㣬��������Ȼ�����ѹջ����ȥ����������������
����b. �����������������󣬴�ջ�������ýڵ㲢����ָ���Ҷ��ӣ�����a���裻
����c. �����нڵ�����꼴�����ʵ����ڵ�Ϊ����ջ��ʱ��ֹͣ��*/
	void preOrderTraverseNonRecursion(BiTree T)
	{
		BiTree p = T;
		stack<BiTree> s;
		while(p || !s.empty())
		{
			while(p != NULL)        //һֱ���󲢽���;�ڵ���ʣ���ӡ����ѹ���ջ 
			{
				cout << p->data << " ";
				s.push(p);
				p = p->lchild;
			}
			if(!s.empty())
			{
				p = s.top();
				s.pop();		//�ڵ㵯����ջ
				p = p->rchild;  //ת��������
			}
		}
	}
	/* ��ʼ����: ������T���� */
	/* �������: ����ݹ����T */
	void inOrderTraverseRecursion(BiTree T)
	{
		if(T == NULL)
			return;
		inOrderTraverseRecursion(T->lchild); /* ������������� */
		cout << T->data << " ";				 /* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
		inOrderTraverseRecursion(T->rchild); /* ���������������� */
	}
	void inOrderTraverseNonRecursion(BiTree T) //�����-���ڵ�-�Ҷ���
	{
		BiTree p = T;
		stack<BiTree> s;
		while(p || !s.empty())
		{
			while(p != NULL)		//һֱ���󲢽���;�ڵ�ѹ���ջ
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
	/* ��ʼ����: ������T���� */
	/* �������: ����ݹ����T */
	void postOrderTraverseRecursion(BiTree T)
	{
		if(T == NULL)
			return;
		postOrderTraverseRecursion(T->lchild); /* �Ⱥ������������  */
		postOrderTraverseRecursion(T->rchild); /* �ٺ������������  */
		cout << T->data << " ";/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	}
	/*����һ���ڵ���ԣ�Ҫʵ�ַ���˳��Ϊ�����-�Ҷ���-���ڵ㣬�������ú���ȳ���ջ���ڽڵ㲻Ϊ�յ�ǰ���£����ν����ڵ㣬�Ҷ��ӣ������ѹջ����������Ҫ���ո��ڵ�-�Ҷ���-����ӵ�˳����������������Ѿ�֪�����������˳���Ǹ��ڵ�-�����-�Ҷ��ӣ���ֻ�轫������������ҵ������ѷ��ʷ�ʽ��ӡ��Ϊѹ����һ��ջ���ɡ����һ���ӡջ�е�Ԫ�ء�*/
	void postOrderTraverseNonRecursion(BiTree T) // ����� - �Ҷ��� - ���ڵ�
	{
		BiTree p = T;
		stack<BiTree> s1;
		stack<BiTree> s2;
		while(p || !s1.empty())
		{
			while(p != NULL)        //һֱ���Ҳ�����;�ڵ���ʣ�ѹ��S2����ѹ���ջS1 
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
		while(!s2.empty())    //���ʣ���ӡ��S2��Ԫ��
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


	// ���϶��£��ظ������˽ڵ��Σ�
	bool isBalanceBiTree(BiTree T)
	{
		if(T == NULL)
			return true;
		int left = biTreeDepthRecursion(T->lchild);			//����������� 
		int right = biTreeDepthRecursion(T->rchild);		//����������� 
		if(abs(left - right) > 1)
			return false;
		return isBalanceBiTree(T->lchild) && isBalanceBiTree(T->rchild);
	}

	// ��������ʱ��������һ���ڵ㣬�����������Ѿ�����  �����Ե������жϣ�ÿ���ڵ�ֻ��Ҫ����һ��
	bool isBalanceBiTree2(BiTree T)
	{
		getDepth(T);
		return isBance;
	}


	// ʹ��������Ϊ�侵��
	void getMirrorOfBiTree(BiTree T)
	{
		if(T == NULL)
			return;
		BiTree p = T->lchild; // ʹ�� p ָ����ʱָ�����ӣ�
		T->lchild = T->rchild;	// T ����ָ��ָ���Һ��ӣ�
		T->rchild = p; //T ���Һ���ָ�����ӣ�
		getMirrorOfBiTree(T->lchild); // �ݹ飻
		getMirrorOfBiTree(T->rchild);
	}

	// �ж϶������ǲ��ǶԳ�����
	bool isBiTreeSymmetry(BiTree T)
	{
		if(T == NULL)
			return true; // Լ�������ǶԳ�����
		return isSubTreeSymmetry(T->lchild, T->rchild); // ���ڵ㲻Ϊ�գ��ж������Ƿ�Գƣ�
	}



	// ������������������������;
	BiTree reConstructBiTreeFromPreAndInOrder(char* preOrder, char* inOrder, int len)
	{
		if(len == 0)
			return NULL;
		BiTree p = new  BiTreeNode;
		p->data = *preOrder;

		int root = 0; // ȫ�֣�
		for(; root < len; root++)
		{
			if(inOrder[root] == *preOrder) // �Ҹ��ڵ㣻
				break;
		}
		p->lchild = reConstructBiTreeFromPreAndInOrder(preOrder + 1, inOrder, root);
		p->rchild = reConstructBiTreeFromPreAndInOrder(preOrder + root + 1, inOrder + root + 1, len - (root + 1));
		return p;
	}
	// ��������������ֱ��д��������������洢��ԭ���������
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

	// �ɺ����������������������
	BiTree reConstructBiTreeFromPostAndInOrder(char* postOrder, char* inOrder, int len)
	{
		if(len == 0)
			return NULL;
		BiTree p = new  BiTreeNode;
		p->data = postOrder[len - 1]; //���һ���Ǹ��ڵ㣻

		int root = 0; // ȫ�֣�
		for(; root < len; root++)
		{
			if(inOrder[root] == postOrder[len - 1]) // �Ҹ��ڵ㣻
				break;
		}
		//left
		p->lchild = reConstructBiTreeFromPostAndInOrder(postOrder, inOrder, root);
		//right
		p->rchild = reConstructBiTreeFromPostAndInOrder(postOrder + root, inOrder + root + 1, len - (root + 1));
		return p;
	}

	// �ɺ�����������ֱ��д��������������洢��ԭ���������
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

	// �����������ĵ�kС�Ľ��ֵ������һ�ö��������������ҳ����еĵ�kС�Ľ��ֵ��
	// ������������������������ǵ�����,��-��-�ң�
	BiTree theKthSmallestNode(BiTree T, int k)
	{
		if(T == NULL || k == 0)
			return NULL;
		else
		{
			// int count=0; //count�����ڱ��������ʼ������Ϊÿ�ζ�Ҫ�ݹ���ú����Լ���
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
		return NULL; // �������һ��Ҫ�з���ֵ����Ȼ�ᱨ��
	}


	// ������������нڵ� T ����һ���ڵ�
	BiTree findNextNodeByInOrder(BiTree T)
	{
		if(T == NULL)
			return NULL;

		// case1: ���������ڣ�
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
			if(p->lchild == T)  // �Ǹ��ڵ�����ӽڵ㣻
				return p;
			else                // �Ǹ��ڵ���Һ��ӽڵ㣻
				T = T->parent;
		}
		return NULL;
	}

	// �ж����������ǲ���ĳ�����������ĺ���������У�
	bool verifySequenceOfBST(int* sequence, int len)
	{
		if(sequence == NULL || len <= 0)
			return false;
		int root = sequence[len - 1];

		// �����������У�����������ֵС�ڸ�����ֵ
		int i = 0;
		for(; i < len - 1; i++)
		{
			if(sequence[i] > root) // ��ͷ��ʼ�ҵ���һ�����ڸ��ڵ������ i��
				break;
		}

		int j = i;
		for(; j < len - 1; j++) // �ӵ�һ�����ڸ�����������ʼ�������ֵ�������һ�����ڵ㣬�����Ķ��ȸ��ڵ��
		{
			if(sequence[j] < root) // ��С�ڸ���㣬˵�����Ƕ����������ĺ���������У�
				return false;
		}

		// �ݹ��ж������������ǲ���ĳ�����������ĺ���������У�
		bool left = true;
		if(i > 0)
			left = verifySequenceOfBST(sequence, i);

		bool right = true;
		if(i < len - 1)
			right = verifySequenceOfBST(sequence + i, len - i - 1);

		return (left && right);
	}


	// �������к�Ϊĳһֵ��·����
	void findPathInBiTree(BiTree T, int expectedSum)
	{
		if(T == NULL)
			return;
		vector<int> path;
		int currentSum = 0;
		findPath(T, expectedSum, path, currentSum);
	}

	// �� ����������ת��Ϊ double linked list ˫������
	BiTree convertBST2DLL(BiTree T)
	{
		BiTree pTail = NULL; // pTail ָ���Ѿ�ת���õ�˫����������һ����㣻
		convertNode(T, &pTail);

		BiTree pHead = pTail; // ����ͷ��㣻
		while(pHead != NULL && pHead->lchild != NULL)
			pHead = pHead->lchild;
		return pHead;
	}


	bool hasSubTree(BiTree A, BiTree B)
	{
		bool result;
		if(A != NULL && B != NULL) //��Tree1��Tree2����Ϊ���ʱ�򣬲Ž��бȽϡ�����ֱ�ӷ���false
		{
			if(A->data == B->data) //����ҵ��˶�ӦTree2�ĸ��ڵ�ĵ�
				result = doesTreeAContainTreeB(A, B); //��������ڵ�ΪΪ����ж��Ƿ����Tree2
			if(!result)  //����Ҳ�������ô����ȥroot������ӵ�����㣬ȥ�ж�ʱ�����Tree2
				result = hasSubTree(A->lchild, B);
			if(!result)  //������Ҳ�������ô����ȥroot���Ҷ��ӵ�����㣬ȥ�ж�ʱ�����Tree2
				result = hasSubTree(A->rchild, B);
		}
		return result;
	}

	// �ɶ���ʵ�ִ��ϵ��´�ӡ�����������ǲ����������
	void printBiTreeFromTopToBottom1(BiTree T)
	{
		if(!T)
			return;

		queue<BiTree> q;
		q.push(T);

		BiTree f;
		while(q.size())
		{
			f = q.front(); // ָ���ͷ��㣻
			q.pop(); // ��ͷ�������У�
			cout << f->data << ' ';

			if(f->lchild)
				q.push(f->lchild);
			if(f->rchild)
				q.push(f->rchild);
		}
	}

	// ���д��ϵ��´�ӡ��������
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

	// ֮���δ�ӡ��������
	void printBiTreeByZType(BiTree T)
	{
		if(T == NULL)
			return;
		stack<BiTree> s[2]; // s0 ���������㣬s1 ����ż���㣻
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
		BiTreeNode a[100][100] = {};					//��һ���㹻��ľ���ԭ���洢�� 
		if(T)
		{
			row = biTreeDepthRecursion(T);					//������
			col = pow(2, row) - 1;					//������
			for(i = 1; i <= row - 1; i++)
			{
				for(j = 1; j <= pow(2, i - 1); j++)
				{
					m = (2 * j - 1)*pow(2, row - i);		//��ǰ�н�����λ�� 
					l = (4 * j - 3)*pow(2, row - i - 1);	//��һ�н�����λ�� 
					r = (4 * j - 1)*pow(2, row - i - 1);
					if(i == 1)						//��ʼ�� 
						a[i][m] = *T;
					if(a[i][m].lchild)				//��һ�� 
						a[i + 1][l] = *(a[i][m].lchild);
					if(a[i][m].rchild)				//��һ�� 
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

	void printTreeByGeneralizedTable(BiTree T)  //�����ű�ʾ�����������
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

	int count = 0; // theKthSmallestNode()�����ļ�������
	int isBance = true; // �ж�ƽ�������

	// ����������ת��Ϊ˫������
	void convertNode(BiTree T, BiTree* pTail)
	{
		if(T == NULL)
			return;
		BiTree pCurrent = T; // ��ǰָ��ָ�����㣻

		// �ȵݹ�ת����������
		if(pCurrent->lchild != NULL)
			convertNode(pCurrent->lchild, pTail);  // ������ת���꣬βָ��ָ�����������Ľ�㣬Ҳ�������еĽ�� 8��

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
			cout << "A path is found��";
			vector<int>::iterator iter = path.begin(); // ���԰ѵ��������Ϊһ��ָ�룬ָ���˵�һ��Ԫ�أ�
			for(; iter != path.end(); iter++) // ָ��һֱ����ƣ�
				cout << *iter << ' ';
			cout << '\n';
		}

		//���������ʽ�������������������
		if(T->lchild != NULL)
			findPath(T->lchild, expectedSum, path, currentSum);
		if(T->rchild != NULL)
			findPath(T->rchild, expectedSum, path, currentSum);

		path.pop_back();
	}

	bool doesTreeAContainTreeB(BiTree A, BiTree B)
	{
		if(B == NULL) //���Tree2�Ѿ��������˶��ܶ�Ӧ���ϣ�����true
			return true;
		if(A == NULL)   //���Tree2��û�б����꣬Tree1ȴ�������ˡ�����false
			return false;
		if(A->data != B->data)  //���������һ����û�ж�Ӧ�ϣ�����false
			return false;

		//������ڵ��Ӧ���ϣ���ô�ͷֱ�ȥ�ӽڵ�����ƥ��
		return doesTreeAContainTreeB(A->lchild, B->lchild) && doesTreeAContainTreeB(A->rchild, B->rchild);
	}

	// �ж�ƽ�������
	int getDepth(BiTree T)
	{
		int left, right;
		if(T == NULL)
			return 0;										//�������Ϊ0 
		left = biTreeDepthRecursion(T->lchild);			//����������� 
		right = biTreeDepthRecursion(T->rchild);			//����������� 
		if(abs(left - right) > 1)
			isBance = false;
		return (left >= right ? left : right) + 1;				//��1 �Ǽ��ϸ��ڵ���һ�㣻
	}

	// �ж϶������ǲ��ǶԳ�����
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
		//cout << "��ʼ��������...\n";
		//t.initBiTree(&T);
		//cout << "�ж϶������Ƿ�Ϊ��...\n";
		//t.biTreeEmpty(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		//cout << "���������д���������...\n";
		//cout << "��Ϊʾ����¼���������У�ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T);
		//cout << "\n���������Ľṹ��ӡ����T=\n";
		//t.printTreeByTreeForm(T);
		//cout << "\n�ݹ鷨��������ȣ�" << t.biTreeDepthRecursion(T);
		//cout << "\n�ǵݹ鷨���������1��" << t.biTreeDepthNonRecursion1(T);
		//cout << "\n�ǵݹ鷨���������2��" << t.biTreeDepthNonRecursion2(T);
		//cout << "\n���������������";
		//t.levelOrderTraverse(T);
		//cout << "\n�ݹ�ǰ�������������";
		//t.preOrderTraverseRecursion(T);
		//cout << "\n�ǵݹ�ǰ�������������";
		//t.preOrderTraverseNonRecursion(T);
		//cout << "\n�ݹ����������������";
		//t.inOrderTraverseRecursion(T);
		//cout << "\n�ǵݹ����������������";
		//t.inOrderTraverseNonRecursion(T);
		//cout << "\n�ݹ���������������";
		//t.postOrderTraverseRecursion(T);
		//cout << "\n�ǵݹ���������������";
		//t.postOrderTraverseNonRecursion(T);
		//cout << "\n���ٶ�����...\n";
		//t.destroyBiTree(&T);
		//if(t.biTreeEmpty(T))
		//cout << "T �ѱ����!\n";
	}

	{
		//BiTree T1,T2;
		//t.initBiTree(&T1);
		//cout << "���� T1 �������У��磺ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T1);
		//t.printTreeByTreeForm(T1);

		//t.initBiTree(&T2);
		//cout << "���� T2 �������У��磺ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T2);
		//t.printTreeByTreeForm(T2);

		//if(t.isTwoBiTreeEqual(T1, T2))
		//	cout << "T1 �� T2 ���\n";
		//else
		//	cout << "T1 �� T2 �����\n";


		//if(t.hasSubTree(T1,T2))
		//	cout << "T2 �� T1 ������\n";
		//else
		//	cout << "T2 ���� T1 ������\n";


		//t.destroyBiTree(&T1);
		//t.destroyBiTree(&T2);
	}

	{
		//BiTree T;
		//cout << "��ʼ��������...\n";
		//t.initBiTree(&T);
		//cout << "�ж϶������Ƿ�Ϊ��...\n";
		//t.biTreeEmpty(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		//cout << "���������д���������...\n";
		//cout << "��Ϊʾ����¼���������У�ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T);
		//cout << "\n���������Ľṹ��ӡ����T=\n";
		//t.printTreeByTreeForm(T);

		//if(t.isBalanceBiTree2(T))
		//	cout<<"T ��ƽ�������\n";
		//else
		//	cout<<"T ����ƽ�������\n";


		//t.getMirrorOfBiTree(T);
		//cout << "\n���������Ľṹ��ӡ���ľ���T'=\n";
		//t.printTreeByTreeForm(T);

		//if(t.isBiTreeSymmetry(T))
		//	cout<<"T �ǶԳƶ�����\n";
		//else
		//	cout<<"T ���ǶԳƶ�����\n";
	}

	{
		//BiTree	p;
		//
		//char* preOrder = "GDAFEMHZ";
		//char* inOrder  = "ADEFGHMZ";
		//char* postOrder = "AEFDHZMG";

		//cout << "��������������й��������......\n";
		//cout << "\n�������У�" << preOrder << endl;
		//cout << "\n�������У�" << inOrder << endl;
		//p = t.reConstructBiTreeFromPreAndInOrder(preOrder, inOrder, strlen(preOrder));
		//cout << "\n������ʾ�� ��" << endl;
		//t.printTreeByGeneralizedTable(p);
		//cout << "\n\n��״�ṹ��ʾ�� ��" << endl;
		//t.printTreeByTreeForm(p);
		//cout << "\n\n";

		//cout << "\n���������������ֱ��д����������......\n";
		//t.getPostOrderFromPreAndInOrder(preOrder,inOrder,strlen(preOrder));
		//cout << "\n\n";


		//cout << "\n�ɺ�����������й��������......\n";
		//cout << "\n�������У�" << postOrder << endl;
		//cout << "\n�������У�" << inOrder << endl;
		//p = t.reConstructBiTreeFromPostAndInOrder(postOrder, inOrder, strlen(inOrder));
		//cout << "\n������ʾ�� ��" << endl;
		//t.printTreeByGeneralizedTable(p);
		//cout << "\n\n��״�ṹ��ʾ�� ��" << endl;
		//t.printTreeByTreeForm(p);
		//cout << "\n\n";


		//cout << "\n�ɺ������������ֱ��д����������......\n";
		//t.getPreOrderFromPostAndInOrder(postOrder,inOrder,strlen(inOrder));
		//cout << "\n\n";

		//t.destroyBiTree(&p);
	}


	// ����������
	{
		BiTree T, p;
		cout << "��ʼ��������...\n";
		t.initBiTree(&T);
		cout << "�ж϶������Ƿ�Ϊ��...\n";
		t.biTreeEmpty(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		cout << "���������д���������...\n";
		cout << "����������������ʾ����532//4//76//8//\n";
		t.createBiTreeByPreOrder(&T);
		cout << "\n���������Ľṹ��ӡ����T=\n";
		t.printTreeByTreeForm(T);

		int k = 3;
		p = t.theKthSmallestNode(T, k);
		cout << "�����������е� " << k << " С�Ľڵ��ֵ��" << p->data << " \n\n";


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
		//cout << "��ʼ��������...\n";
		//t.initBiTree(&T);
		//cout << "�ж϶������Ƿ�Ϊ��...\n";
		//t.biTreeEmpty(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		//cout << "���������д���������...\n";
		//cout << "������������ʾ����124//5//36//7//\n";
		//t.createBiTreeByPreOrder(&T);
		//cout << "\n���������Ľṹ��ӡ����T=\n";
		//t.printTreeByTreeForm(T);


		//p1 = t.findNextNodeByInOrder(T);
		//p2 = T->rchild;
		//cout << "T �ڵ��ֵ��" << T->data << " \n\n";
		//cout << "������������нڵ� T ����һ���ڵ㣺" << p1->data << " \n\n";
		//cout << "p2 �ڵ��ֵ��" << p2->data << " \n\n";
		//p3 = t.findNextNodeByInOrder(p2);
		//cout << "������������нڵ� p2 ����һ���ڵ㣺" << p3->data << " \n\n";
	}

	{
		//BiTree T1,T2;

		//t.initBiTree(&T1);
		//cout << "���� T1 �������У��磺ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T1);
		//t.printTreeByTreeForm(T1);

		//cout << "\n���ϵ��´�ӡ������ T1��\n" << endl;
		//t.printBiTreeFromTopToBottom1(T1);
		//cout << "\n\n";
		//t.printBiTreeFromTopToBottom2(T1);
		//cout << "\n\n";
		//t.printBiTreeByZType(T1);

		//t.initBiTree(&T2);
		//cout << "���� T2 �������У��磺ABDG///EH//I//CF/J///\n";
		//t.createBiTreeByPreOrder(&T2);
		//t.printTreeByTreeForm(T2);


		//cout << "\n���ϵ��´�ӡ������ T2��\n" << endl;
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
		//cout << "�ж�����{5,7,6,9,11,10,8}�Ƿ�Ϊĳ�����������ĺ����������......\n\n";
		//if(t.verifySequenceOfBST(sequence, len))
		//	cout << "True\n\n";
		//else
		//	cout << "False\n\n";
	}

	{
		/* ע�⣺
		 1���ṹ��� data ��Ҫ��int ��
		 2��ͨ���������봴�����Ͷ���������Ҫ���ģ�
			int ch;
			cin >> ch;
			if(ch == 0)
				*T = NULL;
		 �μ���https://blog.csdn.net/why850901938/article/details/51052936  */

		 //BiTree T;
		 //cout << "��ʼ��������...\n";
		 //t.initBiTree(&T);
		 //cout << "�ж϶������Ƿ�Ϊ��...\n";
		 //t.biTreeEmpty(T) ? printf("T Ϊ�գ�\n") : printf("T ��Ϊ�գ�\n");
		 //cout << "���������д���������...\n";
		 //cout << "��Ϊʾ����¼���������У�221//4//3//\n";
		 //t.createBiTreeByPreOrder(&T);
		 //cout << "\n���������Ľṹ��ӡ����T=\n";
		 //t.printTreeByTreeForm(T);

		 //int sum = 3;
		 //cout << "�����Ϊ "<<sum<< " ��·����\n\n";
		 //t.findPathInBiTree(T, sum);
	}
	system("pause");
	return 0;
}