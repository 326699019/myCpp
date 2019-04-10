// �����㷨��
// 1�����������ֱࣺ�Ӳ������� ��>> ϣ������
// 2��ѡ�������ࣺ��ѡ������ ��>> ������
// 3�����������ࣺð������ ��>> ��������
// 4���鲢�����ࣺ�鲢����

#include "stdafx.h" //��ͷ�ļ�һ��Ҫ���ڵ�һ�У�
#include <iostream>
using namespace std;

class Sort
{
public:
	// ���������� ��> ֱ�Ӳ�������
	void insertSort(int* arr, int len)
	{
		int i, j;
		int tmp; //�ڱ���
		for(i = 1; i < len; i++) //�ӵڶ�����¼��ʼ����һ��Ԫ��arr[0]��������
		{
			if(arr[i] < arr[i - 1]) // ����ǰֵ��ǰһ��ֵС��
			{
				tmp = arr[i];		//�ѵ�ǰֵ���� tmp;
				for(j = i - 1; j >= 0; j--) //��ǰһ��Ԫ�ؿ�ʼ�����ڱ��Ƚϣ�
				{
					if(arr[j] > tmp) //���ڱ�������������ƣ�
						arr[j + 1] = arr[j];
					else
						break;
				}
				arr[j + 1] = tmp; // �����ڱ����뵽��ȷ��λ�ã�
			}
		}
	}

	// ���������� ��> ϣ������
	void shellSort(int* arr, int len)
	{
		int i, j, tmp;
		int dk = len; // ��ʼ������ֵ dk��

		while(dk > 1)
		{
			dk = dk / 3 + 1; // �Զ����������У�
			for(i = dk; i < len; i++)
			{
				if(arr[i] < arr[i - dk]) // ��arr[i] �������������ӱ�
				{
					tmp = arr[i]; //�� arr[i] �ݴ��� tmp;
					for(j = i - dk; j >= 0; j -= dk)
					{
						if(tmp < arr[j])
							arr[j + dk] = arr[j]; //��¼���ƣ����Ҳ���λ�ã�
						else
							break;
					}
					arr[j + dk] = tmp; // ���룻
				}
			}
		}
	}

	// ѡ�������� ��> ��ѡ������
	void selectSort(int* arr, int len)
	{
		int i, j, min;

		// ��ͷ��β��������Ԫ�أ�
		for(i = 0; i < len; i++)
		{
			min = i; // ����ǰ�±궨��Ϊ��Сֵ���±ꣻ

			for(j = i + 1; j < len; j++)
			{
				if(arr[j] < arr[min])
					min = j;
			}// �� i+1 ��β����Сֵ���бȽϣ��и�С�������Ϊ��С��

			 // ������� for ѭ��ִ����֮��û�и���min,˵��û�бȵ�ǰ min ��С��ֵ��
			 // ��ʱi=min�����ý�����
			if(i != min)
				swap(arr, i, min);
		}
	}

	// ѡ�������� ��> ������
	void heapSort(int* arr, int len)
	{
		int i;
		// ������������й�����һ���󶥶ѣ�i �Ǹ��ڵ��ȡֵ��������������
		for(i = len / 2 - 1; i >= 0; i--) // ����ײ���������ڵ㿪ʼ�����˵���Ϊ����ѣ�
			maxHeapAdjust(arr, i, len - 1);

		for(i = len - 1; i >= 0; i--)
		{
			swap(arr[0], arr[i]);		// ���Ѷ�Ԫ���뵱ǰ�ѵ����һ��Ԫ�ؽ��н�����
			maxHeapAdjust(arr, 0, i - 1);	// ��ǰ��n-1����Ԫ�����µ���Ϊһ���󶥶ѣ�
		}
	}

	// ���������� ��> ð������1��
	void bubbleSort1(int* arr, int len)
	{
		int i, j;
		for(i = 0; i < len; i++)
		{
			for(j = len - 1; j > i; j--)
			{
				if(arr[j] < arr[j - 1]) // ����
					swap(arr[j], arr[j - 1]);
			}
		}
	}

	// ���������� ��> ð������2��
	// ð������������棬һ�ֱȽ�֮�������������ڲ�ѭ������ִ�У�
	// �� flag = true ��ִ�У��� flag ��־Ϊ false�����˳����ѭ��;
	void bubbleSort2(int* arr, int len)
	{
		int i, j;

		bool flag = true;

		for(i = 0; i < len && flag; i++)
		{
			flag = false;
			for(j = len - 1; j > i; j--)
			{
				if(arr[j] < arr[j - 1]) // ����
				{
					swap(arr[j], arr[j - 1]);
					flag = true;
				}
			}
		}
	}

	// �������� ��> ��������
	void quickSort(int* arr, int low, int high)
	{
		int pivot;
		if(low < high)
		{
			pivot = partition(arr, low, high);
			quickSort(arr, low, pivot - 1); // ʹ�õݹ飻
			quickSort(arr, pivot + 1, high);
		}
	}
	
