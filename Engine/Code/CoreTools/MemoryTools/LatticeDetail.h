/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 18:10)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LATTICE_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_LATTICE_DETAIL_H

#include "Lattice.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <bool OrderLToR, int... Sizes>
bool CoreTools::Lattice<OrderLToR, Sizes...>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <bool OrderLToR, int... Sizes>
int CoreTools::Lattice<OrderLToR, Sizes...>::GetSize(int dimension) const
{
    std::array<int, sizeof...(Sizes)> sizes{};

    MetaAssignSize<0, Sizes...>(sizes.data());

    return sizes.at(dimension);
}

template <bool OrderLToR, int... Sizes>
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<Condition>>
requires(sizeof...(IndexTypes) == sizeof...(Sizes))
int CoreTools::Lattice<OrderLToR, Sizes...>::GetIndex(IndexTypes... tuple) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return MetaGetIndexLToR(tuple...);
}

template <bool OrderLToR, int... Sizes>
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<Condition>>
int CoreTools::Lattice<OrderLToR, Sizes...>::GetIndex(const std::array<int, sizeof...(Sizes)>& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetIndexLToR(coordinate);
}

template <bool OrderLToR, int... Sizes>
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<Condition>>
std::array<int, sizeof...(Sizes)> CoreTools::Lattice<OrderLToR, Sizes...>::GetCoordinate(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    /// i = x[0] + b[0] * (x[1] + b[1] * (x[2] + ...)
    /// tuple = (x[0], ..., x[n-1])
    std::array<int, sizeof...(Sizes)> tuple{};

    for (auto dimension = 0u; dimension < sizeof...(Sizes); ++dimension)
    {
        const auto bound = GetSize(dimension);
        const auto remainder = index;
        index /= bound;
        tuple.at(dimension) = remainder - bound * index;
    }

    return tuple;
}

template <bool OrderLToR, int... Sizes>
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<!Condition>>
requires(sizeof...(IndexTypes) == sizeof...(Sizes))
int CoreTools::Lattice<OrderLToR, Sizes...>::GetIndex(IndexTypes... tuple) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    using Type = std::tuple_element_t<0, std::tuple<IndexTypes...>>;

    return MetaGetIndexRToL(gsl::narrow_cast<Type>(0), tuple...);
}

template <bool OrderLToR, int... Sizes>
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<!Condition>>
int CoreTools::Lattice<OrderLToR, Sizes...>::GetIndex(const std::array<int, sizeof...(Sizes)>& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetIndexRToL(coordinate);
}

template <bool OrderLToR, int... Sizes>
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<!Condition>>
std::array<int, sizeof...(Sizes)> CoreTools::Lattice<OrderLToR, Sizes...>::GetCoordinate(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    /// i = x[n-1] + b[n-1] * (x[n-2] + b[n-2] * (x[n-3] + ...)
    /// tuple = (x[0], ..., x[n-1])
    std::array<int, sizeof...(Sizes)> tuple{};

    for (auto i = 0, dimension = gsl::narrow_cast<int>(sizeof...(Sizes) - 1); i < sizeof...(Sizes); ++i, --dimension)
    {
        const auto bound = GetSize(dimension);
        const auto remainder = index;
        index /= bound;
        tuple.at(dimension) = remainder - bound * index;
    }

    return tuple;
}

template <bool OrderLToR, int... Sizes>
bool CoreTools::Lattice<OrderLToR, Sizes...>::operator==(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return true;
}

template <bool OrderLToR, int... Sizes>
bool CoreTools::Lattice<OrderLToR, Sizes...>::operator!=(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return false;
}

template <bool OrderLToR, int... Sizes>
bool CoreTools::Lattice<OrderLToR, Sizes...>::operator<(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return false;
}

template <bool OrderLToR, int... Sizes>
bool CoreTools::Lattice<OrderLToR, Sizes...>::operator<=(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return true;
}

template <bool OrderLToR, int... Sizes>
bool CoreTools::Lattice<OrderLToR, Sizes...>::operator>(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return false;
}

template <bool OrderLToR, int... Sizes>
bool CoreTools::Lattice<OrderLToR, Sizes...>::operator>=(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return true;
}

