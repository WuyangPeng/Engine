/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 15:44)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY3_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY3_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

/// Array3类表示一个3维数组，
/// 该数组最大限度地减少了调用new和delete的数量。
/// T对象存储在一个连续的数组中。
namespace CoreTools
{
    template <typename T>
    class Array3 final
    {
    public:
        using ClassType = Array3<T>;

    public:
        /// 支持动态调整大小、复制或移动。
        Array3() noexcept;

        /// 该数组具有bound0列、bound1行和bound2切片。
        Array3(int bound0, int bound1, int bound2);
        ~Array3() noexcept = default;
        Array3(const Array3& rhs);
        Array3& operator=(const Array3& rhs);
        Array3(Array3&& rhs) noexcept;
        Array3& operator=(Array3&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 访问阵列。示例用法为
        /// Array3<T> myArray{ 4, 3, 2 };
        ///  数组objects为
        ///   000 001 002 003
        ///   010 011 012 013
        ///   020 021 022 023
        ///
        ///   100 101 102 103
        ///   110 111 112 113
        ///   120 121 122 123
        ///   数组indirect1指向 000 010 020 100 110 120。
        ///   数组indirect2指向 000 100。
        ///   T** slice1 = myArray[1];
        ///   T* slice1row2 = myArray[1][2];
        ///   T slice1Row2Column3 = myArray[1][2][3];
        NODISCARD int GetBound0() const noexcept;
        NODISCARD int GetBound1() const noexcept;
        NODISCARD int GetBound2() const noexcept;

        NODISCARD T* const* operator[](int slice) const;
        NODISCARD T** operator[](int slice);

        NODISCARD const T* operator()(int slice, int row) const;
        NODISCARD T* operator()(int slice, int row);

        NODISCARD const T& operator()(int slice, int row, int column) const;
        NODISCARD T& operator()(int slice, int row, int column);

    private:
        void SetPointers();

        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1) noexcept
        {
            return bound0 * bound1;
        }

        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1, int bound2) noexcept
        {
            return bound0 * bound1 * bound2;
        }

    private:
        int bound0;
        int bound1;
        int bound2;
        std::vector<T> objects;
        std::vector<T*> indirect1;
        std::vector<T**> indirect2;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY3_H
