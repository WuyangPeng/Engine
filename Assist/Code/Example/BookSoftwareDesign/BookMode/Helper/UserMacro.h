// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.3.0 (2020/03/24 21:30)

#ifndef BOOK_MODE_MACRO_USER_MACRO_H
#define BOOK_MODE_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CLOSE_USE_BOOK_MODE (0x01) 
#define CLOSE_BOOK_MODE_MAX ((CLOSE_USE_BOOK_MODE << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_BOOK_MODE_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_MODE_CLOSE, "COMPILE_BOOK_MODE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_MODE_CLOSE <= CLOSE_BOOK_MODE_MAX, "COMPILE_BOOK_MODE_CLOSE Must be less than or equal CLOSE_BOOK_MODE_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_BOOK_MODE_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_BOOK_MODE_CLOSE) || (COMPILE_BOOK_MODE_CLOSE & CLOSE_USE_BOOK_MODE) != CLOSE_USE_BOOK_MODE

#endif // !defined(COMPILE_BOOK_MODE_CLOSE) || (COMPILE_BOOK_MODE_CLOSE & CLOSE_USE_BOOK_MODE) != CLOSE_USE_BOOK_MODE 
 
#endif // BOOK_MODE_MACRO_USER_MACRO_H
