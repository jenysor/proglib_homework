#include "exception_handler.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <queue>

class ICommand {
public:
    virtual void execute() = 0;
};

class TestExceptions : public testing::Test {
public:
    ExeptionHandler handler;
    std::queue<std::shared_ptr<ICommand>> queue;
};

TEST_F(TestExceptions, d)
{
    auto cmd = queue.front();
    queue.pop();

    try {
        cmd->execute();
    }
    catch (const std::exception &e) {
        handler.handleExeption();
    }
}