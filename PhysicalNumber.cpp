#include <iostream>
#include <string>
#include <cmath>

#include "PhysicalNumber.h"

using namespace ariel;
void PhysicalNumber::update(PhysicalNumber number){
	switch (number.unitTOconvert){
		case 1:
		if (number.num>=100){
			number.setNum(number.num/100);
			number.setUnitTOconvert(2);
			number.setUnit("[m]");
		}
		break;
		
		case 2:
		if (number.num>=1000){
			number.setNum(number.num/1000);
			number.setUnitTOconvert(3);
			number.setUnit("[km]");
		}
		break;
		
		case 3: break;
		
		case 4:
		if (number.num>=60){
			number.setNum(number.num/60);
			number.setUnitTOconvert(5);
			number.setUnit("[min]");
		}
		break;
		
		case 5:
		if (number.num>=60){
			number.setNum(number.num/60);
			number.setUnitTOconvert(6);
			number.setUnit("[hour]");
		}
		break;
		
		case 6: break;
		
		case 7:
		if (number.num>=1000){
			number.setNum(number.num/1000);
			number.setUnitTOconvert(8);
			number.setUnit("[kg]");
		}
		break;
		
		case 8:
		if (number.num>=1000){
			number.setNum(number.num/1000);
			number.setUnitTOconvert(9);
			number.setUnit("[ton]");
		}
		break;
		
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
		switch(this->unitTOconvert){
			case 1 : 
			n.unit = "[cm]";
			if(number.unitTOconvert==2) 
				n.num = this->num + number.num*100;
			if(number.unitTOconvert==3) 
				n.num = this->num + number.num*100000;
			break;
			
			case 2 : 
			n.unit = "[m]";
			if(number.unitTOconvert==3)
				n.num = this->num + number.num*1000;
			if(number.unitTOconvert==1)
				n.num = this->num + number.num/100; 
			break;
			
			case 3 :
			n.unit = "[km]";
			if(number.unitTOconvert==2) 
				n.num = this->num + number.num/1000;
			if(number.unitTOconvert==1) 
				n.num = this->num + number.num/100000;
			break;
			
			case 4: 
			n.unit= "[sec]";
			if(number.unitTOconvert==5) 
				n.num = this->num + number.num*60;
			if(number.unitTOconvert==6) 
				n.num = this->num + number.num*3600; 
			break;
			
			case 5: 
			n.unit= "[min]";
			if(number.unitTOconvert==4) 
				n.num = this->num + number.num/60;
			if(number.unitTOconvert==6) 
				n.num = this->num + number.num*60;
			break;
			
			case 6: 
			n.unit= "[hour]";
			if(number.unitTOconvert==4) 
				n.num = this->num + number.num/3600;
			if(number.unitTOconvert==5) 
				n.num = this->num + number.num/60; 
			break;
			
			case 7: 
			n.unit= "[g]";
			if(number.unitTOconvert==8) 
				n.num = this->num + number.num*1000;
			if(number.unitTOconvert==9) 
				n.num = this->num + number.num*1000000; 
			break;
			
			case 8: 
			n.unit= "[kg]";
			if(number.unitTOconvert==7) 
				n.num = this->num + number.num/1000;
			if(number.unitTOconvert==9) 
				n.num = this->num + number.num*1000; 
			break;
			
			case 9: 
			n.unit= "[ton]";
			if(number.unitTOconvert==7) 
				n.num = this->num + number.num/1000000;
			if(number.unitTOconvert==8) 
				n.num = this->num + number.num/1000; 
			break;
		}
		update(n);
		return n;
	}

PhysicalNumber PhysicalNumber::operator-(PhysicalNumber const &number){
	ConvertionCheck(this, number);
	PhysicalNumber n;
	switch(this->unitTOconvert){
		case 1: 
		n.unit = "[cm]";
		if(number.unitTOconvert==2) n.num = this->num - number.num*100;
		if(number.unitTOconvert==3) n.num = this->num - number.num*100000; 
		break;
		
		case 2: 
		n.unit = "[m]";
		if(number.unitTOconvert==3) n.num = this->num - number.num*1000;
		if(number.unitTOconvert==1) n.num = this->num - number.num/100; 
		break;
		
		case 3: 
		n.unit = "[km]";
		if(number.unitTOconvert==2) n.num = this->num - number.num/1000;
        if(number.unitTOconvert==1) n.num = this->num - number.num/100000; 
		break;
		
		case 4: 
		n.unit= "[sec]";
        if(number.unitTOconvert==5) n.num = this->num - number.num*60;
        if(number.unitTOconvert==6) n.num = this->num - number.num*3600; 
		break;
		
		case 5: 
		n.unit= "[min]";
        if(number.unitTOconvert==4) n.num = this->num - number.num/60;
        if(number.unitTOconvert==6) n.num = this->num - number.num*60; 
		break;
		
		case 6: 
		n.unit= "[hour]";
        if(number.unitTOconvert==4) n.num = this->num - number.num/3600;
        if(number.unitTOconvert==5) n.num = this->num - number.num/60; 
		break;
		
		case 7: 
		n.unit= "[g]";
        if(number.unitTOconvert==8) n.num = this->num - number.num*1000;
        if(number.unitTOconvert==9) n.num = this->num - number.num*1000000; 
		break;
		
		case 8: 
		n.unit= "[kg]";
        if(number.unitTOconvert==7) n.num = this->num - number.num/1000;
        if(number.unitTOconvert==9) n.num = this->num - number.num*1000; 
		break;
		
		case 9: 
		n.unit= "[ton]";
        if(number.unitTOconvert==7) n.num = this->num - number.num/1000000;
        if(number.unitTOconvert==8) n.num = this->num - number.num/1000; 
		break;
	}
	update(n);
	return n;
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &number){
ConvertionCheck(this, number);
switch(this->unitTOconvert){
case 1: { this->unit = "[cm]";
          if(number.unitTOconvert==2) this->num += number.num*100;
          if(number.unitTOconvert==3) this->num += number.num*100000; } break;
case 2: { this->unit = "[m]";
          if(number.unitTOconvert==3) this->num += number.num*1000;
          if(number.unitTOconvert==1) this->num += number.num/100; } break;
		  

case 3: { this->unit = "[km]";
          if(number.unitTOconvert==2) this->num += number.num/1000;
          if(number.unitTOconvert==1) this->num += number.num/100000; } break;
		  
case 4: { this->unit= "[sec]";
          if(number.unitTOconvert==5) this->num += number.num*60;
          if(number.unitTOconvert==6) this->num += number.num*3600; } break;
case 5: { this->unit= "[min]";
          if(number.unitTOconvert==4) this->num += number.num/60;
          if(number.unitTOconvert==6) this->num += number.num*60; } break;
case 6: { this->unit= "[hour]";
          if(number.unitTOconvert==4) this->num += number.num/3600;
          if(number.unitTOconvert==5) this->num += number.num/60; } break;
case 7: { this->unit= "[g]";
          if(number.unitTOconvert==8) this->num += number.num*1000;
          if(number.unitTOconvert==9) this->num += number.num*1000000; } break;
case 8: { this->unit= "[kg]";
          if(number.unitTOconvert==7) this->num += number.num/1000;
          if(number.unitTOconvert==9) this->num += number.num*1000; } break;
case 9: { this->unit= "[ton]";
          if(number.unitTOconvert==7) this->num += number.num/1000000;
          if(number.unitTOconvert==8) this->num += number.num/1000; } break;
}
update (*this);
      return *this;
}

PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber &number){
ConvertionCheck(this, number);
switch(this->unitTOconvert){
case 1: {  this->unit = "[cm]";
          if(number.unitTOconvert==2) this->num -= number.num*100;
          if(number.unitTOconvert==3) this->num -= number.num*100000; } break;
		  
case 2: {this->unit = "[m]";
          if(number.unitTOconvert==3) this->num -= number.num*1000;
          if(number.unitTOconvert==1) this->num -= number.num/100; } break;
		  
	
case 3: {this->unit = "[km]";
          if(number.unitTOconvert==2) this->num -= number.num/1000;
          if(number.unitTOconvert==1) this->num -= number.num/100000; } break;
case 4: { this->unit= "[sec]";
          if(number.unitTOconvert==5) this->num -= number.num*60;
          if(number.unitTOconvert==6) this->num -= number.num*3600; } break;
case 5: { this->unit= "[min]";
          if(number.unitTOconvert==4) this->num -= number.num/60;
          if(number.unitTOconvert==6) this->num -= number.num*60; } break;
case 6: { this->unit= "[hour]";
          if(number.unitTOconvert==4) this->num -= number.num/3600;
          if(number.unitTOconvert==5) this->num -= number.num/60; } break;
case 7: { this->unit= "[g]";
          if(number.unitTOconvert==8) this->num -= number.num*1000;
          if(number.unitTOconvert==9) this->num -= number.num*1000000; } break;
case 8: { this->unit= "[kg]";
          if(number.unitTOconvert==7) this->num -= number.num/1000;
          if(number.unitTOconvert==9) this->num -= number.num*1000; } break;
case 9: { this->unit= "[ton]";
          if(number.unitTOconvert==7) this->num -= number.num/1000000;
          if(number.unitTOconvert==8) this->num -= number.num/1000; } break;
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

PhysicalNumber& PhysicalNumber::operator++ (int) {
         this->num+=1;
         update(*this);
		 return *this;
}

PhysicalNumber& PhysicalNumber::operator-- (int) {
         this->num-=1;
         update(*this);
		 return *this;
}
