#include <iostream>
#include <cmath>

#include <limits>
#include <cfloat>
//int для целых значений сторон трапеции
//short для значения высоты,т.к. оно занимает мало места(<=255)
/*float для дробных значений площади*/
int main() {
      int x;
      int y;
      short z;
      std::cin>>x>>y>>z;
      float w= ((x+y)/2)*z ;
     
      std::cout <<"answer="<<w<<" "<<"float"<<"\n";
      std::cout<<"float: min="<<std::numeric_limits<float>::min()<<" "<<"max="<<std::numeric_limits<float>::max()<<" "<<"size="<<"32"<<"\n";
      std::cout<<"int: min="<<std::numeric_limits<int>::min()<<" "<<"max="<<std::numeric_limits<int>::max()<<" "<<"size="<<"16"<<"\n";
      std::cout<<"short: min="<<std::numeric_limits<short>::min()<<" "<<"max="<<std::numeric_limits<short>::max()<<" "<<"size="<<"16";


      


      return 0;
}