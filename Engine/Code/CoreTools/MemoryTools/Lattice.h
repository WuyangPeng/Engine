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
#include "System/Helper/PragmaWarning.h"

#include <gsl/util>
#include <array>
#include <vector>

namespace CoreTools
{
    template <bool OrderLToR, int... Sizes>
    class Lattice
    {
    public:
        using ClassType = Lattice<OrderLToR, Sizes...>;

    public:
        Lattice() noexcept = default;
        virtual ~Lattice() noexcept = default;
        Lattice(const Lattice& rhs) = default;
        Lattice& operator=(const Lattice& rhs) = default;
        Lattice(Lattice&& rhs) noexcept = default;
        Lattice& operator=(Lattice&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD static constexpr int GetDimensions() noexcept
        {
            return sizeof...(Sizes);
        }

        NODISCARD constexpr int GetSize(int dimension) const noexcept
        {
            std::array<int, sizeof...(Sizes)> sizes{};

            MetaAssignSize<0, Sizes...>(sizes.data());

            return sizes.at(dimension);
        }

        NODISCARD constexpr int GetSize() const noexcept
        {
            return MetaProduct<Sizes...>::value;
        }

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        requires(sizeof...(IndexTypes) == sizeof...(Sizes))
        NODISCARD int GetIndex(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD int GetIndex(const std::array<int, sizeof...(Sizes)>& coordinate) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD std::array<int, sizeof...(Sizes)> GetCoordinate(int index) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        requires(sizeof...(IndexTypes) == sizeof...(Sizes))
        NODISCARD int GetIndex(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD int GetIndex(const std::array<int, sizeof...(Sizes)>& coordinate) const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD std::array<int, sizeof...(Sizes)> GetCoordinate(int index) const noexcept;

    private:
        template <int I, int F, int... R>
        struct MetaArgument
        {
            static const auto value = MetaArgument<I - 1, R...>::value;
        };

        template <int F, int... R>
        struct MetaArgument<0, F, R...>
        {
            static const auto value = F;
        };

        template <int I, int F, int... R>
        constexpr void MetaAssignSize(int* sizes) const noexcept
        {
            if (sizes != nullptr)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                sizes[I] = F;

#include STSTEM_WARNING_POP

                MetaAssignSize<I + 1, R...>(sizes);
            }
        }

        template <int NumElements>
        constexpr void MetaAssignSize(int*) const noexcept
        {
        }

        template <int...>
        struct MetaProduct : std::integral_constant<int, 1>
        {
        };

        template <int F, int... R>
        struct MetaProduct<F, R...> : std::integral_constant<int, F * MetaProduct<R...>::value>
        {
        };

        template <typename First, typename... Successors>
        NODISCARD constexpr int MetaGetIndexLToR(First first, Successors... successors) const noexcept requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        {
            constexpr auto size = MetaArgument<sizeof...(Sizes) - 1 - sizeof...(Successors), Sizes...>::value;

            return gsl::narrow_cast<int>(first) + size * MetaGetIndexLToR(successors...);
        }

        template <typename Last>
        NODISCARD constexpr int MetaGetIndexLToR(Last last) const noexcept requires(std::is_integral_v<Last> && !std::is_same_v<Last, bool>)
        {
            return gsl::narrow_cast<int>(last);
        }

        template <int NumDimensions = sizeof...(Sizes), TraitSelector<(NumDimensions > 1)> = 0>
        NODISCARD int GetIndexLToR(const std::array<int, sizeof...(Sizes)>& coordinate) const noexcept;

        template <int NumDimensions = sizeof...(Sizes), TraitSelector<NumDimensions == 1> = 0>
        NODISCARD int GetIndexLToR(const std::array<int, 1>& coordinate) const noexcept;

        template <typename Term, typename First, typename... Successors>
        NODISCARD constexpr int MetaGetIndexRToL(Term t, First first, Successors... successors) const noexcept requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        {
            constexpr auto size = MetaArgument<sizeof...(Sizes) - sizeof...(Successors), Sizes...>::value;

            return MetaGetIndexRToL(size * gsl::narrow_cast<int>(first + t), successors...);
        }

        template <typename Term, typename First>
        NODISCARD constexpr int MetaGetIndexRToL(Term t, First first) const noexcept requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        {
            return gsl::narrow_cast<int>(first + t);
        }

        template <int NumDimensions = sizeof...(Sizes), TraitSelector<(NumDimensions > 1)> = 0>
        NODISCARD int GetIndexRToL(const std::array<int, sizeof...(Sizes)>& coordinate) const noexcept;

        template <int NumDimensions = sizeof...(Sizes), TraitSelector<NumDimensions == 1> = 0>
        NODISCARD int GetIndexRToL(const std::array<int, 1>& coordinate) const noexcept;

    public:
        static int constexpr numDimensions = sizeof...(Sizes);
        static int constexpr numElements = MetaProduct<Sizes...>::value;
    };

    template <bool OrderLToR>
    class Lattice<OrderLToR>
    {
    public:
        using ClassType = Lattice<OrderLToR>;
        using SizeType = std::vector<int>;

    public:
        Lattice() noexcept;
        virtual ~Lattice() noexcept = default;
        Lattice(const Lattice& rhs) = default;
        Lattice& operator=(const Lattice& rhs) = default;
        Lattice(Lattice&& rhs) noexcept = default;
        Lattice& operator=(Lattice&& rhs) noexcept = default;

        explicit Lattice(const SizeType& sizes);
        explicit Lattice(const std::initializer_list<int>& sizes);

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Reset(const SizeType& aSizes);
        virtual void Reset(const std::initializer_list<int>& aSizes);

        NODISCARD int GetDimensions() const;

        NODISCARD int GetSize(int dimension) const;
        NODISCARD int GetSize() const noexcept;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD int GetIndex(IndexTypes... tuple) const;

        template <bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD int GetIndex(const SizeType& coordinate) const;

        template <typename... IndexTypes, bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD int GetIndex(IndexTypes... tuple) const;

        template <bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD int GetIndex(const SizeType& coordinate) const;

        template <bool Condition = OrderLToR, TraitSelector<Condition> = 0>
        NODISCARD SizeType GetCoordinate(int index) const;

        template <bool Condition = OrderLToR, TraitSelector<!Condition> = 0>
        NODISCARD SizeType GetCoordinate(int index) const;

    private:
        template <typename Container>
        void InternalReset(const Container& container);

        template <typename First, typename... Successors>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD int MetaGetIndexLToR(First first, Successors... successors) const;

        template <typename Last>
        requires(std::is_integral_v<Last> && !std::is_same_v<Last, bool>)
        NODISCARD int MetaGetIndexLToR(Last last) const noexcept;

        template <typename Term, typename First, typename... Successors>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD int MetaGetIndexRToL(Term t, First first, Successors... successors) const;

        template <typename Term, typename First>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD int MetaGetIndexRToL(Term t, First first) const noexcept;

        template <typename First>
        requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
        NODISCARD int MetaGetIndexRToL(First first) const;

    protected:
        int numElements;
        SizeType sizes;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_LATTICE_H
