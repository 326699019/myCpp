// 排序算法：
// 1、插入排序类：直接插入排序 —>> 希尔排序；
// 2、选择排序类：简单选择排序 —>> 堆排序；
// 3、交换排序类：冒泡排序 —>> 快速排序；
// 4、归并排序类：归并排序；

#include "stdafx.h" //该头文件一定要放在第一行；
#include <iostream>
using namespace std;

class Sort
{
public:
	// 插入排序类 —> 直接插入排序
	void insertSort(int* arr, int len)
	{
		int i, j;
		int tmp; //哨兵；
		for(i = 1; i < len; i++) //从第二个记录开始，第一个元素arr[0]看成有序；
		{
			if(arr[i] < arr[i - 1]) // 若当前值比前一个值小；
			{
				tmp = arr[i];		//把当前值放入 tmp;
				for(j = i - 1; j >= 0; j--) //从前一个元素开始，与哨兵比较；
				{
					if(arr[j] > tmp) //比哨兵大的依此往后移；
						arr[j + 1] = arr[j];
					else
						break;
				}
				arr[j + 1] = tmp; // 最后把哨兵插入到正确的位置；
			}
		}
	}

	// 插入排序类 —> 希尔排序
	void shellSort(int* arr, int len)
	{
		int i, j, tmp;
		int dk = len; // 初始化增量值 dk；

		while(dk > 1)
		{
			dk = dk / 3 + 1; // 自定义增量序列；
			for(i = dk; i < len; i++)
			{
				if(arr[i] < arr[i - dk]) // 将arr[i] 插入有序增亮子表；
				{
					tmp = arr[i]; //把 arr[i] 暂存在 tmp;
					for(j = i - dk; j >= 0; j -= dk)
					{
						if(tmp < arr[j])
							arr[j + dk] = arr[j]; //记录后移，查找插入位置；
						else
							break;
					}
					arr[j + dk] = tmp; // 插入；
				}
			}
		}
	}

	// 选择排序类 —> 简单选择排序
	void selectSort(int* arr, int len)
	{
		int i, j, min;

		// 从头到尾遍历数据元素；
		for(i = 0; i < len; i++)
		{
			min = i; // 将当前下标定义为最小值的下标；

			for(j = i + 1; j < len; j++)
			{
				if(arr[j] < arr[min])
					min = j;
			}// 从 i+1 到尾与最小值进行比较，有更小的则更新为最小；

			 // 若上面的 for 循环执行完之后，没有更新min,说明没有比当前 min 还小的值，
			 // 此时i=min，不用交换；
			if(i != min)
				swap(arr, i, min);
		}
	}

	// 选择排序类 —> 堆排序
	void heapSort(int* arr, int len)
	{
		int i;
		// 将待排序的序列构建成一个大顶堆，i 是根节点的取值（包括子树）；
		for(i = len / 2 - 1; i >= 0; i--) // 从最底层的子树根节点开始，依此调整为有序堆；
			maxHeapAdjust(arr, i, len - 1);

		for(i = len - 1; i >= 0; i--)
		{
			swap(arr[0], arr[i]);		// 将堆顶元素与当前堆的最后一个元素进行交换；
			maxHeapAdjust(arr, 0, i - 1);	// 将前（n-1）个元素重新调整为一个大顶堆；
		}
	}

	// 交换排序类 —> 冒泡排序1；
	void bubbleSort1(int* arr, int len)
	{
		int i, j;
		for(i = 0; i < len; i++)
		{
			for(j = len - 1; j > i; j--)
			{
				if(arr[j] < arr[j - 1]) // 升序；
					swap(arr[j], arr[j - 1]);
			}
		}
	}

	// 交换排序类 —> 冒泡排序2；
	// 冒泡排序简单升级版，一轮比较之后，若都有序，则内层循环不会执行，
	// 即 flag = true 不执行，则 flag 标志为 false，而退出外层循环;
	void bubbleSort2(int* arr, int len)
	{
		int i, j;

		bool flag = true;

		for(i = 0; i < len && flag; i++)
		{
			flag = false;
			for(j = len - 1; j > i; j--)
			{
				if(arr[j] < arr[j - 1]) // 升序；
				{
					swap(arr[j], arr[j - 1]);
					flag = true;
				}
			}
		}
	}

