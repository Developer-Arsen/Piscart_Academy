#include <stdio.h>
#include <math.h>

// 4.n թվանշան ունեցող բնական թիվը կոչվում է Արմսթրոնգի թիվ, եթե նրա թվանշանների n աստիճանների գումարը հավասար է այդ թվին (օրինակ՝ 153=1^3 +5^3 +3^3 ): Ներմուծել թիվ, արտածել YES եթե այն հանդիսանում է Արմսթրոնգի թիվ, և NO հակառակ դեպքում։


void is_armstrong(int n) {
    int sum = 0;
    int tmp = n;

    int count = 0;
    while (tmp)
    {
        count++;
        tmp /= 10;
    }
    
    int nOrigin = n;
    while (n)
    {
        sum += pow((n %10) , count);
        n /= 10;
    }
    if (sum == nOrigin) printf("true");
    else printf("false");
}

int main () {
    int n = 153;
    is_armstrong(n);

}