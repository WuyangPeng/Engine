///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/24 15:02)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/LoadLibraryUsing.h"

namespace System
{
    // ���غ��ͷŶ�̬���ӿ⡣

    NODISCARD DynamicLinkModule SYSTEM_DEFAULT_DECLARE LoadDynamicLibrary(const DynamicLinkCharType* fileName, LoadLibraryType flag) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FreeDynamicLibrary(DynamicLinkModule module) noexcept;
    NODISCARD DynamicLinkProcess SYSTEM_DEFAULT_DECLARE GetProcessAddress(DynamicLinkModule module, const char* processName) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DisableThreadDynamicLibraryCalls(DynamicLinkModule module) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H
