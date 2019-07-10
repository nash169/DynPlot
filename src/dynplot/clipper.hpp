#ifndef CLIPPER_HPP
#define CLIPPER_HPP

#include <cmath>

class Clipper {
public:
    Clipper(double max_data, double min_data, double max_win, double min_win);

    Clipper();

    virtual ~Clipper();

    double Resize(double current_data);

protected:
    double WIN_MAX;
    double WIN_MIN;
    double DATA_MAX;
    double DATA_MIN;

    double Q;
};

#endif // CLIPPER_HPP