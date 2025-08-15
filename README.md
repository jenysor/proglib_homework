# ДЗ №1

# Complexity Level 1

Прямолинейное равномерное движение без деформации: [movable](movable/).

Поворот объекта вокруг оси: [rotating](rotating/).

Сборка проекта настроена через github-actions (этап Build).

# Complexity Level 2

Тесты расположены в папке с конкретной библиотекой в подпапке test.

Тесты на прямолинейное равномерное движение без деформации: [test_movable](movable/test/).

Запуск тестов настроен через через github-actions (этап Run tests with covarage).

# Complexity Level 3

Тесты на поворот объекта вокруг оси: [test_rotating](rotating/test/).

Ссылка на workflow: [Run tests](https://github.com/jenysor/proglib_homework/actions/workflows/run_tests.yml).

В конце этапа Run tests with covarage выводится краткая информация о покрытии кода тестами, также отчет можно скачать архивом (этап Upload covarage report).
