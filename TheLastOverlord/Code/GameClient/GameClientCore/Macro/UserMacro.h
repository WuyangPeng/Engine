// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.2.0 (2020/01/08 23:49)

#ifndef GAME_CLIENT_CORE_MACRO_USER_MACRO_H
#define GAME_CLIENT_CORE_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h" 

#define CLOSE_USE_GAME_CLIENT_CORE (0x01) 
#define CLOSE_GAME_CLIENT_CORE_MAX (((CLOSE_USE_GAME_CLIENT_CORE) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_GAME_CLIENT_CORE_CLOSE 0x00

static_assert(0 <= COMPILE_GAME_CLIENT_CORE_CLOSE, "COMPILE_GAME_CLIENT_CORE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_GAME_CLIENT_CORE_CLOSE <= CLOSE_GAME_CLIENT_CORE_MAX, "COMPILE_GAME_CLIENT_CORE_CLOSE Must be less than or equal CLOSE_GAME_CLIENT_CORE_MAX.");

#if !defined(COMPILE_GAME_CLIENT_CORE_CLOSE) || (COMPILE_GAME_CLIENT_CORE_CLOSE & CLOSE_USE_GAME_CLIENT_CORE) != CLOSE_USE_GAME_CLIENT_CORE

#endif // !defined(COMPILE_GAME_CLIENT_CORE_CLOSE) || (COMPILE_GAME_CLIENT_CORE_CLOSE & CLOSE_USE_GAME_CLIENT_CORE) != CLOSE_USE_GAME_CLIENT_CORE  

// �Ƿ����ɾ�̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_GAME_CLIENT_CORE_STATIC
#endif // BUILDING_STATIC

#endif // GAME_CLIENT_CORE_MACRO_USER_MACRO_H
