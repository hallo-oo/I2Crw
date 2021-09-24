/***************************************************************
*
* FileName    : typedef.h
* Description : ������������
* Version     : v1.0
* Author      : rj
* Date        : 2016-05-24
* History     :
* <author>		<time>			<version>		<desc>
*	rj			2016-05-24		v1.0			��ʼ�汾
*
**************************************************************/
#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_

// ѹ���洢�ṹ�壬��1�ֽڶ���ṹ���Ա
#define _PACKED_STRUCT	__packed

typedef unsigned char	UCHAR8;
typedef signed char		CHAR8;
typedef unsigned char	UINT8;
typedef signed char		INT8;
typedef unsigned short	UINT16;
typedef signed short	INT16;
typedef unsigned int	UINT;
typedef unsigned long	UINT32;
typedef signed long		INT32;
typedef float			FLOAT32;
typedef double			FLOAT64;
// typedef signed int		BOOL;

typedef unsigned char	U8;
typedef signed char		S8;
typedef unsigned short	U16;
typedef signed short	S16;
typedef unsigned long	U32;
typedef signed long		S32;

typedef struct {
	UINT8* p_dat;
	INT32 len;
} BUF_T, *BUF_PT;

typedef struct {
	UINT16 wr_buf_sz;		// д�뻺���С
	UINT32 erase_unit_sz;	// ������Ԫ��С
	UINT32 total_sz;		// �ܴ�С
	void (*erase)( U32 addr, S32 sz );
	void (*erase_chip)( void );
	void (*write)( U32 addr, U8* p_dat, S32 len );
	void (*read)( U32 addr, U8* p_dat, S32 len );
} FLASH_DRIVER_T;

//#define NULL		0
#define b_TRUE		-1
#define b_FALSE		0

#define INVALID_HANDLE		0xFFFFFFFF

#define GLOBAL_IRQ_ON		__enable_irq()
#define GLOBAL_IRQ_OFF		__disable_irq()

#define ARRAY_COUNT(ARR)	( sizeof(ARR)/sizeof((ARR)[0]) )
// �����ֽ�����ת����ֵ(С��ģʽ)
#define ARR_TO_U16_LE(ARR)	(UINT16)(((ARR)[0])|(((ARR)[1])<<8))
#define ARR_TO_U32_LE(ARR)	(UINT32)(((ARR)[0])|(((ARR)[1])<<8)|(((ARR)[2])<<16)|(((ARR)[3])<<24))
// ����ֵת�ɶ��ֽ�����(С��ģʽ)
#define U16_TO_ARR_LE( VAL, ARR )	\
	do {										\
		(ARR)[0]=(UINT8)((VAL)&0xFF);			\
		(ARR)[1]=(UINT8)(((VAL)>>8)&0xFF);		\
	} while(0)
#define U32_TO_ARR_LE( VAL, ARR )	\
	do {										\
		(ARR)[0]=(UINT8)((VAL)&0xFF);			\
		(ARR)[1]=(UINT8)(((VAL)>>8)&0xFF);		\
		(ARR)[2]=(UINT8)(((VAL)>>16)&0xFF);	\
		(ARR)[3]=(UINT8)(((VAL)>>24)&0xFF);	\
	} while(0)

// �����ֽ�����ת����ֵ(���ģʽ)
#define ARR_TO_U16_BE(ARR)	(UINT32)(((ARR)[1])|(((ARR)[0])<<8))
#define ARR_TO_U32_BE(ARR)	(UINT16)(((ARR)[3])|(((ARR)[2])<<8)|(((ARR)[1])<<16)|(((ARR)[0])<<24))
// ����ֵת�ɶ��ֽ�����(���ģʽ)
#define U16_TO_ARR_BE( VAL, ARR )	\
	do {										\
		(ARR)[0]=(UINT8)(((VAL)>>8)&0xFF);		\
		(ARR)[1]=(UINT8)((VAL)&0xFF);			\
	} while(0)
#define U32_TO_ARR_BE( VAL, ARR )	\
	do {										\
		(ARR)[0]=(UINT8)(((VAL)>>24)&0xFF);	\
		(ARR)[1]=(UINT8)(((VAL)>>16)&0xFF);	\
		(ARR)[2]=(UINT8)(((VAL)>>8)&0xFF);		\
		(ARR)[3]=(UINT8)((VAL)&0xFF);			\
	} while(0)

#endif

