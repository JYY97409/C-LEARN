#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<exception>
using namespace std;

#include<thread>

// 一般大型项目程序才会使用异常，下面我们模拟设计一个服务的几个模块
// 每个模块的继承都是Exception的派生类，每个模块可以添加自己的数据
// 最后捕获时，我们捕获基类就可以
class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg)
		, _id(id)
	{}

	virtual string what() const
	{
		return _errmsg;
	}

	int getid() const
	{
		return _id;
	}
protected:
	string _errmsg;
	int _id;
};

class SqlException : public Exception
{
public:
	SqlException(const string& errmsg, int id, const string& sql)
		:Exception(errmsg, id)
		, _sql(sql)
	{}

	virtual string what() const
	{
		string str = "SqlException:";
		str += _errmsg;
		str += "->";
		str += _sql;
		return str;
	}
private:
	const string _sql;
};

class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(errmsg, id)
	{}

	virtual string what() const
	{
		string str = "CacheException:";
		str += _errmsg;
		return str;
	}
};

class HttpException : public Exception
{
public:
	HttpException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id)
		, _type(type)
	{}

	virtual string what() const
	{
		string str = "HttpException:";
		str += _type;
		str += ":";
		str += _errmsg;
		return str;
	}

private:
	const string _type;
};

void SQLMgr()
{
	if (rand() % 7 == 0)
	{
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}
	else
	{
		cout << "SQLMgr 调用成功" << endl;
	}
}

void CacheMgr()
{
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}
	else
	{
		cout << "CacheMgr 调用成功" << endl;
	}

	SQLMgr();
}

void HttpServer()
{
	if (rand() % 3 == 0)
	{
		throw HttpException("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpException("权限不足", 101, "post");
	}
	else
	{
		cout << "HttpServer调用成功" << endl;
	}

	CacheMgr();
}

void _SendMsg(const string& s)
{
	if (rand() % 2 == 0)
	{
		throw HttpException("网络不稳定，发送失败", 102, "put");
	}
	else if (rand() % 7 == 0)
	{
		throw HttpException("你已经不是对象的好友，发送失败", 103, "put");
	}
	else
	{
		cout << "发送成功" << endl;
	}
}

void SendMsg(const string& s)
{
	// 发送消息失败，则再重试3次
	for (size_t i = 0; i < 4; i++)
	{
		try
		{
			_SendMsg(s);
			break;
		}
		catch (const Exception& e)
		{


			// 捕获异常，if中是102号错误，网络不稳定，则重新发送
			// 捕获异常，else中不是102号错误，则将异常重新抛出
			if (e.getid() == 102)
			{
				// 重试三次以后否失败了，则说明网络太差了，重新抛出异常
				if (i == 3)
					throw;

				//其实就是模拟了网络不好的时候的尝试过程

				cout << "开始第" << i + 1 << "重试" << endl;
			}
			else
			{
				// 重新抛出
				throw;
			}
		}
	}
}
//这就是先捕获，再重新抛出的过程


//int main()
//{
//	srand(time(0));
//	string str;
//	while (cin >> str)
//	{
//		try
//		{
//			//HttpServer();
//			SendMsg(str);
//		}
//		catch (const Exception& e)
//		{
//			cout << e.what() << endl << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//	return 0;
//}


double Divide(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Divide by zero condition!";
	}
	else
	{
		return (double)a / (double)b;
	}
}

template<class T>
class SmartPtr
{
public:
	// RAII
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete[] " << _ptr << endl;
		delete[] _ptr;
	}

	// 重载运算符，模拟指针的行为，方便访问资源
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator[](size_t i)
	{
		return _ptr[i];
	}
private:
	T* _ptr;
};

void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array和array2没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再重新抛出去。
	// 但是如果array2new的时候抛异常呢，就还需要套一层捕获释放逻辑，这里更好解决方案
	// 是智能指针，否则代码太戳了
	SmartPtr<int> sp1 = new int[10];
	SmartPtr<int> sp2 = new int[10];   // 抛异常呢
	SmartPtr<int> sp3 = new int[10];   // 抛异常呢
	SmartPtr<int> sp4 = new int[10];   // 抛异常呢
	SmartPtr<pair<int, int>> sp5 = new pair<int, int>[10];   // 抛异常呢

	int len, time;
	cin >> len >> time;
	cout << Divide(len, time) << endl;
	//在第二个数输入0的时候直接中断，后面的语句通通不执行


	sp1[5] = 50;
	sp5->first = 1;
	sp5->second = 2;
	cout << sp1[5] << endl;
}

//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//
//	//很明显是出现了浅拷贝的问题
//	// 需要sp1和sp2共同管理资源，浅拷贝，析构多次问题得解决
//	SmartPtr<int> sp1 = new int[10];
//	SmartPtr<int> sp2(sp1);
//
//	return 0;
//}

struct Date
{
	int _year;
	int _month;
	int _day;

	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	~Date()
	{
		cout << "~Date()" << endl;
	}

};

int main()
{
	
	
	auto_ptr<Date> ap1(new Date);
	// 拷贝时，管理权限转移，被拷贝对象ap1悬空
	auto_ptr<Date> ap2(ap1);

	// 空指针访问，ap1对象已经悬空
	//ap1->_year++;

	unique_ptr<Date> up1(new Date);
	// 不支持拷贝
	//unique_ptr<Date> up2(up1);

	// 支持移动，但是移动后up1也悬空，所以使用移动要谨慎
	unique_ptr<Date> up3(move(up1));

	shared_ptr<Date> sp1(new Date);
	// 支持拷贝
	shared_ptr<Date> sp2(sp1);
	shared_ptr<Date> sp3(sp2);
	cout << sp1.use_count() << endl;
	sp1->_year++;
	cout << sp1->_year << endl;
	cout << sp2->_year << endl;
	cout << sp3->_year << endl;
	//可以发现这三个智能指针是指向一块空间的，但是存在引用计数的情况


	return 0;
}

