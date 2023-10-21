
#include <iostream>
using namespace std;
#include <chrono>
#include <stack>
# define sizeArr 100000
using namespace std::chrono;
int* aray;

void say(int arr[]) {
    for (int i = 0; i < sizeArr; i++)
    {
        cout << arr[i]<<" ";
    }
    cout << "\n";
}


void say(stack<int> stack) {
    cout << stack.size() << " ";
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << "\n";
}
 void selectionSort(int arr[]) {
    int min, minId=0;
   
    for (int i = 0; i < sizeArr; i++)
    { min = arr[i];
        for (int j = i; j < sizeArr;j++)
        {
            if (min> arr[j])
            {
                min = arr[j];
                minId = j;
            }
        }
        arr[minId] = arr[i];
        arr[i] = min;

    }
}



 void insertionSort(int arr[]) {
     for (int i = 0 ; i < sizeArr; i++)
     {
         int temp = arr[i];
         int j = i - 1;
         while (j >= 0 && arr[j] > temp)
         {
             arr[j + 1] = arr[j];
             j--;
         }
         arr[j + 1] = temp;
     }
 }

 void bubbleSort(int arr[]) {
     int memery;
     bool flag = true;
     for (int i = 0; i < sizeArr - 1&&flag; i++) {
         flag = false;
         for (int j = 0; j < sizeArr - i - 1; j++) {
             if (arr[j] > arr[j + 1]) {
                 swap(arr[j], arr[j+1]);
                 flag = true;
             }
         }
     }
 }

void Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;

    // пока есть элементы в левом и правом рядах
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
        }
    }

    // копируем оставшиеся элементы
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
    while (j <= high) {
        aux[k++] = arr[j++];
    }

    // копируем обратно в исходный массив, чтобы отразить порядок сортировки
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
}

// Сортируем массив `arr[low…high]`, используя вспомогательный массив `aux`
void mergesort(int arr[], int aux[], int low, int high)
{
    // базовый вариант
    if (high <= low) {        // если размер прогона <= 1
        return;
    }

    // найти середину
    int mid = (low + ((high - low) >> 1));

    // рекурсивно разделяем прогоны на две половины до тех пор, пока размер прогона не станет <= 1,
    // затем объединяем их и возвращаемся вверх по цепочке вызовов

    mergesort(arr, aux, low, mid);          // разделить/объединить левую половину
    mergesort(arr, aux, mid + 1, high);     // разделить/объединить правую половину

    Merge(arr, aux, low, mid, high);        // объединить два полупрогона.
}

void quickSort(int arr[], int low, int high) {
    if (high - low>1)//сортируем более 2 элементов
    {
        int id = high;
        int counter=0;
        int member;
        for (int i = low; i <= high; i++)
        {
            if (arr[id]>arr[i]) {
                counter++;//считаем кол-во эл меньше выбранного
            }
        }

        swap(arr[id], arr[low + counter]);//ставим выбранный элемент между меньшими и большими числами
        
       
        int j= low;
        for (int i = low; i <= high; i++)//все числа меньше переставляем влево, все больше вправо
        {
            if (arr[low+counter] > arr[i]) {
                swap(arr[j], arr[i]);
                j++;
            }
        }

        if (counter==0)
        {
        quickSort(arr, low+counter+1, high);
        }
        else
        {
            quickSort(arr, low, low+counter - 1);
            quickSort(arr, low+counter, high);

        }
        
    }
    else if (arr[low] > arr[high]) {//если сортируем 2 эл проверяем их
        swap(arr[high], arr[low]);
    }
}

