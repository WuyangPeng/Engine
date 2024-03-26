/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 15:53)

#ifndef SYSTEM_MEMORY_TOOLS_LOCAL_MEMORY_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_LOCAL_MEMORY_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class LocalMemory
    {
        /// 分配固定内存，返回值是指向内存对象的指针。
        Fixed = LMEM_FIXED,

        /// 分配可移动内存，返回值是内存对象的句柄，要将句柄转换为指针，请使用LocalLock函数，此值不能与Fixed组合使用。
        MoveAble = LMEM_MOVEABLE,

        /// 将存储器内容初始化为零。
        ZeroInit = LMEM_ZEROINIT,

        /// 组合MoveAble和ZeroInit。
        LHnd = LHND,

        /// 组合Fixed和ZeroInit。
        LPtr = LPTR,

        /// 同MoveAble
        NonZeroLHnd = NONZEROLHND,

        /// 同Fixed
        NonZeroLPtr = NONZEROLPTR,

        /// ReAlloc选项，如果指定了Modify，则函数仅修改内存对象的属性（忽略bytes参数）。
        Modify = LMEM_MODIFY,

        InvalidHandle = LMEM_INVALID_HANDLE,
        LockCount = LMEM_LOCKCOUNT,
        DiscardAble = LMEM_DISCARDABLE,

        NoCompact = LMEM_NOCOMPACT,
        NoDiscard = LMEM_NODISCARD,
        ValidFlags = LMEM_VALID_FLAGS,
        Discarded = LMEM_DISCARDED,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class LocalMemory
    {
        Fixed = 0x0000,
        MoveAble = 0x0002,
        ZeroInit = 0x0040,
        LHnd = MoveAble | ZeroInit,
        LPtr = Fixed | ZeroInit,
        NonZeroLHnd = MoveAble,
        NonZeroLPtr = Fixed,
        Modify = 0x0080,

        InvalidHandle = 0x8000,
        LockCount = 0x00FF,
        DiscardAble = 0x0F00,

        NoCompact = 0x0010,
        NoDiscard = 0x0020,
        ValidFlags = 0x0F72,
        Discarded = 0x4000,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_LOCAL_MEMORY_FLAGS_H
