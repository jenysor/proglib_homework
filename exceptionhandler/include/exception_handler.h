#ifndef PROGLIB_HOMEWORK_EXCEPTION_HANDLER_H
#define PROGLIB_HOMEWORK_EXCEPTION_HANDLER_H

#include <exception>
#include <memory>
#include <list>
#include <utility>
#include <iostream>
#include <queue>

// временно
class ICommand {
public:
	virtual void execute() = 0;

	virtual ~ICommand() = default;
};

class IExeptionHandler {
public:
	[[nodiscard]] virtual bool canHandleException(const std::exception& e) const = 0;

	virtual void handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const = 0;

	virtual ~IExeptionHandler() = default;
};

class WriteExceptionToLogByQueueHandler : public IExeptionHandler {
public:
	explicit WriteExceptionToLogByQueueHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q);

	[[nodiscard]] bool canHandleException(const std::exception& e) const override;

	void handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const override;

	~WriteExceptionToLogByQueueHandler() override = default;

private:
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue;
};

class RepeatCommandByQueueHandler : public IExeptionHandler {
public:
	explicit RepeatCommandByQueueHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q);

	[[nodiscard]] bool canHandleException(const std::exception& e) const override;

	void handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const override;

	~RepeatCommandByQueueHandler() override = default;

private:
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue;
};

class RepeatAndWriteToLogHandler : public IExeptionHandler {
public:
	explicit RepeatAndWriteToLogHandler();

	[[nodiscard]] bool canHandleException(const std::exception& e) const override;

	void handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const override;

	~RepeatAndWriteToLogHandler() override = default;
};

class RepeatTwiceAndWriteToLogHandler : public IExeptionHandler {
public:
	explicit RepeatTwiceAndWriteToLogHandler();

	[[nodiscard]] bool canHandleException(const std::exception& e) const override;

	void handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const override;

	~RepeatTwiceAndWriteToLogHandler() override = default;
};

class WriteExceptionToLogCommand : public ICommand {
public:
	explicit WriteExceptionToLogCommand(std::exception e) : exception(std::move(e))
	{}

	void execute() override
	{
		std::cerr << "exception: " << exception.what() << std::endl;
	}

	~WriteExceptionToLogCommand() override = default;

private:
	std::exception exception;
};

class RepeatCommand : public ICommand {
public:
	explicit RepeatCommand(std::shared_ptr<ICommand> cmd) : command(std::move(cmd))
	{}

	void execute() override
	{
		command->execute();
	}

	~RepeatCommand() override = default;

private:
	std::shared_ptr<ICommand> command;
};

class RepeatTwiceCommand : public ICommand {
	public:
	explicit RepeatTwiceCommand(std::shared_ptr<ICommand> cmd) : command(std::make_shared<RepeatCommand>(cmd))
	{}

	void execute() override
	{
		command->execute();
	}

	~RepeatTwiceCommand() override = default;

private:
	std::shared_ptr<ICommand> command;
};

#endif // PROGLIB_HOMEWORK_EXCEPTION_HANDLER_H
