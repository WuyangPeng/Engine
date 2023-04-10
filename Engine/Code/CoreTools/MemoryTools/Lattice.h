///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 15:04)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LATTICE_H
#define CORE_TOOLS_MEMORY_TOOLS_LATTICE_H

#include "CoreTools/CoreToolsDll.h"

#include "TypeTraits.h"

#include <vector>

namespace CoreTools
{
    template <bool OrderLToR, size_t... Sizes>
    requires(1 <= sizeof...(Sizes))
    class Lattice
    {
    public:
        using ClassType = Lattice<OrderLToR, Sizes...>;

    public:
        Lattice() noexcept = default;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static constexpr size_t GetDimensions() noexcept
        {
            return sizeof...(Sizes);
        }

        NODISCARD constexpr size_t GetSize(size_t dimension) const noexcept
        {
            std::array<size_t, sizeof...(Sizes)> sizes{};

            MetaAssignSize<0, Sizes...>(sizes.data());

            return sizes[dimension];
        }

        NODISCARD constexpr size_t GetSize() const noexcept
        {
            return MetaProduct<Sizes...>::value;
        }

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        requires(sizeof...(IndexTypes) == sizeof...(Sizes))
        NODISCARD size_t GetIndex(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD size_t GetIndex(const std::array<size_t, sizeof...(Sizes)>& coordinate) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD std::array<size_t, sizeof...(Sizes)> GetCoordinate(size_t index) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        requires(sizeof...(IndexTypes) == sizeof...(Sizes))
        NODISCARD size_t GetIndex(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD size_t GetIndex(const std::array<size_t, sizeof...(Sizes)>& coordinate) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD std::array<size_t, sizeof...(Sizes)> GetCoordinate(size_t index) const noexcept;

    private:
        template <size_t I, size_t F, size_t... R>
        struct MetaArgument
        {
            static const auto value = MetaArgument<I - 1, R...>::value;
        };

        template <size_t F, size_t... R>
        struct MetaArgument<0, F, R...>
        {
            static const auto value = F;
        };

        template <size_t I, size_t F, size_t... R>
        constexpr void MetaAssignSize(size_t* sizes) const noexcept
        {
            sizes[I] = F;
            MetaAssignSize<I + 1, R...>(sizes);
        }

        template <size_t NumElements>
        constexpr void MetaAssignSize(size_t*) const noexcept
        {
        }

        template <size_t...>
        struct MetaProduct : std::integral_constant<size_t, 1>
        {
        };

        template <size_t F, size_t... R>
        struct MetaProduct<F, R...> : std::integral_constant<size_t, F * MetaProduct<R...>::value>
        {
        };

        template <typename First, typename... Successors>
        NODISCARD constexpr size_t MetaGetIndexLToR(First first, Successors... successors) const noexcept requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        {
            constexpr auto size = MetaArgument<sizeof...(Sizes) - 1 - sizeof...(Successors), Sizes...>::value;

            return static_cast<size_t>(first) + size * MetaGetIndexLToR(successors...);
        }

        template <typename Last>
        NODISCARD constexpr size_t MetaGetIndexLToR(Last last) const noexcept requires(std::is_integral_v<Last> && !std::is_same_v<Last, bool>)
        {
            return static_cast<size_t>(last);
        }

        template <size_t NumDimensions = sizeof...(Sizes), TraitSelector<(NumDimensions > 1)> = 0>
        NODISCARD size_t GetIndexLToR(const std::array<size_t, sizeof...(Sizes)>& coordinate) const noexcept;

        template <size_t NumDimensions = sizeof...(Sizes), TraitSelector<NumDimensions == 1> = 0>
        NODISCARD size_t GetIndexLToR(const std::array<size_t, 1>& coordinate) const noexcept;

        template <typename Term, typename First, typename... Successors>
        NODISCARD constexpr size_t MetaGetIndexRToL(Term t, First first, Successors... successors) const noexcept requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        {
            constexpr auto size = MetaArgument<sizeof...(Sizes) - sizeof...(Successors), Sizes...>::value;

            return MetaGetIndexRToL(size * static_cast<size_t>(first + t), successors...);
        }

        template <typename Term, typename First>
        NODISCARD constexpr size_t MetaGetIndexRToL(Term t, First first) const noexcept requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        {
            return static_cast<size_t>(first + t);
        }

        template <size_t NumDimensions = sizeof...(Sizes), TraitSelector<(NumDimensions > 1)> = 0>
        NODISCARD size_t GetIndexRToL(const std::array<size_t, sizeof...(Sizes)>& coordinate) const noexcept;

        template <size_t NumDimensions = sizeof...(Sizes), TraitSelector<NumDimensions == 1> = 0>
        NODISCARD size_t GetIndexRToL(const std::array<size_t, 1>& coordinate) const noexcept;

    public:
        static size_t constexpr numDimensions = sizeof...(Sizes);
        static size_t constexpr numElements = MetaProduct<Sizes...>::value;
    };

    template <bool OrderLToR>
    class Lattice<OrderLToR>
    {
    public:
        using ClassType = Lattice<OrderLToR>;
        using SizeType = std::vector<size_t>;

    public:
        Lattice() noexcept;

        explicit Lattice(const SizeType& sizes);
        explicit Lattice(const std::initializer_list<size_t>& sizes);

        CLASS_INVARIANT_DECLARE;

        void Reset(const SizeType& sizes);
        void Reset(const std::initializer_list<size_t>& sizes);

        NODISCARD size_t GetDimensions() const noexcept;

        NODISCARD size_t GetSize(size_t dimension) const;
        NODISCARD size_t GetSize() const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD size_t GetIndex(IndexTypes... tuple) const;

        template <bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD size_t GetIndex(const SizeType& coordinate) const;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD size_t GetIndex(IndexTypes... tuple) const;

        template <bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD size_t GetIndex(const SizeType& coordinate) const;

        template <bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD SizeType GetCoordinate(size_t index) const;

        template <bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD SizeType GetCoordinate(size_t index) const;

        NODISCARD std::strong_ordering operator<=>(const Lattice& rhs) const;

    private:
        template <typename Container>
        void InternalReset(const Container& container);

        template <typename First, typename... Successors>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD size_t MetaGetIndexLToR(First first, Successors... successors) const;

        template <typename Last>
        requires(std::is_integral_v<Last> && !std::is_same_v<Last, bool>)
        NODISCARD size_t MetaGetIndexLToR(Last last) const;

        template <typename Term, typename First, typename... Successors>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD size_t MetaGetIndexRToL(Term t, First first, Successors... successors) const;

        template <typename Term, typename First>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD size_t MetaGetIndexRToL(Term t, First first) const;

        template <typename First>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD size_t MetaGetIndexRToL(First first) const;

    protected:
        size_t numElements;
        SizeType sizes;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_LATTICE_H
