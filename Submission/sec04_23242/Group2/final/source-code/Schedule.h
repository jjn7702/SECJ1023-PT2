#ifndef SCHEDULE_H
#define SCHEDULE_H
class Schedule{
    protected:
        bool status;

    public:
        Schedule(bool);

        //mutators
        void setStatus(bool);

        //accessors
        void printStatus();
};

#endif
