// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 14:45)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_FWD_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_FWD_H

#include "DynamicLinkFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"

namespace System
{
	DynamicLinkModule LoadDynamicLibrary(const DynamicLinkCharType* fileName, LoadLibrary flag) noexcept;
	bool FreeDynamicLibrary(DynamicLinkModule module) noexcept;
	DynamicLinkProcess GetProcessAddress(DynamicLinkModule module, const char* processName) noexcept;
	bool DisableThreadDynamicLibraryCalls(DynamicLinkModule module) noexcept;
}

#endif // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_FWD_H