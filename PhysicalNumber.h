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
		
		void update (PhysicalNumber &number);
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
		PhysicalNumber& operator++() ;
		PhysicalNumber& operator--();
		PhysicalNumber operator++ ( int);
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
			double n;
			int u;
			input>> n>> s;
			try{
				if (!s.compare("[cm]")) u=1;
				else if(!s.compare("[m]")) u=2;
				else if(!s.compare("[km]")) u=3;
				else if(!s.compare("[sec]")) u=4;
				else if(!s.compare("[min]")) u=5;
				else if(!s.compare("[hour]")) u=6;
				else if(!s.compare("[g]")) u=7;
				else if(!s.compare("[kg]")) u=8;
				else if(!s.compare("[ton]")) u=9;
				else throw std::invalid_argument("");
				
				number.num=n;
				number.unitTOconvert=u;
			}
			catch(exception& e){
				cout<<"invalid measure"<<endl;
			}
			return input;
		}
	};
}
