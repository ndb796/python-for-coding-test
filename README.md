### 이것이 취업을 위한 코딩 테스트다 with Python
> 취업과 이직을 결정하는 알고리즘 인터뷰 완벽 가이드 (2020년 08월 05일 정식 출시)

* 이 저장소는 <b>이것이 취업을 위한 코딩 테스트다 with Python</b> (나동빈 저, 한빛미디어) 전체 소스코드를 포함합니다.
* 본 책은 Python 3.7 문법을 활용하였으나, 추가적으로 Java, C++11 소스코드를 제공합니다.
* 책 내용 및 소스코드와 관련한 궁금한 점은 [Issues](https://github.com/ndb796/python-for-coding-test/issues) 탭을 이용하여 남겨주세요.
* 책의 오류 사항을 발견하시면 dongbinna@postech.ac.kr로 보내주시면 감사하겠습니다.
    * 이 경우, 원하신다면 <b>[정오표](/notice.md)</b>에 독자님의 이름(혹은 아이디)을 함께 기재해드립니다.
* 이 책을 이용해 강의를 진행하시는 교수/선생님/강사/동아리장 님들을 위해 강의용 PPT를 제공합니다. (준비중)
* 전체 동영상 강의는 2020년 8 ~ 9월에 걸친 유튜브 라이브 강의를 진행하고 편집 후에 업로드 될 예정입니다.
* 책 구매 링크: [한빛미디어](http://hanbit.co.kr/store/books/look.php?p_code=B8945183661) / [YES24](http://www.yes24.com/Product/Goods/91433923) / [교보문고](http://www.kyobobook.co.kr/product/detailViewKor.laf?barcode=9791162243077) / [알라딘](https://www.aladin.co.kr/shop/wproduct.aspx?ISBN=K342631735)

<hr>

### 도와주신 분들

* 베타 리뷰어 님들: 김민철, 안수빈, 정한길, 황성호 외 10분
* [백준 온라인 저지(BOJ)](https://www.acmicpc.net/)의 일부 문제를 사용할 수 있도록 허락해주고, 개인적으로 많은 도움을 주신 최백준 님
* 2019, 2020 K사 문제를 책에 수록할 수 있도록 허락해주신 (주)그렙 [프로그래머스](https://programmers.co.kr/)
    * PPL: [프로그래머스 알고리즘 문제 풀이 강의](https://programmers.co.kr/learn/courses/10336)

### 시작하며

* [지은이의 글 및 리뷰어의 글](https://blog.naver.com/ndb796/222048713087)

### Part 1 코딩 테스트, 무엇을 어떻게 준비할까?

#### 1장 코딩 테스트 개요

* 코딩 테스트 개념과 배경
* 실습 환경 구축하기
* 복잡도
    * [파이썬 수행 시간 측정 방법](/1/1.py)
    * [선택 정렬과 기본 정렬 라이브러리의 수행 시간 비교](/1/2.py)

#### 2장 16~20년 코딩 테스트 기출문제 유형 분석

* 최신 출제 경향과 준비 방향
* 연도별 코딩 테스트 유형 분석

#### GUIDE: 성공적인 취업을 위한 가이드

* 채용 프로세스
* 기술 면접의 대표적인 유형
* 기술 면접 준비
* 알고리즘 문제 풀이 사이트
* 커뮤니티 사이트

### Part 2 주요 알고리즘 이론과 실전 문제

#### 3장 그리디

* 이론
    * 당장 좋은 것만 선택하는 그리디
    * 거스름돈 문제: ([Python 3.7 코드](/3/1.py) / [C++ 코드](/3/1.cpp) / [Java 코드](/3/1.java))
* 실전
    * 동빈이의 큰 수의 법칙: ([Python 3.7 코드](/3/2.py) / [C++ 코드](/3/2.cpp) / [Java 코드](/3/2.java))
    * 숫자 카드게임: ([Python 3.7 코드](/3/4.py) / [C++ 코드](/3/4.cpp) / [Java 코드](/3/4.java))
    * 1이 될 때까지: ([Python 3.7 코드](/3/6.py) / [C++ 코드](/3/6.cpp) / [Java 코드](/3/6.java))

#### 4장 구현

* 이론
    * 아이디어를 코드로 바꾸는 구현
    * 상하좌우: ([Python 3.7 코드](/4/1.py) / [C++ 코드](/4/1.cpp) / [Java 코드](/4/1.java))
    * 시각: ([Python 3.7 코드](/4/2.py) / [C++ 코드](/4/2.cpp) / [Java 코드](/4/2.java))
* 실전
    * 왕실의 나이트: ([Python 3.7 코드](/4/3.py) / [C++ 코드](/4/3.cpp) / [Java 코드](/4/3.java))
    * 게임 개발: ([Python 3.7 코드](/4/4.py) / [C++ 코드](/4/4.cpp) / [Java 코드](/4/4.java))

#### 5장 DFS/BFS

* 이론
    * 꼭 필요한 자료구조 기초
    * 탐색 알고리즘 DFS/BFS
    * 스택 구현 예제: ([Python 3.7 코드](/5/1.py) / [C++ 코드](/5/1.cpp) / [Java 코드](/5/1.java))
    * 큐 구현 예제: ([Python 3.7 코드](/5/2.py) / [C++ 코드](/5/2.cpp) / [Java 코드](/5/2.java))
    * 무한히 반복되는 재귀함수 예제: ([Python 3.7 코드](/5/3.py) / [C++ 코드](/5/3.cpp) / [Java 코드](/5/3.java))
    * 재귀함수의 종료 조건 예제: ([Python 3.7 코드](/5/4.py) / [C++ 코드](/5/4.cpp) / [Java 코드](/5/4.java))
    * 2가지 방식으로 구현한 팩토리얼 예제: ([Python 3.7 코드](/5/5.py) / [C++ 코드](/5/5.cpp) / [Java 코드](/5/5.java))
    * 인접 행렬 예제: ([Python 3.7 코드](/5/6.py) / [C++ 코드](/5/6.cpp) / [Java 코드](/5/6.java))
    * 인접 리스트 예제: ([Python 3.7 코드](/5/7.py) / [C++ 코드](/5/7.cpp) / [Java 코드](/5/7.java))
    * DFS: ([Python 3.7 코드](/5/8.py) / [C++ 코드](/5/8.cpp) / [Java 코드](/5/8.java))
    * BFS: ([Python 3.7 코드](/5/9.py) / [C++ 코드](/5/9.cpp) / [Java 코드](/5/9.java))
* 실전
    * 음료수 얼려 먹기: ([Python 3.7 코드](/5/10.py) / [C++ 코드](/5/10.cpp) / [Java 코드](/5/10.java))
    * 미로 탈출: ([Python 3.7 코드](/5/11.py) / [C++ 코드](/5/11.cpp) / [Java 코드](/5/11.java))

#### 6장 정렬

* 이론
    * 기준에 따라서 데이터를 정렬
    * 선택 정렬: ([Python 3.7 코드](/6/1.py) / [C++ 코드](/6/1.cpp) / [Java 코드](/6/1.java))
    * 스와프(Swap): ([Python 3.7 코드](/6/2.py) / [C++ 코드](/6/2.cpp) / [Java 코드](/6/2.java))
    * 삽입 정렬: ([Python 3.7 코드](/6/3.py) / [C++ 코드](/6/3.cpp) / [Java 코드](/6/3.java))
    * 퀵 정렬: ([Python 3.7 코드](/6/4.py) / [C++ 코드](/6/4.cpp) / [Java 코드](/6/4.java))
    * 파이썬의 장점을 살린 퀵 정렬: [Python 3.7 코드](/6/5.py)
    * 계수 정렬: ([Python 3.7 코드](/6/6.py) / [C++ 코드](/6/6.cpp) / [Java 코드](/6/6.java))
    * 정렬 라이브러리 기본 예제: ([Python 3.7 코드](/6/7.py) / [C++ 코드](/6/7.cpp) / [Java 코드](/6/7.java))
    * 정렬 라이브러리 키(Key) 기준 정렬 예제: ([Python 3.7 코드](/6/9.py) / [C++ 코드](/6/9.cpp) / [Java 코드](/6/9.java))
* 실전
    * 위에서 아래로: ([Python 3.7 코드](/6/10.py) / [C++ 코드](/6/10.cpp) / [Java 코드](/6/10.java))
    * 성적이 낮은 순서대로 학생 출력하기: ([Python 3.7 코드](/6/11.py) / [C++ 코드](/6/11.cpp) / [Java 코드](/6/11.java))
    * 두 배열의 원소 교체: ([Python 3.7 코드](/6/12.py) / [C++ 코드](/6/12.cpp) / [Java 코드](/6/12.java))

#### 7장 이진 탐색

* 이론
    * 범위를 반씩 좁혀가는 탐색
    * 순차 탐색: ([Python 3.7 코드](/7/1.py) / [C++ 코드](/7/1.cpp) / [Java 코드](/7/1.java))
    * 재귀 함수를 이용한 이진 탐색: ([Python 3.7 코드](/7/2.py) / [C++ 코드](/7/2.cpp) / [Java 코드](/7/2.java))
    * 반복문을 이용한 이진 탐색: ([Python 3.7 코드](/7/3.py) / [C++ 코드](/7/3.cpp) / [Java 코드](/7/3.java))
    * 파이썬에서 빠르게 입력 받기: [Python 3.7 코드](/7/4.py)
* 실전
    * 부품 찾기
        * 이진 탐색으로 해결: ([Python 3.7 코드](/7/5.py) / [C++ 코드](/7/5.cpp) / [Java 코드](/7/5.java))
        * 계수 정렬로 해결: ([Python 3.7 코드](/7/6.py) / [C++ 코드](/7/6.cpp) / [Java 코드](/7/6.java))
        * 집합(Set) 자료형으로 해결: ([Python 3.7 코드](/7/7.py) / [C++ 코드](/7/7.cpp) / [Java 코드](/7/7.java))
    * 떡볶이 떡 만들기: ([Python 3.7 코드](/7/8.py) / [C++ 코드](/7/8.cpp) / [Java 코드](/7/8.java))

#### 8장 다이나믹 프로그래밍

* 이론
    * 비효율적인 피보나치 수열 구현: ([Python 3.7 코드](/8/1.py) / [C++ 코드](/8/1.cpp) / [Java 코드](/8/1.java))
    * 피보나치 수열 (Top-bottom): ([Python 3.7 코드](/8/2.py) / [C++ 코드](/8/2.cpp) / [Java 코드](/8/2.java))
    * 피보나치 수열 (Bottom-top): ([Python 3.7 코드](/8/4.py) / [C++ 코드](/8/4.cpp) / [Java 코드](/8/4.java))
* 실전
    * 1로 만들기: ([Python 3.7 코드](/8/5.py) / [C++ 코드](/8/5.cpp) / [Java 코드](/8/5.java))
    * 개미 전사: ([Python 3.7 코드](/8/6.py) / [C++ 코드](/8/6.cpp) / [Java 코드](/8/6.java))
    * 바닥 공사: ([Python 3.7 코드](/8/7.py) / [C++ 코드](/8/7.cpp) / [Java 코드](/8/7.java))
    * 효율적인 화폐 구성: ([Python 3.7 코드](/8/8.py) / [C++ 코드](/8/8.cpp) / [Java 코드](/8/8.java))

#### 9장 최단 경로

* 이론
    * 가장 빠른 길 찾기
    * 간단한 다익스트라 알고리즘: ([Python 3.7 코드](/9/1.py) / [C++ 코드](/9/1.cpp) / [Java 코드](/9/1.java))
    * 개선된 다익스트라 알고리즘 (우선순위 큐): ([Python 3.7 코드](/9/2.py) / [C++ 코드](/9/2.cpp) / [Java 코드](/9/2.java))
    * 플로이드 워셜 알고리즘: ([Python 3.7 코드](/9/3.py) / [C++ 코드](/9/3.cpp) / [Java 코드](/9/3.java))
* 실전
    * 미래 도시: ([Python 3.7 코드](/9/4.py) / [C++ 코드](/9/4.cpp) / [Java 코드](/9/4.java))
    * 전보: ([Python 3.7 코드](/9/5.py) / [C++ 코드](/9/5.cpp) / [Java 코드](/9/5.java))

#### 10장 기타 그래프 이론

* 이론
    * 다양한 그래프 알고리즘
    * 간단한 서로소 집합 알고리즘: ([Python 3.7 코드](/10/1.py) / [C++ 코드](/10/1.cpp) / [Java 코드](/10/1.java))
    * 개선된 서로소 집합 알고리즘 (경로 압축): ([Python 3.7 코드](/10/3.py) / [C++ 코드](/10/3.cpp) / [Java 코드](/10/3.java))
    * 서로소 집합을 활용한 사이클 판별: ([Python 3.7 코드](/10/4.py) / [C++ 코드](/10/4.cpp) / [Java 코드](/10/4.java))
    * 크루스칼 알고리즘: ([Python 3.7 코드](/10/5.py) / [C++ 코드](/10/5.cpp) / [Java 코드](/10/5.java))
    * 위상 정렬: ([Python 3.7 코드](/10/6.py) / [C++ 코드](/10/6.cpp) / [Java 코드](/10/6.java))
* 실전
    * 팀 결성: ([Python 3.7 코드](/10/7.py) / [C++ 코드](/10/7.cpp) / [Java 코드](/10/7.java))
    * 도시 분할 계획: ([Python 3.7 코드](/10/8.py) / [C++ 코드](/10/8.cpp) / [Java 코드](/10/8.java))
    * 커리큘럼: ([Python 3.7 코드](/10/9.py) / [C++ 코드](/10/9.cpp) / [Java 코드](/10/9.java))

### Part 3 알고리즘 유형별 기출문제

#### 11장 그리디

* 모험가 길드 (핵심 유형): ([Python 3.7 코드](/11/1.py) / [C++ 코드](/11/1.cpp) / [Java 코드](/11/1.java))
* 곱하기 혹은 더하기 (Facebook 인터뷰 기출): ([Python 3.7 코드](/11/2.py) / [C++ 코드](/11/2.cpp) / [Java 코드](/11/2.java))
* [문자열 뒤집기](https://www.acmicpc.net/problem/1439) (핵심 유형): ([Python 3.7 코드](/11/3.py) / [C++ 코드](/11/3.cpp) / [Java 코드](/11/3.java))
* 만들 수 없는 금액 (K 대회 기출): ([Python 3.7 코드](/11/4.py) / [C++ 코드](/11/4.cpp) / [Java 코드](/11/4.java))
* 볼링공 고르기 (S 기관 입학 테스트): ([Python 3.7 코드](/11/5.py) / [C++ 코드](/11/5.cpp) / [Java 코드](/11/5.java))
* [무지의 먹방 라이브](https://programmers.co.kr/learn/courses/30/lessons/42891) (카카오): ([Python 3.7 코드](/11/6.py) / [C++ 코드](/11/6.cpp) / [Java 코드](/11/6.java))

#### 12장 구현

* [럭키 스트레이트](https://www.acmicpc.net/problem/18406) (핵심 유형): ([Python 3.7 코드](/12/1.py) / [C++ 코드](/12/1.cpp) / [Java 코드](/12/1.java))
* 문자열 재정렬 (Facebook 인터뷰 기출): ([Python 3.7 코드](/12/2.py) / [C++ 코드](/12/2.cpp) / [Java 코드](/12/2.java))
* [문자열 압축](https://programmers.co.kr/learn/courses/30/lessons/60057) (카카오): ([Python 3.7 코드](/12/3.py) / [C++ 코드](/12/3.cpp) / [Java 코드](/12/3.java))
* [자물쇠와 열쇠](https://programmers.co.kr/learn/courses/30/lessons/60059) (카카오): ([Python 3.7 코드](/12/4.py) / [C++ 코드](/12/4.cpp) / [Java 코드](/12/4.java))
* [뱀](https://www.acmicpc.net/problem/3190) (삼성): ([Python 3.7 코드](/12/5.py) / [C++ 코드](/12/5.cpp) / [Java 코드](/12/5.java))
* [기둥과 보 설치](https://programmers.co.kr/learn/courses/30/lessons/60061) (카카오): ([Python 3.7 코드](/12/6.py) / [C++ 코드](/12/6.cpp) / [Java 코드](/12/6.java))
* [치킨 배달](https://www.acmicpc.net/problem/15686) (삼성): ([Python 3.7 코드](/12/7.py) / [C++ 코드](/12/7.cpp) / [Java 코드](/12/7.java))
* [외벽 점검](https://programmers.co.kr/learn/courses/30/lessons/60062) (카카오): ([Python 3.7 코드](/12/8.py) / [C++ 코드](/12/8.cpp) / [Java 코드](/12/8.java))

#### 13장 DFS/BFS

* [특정 거리의 도시 찾기](https://www.acmicpc.net/problem/18352) (핵심 유형): ([Python 3.7 코드](/13/1.py) / [C++ 코드](/13/1.cpp) / [Java 코드](/13/1.java))
* [연구소](https://www.acmicpc.net/problem/14502) (삼성): ([Python 3.7 코드](/13/2.py) / [C++ 코드](/13/2.cpp) / [Java 코드](/13/2.java))
* [경쟁적 전염](https://www.acmicpc.net/problem/18405) (핵심 유형): ([Python 3.7 코드](/13/3.py) / [C++ 코드](/13/3.cpp) / [Java 코드](/13/3.java))
* [괄호 변환](https://programmers.co.kr/learn/courses/30/lessons/60058) (카카오): ([Python 3.7 코드](/13/4.py) / [C++ 코드](/13/4.cpp))
* [연산자 끼워 넣기](https://www.acmicpc.net/problem/14888) (삼성): ([Python 3.7 코드](/13/5.py) / [C++ 코드](/13/5.cpp) / [Java 코드](/13/5.java))
* [감시 피하기](https://www.acmicpc.net/problem/18428) (핵심 유형): ([Python 3.7 코드](/13/6.py) / [C++ 코드](/13/6.cpp) / [Java 코드](/13/6.java))
* [인구 이동](https://www.acmicpc.net/problem/16234) (삼성): ([Python 3.7 코드](/13/7.py) / [C++ 코드](/13/7.cpp) / [Java 코드](/13/7.java))
* [블록 이동하기](https://programmers.co.kr/learn/courses/30/lessons/60063) (카카오): ([Python 3.7 코드](/13/8.py) / [C++ 코드](/13/8.cpp))

#### 14장 정렬

* [국영수](https://www.acmicpc.net/problem/10825) (핵심 유형): ([Python 3.7 코드](/14/1.py) / [C++ 코드](/14/1.cpp) / [Java 코드](/14/1.java))
* [안테나](https://www.acmicpc.net/problem/18310) (국내 S 교육 기관 선발 평가): ([Python 3.7 코드](/14/2.py) / [C++ 코드](/14/2.cpp) / [Java 코드](/14/2.java))
* [실패율](https://programmers.co.kr/learn/courses/30/lessons/42889) (카카오): ([Python 3.7 코드](/14/3.py) / [C++ 코드](/14/3.cpp) / [Java 코드](/14/3.java))
* [카드 정렬하기](https://www.acmicpc.net/problem/1715) (핵심 유형): ([Python 3.7 코드](/14/4.py) / [C++ 코드](/14/4.cpp) / [Java 코드](/14/4.java))

#### 15장 이진 탐색

* 정렬된 배열에서 특정 수의 개수 구하기 (Zoho 인터뷰 기출): ([Python 3.7 코드](/15/1.py) / [C++ 코드](/15/1.cpp) / [Java 코드](/15/1.java))
* 고정점 찾기 (Amazon 인터뷰 기출): ([Python 3.7 코드](/15/2.py) / [C++ 코드](/15/2.cpp) / [Java 코드](/15/2.java))
* [공유기 설치](https://www.acmicpc.net/problem/2110) (핵심 유형): ([Python 3.7 코드](/15/3.py) / [C++ 코드](/15/3.cpp) / [Java 코드](/15/3.java))
* [가사 검색](https://programmers.co.kr/learn/courses/30/lessons/60060) (카카오): ([Python 3.7 코드](/15/4.py) / [C++ 코드](/15/4.cpp) / [Java 코드](/15/4.java))

#### 16장 다이나믹 프로그래밍

* 금광 (Flipkart 인터뷰 기출): ([Python 3.7 코드](/16/1.py) / [C++ 코드](/16/1.cpp) / [Java 코드](/16/1.java))
* [정수 삼각형](https://www.acmicpc.net/problem/1932) (IOI): ([Python 3.7 코드](/16/2.py) / [C++ 코드](/16/2.cpp) / [Java 코드](/16/2.java))
* [퇴사](https://www.acmicpc.net/problem/14501) (삼성): ([Python 3.7 코드](/16/3.py) / [C++ 코드](/16/3.cpp) / [Java 코드](/16/3.java))
* [병사 배치하기](https://www.acmicpc.net/problem/18353) (핵심 유형): ([Python 3.7 코드](/16/4.py) / [C++ 코드](/16/4.cpp) / [Java 코드](/16/4.java))
* 못생긴 수 (Google 인터뷰 기출): ([Python 3.7 코드](/16/5.py) / [C++ 코드](/16/5.cpp) / [Java 코드](/16/5.java))
* 편집 거리 (Goldman Sachs 인터뷰 기출): ([Python 3.7 코드](/16/6.py) / [C++ 코드](/16/6.cpp) / [Java 코드](/16/6.java))

#### 17장 최단 경로

* [플로이드](https://www.acmicpc.net/problem/11404) (핵심 유형): ([Python 3.7 코드](/17/1.py) / [C++ 코드](/17/1.cpp) / [Java 코드](/17/1.java))
* 정확한 순위 (K 대회 기출): ([Python 3.7 코드](/17/2.py) / [C++ 코드](/17/2.cpp) / [Java 코드](/17/2.java))
* 화성 탐사 (ICPC): ([Python 3.7 코드](/17/3.py) / [C++ 코드](/17/3.cpp) / [Java 코드](/17/3.java))
* 숨바꼭질 (USACO): ([Python 3.7 코드](/17/4.py) / [C++ 코드](/17/4.cpp) / [Java 코드](/17/4.java))

#### 18장 기타 그래프 이론

* 여행 계획 (핵심 유형): ([Python 3.7 코드](/18/1.py) / [C++ 코드](/18/1.cpp) / [Java 코드](/18/1.java))
* 탑승구 (CCC): ([Python 3.7 코드](/18/2.py) / [C++ 코드](/18/2.cpp) / [Java 코드](/18/2.java))
* 어두운 길 (University of Ulm Local Contest): ([Python 3.7 코드](/18/3.py) / [C++ 코드](/18/3.cpp) / [Java 코드](/18/3.java))
* [행성 터널](https://www.acmicpc.net/problem/2887) (COCI): ([Python 3.7 코드](/18/4.py) / [C++ 코드](/18/4.cpp) / [Java 코드](/18/4.java))
* [최종 순위](https://www.acmicpc.net/problem/3665) (ICPC): ([Python 3.7 코드](/18/5.py) / [C++ 코드](/18/5.cpp) / [Java 코드](/18/5.java))

#### 19장 2020년 상반기 삼성전자 기출문제

* [아기 상어](https://www.acmicpc.net/problem/16236) (삼성): [Python 3.7 코드](19/1.py)
* [청소년 상어](https://www.acmicpc.net/problem/19236) (삼성): [Python 3.7 코드](19/2.py)
* [어른 상어](https://www.acmicpc.net/problem/19237) (삼성): [Python 3.7 코드](19/3.py)

### Part 4 부록

#### 부록 A 코딩 테스트를 위한 파이썬 문법

* 자료형
    * 수 자료형
        * 정수형
        * 실수형
        * 수 자료형의 연산
    * 리스트 자료형
        * 리스트 만들기
        * 리스트 인덱싱
        * 리스트 슬라이싱
        * 리스트 컴프리헨션
        * 리스트 관련 메서드
    * 문자열 자료형
        * 문자열 초기화
        * 문자열 연산
    * 튜플 자료형
        * 튜플 초기화
    * 사전 자료형
        * 사전 자료형 초기화
        * 사전에서 키로 검색
        * 사전 자료형 관련 메서드
    * 집합 자료형
        * 집합 초기화
        * 집합 연산
        * 집합 관련 메서드
* 조건문
    * 조건문 예시 1
    * 조건문 예시 2
    * 조건문 예시 3
    * pass 키워드 사용 예시
    * 조건문 한 줄에 쓰기
    * 조건부 표현식
* 반복문
    * while 문법
        * while 문법 예시 1
        * while 문법 예시 2
    * for 문법
        * for 문법 예시 1
        * for 문법 예시 2
        * for 문법 예시 3
        * for 문법 예시 4
* 함수
    * 더하기 함수
    * global 키워드 사용 예시
* 입출력
    * 코딩 테스트에서 입력을 위한 전형적인 코드
    * 공백을 기준으로 적은 수의 데이터 입력
    * readline()으로 빠르게 입력 받기
    * f-string 사용 예시
* 주요 라이브러리의 문법과 유의점
    * 내장 함수
    * itertools
    * heapq
    * bisect
    * collections
    * math
* 자신만의 알고리즘 노트 만들기

#### 부록 B 기타 알고리즘

* 이론
    * 소수 판별: ([Python 3.7 코드](/20/1.py) / [C++ 코드](/20/1.cpp) / [Java 코드](/20/1.java))
    * 에라토스테네스의 체: ([Python 3.7 코드](/20/2.py) / [C++ 코드](/20/2.cpp) / [Java 코드](/20/2.java))
    * 특정한 합을 가지는 부분 연속 수열 찾기 (투 포인터): ([Python 3.7 코드](/20/3.py) / [C++ 코드](/20/3.cpp) / [Java 코드](/20/3.java))
    * 정렬되어 있는 두 리스트 합치기 (투 포인터): [Python 3.7 코드](/20/4.py)
    * 구간 합: ([Python 3.7 코드](/20/5.py) / [C++ 코드](/20/5.cpp) / [Java 코드](/20/5.java))
    * 순열: [Python 3.7 코드](/20/6.py)
    * 조합: [Python 3.7 코드](/20/7.py)
* 실전
    * [소수 구하기](https://www.acmicpc.net/problem/1929) (핵심 유형): [Python 3.7 코드](/20/8.py)
    * [암호 만들기](https://www.acmicpc.net/problem/1759) (핵심 유형): [Python 3.7 코드](/20/9.py)

#### 부록 C 개발형 코딩 테스트

* 서버와 클라이언트
* REST API
* JSON
* API 호출 실습
   * API 호출 실습 1
   * API 호출 실습 2
   * 회원 정보 처리 실습

#### 부록 D 알고리즘 유형별 문제 풀이