template <bool OrderLToR, int... Sizes>
template <int NumDimensions, CoreTools::TraitSelector<(NumDimensions > 1)>>
int CoreTools::Lattice<OrderLToR, Sizes...>::GetIndexLToR(const std::array<int, sizeof...(Sizes)>& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    std::array<int, sizeof...(Sizes)> sizes{};

    MetaAssignSize<0, Sizes...>(sizes.data());
    auto dimension = coordinate.size() - 1;
    auto indexLToR = coordinate.at(dimension);
    --dimension;
    for (auto i = 1u; i < sizeof...(Sizes); ++i, --dimension)
    {
        indexLToR = sizes.at(dimension) * indexLToR + coordinate.at(dimension);
    }

    return indexLToR;
}

template <bool OrderLToR, int... Sizes>
template <int NumDimensions, CoreTools::TraitSelector<NumDimensions == 1>>
int CoreTools::Lattice<OrderLToR, Sizes...>::GetIndexLToR(const std::array<int, 1>& coordinate) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return coordinate[0];
}

template <bool OrderLToR, int... Sizes>
template <int NumDimensions, CoreTools::TraitSelector<(NumDimensions > 1)>>
int CoreTools::Lattice<OrderLToR, Sizes...>::GetIndexRToL(const std::array<int, sizeof...(Sizes)>& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    std::array<int, sizeof...(Sizes)> sizes{};

    MetaAssignSize<0, Sizes...>(sizes.data());
    auto dimension = 0u;
    auto indexRtoL = coordinate.at(dimension);
    for (++dimension; dimension < sizeof...(Sizes); ++dimension)
    {
        indexRtoL = sizes.at(dimension) * indexRtoL + coordinate.at(dimension);
    }

    return indexRtoL;
}

template <bool OrderLToR, int... Sizes>
template <int NumDimensions, CoreTools::TraitSelector<NumDimensions == 1>>
int CoreTools::Lattice<OrderLToR, Sizes...>::GetIndexRToL(const std::array<int, 1>& coordinate) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return coordinate[0];
}

template <bool OrderLToR>
CoreTools::Lattice<OrderLToR>::Lattice() noexcept
    : numElements{ 0 },
      sizes{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <bool OrderLToR>
CoreTools::Lattice<OrderLToR>::Lattice(const SizeType& sizes)
    : numElements{ 0 },
      sizes{}
{
    InternalReset(sizes);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <bool OrderLToR>
CoreTools::Lattice<OrderLToR>::Lattice(const std::initializer_list<int>& sizes)
    : numElements{ 0 },
      sizes{}
{
    InternalReset(sizes);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <bool OrderLToR>
bool CoreTools::Lattice<OrderLToR>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <bool OrderLToR>
void CoreTools::Lattice<OrderLToR>::Reset(const SizeType& aSizes)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    InternalReset(aSizes);
}

template <bool OrderLToR>
void CoreTools::Lattice<OrderLToR>::Reset(const std::initializer_list<int>& aSizes)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    InternalReset(aSizes);
}

template <bool OrderLToR>
int CoreTools::Lattice<OrderLToR>::GetDimensions() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(sizes.size());
}

template <bool OrderLToR>
int CoreTools::Lattice<OrderLToR>::GetSize(int dimension) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sizes.at(dimension);
}

template <bool OrderLToR>
int CoreTools::Lattice<OrderLToR>::GetSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numElements;
}

template <bool OrderLToR>
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<Condition>>
int CoreTools::Lattice<OrderLToR>::GetIndex(IndexTypes... tuple) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (sizes.empty() || sizes.size() != sizeof...(IndexTypes))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效索引参数"));
    }

    return MetaGetIndexLToR(tuple...);
}

template <bool OrderLToR>
template <bool Condition, CoreTools::TraitSelector<Condition>>
int CoreTools::Lattice<OrderLToR>::GetIndex(const SizeType& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (sizes.empty() || sizes.size() != coordinate.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效索引参数"));
    }

    auto dimension = coordinate.size() - 1;
    auto indexLToR = coordinate.at(dimension);
    --dimension;
    for (auto i = 1u; i < coordinate.size(); ++i, --dimension)
    {
        indexLToR = sizes.at(dimension) * indexLToR + coordinate.at(dimension);
    }

    return indexLToR;
}

template <bool OrderLToR>
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<!Condition>>
int CoreTools::Lattice<OrderLToR>::GetIndex(IndexTypes... tuple) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (sizes.empty() || sizes.size() != sizeof...(IndexTypes))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效索引参数"));
    }

    using Type = std::tuple_element_t<0, std::tuple<IndexTypes...>>;

    return MetaGetIndexRToL(gsl::narrow_cast<Type>(0), tuple...);
}

