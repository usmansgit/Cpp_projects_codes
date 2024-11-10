#ifndef CLOCK_HH
#define CLOCK_HH


class Clock
{
public:
    Clock(int hour, int minute);
    void tick_tock();
    void print();
private:
    int hours_;
    int minutes_;
};

#endif // CLOCK_HH
