// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/06 20:19)

#ifndef CHAT_MACRO_USER_MACRO_H
#define CHAT_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_CHAT_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_CHAT_CLOSE 0x00

static_assert(0 <= COMPILE_CHAT_CLOSE, "COMPILE_CHAT_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CHAT_CLOSE <= CLOSE_CHAT_MAX, "COMPILE_CHAT_CLOSE Must be less than or equal CLOSE_CHAT_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_GAME_STATIC
	#define  BUILDING_CHAT_STATIC
#endif // BUILDING_GAME_STATIC

#if !defined(COMPILE_CHAT_CLOSE) || (COMPILE_CHAT_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_CHAT_CLOSE) || (COMPILE_CHAT_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 
 
#endif // CHAT_MACRO_USER_MACRO_H
