#ifndef TRIWAVE_H
#define TRIWAVE_H

#include <string>
using namespace std;
class TriWave{
public:
    TriWave();
    double get_frequency(); //default 1khz
    double get_Vpp(); // default 1
    double get_Voffset(); //0
    double get_Vlow(); //-1
    double get_Vhigh(); //+1
    double get_phase(); //0
    bool get_Vmode();
    bool get_noise();
    double get_sample_frequency();
    int get_sample_points();
    string get_unit_frequency();
    string get_unit_V();

    //length
    void set_frequency(double frequency);
    void set_Vpp(double Vpp);
    void set_Voffset(double Voffset);
    void set_Vlow(double Vlow);
    void set_Vhigh(double Vhigh);
    void set_phase(double phase); // enter in Radian.
    void set_unit_frequency(string unit_frequency);
    void set_unit_V(string unit_V);
    void set_Vmode(bool Vmode);
    void set_noise(bool noise);
    void set_sample_frequency(double sample_frequency);
    void set_sample_points(int sample_points);

private:
    double _frequency;
    double _Vpp;
    double _Voffset;
    double _Vlow;
    double _Vhigh;
    double _phase;
    bool _Vmode; // determine whether the voltage is represented by Vpp and offset / Vhigh and Vlow
    bool _noise;
    double _sample_frequency;
    int _sample_points;
    string _unit_frequency;
    string _unit_V;
};

#endif // TRIWAVE_H
