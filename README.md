# ДЗ №5

Реализация команд проверки топлива CheckFuelCommand и использования топлива 
BurnFuelCommand: [fuelcommands](fuelcommands/).

Реализация макрокоманды: [macrocommand](macrocommand/).

Тесты расположены в папке с конкретной библиотекой в подпапке test.

Макрокоманда движения по прямой с расходом топлива реализована в тесте 
MacroFuelCommand_Execute_Success: [test_macrocommand](macrocommand/test/test_macrocommand.cpp).

Команда модификации мгновенной скорости CorrectInstantVelocityCommand: [command](macrocommand/include/macrocommand.h).

Запуск тестов настроен через через github-actions (этап Run tests with covarage).

Ссылка на workflow: [Run tests](https://github.com/jenysor/proglib_homework/actions/workflows/run_tests.yml).
