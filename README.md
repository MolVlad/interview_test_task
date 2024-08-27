# Тестовое задание по MLSE

Постановка задачи:
- Сделать fork репозитория.
- Реализовать [MLSE эквалайзер](https://wirelesspi.com/maximum-likelihood-sequence-estimation-mlse-equalizer/) в Матлабе (файл mlse.m).
- Модернизировать скрипт mlseExperiment.m так, чтобы можно было проанализировать BER от SNR как функцию от номера бита в блоке. Убедиться, что BER не зависит от номера бита в блоке (если это не так, проверьте инициализацию и терминирование Витерби алгоритма).
- Перенести класс mlse.m на С++ и продемонстрировать соответствие модели (способ демонстрации на усмотрение кандидата).
- Предложить изменения, которые необходимо внести в реализованный эквалайзер, чтобы понизить вычислительную сложность (возможно, путем небольшого уменьшения помехоустойчивости).
- Вставить результаты в README.md, залить весь код в свой fork, сделать merge request.

Требования к оформлению:
- Код С++ должен компилироваться с g++ -std=c++17. При необходимости можно написать makefile, однако в таком случае нужно указать, как собирать программу.
- Должно быть использовано осознанное наименование переменных (по смыслу).
- Эквалайзер на С++ должен быть оформлен в виде класса, также должны быть предусмотрены всевозможные проверки входных данных (защита от дурака).
