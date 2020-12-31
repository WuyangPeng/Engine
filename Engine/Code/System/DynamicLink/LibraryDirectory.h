//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 10:03)

#ifndef SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H
#define SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H

#include "System/SystemDll.h"

#include "Using/LoadLibraryUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 设置动态链接库的载入目录。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetLibraryDirectory(const DynamicLinkCharType* pathName) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetLibraryDirectory(WindowDWord bufferLength, DynamicLinkCharType* buffer) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H
