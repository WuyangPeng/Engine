// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 17:40)

#ifndef FRAMEWORK_MACRO_USER_MACRO_H
#define FRAMEWORK_MACRO_USER_MACRO_H

#define _SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING

#include "System/Helper/UserMacro.h" 
#include "CoreTools/Helper/UserMacro.h" 
#include "Network/Macro/UserMacro.h" 
#include "Database/Macro/UserMacro.h" 
#include "Script/Macro/UserMacro.h" 
#include "Mathematics/Macro/UserMacro.h" 
#include "SoundEffect/Macro/UserMacro.h" 
#include "InputOutput/Macro/UserMacro.h" 
#include "ResourceManager/Macro/UserMacro.h" 
#include "Rendering/Macro/UserMacro.h" 
#include "Physics/Macro/UserMacro.h" 
#include "Imagics/Macro/UserMacro.h" 
#include "Animation/Macro/UserMacro.h" 
#include "ArtificialIntellegence/Macro/UserMacro.h" 
#include "UserInterface/Macro/UserMacro.h" 
#include "AssistTools/Macro/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_FRAMEWORK_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_FRAMEWORK_CLOSE 0x00

static_assert(0 <= COMPILE_FRAMEWORK_CLOSE, "COMPILE_FRAMEWORK_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_FRAMEWORK_CLOSE <= CLOSE_FRAMEWORK_MAX, "COMPILE_FRAMEWORK_CLOSE Must be less than or equal CLOSE_FRAMEWORK_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_FRAMEWORK_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_FRAMEWORK_CLOSE) || (COMPILE_FRAMEWORK_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_FRAMEWORK_CLOSE) || (COMPILE_FRAMEWORK_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX  
 
#endif // FRAMEWORK_MACRO_USER_MACRO_H
