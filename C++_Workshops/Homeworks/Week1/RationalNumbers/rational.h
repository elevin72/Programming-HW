#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
public:
    Rational(int num, int denom): _num(num), _denom(denom ? denom : 1){}
    Rational(){}
    int GetNum(){return _num;}
    int GetDenom(){return _denom;}
    void SetNum(int n){_num = n;}
    void SetDenom(int d){_denom = d;}
    void Print();
    bool Equal(Rational);
    
private:
    int _num;
    int _denom;
    Rational ReduceFrac();  
};

#endif

