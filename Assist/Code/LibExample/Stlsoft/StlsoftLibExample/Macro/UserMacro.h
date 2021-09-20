// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.0.0.3 (2019/09/30 16:14)

#ifndef STLSOFT_LIB_EXAMPLE_MACRO_USER_MACRO_H
#define STLSOFT_LIB_EXAMPLE_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_STLSOFT_LIB_EXAMPLE_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_STLSOFT_LIB_EXAMPLE_CLOSE 0x00

static_assert(0 <= COMPILE_STLSOFT_LIB_EXAMPLE_CLOSE, "COMPILE_STLSOFT_LIB_EXAMPLE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_STLSOFT_LIB_EXAMPLE_CLOSE <= CLOSE_STLSOFT_LIB_EXAMPLE_MAX, "COMPILE_STLSOFT_LIB_EXAMPLE_CLOSE Must be less than or equal CLOSE_STLSOFT_LIB_EXAMPLE_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_STLSOFT_LIB_EXAMPLE_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_STLSOFT_LIB_EXAMPLE_CLOSE) || (COMPILE_STLSOFT_LIB_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_STLSOFT_LIB_EXAMPLE_CLOSE) || (COMPILE_STLSOFT_LIB_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 
 
#endif // STLSOFT_LIB_EXAMPLE_MACRO_USER_MACRO_H
