#ifndef COORDINATE_H
#define COORDINATE_H
#define PI 3.14159265

class caculate_coordinate {
 public:
  // only accessors and mutators are public in this example
  void set_abscissa(double abscissa);
  double get_coordinate();
 private:
  // member variables are private and set/get via accessor/mutator
  double _abscissa;
  double _coordinate;
};

#endif