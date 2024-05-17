![header](https://capsule-render.vercel.app/api?type=wave&color=auto&height=300&section=header&text=42Seoul&fontSize=90)
# :computer: 42본과정 :computer:
42서울 본과정때 수행했던 과제들입니다.

## :pencil2: Skill

<img src="https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=C&logoColor=white"> <img src="https://img.shields.io/badge/C++-512BD4?style=for-the-badge&logo=C++&logoColor=white"> <img src="https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=Docker&logoColor=white"> <img src="https://img.shields.io/badge/NGINX-009639?style=for-the-badge&logo=NGINX&logoColor=white">

## :one: libft

### :heavy_exclamation_mark: 나만의 라이브러리 만들기

C에 내장된 여러 함수들을 직접 구현하면서 나만의 라이브러리를 만드는 과제

## 2️⃣: ft_printf

### :heavy_exclamation_mark: printf 함수를 구현해 보기

stdio.h에 내장된 printf함수를 직접 구현해보기

## 3️⃣: get_next_line

### :heavy_exclamation_mark: 파일 디스크럽터로부터 읽어온 하나의 라인을 반환하는 함수를 작성

read()함수를 사용해 한 파일에 있는 내용을 개행전까지 반환해주는 함수 만들기

## 4️⃣: push_swap

### :heavy_exclamation_mark: 두 개의 스택(A, B)에 들어있는 숫자들을 적절한 연산을 통해 스택A에 들어있는 숫자를 오름차순으로 정렬하기.

#### :bangbang: 사용할수 있는 연산
sa: A의 가장 위에 있는 두 원소(혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.

sb: B의 가장 위에 있는 두 원소(혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.

ss: sa와 sb를 동시에 실행한다.

pa: B에서 가장 위(탑)에 있는 원소를 가져와서 A의 맨 위(탑)에 넣는다. B가 비어 있으면 아무 것도 하지 않는다.

pb: A에서 가장 위(탑)에 있는 원소를 가져와서 B의 맨 위(탑)에 넣는다. A가 비어 있으면 아무 것도 하지 않는다.

ra: A의 모든 원소들을 위로 1 인덱스만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.

rb: B의 모든 원소들을 위로 1 인덱스만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.

rr: ra와 rb를 동시에 실행한다.

rra: A의 모든 원소들을 아래로 1 인덱스만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.

rrb: B의 모든 원소들을 아래로 1 인덱스만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.

rrr: rra와 rrb를 동시에 실행한다.

#### :bangbang: 사용한 알고리즘
그리디 알고리즘(탐욕 알고리즘)
매 순간 최적의 경우를 선택하는 알고리즘
최소한의 연산을 사용하는 숫자를 찾아서 정렬을 함