void quickSortMedian(int arr[], int low, int high) {
    if (high - low > 2)//сортируем более 3 элементов
    {
        
        int id = (low + high) / 2;//выбираем ~средний элемент
        if (arr[low] >= arr[high] && arr[low] <= arr[id]|| arr[low]>= arr[id] && arr[low] <= arr[high]) {
            id = low;
        }
        else if (arr[high] >= arr[low] && arr[high] <= arr[id] || arr[high]>= arr[id] && arr[high] <= arr[low]) {
            id = high;
        }
        
        int counter = 0;
        int member;
        for (int i = low; i <= high; i++)
        {
            if (arr[id] > arr[i]) {
                counter++;//считаем кол-во эл меньше выбранного
            }
        }

        swap(arr[id], arr[low + counter]);//ставим выбранный элемент между меньшими и большими числами


        int j = low;
        for (int i = low; i <= high; i++)//все числа меньше переставляем влево, все больше вправо
        {
            if (arr[low + counter] > arr[i]) {
                swap(arr[j], arr[i]);
                j++;
            }
        }

        if (counter == 0)
        {
            quickSort(arr, low + counter + 1, high);
        }
        else
        {
            quickSort(arr, low, low + counter - 1);
            quickSort(arr, low + counter, high);

        }

    }
    else{//если сортируем 3 эл проверяем их
        if (arr[low] > arr[high - 1]) swap(arr[high - 1], arr[low]);
        if (arr[low+1] > arr[high ]) swap(arr[high ], arr[low+1]);
        if (arr[low] > arr[high - 1]) swap(arr[high - 1], arr[low]);

    }
}
void shellSortDel2(int arr[])
{
    for (int step = sizeArr / 2; step > 0; step /= 2)//перебор всех шагов
    {
        for (int i = step; i < sizeArr; i += 1)//перебор всех наборов с данным шагом
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= step && arr[j - step] > temp; j -= step) {//проверка эллементов в наборе по алгоритму вставки
                arr[j] = arr[j - step];
            }

            arr[j] = temp;
        }
    }
}


void shellSortPow(int arr[])
{
    for (int istep = 1; 2 * istep - 1 < sizeArr;  istep++)//перебор всех шагов
    {
        int step = 2 * istep - 1;
        for (int i = step; i < sizeArr; i += 1)//перебор всех наборов с данным шагом
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= step && arr[j - step] > temp; j -= step) {//проверка эллементов в наборе по алгоритму вставки
                arr[j] = arr[j - step];
            }

            arr[j] = temp;
        }
    }
}

