#include <iostream>
#include <math.h>
#include <string>
#include <clocale>
#include <complex>
using namespace std;
typedef double ComplexDouble;

enum STATE {
	OK, BAD_INIT, BAD_DIV
};

class VectorInt {
	ComplexDouble* v;
	int num;
	int state = 0;
public:
	VectorInt() : VectorInt(2) {}
	VectorInt(int n);
	VectorInt(int n, ComplexDouble&);
	VectorInt(int n, ComplexDouble*);
	VectorInt(const VectorInt& s);
	VectorInt& operator=(const VectorInt& s);
	~VectorInt() {
		num = 0;
	}

	VectorInt A(VectorInt& b); //++
	VectorInt B(VectorInt& b); //--
	VectorInt D(VectorInt& b); //-
	VectorInt E(VectorInt& b); //=
	VectorInt F(VectorInt& b); //+=
	VectorInt G(VectorInt& b); //-=
	VectorInt H(VectorInt& b); //*=
	VectorInt I(VectorInt& b); // /=
	VectorInt J(VectorInt& b); //%=

	VectorInt F1(VectorInt& b); //+
	VectorInt G1(VectorInt& b); //-
	VectorInt H1(VectorInt& b); //*
	VectorInt I1(VectorInt& b); // /
	VectorInt J1(VectorInt& b); // %

	VectorInt A1(VectorInt& b); // >>
	VectorInt B1(VectorInt& b); // <<
	VectorInt C1(VectorInt& b); // ==
	VectorInt C11(VectorInt& b); // !=

	double& A2(VectorInt& b); // []

	bool C(VectorInt& s);
	bool Bi(VectorInt& b); // >
	bool Ci(VectorInt& b); // >=
	bool Di(VectorInt& b); // <
	bool Ei(VectorInt& b); // <=


	void Output();
	void Output1();
	void Input();
};

VectorInt::VectorInt(int n) {
	if (n <= 0)    n = 2;  // default num =2;
	num = n;
	v = new ComplexDouble[n];
	for (int i = 0; i < n; i++) {
		v[i] = 0.0;
	}
}
VectorInt::VectorInt(int n, ComplexDouble& b) : VectorInt(n) {
	for (int i = 0; i < num; i++) {
		v[i] = b;
	}
}
VectorInt::VectorInt(int n, ComplexDouble* p) : VectorInt(n) {
	if (p != nullptr)
		for (int i = 0; i < num; i++)
			v[i] = p[i];

}
VectorInt::VectorInt(const VectorInt& s) {
	// if (this == &s) return;  // the expression is used in the old standard
	num = s.num;
	v = new ComplexDouble[num];
	state = 0;
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
}
VectorInt& VectorInt::operator=(const VectorInt& s) {

	if (num != s.num)
	{
		if (v) delete[] v;
		num = s.num;
		v = new ComplexDouble[num];
		state = 0;
	}
	for (int i = 0; i < num; i++)   v[i] = s.v[i];

	return *this;

};

VectorInt VectorInt::A(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);

	cout << "Add: \n";
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i] + 1;
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::B(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "Subtr: \n";
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i] - 1;
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}

bool VectorInt::C(VectorInt& s) {
	return (num != 0);
}

