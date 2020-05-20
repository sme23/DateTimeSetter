#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

int main() {
	
	//print to console
	//PUSH
	//ORG $D74D0
	//String("YYYY/MM/DD(WEK) HH:MM:SS")
	//POP

	cout << "PUSH" << endl;
	cout << "ORG $D74D0" << endl;
	
	time_t now = time(0);
	tm *ltm = localtime(&now);

	int year = (1900 + ltm->tm_year);
	int month = (1 + ltm->tm_mon);
	int day = ltm->tm_mday;
	int week = ltm->tm_wday;
	int hour = (ltm->tm_hour);
	int min = (1 + ltm->tm_min);
	int sec = (1 + ltm->tm_sec);

	string weekStr;

	switch (week) {
	case 0:
		weekStr = "SUN";
		break;
	case 1:
		weekStr = "MON";
		break;
	case 2:
		weekStr = "TUE";
		break;
	case 3:
		weekStr = "WED";
		break;
	case 4:
		weekStr = "THU";
		break;
	case 5:
		weekStr = "FRI";
		break;
	case 6:
		weekStr = "SAT";
		break;
	default:
		weekStr = "ERR";
		break;
	}

	//String("YYYY/MM/DD(WEK) HH:MM:SS")
	cout << "String(\"" << year << "/";
	
	if (month >= 10) { cout << month << "/"; } else { cout << 0 << month << "/"; }
	if (day >= 10) { cout << day << "("; } else { cout << 0 << day << "("; }
	
	cout << weekStr << ") ";

	if (hour >= 10) { cout << hour << ":"; } else { cout << 0 << hour << ":"; }
	if (min >= 10) { cout << min << ":"; } else { cout << 0 << min << ":"; }
	if (sec >= 10) { cout << sec << "\")"; } else { cout << 0 << sec << "\")";  }
	
	cout << endl;

	cout << "POP" << endl;


}

