#include <iostream>
#include <cstdio>

int main()
{
    for (int hour = 0, min = 0; std::cin >> hour >> min && (hour != 0 || min != 0); )
    {
        double degree1= hour * 30.0 + 0.5 * min; 
        double degree2 = min * 6.0;
        double degree = degree1 > degree2 ? degree1 - degree2 : degree2 - degree1;
        degree = degree > 180.0 ? 360.0 - degree : degree; 
        std::cout << "At " << hour << ":";
        printf("%02d", min);
        std::cout << " the angle is ";
        printf("%.1f", degree);
        std::cout << " degrees." << std::endl;
    }
    return 0;
}

