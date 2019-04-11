#include <iostream>
#include "Unit.h"
using namespace std;

namespace ariel
{
	class PhysicalNumber{
		public:
		
		double num;
		int unitTOconvert;

		PhysicalNumber(){}

		PhysicalNumber(double a, int b){
			num=a;
			unitTOconvert=b;
		}
		
		void update (PhysicalNumber number);
		bool ConvertionCheck(PhysicalNumber* a, PhysicalNumber b);
		PhysicalNumber operator+(PhysicalNumber const &number);
		PhysicalNumber operator-(PhysicalNumber const &number);
		PhysicalNumber& operator+=(const PhysicalNumber &number);
		PhysicalNumber& operator-=(const PhysicalNumber &number);
		PhysicalNumber& operator- ();
		PhysicalNumber& operator+ ();
		bool operator < (PhysicalNumber const &number);
		bool operator > (PhysicalNumber const &number);
		bool operator == (PhysicalNumber const &number);
		bool operator >= (PhysicalNumber const &number);
		bool operator <= (PhysicalNumber const &number);
		bool operator != (PhysicalNumber const &number);
		PhysicalNumber operator++ (int);
		PhysicalNumber operator-- (int);

		friend ostream& operator<<(ostream& os, const PhysicalNumber& number){
			string unit;
			switch(number.unitTOconvert){
				case 1: unit="[cm]"; break;
				case 2: unit="[m]"; break;
				case 3: unit="[km]"; break;
				case 4: unit="[sec]"; break;
				case 5: unit="[min]"; break;
				case 6: unit="[hour]"; break;
				case 7: unit="[g]"; break;
				case 8: unit="[kg]"; break;
				case 9: unit="[ton]"; break; 
			}
			os<<number.num<<unit;
			return os;
		}
		
		friend istream& operator>>(istream& input, PhysicalNumber& number){
			string s;
			input>> number.num>> s;
			if (s.find("cm") != string:npos) number.unitTOconvert=1;
			else if(s.find("m") != string:npos) number.unitTOconvert=2;
			else if(s.find("km") != string:npos) number.unitTOconvert=3;
			else if(s.find("sec") != string:npos) number.unitTOconvert=4;
			else if(s.find("min") != string:npos) number.unitTOconvert=5;
			else if(s.find("hour") != string:npos || s.find("hr") != string:npos) number.unitTOconvert=6;
			else if(s.find("gr") != string:npos || s.find("gram") != string:npos) number.unitTOconvert=7;
			else if(s.find("kg") != string:npos) number.unitTOconvert=8;
			else if(s.find("ton") != string:npos) number.unitTOconvert=9;
			return input;
		}
	};
}