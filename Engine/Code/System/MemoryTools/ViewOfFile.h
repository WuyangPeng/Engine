///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 15:02)

#ifndef SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_H
#define SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // �ļ�ӳ��ϵͳ��

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemFileMapping(WindowsHandle file,
                                                                               MemoryProtect protect,
                                                                               FileMapProtection otherProtect,
                                                                               WindowsDWord maximumSizeHigh,
                                                                               WindowsDWord maximumSizeLow,
                                                                               const wchar_t* name,
                                                                               bool* isExists) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseFileMapping(WindowsHandle fileMappingHandle) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE OpenSystemFileMapping(FileMapDesiredAccess desiredAccess, bool inheritHandle, const wchar_t* name) noexcept;

    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_DEFAULT_DECLARE MapSystemViewOfFile(WindowsHandle fileMappingObject,
                                                                            FileMapDesiredAccess desiredAccess,
                                                                            WindowsDWord maximumSizeHigh,
                                                                            WindowsDWord maximumSizeLow,
                                                                            WindowsSize numberOfBytesToMap) noexcept;
    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_DEFAULT_DECLARE MapSystemViewOfFile(WindowsHandle fileMappingObject,
                                                                            FileMapDesiredAccess desiredAccess,
                                                                            WindowsDWord maximumSizeHigh,
                                                                            WindowsDWord maximumSizeLow,
                                                                            WindowsSize numberOfBytesToMap,
                                                                            WindowsVoidPtr baseAddress) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE FlushSystemViewOfFile(WindowsVoidPtr baseAddress, WindowsSize numberOfBytesToFlush) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE UnmapSystemViewOfFile(WindowsVoidPtr baseAddress) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_H