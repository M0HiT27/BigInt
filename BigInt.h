#ifndef _BigInt_H
#define _BigInt_H
#include <string>
#include <iostream>

class BigInt
{
	std::string number = "";

public:
	std::string returnstring();
	void read();
	void removeleadingzeroes(std::string &s);
	void print();
	void setBig(std::string s);


};

//function prototypes
BigInt max(BigInt x, BigInt y);
BigInt min(BigInt x , BigInt y);
bool isequal(BigInt x , BigInt y);
bool isless(BigInt x , BigInt y);
bool isless(std::string x , std:: string y);
bool isgreater(BigInt x , BigInt y);
bool isgreater(std::string x , std:: string y);
BigInt abs(BigInt x);
void MergeSort(BigInt arr[] , int l , int r);
void Merge(BigInt arr[] , int l , int r , int mid);
void sort(BigInt arr[] , int n);
BigInt add(BigInt x , BigInt y);
std::string addstring(std::string x , std::string y);
BigInt substract(BigInt x , BigInt y);
std::string substractstring(std::string x , std::string y);
BigInt multiply(BigInt x , BigInt y);



//function declaration
std::string BigInt::returnstring()
{

	return number;

}


void BigInt::read()
{

	std::cin >> number;
	removeleadingzeroes(number);

}


void BigInt::removeleadingzeroes(std::string &s)
{

	int start = 0;
	std::string copy = "";
	if (s[0] == '-')
	{
		start = 1;
		copy += s[0];
	}
	int strsize = s.length();
	for (int i = start ; i < strsize - 1 ; i++)
	{
		if (s[i] != '0')
		{
			break;
		}
		start++;
	}

	for (int i = start ; i < strsize ; i++)
	{
		copy += s[i];
	}
	s = copy;
	if (s == "-0")
	{
		s = "0";
	}

}


void BigInt::print()
{
	if (number != "")
	{
		std::cout <<  number;
	}
	else {
		std::cout <<  "empty\n";
	}


}

void BigInt::setBig(std::string s) {

	number = s;
	removeleadingzeroes(number);

}


BigInt abs(BigInt x) {

	BigInt temp;
	std::string str = x.returnstring();
	if (str[0] == '-')
	{
		str = str.substr(1, str.length());
	}
	temp.setBig(str);
	return temp;

}


BigInt max(BigInt x, BigInt y)
{

	std::string xstr = x.returnstring();
	std::string ystr = y.returnstring();
	int xsize = xstr.length();
	int ysize = ystr.length();
	if (xstr == ystr)
	{
		return x;
	}
	else if (xstr[0] == '-' && ystr[0] != '-') // if one number is negative
	{
		return y;
	}
	else if (ystr[0] == '-' && xstr[0] != '-')// if one number is negative
	{
		return x;
	}
	else if (ystr[0] == '-' && xstr[0] == '-') // if both number are -ve
	{
		if (xsize > ysize)
		{
			return y;
		}
		else if (xsize < ysize)
		{
			return x;
		}
		else {
			for (int i = 1 ; i < xsize ; i++)
			{
				if (xstr[i] > ystr[i])
				{
					return y;
				}
				else if (xstr[i] < ystr[i])
				{
					return x;
				}
			}
		}
	}
	else if (ystr[0] != '-' && xstr[0] != '-')  // if both number are +ve
	{
		if (xsize > ysize)
		{
			return x;
		}
		else if (xsize < ysize)
		{
			return y;
		}
		else {
			for (int i = 0 ; i < xsize ; i++)
			{
				if (xstr[i] > ystr[i])
				{
					return x;
				}
				else if (xstr[i] < ystr[i])
				{
					return y;
				}
			}
		}
	}
	return x;

}


BigInt min(BigInt x , BigInt y)
{

	BigInt temp = max(x, y);
	if (isequal(temp, x))
	{
		return y;
	}
	else {
		return x;
	}

}

bool isequal(BigInt x , BigInt y)
{

	std::string xstr = x.returnstring();
	std::string ystr = y.returnstring();
	if (xstr == ystr)
	{
		return true;
	}
	else {
		return false;
	}

}

