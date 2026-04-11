#define  _CRT_SECURE_NO_WARNINGS 1

//第一个C++程序
//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	
//	int num;
//	cin >> num;  //获取标准输入——把num的值提取出来
//	cout << num << endl;  //输出操作，将num中的值打印在屏幕上——插入！
//
//
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//    cout << "  *"  << endl;
//    cout <<" ***" << endl;
//    cout << "*****" << endl;
//    cout << " ***" << endl;
//    cout << "  *" << endl;
//    return 0;
//}
// 洛谷经典题 上学迟到 
// 初见方案：
//#include <iostream>
//#include <iomanip>
//using namespace std;
//int main()
//{
//    int s, v;
//    cin >> s >> v;
//    int t = s / v;
//    int time;
//    if (s % v == 0) //不用估算小数点后的时间
//    {
//        time = t + 10;
//    }
//    else //需要估算小数点后的时间
//    {
//        time = t + 11;
//    }
//    if (time <= 60)
//    {
//        cout << "07:" << setfill('0') << setw(2) << 60 - time << endl;
//    }
//    if (time > 60)
//    {
//        int count = 0;
//        count = time / 60;
//        int hour = 7 - count;
//        int min = 60 - (time % 60);
//        cout << setfill('0') << setw(2)<<hour << ":" << setfill('0') << setw(2) << min << endl;
//    }
//
//    return 0;
//}
//改善满分方案：更简洁易懂且考虑到了前一天
//#include <iostream>
//#include <iomanip> // 必须包含，用于处理 08:05 这种格式
//#include <cmath>
//
//using namespace std;
//
//int main() {
//    int s, v;
//    if (!(cin >> s >> v)) return 0;
//
//    // 1. 计算总耗时（向上取整 + 10分钟）
//    // (s + v - 1) / v 是整数除法实现向上取整的技巧
//    int walk_time = (s + v - 1) / v;
//    int total_needed = walk_time + 10;
//
//    // 2. 统一转换成分钟数来计算
//    // 8:00 相当于从 00:00 过了 8 * 60 = 480 分钟
//    int start_time_minutes = 8 * 60 - total_needed;
//
//    // 3. 处理跨天情况（如果分钟数是负数，加上一整天 24 小时）
//    if (start_time_minutes < 0) {
//        start_time_minutes += 24 * 60;
//    }
//
//    // 4. 分离出小时和分钟
//    int h = start_time_minutes / 60;
//    int m = start_time_minutes % 60;
//
//    // 5. 格式化输出，保证 2 位宽度，不足补 '0'
//    cout << setfill('0') << setw(2) << h << ":"
//        << setfill('0') << setw(2) << m << endl;
//
//    return 0;
//}
//洛谷经典题 大象喝水
//#include <iostream>
//#define pi 3.14;
//using namespace std;
//int main()
//{
//	int h, r;
//	int water = 20000;
//	cin >> h >> r;
//	double bottle = h * r * r * pi;
//	int sum = (water + bottle - 1) / bottle;
//	cout << sum << endl;
//
//	return 0;
//}
//洛谷经典题 小鱼的游泳时间
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a, b, c, d,hour,min;
//	cin >> a >> b >> c >> d;
//	if (a > c || ((a == c) && (b > d)))
//	{
//		cout << "输出错误！" << endl;
//	}
//	else
//	{
//		if (b <= d)
//		{
//			hour = c - a;
//			min = d - b;
//			cout << hour << " " << min << endl;
//		}
//		else
//		{
//			hour = c - a - 1;
//			min = d + 60 - b;
//			cout << hour << " " << min << endl;
//		}
//	}
//	return 0;
//}
//洛谷经典题 小玉买可乐
//#include <iostream>
//#include <iomanip>
//using namespace std;
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	float totle = (a * 1.0) + (b * 0.1);
//	int n = totle / 1.9;
//	cout << n << endl;
//
//	return 0;
//}
//洛谷经典题 期末成绩
//初见
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	float sum = a * 0.2 + b * 0.3 + c * 0.5;
//	int sum1 = (int)sum;
//	int score;
//	if (sum - sum1 > 0.5)
//	{
//		score = sum1 + 1;
//	}
//	else
//	{
//		score = sum1;
//	}
//	cout << score << endl;
//
//	return 0;
//}
//优化
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    // 全程使用整型运算，彻底规避浮点数精度风险
    int score = (a * 2 + b * 3 + c * 5) / 10;

    cout << score << endl;

    return 0;
}