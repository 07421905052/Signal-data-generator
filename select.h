#ifndef SELECT_H
#define SELECT_H
class Select{
public:
    Select();
    int get_waveform1();
    int get_waveform2();
    void set_waveform1(int waveform1);
    void set_waveform2(int waveform2);
    int get_operation();
    void set_operation(int operation);
private:
    int _waveform1;
    int _waveform2;
    int _operation;
};

#endif