	// 交换排序 —> 快速排序；
	void quickSort(int* arr, int low, int high)
	{
		int pivot;
		if(low < high)
		{
			pivot = partition(arr, low, high);
			quickSort(arr, low, pivot - 1); // 使用递归；
			quickSort(arr, pivot + 1, high);
		}
	}
	
	// 归并排序，h 代表 head，t 代表 tail；
	void mergeSort(int* arr, int h,int t)
	{
		if(h < t)

		{
			int m = (h + t) / 2; // 将 arr[h...t] 平分为 arr[h...m] 和 arr[m+1,t]
			mergeSort(arr,h,m);  // 递归将 arr[h...m] 归并为有序；
			mergeSort(arr,m+1,t); // 递归将 arr[m+1...t] 归并为有序；
			merge(arr,h,m,t);	// 两路归并；
		}
	}

	// 输出排好序的数组；
	void printArray(int* arr, int len)
	{
		for(int i = 0; i < len; i++)
			cout << arr[i] << " ";
		cout << endl;
	}


private:
	// 返回此时的 low 下标，arr[low] 值作为中轴值；
	int partition(int* arr, int low, int high)
	{
		int pivotkey; // 中轴点，左边的值都比它小，右边的值都比它大；
		pivotkey = arr[low];
		while(low < high) // low 和 high 交替 向中间移动，直到 high >= low；
		{
			while(low < high && arr[high] >= pivotkey) // 先移high;
				high--;
			swap(arr, low, high);
			while(low < high && arr[low] <= pivotkey) //再移low;
				low++;
			swap(arr, low, high);
		}
		return low; // 返回此时的 low 下标，arr[low] 值作为中轴值；
	}

	// 调整大顶堆；
	// 把两个判断改为 arr[child] > arr[child + 1] 和 tmp <= arr[child] 就变成了 小顶堆；
	void maxHeapAdjust(int* arr, int r, int tail)
	{
		int tmp, child;
		tmp = arr[r];
		while(2 * r <= tail) 
		{
			child = 2 * r; //二叉树性质5，child 是当前根节点 r 的左孩子；

			// child < tail 说明不是最后一个节点，
			// arr[child] < arr[child + 1] 说明左孩子小于右孩子，child++ 找到较大的孩子；
			if(child < tail && arr[child] < arr[child + 1])
				child++;

			if(tmp >= arr[child]) // 当前根节点比 较大的孩子节点要大，说明是大堆，退出循环；
				break;
			else
				arr[r] = arr[child]; // 孩子节点放入当前根节点，完成一半交换；
			
			r = child;				// r 此时是较大孩子节点的下标；
		}
		arr[r] = tmp;	// 插入，完成交换；
	}

	// 两路归并函数，h1、h2 代表 head，t2 代表 tail；
	void merge(int* arr, int h1, int t1, int t2)
	{
		int i, j, k;
		int n1, n2; // 两个数组的大小；
		n1 = t1 - h1 + 1;
		n2 = t2 - t1;

		int* L = new int[n1]; // 新建数组内存空间
		int* R = new int[n2];
		
		for(i = 0, k = h1; i < n1; i++, k++)	// 复制到数组 L;
			L[i] = arr[k];
		for(j = 0, k = t1 + 1; j < n2; j++, k++) // 复制到数组 R;
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

		if(i < n1) // L[] 没有归并完；
		{
			for(j = i; j < n1; j++, k++)
				arr[k] = L[j];
		}
		if(j < n2) // R[] 没有归并完；
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

	void swap(int& a, int& b) // 使用引用传递；
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

	cout << "直接插入排序：";
	s.insertSort(arr, len);
	s.printArray(arr, len);

	cout << "希尔排序：";
	s.shellSort(arr, len);
	s.printArray(arr, len);

	cout << "简单选择排序：";
	s.selectSort(arr, len);
	s.printArray(arr, len);

	cout << "堆排序：";
	s.heapSort(arr, len);
	s.printArray(arr, len);

	cout << "冒泡排序基础版：";
	s.bubbleSort1(arr, len);
	s.printArray(arr, len);

	cout << "冒泡排序升级版：";
	s.bubbleSort2(arr, len);
	s.printArray(arr, len);

	cout << "快速排序：";
	s.quickSort(arr, 0,len-1);
	s.printArray(arr, len);

	cout << "归并排序：";
	s.mergeSort(arr,0,len-1);
	s.printArray(arr, len);

	getchar();
	return 0;
}