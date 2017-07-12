//
// Created by cpasjuste on 10/07/17.
//

#ifndef _KP2S_HOOKS_IO_H_
#define _KP2S_HOOKS_IO_H_

#include "libmodule.h"

typedef struct Hook {
    SceUID uid;
    tai_hook_ref_t ref;
    const char name[32];
    uint32_t lib;
    uint32_t nid;
    const void *func;
} Hook;

// kernel hooks
enum {
    HOOK_IO_OPEN = 0,
    HOOK_IO_CLOSE,
    HOOK_IO_READ,
    HOOK_IO_WRITE,
    HOOK_IO_LSEEK,
    HOOK_IO_REMOVE,
    HOOK_IO_RENAME,
    HOOK_IO_DOPEN,
    HOOK_IO_DREAD,
    HOOK_IO_DCLOSE,
    HOOK_IO_MKDIR,
    HOOK_IO_RMDIR,
    HOOK_IO_GETSTAT,
    HOOK_IO_GETSTATBYFD,
    HOOK_IO_CHSTAT,
    HOOK_IO_DEVCTL,
    HOOK_END
};

// psp2/io/fcntl.h
SceUID _sceIoOpen(const char *file, int flags, SceMode mode);

SceUID _sceIoOpenAsync(const char *file, int flags, SceMode mode);

int _sceIoClose(SceUID fd);

int _sceIoCloseAsync(SceUID fd);

int _sceIoRead(SceUID fd, void *data, SceSize size);

int _sceIoReadAsync(SceUID fd, void *data, SceSize size);

int _sceIoWrite(SceUID fd, const void *data, SceSize size);

int _sceIoWriteAsync(SceUID fd, const void *data, SceSize size);

SceOff _sceIoLseek(SceUID fd, SceOff offset, int whence);

int _sceIoLseekAsync(SceUID fd, SceOff offset, int whence);

int _sceIoLseek32(SceUID fd, int offset, int whence);

int _sceIoLseek32Async(SceUID fd, int offset, int whence);

int _sceIoRemove(const char *file);

int _sceIoRename(const char *oldname, const char *newname);

int _sceIoSync(const char *device, unsigned int unk);

int _sceIoSyncByFd(SceUID fd);

int _sceIoWaitAsync(SceUID fd, SceInt64 *res);

int _sceIoWaitAsyncCB(SceUID fd, SceInt64 *res);

int _sceIoPollAsync(SceUID fd, SceInt64 *res);

int _sceIoGetAsyncStat(SceUID fd, int poll, SceInt64 *res);

int _sceIoCancel(SceUID fd);

int _sceIoGetDevType(SceUID fd);

int _sceIoChangeAsyncPriority(SceUID fd, int pri);

int _sceIoSetAsyncCallback(SceUID fd, SceUID cb, void *argp);
// psp2/io/fcntl.h

// psp2/io/dirent.h
SceUID _sceIoDopen(const char *dirname);

int _sceIoDread(SceUID fd, SceIoDirent *dir);

int _sceIoDclose(SceUID fd);
// psp2/io/dirent.h

// io/stat.h
int _sceIoMkdir(const char *dir, SceMode mode);

int _sceIoRmdir(const char *path);

int _sceIoGetstat(const char *file, SceIoStat *stat);

int _sceIoGetstatByFd(SceUID fd, SceIoStat *stat);

int _sceIoChstat(const char *file, SceIoStat *stat, int bits);
// io/stat.h

// io/devctl.h
int _sceIoDevctl(const char *dev, unsigned int cmd, void *indata, int inlen, void *outdata, int outlen);
// io/devctl.h

void set_hooks_io();

void delete_hooks_io();

#endif //_KP2S_HOOKS_IO_H_
