#ifndef SINE_WAVE_H
#define SINE_WAVE_H
class sine_wave {
 public:
  sine_wave(); //constructor set a default value when claim the class.
  // mutators
  void set_frequency(double frequency);
  void set_phase(double phase);
  void set_Vpp(double Vpp);
  void set_Voffset(double Voffset);
  void set_Vhigh(double Vhigh);
  void set_Vlow(double Vlow);
  void set_length(int length);
  void set_sample_frequency(double sample_frequency);
  void set_noise(bool noise);
  void set_choose(bool choose);
  // accessors
  double get_frequency();
  double get_phase();
  double get_Vpp();
  double get_Voffset();
  double get_Vhigh();
  double get_Vlow();
  int get_length();
  double get_sample_frequency();
  bool get_noise();
  bool get_choose();
 private:
  double _frequency;
  double _phase;
  double _Vpp;
  double _Voffset;
  double _Vhigh;
  double _Vlow;
  int _length;
  double _sample_frequency;
  bool _noise;
  bool _choose;
};
#endif