bool isless(BigInt x , BigInt y)
{
	if (isequal(x, y))
	{
		return false;
	}

	if (isequal(max(x, y), y))
	{
		return true;
	}
	return false;

}
bool isless(std::string x , std:: string y) {
	BigInt xbig;
	xbig.setBig(x);
	BigInt ybig;
	ybig.setBig(y);
	return isless(xbig, ybig);
}
bool isgreater(std::string x , std:: string y) {
	BigInt xbig;
	xbig.setBig(x);
	BigInt ybig;
	ybig.setBig(y);
	return isgreater(xbig, ybig);
}
bool isgreater(BigInt x , BigInt y)
{
	if (isequal(x, y))
	{
		return false;
	}
	if (isequal(max(x, y), y))
	{
		return false;
	}
	return true;

}



void swap(BigInt &x , BigInt &y)
{

	std::string xtr = x.returnstring();
	std::string ystr = y.returnstring();
	//std::string s = xtr;
	x.setBig(ystr);
	y.setBig(xtr);

}

void sort(BigInt arr[], int n) {

	MergeSort(arr, 0, n - 1);
}

void MergeSort(BigInt arr[] , int l , int r) {

	if (l < r)
	{

		int mid = (l + r) / 2;
		MergeSort(arr , l , mid);
		MergeSort(arr , mid + 1 , r);

		Merge(arr, l, r, mid);
	}

}


void Merge(BigInt arr[] , int l , int r , int mid)
{

	int size1 = (mid - l + 1);
	int size2 = (r - mid);
	BigInt arr1[size1];
	BigInt arr2[size2];
	int ptr1 = 0;
	for (int i = l ; i <= mid; i++)
	{
		arr1[ptr1] = arr[i];
		ptr1++;
	}
	int ptr2 = 0;
	for (int i = mid + 1 ; i <= r ; i++)
	{
		arr2[ptr2] = arr[i];
		ptr2++;
	}
	ptr1 = 0;
	ptr2 = 0;
	int j = l;
	//merging and rearranging process
	while (ptr1 < size1 && ptr2 < size2)
	{
		if (isless(arr2[ptr2], arr1[ptr1]))
		{
			arr[j] = arr2[ptr2];
			j++;
			ptr2++;

		}
		else {
			arr[j] = arr1[ptr1];
			j++;
			ptr1++;
		}
	}
	if (ptr1 < size1)
	{
		for (int i = ptr1 ; i < size1 ; i++)
		{
			arr[j] = arr1[i];
			j++;
		}
	}

	if (ptr2 < size2)
	{
		for (int i = ptr2 ; i < size2 ; i++)
		{
			arr[j] = arr2[i];
			j++;
		}
	}

}


BigInt add(BigInt x , BigInt y) {

	std::string xstr = x.returnstring();
	std::string ystr = y.returnstring();
	BigInt sum;

	sum.setBig(addstring(xstr, ystr));
	return sum;

}
BigInt substract(BigInt x , BigInt y) {
	std::string xstr = x.returnstring();
	std::string ystr = y.returnstring();
	BigInt substraction;

	substraction.setBig(substractstring(xstr, ystr));
	return substraction;
}


std::string addstring(std::string x , std::string y) {
	int flag = 0;
	int xsize = x.length();
	int ysize = y.length();
	if (xsize == 0)
	{
		return y;
	}
	else if (ysize == 0)
	{
		return x;
	}
	if (x[0] == '-' && y[0] != '-')
	{
		return substractstring(y, x.substr(1, x.length()));
	}
	else if (x[0] != '-' && y[0] == '-')
	{
		return substractstring(x, y.substr(1, y.length()));
	}
	else if (x[0] == '-' && y[0] == '-')
	{
		flag = 1;
		x.erase(0, 1);
		y.erase(0, 1);
	}
	xsize = x.length();
	ysize = y.length();

	int carry = 0;
	std::string strsum = "";
	int ptr1 = xsize - 1;
	int ptr2 = ysize - 1;

	while (ptr1 >= 0 && ptr2 >= 0)
	{
		int char1 = x[ptr1] - '0';
		int char2 = y[ptr2] - '0';
		int tempsum = char1 + char2 + carry;
		carry = tempsum / 10;
		tempsum = tempsum % 10;
		char ToBeAddedToStrsum = tempsum + '0';
		strsum = ToBeAddedToStrsum + strsum;

		ptr1--;
		ptr2--;
	}

	if (ptr1 >= 0)
	{
		while (ptr1 >= 0)
		{
			int char1 = x[ptr1] - '0';
			int tempsum = char1 + carry;
			carry = tempsum / 10;
			tempsum = tempsum % 10;
			char ToBeAddedToStrsum = tempsum + '0';
			strsum = ToBeAddedToStrsum + strsum;
			ptr1--;
		}
	}

	if (ptr2 >= 0)
	{
		while (ptr2 >= 0)
		{
			int char2 = y[ptr2] - '0';
			int tempsum = char2 + carry;
			carry = tempsum / 10;
			tempsum = tempsum % 10;
			char ToBeAddedToStrsum = tempsum + '0';
			strsum = ToBeAddedToStrsum + strsum;
			ptr2--;
		}
	}

	if (carry > 0)
	{
		char ToBeAddedToStrsum = carry + '0';
		strsum = ToBeAddedToStrsum + strsum;
	}
	if (flag == 1)
	{
		strsum = '-' + strsum;
	}
	return strsum;

}


