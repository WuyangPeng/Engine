// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/01 11:15)

#ifndef PERL_LIB_EXAMPLE_MACRO_USER_MACRO_H
#define PERL_LIB_EXAMPLE_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_PERL_LIB_EXAMPLE_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_PERL_LIB_EXAMPLE_CLOSE 0x00

static_assert(0 <= COMPILE_PERL_LIB_EXAMPLE_CLOSE, "COMPILE_PERL_LIB_EXAMPLE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_PERL_LIB_EXAMPLE_CLOSE <= CLOSE_PERL_LIB_EXAMPLE_MAX, "COMPILE_PERL_LIB_EXAMPLE_CLOSE Must be less than or equal CLOSE_PERL_LIB_EXAMPLE_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_PERL_LIB_EXAMPLE_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_PERL_LIB_EXAMPLE_CLOSE) || (COMPILE_PERL_LIB_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_PERL_LIB_EXAMPLE_CLOSE) || (COMPILE_PERL_LIB_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 
 
#endif // PERL_LIB_EXAMPLE_MACRO_USER_MACRO_H