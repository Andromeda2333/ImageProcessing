#include "stdafx.h"
#include "RegexDemo.h"

using namespace std;
RegexDemo::RegexDemo()
{
}


RegexDemo::~RegexDemo()
{
}

void RegexDemo::RegexMatchDemo() const
{
	//生成一个正则表达式
	//不能匹配子字符串
	/*regex r("^\\d{4}(?:0?[1-9]|1[0-2])(?:0?[1-9]|[1-2][0-9]|3[0-1])$");*/
	regex r("^(\\d{4})(0?[1-9]|1[0-2])(0?[1-9]|[1-2][0-9]|3[0-1])$");
	/*regex r("\\d{3}[^[:lower:]]{4}");*/
	while (true){
		cout << "Enter a date (year/month/day) (q=quit)" << endl;
		string str;
		if (!getline(cin, str) || str == "q"){
			break;
		}
		smatch m;
		if (regex_match(str, m, r)){
			/*cout << "Valid date !!!!" << endl;*/
			int year = atoi(m._At(1).str().c_str());
			int month = atoi(m._At(2).str().c_str());
			int day = atoi(m._At(3).str().c_str());
			cout << "Valid date:Year=" << year
				<< ",month=" << month << ",day=" << day << endl;
		}
		else{
			cout << "Invalid date !!!" << endl;
		}
	}

}

void RegexDemo::RegexSearchDemo() const
{//regex_search可以匹配子字符串
	regex r("//\\s*(.+)");
	while (true)
	{
		cout << "Enter a string (q=quit):" ;
		string str;
		if (!getline(cin,str)||str=="q")
		{
			break;
		}

		smatch m;
		if (regex_search(str,m,r))
		{
			cout << "Found comment '" << m._At(1) << "'" << endl;
		}
		else
		{
			cout << "No comment found!!" << endl;
		}
	}
}

void RegexDemo::RegexIteratorDemo() const
{
	//sregex_iterator利用循环匹配子字符串并输出给个匹配的部分
	regex r("[\\w]+");//匹配一个或者多个大写或者小写字母
	string str;
	while (true)
	{
		cout << "Enter a string to spilt (q=quit):";
		if (!getline(cin, str) || str == "q"){
			break;
		}

		const sregex_iterator end;
		for (sregex_iterator it(str.begin(), str.end(), r); it != end; ++it)
		{
			cout << "\"" << (*it)[0] << "\"" << endl;
		}
	}

}

void RegexDemo::RegexTokenIteratorDemo() const
{
	regex r("^(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])$");
	while (true)
	{
		cout << "Enter a date (year/month/day) (q==quit):";
		string str;
		if (!getline(cin,str)||str=="q")
		{
			break;
		}
		vector<int> vec = {2,3};
		const sregex_token_iterator end;
		
		for (sregex_token_iterator it(str.begin(), str.end(), r, vec); it != end;++it)
		{
			cout << "\"" << *it << "\"" << endl;
		}
	}
}

void RegexDemo::RegexTokenIteratorDemo1() const
{
	regex r("\\s*[,;]+\\s*");
	string str;
	while (true)
	{
		cout << "Enter a string to spilt (q=quit):";
		if (!getline(cin,str)||str=="q")
		{
			break;
		}
		const sregex_token_iterator end;
		for (sregex_token_iterator it(str.begin(), str.end(), r, -1); it != end;++it)
		{
			cout << "the string has words:" << *it << endl;
		}

	}

}

void RegexDemo::Test() const
{
	//std::cout.write("hello\n",6);//原始的输出流
	//std::cout.put(std::string("sdasdasd").at(1));//智能每次输出一个字符
	if (cout.good())
	{
		cout << "All good!!" << endl;
	}
	bool myBool = true;
	cout << "this is defalut:" << myBool << endl;
	cout << "This should be true:" << boolalpha << myBool << endl;
	cout << "This should be 1:" << noboolalpha<<myBool << endl;

	int i = 123;
	cout << "This should be '123':" << setw(6) << i << endl;//设置输出字符宽度为6
	cout << "This should be '000123':" << setfill('0') <<setw(6)<< i << endl;//宽度为6,不足以0填充
	cout << "This should be '000123':" << setfill('&') << setw(6) << i << endl;//宽度为6,不足以&填充
	cout << setfill(' ');

	double dbl = 1.452;
	double dbl2 = 5;
	cout << "This should be ' 5':" << setw(2) << noshowpoint << dbl2 << endl;//不显示小数
	cout << "This should be '@@1.452':" << setw(7) << setfill('@') << dbl << endl;//不足部分用@填充

}