	// �鲢����h ���� head��t ���� tail��
	void mergeSort(int* arr, int h,int t)
	{
		if(h < t)

		{
			int m = (h + t) / 2; // �� arr[h...t] ƽ��Ϊ arr[h...m] �� arr[m+1,t]
			mergeSort(arr,h,m);  // �ݹ齫 arr[h...m] �鲢Ϊ����
			mergeSort(arr,m+1,t); // �ݹ齫 arr[m+1...t] �鲢Ϊ����
			merge(arr,h,m,t);	// ��·�鲢��
		}
	}

	// ����ź�������飻
	void printArray(int* arr, int len)
	{
		for(int i = 0; i < len; i++)
			cout << arr[i] << " ";
		cout << endl;
	}


private:
	// ���ش�ʱ�� low �±꣬arr[low] ֵ��Ϊ����ֵ��
	int partition(int* arr, int low, int high)
	{
		int pivotkey; // ����㣬��ߵ�ֵ������С���ұߵ�ֵ��������
		pivotkey = arr[low];
		while(low < high) // low �� high ���� ���м��ƶ���ֱ�� high >= low��
		{
			while(low < high && arr[high] >= pivotkey) // ����high;
				high--;
			swap(arr, low, high);
			while(low < high && arr[low] <= pivotkey) //����low;
				low++;
			swap(arr, low, high);
		}
		return low; // ���ش�ʱ�� low �±꣬arr[low] ֵ��Ϊ����ֵ��
	}

	// �����󶥶ѣ�
	// �������жϸ�Ϊ arr[child] > arr[child + 1] �� tmp <= arr[child] �ͱ���� С���ѣ�
	void maxHeapAdjust(int* arr, int r, int tail)
	{
		int tmp, child;
		tmp = arr[r];
		while(2 * r <= tail) 
		{
			child = 2 * r; //����������5��child �ǵ�ǰ���ڵ� r �����ӣ�

			// child < tail ˵���������һ���ڵ㣬
			// arr[child] < arr[child + 1] ˵������С���Һ��ӣ�child++ �ҵ��ϴ�ĺ��ӣ�
			if(child < tail && arr[child] < arr[child + 1])
				child++;

			if(tmp >= arr[child]) // ��ǰ���ڵ�� �ϴ�ĺ��ӽڵ�Ҫ��˵���Ǵ�ѣ��˳�ѭ����
				break;
			else
				arr[r] = arr[child]; // ���ӽڵ���뵱ǰ���ڵ㣬���һ�뽻����
			
			r = child;				// r ��ʱ�ǽϴ��ӽڵ���±ꣻ
		}
		arr[r] = tmp;	// ���룬��ɽ�����
	}

	// ��·�鲢������h1��h2 ���� head��t2 ���� tail��
	void merge(int* arr, int h1, int t1, int t2)
	{
		int i, j, k;
		int n1, n2; // ��������Ĵ�С��
		n1 = t1 - h1 + 1;
		n2 = t2 - t1;

		int* L = new int[n1]; // �½������ڴ�ռ�
		int* R = new int[n2];
		
		for(i = 0, k = h1; i < n1; i++, k++)	// ���Ƶ����� L;
			L[i] = arr[k];
		for(j = 0, k = t1 + 1; j < n2; j++, k++) // ���Ƶ����� R;
			R[j] = arr[k];

		for(k = h1, i = 0, j = 0; i < n1 && j < n2; k++)
		{
			if(L[i] < R[j])
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
		}

		if(i < n1) // L[] û�й鲢�ꣻ
		{
			for(j = i; j < n1; j++, k++)
				arr[k] = L[j];
		}
		if(j < n2) // R[] û�й鲢�ꣻ
		{
			for(i = j; i < n2; i++, k++)
				arr[k] = R[i];
		}

		delete[] L;
		delete[] R;
	}

	void swap(int* arr, int i, int j)
	{
		int* tmp = new int;
		*tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = *tmp;
		delete tmp;
	}

	void swap(int& a, int& b) // ʹ�����ô��ݣ�
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
};


int main()
{
	int arr[] = {50,10,90,30,70,40,80,60,20};
	int len = sizeof(arr) / sizeof(arr[0]);

	Sort s;

	cout << "ֱ�Ӳ�������";
	s.insertSort(arr, len);
	s.printArray(arr, len);

	cout << "ϣ������";
	s.shellSort(arr, len);
	s.printArray(arr, len);

	cout << "��ѡ������";
	s.selectSort(arr, len);
	s.printArray(arr, len);

	cout << "������";
	s.heapSort(arr, len);
	s.printArray(arr, len);

	cout << "ð����������棺";
	s.bubbleSort1(arr, len);
	s.printArray(arr, len);

	cout << "ð�����������棺";
	s.bubbleSort2(arr, len);
	s.printArray(arr, len);

	cout << "��������";
	s.quickSort(arr, 0,len-1);
	s.printArray(arr, len);

	cout << "�鲢����";
	s.mergeSort(arr,0,len-1);
	s.printArray(arr, len);

	getchar();
	return 0;
}