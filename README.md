# Программирование, 2 курс. Занятие 7 #

## Задача ##

Ваш компьютер «не знает» арифметики вещественных чисел. Научите его выполнять операции сложения,
вычитания и умножения чисел с плавающей точкой, используя **только**:

- функции для работы с символами и строками,
- операции целочисленной арифметики.

Для этого определите структурный тип данных DECIMAL для представления конечной десятичной дроби, 
и напишите функции:

- `DECIMAL summarize(DECIMAL, DECIMAL)`,
- `DECIMAL subtract(DECIMAL, DECIMAL)`,
- `DECIMAL multiply(DECIMAL, DECIMAL)`,

Которые возвращают значения суммы, разности и произведения значений типа `DECIMAL`.

## Анализ задачи ##

Тип `DECIMAL` - конечная десятичная дробь. 

- ***Конечная десятичная дробь*** - это *десятичная* дробь, у которой после запятой стоит *конечное* число знаков.
- ***Десятичная дробь*** - это разновидность обыкновенной дроби. По определению:  
`decimal :: {num÷denum / num∈ Z, denum∈ N, denum⋮ 10, n∈N}`

Таким образом десятичную дробь можно представить в виде `{x÷10^n / x∈ Z, n∈ N}`