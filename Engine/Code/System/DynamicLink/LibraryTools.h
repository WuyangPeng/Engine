///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:57)

#ifndef SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/LoadLibraryUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // ʹ�ö�̬���ӿ�ĸ���������

    // GetDynamicLinkHandle�����Ӿ�������ü�����
    NODISCARD DynamicLinkModule SYSTEM_DEFAULT_DECLARE GetDynamicLinkHandle(const DynamicLinkCharType* moduleName) noexcept;

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetDynamicLinkFileName(DynamicLinkModule module, DynamicLinkCharType* filename, WindowsDWord size) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetDynamicLinkHandle(GetModuleHandleType flags, const DynamicLinkCharType* moduleName, DynamicLinkModule* module) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H
