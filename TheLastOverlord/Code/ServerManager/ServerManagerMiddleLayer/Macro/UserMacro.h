// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 16:49)

#ifndef SERVER_MANAGER_MIDDLE_LAYER_MACRO_USER_MACRO_H
#define SERVER_MANAGER_MIDDLE_LAYER_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_SERVER_MANAGER_MIDDLE_LAYER_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_SERVER_MANAGER_MIDDLE_LAYER_CLOSE 0x00

static_assert(0 <= COMPILE_SERVER_MANAGER_MIDDLE_LAYER_CLOSE, "COMPILE_SERVER_MANAGER_MIDDLE_LAYER_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SERVER_MANAGER_MIDDLE_LAYER_CLOSE <= CLOSE_SERVER_MANAGER_MIDDLE_LAYER_MAX, "COMPILE_SERVER_MANAGER_MIDDLE_LAYER_CLOSE Must be less than or equal CLOSE_SERVER_MANAGER_MIDDLE_LAYER_MAX.");

#if !defined(COMPILE_SERVER_MANAGER_MIDDLE_LAYER_CLOSE) || (COMPILE_SERVER_MANAGER_MIDDLE_LAYER_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_SERVER_MANAGER_MIDDLE_LAYER_CLOSE) || (COMPILE_SERVER_MANAGER_MIDDLE_LAYER_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 

// �Ƿ����ɾ�̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC
#endif // BUILDING_STATIC
 
#endif // SERVER_MANAGER_MIDDLE_LAYER_MACRO_USER_MACRO_H
