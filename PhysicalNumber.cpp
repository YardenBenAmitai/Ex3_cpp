#include <iostream>
#include <string>
#include <cmath>
#include "PhysicalNumber.h"

using namespace ariel;


void PhysicalNumber::update(PhysicalNumber number){
	switch (number.unitTOconvert){
		case 1:
		if (number.num>=100){
			number.num=number.num/100;
			number.unitTOconvert=2;
		}break;
		
		case 2:
		if (number.num>=1000){
			number.num=number.num/1000;
			number.unitTOconvert=3;
		}else if(number.num<1){
			number.num=number.num*100;
			number.unitTOconvert=1;
		}break;
		
		case 3:
		if(number.num<1){
			number.num=number.num*1000;
			number.unitTOconvert=2;
		}break;
		
		case 4:
		if (number.num>=60){
			number.num=number.num/60;
			number.unitTOconvert=5;
		}break;
		
		case 5:
		if (number.num>=60){
			number.num=number.num/60;
			number.unitTOconvert=6;
		}else if(number.num<1){
			number.num=number.num*60;
			number.unitTOconvert=4;
		}break;
		
		case 6:
		if(number.num<1){
			number.num=number.num*60;
			number.unitTOconvert=5;
		}break;
		
		case 7:
		if (number.num>=1000){
			number.num=number.num/1000;
			number.unitTOconvert=8;
		}break;
		
		case 8:
		if (number.num>=1000){
			number.num=number.num/1000;
			number.unitTOconvert=9;
		}else if(number.num<1){
			number.num=number.num*1000;
			number.unitTOconvert=7;
		}break;
		
		case 9:
		if(number.num<1){
			number.num=number.num*1000;
			number.unitTOconvert=8;
		}break;
	}
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
		PhysicalNumber n;
		n.unitTOconvert=this->unitTOconvert;
		switch(this->unitTOconvert){
			case 1 : 
			if(number.unitTOconvert==2) 
				n.num = this->num + number.num*100;
			else if(number.unitTOconvert==3) 
				n.num = this->num + number.num*100000;
			else
				n.num=this->num+number.num;
			break;
			
			case 2 : 
			if(number.unitTOconvert==3)
				n.num = this->num + number.num*1000;
			else if(number.unitTOconvert==1)
				n.num = this->num + number.num/100; 
			else
				n.num=this->num+number.num;
			break;
			
			case 3 :
			if(number.unitTOconvert==2) 
				n.num = this->num + number.num/1000;
			else if(number.unitTOconvert==1) 
				n.num = this->num + number.num/100000;
			else
				n.num=this->num+number.num;
			break;
			
			case 4: 
			if(number.unitTOconvert==5) 
				n.num = this->num + number.num*60;
			else if(number.unitTOconvert==6) 
				n.num = this->num + number.num*3600; 
			else
				n.num=this->num+number.num;
			break;
			
			case 5: 
			if(number.unitTOconvert==4) 
				n.num = this->num + number.num/60;
			else if(number.unitTOconvert==6) 
				n.num = this->num + number.num*60;
			else
				n.num=this->num+number.num;
			break;
			
			case 6: 
			if(number.unitTOconvert==4) 
				n.num = this->num + number.num/3600;
			else if(number.unitTOconvert==5) 
				n.num = this->num + number.num/60; 
			else
				n.num=this->num+number.num;
			break;
			
			case 7: 
			if(number.unitTOconvert==8) 
				n.num = this->num + number.num*1000;
			else if(number.unitTOconvert==9) 
				n.num = this->num + number.num*1000000; 
			else
				n.num=this->num+number.num;
			break;
			
			case 8: 
			if(number.unitTOconvert==7) 
				n.num = this->num + number.num/1000;
			else if(number.unitTOconvert==9) 
				n.num = this->num + number.num*1000; 
			else
				n.num=this->num+number.num;
			break;
			
			case 9: 
			if(number.unitTOconvert==7) 
				n.num = this->num + number.num/1000000;
			else if(number.unitTOconvert==8) 
				n.num = this->num + number.num/1000; 
			else
				n.num=this->num+number.num;
			break;
		}
		update(n);
		return n;
	}

