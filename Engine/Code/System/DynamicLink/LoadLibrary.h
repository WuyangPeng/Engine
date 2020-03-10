// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 14:47)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H

#include "System/SystemDll.h"

#include "Using/LoadLibraryUsing.h"
#include "Fwd/DynamicLinkFlagsFwd.h"

namespace System
{
	// ���غ��ͷŶ�̬���ӿ⡣

	DynamicLinkModule SYSTEM_DEFAULT_DECLARE LoadDynamicLibrary(const DynamicLinkCharType* fileName, LoadLibrary flag) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FreeDynamicLibrary(DynamicLinkModule module) noexcept;
	DynamicLinkProcess SYSTEM_DEFAULT_DECLARE GetProcessAddress(DynamicLinkModule module, const char* processName) noexcept;
	bool SYSTEM_DEFAULT_DECLARE DisableThreadDynamicLibraryCalls(DynamicLinkModule module) noexcept;
}

#endif // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H