void shellSortTsiura(int arr[])
{
    int stepArr[9] = { 1750,701,301,132,57,23,10,4,1 };
    for (int istep = 0; istep<9; istep++)//перебор всех шагов
    {
        int step = stepArr[istep];
        if (step<sizeArr/2+1)
        {
            
            for (int i = step; i < sizeArr; i += 1)//перебор всех наборов с данным шагом
            {
                int temp = arr[i];
                int j;
                for (j = i; j >= step && arr[j - step] > temp; j -= step) {//проверка эллементов в наборе по алгоритму вставки
                    arr[j] = arr[j - step];
                }

                arr[j] = temp;
            }
        }
    }
}

 int getMinRunInsert(int n) {// оитимально от 32 до 64
    while (n >= 64) {//делим число на 2, пока оно больше 64
        n >>= 1;
    }
    return n ;
}

 void MergeTimsort(int arr[], int aux[], int low, int mid, int high) {
     int leftL = low;
     int rightL= mid-1;
     int serch = arr[mid];
     while (leftL < rightL&& rightL - leftL>1)
     {
         int mid = (rightL + leftL) / 2;
         if (arr[mid] == serch)
         {
             leftL = mid;
         }
         else if (arr[mid] < serch)
         {
             leftL = mid + 1;
         }
         else
         {
             rightL = mid - 1;
         }
     }

     int leftR = mid;
     int rightR = high;
      serch = arr[mid-1];
     while (leftR < rightR && rightR - leftR>1)
     {
         int mid = (rightR + leftR) / 2;
         if (arr[mid] == serch)
         {
             leftR = mid;
         }
         else if (arr[mid] < serch)
         {
             leftR = mid + 1;
         }
         else
         {
             rightR = mid - 1;
         }
     } 
    Merge(arr, aux, leftL, mid-1, rightR);
           
 }
 void StacRecursTimSort(int arr[], int aux[], int minRunInsert, stack<int> &stack, int step,int i) {
    
    


 int first, second, third;
         switch (stack.size())
         {
         case 1:
             break;
         case 2:
             first = stack.top();
             stack.pop();
             second = stack.top();
             stack.pop();

             if (first >= second)//не удовлетворяет первому правилу
             {
               
                 MergeTimsort(arr, aux, minRunInsert * (step - i-1), minRunInsert * (step - i- 1)+ first, minRunInsert * (step - i - 1)+ first + second-1);
                 
                 stack.push(first + second);
             }
             else
             {
                 stack.push(second);
                 stack.push(first);
             }
             break;
         default:
            
             first = stack.top();
             stack.pop();
             second = stack.top();
             stack.pop();
             third = stack.top();
             stack.pop();

                     
             if (first >= second || second >= third || first + second >= third)//не удовлетворяет правилам
             {
                 if (first >= third)
                 {
                      MergeTimsort(arr, aux, minRunInsert * (step - i - 1), minRunInsert * (step - i - 1)+ first, minRunInsert * (step - i - 1) + first + second-1);
                     stack.push(third);
                     stack.push(first+ second);
                     StacRecursTimSort(arr, aux, minRunInsert, stack,step, i);//проверить следующие группы на несоблюдение правил
                 }
                 else
                 {
                     
                     MergeTimsort(arr, aux, minRunInsert * (step - i - 1)+ first, minRunInsert * (step - i - 1)+ first + second, minRunInsert * (step - i - 1)+ first + second + third-1);
                     stack.push(third + second);
                     stack.push(first);
                     StacRecursTimSort(arr, aux, minRunInsert, stack,step, i);//проверить следующие группы на несоблюдение правил
                 }
             }
             else
             {
                 stack.push(third);
                 stack.push(second);
                 stack.push(first);
             }
             break;
         }
     
 }
 // Сортируем массив `arr[low…high]`, используя вспомогательный массив `aux`
 void Timsort(int arr[], int aux[],int size, int minRunInsert)
 {

    int FersteEementLastRun = size - (size % minRunInsert);
     for (int segment = 0; segment < FersteEementLastRun; segment+= minRunInsert)//сортируем отрезки
     {
         for (int i = segment; i < segment+ minRunInsert; i++)
         {
             int temp = arr[i];
             int j = i - 1;
             while (j >= segment && arr[j] > temp)
             {
                 arr[j + 1] = arr[j];
                 j--;
             }
             arr[j + 1] = temp;
         }
     }
     
     
     for (int i = FersteEementLastRun; i < size; i++)
     {
         int temp = arr[i];
         int j = i - 1;
         while (j >= FersteEementLastRun && arr[j] > temp)
         {
             arr[j + 1] = arr[j];
             j--;
         }
         arr[j + 1] = temp;
     }
     stack<int> stack;
     int step = sizeArr / minRunInsert;
     if (sizeArr % minRunInsert != 0) {
         stack.push(sizeArr % minRunInsert);

     }

     for (int i = 0; i < step; i++)
     {

         stack.push(minRunInsert);//все отрезки, кроме последнего, изначально одного размера
         StacRecursTimSort(arr, aux, minRunInsert, stack,step,i);
     }
     while (stack.size()>1)
     {
        int first = stack.top();
         stack.pop();
        int second = stack.top();
         stack.pop();
         MergeTimsort(arr, aux, size - second - first, size- second, size -1);
         stack.push(first + second);
     }
 }


 void heapify(int arr[], int n, int i)
 {
     int largest = i;
     // Инициализируем наибольший элемент как корень
     int l = 2 * i + 1; // левый = 2*i + 1
     int r = 2 * i + 2; // правый = 2*i + 2

     // Если левый дочерний элемент больше корня
     if (l < n && arr[l] > arr[largest])
         largest = l;

     // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
     if (r < n && arr[r] > arr[largest])
         largest = r;

     // Если самый большой элемент не корень
     if (largest != i)
     {
         swap(arr[i], arr[largest]);

         // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
         heapify(arr, n, largest);
     }
 }

 // Основная функция, выполняющая пирамидальную сортировку
 void pyramidSort(int arr[], int n)
 {
     // Построение кучи (перегруппируем массив)
     for (int i = n / 2 - 1; i >= 0; i--)
         heapify(arr, n, i);

     // Один за другим извлекаем элементы из кучи
     for (int i = n - 1; i >= 0; i--)
     {
         // Перемещаем текущий корень в конец
         swap(arr[0], arr[i]);

         // вызываем процедуру heapify на уменьшенной куче
         heapify(arr, i, 0);
     }
 }


 void IntroSort(int arr[], int low, int high,int step,int stepTopyramidSort) {
     if (high - low > 1)//сортируем более 2 элементов
     {
         int id = high;
         int counter = 0;
         int member;
         for (int i = low; i <= high; i++)
         {
             if (arr[id] > arr[i]) {
                 counter++;//считаем кол-во эл меньше выбранного
             }
         }

         swap(arr[low + counter], arr[id]);//ставим выбранный элемент между меньшими и большими числами
        

         int j = low;
         for (int i = low; i <= high; i++)//все числа меньше переставляем влево, все больше вправо
         {
             if (arr[low + counter] > arr[i]) {
                 swap(arr[j], arr[i]);
                 j++;
             }
         }
         if (step> stepTopyramidSort)
         {
             if (counter == 0)
             {
                 IntroSort(arr, low + counter + 1, high, step+1, stepTopyramidSort);
             }
             else
             {
                 IntroSort(arr, low, low + counter - 1, step+1, stepTopyramidSort);
                 IntroSort(arr, low + counter, high, step+1, stepTopyramidSort);

             }
         }
         else//создаем 2 массива, сортируем их пирамидальной сортировкой, а потом вставляем в изначальный массив
         {
             int* arr1eft =new int[ counter  ];
             int j = 0;
             for (int i = low; i < low + counter ; i++)
             {
                 arr1eft[j++] = arr[i];
             }
             j = 0;
             int* arrRight = new int[high - (low + counter)];
             for (int i = low + counter; i < high; i++)
             {
                 arrRight[j++] = arr[i];
             }
             pyramidSort(arr1eft,  counter - 1);
             pyramidSort(arrRight,  high- counter );
             j = 0;
             for (int i = 0 ; i < low + counter; i++)
             {
                 arr[i] = arr1eft[j++];
             }
             j = 0;
             for (int i = low + counter; i < high; i++)
             {
                 arr[i] = arrRight[j++];
             }
         }

     }
     else if (arr[low] > arr[high]) {//если сортируем 2 эл проверяем их
         swap(arr[low], arr[high]);
     }
 }

 void creatSorted(int* arr) {
 //выбираем какой вид заполнения масива
    
   /*
     for (int i = 0; i < size; i++)
     {
         arr[i] = i;
     } 
     */
     // swap(arr[size/2] , arr[size/2+1]);//для Почти отсортированного массива 
    

      for (int i = 0; i < sizeArr; i++)
     {
         arr[i] = sizeArr-i;
     }
     
     //arr = aray;//случайный масив
     
 }

