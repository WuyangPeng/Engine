/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 17:30)

#ifndef SYSTEM_MEMORY_TOOLS_LOCAL_MEMORY_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_LOCAL_MEMORY_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class LocalMemory
    {
        // ����̶��ڴ棬����ֵ��ָ���ڴ�����ָ�롣
        Fixed = LMEM_FIXED,

        // ������ƶ��ڴ棬����ֵ���ڴ����ľ����Ҫ�����ת��Ϊָ�룬��ʹ��LocalLock��������ֵ������Fixed���ʹ�á�
        Moveable = LMEM_MOVEABLE,

        // ���洢�����ݳ�ʼ��Ϊ�㡣
        ZeroInit = LMEM_ZEROINIT,

        // ���Moveable��ZeroInit��
        LHnd = LHND,

        // ���Fixed��ZeroInit��
        LPtr = LPTR,

        // ͬMoveable
        NonZeroLHnd = NONZEROLHND,

        // ͬFixed
        NonZeroLPtr = NONZEROLPTR,

        // ReAllocѡ����ָ����Modify���������޸��ڴ��������ԣ�����bytes��������
        Modify = LMEM_MODIFY,

        InvalidHandle = LMEM_INVALID_HANDLE,
        LockCount = LMEM_LOCKCOUNT,
        Discardable = LMEM_DISCARDABLE,

        NoCompact = LMEM_NOCOMPACT,
        NoDiscard = LMEM_NODISCARD,
        ValidFlags = LMEM_VALID_FLAGS,
        Discarded = LMEM_DISCARDED,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class LocalMemory
    {
        Fixed = 0x0000,
        Moveable = 0x0002,
        ZeroInit = 0x0040,
        LHnd = Moveable | ZeroInit,
        LPtr = Fixed | ZeroInit,
        NonZeroLHnd = Moveable,
        NonZeroLPtr = Fixed,
        Modify = 0x0080,

        InvalidHandle = 0x8000,
        LockCount = 0x00FF,
        Discardable = 0x0F00,

        NoCompact = 0x0010,
        NoDiscard = 0x0020,
        ValidFlags = 0x0F72,
        Discarded = 0x4000,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_LOCAL_MEMORY_FLAGS_H
