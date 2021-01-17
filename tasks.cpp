#include <iostream>
#include "mod_functions.h"
#include "tasks.h"

void task1(){
    int n, length, i;
    std::cout << "Task 1: array of integers modulo n" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    do{
        std::cout << "length = ";
        std::cin >> length;
    }
    while(length < 0);
    int arr[length];
    for(i = 0; i < length; i ++){
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
    std::cout << "arr = {";
    for(i = 0; i < length - 1; i ++)
        std::cout << mod(n, arr[i]) <<",";
    std::cout << mod(n, arr[length - 1]) << "}" << " (mod " << n <<")";
    std::cout << std::endl << std::endl;
}

void task2(){
    int n, a, b;
    std::cout << "Task 2: a + b (mod n)" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << a << " + " << b << " = " << mod_sum(n, a, b) << " (mod " << n <<")";
    std::cout << std::endl << std::endl;
}

void task3(){
    int n, a, b;
    std::cout << "Task 3: a - b (mod n)" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << a << " - " << b << " = " << mod_difference(n, a, b) << " (mod " << n << ")";
    std::cout << std::endl << std::endl;
}

void task4(){
    int n, a, b;
    std::cout << "Task 4: a * b (mod n)" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << a << " * " << b << " = " << mod_product(n, a, b) << " (mod " << n << ")";
    std::cout << std::endl << std::endl;
}

void task5(){
    int i, k, n;
    std::cout << "Task 5: finds all invertible elements modulo n" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    k = euler(n);
    //cout << "euler(n) = " << k << endl;
    int **t = inverses_matrix(n);
    std::cout << "Table of inverses:" << std::endl;
    for(i = 0; i < k; i ++){
        std::cout << t[i][0] << "^(-1) = " << t[i][1] << " (mod " << n << ")" << std::endl;
    }
    for(i = 0; i < k; i ++){
        delete [] t[i] ;
    }
    delete [] t;
    std::cout << std::endl;
}

void task6(){
    int a, i, k, n;
    std::cout << "Task 6: a^(-1) (mod n) using the table of inverible elements" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    k = euler(n);
    int** t = inverses_matrix(n);
    std::cout << "a = ";
    std::cin >> a;
    int result = mod_inverse_tabular(n, t, a);
    if(result != -1)
        std::cout << a << "^(-1) = " << result << " (mod " << n << ")";
    else
        std::cout << a << " is not invertible modulo " << n;
    for(i = 0; i < k; i ++){
        delete [] t[i] ;
    }
    delete [] t;
    std::cout << std::endl << std::endl;
}

void task7(){
    int n, a;
    std::cout << "Task 7: a^(-1) (mod n)" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    std::cout << "a = ";
    std::cin >> a;
    int result = mod_inverse(n, a);
    if(result != -1)
        std::cout << a << "^(-1) = " << result << " (mod " << n << ")";
    else
        std::cout << a << " is not invertible modulo " << n;
    std::cout << std::endl << std::endl;
}

void task8(){
    int n, a, b;
    std::cout << "Task 8: a * b^(-1) (mod n)" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    int result = mod_division(n, a, b);
    if(result != -1)
        std::cout << a << " * " << b << "^(-1) = " << result << " (mod " << n << ")";
    else
        std::cout << b << " is not invertible modulo " << n;
    std::cout << std::endl << std::endl;
}

void task9(){
    int n, a, m;
    std::cout << "Task 9: a^m (mod n)" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    std::cout << "a = ";
    std::cin >> a;
    do{
        std::cout << "m = ";
        std::cin >> m;
    }
    while(m < 0);
    std::cout << a << "^" << m << " = " << mod_power_task9(n, a, m) << " (mod " << n << ")";
    std::cout << std::endl << std::endl;
}

void task10(){
    int n, a, m;
    std::cout << "Task 9: a^m (mod n)" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    std::cout << "a = ";
    std::cin >> a;
    do{
        std::cout << "m = ";
        std::cin >> m;
    }
    while(m < 0);
    std::cout << a << "^" << m << " = " << mod_power_fast(n, a, m) << " (mod " << n << ")";
    std::cout << std::endl << std::endl;
}

void task11(){
    int n, a;
    std::cout << "Task 11: tests whether a is some primitive root modulo n" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    std::cout << "a = ";
    std::cin >> a;
    if(primitive_root(n, a))
        std::cout << a << " is a primitive root modulo " << n;
    else
        std::cout << a << " is not a primitive root modulo " << n;
    std::cout << std::endl << std::endl;
}

void task12(){
    int n, i;
    std::cout << "Task 12: finds all primitive roots modulo n" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    int* all_primitive_roots = primitive_roots(n);
    if(primitive_root_first(n) != -1){
        int k = euler(n);
        int m = euler(k);
        for(i = 0; i < m; i ++){
            std::cout << all_primitive_roots[i] << " (mod " << n << ")" << std::endl;
        }
    }
    else
        std::cout << "There are not primitive roots modulo " << n;
    delete [] all_primitive_roots;
    std::cout << std::endl << std::endl;
}

void task13(){
    int n, a, b;
    std::cout << "Task 13: the discrte logarithm log_a b (mod n)" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    if(! primitive_root(n, a))
        std::cout << "Error: " << a << " is not a primitive root modulo " << n;
    else if(gcd(n, b) != 1)
        std::cout << "Error: " << b << " is not relatively prime with " << n;
    else
        std::cout << "log_" << a << "(" << b << ") = " << mod_log(n, a, b) << " (mod " << n << ")";
    std::cout << std::endl << std::endl;
}

void task14(){
    int n;
    std::cout << "Task 14: tests whether Z_n is a field, i.e. that n is prime" << std::endl;
    do{
        std::cout << "n = ";
        std::cin >> n;
    }
    while(n <= 0);
    if(field(n))
        std::cout << "Z_" << n << " is a field ";
    else
        std::cout << "Z_" << n << " is not a field ";
    std::cout << std::endl << std::endl;
}
