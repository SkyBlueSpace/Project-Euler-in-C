#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>

void Question_1(){
    uint32_t sum = 0;
    for (uint16_t i=0;i<1000;i++){
        if (!(i%3)||!(i%5)) sum += i;
    }
    printf("%"PRIu32,sum);
}
void Question_2(){
    uint32_t number1 = 1;
    uint32_t number2 = 2;
    uint32_t sum = 0;
    while (number1<4000000) {
        number1 += number2;
        uint32_t temp = number1;
        number1 = number2;
        number2 = temp;
        if (!(number1%2)) sum += number1;
    }
    printf("%"PRIu32,sum);
}

int Primecheck(uint32_t num){
    uint16_t Prime = 1;
    for (uint32_t i = 2; i < (uint32_t) sqrt(num); i++){
        if ((num%i) == 0) Prime = 0;
    }
    return Prime;
}

void Question_3(){
    uint32_t factor = 0;
    uint64_t number = 600851475143;
    for (uint32_t i = 1; i < 775147; i++){
        if ((Primecheck(i) == 1) && (number%i == 0) && (i>factor)) factor = i;
    }
    printf("%"PRIu32,factor);
}

int checkpalindrome(uint32_t num){
    uint32_t reversed = 0, r, original;
    original = num;
    while (num != 0){
        r = num%10;
        reversed = reversed*10+r;
        num/=10;
    }
    if (original == reversed) {
        return 1;
    } else {
        return 0;
    }
}

void Question_4(){
    uint32_t largest_palindrome = 0;
    for (uint16_t i = 999; i > 0; i--){
        for (uint16_t j = 999; j > 0; j--){
            if ((checkpalindrome(i*j) == 1) && (i*j > largest_palindrome)){
                largest_palindrome = i*j;
            }
        }
    }
    printf("%"PRId32,largest_palindrome);
}
uint32_t gcd(uint32_t a, uint32_t b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

uint32_t lcm(uint32_t a, uint32_t b){
    return (a / gcd(a, b)) * b;
}

void Question_5(){
    uint32_t num = 1;
    for (uint16_t i = 2; i<21;i++){
        num = lcm(num,i);
    }
    printf("%"PRIu32,num);
}

uint64_t sumofsquares(uint16_t n){
    uint64_t output = n*(n+1)*(2*n+1)/6;
    return output;
}

uint64_t squareofsums(uint16_t n){
    uint64_t output = n*(n+1)*n*(n+1)/4;
    return output;
}

void Question_6(){
    uint64_t answer = squareofsums(100) - sumofsquares(100);
    printf("%"PRIu64,answer);
}

void Question_7(){
    int num = 10001;
    int List[num];
    List[0] = 2; List[1] = 3; List[2] = 5; List[3] = 7;
    int PrimesFound = 4;
    int Checking = 9;
    while (PrimesFound < num){
        int PrimeStat = 1;
        int Checklimit = sqrt(Checking) + 1;
        for (int i = 0; i<PrimesFound; i++){
            if (List[i] > Checklimit){
                continue;
            }
            if (Checking%List[i] == 0){
                PrimeStat = 0;
                break;
            }
        }
        if (PrimeStat == 1){
            List[PrimesFound] = Checking;
            PrimesFound += 1;
        }
        Checking += 2; 
    }
    printf("%d""\n",List[10000]);
}

char Num[] = 
"73167176531330624919225119674426574742355349194934"
"96983520312774506326239578318016984801869478851843"
"85861560789112949495459501737958331952853208805511"
"12540698747158523863050715693290963295227443043557"
"66896648950445244523161731856403098711121722383113"
"62229893423380308135336276614282806444486645238749"
"30358907296290491560440772390713810515859307960866"
"70172427121883998797908792274921901699720888093776"
"65727333001053367881220235421809751254540594752243"
"52584907711670556013604839586446706324415722155397"
"53697817977846174064955149290862569321978468622482"
"83972241375657056057490261407972968652414535100474"
"82166370484403199890008895243450658541227588666881"
"16427171479924442928230863465674813919123162824586"
"17866458359124566529476545682848912883142607690042"
"24219022671055626321111109370544217506941658960408"
"07198403850962455444362981230987879927244284909188"
"84580156166097919133875499200524063689912560717606"
"05886116467109405077541002256983155200055935729725"
"71636269561882670428252483600823257530420752963450";

void Question_8(){
    uint64_t best = 0;
    for (int i = 0; i < 988; i++){
        uint64_t current = 1;
        for (int j = 0; j < 13; j++){
            current *= (int)(Num[i+j]-'0');
        }
        if (current > best){
            best = current;
        }
    }
    printf("%"PRIu64,best);
}

void Question_9(){
    for (int m = 1; m<33; m++){
        for (int n = m; n<33; n++){
            int a = n*n-m*m;
            int b = 2*n*m;
            int c = n*n+m*m;
            if (a+b+c == 1000){
                printf("%i",a*b*c);
            }
        }
    }
}

void Question_10(){
    uint64_t sum = 17;
    int cap = 2000000;
    int List[148932];
    List[0] = 2; List[1] = 3; List[2] = 5; List[3] = 7;
    int PrimesFound = 4;
    int Checking = 9;
    while (Checking < cap){
        int PrimeStat = 1;
        int Checklimit = sqrt(Checking) + 1;
        for (int i = 0; i<PrimesFound; i++){
            if (List[i] > Checklimit){
                continue;
            }
            if (Checking%List[i] == 0){
                PrimeStat = 0;
                break;
            }
        }
        if (PrimeStat == 1){
            List[PrimesFound] = Checking;
            PrimesFound += 1;
            sum += Checking;
        }
        Checking += 2; 
    }
    printf("%"PRIu64,sum);
}

int main(){
    Question_10();
}