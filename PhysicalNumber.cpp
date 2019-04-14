#include <iostream>
#include <string>
#include <cmath>
#include "PhysicalNumber.h"

using namespace ariel;


PhysicalNumber PhysicalNumber::update(PhysicalNumber const &number){
	int u=number.unitTOconvert;
	double n;
	for(int i=0;i<2;i++){
		switch (number.unitTOconvert){
		case 1:
		if (abs(number.num)>=100){
			n=number.num/100;
			u=2;
		}break;
		
		case 2:
		if (abs(number.num)>=1000){
			n=number.num/1000;
			u=3;
		}else if(abs(number.num)<1 && abs(number.num)>0){
			n=number.num*100;
			u=1;
		}break;
		
		case 3:
		if(abs(number.num)<1 && abs(number.num)>0){
			n=number.num*1000;
			u=2;
		}break;
		
		case 4:
		if (abs(number.num)>=60){
			n=number.num/60;
			u=5;
		}break;
		
		case 5:
		if (abs(number.num)>=60){
			n=number.num/60;
			u=6;
		}else if(abs(number.num)<1 && abs(number.num)>0){
			n=number.num*60;
			u=4;
		}break;
		
		case 6:
		if(abs(number.num)<1 && abs(number.num)>0){
			n=number.num*60;
			u=5;
		}break;
		
		case 7:
		if (abs(number.num)>=1000){
			n=number.num/1000;
			u=8;
		}break;
		
		case 8:
		if (abs(number.num)>=1000){
			n=number.num/1000;
			u=9;
		}else if(abs(number.num)<1 && abs(number.num)>0){
			n=number.num*1000;
			u=7;
		}break;
		
		case 9:
		if(abs(number.num)<1 && abs(number.num)>0){
			n=number.num*1000;
			u=8;
		}break;
	}
	
	if(number.unitTOconvert==u)
		break;
	}
	return PhysicalNumber(n,u);
}

bool PhysicalNumber::ConvertionCheck(PhysicalNumber* a, PhysicalNumber b){
		if((a->unitTOconvert <= 3 && b.unitTOconvert >= 4)) {
			throw std::invalid_argument("Units do not match - length cannot be converted to weight or time");
		}
		else if((a->unitTOconvert >= 7 && b.unitTOconvert <= 6)) {
			throw std::invalid_argument("Units do not match - weight cannot be converted to length or time");
		}
		else if(((a->unitTOconvert >=4 && a->unitTOconvert <=6) && (b.unitTOconvert >=7 || b.unitTOconvert <= 3))) {
			throw std::invalid_argument("Units do not match - time cannot be converted to weight or length");
		}
		return true;
	}
	
PhysicalNumber PhysicalNumber::operator+(PhysicalNumber const &number){
		ConvertionCheck(this, number);
		double n;
		switch(this->unitTOconvert){
			case 1 : 
			if(number.unitTOconvert==2) 
				n= this->num + number.num*100;
			else if(number.unitTOconvert==3) 
				n= this->num + number.num*100000;
			else
				n=this->num+number.num;
			break;
			
			case 2 : 
			if(number.unitTOconvert==3)
				n = this->num + number.num*1000;
			else if(number.unitTOconvert==1)
				n= this->num + number.num/100; 
			else
				n=this->num+number.num;
			break;
			
			case 3 :
			if(number.unitTOconvert==2) 
				n= this->num + number.num/1000;
			else if(number.unitTOconvert==1) 
				n= this->num + number.num/100000;
			else
				n=this->num+number.num;
			break;
			
			case 4: 
			if(number.unitTOconvert==5) 
				n = this->num + number.num*60;
			else if(number.unitTOconvert==6) 
				n = this->num + number.num*3600; 
			else
				n=this->num+number.num;
			break;
			
			case 5: 
			if(number.unitTOconvert==4) 
				n= this->num + number.num/60;
			else if(number.unitTOconvert==6) 
				n= this->num + number.num*60;
			else
				n=this->num+number.num;
			break;
			
			case 6: 
			if(number.unitTOconvert==4) 
				n = this->num + number.num/3600;
			else if(number.unitTOconvert==5) 
				n = this->num + number.num/60; 
			else
				n=this->num+number.num;
			break;
			
			case 7: 
			if(number.unitTOconvert==8) 
				n= this->num + number.num*1000;
			else if(number.unitTOconvert==9) 
				n = this->num + number.num*1000000; 
			else
				n=this->num+number.num;
			break;
			
			case 8: 
			if(number.unitTOconvert==7) 
				n= this->num + number.num/1000;
			else if(number.unitTOconvert==9) 
				n = this->num + number.num*1000; 
			else
				n=this->num+number.num;
			break;
			
			case 9: 
			if(number.unitTOconvert==7) 
				n = this->num + number.num/1000000;
			else if(number.unitTOconvert==8) 
				n = this->num + number.num/1000; 
			else
				n=this->num+number.num;
			break;
		}
		return PhysicalNumber( n, this->unitTOconvert);
	}

