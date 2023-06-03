#ifndef MODULATE_H
#define MODULATE_H
using namespace std;

class Modulate{
public:
    Modulate();
    double get_frequency();
    int get_depth();
    int get_type();


    void set_frequency(double frequency);
    void set_depth(int depth);
    void set_type(int type);


private:
    double _frequency;
    int _depth;
    int _type;

};

#endif // MODULATE_H
