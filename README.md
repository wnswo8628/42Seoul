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

## 5️⃣: pipex

### :heavy_exclamation_mark: shell에서 사용하는 파이프(|)와 동일한 기능을 하는 함수 만들기.

부모-자식 프로세스간 연결하기!

#### :bangbang: 사용할수 있는 함수
fork, pipe, access, open, close, execve, perror, waitpid

## 6️⃣: so_long

### :heavy_exclamation_mark: 미니 2D 게임 만들기!

42에서 제공하는 miniLibX를 이용해서 플레이어가 오브젝트를 먹고 다 먹었을 경우에만 탈출구로 탈출이 가능하도록 하는 게임.
만약 탈출하는 경로가 막혀있거나 모든 오브젝트를 먹지 못하는 맵일 경우 예외처리하기!(DFS를 사용)

## 7️⃣: Philosophers

### :heavy_exclamation_mark: 운영체제에서 유명한 문제인 식사하는 철학자 문제를 직접 구현!

쓰레드와 상호배제(mutex)를 이용하여 철학자 문제를 해결하기.

## 8️⃣: minishell

### :heavy_exclamation_mark: bash나 zsh 같은 쉘 스크립트를 직접 구현!

명령어 파싱에는 토큰이라는 구조를 사용하기!
시그널 처리도 해야됨!
앞서 했던 과제인 파이프도 사용하기!

## 9️⃣: cub3d

### :heavy_exclamation_mark: 이번엔 3D 미로 게임을 구현!

42에서 제공하는 miniLibX를 사용해서 3D 미로 게임 구현!
레이캐스팅을 공부하고 사용해야함!
맵은 항상 벽으로 둘러싸여 있어야 하고 플레이어는 무조건 1명이여야 하므로 맵 유효성 검사도 하기!

## 🔟: cpp_module00 ~ 09

### :heavy_exclamation_mark: C++의 기본 문법 및 특징들에 대해 실습

C++의 핵심 특징인 상속, 객체, 클래스, 동적할당등 여러 특징들을 직접 구현해보면서 익히기!

## :one: :one: ft_irc

### :heavy_exclamation_mark: C++의 기본 문법 및 특징들에 대해 실습
