/*Write a C++ program to accpet worker information Worker_Name, No_Of_Hours_Worked,
Pay_Rate and Salary. Write necessary functions to calculate and display the salary of Worker. (Use
Default values for Pay_Rate Rs. 500 per hours)*/

#include<iostream>
using namespace std;

class worker
{
	private:
	string name;
	int num,pay_r;
	float sal,num_h,c_sal,salary;
	public:
	void read(string name, float num_h, float sal)
	{

	
		this->name=name;
		this->num_h=num_h;
		this->sal=sal;
		
	}
	
	void calculate()
	{
		int pay_r=500;
		c_sal=(num_h*pay_r);
		salary=sal+c_sal;
	}
	
	
	void print()
	{


		cout<<"\nname of worker is : "<<name<<"\tnumber of hours he or she has worked : "<<num_h<<"\tsalary given to worker : "<<sal<<"\tsalary according to pay rate : "<<salary;

	}
};
	
int main()
{

	worker w;
	w.read("pratik",1,200);
	w.calculate();
	w.print();
	return 0;
}