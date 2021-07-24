#include <iostream>
using namespace std;

//Tinh tong chuoi S
int add(int n)
{
  if (n != 0)
    return n + add(n - 1);
  return 0;
}

//Tinh Fibonacci
int fibonacci_str(int num)
{
  if (num == 0)
    return 0;
  else if (num == 1)
    return 1;
  else
    return (fibonacci_str(num - 1) + fibonacci_str(num - 2));
}

//Tinh UCLN
int gcd(int a, int b)
{
  if (b != 0)
    return gcd(b, a % b);
  else
    return a;
}

int main()
{

  int n;
  int count, c = 0;
  int i, fact = 1, number;
  int a, b;

  //Tinh n!
  cout << "1.Tinh n!" << endl;
  cout << "Nhap so bat ky: ";
  cin >> number;
  for (i = 1; i <= number; i++)
  {
    fact = fact * i;
  }
  cout << "Giai thua cua " << number << " is: " << fact << endl;

  //Tinh S of 1 to N
  cout << "2. Tinh S=1+2+3+..+n" << endl;
  cout << "Nhap so bat ky: ";
  cin >> n;

  cout << "Tong =  " << add(n) << endl;
  ;

  //Tinh UCLN
  cout << "3. Tinh UCLN cua a & b" << endl;
  cout << "Nhap hai so a va b: ";
  cin >> a >> b;

  cout << "UCLN cua " << a << " & " << b << " la: " << gcd(a, b) << endl;

  //Tinh Fibona4cci
  cout << "4. Tinh day so Fibonacci." << endl;
  cout << "Nhap vao so luong cac so trong chuoi Fibonacci: ";
  cin >> count;
  cout << "Chuoi Fibonacci la: \n";
  for (i = 1; i <= count; i++)
  {
    cout << fibonacci_str(c) << endl;
    c++;
  }

  return 0;
}