std::string substractstring(std::string x , std::string y) {
	if (x[0] != '-' && y[0] == '-')
	{
		return addstring(x, y.substr(1, y.length()));
	}
	else if (x[0] == '-' && y[0] != '-')
	{
		y = '-' + y;
		return addstring(x, y);
	}
	else if (x[0] == '-' && y[0] == '-') {
		return (substractstring(y.substr(1, y.length()), x.substr(1, x.length())));
	}
	int flag = 0;
	std::string subs = "";
	if (isgreater(y, x))
	{
		flag = 1;
		subs = substractstring(y, x);
	}
	else {
		int size1 = x.size();
		int size2 = y.size();
		int ptr1 = size1 - 1;
		int ptr2 = size2 - 1;
		int carry = 0;
		while (ptr1 >= 0 && ptr2 >= 0)
		{
			int char1 = x[ptr1] - '0' - carry;
			int char2 = y[ptr2] - '0' ;
			if (char2 > (char1))
			{
				carry = 1;
				char1 += 10;
			}
			else {
				carry = 0;
			}
			int tempsum = char1 - char2;
			char ToBeAddedToStrsum = tempsum + '0';
			subs = ToBeAddedToStrsum + subs;


			ptr1--;
			ptr2--;
		}

		if (ptr1 >= 0)
		{
			while (ptr1 >= 0 )
			{
				int char1 = x[ptr1] - '0' - carry;
				if (char1 < 0)
				{
					carry = 1;
					char1 += 10;
				}
				else {
					carry = 0;
				}
				int tempsum = char1 ;

				char ToBeAddedToStrsum = tempsum + '0';
				subs = ToBeAddedToStrsum + subs;
				ptr1--;
			}
		}


	}
	if (flag == 1)
	{
		subs = '-' + subs;
	}

	return subs;

}

BigInt multiply(BigInt x , BigInt y) {
	std::string xstr = x.returnstring();
	std::string ystr = y.returnstring();
	int xsize = xstr.length();
	int ysize = ystr.length();
	BigInt ans;
	if (xsize == 0 || ysize == 0)
	{
		std::cout << "error : in function multiply(BigInt x, BigInt y) one or both of the arguments are empty\n";
		return ans;
	}
	else if (xstr == "0" || ystr == "0")
	{
		ans.setBig("0");
		return ans;
	}
	else {
		int flag = 0;
		if (xstr[0] != '-' && ystr[0] == '-')
		{
			flag = 1;
			ystr.erase(0, 1);
		}
		else if (xstr[0] == '-' && ystr[0] != '-')
		{
			flag = 1;
			xstr.erase(0, 1);
		}
		else if (xstr[0] == '-' && ystr[0] == '-')
		{

			xstr.erase(0, 1);
			ystr.erase(0, 1);
		}
		xsize = xstr.length();
		ysize = ystr.length();
		std::string anstr = "";
		int countzeroes = 0;
		for (int i = xsize - 1 ; i >= 0 ; i--)
		{
			int charx = xstr[i] - '0';

			std::string temp = "";
			int carry = 0;
			for (int zer = 1 ; zer <= countzeroes ; zer++)
			{
				temp += "0";
			}
			//std::cout << temp << "\n";
			for (int j = ysize - 1 ; j >= 0 ; j--)
			{
				int chary = ystr[j] - '0';

				int prod = (charx * chary) + carry;
				carry = prod / 10;
				prod = prod % 10;
				char tobeadded = (prod) + '0';
				temp = tobeadded + temp;
			}

			if (carry > 0)
			{
				char tobeadded = (carry) + '0';
				temp = tobeadded  + temp;
			}

			anstr = addstring(anstr, temp);


			countzeroes++;
		}

		if (flag == 1)
		{
			anstr = "-" + anstr;
		}
		ans.setBig(anstr);
		return ans;
	}

}


#endif