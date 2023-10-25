///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:32)

#ifndef CORE_TOOLS_MEMORY_TOOLS_CONTAINER_ADAPTER_H
#define CORE_TOOLS_MEMORY_TOOLS_CONTAINER_ADAPTER_H

#include "CoreTools/CoreToolsDll.h"

#include "RawIterators.h"

/// ContainerAdapter类是一种用于一维数据的适配器机制。
/// 它提供了std::array和std::vector中最常见的成员函数，包括使用基于范围的迭代。
/// 它还提供构造函数来包装来自另一个包的原始指针。

namespace CoreTools
{
    /// 容器的主要模板具有std::vector的大部分接口，但源数据是一个原始指针。
    /// 这支持的函数可以接受std::array<T,N>类型的参数，或者对于N＞0（编译时已知大小），接受ContainerAdapter<T,N>类型的自变量。
    /// 它支持可以接受std::vector<T>类型或ContainerAdapter<T>（大小仅在运行时已知）类型的参数的函数。
    template <typename T, int...>
    class ContainerAdapter;

    template <typename T, int N>
    requires(N > 0)
    class ContainerAdapter<T, N>
    {
    public:
        using ClassType = ContainerAdapter<T, N>;

        using value_type = T;
        using size_type = int;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;
        using iterator = RawIterator<T>;
        using const_iterator = RawConstIterator<T>;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    public:
        /// 输入是指向连续元素数组的非空指针。调用方必须确保元素数至少为N。
        /// 最后一个默认参数numElements允许在适配器操作中实现泛型，构造函数将忽略它。
        explicit ContainerAdapter(T* elements, int numElements = N);

        /// 由于类对输入的原始数据一无所知，因此不会析构任何内容。
        /// 如果数据是在应用程序的其他地方动态分配的，则调用方负责解除分配。
        /// 调用方负责保证ContainerAdapter使用时内存的有效性。
        ~ContainerAdapter() noexcept = default;

        /// 复制构造函数被禁用，以避免在对象之间共享原始指针，这是适配器系统的简化设计。
        ContainerAdapter(const ContainerAdapter& rhs) = delete;
        ContainerAdapter& operator=(const ContainerAdapter& rhs) = delete;

        ContainerAdapter(ContainerAdapter&& rhs) noexcept;
        ContainerAdapter& operator=(ContainerAdapter&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static int constexpr size() noexcept
        {
            return N;
        }

        NODISCARD T* GetData() noexcept;
        NODISCARD const T* GetData() const noexcept;

        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        NODISCARD iterator begin() noexcept;
        NODISCARD const_iterator begin() const noexcept;

        NODISCARD iterator end() noexcept;
        NODISCARD const_iterator end() const noexcept;

        NODISCARD reverse_iterator rbegin() noexcept;
        NODISCARD const_reverse_iterator rbegin() const noexcept;

        NODISCARD reverse_iterator rend() noexcept;
        NODISCARD const_reverse_iterator rend() const noexcept;

        NODISCARD const_iterator cbegin() const noexcept;
        NODISCARD const_iterator cend() const noexcept;

        NODISCARD const_reverse_iterator crbegin() const noexcept;
        NODISCARD const_reverse_iterator crend() const noexcept;

        /// 将所有元素设置为指定值。
        void Fill(const T& value);

    private:
        T* elements;
    };

    template <typename T>
    class ContainerAdapter<T>
    {
    public:
        using ClassType = ContainerAdapter<T>;

        using value_type = T;
        using size_type = int;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;
        using iterator = RawIterator<T>;
        using const_iterator = RawConstIterator<T>;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    public:
        /// 输入是指向连续元素数组的非空指针。调用方必须确保元素数至少为numElements。
        explicit ContainerAdapter(T* elements, int numElements = 0);

        /// 由于类对输入的原始数据一无所知，因此不会析构任何内容。
        /// 如果数据是在应用程序的其他地方动态分配的，则调用方负责解除分配。
        /// 调用方负责保证ContainerAdapter使用时内存的有效性。
        ~ContainerAdapter() noexcept = default;

        /// 复制构造函数被禁用，以避免在对象之间共享原始指针，这是适配器系统的简化设计。
        ContainerAdapter(const ContainerAdapter& rhs) = delete;
        ContainerAdapter& operator=(const ContainerAdapter& rhs) = delete;

        ContainerAdapter(ContainerAdapter&& rhs) noexcept = delete;
        ContainerAdapter& operator=(ContainerAdapter&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int size() const noexcept;

        NODISCARD T* GetData() noexcept;
        NODISCARD const T* GetData() const noexcept;

        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        NODISCARD iterator begin() noexcept;
        NODISCARD const_iterator begin() const noexcept;

        NODISCARD iterator end() noexcept;
        NODISCARD const_iterator end() const noexcept;

        NODISCARD reverse_iterator rbegin() noexcept;
        NODISCARD const_reverse_iterator rbegin() const noexcept;

        NODISCARD reverse_iterator rend() noexcept;
        NODISCARD const_reverse_iterator rend() const noexcept;

        NODISCARD const_iterator cbegin() const noexcept;
        NODISCARD const_iterator cend() const noexcept;

        NODISCARD const_reverse_iterator crbegin() const noexcept;
        NODISCARD const_reverse_iterator crend() const noexcept;

        /// 将所有元素设置为指定值。
        void Fill(const T& value);

    private:
        int numElements;
        T* elements;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H