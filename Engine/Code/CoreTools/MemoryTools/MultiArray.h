///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 15:44)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_H

#include "CoreTools/CoreToolsDll.h"

#include <array>

namespace CoreTools
{
    template <typename T, bool OrderLToR, size_t... Sizes>
    class MultiArray : public Lattice<OrderLToR, Sizes...>
    {
    public:
        using ClassType = MultiArray<T, OrderLToR, Sizes...>;
        using ParentType = Lattice<OrderLToR, Sizes...>;

    public:
        MultiArray() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* data() noexcept;

        NODISCARD const T& operator[](size_t index) const;
        NODISCARD T& operator[](size_t index);

        void Fill(const T& value);

        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple);

        NODISCARD const T& operator()(const std::array<size_t, sizeof...(Sizes)>& coordinate) const;
        NODISCARD T& operator()(const std::array<size_t, sizeof...(Sizes)>& coordinate);

        NODISCARD std::strong_ordering operator<=>(const MultiArray& rhs) const;

    private:
        std::array<T, Lattice<OrderLToR, Sizes...>::NumElements> container;
    };

    template <typename T, bool OrderLToR>
    class MultiArray<T, OrderLToR> : public Lattice<OrderLToR>
    {
    public:
        using ClassType = MultiArray<T, OrderLToR>;
        using ParentType = Lattice<OrderLToR>;
        using SizeType = std::vector<size_t>;

    public:
        MultiArray() noexcept;

        CLASS_INVARIANT_DECLARE;

        MultiArray(const SizeType& sizes);
        MultiArray(const std::initializer_list<size_t>& sizes);

        void Reset(const SizeType& sizes);
        void Reset(const std::initializer_list<size_t>& sizes);

        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        NODISCARD const T& operator[](size_t index) const;
        NODISCARD T& operator[](size_t index);

        void Fill(const T& value);

        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const;
        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple);

        NODISCARD const T& operator()(const SizeType& coordinate) const;
        NODISCARD T& operator()(const SizeType& coordinate);

        NODISCARD std::strong_ordering operator<=>(const MultiArray& rhs) const;

    private:
        std::vector<T> container;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_H
