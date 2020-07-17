// Threading Core Render Engine
// ���ߣ������������ʶ���������
// Copyright (c) 2011-2018
//
// ����汾��0.0.0.1 (2018/07/19 13:22)

#ifndef INPUT_OUTPUT_MACRO_USER_MACRO_H
#define INPUT_OUTPUT_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_X (0x01) 
#define CLOSE_INPUT_OUTPUT_MAX (((CLOSE_USE_X) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_INPUT_OUTPUT_CLOSE 0x00

static_assert(0 <= COMPILE_INPUT_OUTPUT_CLOSE, "COMPILE_INPUT_OUTPUT_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_INPUT_OUTPUT_CLOSE <= CLOSE_INPUT_OUTPUT_MAX, "COMPILE_INPUT_OUTPUT_CLOSE Must be less than or equal CLOSE_INPUT_OUTPUT_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_INPUT_OUTPUT_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_INPUT_OUTPUT_CLOSE) || (COMPILE_INPUT_OUTPUT_CLOSE & CLOSE_USE_X) != CLOSE_USE_X
	#define INPUT_OUTPUT_USE_X
#endif // !defined(COMPILE_INPUT_OUTPUT_CLOSE) || (COMPILE_INPUT_OUTPUT_CLOSE & CLOSE_USE_X) != CLOSE_USE_X   
 
#endif // INPUT_OUTPUT_MACRO_USER_MACRO_H
