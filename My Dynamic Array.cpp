
#include<iostream>

using namespace std;

class MyDynamicArray
{
private:
	float *ptr;
	int size;

public:

	MyDynamicArray()
	{
		ptr = NULL;
		size = 0;
	}

	~MyDynamicArray()
	{

		delete[] ptr;
		ptr = NULL;
	}

	void setsize(int new_size)
	{
		if (!new_size)
		{
			size = 0;
			delete[] ptr;
			ptr = NULL;

		}
		int max;
		float *temp;
		temp = new float[new_size];

		if (new_size >= size)
			max = size;
		else
			max = new_size;
		
		for (int i = 0; i < max; i++)
		{
			 temp[i] = ptr[i];
		}
		delete[] ptr;
		ptr = temp;
		size = new_size;
		return;
	}

	int getsize()
	{
		return size;
	}
	
	void add(float f)
	{
		// momken hena a7ot condition 3shan yzwd l size b 2 size msh +1
		setsize(size + 1);
		ptr[size - 1] = f;
		return;
	}

	void insert(int index, float f)
	{
		float *temp1;
		int j = 0;
		setsize(size + 1);
		temp1 = new float[size];
		for (int i = 0; i < size; i++)
		{
			if (i != index - 1)
			{
				temp1[i] = ptr[j];
				j++;
			}
			else
			{
				temp1[i] = f;
			}
		}
		delete[] ptr;
		ptr = temp1;
		return;
	}

	float getelement(int index)
	{
		for (int i = 0; i < size; i++)
		{
			if (i == index - 1)
				return ptr[i];
		}
	}

	void removeelement(int index)
	{
		for (int i = 0; i < size; i++)
		{
			if (i == index - 1)
			{
				for (int j = index - 1; j < size - 1; j++)
				{
					ptr[j] = ptr[j + 1];
				}
				setsize(size - 1);
				return;

			}

		}

	}

	void removeduplicate()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (ptr[i] == ptr[j])
					removeelement(j+1);
			}
		}
		return;
	}

	void removeall()
	{
		size = 0;
		delete[] ptr;
		ptr = NULL;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << ptr[i] << endl;
		}
		return;
	}

	void find(float f)
	{
		for (int i = 0; i < size; i++)
		{
		// CHECK THOSE
		//	MyDynamicArray x;
		//	x.setsize(size);
			int x[100], j = 0;
			if (ptr[i] == f)
			{
				x[j] = i;
				j++;
			}
			for (int k = 0; k < j; k++)
			{
				cout << x[k]+1 << endl;
			}
		}
		return;
	}

	float sum()
	{
		float sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += ptr[i];
		}
		return sum;
	}

	void concatinate(MyDynamicArray &X)
	{
		/*
		int x = X.getsize() + size;

		for (int i = size; i < x; i++)
		{	//ptr[i] = 
			add(X.getelement(i));
		}*/

		int j = 1;
		int x = X.getsize() + size;
		float *temp2;
		temp2 = new float[x];
		for (int i = 0; i < x; i++)
		{
			if (i < size)
				temp2[i] = ptr[i];
			else
			{
				
				temp2[i] = X.getelement(j);
				j++;
			}
		}
		delete[] ptr;
		size = x;
		ptr = temp2;
		temp2 = NULL;
		return;
	}

	void swap(int index1, int index2)
	{
		int j = 0;
		float *temp3;
		temp3 = new float;
		for (int i = 0; i < size; i++)
		{
			if (index2 < index1)
			{
				int temp;
				temp = index2;
				index2 = index1;
				index1 = temp;
				
			}
			if (i == index1 - 1)
				j = i;
			if (i == index2 - 1)
			{
				*temp3 = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = *temp3;
				delete[] temp3;
				return;
			}


		}
	}
	
	void sort(int acc)// 1 low tasa3ody, 0 low tanazoly
	{
		cout << "enter 1 if you want to sort the array ascending or 0 if you want to sort the array descending" << endl;
		cin >> acc;
		if (size < 2)
			return;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i; j++)
			{
				if (acc)
				{
					if (ptr[j] > ptr[j+1])
						swap(j+1, j+2);
					//cout << ptr[j] << endl << ptr[j + 1]<<endl;
				}
				if (!acc)
				{
					if (ptr[j] < ptr[j+1])
						swap(j+1, j+2);
				}
			}
		}
		return;
	}
};

/*
int main()
{
//	printf("hello");
	MyDynamicArray A, B;
	for (float i = 0; i < 100; i+=5)
	{
		A.add(i);
	}
	for (float j = 10; j < 50; j+=3)
	{
		B.add(j);
	}
	//B.print();
	A.concatinate(B);
	A.sort(0);
	A.removeduplicate();
	A.print();
	//A.find(5);
	
	//cout <<A.getsize() << endl;
	system("pause");
	return 0;
}*/
