#ifndef PARTICIPANT_H
#define PARTICIPANT_H

enum Limba{engleza,romana, germana, franceza};
class Participant
{
public:
    Participant();
    virtual Limba Vorbeste();
};

#endif // PARTICIPANT_H
