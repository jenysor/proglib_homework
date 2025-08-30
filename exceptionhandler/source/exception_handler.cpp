#include "exception_handler.h"
#include <utility>

WriteExceptionToLogByQueueHandler::WriteExceptionToLogByQueueHandler(
    std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q) :
    queue(std::move(q))
{}

bool WriteExceptionToLogByQueueHandler::canHandleException(const std::exception& e) const
{
	return true;
}

void WriteExceptionToLogByQueueHandler::handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const
{
	queue->push(std::make_shared<WriteExceptionToLogCommand>(e));
}

RepeatCommandByQueueHandler::RepeatCommandByQueueHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q) :
    queue(std::move(q))
{}

bool RepeatCommandByQueueHandler::canHandleException(const std::exception& e) const
{
	return true;
}

void RepeatCommandByQueueHandler::handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const
{
	queue->push(std::make_shared<RepeatCommand>(cmd));
}

RepeatAndWriteToLogHandler::RepeatAndWriteToLogHandler()
{}

bool RepeatAndWriteToLogHandler::canHandleException(const std::exception& e) const
{
	return true;
}

void RepeatAndWriteToLogHandler::handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const
{
	try {
		RepeatCommand repeatCmd(cmd);
		repeatCmd.execute();
	}
	catch(const std::exception& ex) {
		WriteExceptionToLogCommand logCmd(ex);
		logCmd.execute();
	}
}

RepeatTwiceAndWriteToLogHandler::RepeatTwiceAndWriteToLogHandler()
{}

bool RepeatTwiceAndWriteToLogHandler::canHandleException(const std::exception& e) const
{
	return true;
}

void RepeatTwiceAndWriteToLogHandler::handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const
{
	RepeatTwiceCommand repeatTwiceCmd(cmd);
	repeatTwiceCmd.execute();

	WriteExceptionToLogCommand logCmd(e);
	logCmd.execute();
}
