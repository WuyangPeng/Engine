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
    template <typename T, size_t...>
    class ContainerAdapter;

    template <typename T, size_t N>
    requires(N > 0)
    class ContainerAdapter<T, N>
    {
    public:
        using ClassType = ContainerAdapter<T, N>;

        using value_type = T;
        using size_type = size_t;
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
        explicit ContainerAdapter(T* elements = nullptr, size_t numElements = 0);

        ~ContainerAdapter() noexcept = default;

        ContainerAdapter(const ContainerAdapter& rhs) = delete;
        ContainerAdapter& operator=(const ContainerAdapter& rhs) = delete;

        ContainerAdapter(ContainerAdapter&& rhs) noexcept = delete;
        ContainerAdapter& operator=(ContainerAdapter&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Reset(T* aElements, size_t numElements = 0) noexcept;

        NODISCARD static size_t constexpr GetSize() noexcept
        {
            return N;
        }

        NODISCARD T* GetData() noexcept;
        NODISCARD const T* GetData() const noexcept;

        NODISCARD const T& operator[](size_t index) const;
        NODISCARD T& operator[](size_t index);

        NODISCARD iterator begin();
        NODISCARD const_iterator begin() const;

        NODISCARD iterator end();
        NODISCARD const_iterator end() const;

        NODISCARD reverse_iterator rbegin();
        NODISCARD const_reverse_iterator rbegin() const;

        NODISCARD reverse_iterator rend();
        NODISCARD const_reverse_iterator rend() const;

        NODISCARD const_iterator cbegin() const;
        NODISCARD const_iterator cend() const;

        NODISCARD const_reverse_iterator crbegin() const;
        NODISCARD const_reverse_iterator crend() const;

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
        using size_type = size_t;
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
        explicit ContainerAdapter(T* elements = nullptr, size_t numElements = 0);

        ~ContainerAdapter() noexcept = default;

        ContainerAdapter(const ContainerAdapter& rhs) = delete;
        ContainerAdapter& operator=(const ContainerAdapter& rhs) = delete;
        ContainerAdapter(ContainerAdapter&& rhs) noexcept = delete;
        ContainerAdapter& operator=(ContainerAdapter&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Reset(T* aElements, size_t aNumElements);

        NODISCARD size_t GetSize() const noexcept;

        NODISCARD T* GetData() noexcept;

        NODISCARD const T* GetData() const noexcept;

        NODISCARD NODISCARD const T& operator[](size_t index) const noexcept;
        NODISCARD T& operator[](size_t index) noexcept;

        NODISCARD iterator begin();
        NODISCARD const_iterator begin() const;

        NODISCARD iterator end();
        NODISCARD const_iterator end() const;

        NODISCARD reverse_iterator rbegin();
        NODISCARD const_reverse_iterator rbegin() const;

        NODISCARD reverse_iterator rend();
        NODISCARD const_reverse_iterator rend() const;

        NODISCARD const_iterator cbegin() const;
        NODISCARD const_iterator cend() const;

        NODISCARD const_reverse_iterator crbegin() const;
        NODISCARD const_reverse_iterator crend() const;

    private:
        size_t numElements;
        T* elements;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H
