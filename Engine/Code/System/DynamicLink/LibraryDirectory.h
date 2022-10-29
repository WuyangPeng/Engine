///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/08 21:48)

#ifndef SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H
#define SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H

#include "System/SystemDll.h"

#include "Using/LoadLibraryUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 设置动态链接库的载入目录。

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetLibraryDirectory(const DynamicLinkCharType* pathName) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetLibraryDirectory(WindowsDWord bufferLength, DynamicLinkCharType* buffer) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H
