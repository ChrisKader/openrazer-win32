#ifndef KERNEL_H_
#define KERNEL_H_

#include <windows.h>

#define ARRAY_SIZE(array) \
    (sizeof(array) / sizeof(*array))

#define DLL_INTERNAL __declspec( dllexport )

#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned int
#define u64 unsigned long

#define s8 char
#define s16 short
#define s32 int
#define s64 long

#define __u8 unsigned char
#define __u16 unsigned short
#define __u32 unsigned int
#define __u64 unsigned long
#define uint8_t unsigned char
#define uint16_t unsigned short
#define uint32_t unsigned int
#define uint64_t unsigned long
#define __le8 unsigned char
#define __le16 unsigned short
#define __le32 unsigned int
#define __le64 unsigned long
#define __s8 signed char
#define __s16 signed short
#define __s32 signed int
#define __s64 signed long
#define uint unsigned int
#define ulong unsigned long

#define socklen_t int

#define bool int
#define true 1
#define false 0

#define size_t SIZE_T
#define ssize_t SSIZE_T

struct mutex {
	CRITICAL_SECTION lock;
};

inline void mutex_init(struct mutex* mutex) {
	InitializeCriticalSection(&mutex->lock);
}

inline void mutex_lock(struct mutex* mutex) {
	EnterCriticalSection(&mutex->lock);
}

inline void mutex_unlock(struct mutex* mutex) {
	LeaveCriticalSection(&mutex->lock);
}

inline int mutex_trylock(struct mutex* mutex) {
	return TryEnterCriticalSection(&mutex->lock);
}

inline int mutex_is_locked(struct mutex* mutex) {
	if (mutex_trylock(mutex)) {
		mutex_unlock(mutex);
		return 0;
	}
	else
		return 1;
}

inline void set_bit(int nr, volatile unsigned long *addr) {
        int *a = (int *)addr;
        int mask;

        a += nr >> 5;
        mask = 1 << (nr & 0x1f);
        *a |= mask;
}
#define __set_bit set_bit

inline void clear_bit(int nr, volatile unsigned long *addr) {
        int *a = (int *)addr;
        int mask;

        a += nr >> 5;
        mask = 1 << (nr & 0x1f);
        *a &= ~mask;
}

inline int test_bit(int nr, const void *addr) {
        int *a = (int *)addr;
        int mask;

		a += nr >> 5;
        mask = 1 << (nr & 0x1f);
        return ((mask & *a) != 0);
}

inline int kstrtouint(const char* s,
    unsigned int base,
    unsigned int* res)
{
    return 0;
}

int kstrtobool(const char* s, bool* res)
{
	if (!s)
		return -EINVAL;

	switch (s[0]) {
	case 'y':
	case 'Y':
	case '1':
		*res = true;
		return 0;
	case 'n':
	case 'N':
	case '0':
		*res = false;
		return 0;
	case 'o':
	case 'O':
		switch (s[1]) {
		case 'n':
		case 'N':
			*res = true;
			return 0;
		case 'f':
		case 'F':
			*res = false;
			return 0;
		default:
			break;
		}
	default:
		break;
	}

	return -EINVAL;
}

static inline void input_report_rel(struct input_dev* dev, unsigned int code, int value)
{
    
}

inline struct usb_interface* usb_ifnum_to_if(const struct usb_device* dev,
    unsigned ifnum)
{
    return NULL;
}

inline void input_set_capability(struct input_dev* dev, unsigned int type, unsigned int code)
{

}
#endif /* KERNEL_H_ */
