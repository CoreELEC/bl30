#ifndef __MAILBOX_API_H__
#define __MAILBOX_API_H__

#if __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <FreeRTOS.h>
#include "task.h"
#include "mailbox.h"
#include "rpc-user.h"

#define TICKS_TO_WAIT			100
#define TASK_PRIORITY			4

#define MBOX_BUF_LEN			MHU_DATA_SIZE

/*use by mailbox driver*/
#define AOREE_CHANNEL			2
#define AOTEE_CHANNEL			4

/*if call mbox api, use this define CHANNEL*/
#define MAILBOX_CHANNEL			AOREE_CHANNEL


BaseType_t xInstallRemoteMessageCallbackFeedBack(uint32_t ulChan, uint32_t cmd,
						 void *(handler) (void *),
						 uint8_t needFdBak);

BaseType_t xUninstallRemoteMessageCallback(uint32_t ulChan,
					   int32_t cmd);

void vMbInit(void);
#if __cplusplus
}
#endif
#endif

