///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 17:00)

#ifndef SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_H
#define SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// �ļ�ӳ��ϵͳ��
namespace System
{
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemFileMapping(WindowsHandle file,
                                                                               MemoryProtect protect,
                                                                               FileMapProtection otherProtect,
                                                                               WindowsDWord maximumSizeHigh,
                                                                               WindowsDWord maximumSizeLow,
                                                                               const TChar* name,
                                                                               bool* isExists) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseFileMapping(WindowsHandle fileMappingHandle) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE OpenSystemFileMapping(FileMapDesiredAccess desiredAccess, bool inheritHandle, const TChar* name) noexcept;

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
    NODISCARD bool SYSTEM_DEFAULT_DECLARE UnMapSystemViewOfFile(WindowsVoidPtr baseAddress) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_H