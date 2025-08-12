#include<iostream>

class report
{
	int* grade;
	int datacount;
	int capacity;
public:
	report()
		:grade(nullptr), datacount(0), capacity(10)
	{
		grade = new int[capacity];
	}
	~report()
	{
		delete[] grade;
		datacount = 0;
		capacity = 0;
	}
	void pushback(int a)
	{
		if (datacount >= capacity)
		{
			int* newgrade;
			newgrade = new int[capacity * 2];
			for (int i = 0; i < datacount; ++i)
			{
				newgrade[i] = grade[i];
			}
			
			grade = newgrade;
			delete[]newgrade;
			
		}
		grade[datacount] = a;
		++datacount;
	}
	void pushfront(int a)
	{
		if (datacount >= capacity)
		{
			int* newgrade;
			newgrade = new int[capacity * 2];
			for (int i = 0; i < datacount; ++i)
			{
				newgrade[i] = grade[i];
			}

			grade = newgrade;
			delete[]newgrade;

		}
		for (int i = datacount-1; i >= 0; --i)
		{
			
			grade[i+1] = grade[i];

		}
		grade[0] = a;
		++datacount;
	}
	void popback()
	{
		grade[datacount] = 0;
		--datacount;

	}
	void popfront()
	{
		for (int i = 1; i < datacount; ++i) {
			grade[i - 1] = grade[i];
		}
		--datacount;
	}
	void bubblesort()
	{
		for(int j=0;j<datacount-1;++j)
		{
			for (int i = 0; i < datacount - 1 - j; ++i)
			{
				if (grade[i] > grade[i + 1])
				{
					int a = grade[i];
					grade[i] = grade[i + 1];
					grade[i + 1] = a;
				}
			}
		}
		
	}
	void print()
	{
		std::cout << "print report card" << std::endl;
		for (int i = 0; i < datacount; ++i)
		{
			std::cout << grade[i] << std::endl;
		}
	}

};
int main()
{
	report arr;
	arr.pushback(5);
	arr.pushback(4);
	arr.pushback(3);
	arr.pushback(2);
	arr.pushback(1);
	arr.pushfront(10);
	arr.print();
	std::cout << "popback:" << std::endl;
	arr.popback();
	arr.print();
	std::cout << "bubblesort" << std::endl;
	arr.bubblesort();
	arr.print();
	std::cout << "popfront" << std::endl;
	arr.popfront();
	arr.print();

}