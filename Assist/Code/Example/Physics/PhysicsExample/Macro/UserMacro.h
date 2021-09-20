// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/26 15:58)

#ifndef PHYSICS_EXAMPLE_MACRO_USER_MACRO_H
#define PHYSICS_EXAMPLE_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_PHYSICS_EXAMPLE_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_PHYSICS_EXAMPLE_CLOSE 0x00

static_assert(0 <= COMPILE_PHYSICS_EXAMPLE_CLOSE, "COMPILE_PHYSICS_EXAMPLE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_PHYSICS_EXAMPLE_CLOSE <= CLOSE_PHYSICS_EXAMPLE_MAX, "COMPILE_PHYSICS_EXAMPLE_CLOSE Must be less than or equal CLOSE_PHYSICS_EXAMPLE_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_PHYSICS_EXAMPLE_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_PHYSICS_EXAMPLE_CLOSE) || (COMPILE_PHYSICS_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_PHYSICS_EXAMPLE_CLOSE) || (COMPILE_PHYSICS_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 
 
#endif // PHYSICS_EXAMPLE_MACRO_USER_MACRO_H