PhysicalNumber PhysicalNumber::operator-(PhysicalNumber const &number){
	ConvertionCheck(this, number);
	PhysicalNumber n;
	n.unitTOconvert=this->unitTOconvert;
	switch(this->unitTOconvert){
		case 1: 
		if(number.unitTOconvert==2) n.num = this->num - number.num*100;
		else if(number.unitTOconvert==3) n.num = this->num - number.num*100000; 
		else n.num=this->num-number.num;
		break;
		
		case 2: 
		if(number.unitTOconvert==3) n.num = this->num - number.num*1000;
		else if(number.unitTOconvert==1) n.num = this->num - number.num/100; 
		else n.num=this->num-number.num;
		break;
		
		case 3: 
		if(number.unitTOconvert==2) n.num = this->num - number.num/1000;
        else if(number.unitTOconvert==1) n.num = this->num - number.num/100000; 
		else n.num=this->num-number.num;
		break;
		
		case 4: 
        if(number.unitTOconvert==5) n.num = this->num - number.num*60;
        else if(number.unitTOconvert==6) n.num = this->num - number.num*3600; 
		else n.num=this->num-number.num;
		break;
		
		case 5: 
        if(number.unitTOconvert==4) n.num = this->num - number.num/60;
        else if(number.unitTOconvert==6) n.num = this->num - number.num*60; 
		else n.num=this->num-number.num;
		break;
		
		case 6: 
        if(number.unitTOconvert==4) n.num = this->num - number.num/3600;
        else if(number.unitTOconvert==5) n.num = this->num - number.num/60; 
		else n.num=this->num-number.num;
		break;
		
		case 7: 
        if(number.unitTOconvert==8) n.num = this->num - number.num*1000;
        else if(number.unitTOconvert==9) n.num = this->num - number.num*1000000; 
		else n.num=this->num-number.num;
		break;
		
		case 8: 
        if(number.unitTOconvert==7) n.num = this->num - number.num/1000;
        else if(number.unitTOconvert==9) n.num = this->num - number.num*1000; 
		else n.num=this->num-number.num;
		break;
		
		case 9: 
        if(number.unitTOconvert==7) n.num = this->num - number.num/1000000;
        else if(number.unitTOconvert==8) n.num = this->num - number.num/1000; 
		else n.num=this->num-number.num;
		break;
	}
	update(n);
	return n;
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
	update (*this);
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
	update(*this);
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
	update(*this); update(number);
	if(this->unitTOconvert < number.unitTOconvert)
		return true;
	else if(this->unitTOconvert == number.unitTOconvert && this->num < number.num)
		return true;
	return false;
}

bool PhysicalNumber::operator > (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	update(*this); update(number);
	if(this->unitTOconvert > number.unitTOconvert)
		return true;
	else if(this->unitTOconvert == number.unitTOconvert && this->num > number.num)
		return true;
	return false;
}

bool PhysicalNumber::operator == (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	update(*this); update(number);
	if(this->unitTOconvert == number.unitTOconvert && this->num==number.num)
		return true;
	return false;
}

bool PhysicalNumber::operator >= (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	update(*this); update(number);
	if(this->unitTOconvert > number.unitTOconvert)
		return true;
	else if(this->unitTOconvert == number.unitTOconvert && this->num >= number.num)
		return true;
	return false;
}

bool PhysicalNumber::operator <= (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	update(*this); update(number);
	if(this->unitTOconvert < number.unitTOconvert)
		return true;
	else if(this->unitTOconvert == number.unitTOconvert && this->num <= number.num)
		return true;
	return false;
}

bool PhysicalNumber::operator != (PhysicalNumber const &number) {
	ConvertionCheck(this, number);
	update(*this); update(number);
	if(this->unitTOconvert != number.unitTOconvert)
		return true;
	else if(this->unitTOconvert == number.unitTOconvert && this->num != number.num)
		return true;
	return false;
}

PhysicalNumber& PhysicalNumber::operator++() {
         PhysicalNumber result=*this;
		 result.num+=1;
		 update(result);
		 return *this;
}
PhysicalNumber PhysicalNumber::operator++ (int) {
		 PhysicalNumber result=*this;
         result.num+=1;
		 update(result);
		 return result;
}

PhysicalNumber& PhysicalNumber::operator-- () {
         PhysicalNumber result=*this;
		 result.num-=1;
         update(result);
		 return *this;
}

PhysicalNumber PhysicalNumber::operator-- (int) {
         PhysicalNumber result=*this;
		 result.num-=1;
         update(result);
		 return result;
}
