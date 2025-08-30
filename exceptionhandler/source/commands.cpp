#include "commands.h"

WriteExceptionToLogCommand::WriteExceptionToLogCommand(std::exception e) : exception(std::move(e))
{}

void WriteExceptionToLogCommand::execute()
{
    std::cerr << "exception: " << exception.what() << std::endl;
}

RepeatCommand::RepeatCommand(std::shared_ptr<ICommand> cmd) : command(std::move(cmd))
{}

void RepeatCommand::execute()
{
    command->execute();
}

RepeatTwiceCommand::RepeatTwiceCommand(std::shared_ptr<ICommand> cmd)
    : command(cmd), repeatCommand(std::make_shared<RepeatCommand>(cmd))
{}

void RepeatTwiceCommand::execute()
{
    command->execute();
    repeatCommand->execute();
}
