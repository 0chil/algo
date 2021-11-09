# 땡칠이 알고리즘 공부 저장소

<div align=center>

![GitHub commit activity](https://img.shields.io/github/commit-activity/w/0chil/algo)
![GitHub last commit](https://img.shields.io/github/last-commit/0chil/algo)
<!-- [![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2F0chil%2Falgo&count_bg=%23007EC6&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=false)](https://hits.seeyoufarm.com) -->
<!-- [![Latest Post](https://img.shields.io/endpoint?url=https%3A%2F%2Fapi.chll.it%2FgetLatestPost%2Fbadge&color=12b886)](https://chll.it)<br> -->
<div align=center><img src="https://api.chll.it/solvedac/tierImage" width=75>

![Tier](https://img.shields.io/badge/dynamic/json?color=yellow&label=tier&query=%24.tierName&url=https%3A%2F%2Fapi.chll.it%2Fsolvedac)
![Rating](https://img.shields.io/badge/dynamic/json?label=rating&query=%24.rating&url=https%3A%2F%2Fapi.chll.it%2Fsolvedac)
</div>

![Solved](https://img.shields.io/badge/dynamic/json?label=solved&query=%24.solvedCount&suffix=%20problems&url=https%3A%2F%2Fapi.chll.it%2Fsolvedac)
![Rank](https://img.shields.io/badge/dynamic/json?label=rank&query=%24.rank&url=https%3A%2F%2Fapi.chll.it%2Fsolvedac)
</div>

<details align=center>
<summary><a href="https://solved.ac">solved.ac</a> 뱃지 따라하기</summary>

### `{handle}` 을 자신의 아이디로 바꾸세요<br><br>

![Solved](https://img.shields.io/badge/dynamic/json?label=solved&query=$.solvedCount&suffix=%20problems&url=https://api.chll.it/solvedac)

    ![Solved](https://img.shields.io/badge/dynamic/json?label=solved&query=$.solvedCount&suffix=%20problems&url=https://api.chll.it/solvedac/{handle})
<br>

![Rank](https://img.shields.io/badge/dynamic/json?label=rank&query=$.rank&url=https://api.chll.it/solvedac)

    ![Rank](https://img.shields.io/badge/dynamic/json?label=rank&query=$.rank&url=https://api.chll.it/solvedac/{handle})
<br>

<div align=center><img src="https://api.chll.it/solvedac/tierImage" width=75>

![Tier](https://img.shields.io/badge/dynamic/json?color=yellow&label=tier&query=%24.tierName&url=https%3A%2F%2Fapi.chll.it%2Fsolvedac)
</div>

    <div align=center><img src="https://api.chll.it/solvedac/{handle}/tierImage" width=75>

    ![Tier](https://img.shields.io/badge/dynamic/json?color=yellow&label=tier&query=$.tierName&url=https://api.chll.it/solvedac/{handle})
    ![Rating](https://img.shields.io/badge/dynamic/json?label=rating&query=$.rating&url=https://api.chll.it/solvedac/{handle})
    </div>
</details><br>

## 여기다 뭐하는 중?
- 2021.7.12 부터 틈틈히 알고리즘 문제를 푸는 습관을 들여 진행중입니다.
- 인상깊거나 재밌었던, 혹은 고민하게 했던 사항을 블로그/코드에 적어놓는 편입니다.
- ### [땡칠로그 - 알고리즘 시리즈](https://velog.io/@0chil/series/%EC%82%AC%EC%A7%80%EB%B0%A9%EC%97%90%EC%84%9C-%EC%BD%94%EB%94%A9%ED%95%98%EA%B8%B0)
- 동적계획법을 좋아해서 동적계획법으로 좀 편향되었을 수 있습니다.

## 문제집/순서
- [알고리즘 문제 리스트](https://velog.io/@0chil/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%AC%B8%EC%A0%9C-%EB%A6%AC%EC%8A%A4%ED%8A%B8%EA%B8%B0%EC%B4%881%EC%A4%91%EA%B8%893)

## 알고리즘 푸는 환경
▼ 현재
- Macbook Air (2020) 13''
- M1, 16GB RAM
- macOS Monterey
<details>
<summary>과거</summary>

- 사지방
- Ampere A1 Compute Container (Oracle Cloud)
- Neoverse N1(2 cores), 12GB RAM
- Ubuntu 20.04.3 LTS (arm64)
- g++, gdb
- [code-server](https://github.com/cdr/code-server)
- [FiraCode](https://github.com/tonsky/FiraCode) font
</details>

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
다른 문제들은 어디있는지 모르겠어요<br>
~~Baekjoon Online Judge에 있지 않을까~~
