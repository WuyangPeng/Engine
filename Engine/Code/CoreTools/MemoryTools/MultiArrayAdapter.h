///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:30)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_H
#define CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_H

#include "CoreTools/CoreToolsDll.h"

#include "Lattice.h"

/// 类MultiArrayAdapter实际上与MultiArray具有相同的接口，只是存储的原始指针是由外部源提供的。
/// 因为原始指针是外部的，并且类共享原始指针，所以复制和移动语义被禁用。
namespace CoreTools
{
    /// 编译时已知大小的多维数组适配器的实现。
    template <typename T, bool OrderLToR, int... Sizes>
    class MultiArrayAdapter final : public Lattice<OrderLToR, Sizes...>, private boost::totally_ordered<MultiArrayAdapter<T, OrderLToR, Sizes...>>
    {
    public:
        using ClassType = MultiArrayAdapter<T, OrderLToR, Sizes...>;
        using ParentType = Lattice<OrderLToR, Sizes...>;

    public:
        explicit MultiArrayAdapter(T* container);

        ~MultiArrayAdapter() noexcept = default;

        MultiArrayAdapter(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter& operator=(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter(MultiArrayAdapter&& rhs) noexcept = delete;
        MultiArrayAdapter& operator=(MultiArrayAdapter&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Reset(T* aContainer);

        // 获取指向元素数组的指针。
        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        // 访问指定索引处的元素。
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // 将所有元素设置为指定值。
        void Fill(const T& value) noexcept;

        // 获取与索引的n维参数包相对应的元素。
        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple) noexcept;

        // 获取与n维坐标对应的元素。
        NODISCARD const T& operator()(const std::array<int, sizeof...(Sizes)>& coordinate) const;
        NODISCARD T& operator()(const std::array<int, sizeof...(Sizes)>& coordinate);

        // 支持对MultiArrayAdapter对象进行排序和比较。
        NODISCARD bool operator==(const MultiArrayAdapter& rhs) const noexcept;
        NODISCARD bool operator<(const MultiArrayAdapter& rhs) const noexcept;

    private:
        // 指针必须指向存储Lattice<OrderLToR, Sizes...>::GetSize()个内存块的T对象。
        T* container;
    };

    // 仅在运行时才知道其大小的多维数组的实现。
    template <typename T, bool OrderLToR>
    class MultiArrayAdapter<T, OrderLToR> final : public Lattice<OrderLToR>
    {
    public:
        using ClassType = MultiArrayAdapter<T, OrderLToR>;
        using ParentType = Lattice<OrderLToR>;

        using SizeType = std::vector<int>;

    public:
        MultiArrayAdapter(const SizeType& sizes, T* container);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Reset(const SizeType& sizes, T* aContainer);

        ~MultiArrayAdapter() noexcept = default;

        MultiArrayAdapter(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter& operator=(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter(MultiArrayAdapter&& rhs) noexcept = delete;
        MultiArrayAdapter& operator=(MultiArrayAdapter&& rhs) noexcept = delete;

        // 获取指向元素数组的指针。
        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        // 访问指定索引处的元素。
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // 将所有元素设置为指定值。
        void Fill(const T& value) noexcept;

        // 获取与索引的n维参数包相对应的元素。
        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple);

        // 获取与n维坐标对应的元素。
        NODISCARD const T& operator()(const SizeType& coordinate) const;
        NODISCARD T& operator()(const SizeType& coordinate);

        // 支持对MultiArrayAdapter对象进行排序和比较。
        NODISCARD bool operator==(const MultiArrayAdapter& rhs) const noexcept;
        NODISCARD bool operator<(const MultiArrayAdapter& rhs) const noexcept;

    private:
        // 指针必须指向存储Lattice<OrderLToR>::GetSize()个内存块的T对象。
        T* container;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_H