std::string RegexDemo::ReadName(std::istream& inStream) const
{
	string name;
	while (inStream.good())
	{
		int next = inStream.get();
		if (next==EOF)
		{
			break;
		}
		name += next;
	}
	return name;
}

void RegexDemo::StringStream() const
{
	//字符串流
	cout << "Enter tokens .Ctrl+Z to end" << endl;
	ostringstream outStream;
	while (cin)
	{
		string nextToken;
		cout << "Next token:";
		cin >> nextToken;
		if (nextToken=="done")
		{
			break;
		}
		outStream << nextToken << "\t";
	}
	cout << "The end result is:" << outStream.str()<<endl;
}

void RegexDemo::FileStreamDemo(int argc, string argv[]) const
{
	ofstream outFile;
	outFile.open("test.txt");
	if (!outFile.is_open())
	{
		cout << "Error when open file!!" << endl;
		return;
	}
	outFile << "There were " << argc << " arguments to this program." << endl;
	outFile << "there are:" << endl;
	for (int i = 0; i < argc;++i)
	{
		outFile << argv[i] << endl;
	}

}

void RegexDemo::OutString() const
{
	ofstream fout("test.out");
	if (!fout.good())
	{
		cerr << "Error opening test.out for writing" << endl;
		return;
	}
	fout << "12345";
	ios_base::streampos curPos = fout.tellp();
	if (5==curPos)
	{
		cout << "At position 5!!" << endl;
	} 
	else
	{
		cout << "Not at position 5!!" << endl;
	}
	fout.seekp(2, ios_base::beg);
	fout << 0;
	fout.close();

	ifstream fin("test.out");
	if (!fin)
	{
		cerr << "Error when open test.out for reading!" << endl;
		return;
	}
	int testValue;
	fin >> testValue;
	const int expected = 12045;
	if (testValue==expected)
	{
		cout << "Test passed: value is " << expected << endl;
	} 
	else
	{
		cout << "Test failed: value is not " << expected << "(It was " << testValue <<
			" )" << endl;
	}
}

void RegexDemo::StreamTie() const
{
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	inFile.tie(&outFile);
	outFile << "Hello there!!!";
	string nextToken;
	inFile >> nextToken;
}

int RegexDemo::SumValue(int inLValue, int inRValue) const
{
	return inLValue + inRValue;
}

void RegexDemo::RatioTest() const
{
	typedef std::ratio<4, 7> r1;
	typedef std::ratio<4, 7> r2;
	typedef std::ratio_add<r1, r2> r3;
	cout << r3::num << "/" << r3::den << std::endl;
}

void RegexDemo::DurationTest() const
{
	chrono::duration<long,ratio<60>> r1(123);
	cout << r1.count() << endl << (r1.max()).count() << endl << (r1.min()).count() << endl;

	chrono::duration<double>d2;
	d2 = d2.max();
	cout << d2.count() << endl;

	chrono::duration<long, ratio<60>>d3(10);
	chrono::duration<long, ratio<1>>d4(14);
	if (d3>d4)
	{
		cout << "d3>d4" << endl;
	} 
	else
	{
		cout << "d3<=d4" << endl;
	}
	//cout << d3.count() << endl;
	++d4;
	//cout << d3.count() << endl;
	d4 *= 2;
	chrono::duration<double, ratio<60>>d5 = d3 + d4;
	chrono::duration<long, ratio<1>>d6 = d3 + d4;
	cout << d3.count() << "分+" << d4.count() << "秒=" <<
		d5.count() << "分 或者" << d6.count() << "秒" << endl;

	using namespace chrono;//chrono也是一个名称空间
	duration<long>d7(30);
	duration<double, ratio<60>>d8(d7);
	cout << d7.count() << "秒=" << d8.count() << "分" << endl;

}

