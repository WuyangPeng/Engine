// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 10:50)

#ifndef ASSIST_TOOLS_MACRO_USER_MACRO_H
#define ASSIST_TOOLS_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_ASSIST_TOOLS_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_ASSIST_TOOLS_CLOSE 0x00

static_assert(0 <= COMPILE_ASSIST_TOOLS_CLOSE, "COMPILE_ASSIST_TOOLS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ASSIST_TOOLS_CLOSE <= CLOSE_ASSIST_TOOLS_MAX, "COMPILE_ASSIST_TOOLS_CLOSE Must be less than or equal CLOSE_ASSIST_TOOLS_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_ASSIST_TOOLS_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_ASSIST_TOOLS_CLOSE) || (COMPILE_ASSIST_TOOLS_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_ASSIST_TOOLS_CLOSE) || (COMPILE_ASSIST_TOOLS_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 

#endif // ASSIST_TOOLS_MACRO_USER_MACRO_H
