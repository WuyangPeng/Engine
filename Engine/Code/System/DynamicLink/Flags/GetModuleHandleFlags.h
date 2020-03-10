// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 14:43)

#ifndef SYSTEM_DYNAMIC_LINK_GET_MODULE_HANDLE_FLAGS_H
#define SYSTEM_DYNAMIC_LINK_GET_MODULE_HANDLE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32  

	enum class GetModuleHandle
	{
		Default = 0, // 则当调用该函数时，模块的引用计数自动增加
		Pin = GET_MODULE_HANDLE_EX_FLAG_PIN, // 模块一直映射在调用该函数的进程中，直到该进程结束
		UnchangedRefcount = GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, // 同GetModuleHandle相同，不增加引用计数
		FromAddress = GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, // moduleName是模块中的一个地址
	};

#else // !SYSTEM_PLATFORM_WIN32  

	enum class GetModuleHandle
	{
		Default = 0,
		Pin = 0x00000001,
		UnchangedRefcount = 0x00000002,
		FromAddress = 0x00000004,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_DYNAMIC_LINK_GET_MODULE_HANDLE_FLAGS_H
