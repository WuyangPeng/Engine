///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 16:14)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_H
#define CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T, bool OrderLToR, size_t... Sizes>
    class MultiArrayAdapter : public Lattice<OrderLToR, Sizes...>
    {
    public:
        using ClassType = MultiArrayAdapter<T, OrderLToR, Sizes...>;
        using ParentType = Lattice<OrderLToR, Sizes...>;

    public:
        explicit MultiArrayAdapter(T* container = nullptr);

        ~MultiArrayAdapter() noexcept = default;

        MultiArrayAdapter(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter& operator=(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter(MultiArrayAdapter&& rhs) noexcept = delete;
        MultiArrayAdapter& operator=(MultiArrayAdapter&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Reset(T* aContainer);

        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        NODISCARD const T& operator[](size_t index) const;
        NODISCARD T& operator[](size_t index);

        void Fill(const T& value);

        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple);

        NODISCARD const T& operator()(const std::array<size_t, sizeof...(Sizes)>& coordinate) const;
        NODISCARD T& operator()(const std::array<size_t, sizeof...(Sizes)>& coordinate);

        NODISCARD std::strong_ordering operator<=>(const MultiArrayAdapter& rhs) const;

    private:
        T* container;
    };

    template <typename T, bool OrderLToR>
    class MultiArrayAdapter<T, OrderLToR> : public Lattice<OrderLToR>
    {
    public:
        using ClassType = MultiArrayAdapter<T, OrderLToR>;
        using ParentType = Lattice<OrderLToR>;
        using SizeType = std::vector<size_t>;

    public:
        MultiArrayAdapter() noexcept;
        MultiArrayAdapter(const SizeType& sizes, T* container);

        CLASS_INVARIANT_DECLARE;

        void Reset(const SizeType& sizes, T* aContainer);

        ~MultiArrayAdapter() noexcept = default;

        MultiArrayAdapter(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter& operator=(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter(MultiArrayAdapter&& rhs) noexcept = delete;
        MultiArrayAdapter& operator=(MultiArrayAdapter&& rhs) noexcept = delete;

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

        NODISCARD std::strong_ordering operator<=>(const MultiArrayAdapter& rhs) const;

    private:
        T* container;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_H
