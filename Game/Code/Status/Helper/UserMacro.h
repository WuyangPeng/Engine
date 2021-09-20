// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:46)

#ifndef STATUSMACRO_USER_MACRO_H
#define STATUSMACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_STATUSMAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_STATUSCLOSE 0x00

static_assert(0 <= COMPILE_STATUSCLOSE, "COMPILE_STATUSCLOSE Must be greater than or equal 0.");
static_assert(COMPILE_STATUSCLOSE <= CLOSE_STATUSMAX, "COMPILE_STATUSCLOSE Must be less than or equal CLOSE_STATUSMAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_GAME_STATIC
	#define  BUILDING_STATUSSTATIC
#endif // BUILDING_GAME_STATIC

#if !defined(COMPILE_STATUSCLOSE) || (COMPILE_STATUSCLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_STATUSCLOSE) || (COMPILE_STATUSCLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 
 
#endif // STATUSMACRO_USER_MACRO_H
