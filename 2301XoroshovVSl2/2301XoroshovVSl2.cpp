
#include <iostream>
using namespace std;
#include <chrono>
#include <stack>

using namespace std::chrono;
int* aray;

void say(int arr[], int sizeArr) {
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
 void selectionSort(int arr[], int sizeArr) {
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



 void insertionSort(int arr[], int sizeArr) {
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

 void bubbleSort(int arr[], int sizeArr) {
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
void shellSortDel2(int arr[], int sizeArr)
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


void shellSortPow(int arr[],int sizeArr)
{
    int firstStep = sizeArr;
   
    for (int i = 8*sizeof(int); i>=0 ; i--)
    {
        int powN = pow(2, i);
        if ((sizeArr&powN)!=0)
        {
            firstStep = powN;
            break;
        }
    }

    for (int step = firstStep; step > 1;  step=(step+1)/2)//перебор всех шагов
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
    for (int i = 1; i < sizeArr; i += 1)//перебор всех наборов с данным шагом
    {
        int temp = arr[i];
        int j;
        for (j = i; j >= 1 && arr[j - 1] > temp; j -= 1) {//проверка эллементов в наборе по алгоритму вставки
            arr[j] = arr[j - 1];
        }

        arr[j] = temp;
    }
}

void shellSortTsiura(int arr[],int sizeArr)
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

    int FirsteEementLastRun = size - (size % minRunInsert);
     for (int segment = 0; segment < FirsteEementLastRun; segment+= minRunInsert)//сортируем отрезки
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
     
     
     for (int i = FirsteEementLastRun; i < size; i++)
     {
         int temp = arr[i];
         int j = i - 1;
         while (j >= FirsteEementLastRun && arr[j] > temp)
         {
             arr[j + 1] = arr[j];
             j--;
         }
         arr[j + 1] = temp;
     }
     stack<int> stack;
     int step = size / minRunInsert;
     if (size % minRunInsert != 0) {
         stack.push(size % minRunInsert);

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


 // Сортируем массив `arr[low…high]`, используя вспомогательный массив `aux`
 void TimsortRecPopolam(int arr[], int aux[], int low, int high, int minRunInsert)
 {

     // базовый вариант
     if (high - low > minRunInsert) {        // если размер прогона <= 1



         // найти середину
         int mid = (low + ((high - low) >> 1));

         // рекурсивно разделяем прогоны на две половины до тех пор, пока размер прогона не станет <= 1,
         // затем объединяем их и возвращаемся вверх по цепочке вызовов

         TimsortRecPopolam(arr, aux, low, mid, minRunInsert);          // разделить/объединить левую половину
         TimsortRecPopolam(arr, aux, mid + 1, high, minRunInsert);     // разделить/объединить правую половину
         Merge(arr, aux, low, mid, high);        // объединить два полупрогона.
     }
     else
     {
         for (int i = low; i < high; i++)
         {
             int temp = arr[i];
             int j = i - 1;
             while (j >= low && arr[j] > temp)
             {
                 arr[j + 1] = arr[j];
                 j--;
             }
             arr[j + 1] = temp;
         }
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

 void creatSorted(int* arr, int sizeArr, int tupe) {
     //выбираем какой вид заполнения масива
     if (tupe == 1)
     {


         for (int i = 0; i < sizeArr; i++)
         {
             arr[i] = i;
         }
     }
     else if (tupe == 2)
     {


         for (int i = 0; i < sizeArr; i++)
         {
             arr[i] = i;
         }
         swap(arr[sizeArr / 2], arr[sizeArr / 2 + 1]);//для Почти отсортированного массива 
     }
     else if (tupe == 3)
     {
         for (int i = 0; i < sizeArr; i++)
         {
             arr[i] = sizeArr - i;
         }
     }
     else if (tupe == 4)
     {
         for (int i = 0; i < sizeArr; i++)
         {
             arr[i] = aray[i];
         }//случайный масив
     }
 
 }

 int main()
 {

    srand(time(0));


    int startSizeArr = 20;//стартовый массив
    int finishSizeArr = 200;//конечный массив
    int sizeArr = startSizeArr;

    aray = (int*)malloc(finishSizeArr * sizeof(int));
    int* arr=(int*) malloc(sizeArr * sizeof(int));
    int* arr2=(int*) malloc(sizeArr * sizeof(int));//некоторые сортировки требуют вспомогательный массив
   
    for (int i = 0; i < finishSizeArr; i++)
    {
        aray[i] = rand();
    }


    auto begin = steady_clock::now();
    auto end = steady_clock::now();
   
    for (int i = 1; i < 5; i++)
    {

      
        std::cout << "selectionSort ";

        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));
            creatSorted(arr, sizeArr, i);
            begin = steady_clock::now();
            selectionSort(arr, sizeArr);
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";
        }
        std::cout << " \n";
        
        std::cout << "insertionSort ";
        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));
            creatSorted(arr, sizeArr, i);
            begin = steady_clock::now();
            insertionSort(arr, sizeArr);
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";
        }
        std::cout << " \n";

        std::cout << "bubbleSort ";
        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));

            creatSorted(arr, sizeArr, i);
            begin = steady_clock::now();
            bubbleSort(arr, sizeArr);
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";
        }
        std::cout << " \n";
        
        std::cout << "mergesort ";
        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));
            arr2 = (int*)realloc(arr2, sizeArr * sizeof(int));

            creatSorted(arr, sizeArr, i);
            creatSorted(arr2, sizeArr, i);
            begin = steady_clock::now();
            mergesort(arr, arr2, 0, sizeArr - 1);
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";

        }
        std::cout << " \n";
        
        if (finishSizeArr <= 2800)
        {


            std::cout << "quickSort ";
            for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
                arr = (int*)realloc(arr, sizeArr * sizeof(int));



                creatSorted(arr, sizeArr, i);
                begin = steady_clock::now();
                quickSort(arr, 0, sizeArr - 1);
                end = steady_clock::now();
                std::cout << duration_cast<microseconds>(end - begin).count() << " ";

            }
            std::cout << " \n";

            std::cout << "quickSortMedian ";
            for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
                arr = (int*)realloc(arr, sizeArr * sizeof(int));

                creatSorted(arr, sizeArr, i);
                begin = steady_clock::now();
                quickSortMedian(arr, 0, sizeArr - 1);
                end = steady_clock::now();
                std::cout << duration_cast<microseconds>(end - begin).count() << " ";

            }
        }
        std::cout << " \n";

        std::cout << "shellSortDel2 ";
        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));



            creatSorted(arr, sizeArr, i);
            begin = steady_clock::now();
            shellSortDel2(arr, sizeArr);
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";

        }
        std::cout << " \n";

        std::cout << "shellSortPow ";
        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));


            creatSorted(arr, sizeArr, i);
            begin = steady_clock::now();
            shellSortPow(arr, sizeArr);
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";

        }
        std::cout << " \n";

        std::cout << "shellSortTsiura ";
        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));

            creatSorted(arr, sizeArr, i);
            begin = steady_clock::now();
            shellSortTsiura(arr, sizeArr);
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";

        }
        std::cout << " \n";

        std::cout << "Timsort ";
        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));
            arr2 = (int*)realloc(arr2, sizeArr * sizeof(int));

            creatSorted(arr, sizeArr, i);
            creatSorted(arr2, sizeArr, i);
            begin = steady_clock::now();
            Timsort(arr, arr2, sizeArr, getMinRunInsert(sizeArr));
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";

        }
        std::cout << " \n";

        std::cout << "TimsortRecPopolam ";
        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));
            arr2 = (int*)realloc(arr2, sizeArr * sizeof(int));

            creatSorted(arr, sizeArr, i);
            creatSorted(arr2, sizeArr, i);
            begin = steady_clock::now();
            TimsortRecPopolam(arr, arr2,0, sizeArr-1, getMinRunInsert(sizeArr));
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";

        }
        std::cout << " \n";

        std::cout << "pyramidSort ";
        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));


            creatSorted(arr, sizeArr, i);
            begin = steady_clock::now();
            pyramidSort(arr, sizeArr);
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";

        }
        std::cout << " \n";

        std::cout << "IntroSort ";
        for (sizeArr = startSizeArr; sizeArr <= finishSizeArr; sizeArr += startSizeArr) {
            arr = (int*)realloc(arr, sizeArr * sizeof(int));

            creatSorted(arr, sizeArr, i);
            begin = steady_clock::now();
            IntroSort(arr, 0, sizeArr - 1, 0, log(sizeArr));
            end = steady_clock::now();
            std::cout << duration_cast<microseconds>(end - begin).count() << " ";
        }
        std::cout << " \n";
        std::cout << " \n";
        std::cout << " \n";
        std::cout << " \n";
    }

    
    delete arr;
    delete arr2;
    delete aray;

}
