#ifndef PROGLIB_HOMEWORK_COMMANDS_H
#define PROGLIB_HOMEWORK_COMMANDS_H

#include "interfaces.h"
#include <memory>

class WriteExceptionToLogCommand : public ICommand {
public:
    explicit WriteExceptionToLogCommand(std::exception e);

    void execute() override;

    ~WriteExceptionToLogCommand() override = default;

private:
    std::exception exception;
};

class RepeatCommand : public ICommand {
public:
    explicit RepeatCommand(std::shared_ptr<ICommand> cmd);

    void execute() override;

    ~RepeatCommand() override = default;

private:
    std::shared_ptr<ICommand> command;
};

class RepeatTwiceCommand : public ICommand {
public:
    explicit RepeatTwiceCommand(std::shared_ptr<ICommand> cmd);

    void execute() override;

    ~RepeatTwiceCommand() override = default;

private:
    std::shared_ptr<ICommand> command;
    std::shared_ptr<ICommand> repeatCommand;
};

#endif //PROGLIB_HOMEWORK_COMMANDS_H
