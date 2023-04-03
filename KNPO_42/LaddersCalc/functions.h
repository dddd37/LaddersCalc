#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>

class Functions
{
public:
    int countOfLadders(int prevStep, int cubeCount);
};

/*!
* Cчитает количество лесенок, которые можно сделать из cubeCount.
*\param[in] prevStep - Количество кубиков в предыдущей ступеньке.
*\param[in] cubeCount - Общее количество кубиков (1<=cubeCount<=100).
*\return – Количество лесенок.
*/
int Functions::countOfLadders(int prevStep, int cubeCount)
{
    if(cubeCount==0) // если количество кубиков равно 0
    return 1; // лесенку получилось построить

  int count = 0; // обнулить количество лесенок
  for (int level = 1; level < prevStep; ++level) // для каждой ступеньки лестницы, начиная со второй
  {
    count += countOfLadders(level, cubeCount - level); // прибавить к количеству лесенок результат вызова функции подсчета лесенок
  }

  return count; // вернуть значение количество лесенок
}

#endif // FUNCTIONS_H
