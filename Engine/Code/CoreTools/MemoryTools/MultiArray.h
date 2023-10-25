///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:31)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_H

#include "CoreTools/CoreToolsDll.h"

#include "Lattice.h"

#include <array>

/// Lattice类负责对连续的内存块进行多索引。
/// MultiArray类负责提供内存。它继承自Lattice。
namespace CoreTools
{
    // 编译时已知大小的多维数组的实现。
    template <typename T, bool OrderLToR, int... Sizes>
    class MultiArray final : public Lattice<OrderLToR, Sizes...>, private boost::totally_ordered<MultiArray<T, OrderLToR, Sizes...>>
    {
    public:
        using ClassType = MultiArray<T, OrderLToR, Sizes...>;
        using ParentType = Lattice<OrderLToR, Sizes...>;

    public:
        MultiArray() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 获取指向元素数组的指针。
        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        // 访问指定索引处的元素。
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // 将所有元素设置为指定值。
        void Fill(const T& value);

        // 获取与索引的n维参数包相对应的元素。
        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple);

        // 获取与n维坐标对应的元素。
        NODISCARD const T& operator()(const std::array<int, sizeof...(Sizes)>& coordinate) const;
        NODISCARD T& operator()(const std::array<int, sizeof...(Sizes)>& coordinate);

        // 支持对多维数组对象进行排序和比较
        NODISCARD bool operator==(const MultiArray& rhs) const noexcept;
        NODISCARD bool operator<(const MultiArray& rhs) const noexcept;

    private:
        static constexpr auto numElements = Lattice<OrderLToR, Sizes...>::numElements;
        using Container = std::array<T, numElements>;

    private:
        Container container;
    };

    // 仅在运行时才知道其大小的多数组的实现。
    template <typename T, bool OrderLToR>
    class MultiArray<T, OrderLToR> final : public Lattice<OrderLToR>, private boost::totally_ordered<MultiArray<T, OrderLToR>>
    {
    public:
        using ClassType = MultiArray<T, OrderLToR>;
        using ParentType = Lattice<OrderLToR>;

        using SizeType = std::vector<int>;

    public:
        MultiArray() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 多维数组具有指定的大小。
        explicit MultiArray(const SizeType& sizes);
        explicit MultiArray(const std::initializer_list<int>& sizes);

        /// 支持由默认构造函数创建初始多维数组的延迟构造。
        /// 在以后的执行过程中，可以根据需要设置多维数组的大小。
        void Reset(const SizeType& sizes) override;
        void Reset(const std::initializer_list<int>& sizes) override;

        // 获取指向元素数组的指针。
        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        // 访问指定索引处的元素。
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // 将所有元素设置为指定值。
        void Fill(const T& value);

        // 获取与索引的n维参数包相对应的元素。
        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple);

        // 获取与n维坐标对应的元素。
        NODISCARD const T& operator()(const SizeType& coordinate) const;
        NODISCARD T& operator()(const SizeType& coordinate);

        // 支持对多维数组对象进行排序和比较
        NODISCARD bool operator==(const MultiArray& rhs) const noexcept;
        NODISCARD bool operator<(const MultiArray& rhs) const noexcept;

    private:
        using Container = std::vector<T>;

    private:
        Container container;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_H
