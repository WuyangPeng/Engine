///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 10:49)

#ifndef CORE_TOOLS_MEMORY_TOOLS_CONTAINER_ADAPTER_H
#define CORE_TOOLS_MEMORY_TOOLS_CONTAINER_ADAPTER_H

#include "CoreTools/CoreToolsDll.h"

#include "RawIterators.h"

namespace CoreTools
{
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
        explicit ContainerAdapter(T* elements, int numElements = 0);

        ~ContainerAdapter() noexcept = default;

        ContainerAdapter(const ContainerAdapter& rhs) = delete;
        ContainerAdapter& operator=(const ContainerAdapter& rhs) = delete;

        ContainerAdapter(ContainerAdapter&& rhs) noexcept = delete;
        ContainerAdapter& operator=(ContainerAdapter&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Reset(T* aElements, int numElements = 0);

        NODISCARD static int constexpr GetSize() noexcept
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
        explicit ContainerAdapter(T* elements, int numElements = 0);

        ~ContainerAdapter() noexcept = default;

        ContainerAdapter(const ContainerAdapter& rhs) = delete;
        ContainerAdapter& operator=(const ContainerAdapter& rhs) = delete;
        ContainerAdapter(ContainerAdapter&& rhs) noexcept = delete;
        ContainerAdapter& operator=(ContainerAdapter&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Reset(T* aElements, int aNumElements);

        NODISCARD int GetSize() const noexcept;

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

    private:
        int numElements;
        T* elements;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H
