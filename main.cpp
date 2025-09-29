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
      std::cout<<"float"<<"\n"<<"min="<<FLT_MIN<<" "<<"max="<<" "<<FLT_MAX<<" "<<"size="<<"32"<<"\n";
      std::cout<<"int"<<"\n"<<"min="<<INT_MIN<<" "<<"max="<<INT_MAX<<" "<<"size="<<"16"<<"\n";
      std::cout<<"short"<<"\n"<<"min="<<SHRT_MIN<<" "<<"max="<<SHRT_MAX<<" "<<"size="<<"16";


      


      return 0;
}