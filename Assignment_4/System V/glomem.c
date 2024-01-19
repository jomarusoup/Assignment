/******************************************************************************
* SOURCE NAME  : glomem.h
* DESCRIPTION  : ���� �޸� ���̺귯��
* DATE         :
* AUTHOR       :
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#include "kntable.h"
#include "glomem.h"

KEYNAME *g_KnList = NULL;

/******************************************************************************
FUNCTION    : GlobalCheckShm
DESCRIPTION : ���� �޸� ���� Ȯ��
PARAMETERS  :
RETURNED    : 1(SUCCESS), -1(FAIL)
******************************************************************************/
int GlobalCheckShm()
{
    int     shmid, shmin;
    struct  shmid_ds shminfo;

    shmid = shmget(SHM_KEY, 0, PERM);
    if (shmid < 0) return -1;

    // �������� �˻��Ͽ� ���� �޸� ���׸�Ʈ ���� Ȯ��
    shmin = shmctl(shmid, IPC_STAT, &shminfo);
    if (shmin == 0) return shmid;

}


/******************************************************************************
FUNCTION    : GlobalCreateShm
DESCRIPTION : ���� �޸� ����
PARAMETERS  :
RETURNED    : shmid - ���� �޸� ID
******************************************************************************/
int GlobalCreateShm()
{
    int shmid;

    shmid = shmget(SHM_KEY, MAX_ENTRIES * sizeof(KEYNAME), IPC_CREAT | PERM);
    if (shmid < 0)
        return -1;

    g_KnList = shmat(shmid, NULL, 0);
    if (g_KnList < 0)
        return -1;

    memset(g_KnList, 0x00, MAX_ENTRIES * sizeof(KEYNAME));

    shmdt(g_KnList);

    return shmid;
}


/******************************************************************************
FUNCTION    : GlobalAttachShm
DESCRIPTION : ���� �޸� attach
PARAMETERS  :
RETURNED    : 1(SUCCESS), -1(FAIL)
******************************************************************************/
/*--- System V shared memory attach ---*/
#if 0
int GlobalAttachShm()
{
	int shmid;

	shmid = shmget(SHM_KEY, 0, PERM);

	g_KnList = shmat(shmid, NULL, 0);
	if (g_KnList == (KEYNAME*)-1)
	{
		printf("attach error! [%d] : %s\n", errno, strerror(errno));
		return -1;
	}

	return 1;
}
#endif

KEYNAME *GlobalAttachShm()
{
	int		 shmid;

	shmid = shmget(SHM_KEY, 0, PERM);
	if (shmid < 0)
	{
		printf("shmget error: %s\n", strerror(errno));
		return NULL;
	}

	g_KnList = shmat(shmid, NULL, 0);
	if (g_KnList == (void*)-1)
		return NULL;

	return g_KnList;
}

/******************************************************************************
FUNCTION    : GlobalDetachShm
DESCRIPTION : ���� �޸� detach
PARAMETERS  :
RETURNED    : 1(SUCCESS), -1(FAIL)
******************************************************************************/
int GlobalDetachShm()
{
	if (shmdt(g_KnList) < 0)
	{
		printf("detach error! [%d] : %s\n", errno, strerror(errno));
		return -1;
	}

	return 1;
}

/******************************************************************************
FUNCTION    : GlobalRemoveShm
DESCRIPTION : ���� �޸� ����
PARAMETERS  :
RETURNED    : 1(SUCCESS), -1(FAIL)
******************************************************************************/
int GlobalRemoveShm()
{
	int shmid, ret;

	shmid = shmget(SHM_KEY, 0, PERM);
	if (shmid < 0)
	{
		printf("shmget error! [%d] : %s\n", errno, strerror(errno));
		return -1;
	}

	ret = shmctl(shmid, IPC_RMID, NULL);
	if (ret < 0)
	{
		printf("shmctl error! [%d] : %s\n", errno, strerror(errno));
		return -1;
	}
	else
	{
		printf("Remove Shared Memory\n");
	}

	return 1;
}

