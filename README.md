# ДЗ №4

Обработчик try-catch перехватывает базовое исключение std::exception: [test_exceptions](exceptionhandler/test/).

Реализация команд: [commands](exceptionhandler/include/commands.h).

- Команда, которая записывает информацию о выброшенном исключении в лог: WriteExceptionToLogCommand.
- Команда, которая повторяет Команду, выбросившую исключение: RepeatCommand.
- Команда, которая повторяет команду дважды: RepeatTwiceCommand.

Реализация обработчиков: [exception_handlers](exceptionhandler/include/exception_handlers.h).

- Обработчик исключения, который ставит команду, пишущую в лог в очередь команд: WriteExceptionToLogByQueueHandler.
- Обработчик исключения, который ставит команду-повторитель в очередь команд: RepeatCommandByQueueHandler.
- Обработчик исключения, который повторяет команду, при повторном исключении пишет информацию в лог: RepeatAndWriteToLogHandler.
- Обработчик исключения, который повторяет команду дважды, потом пишет информацию в лог: RepeatTwiceAndWriteToLogHandler.

Запуск тестов настроен через через github-actions (этап Run tests with covarage).

Ссылка на workflow: [Run tests](https://github.com/jenysor/proglib_homework/actions/workflows/run_tests.yml).
