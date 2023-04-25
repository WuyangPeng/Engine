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

#include "Lattice.h"

namespace CoreTools
{
    template <typename T, bool OrderLToR, int... Sizes>
    class MultiArrayAdapter : public Lattice<OrderLToR, Sizes...>
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

        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        void Fill(const T& value) noexcept;

        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple) noexcept;

        NODISCARD const T& operator()(const std::array<int, sizeof...(Sizes)>& coordinate) const noexcept;
        NODISCARD T& operator()(const std::array<int, sizeof...(Sizes)>& coordinate) noexcept;

    private:
        T* container;
    };

    template <typename T, bool OrderLToR>
    class MultiArrayAdapter<T, OrderLToR> : public Lattice<OrderLToR>
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

        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        void Fill(const T& value) noexcept;

        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple);

        NODISCARD const T& operator()(const SizeType& coordinate) const;
        NODISCARD T& operator()(const SizeType& coordinate);

    private:
        T* container;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_H
