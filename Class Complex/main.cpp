#include"complex.h"
#include<iostream>
#include<math.h>

using namespace std;



            int main()
{
    Complex value1(5,2);
    Complex value2(3,-3);
 
    cout << value1 << "; " << value2 << endl;
 
    cout << value1 + value2 << endl;
 
    cout << value1 - value2 << endl;
 
    cout << value1 * value2 << endl;
 
    cout << value1 / value2 << endl;    
 
    value1 = value2;
 
    cout << value1 << " = " << value2 << endl;
    

	system("pause");
    return 0;
}
 