PhysicalNumber PhysicalNumber::operator-(PhysicalNumber const &number){
	ConvertionCheck(this, number);
	double n;
	switch(this->unitTOconvert){
		case 1: 
		if(number.unitTOconvert==2) n = this->num - number.num*100;
		else if(number.unitTOconvert==3) n= this->num - number.num*100000; 
		else n=this->num-number.num;
		break;
		
		case 2: 
		if(number.unitTOconvert==3) n = this->num - number.num*1000;
		else if(number.unitTOconvert==1) n = this->num - number.num/100; 
		else n=this->num-number.num;
		break;
		
		case 3: 
		if(number.unitTOconvert==2) n= this->num - number.num/1000;
        else if(number.unitTOconvert==1) n = this->num - number.num/100000; 
		else n=this->num-number.num;
		break;
		
		case 4: 
        if(number.unitTOconvert==5) n= this->num - number.num*60;
        else if(number.unitTOconvert==6) n = this->num - number.num*3600; 
		else n=this->num-number.num;
		break;
		
		case 5: 
        if(number.unitTOconvert==4) n = this->num - number.num/60;
        else if(number.unitTOconvert==6) n = this->num - number.num*60; 
		else n=this->num-number.num;
		break;
		
		case 6: 
        if(number.unitTOconvert==4) n = this->num - number.num/3600;
        else if(number.unitTOconvert==5) n = this->num - number.num/60; 
		else n=this->num-number.num;
		break;
		
		case 7: 
        if(number.unitTOconvert==8) n = this->num - number.num*1000;
        else if(number.unitTOconvert==9) n = this->num - number.num*1000000; 
		else n=this->num-number.num;
		break;
		
		case 8: 
        if(number.unitTOconvert==7) n = this->num - number.num/1000;
        else if(number.unitTOconvert==9) n = this->num - number.num*1000; 
		else n=this->num-number.num;
		break;
		
		case 9: 
        if(number.unitTOconvert==7) n = this->num - number.num/1000000;
        else if(number.unitTOconvert==8) n = this->num - number.num/1000; 
		else n=this->num-number.num;
		break;
	}
	return PhysicalNumber(n, this->unitTOconvert);
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &number){
	ConvertionCheck(this, number);
	switch(this->unitTOconvert){
		case 1: 
        if(number.unitTOconvert==2) this->num += number.num*100;
        else if(number.unitTOconvert==3) this->num += number.num*100000; 
		else this->num+=number.num;
		break;
		
		case 2: 
        if(number.unitTOconvert==3) this->num += number.num*1000;
        else if(number.unitTOconvert==1) this->num += number.num/100; 
		else this->num+=number.num;
		break;
		
		case 3: 
        if(number.unitTOconvert==2) this->num += number.num/1000;
        else if(number.unitTOconvert==1) this->num += number.num/100000; 
		else this->num+=number.num;
		break;
		
		case 4: 
        if(number.unitTOconvert==5) this->num += number.num*60;
        else if(number.unitTOconvert==6) this->num += number.num*3600; 
		else this->num+=number.num;
		break;
		
		case 5: 
        if(number.unitTOconvert==4) this->num += number.num/60;
        else if(number.unitTOconvert==6) this->num += number.num*60; 
		else this->num+=number.num;
		break;
		
		case 6: 
        if(number.unitTOconvert==4) this->num += number.num/3600;
        else if(number.unitTOconvert==5) this->num += number.num/60; 
		else this->num+=number.num;
		break;
		
		case 7: 
        if(number.unitTOconvert==8) this->num += number.num*1000;
        else if(number.unitTOconvert==9) this->num += number.num*1000000; 
		else this->num+=number.num;
		break;
		
		case 8: 
        if(number.unitTOconvert==7) this->num += number.num/1000;
        else if(number.unitTOconvert==9) this->num += number.num*1000; 
		else this->num+=number.num;
		break;
		
		case 9: 
        if(number.unitTOconvert==7) this->num += number.num/1000000;
        else if(number.unitTOconvert==8) this->num += number.num/1000; 
		else this->num+=number.num;
		break;
	}
    return *this;
}

PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber &number){
	ConvertionCheck(this, number);
	switch(this->unitTOconvert){
		case 1: 
        if(number.unitTOconvert==2) this->num -= number.num*100;
        else if(number.unitTOconvert==3) this->num -= number.num*100000; 
		else this->num-=number.num;
		break;  
		
		case 2: 
        if(number.unitTOconvert==3) this->num -= number.num*1000;
        else if(number.unitTOconvert==1) this->num -= number.num/100; 
		else this->num-=number.num;
		break;
		
		case 3: 
        if(number.unitTOconvert==2) this->num -= number.num/1000;
        else if(number.unitTOconvert==1) this->num -= number.num/100000; 
		else this->num-=number.num;
		break;
		
		case 4: 
        if(number.unitTOconvert==5) this->num -= number.num*60;
        else if(number.unitTOconvert==6) this->num -= number.num*3600; 
		else this->num-=number.num;
		break;
		
		case 5: 
        if(number.unitTOconvert==4) this->num -= number.num/60;
        else if(number.unitTOconvert==6) this->num -= number.num*60; 
		else this->num-=number.num;
		break;
		
		case 6: 
        if(number.unitTOconvert==4) this->num -= number.num/3600;
        else if(number.unitTOconvert==5) this->num -= number.num/60; 
		else this->num-=number.num;
		break;
		
		case 7: 
        if(number.unitTOconvert==8) this->num -= number.num*1000;
        else if(number.unitTOconvert==9) this->num -= number.num*1000000; 
		else this->num-=number.num;
		break;
		
		case 8: 
        if(number.unitTOconvert==7) this->num -= number.num/1000;
        else if(number.unitTOconvert==9) this->num -= number.num*1000; 
		else this->num-=number.num;
		break;
		
		case 9: 
        if(number.unitTOconvert==7) this->num -= number.num/1000000;
        else if(number.unitTOconvert==8) this->num -= number.num/1000; 
		else this->num-=number.num;
		break;
	}
    return *this;
}

PhysicalNumber& PhysicalNumber::operator- () {
         this->num = -this->num;
         return *this;
      }

PhysicalNumber& PhysicalNumber::operator+ () {
         this->num = abs(this->num);
         return *this;
}

bool PhysicalNumber::operator < (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	PhysicalNumber a=update(*this);
	PhysicalNumber b=update(number);
	cout<<a<<"<"<<b<<endl;
	if(a.unitTOconvert < b.unitTOconvert && ((b.num>0) || (a.num<0 &&b.num<0)))
		return true;
	else if(a.unitTOconvert == b.unitTOconvert && a.num <b.num)
		return true;
	return false;
}

bool PhysicalNumber::operator > (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	PhysicalNumber a=update(*this);
	PhysicalNumber b=update(number);
	cout<<a<<">"<<b<<endl;
	if(a.unitTOconvert > b.unitTOconvert && ((a.num>0) || (a.num<0 && b.num<0)))
		return true;
	else if(a.unitTOconvert == b.unitTOconvert && a.num > b.num)
		return true;
	return false;
}

bool PhysicalNumber::operator == (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	PhysicalNumber a=update(*this);
	PhysicalNumber b=update(number);
	cout<<a<<"=="<<b<<endl;
	if(a.unitTOconvert ==b.unitTOconvert && a.num==b.num)
		return true;
	return false;
}

bool PhysicalNumber::operator >= (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	PhysicalNumber a=update(*this);
	PhysicalNumber b=update(number);
	cout<<a<<">="<<b<<endl;
	if(a.unitTOconvert > b.unitTOconvert && ((a.num>0) || (a.num<0 && b.num<0)))
		return true;
	else if(a.unitTOconvert == b.unitTOconvert && a.num >= b.num)
		return true;
	return false;
}

bool PhysicalNumber::operator <= (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	PhysicalNumber a=update(*this);
	PhysicalNumber b=update(number);
	cout<<a<<"<="<<b<<endl;
	if(a.unitTOconvert < b.unitTOconvert && ((b.num>0) || (a.num<0 && b.num<0)))
		return true;
	else if(a.unitTOconvert == b.unitTOconvert && a.num <= b.num)
		return true;
	return false;
}

bool PhysicalNumber::operator != (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	PhysicalNumber a=update(*this);
	PhysicalNumber b=update(number);
	cout<<a<<"!="<<b<<endl;
	if(a.unitTOconvert != b.unitTOconvert)
		return true;
	else if(a.unitTOconvert == b.unitTOconvert && a.num != b.num)
		return true;
	return false;
}

// pre increment
PhysicalNumber& PhysicalNumber::operator++() {
	num++;
	return *this;
}

// post increment
PhysicalNumber PhysicalNumber::operator++ (int) {
	const PhysicalNumber result=*this;
	++(*this);
	return result;
}

// pre decrement
PhysicalNumber& PhysicalNumber::operator-- () {
	num--;
	return *this;
}

// post decrement
PhysicalNumber PhysicalNumber::operator-- (int) {
	const PhysicalNumber result=*this;
	--(*this);
	return result;
}
