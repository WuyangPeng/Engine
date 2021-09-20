// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:38)

#ifndef SKILL_MACRO_USER_MACRO_H
#define SKILL_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_SKILL_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_SKILL_CLOSE 0x00

static_assert(0 <= COMPILE_SKILL_CLOSE, "COMPILE_SKILL_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SKILL_CLOSE <= CLOSE_SKILL_MAX, "COMPILE_SKILL_CLOSE Must be less than or equal CLOSE_SKILL_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_GAME_STATIC
	#define  BUILDING_SKILL_STATIC
#endif // BUILDING_GAME_STATIC

#if !defined(COMPILE_SKILL_CLOSE) || (COMPILE_SKILL_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_SKILL_CLOSE) || (COMPILE_SKILL_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 
 
#endif // SKILL_MACRO_USER_MACRO_H
