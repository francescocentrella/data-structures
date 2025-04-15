#include <iostream>

#include <iomanip>

using namespace std;

//Francesco Pio Centrella

struct dimensions
{
    float length,
          width;
};

struct results
{
    float area,
          perimeter;
};

struct rectangle
{
    results attributes;
    dimensions sizes;
};

results calculateArea (dimensions *sizes);

results calculatePerimeter (dimensions *sizes);


int main()
{
  rectangle box;
  results calculation;

  cout << "Enter the length of a rectangle: ";
  cin >> box.sizes.length;

  cout << "Enter the width of a rectangle: ";
  cin >> box.sizes.width;

  box.attributes = calculateArea(&box.sizes);

  box.attributes = calculatePerimeter(&box.sizes);

  cout << fixed << showpoint << setprecision(2);

  cout << "The area of the rectangle is " << box.attributes.area << " ";

  cout << "The perimeter of the rectangle is " << box.attributes.perimeter << endl;

  return 0;

}

results calculateArea (dimensions *sizes)
{
    results temp;
    temp.area = ((sizes->width) * (sizes->length));
    return temp;
}


results calculatePerimeter (dimensions *sizes)
{
    results temp;
    temp.perimeter = ((sizes->width * 2) + (sizes->length * 2));
    return temp;
}