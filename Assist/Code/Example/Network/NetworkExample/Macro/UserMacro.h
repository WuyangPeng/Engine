// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/23 23:16)

#ifndef NETWORK_EXAMPLE_MACRO_USER_MACRO_H
#define NETWORK_EXAMPLE_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_NETWORK_EXAMPLE_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_NETWORK_EXAMPLE_CLOSE 0x00

static_assert(0 <= COMPILE_NETWORK_EXAMPLE_CLOSE, "COMPILE_NETWORK_EXAMPLE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_NETWORK_EXAMPLE_CLOSE <= CLOSE_NETWORK_EXAMPLE_MAX, "COMPILE_NETWORK_EXAMPLE_CLOSE Must be less than or equal CLOSE_NETWORK_EXAMPLE_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_NETWORK_EXAMPLE_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_NETWORK_EXAMPLE_CLOSE) || (COMPILE_NETWORK_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_NETWORK_EXAMPLE_CLOSE) || (COMPILE_NETWORK_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 
 
#endif // NETWORK_EXAMPLE_MACRO_USER_MACRO_H