template <bool OrderLToR>
template <bool Condition, CoreTools::TraitSelector<!Condition>>
int CoreTools::Lattice<OrderLToR>::GetIndex(const SizeType& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (sizes.empty() || sizes.size() != coordinate.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效索引参数"));
    }

    auto dimension = 0u;
    auto indexRToL = coordinate.at(dimension);
    for (++dimension; dimension < coordinate.size(); ++dimension)
    {
        indexRToL = sizes.at(dimension) * indexRToL + coordinate.at(dimension);
    }

    return indexRToL;
}

template <bool OrderLToR>
template <bool Condition, CoreTools::TraitSelector<Condition>>
typename CoreTools::Lattice<OrderLToR>::SizeType CoreTools::Lattice<OrderLToR>::GetCoordinate(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    /// i = x[0] + b[0] * (x[1] + b[1] * (x[2] + ...)
    /// tuple = (x[0], ..., x[n-1])
    const auto numDimensions = GetDimensions();

    SizeType tuple(numDimensions);
    for (auto dimension = 0; dimension < numDimensions; ++dimension)
    {
        const auto bound = GetSize(dimension);
        const auto remainder = index;
        index /= bound;
        tuple.at(dimension) = remainder - bound * index;
    }

    return tuple;
}

template <bool OrderLToR>
template <bool Condition, CoreTools::TraitSelector<!Condition>>
typename CoreTools::Lattice<OrderLToR>::SizeType CoreTools::Lattice<OrderLToR>::GetCoordinate(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    /// i = x[n-1] + b[n-1] * (x[n-2] + b[n-2] * (x[n-3] + ...)
    /// tuple = (x[0], ..., x[n-1])
    const auto numDimensions = GetDimensions();

    SizeType tuple(numDimensions);
    for (auto i = 0, dimension = numDimensions - 1; i < numDimensions; ++i, --dimension)
    {
        const auto bound = GetSize(dimension);
        const auto remainder = index;
        index /= bound;
        tuple.at(dimension) = remainder - bound * index;
    }
    return tuple;
}

template <bool OrderLToR>
bool CoreTools::Lattice<OrderLToR>::operator==(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sizes == rhs.sizes;
}

template <bool OrderLToR>
bool CoreTools::Lattice<OrderLToR>::operator!=(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sizes != rhs.sizes;
}

template <bool OrderLToR>
bool CoreTools::Lattice<OrderLToR>::operator<(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sizes < rhs.sizes;
}

template <bool OrderLToR>
bool CoreTools::Lattice<OrderLToR>::operator<=(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sizes <= rhs.sizes;
}

template <bool OrderLToR>
bool CoreTools::Lattice<OrderLToR>::operator>(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sizes > rhs.sizes;
}

template <bool OrderLToR>
bool CoreTools::Lattice<OrderLToR>::operator>=(const Lattice& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sizes >= rhs.sizes;
}

template <bool OrderLToR>
template <typename Container>
void CoreTools::Lattice<OrderLToR>::InternalReset(const Container& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (container.size() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("容器大小为空"));
    }

    numElements = 1;

    for (const auto& size : container)
    {
        if (size <= 0)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("维度必须为正数。"));
        }

        numElements *= size;
        sizes.emplace_back(size);
    }
}

template <bool OrderLToR>
template <typename First, typename... Successors>
requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
int CoreTools::Lattice<OrderLToR>::MetaGetIndexLToR(First first, Successors... successors) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(first) + sizes.at(sizes.size() - 1 - sizeof...(Successors)) * MetaGetIndexLToR(successors...);
}

template <bool OrderLToR>
template <typename Last>
requires(std::is_integral_v<Last> && !std::is_same_v<Last, bool>)
int CoreTools::Lattice<OrderLToR>::MetaGetIndexLToR(Last last) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return gsl::narrow_cast<int>(last);
}

template <bool OrderLToR>
template <typename Term, typename First, typename... Successors>
requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
int CoreTools::Lattice<OrderLToR>::MetaGetIndexRToL(Term t, First first, Successors... successors) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto size = sizes.at(sizes.size() - sizeof...(Successors));

    return MetaGetIndexRToL(size * gsl::narrow_cast<int>(first + t), successors...);
}

template <bool OrderLToR>
template <typename Term, typename First>
requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
int CoreTools::Lattice<OrderLToR>::MetaGetIndexRToL(Term t, First first) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return gsl::narrow_cast<int>(first + t);
}

template <bool OrderLToR>
template <typename First>
requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
int CoreTools::Lattice<OrderLToR>::MetaGetIndexRToL(First first) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return static_cast<int>(first);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_LATTICE_DETAIL_H
