/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/22 14:00)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY4_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY4_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

/// Array4类表示一个4维数组，
/// 该数组最大限度地减少了调用new和delete的数量。
/// T对象存储在一个连续的数组中。
namespace CoreTools
{
    template <typename T>
    class Array4 final
    {
    public:
        using ClassType = Array4<T>;

    public:
        /// 支持动态调整大小、复制或移动。
        Array4() noexcept;

        /// 该数组具有bound0列、bound1行、bound2切片和bound3长方体。
        Array4(int bound0, int bound1, int bound2, int bound3);
        ~Array4() noexcept = default;
        Array4(const Array4& rhs);
        Array4& operator=(const Array4& rhs);
        Array4(Array4&& rhs) noexcept;
        Array4& operator=(Array4&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 访问阵列。示例用法为
        //   Array4<T> myArray{ 5, 4, 3, 2 };
        //   T*** cuboid1 = myArray[1];
        //   T** cuboid1Slice2 = myArray[1][2];
        //   T* cuboid1Slice2Row3 = myArray[1][2][3];
        //   T cuboid1Slice2Row3Col4 = myArray[1][2][3][4];
        NODISCARD int GetBound0() const noexcept;
        NODISCARD int GetBound1() const noexcept;
        NODISCARD int GetBound2() const noexcept;
        NODISCARD int GetBound3() const noexcept;

        NODISCARD T** const* operator[](int cuboid) const;
        NODISCARD T*** operator[](int cuboid);

        NODISCARD T* const* operator()(int cuboid, int slice) const;
        NODISCARD T** operator()(int cuboid, int slice);

        NODISCARD const T* operator()(int cuboid, int slice, int row) const;
        NODISCARD T* operator()(int cuboid, int slice, int row);

        NODISCARD const T& operator()(int cuboid, int slice, int row, int column) const;
        NODISCARD T& operator()(int cuboid, int slice, int row, int column);

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

        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1, int bound2, int bound3) noexcept
        {
            return bound0 * bound1 * bound2 * bound3;
        }

    private:
        int bound0;
        int bound1;
        int bound2;
        int bound3;
        std::vector<T> objects;
        std::vector<T*> indirect1;
        std::vector<T**> indirect2;
        std::vector<T***> indirect3;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY4_H
