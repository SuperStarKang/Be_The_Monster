#include <iostream>

using namespace std;

int N;

int main(void) {
	cin >> N;

	string older;
	string younger;
	int oday=10000,omonth=10000,oyear=10000;
	int yday=0,ymonth=0,yyear=0;

	int day,month,year;
	string name;
	for (int i=0; i<N; i++) {
		cin >> name >> day >> month >> year;
		if (year > yyear) {
			younger = name;
			yday = day;
			ymonth = month;
			yyear = year;
		}
		else if (year == yyear) {
			if (month > ymonth) {
				younger = name;
				yday = day;
				ymonth = month;
				yyear = year;
			}
			else if (month == ymonth) {
				if (day > yday) {
					younger = name;
					yday = day;
					ymonth = month;
					yyear = year;
				}
			}
		}

		if (year < oyear) {
			older = name;
			oday = day;
			omonth = month;
			oyear = year;
		}
		else if (year == oyear) {
			if (month < omonth) {
				older = name;
				oday = day;
				omonth = month;
				oyear = year;
			}
			else if (month == omonth) {
				if (day < oday) {
					older = name;
					oday = day;
					omonth = month;
					oyear = year;
				}
			}
		}
	}

	cout << younger << '\n' << older << '\n';

	return 0;
}