#include <iostream>
#include "Unit.h"
using namespace std;

namespace ariel
{
	class PhysicalNumber{
		public:
		
		double num;
		int unitTOconvert;
		string unit;

		PhysicalNumber(){}

		PhysicalNumber(double a, int b){
			num=a;
			unitTOconvert=b;
			switch(unitTOconvert){
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
		}

		void setNum(double n){
			this->num=n;
		}

		void setUnitTOconvert(int n){
			this->unitTOconvert=n;
		}

		void setUnit(string s){
			this->unit=s;
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
		PhysicalNumber& operator++ (int);
		PhysicalNumber& operator-- (int);

		friend ostream& operator<<(ostream& os, const PhysicalNumber& number){
			os<<number.num<<number.unit;
			return os;
		}
		friend istream& operator>>(istream& input, PhysicalNumber& number){
			string s;
			double n;
			input>> n >> s;
			number.num=n;
			number.unit=s;
			if (s.compare("[cm]")==0) number.unitTOconvert=1;
			else if(s.compare("[m]")==0) number.unitTOconvert=2;
			else if(s.compare("[km]")==0) number.unitTOconvert=3;
			else if(s.compare("[sec]")==0) number.unitTOconvert=4;
			else if(s.compare("[min]")==0) number.unitTOconvert=5;
			else if(s.compare("[hour]")==0) number.unitTOconvert=6;
			else if(s.compare("[g]")==0) number.unitTOconvert=7;
			else if(s.compare("[kg]")==0) number.unitTOconvert=8;
			else if(s.compare("[ton]")==0) number.unitTOconvert=9;
			return input;
		}
	};
}