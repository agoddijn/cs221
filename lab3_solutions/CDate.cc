// ..................................................
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"
#include <vector>
#include <cmath>

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );
}

CDate::CDate(int year, std::string month, int day){
	setDate(year, monthStr2Num(month), day);
}

bool CDate::isValidDate(int year, int month, int day){
	if(isValidYear(year) && isValidMonth(month) && isValidDay(year, month, day)) return true;
	return false;
}

bool CDate::isValidDate(int year, std::string month, int day){
	return isValidDate(year, monthStr2Num(month), day);
}

int CDate::monthStr2Num(std::string month){
	std::vector<std::string> months = {
		"jan", "january", "Jan", "January",
		"feb", "february", "Feb", "February",
		"mar", "march", "Mar", "March",
		"apr", "april", "Apr", "April",
		"may", "may", "May", "May",
		"jun", "june", "Jun", "June",
		"jul", "july", "Jul", "July",
		"aug", "august", "Aug", "August",
		"sep", "september", "Sep", "September",
		"oct", "october", "Oct", "October",
		"nov", "november", "Nov", "November",
		"dec", "december", "Dec", "December"};
	for(int i = 0; i < months.size(); i++){
		if (month.compare(months.at(i)) == 0) {
			return int(ceil((i+1)/4));
		}
	}
	return -1;
}

bool CDate::isValidYear(int year){
	if(year > 0) return true;
	return false;
}

bool CDate::isValidMonth(int month){
	if ((month < 1) || (month > 12)) return false;
	return true;
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;

	bool valid = false;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			valid = true;
			break;
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			valid = (day <= 30);
			break;
		default:
			break;
	}
	return valid;
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate(int year, std::string month, int day){
	setDate(year, monthStr2Num(month), day);
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}

