// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 10:03)

#ifndef ARTIFICIAL_INTELLEGENCE_MACRO_USER_MACRO_H
#define ARTIFICIAL_INTELLEGENCE_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_ARTIFICIAL_INTELLEGENCE_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_ARTIFICIAL_INTELLEGENCE_CLOSE 0x00

static_assert(0 <= COMPILE_ARTIFICIAL_INTELLEGENCE_CLOSE, "COMPILE_ARTIFICIAL_INTELLEGENCE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ARTIFICIAL_INTELLEGENCE_CLOSE <= CLOSE_ARTIFICIAL_INTELLEGENCE_MAX, "COMPILE_ARTIFICIAL_INTELLEGENCE_CLOSE Must be less than or equal CLOSE_ARTIFICIAL_INTELLEGENCE_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_ARTIFICIAL_INTELLEGENCE_CLOSE) || (COMPILE_ARTIFICIAL_INTELLEGENCE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_ARTIFICIAL_INTELLEGENCE_CLOSE) || (COMPILE_ARTIFICIAL_INTELLEGENCE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX  
 
#endif // ARTIFICIAL_INTELLEGENCE_MACRO_USER_MACRO_H
