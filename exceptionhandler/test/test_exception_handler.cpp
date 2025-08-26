#include "exception_handler.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <queue>

class MockCommand : public ICommand {
public:
    MOCK_METHOD(void, execute, (), (override));
};

class TestExceptions : public testing::Test {
public:
    std::unique_ptr<IExeptionHandler> handler;
    std::shared_ptr<std::queue<std::shared_ptr<MockCommand>>> queue;
};

TEST_F(TestExceptions, d)
{
    auto cmd = std::make_shared<MockCommand>();

    try {
        cmd->execute();
    }
    catch (const std::exception &e) {
        handler->handleExeption(cmd, e);
    }
}