void RegexDemo::ClockTest() const
{
	using namespace chrono;
	//获取当前系统时间
	system_clock::time_point tpoint = system_clock::now();
	//C++风格的时间转化为C风格的时间
	time_t tt = system_clock::to_time_t(tpoint);
	//C风格的时间转化为本地时间
	struct tm t;
	errno_t err=localtime_s(&t,&tt);
	//按一定的格式输出时间
	if (err)
	{
		cout << "Invalid failed!!" << endl;
		return;
	}
	else
	{
		cout << "Successfull!!!" << endl;
	}
	cout << put_time(&t, "%H:%M:&S") << endl;

	//测试一段代码的执行时间
	auto start = system_clock::now();//开始
	double d = 0;
	for (int i = 0; i < 1000000;++i)
	{
		d = sqrt(sin(i)*cos(i));
	}
	auto end = system_clock::now();//结束
	auto diff = end - start;//计算运行时间
	cout << duration<double, ratio<1,10>>(diff).count() << "毫秒" << endl;//转化为毫秒输出

	//时点
	time_point<system_clock>tp1;
	tp1+=minutes(10);
	auto d1 = tp1.time_since_epoch();
	duration<double>d2(d1);
	cout << d2.count() << "秒" << endl;
}

void RegexDemo::RandNumber() const
{
	using namespace chrono;
	srand(static_cast<unsigned int>(time(nullptr)));
	cout << rand() << endl;

	//random_device是基于硬件生成的随机数
	//rnd.entropy()返回值不为0则表示连接了硬件设备(有放射源)
	random_device rnd;
	cout << "Entropy: " << rnd.entropy() << endl;
	cout << "Min value: " << rnd.min() << endl
		<< ",Max value: " << rnd.max() << endl;
	cout << "Random number: " << rnd() << endl;
}

void RegexDemo::TupleTest() const
{
	//元组
	typedef tuple<int, string, bool>MyTuple;
	MyTuple t1(132,"myTuple",true);
	cout << "t1=(" << get<0>(t1) << "," << get<1>(t1) << ","
		<< get<2>(t1) << ")" << endl;
	cout << "Type of get<1>(t1)=" << typeid(get<1>(t1)).name() << endl;

	//string str = "weqe";
	//cout << typeid(str).name() << endl;
	//返回元组的大小
	cout << "MyTuple size =" << tuple_size<MyTuple>::value << endl;

	//make_tuple可以定制一个tuple,通过ref(),cref()引用指定变量
	double d = 3.12423;
	string str = "hello";
	auto t2 = make_tuple(12, ref(d), ref(str), ref(str)); //cref()是常引用const &
	cout << "d=" << get<1>(t2) << endl;
	get<1>(t2) *= 2;
	cout << "d=" << get<1>(t2) << endl;
}

void RegexDemo::IteratorTest() const
{
	vector<int>myVector(100);
	int value = 12;
	generate(myVector.begin(), myVector.end(), [&]{value++; return value*value; });
	//for (auto& i : myVector)
	//{
	//	cout << i << endl;
	//}
	int num = 0;
	cout << "Enter a number to find:";
	cin >> num;
	auto it1 = find(myVector.begin(), myVector.end(), num);
	auto it2 = find(myVector.rbegin(), myVector.rend(), num);

	if (it1!=myVector.end())
	{
		cout << "Found " << num << "at position  " 
			<< it1 - myVector.begin() << " going forward!" << endl;
		cout << "Found " << num << "at position  " <<
			it2.base() - 1 - myVector.begin() << " going backward!!" << endl;
	}
	else
	{
		cout << "Failed to find " << num << endl;
	}
	//ostream_iterator流迭代器,下述代码输出myVector中的元素
	copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
}

void RegexDemo::PointerTest() const
{
	//方法一
	Pointer<vector<int>> vec(new vector<int>);

	//方法二
	vector<string> *vecS=new vector<string>();
	auto s = new Pointer<vector<string>>(vecS);
	s->~Pointer();
	
	vec->push_back(213);
	(*vec).push_back(123);
}
