///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/19 11:41)

#ifndef SYSTEM_MEMORY_TOOLS_LOCAL_MEMORY_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_LOCAL_MEMORY_FLAGS_H

#include "System/Helper/EnumMacro.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class LocalMemory
    {
        // 分配固定内存。返回值是指向内存对象的指针。
        Fixed = LMEM_FIXED,

        // 分配可移动内存。返回值是内存对象的句柄。要将句柄转换为指针，请使用LocalLock函数。此值不能与Fixed组合使用。
        Moveable = LMEM_MOVEABLE,

        // 将存储器内容初始化为零。
        ZeroInit = LMEM_ZEROINIT,

        // 组合Moveable和ZeroInit。
        LHnd = LHND,

        // 组合Fixed和ZeroInit。
        LPtr = LPTR,

        // 同Moveable
        NonZeroLHnd = NONZEROLHND,

        // 同Fixed
        NonZeroLPtr = NONZEROLPTR,

        // ReAlloc选项。如果指定了Modify，则函数仅修改内存对象的属性（忽略bytes参数）。
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
        NoCompact = 0x0010,
        NoDiscard = 0x0020,
        ZeroInit = 0x0040,
        Modify = 0x0080,
        Discardable = 0x0F00,
        ValidFlags = 0x0F72,
        InvalidHandle = 0x8000,
        LHnd = Moveable | ZeroInit,
        LPtr = Fixed | ZeroInit,
        NonZeroLHnd = Moveable,
        NonZeroLPtr = Fixed,
        Discarded = 0x4000,
        LockCount = 0x00FF,
    };

#endif  // SYSTEM_PLATFORM_WIN32

    // 定义operator &和|运算符。
    ENUM_ANDABLE_OPERATOR_DEFINE(LocalMemory);
    ENUM_ORABLE_OPERATOR_DEFINE(LocalMemory);
}

#endif  // SYSTEM_MEMORY_TOOLS_LOCAL_MEMORY_FLAGS_H
