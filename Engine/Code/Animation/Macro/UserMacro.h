// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 09:51)

#ifndef ANIMATION_MACRO_USER_MACRO_H
#define ANIMATION_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_ANIMATION_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_ANIMATION_CLOSE 0x00

static_assert(0 <= COMPILE_ANIMATION_CLOSE, "COMPILE_ANIMATION_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ANIMATION_CLOSE <= CLOSE_ANIMATION_MAX, "COMPILE_ANIMATION_CLOSE Must be less than or equal CLOSE_ANIMATION_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_ANIMATION_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_ANIMATION_CLOSE) || (COMPILE_ANIMATION_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_ANIMATION_CLOSE) || (COMPILE_ANIMATION_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 
 
#endif // ANIMATION_MACRO_USER_MACRO_H
