#include <iostream>
#include <cstdio>
using namespace std;

int Coin[6] = { 500, 100, 50, 10, 5, 1 };
//동전이 큰순서로 되어있다.
// 그리디는 최적인 답을 선택하는데 적합
// 하지만 항상 최적해를 보장하지는 않음
int Search(int money){
    int total = 1000 - money;
    //total에 거스름돈이 들어가있음
    int cnt = 0;
    for (int i = 0; i < 6; i++){
        while (total - Coin[i] >= 0){
            total -= Coin[i];
            cnt++;
            if (total <= 0) break;
        }
    }
    return cnt;
}

int main(void){
    int money = 0;
    scanf("%d", &money);
    printf("%d\n", Search(money));
    
    return 0;
}
