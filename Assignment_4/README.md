# Table

- [Question](#question)
- [Formatting](#formatting)
- [Input & Output example](#input--output-example)

# Question

- 이 프로젝트는 POSIX 공유 메모리에 대해 쓰기, 읽기, 검색, 삭제 기능을 수행하는 프로그램

- key에 대한 중복값 예외


- utilM.c
    - main
- lib.c
    - Insert, Read, Delete, Search 등의 라이브러리 함수
- glomem.c
    - 공유 메모리 함수 라이브러리
- glomem.h
    - 공유 메모리 미와 관련 define 값
    - glomem.c 프로토 타입
- kntable.h
    - define 값과 구조체
- file.txt
    - 데이터만 저장된 파체체

# Formatting
- 기본 형식
- 필요에 따라 사용자 지정 함수 변경 및 추가 삭제 가능

## kntable.h
```c
/******************************************************************************
* SOURCE NAME  : kntable.h
* DESCRIPTION  :
* DATE         :
* AUTHOR       :
******************************************************************************/

/*--- define ---*/
#define KEYSIZE 9
#define NAMESIZE 40

#ifndef KNLIST_H
#define KNLIST_H

/*--- struct ---*/
typedef struct KEYNAME
{
    char key[KEYSIZE];
    char name[NAMESIZE];
} KEYNAME;

extern KEYNAME *g_KnList;

#endif /* KNLIST_H */

```

## glomem.h
```c
/******************************************************************************
* SOURCE NAME  : glomem.h
* DESCRIPTION  : SHM key와 prototype
* DATE         :
* AUTHOR       :
******************************************************************************/

/*--- define ---*/
#define SHM_KEY     0x00012345
#define PERM        0666
#define MAX_ENTRIES 1000

/*--- prototype ---*/

```

## lib.c
```c
/******************************************************************************
 * FILE NAME   : lib.c
 * DESCRIPTION : 공유 메모리 함수
 * DATE        :
 * AUTHOR      :
 ******************************************************************************/
#include <stdio.h>

/******************************************************************************
FUNCTION    : Cmp
DESCRIPTION : 비교함수
PARAMETERS  : const void *aa - 비교할 데이터
              const void *bb - 비교할 데이터
RETURNED    : strcmp()의 반환값
******************************************************************************/
int Cmp()
{

}

/******************************************************************************
FUNCTION    : CountShm
DESCRIPTION : 공유 메모리 내의 레코드 개수
PARAMETERS  :
RETURNED    : count - 레코드 개수
******************************************************************************/
int CountShm()
{

}

/******************************************************************************
FUNCTION    : lInsertShm
DESCRIPTION : 공유 메모리에 데이터 입력
PARAMETERS  :
RETURNED    :  1(SUCCESS)
******************************************************************************/
int lInsertShm()
{

}

/******************************************************************************
FUNCTION    : ReadShm
DESCRIPTION : 공유 메모리에 데이터 출력
PARAMETERS  :
RETURNED    : 1(SUCCESS)
******************************************************************************/
lReadShm()
{

}

/******************************************************************************
FUNCTION    : SearchShm
DESCRIPTION : 공유 메모리에 데이터 검색
PARAMETERS  :
RETURNED    : 1(SUCCESS)
******************************************************************************/
int lSearchShm()
{

}

/******************************************************************************
FUNCTION    : DeleteShm
DESCRIPTION : 공유 메모리에 데이터 삭제
PARAMETERS  :
RETURNED    : 1(SUCCESS)
******************************************************************************/
int lDeleteShm()
{

}

```

## glomem.c
```c
/******************************************************************************
* SOURCE NAME  : glomem.h
* DESCRIPTION  : 공유 메모리 라이브러리
* DATE         :
* AUTHOR       :
******************************************************************************/
#include <stdio.h>

/******************************************************************************
FUNCTION    : GlobalCreateShm
DESCRIPTION : 공유 메모리 생성
PARAMETERS  :
RETURNED    :
******************************************************************************/
int GlobalCreateShm()
{

}

/******************************************************************************
FUNCTION    : GlobalCheckShm
DESCRIPTION : 공유 메모리 존재 확인
PARAMETERS  :
RETURNED    :
******************************************************************************/
int GlobalCheckShm()
{

}

/******************************************************************************
FUNCTION    : GlobalAttachShm
DESCRIPTION : 공유 메모리 attach
PARAMETERS  :
RETURNED    :
******************************************************************************/
KEYNAME *GlobalAttachShm()
{

}

/******************************************************************************
FUNCTION    : GlobalDetachShm
DESCRIPTION : 공유 메모리 detach
PARAMETERS  :
RETURNED    :
******************************************************************************/
int GlobalDetachShm()
{

}

/******************************************************************************
FUNCTION    : GlobalRemoveShm
DESCRIPTION : 공유 메모리 삭제
PARAMETERS  :
RETURNED    :
******************************************************************************/
int GlobalRemoveShm()
{

}
```

## utilM.c
```c
/******************************************************************************
* FILE NAME   : main.c
* DESCRIPTION : 메인 함수
* DATE        :
* AUTHOR      :
******************************************************************************/
#include <stdio.h>

/******************************************************************************
FUNCTION    : InsertShmU
DESCRIPTION : 공유 메모리에 데이터 추가
PARAMETERS  :
RETURNED    : 1(SUCCESS)
******************************************************************************/
int InsertShmU()
{

}

/******************************************************************************
FUNCTION    : ReadShmU
DESCRIPTION : 공유 메모리에 데이터 출력
PARAMETERS  :
RETURNED    : 1(SUCCESS)
******************************************************************************/
int ReadShmU()
{

}

/******************************************************************************
FUNCTION    : SearchShmU
DESCRIPTION : 공유 메모리에서 데이터 검색
PARAMETERS  :
RETURNED    : 1(SUCCESS)
******************************************************************************/
int SearchShmU()
{

}

/******************************************************************************
FUNCTION    : DeleteShmU
DESCRIPTION : 공유 메모리에서 데이터 삭제
PARAMETERS  :
RETURNED    : 1(SUCCESS)
******************************************************************************/
int DeleteShmU()
{

}

/******************************************************************************
FUNCTION    : CheckShmU
DESCRIPTION : 공유 메모리 존재 여부 확인
PARAMETERS  :
RETURNED    : 1(SUCCESS)
******************************************************************************/
int CheckShmU()
{

}

/******************************************************************************
FUNCTIONS   : Usage
DESCRIPTION : Usage display
PARAMETERS  :
RETURNED    :
******************************************************************************/
void Usage()
{

}

/******************************************************************************
FUNCTION    : main
DESCRIPTION : 메인 함수
PARAMETERS  :
RETURNED    : 0(SUCCESS)
******************************************************************************/
int main()
{

}


```



# Input & Output example

## Usage
```bash
$ /utilM

**********************************
|                                |
|     Shared Memory Control      |
|                                |
*================================*
|                                |
|                                |
|   [1] Check Shared Memory      |
|   [2] Create Shared Memory     |
|   [3] Add                      |
|   [4] Read                     |
|   [5] Search                   |
|   [6] Delete                   |
|   [7] Remove Shared Memory     |
|                                |
*================================*


 Use : ./utilM [ Control Number ]


```

## SHM check
```bash
$ ./utilM 1

*--------------------------------*
|                                |
|       Exist Shared Memory      |
|                                |
*--------------------------------*

```

## Create SHM