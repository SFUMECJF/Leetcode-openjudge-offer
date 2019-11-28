@[TOC](四则运算表达式求值)

## AC代码
```c
/**********************************************************************/
/*                     _   _  __  __    ____  _____                   */
/*                    | | | ||  \/  |  / ___||  ___|                  */
/*                    | | | || |\/| | | |    | |___                   */
/*                    | |_| || |  | | | |___ | |___|                  */
/*                     \___/ |_|  |_|  \____||_|                      */
/**********************************************************************/
#include <iomanip>
#include <iostream>

using namespace std;

double factor_value();//因式 
double term_value();//项 
double expression_value();//表达式 

int main()
{
    cout << fixed <<setprecision(2) << expression_value() << endl;
return 0;
}

double expression_value()
{
	double result = term_value();
	while(true)
	{
		char op = cin.peek();
		if(op == '+' || op == '-')
		{
			cin.get();
			double value = term_value();
			if(op == '+')
			{
				result += value;
			}
			else
			{
				result -= value;
			}
			
		}
		else
		{
			break;
		}
	}
	return result;
}

double factor_value()
{
	double factor_result= 0;//此处变量不初始化，会造成bug 
	if(cin.peek() == '(')
	{
		cin.get();
		factor_result = expression_value();
		cin.get();
	}
	else
	{
		while(isdigit(cin.peek()))
		{
				factor_result = 10 * factor_result + cin.peek() - '0';//必须初始化，第一次读书十位是0 
				cin.get();
		}
		if(cin.peek()=='.')
		{
			cin.get();
			double base_result=0;
			if(isdigit(cin.peek()))
			{
				for(double times =0.1; isdigit(cin.peek()); times *= 0.1)
				{
					base_result =  base_result + times*(cin.peek() - '0');//必须初始化，第一次读书十位是0 
					cin.get();
				}	
			}
		
			factor_result += base_result;
		}
		
	}
	return factor_result;
} 

double term_value()
{
	double term_result = factor_value();
	//bool more = true;//true not 1 
	while(true)
	{
		char op = cin.peek();
		if(op == '*' || op == '/')
		{
			cin.get();
			double value = factor_value();
			if(op == '*')
			{
				term_result *= value;
			}
			else
			{
				term_result /= value;
			}
			
		}
		else
		{
			break;//more = false;//false not 1
		}
	}
	return term_result;
	
}
```
## 解析
[参看中国大学慕课郭炜老师课程讲解递归二](https://www.icourse163.org/course/PKU-1001894005)
## 坑
郭炜老师所讲是整数的，如果想要AC4132需要检查一下小数点。变量最好初始化，否则会有意想不到的问题


## 新知识
### cout格式
```
cout << fixed <<setprecision(2) << expression_value() << endl;
```
可设置小数点右边位数
### true代表1，false代表0
### 输入流操作
cin.peek()；
cin.get()；
isdigit();
### ASCII
factor_result = 10 * factor_result + cin.peek() - '0';
字符减0，转为数字


