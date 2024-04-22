/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 15:43)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

/// Array2类表示一个2维数组，
/// 该数组最大限度地减少了调用new和delete的数量。
/// T对象存储在一个连续的数组中。
namespace CoreTools
{
    template <typename T>
    class Array2 final
    {
    public:
        using ClassType = Array2<T>;

    public:
        /// 支持动态调整大小、复制或移动。
        Array2() noexcept;

        /// 该数组具有bound0列和bound1行。
        Array2(int bound0, int bound1);
        ~Array2() noexcept = default;
        Array2(const Array2& rhs);
        Array2& operator=(const Array2& rhs);
        Array2(Array2&& rhs) noexcept;
        Array2& operator=(Array2&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 访问数组。示例用法为
        ///   Array2<T> myArray{ 3, 2 };
        ///   数组objects为
        ///   00 01 02
        ///   10 11 12
        ///   数组indirect指向 00 10。
        ///   T* row1 = myArray[1];
        ///   T row1Column2 = myArray[1][2];
        NODISCARD int GetBound0() const noexcept;
        NODISCARD int GetBound1() const noexcept;

        NODISCARD const T* operator[](int row) const;
        NODISCARD T* operator[](int row);

        NODISCARD const T& operator()(int row, int column) const;
        NODISCARD T& operator()(int row, int column);

    private:
        void SetPointers();

        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1) noexcept
        {
            return bound0 * bound1;
        }

    private:
        int bound0;
        int bound1;
        std::vector<T> objects;
        std::vector<T*> indirect;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H
