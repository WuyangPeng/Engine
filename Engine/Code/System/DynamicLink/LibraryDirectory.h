/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:16)

#ifndef SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H
#define SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H

#include "System/SystemDll.h"

#include "Using/LoadLibraryUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// 设置动态链接库的载入目录。
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetLibraryDirectory(const DynamicLinkCharType* pathName) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetLibraryDirectory(WindowsDWord bufferLength, DynamicLinkCharType* buffer) noexcept;
    NODISCARD String SYSTEM_DEFAULT_DECLARE GetLibraryDirectory();
}

#endif  // SYSTEM_DYNAMIC_LINK_LIBRARY_DIRECTORY_H