int main()
{

    srand(time(0));
    aray = new int[sizeArr];
    int arr[sizeArr];
    int arr2[sizeArr];//некоторые сортировки требуют вспомогательный массив
    for (int i = 0; i < sizeArr; i++)
    {
        aray[i] = rand();
    }


    auto begin = steady_clock::now();
    auto end = steady_clock::now();
   
    
/*
       
    creatSorted(arr);
    begin = steady_clock::now();
    selectionSort(arr);
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";
    

    creatSorted(arr);
    begin = steady_clock::now();
    insertionSort(arr);
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";

    creatSorted(arr);
    begin = steady_clock::now();
    bubbleSort(arr);
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";

    creatSorted(arr);
    creatSorted(arr2);
    begin = steady_clock::now();
    mergesort(arr, arr2, 0, sizeArr - 1);
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";
    */
/*
    creatSorted(arr);
    begin = steady_clock::now();
    quickSort(arr, 0, size - 1);
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";
*/
    /*
    creatSorted(arr);
    begin = steady_clock::now();
    shellSortDel2(arr);
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";
    

    creatSorted(arr);
    begin = steady_clock::now();
    shellSortPow(arr);
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";

    creatSorted(arr);
    begin = steady_clock::now();
    shellSortTsiura(arr);
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";
*/
    creatSorted(arr);
    creatSorted(arr2);
    begin = steady_clock::now();
    Timsort(arr, arr2,  sizeArr , getMinRunInsert(sizeArr));
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";
   
   /*
    creatSorted(arr);
    begin = steady_clock::now();
    pyramidSort(arr, sizeArr);
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";
    
    creatSorted(arr);
    begin = steady_clock::now();
    IntroSort(arr, 0, sizeArr - 1, 0, log(sizeArr));
    end = steady_clock::now();
    std::cout << duration_cast<microseconds>(end - begin).count() << " \n";
    */
}
