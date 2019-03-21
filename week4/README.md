# ЗАДАЧИ:

### Зад. 1: Да се имплементира клас **Jedi**, който да има следните член-данни:

```C++
* name - char*
* rank - enum {YOUNGLING, PADAWAN, KNIGHT, MASTER, GRAND_MASTER}
* age - unsigned short
* saberColor - char*
* strength - double
```

И съответно да притежава следните член-функции:

```C++
* Голяма четворка
* Конструктор с параметри
* Гетъри и сетъри за всички член данни
* operator==
* operator< - сравнява 2 Jedi по сила
* operator> - сравнява 2 Jedi по сила
```

### Зад. 2: Да се имплементира клас **JediOrder**, който да има следните член-данни:

```C++
* Jedi* jedi; - динамичен масив от джедаи
* char* planet
```

И съответно да притежава следните член-функции:

```C++
* Голяма четворка
* Гетъри и сетъри
* contains(Jedi jedi)
* Добавяне на джедай 
* Премахване на джедай (ако съществува в JediOrder-a)
* operator* - връща сечението на 2 jedi order-a
* operator+ - връща обединението на 2 jedi order-a
* operator*= - прави сечение на текущия jedi order с друг
* operator+= - прави обединение на текущия jedi order с друг
* operator[]
* Jedi getStrongestJedi() - метод, който намира най-силния джедай
* Jedi getYoungestJedi() - метод, който намира най-младия джедай
```

**Бонус задача**: Да се имплементира метод **getMostUsedSaberColor()** в класа JediOrder, който връща най-често срещания цвят мечове, който се използва от поне един MASTER.