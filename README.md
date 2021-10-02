# 땡칠이 알고리즘 공부 저장소
## 여기다 뭐하는 중?
- 2021.7.12 부터 하루에 알고리즘 3~5문제씩 푸는 습관을 들여 진행중입니다. (생각보다 재밌음)
- 인상깊거나 재밌었던, 혹은 고민하게 했던 사항은 블로그/코드에 적어놓는 편입니다.
- ### [땡칠로그 - 사지방에서 알고리즘 시리즈](https://velog.io/@0chil/series/%EC%82%AC%EC%A7%80%EB%B0%A9%EC%97%90%EC%84%9C-%EC%BD%94%EB%94%A9%ED%95%98%EA%B8%B0)
- 동적계획법을 좋아해서 동적계획법으로 좀 편향되었을 수 있습니다.

## 알고리즘 푸는 환경
- 사지방
- Ampere A1 Compute Container (Oracle Cloud)
- Neoverse N1(2 cores), 12GB RAM
- Ubuntu 20.04.3 LTS (arm64)
- g++, gdb
- [code-server](https://github.com/cdr/code-server)
- [FiraCode](https://github.com/tonsky/FiraCode) font

## 팁
- > **`.vscode` 디렉토리 안에 user snippet 파일 있습니다.**<br> 1. 해당 디렉토리를 프로젝트 안에 넣으시고<br>2. `문제번호.cpp` 파일 만들고 `algo` 라고 치거나, `dp` 라고 치면 <br>3. 아래처럼 주석과 함께 템플릿이 자동완성됩니다.
    ```cpp
    // 2021.10.02 23:25:58
    // 7569 https://boj.kr/7569
    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        cin.tie(0);
        ios::sync_with_stdio(false);

    }
    ```
- > **BOJ 디렉토리 안에 `clear.sh`가 있습니다.**<br> 디렉토리 안에서 `./clear.sh` 라고 외치시면 컴파일된 바이너리들이 증발합니다. (구조 정리 시 👍)

## 기존에 풀었던 문제는 어디갔을까?
~~다른 문제들은 어디있는지 모르겠어요<br>
Baekjoon Online Judge에 있지 않을까~~
