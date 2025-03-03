#include<iostream>
using namespace std;

class Square{

    private:
    float sideLength;
    float area;
    static float allareas;

    public:

    Square(){
        sideLength = 0.0;
        area = 0.0;
    }

    Square(float sideLength){
        this->sideLength = sideLength;
    }

    float calarea(float sideLength){
        area = sideLength*sideLength;
        allareas = allareas + area;
        return area;
    }

    void setsideLength(float side){
        sideLength = side;
    }
    void setarea(float Area){
        area = Area;
    }
    void setallareas(float Allareas){
        allareas = Allareas;
    }
    float getsideLength(){
        return sideLength;
    }
    float getarea(){
        return area;
    }
    float getallareas(){
        return allareas;
    }
};
float Square::allareas = 0.0;

int main(){

    Square S1(4.0);
    Square S2(5.0);
    Square S3(2.0);

    S1.calarea(4.0);
    cout << "The Area of Square 1: " << S1.getarea() << endl;
    cout << "All Areas: " << S1.getallareas() << endl;
    S2.calarea(5.0);
    cout << "The Area of Square 2: " << S2.getarea() << endl;
    cout << "All Areas: " << S2.getallareas() << endl;
    S3.calarea(2.0);
    cout << "The Area of Square 3: " << S3.getarea() << endl;
    cout << "All Areas: " << S3.getallareas() << endl;
    
    return 0;
}
