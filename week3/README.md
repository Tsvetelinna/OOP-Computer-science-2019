# ЗАДАЧИ:

### Зад. 1: Дефинирайте шаблонен клас Set, който поддържа следните операции:

	- Голяма четворка
	- bool add(T element) - добавя елемент. Връща true, ако елементът не е съществувал в множеството
	- bool contains(T element) - проверява дали елемент принадлежи на множеството
	- bool isEmpty()
	- bool remove(T element) - премахва елемент от множеството. Връща true, ако множеството е съдържало този елемент
	- int getSize() - връща броя елементи в множеството
	- operator==
	- operator+ - обединение на 2 множества (връща ново множество, без да променя текущото)
	- operator* - сечение на 2 множества (връща ново множество, без да променя текущото)
	- operator- - разлика на 2 множества (връща ново множество, без да променя текущото)

### Зад. 2: Към класа Set, добавете методите:

	- Set map(MapFn<T>); - променя всеки елемент от множеството
	- Set filter(Predicate<T>); - връща ново множество от елементите, които удовлетворяват условието
	- K reduce(ReduceFn<T>, K initialValue) - обединяване на елементите в един резултат

### Зад. 3: Използвайки класа Person от предното упражнение, имплементирайте map функция, която работи за Set<Person>. Функцията да увеличава възрастта на всеки Person в множеството с 1 година.

### Зад. 4: Използвайки класа Person от предното упражнение, имплементирайте filter функция, която работи за Set<Person>. Функцията да връща ново множество само от пълнолетни хора.

### Зад. 5: Използвайки класа Person от предното упражнение, имплементирайте reduce функция, която работи за Set<Person>. Функцията да връща true, ако всички хора от множеството имат шофьорска книжка, иначе false