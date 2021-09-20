///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/24 11:32)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_USING_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using EnumResourceLanguageProcess = ENUMRESLANGPROC;
    using EnumResourceNameProcess = ENUMRESNAMEPROC;
    using EnumResourceTypeProcess = ENUMRESTYPEPROC;

#else  // !SYSTEM_PLATFORM_WIN32

    using EnumResourceLanguageProcess = WindowsBool (*)(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language, WindowsPtrLong param);
    using EnumResourceNameProcess = WindowsBool (*)(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowsPtrLong param);
    using EnumResourceTypeProcess = WindowsBool (*)(DynamicLinkModule module, DynamicLinkCharType* type, WindowsPtrLong param);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_USING_H
