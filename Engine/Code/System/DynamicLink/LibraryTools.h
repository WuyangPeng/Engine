///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 16:35)

#ifndef SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/LoadLibraryUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// ʹ�ö�̬���ӿ�ĸ���������
namespace System
{
    // GetDynamicLinkHandle�����Ӿ�������ü�����
    NODISCARD DynamicLinkModule SYSTEM_DEFAULT_DECLARE GetDynamicLinkHandle(const DynamicLinkCharType* moduleName) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetDynamicLinkHandle(GetModuleHandleType flags, const DynamicLinkCharType* moduleName, DynamicLinkModule* module) noexcept;

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetDynamicLinkFileName(DynamicLinkModule module, DynamicLinkCharType* filename, WindowsDWord size) noexcept;
    NODISCARD DynamicLinkString SYSTEM_DEFAULT_DECLARE GetDynamicLinkFileName(DynamicLinkModule module);
}

#endif  // SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H
