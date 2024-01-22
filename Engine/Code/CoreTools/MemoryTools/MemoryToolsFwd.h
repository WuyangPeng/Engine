/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 09:44)

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

    template <bool RowMajor, typename Real, int... Dimensions>
    class LexicoArray2;

    template <typename T, int...>
    class ContainerAdapter;

    template <typename T>
    class RawConstIterator;

    template <typename T>
    class RawIterator;

    template <bool OrderLToR, int... Sizes>
    requires(sizeof...(Sizes) >= 1)
    class Lattice;

    template <typename T, bool OrderLToR, size_t... Sizes>
    class MultiArray;

    template <typename T, bool OrderLToR, size_t... Sizes>
    class MultiArrayAdapter;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_FWD_H