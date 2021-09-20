// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.1.0.1 (2020/04/05 17:51)

#ifndef BOOK_UML_MACRO_USER_MACRO_H
#define BOOK_UML_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CLOSE_USE_BOOK_UML (0x01) 
#define CLOSE_BOOK_UML_MAX ((CLOSE_USE_BOOK_UML << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_BOOK_UML_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_UML_CLOSE, "COMPILE_BOOK_UML_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_UML_CLOSE <= CLOSE_BOOK_UML_MAX, "COMPILE_BOOK_UML_CLOSE Must be less than or equal CLOSE_BOOK_UML_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_BOOK_UML_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_BOOK_UML_CLOSE) || (COMPILE_BOOK_UML_CLOSE & CLOSE_USE_BOOK_UML) != CLOSE_USE_BOOK_UML

#endif // !defined(COMPILE_BOOK_UML_CLOSE) || (COMPILE_BOOK_UML_CLOSE & CLOSE_USE_BOOK_UML) != CLOSE_USE_BOOK_UML 
 
#endif // BOOK_UML_MACRO_USER_MACRO_H
