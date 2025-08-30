#include "handler_pool.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <queue>

class MockCommand : public ICommand {
public:
    MOCK_METHOD(void, execute, (), (override));
};

class TestExceptions : public testing::Test {
public:
    TestExceptions() {
        handlerPool = std::make_unique<HandlerPool>();

        queue = std::make_shared<std::queue<std::shared_ptr<ICommand>>>();
        queue->push(std::make_shared<MockCommand>());
    }

    std::unique_ptr<HandlerPool> handlerPool;
    std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue;
};

TEST_F(TestExceptions, WriteToLogByQueueHandler_PushWriteToLogCommandToQueue_Sucess)
{
    handlerPool->registerHandler(std::make_shared<WriteExceptionToLogByQueueHandler>(queue));

    auto cmd = queue->front();
    queue->pop();

    auto mockObject = dynamic_cast<MockCommand *>(cmd.get());
    EXPECT_CALL(*mockObject, execute()).WillOnce(testing::Invoke([]() {
        throw std::runtime_error("execute failed");
    }));

    try {
        cmd->execute();
    }
    catch (const std::exception &e) {
        handlerPool->handleExeption(cmd, e);
    }

    ASSERT_EQ(queue->size(), 1);
    ASSERT_TRUE(dynamic_cast<WriteExceptionToLogCommand *>(queue->front().get()));
    queue->front()->execute();
}

TEST_F(TestExceptions, RepeatCommandByQueueHandler_PushRepeatCommandToQueue_Sucess)
{
    handlerPool->registerHandler(std::make_shared<RepeatCommandByQueueHandler>(queue));

    auto cmd = queue->front();
    queue->pop();

    auto mockObject = dynamic_cast<MockCommand *>(cmd.get());
    EXPECT_CALL(*mockObject, execute()).WillRepeatedly(testing::Invoke([]() {
        throw std::runtime_error("execute failed");
    }));

    try {
        cmd->execute();
    }
    catch (const std::exception &e) {
        handlerPool->handleExeption(cmd, e);
    }

    ASSERT_EQ(queue->size(), 1);
    ASSERT_TRUE(dynamic_cast<RepeatCommand *>(queue->front().get()));
}

TEST_F(TestExceptions, RepeatAndWriteToLogHandler_RepeatAndWriteToLog_Sucess)
{
    handlerPool->registerHandler(std::make_shared<RepeatAndWriteToLogHandler>());

    auto cmd = queue->front();
    queue->pop();

    auto mockObject = dynamic_cast<MockCommand *>(cmd.get());
    EXPECT_CALL(*mockObject, execute()).WillRepeatedly(testing::Invoke([]() {
        throw std::runtime_error("execute failed");
    }));

    try {
        cmd->execute();
    }
    catch (const std::exception &e) {
        handlerPool->handleExeption(cmd, e);
    }

    ASSERT_EQ(queue->size(), 0);
}

TEST_F(TestExceptions, RepeatTwiceAndWriteToLogHandler_RepeatTwiceAndWriteToLog_Sucess)
{
    handlerPool->registerHandler(std::make_shared<RepeatTwiceAndWriteToLogHandler>());

    auto cmd = queue->front();
    queue->pop();

    auto mockObject = dynamic_cast<MockCommand *>(cmd.get());
    EXPECT_CALL(*mockObject, execute()).WillRepeatedly(testing::Invoke([]() {
        throw std::runtime_error("execute failed");
    }));

    try {
        cmd->execute();
    }
    catch (const std::exception &e) {
        handlerPool->handleExeption(cmd, e);
    }

    ASSERT_EQ(queue->size(), 0);
}
