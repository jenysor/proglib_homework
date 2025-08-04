#ifndef PROGLIB_HOMEWORK_ICOMMAND_H
#define PROGLIB_HOMEWORK_ICOMMAND_H

class ICommand
{
public:
    virtual void execute() = 0;

    virtual ~ICommand() = default;
};

#endif // PROGLIB_HOMEWORK_ICOMMAND_H
