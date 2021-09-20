// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/12 21:15)

#ifndef USER_INTERFACE_EDITOR_MACRO_USER_MACRO_H
#define USER_INTERFACE_EDITOR_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_USER_INTERFACE_EDITOR_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_USER_INTERFACE_EDITOR_CLOSE 0x00

static_assert(0 <= COMPILE_USER_INTERFACE_EDITOR_CLOSE, "COMPILE_USER_INTERFACE_EDITOR_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_USER_INTERFACE_EDITOR_CLOSE <= CLOSE_USER_INTERFACE_EDITOR_MAX, "COMPILE_USER_INTERFACE_EDITOR_CLOSE Must be less than or equal CLOSE_USER_INTERFACE_EDITOR_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_USER_INTERFACE_EDITOR_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_USER_INTERFACE_EDITOR_CLOSE) || (COMPILE_USER_INTERFACE_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_USER_INTERFACE_EDITOR_CLOSE) || (COMPILE_USER_INTERFACE_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 
 
#endif // USER_INTERFACE_EDITOR_MACRO_USER_MACRO_H
