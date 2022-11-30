///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/16 21:33)

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

    using EnumResourceLanguageProcess = WindowsBool (*)(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language, WindowsLongPtrSizeType param);
    using EnumResourceNameProcess = WindowsBool (*)(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowsLongPtrSizeType param);
    using EnumResourceTypeProcess = WindowsBool (*)(DynamicLinkModule module, DynamicLinkCharType* type, WindowsLongPtrSizeType param);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_USING_H
