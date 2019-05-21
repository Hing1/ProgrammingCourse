#include "time.h"

Time::Time()
    : hrs(0), mins(0), secs(0) {}
Time::Time(int initHrs, int initMins, int initSecs) // constructor
    : hrs(initHrs), mins(initMins), secs(initSecs)
{
}
void Time::Set(int hours, int minutes, int seconds)
{
    hrs = hours;
    mins = minutes;
    secs = seconds;
}
void Time::Increment()
{
    secs++;
    if (secs >= 60)
    {
        secs = secs - 60;
        mins++;
    }
    if (mins >= 60)
    {
        mins = mins - 60;
        hrs++;
    }
    if (hrs >= 24)
        hrs = hrs - 24;
}