VectorInt VectorInt::D(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "-: \n";
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = -v[i];
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::E(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "=: \n";
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i];
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::F(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "+=: \n";
	for (int i = 0; i < tnum; i++) {
		v[i] += b.v[i];
	}
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i];
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::G(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "-=: \n";
	for (int i = 0; i < tnum; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < tnum; i++) {
		v[i] -= b.v[i];
	}
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i];
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::H(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "*=: \n";
	int a;
	cout << "Input a: "; cin >> a;
	for (int i = 0; i < tnum; i++) {
		v[i] *= a;
	}
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i];
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::I(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "/=: \n";
	int a;
	cout << "Input a: "; cin >> a;
	for (int i = 0; i < tnum; i++) {
		v[i] /= a;
	}
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i];
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::J(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "%=: \n";
	for (int i = 0; i < tnum; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	int a;
	cout << "Input a: "; cin >> a;
	for (int i = 0; i < tnum; i++) {
		v[i] = (int)v[i] % a;
	}
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i];
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}

VectorInt VectorInt::F1(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "+: \n";
	for (int i = 0; i < tnum; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i] + b.v[i];
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::G1(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "-: \n";
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i] - b.v[i];
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::H1(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "*: \n";
	int a;
	cout << "Input a: "; cin >> a;
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i] * a;
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::I1(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "/: \n";
	int a;
	for (int i = 0; i < tnum; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	cout << "Input a: "; cin >> a;
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = v[i] / a;
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::J1(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "%: \n";
	int a;
	for (int i = 0; i < tnum; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	cout << "Input a: "; cin >> a;
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = (int)v[i] % a;
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}

VectorInt VectorInt::A1(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);

	cout << ">> : \n";
	for (int i = 0; i < tnum; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = (int)v[i] >> 1;
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::B1(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "<< : \n";
	for (int i = 0; i < tnum; i++) {
		tmp.v[i] = (int)v[i] << 1;
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::C1(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "==: \n";
	for (int i = 0; i < tnum; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < tnum; i++) {
		if (v[i] == v[i + 1]) { tmp.v[i] = 1; }
		else tmp.v[i] = 0;
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}
VectorInt VectorInt::C11(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "!=: \n";
	for (int i = 0; i < tnum; i++) {
		if (v[i] != v[i + 1]) { tmp.v[i] = 1; }
		else tmp.v[i] = 0;
	}
	for (int i = 0; i < tnum; i++) {
		return tmp;
	}
}

double& VectorInt::A2(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	cout << "[]: \n";
	cout << "Input Index: ";
	int a, codeError = 0;

	ComplexDouble q;
	cin >> a;
	for (int i = 0; i < tnum; i++) {
		cout << v[i] << " ";
	}
	for (int i = 0; i < tnum; i++) {
		if ((a < 0) || (a >= tnum)) { q = v[tnum - 1]; codeError = 1; goto e; }
	}
	for (int i = 0; i < tnum; i++) {
		if (i == a) { q = v[i]; }
	}
e:

	if (codeError != 0) { cout << "\nError: " << codeError; }
	cout << "\nEl:" << q;
	return q;
}

bool VectorInt::Bi(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	bool vc = 0;
	string t;
	cout << "1: ";
	for (int i = 0; i < tnum; i++) {
		cout << v[i] << " ";
	}
	cout << "\n2: ";
	for (int i = 0; i < tnum; i++) {
		cout << b.v[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < tnum; i++) {
		if (v[i] > b.v[i]) { t += "true "; }
		else { t += "false "; }
	}

	cout << "\nResult: " << t;
	return vc;
}
bool VectorInt::Ci(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	bool vc = 0;
	string t;

	cout << "\n";
	for (int i = 0; i < tnum; i++) {
		if (v[i] >= b.v[i]) { t += "true "; }
		else { t += "false "; }
	}
	cout << "Result: " << t;
	return vc;
}
bool VectorInt::Di(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	bool vc = 0;
	string t;

	for (int i = 0; i < tnum; i++) {
		if (v[i] < b.v[i]) { t += "true "; }
		else { t += "false "; }
	}
	cout << "Result: " << t;
	return vc;
}
bool VectorInt::Ei(VectorInt& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	VectorInt tmp(tnum);
	bool vc = 0;
	string t;

	for (int i = 0; i < tnum; i++) {
		if (v[i] <= b.v[i]) { t += "true "; }
		else { t += "false "; }
	}
	cout << "Result: " << t;
	return vc;
}

void VectorInt::Input() {
	int in_num = 0;
	do {
		cout << "Input size Vec\n";
		cin >> in_num;
	} while (in_num <= 0);
	if (num != in_num) {
		num = in_num;
		if (v) delete[] v;
		v = new ComplexDouble[num];
	}
	for (int i = 0; i < num; i++) {

#if defined(_MSC_VER)
		cout << " v [ " << i << " ] real img  "; cin >> v[i];
#else 
		double re, im;
		cout << " v [ " << i << " ] real img  "; cin >> re >> im;
		v[i].real(re);
		v[i].imag(im);
#endif    
	}
}

void VectorInt::Output() {
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << " v [ " << i << " ]   " << v[i] << '\t';
			cout << endl;
		}
	}
}
void VectorInt::Output1() {
	if (num != 0) {
		for (int i = 0; i < num - 1; i++) {
			cout << " v [ " << i << " ]   " << v[i] << '\t';
			cout << endl;
		}
	}
}

int main1() {
	ComplexDouble a(1), b, c;
	cout << a << endl;
#if defined(_MSC_VER)
	b = 21.3;
	b = 22.3;
#else 
	b.real(21.3);
	b.imag(22.3);
#endif  

	cout << b << endl;
	c = a + b;
	cout << c << endl;
	cout << " Test  " << endl;
	VectorInt VecObj, VecObj1(10);
	cout << "VecObj \n";
	VecObj.Output();
	cout << "VecObj1 \n";
	VecObj1.Output();
	cout << "Input a " << endl;

#if defined(_MSC_VER)
	cin >> a;
#else 
	double re, im;
	cin >> re >> im;
	a.real(re);
	a.imag(im);
#endif    

	cout << a << endl;
	VectorInt VecObj2(10, a);
	VecObj2.Output();


	VecObj.Input();
	cout << endl;
	VecObj.Output();



	cout << "\n1 \n";
	VecObj1 = VecObj.A(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n2 \n";
	VecObj1 = VecObj.B(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n3 \n";
	if (VecObj.C(VecObj2) == 1) {
		cout << "true";
	}
	else cout << "false";
	cout << "\n";

	cout << "\n4 \n";
	VecObj1 = VecObj.D(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n5 \n";
	VecObj1 = VecObj.E(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n6 \n";
	VecObj1 = VecObj.F(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n7 \n";
	VecObj1 = VecObj.G(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n8 \n";
	VecObj1 = VecObj.H(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n9 \n";
	VecObj1 = VecObj.I(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n10 \n";
	VecObj1 = VecObj.J(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n13 \n";
	VecObj1 = VecObj.F1(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n14 \n";
	VecObj1 = VecObj.G1(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n15 \n";
	VecObj1 = VecObj.H1(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n16 \n";
	VecObj1 = VecObj.I1(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n17 \n";
	VecObj1 = VecObj.J1(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n18 \n";
	VecObj1 = VecObj.A1(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n19 \n";
	VecObj1 = VecObj.B1(VecObj2);
	VecObj1.Output();
	cout << endl;

	cout << "\n20 \n";
	VecObj1 = VecObj.C1(VecObj2);
	VecObj1.Output1();
	cout << endl;

	cout << "\n21 \n";
	VecObj1 = VecObj.C11(VecObj2);
	VecObj1.Output1();
	cout << endl;

	cout << "\n22 \n";
	VecObj1 = VecObj.A2(VecObj2);
	cout << endl;

	cout << "\n23 \n";
	VecObj1 = VecObj.Bi(VecObj2);
	cout << "\n";

	cout << "\n24 \n";
	VecObj1 = VecObj.Ci(VecObj2);
	cout << "\n";

	cout << "\n25 \n";
	VecObj1 = VecObj.Di(VecObj2);
	cout << "\n";

	cout << "\n26 \n";
	VecObj1 = VecObj.Ei(VecObj2);
	cout << "\n";




	return 0;
}


typedef unsigned int uint;

struct n {
	unsigned short a;
	string b;
	bool operator==(n& s)
	{
		return a == s.a && b == s.b ? true : false;
	}
	bool operator>(n& s)
	{
		if (a > s.a) return true;
		if (a < s.a) return false;
		return b > s.b ? true : false;
	}
};

ostream& operator<<(ostream& os, n& t) {
	if ((t.a < 0) && (t.a > 100)) os << "0" << t.a; else os << " " << t.a;
	os << " :" << t.b;
	os << " ";
	return os;
}

istream& operator>>(istream& iso, n& t) {
	iso >> t.a >> t.b;
	t.a %= 100;
	return iso;
}

class m
{
	uint* Number;
	n* Mas;
	int a;
	string b;
	int State;
public:
	m() : a(0), b() {
		Number = new uint[20]; Mas = new n[20];
	}
	~m() {
		if (Number != nullptr) delete[] Number;
		if (Mas != nullptr) delete[] Mas;
	}
	m(int size, uint* mf, n* tm) : a(size) {
		Number = new uint[a]; Mas = new n[a];
		for (int i = 0; i < size; i++) {
			Number[i] = mf[i];
			Mas[i] = tm[i];
		}
	}
	void TableFlight()
	{
		cout << " Test \n";
		int k;
		cout << "Input index: ";
		cin >> k;
		if ((k < 0) || (k > 100)) {
			int CodeError = 2;
			cout << "Error: " << CodeError << "\n";
			return;
		}
		for (int i = 0; i < a; i++) {
			if (i == k - 1) {
				cout << Mas[i] << endl;
			}
		}

	}
	uint operator[](n& s) {
		uint f = 0;
		for (int i = 0; i < a; i++)
			if (Mas[i] == s) return Number[i];
		cout << " Error: item not found ";
		State = -1;
		return f;
	}
	n operator[](uint& s) {
		n c{ 0 };
		for (int i = 0; i < a; i++)
			if (Number[i] == s) return Mas[i];
		cout << " Error: item not found ";
		State = -1;
		return c;
	}
	void operator()(uint a, uint b) {
		bool t = false;
		for (int i = 0; i < a; i++)
			if (Mas[i].a >= a && Mas[i].a <= b) {
				cout << Number[i] << "\t";
				t = true;
			}
		if (t == false) cout << " Item not found \n";
		cout << endl;
		return;
	}
};

int main2() {
	cout << " End begin \n";
	uint F[100] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100 };
	n T[100] = { {1," one"}, {2," two"}, {3," three"}, {4," four"} , {5," five"}, {6," six"}, {7," seven"}, {8," eight"}, {9," nine"}, {10," ten"},
	{11," eleven"}, {12," twelve"}, {13," thirteen"}, {14," fourteen"} , {15," fifteen"}, {16," sixteen"}, {17," seventeen"}, {18," eighteen"}, {19," nineteen"}, {20," twenty"},
	{21," twenty-one"}, {22," twenty-two"}, {23," twenty-three"}, {24," twenty-four"} , {25," twenty-five"}, {26," twenty-six"}, {27," twenty-seven"}, {28," twenty-eight"}, {29," nine"}, {30," ten"},
	{31," thirty-one"}, {32," thirty-two"}, {33," thirty-three"}, {34," thirty-four"} , {35," thirty-five"}, {36," thirty-six"}, {37," thirty-seven"}, {38," thirty-eight"}, {39," thirty-nine"}, {40," forty"},
	{41," forty-one"}, {42," forty-two"}, {43," forty-three"}, {44," forty-four"} , {45," forty-five"}, {46," forty-six"}, {47," forty-seven"}, {48," forty-eight"}, {49," forty-nine"}, {50," fifty"},
	{51," fifty-one"}, {52," fifty-two"}, {53," fifty-three"}, {54," fifty-four"} , {55," fifty-five"}, {56," fifty-six"}, {57," fifty-seven"}, {58," fifty-eight"}, {59," fifty-nine"}, {60," sixty"},
	{61," sixty-one"}, {62," sixty-two"}, {63," sixty-three"}, {64," sixty-four"} , {65," sixty-five"}, {66," sixty-six"}, {67," sixty-seven"}, {68," sixty-eight"}, {69," sixty-nine"}, {70," seventy"},
	{71," seventy-one"}, {72," seventy-two"}, {73," seventy-three"}, {74," seventy-four"} , {75," seventy-five"}, {76," seventy-six"}, {77," seventy-seven"}, {78," seventy-eight"}, {79," seventy-nine"}, {80," eighty"},
	{81," eighty-one"}, {82," eighty-two"}, {83," eighty-three"}, {84," eighty-four"} , {85," eighty-five"}, {86," eighty-six"}, {87," eighty-seven"}, {88," eighty-eight"}, {89," eighty-nine"}, {90," ninety"},
	{91," ninety-one"}, {92," ninety-two"}, {93," ninety-three"}, {94," ninety-four"} , {95," ninety-five"}, {96," ninety-six"}, {97," ninety-seven"}, {98," ninety-eight"}, {99," ninety-nine"}, {100," one hundred"} };
	m dbase(100, F, T);
	dbase.TableFlight();
	return 0;
}


int main()
{
	int n;
	cout << "N: ";
e: cin >> n;

	switch (n) {
	case 1: main1(); break;
	case 2: main2(); break;
	default: cout << "Error\n"; goto e;
	}

	return 0;
}

