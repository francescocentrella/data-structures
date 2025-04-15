#include <iostream>

#include <iomanip>

using namespace std;

// Francesco Pio Centrella

struct dimensions 
{
    float lenght, 
          width;
};


struct rectangle
{
    float area, 
          perimeter;
    dimensions sizes;
};

int main()

{

  rectangle box;

  cout << "Enter the length of a rectangle: ";
  cin >> box.sizes.lenght;

  cout << "Enter the width of a rectangle: ";
  cin >> box.sizes.width;

  box.area = ((box.sizes.width) * (box.sizes.lenght));

  box.perimeter = ((box.sizes.width * 2) + (box.sizes.lenght * 2));

  cout << fixed << showpoint << setprecision(2);

  cout << "The area of the rectangle is " << box.area << " ";

  cout << "The perimeter of the rectangle is " << box.perimeter << endl;

  return 0;

}