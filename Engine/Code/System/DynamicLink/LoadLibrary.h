///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 16:35)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/LoadLibraryUsing.h"

// ���غ��ͷŶ�̬���ӿ⡣
namespace System
{
    NODISCARD DynamicLinkModule SYSTEM_DEFAULT_DECLARE LoadDynamicLibrary(const DynamicLinkCharType* fileName, LoadLibraryType flag) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FreeDynamicLibrary(DynamicLinkModule module) noexcept;
    NODISCARD DynamicLinkProcess SYSTEM_DEFAULT_DECLARE GetProcessAddress(DynamicLinkModule module, const char* processName) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DisableThreadDynamicLibraryCalls(DynamicLinkModule module) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H
