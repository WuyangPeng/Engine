//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 1:00)

#ifndef SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_H
#define SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // 文件映射系统。

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemFileMapping(WindowHandle file, MemoryProtect protect, FileMapProtection otherProtect, WindowDWord maximumSizeHigh,
                                                                              WindowDWord maximumSizeLow, const wchar_t* name, bool* isExists) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseFileMapping(WindowHandle fileMappingHandle) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE OpenSystemFileMapping(FileMapDesiredAccess desiredAccess, bool inheritHandle, const wchar_t* name) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemFileMappingNuma(WindowHandle file, WindowSecurityAttributesPtr fileMappingAttributes, MemoryProtect protect,
                                                                                  FileMapProtection otherProtect, WindowDWord maximumSizeHigh, WindowDWord maximumSizeLow,
                                                                                  const wchar_t* name, WindowDWord preferred) noexcept;

    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE MapSystemViewOfFile(WindowHandle fileMappingObject, FileMapDesiredAccess desiredAccess, WindowDWord maximumSizeHigh,
                                                                           WindowDWord maximumSizeLow, WindowSize numberOfBytesToMap) noexcept;
    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE MapSystemViewOfFile(WindowHandle fileMappingObject, FileMapDesiredAccess desiredAccess, WindowDWord maximumSizeHigh,
                                                                           WindowDWord maximumSizeLow, WindowSize numberOfBytesToMap, WindowVoidPtr baseAddress) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FlushSystemViewOfFile(WindowVoidPtr baseAddress, WindowSize numberOfBytesToFlush) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE UnmapSystemViewOfFile(WindowVoidPtr baseAddress) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_H