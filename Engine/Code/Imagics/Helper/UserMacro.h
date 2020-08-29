// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/30 14:23)

#ifndef IMAGICS_IMAGICS_MACRO_USER_MACRO_H
#define IMAGICS_IMAGICS_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Mathematics/Helper/UserMacro.h"

#define CLOSE_USE_OPENCV (0x01) 
#define CLOSE_IMAGICS_MAX (((CLOSE_USE_OPENCV) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x07��
#define COMPILE_IMAGICS_CLOSE 0x00

static_assert(0 <= COMPILE_IMAGICS_CLOSE, "COMPILE_IMAGICS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_IMAGICS_CLOSE <= CLOSE_IMAGICS_MAX, "COMPILE_IMAGICS_CLOSE Must be less than or equal CLOSE_IMAGICS_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_IMAGICS_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_USE_OPENCV) != CLOSE_USE_OPENCV
	#define IMAGICS_USE_OPENCV
#endif // !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_USE_OPENCV) != CLOSE_USE_OPENCV  
 
#endif // IMAGICS_IMAGICS_MACRO_USER_MACRO_H
