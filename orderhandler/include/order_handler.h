#ifndef PROGLIB_HOMEWORK_ORDER_HANDLER_H
#define PROGLIB_HOMEWORK_ORDER_HANDLER_H

#include "interfaces.h"
#include <memory>
#include <queue>

class IOrderHandler {
public:
	virtual void handleOrder(std::shared_ptr<IUObject> order, std::shared_ptr<IUObject> object) const = 0;

	virtual ~IOrderHandler() = default;
};

class StartMoveHandler : public IOrderHandler {
public:
	explicit StartMoveHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue);

	void handleOrder(std::shared_ptr<IUObject> order, std::shared_ptr<IUObject> object) const override;

	~StartMoveHandler() override = default;

private:
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue;
};

class EndMoveHandler : public IOrderHandler {
public:
	explicit EndMoveHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue);

	void handleOrder(std::shared_ptr<IUObject> order, std::shared_ptr<IUObject> object) const override;

	~EndMoveHandler() override = default;

private:
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue;
};

class StartRotateHandler : public IOrderHandler {
public:
	explicit StartRotateHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue);

	void handleOrder(std::shared_ptr<IUObject> order, std::shared_ptr<IUObject> object) const override;

	~StartRotateHandler() override = default;

private:
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue;
};

class EndRotateHandler : public IOrderHandler {
public:
	explicit EndRotateHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue);

	void handleOrder(std::shared_ptr<IUObject> order, std::shared_ptr<IUObject> object) const override;

	~EndRotateHandler() override = default;

private:
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue;
};

#endif // PROGLIB_HOMEWORK_ORDER_HANDLER_H
