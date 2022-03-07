///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/28 20:50)

#ifndef CORE_TOOLS_MEMORY_TOOLS_FWD_H
#define CORE_TOOLS_MEMORY_TOOLS_FWD_H

namespace CoreTools
{
    template <typename T>
    class HeapAllocate;

    template <typename T>
    class Array2;

    template <typename T>
    class Array3;

    template <typename T>
    class Array4;

    template <typename T>
    struct SharedPtrEqual;

    template <typename T>
    struct SharedPtrUnequal;

    template <typename T>
    struct SharedPtrLess;

    template <typename T>
    struct SharedPtrLessEqual;

    template <typename T>
    struct SharedPtrGreater;

    template <typename T>
    struct SharedPtrGreaterEqual;

    template <typename T>
    struct WeakPtrEqual;

    template <typename T>
    struct WeakPtrUnequal;

    template <typename T>
    struct WeakPtrLess;

    template <typename T>
    struct WeakPtrLessEqual;

    template <typename T>
    struct WeakPtrGreater;

    template <typename T>
    struct WeakPtrGreaterEqual;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_FWD_H