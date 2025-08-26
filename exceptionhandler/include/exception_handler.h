#ifndef PROGLIB_HOMEWORK_EXCEPTION_HANDLER_H
#define PROGLIB_HOMEWORK_EXCEPTION_HANDLER_H

#include <exception>
#include <memory>
#include <list>
#include <utility>
#include <iostream>

//временно
class ICommand {
public:
    virtual void execute() = 0;

    virtual ~ICommand() = default;
};

class IExeptionHandler {
public:
    virtual void registerHandler(std::shared_ptr<IExeptionHandler> handler) = 0;

    virtual void handleExeption(std::shared_ptr<ICommand> cmd, const std::exception &e) = 0;
};

class ExeptionHandler : public IExeptionHandler {
public:
    void registerHandler(std::shared_ptr<IExeptionHandler> handler) override;

    void handleExeption(std::shared_ptr<ICommand> cmd, const std::exception &e) override;

private:
    std::list<std::shared_ptr<IExeptionHandler>> handlers;
};

class WriteExceptionToLogCommand : public ICommand {
public:
    WriteExceptionToLogCommand(std::exception e) : exception(std::move(e))
    {}

    void execute() override
    {
        std::cerr << "exception: " << exception.what() << std::endl;
    }

    ~WriteExceptionToLogCommand() = default;

private:
    std::exception exception;
};

class RepeatCommand : public ICommand {
public:
    RepeatCommand(std::shared_ptr<ICommand> cmd) : command(std::move(cmd))
    {}

    void execute() override
    {
        command->execute();
    }

    ~RepeatCommand() = default;

private:
    std::shared_ptr<ICommand> command;
};



#endif //PROGLIB_HOMEWORK_EXCEPTION_HANDLER_H
