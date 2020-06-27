// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/20 10:53)

#ifndef FRAMEWORK_HELPER_USER_MACRO_H
#define FRAMEWORK_HELPER_USER_MACRO_H

#include "System/Helper/UserMacro.h" 
#include "CoreTools/Helper/UserMacro.h" 
#include "Network/Helper/UserMacro.h" 
#include "Database/Helper/UserMacro.h" 
#include "Script/Helper/UserMacro.h" 
#include "Mathematics/Helper/UserMacro.h" 
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

#define CLOSE_USE_ANDROID_TEST (0x01) 
#define CLOSE_FRAMEWORK_MAX (((CLOSE_USE_ANDROID_TEST) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_FRAMEWORK_CLOSE 0x01

static_assert(0 <= COMPILE_FRAMEWORK_CLOSE, "COMPILE_FRAMEWORK_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_FRAMEWORK_CLOSE <= CLOSE_FRAMEWORK_MAX, "COMPILE_FRAMEWORK_CLOSE Must be less than or equal CLOSE_FRAMEWORK_MAX.");

// 是否编译为静态库
#ifdef BUILDING_STATIC
	#define BUILDING_FRAMEWORK_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_FRAMEWORK_CLOSE) || (COMPILE_FRAMEWORK_CLOSE & CLOSE_USE_ANDROID_TEST) != CLOSE_USE_ANDROID_TEST

	#ifdef SYSTEM_PLATFORM_ANDROID
		// 开启安卓测试模式
		#define FRAMEWORK_ANDROID_TEST
	#endif // SYSTEM_PLATFORM_ANDROID

#endif // !defined(COMPILE_FRAMEWORK_CLOSE) || (COMPILE_FRAMEWORK_CLOSE & CLOSE_USE_ANDROID_TEST) != CLOSE_USE_ANDROID_TEST  

#endif // FRAMEWORK_HELPER_USER_MACRO_H
