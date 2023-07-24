## C++의 대괄호를 이용한 구조적 바인딩
구조적 바인딩은 레퍼런스와 같이 객체에 대한 별명이 됩니다.
차이가 있다면, 꼭 레퍼런스 타입일 필요가 없다는 것입니다.
아래 케이스를 살펴보겠습니다.

### CASE: 배열 바인딩하기
```c++
int a[2] = {1, 2};
auto [x, y] = a;
auto& [xr, yr] = a;
```

바인딩이 레퍼런스 타입이 아닌 경우, e[2]라는 새로운 배열이 생성되고 a가 e로 복사됩니다.
x는 e[0]의 레퍼런스이고 y는 e[1]의 레퍼런스입니다.
바인딩이 레퍼런스 타입인 경우, xr은 a[0]의 레퍼런스이고, yr은 a[1]의 레퍼런스입니다.

[structured binding declaration](https://en.cppreference.com/w/cpp/language/structured_binding)



http://progtrend.blogspot.com/2017/03/type-alias-using.html
