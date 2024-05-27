#ifndef SCHEDULE_H
#define SCHEDULE_H
class Schedule{
    protected:
        bool status;

    public:
        Schedule(bool);
        void setStatus(bool);
        void printStatus();
};

#endif