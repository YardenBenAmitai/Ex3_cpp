#include <iostream>

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
			os<<number.num<<" "<<number.unit;
			return os;
		}
		friend istream& operator>>(istream& input, PhysicalNumber& number){
			input >> number.num >> number.unit;
			return input;
		}					
	};
}