///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 14:31)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LATTICE_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_LATTICE_DETAIL_H

#include "Lattice.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes)) bool CoreTools::Lattice<OrderLToR, Sizes...>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes))
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<Condition>>
requires(sizeof...(IndexTypes) == sizeof...(Sizes))
size_t CoreTools::Lattice<OrderLToR, Sizes...>::GetIndex(IndexTypes... tuple) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return MetaGetIndexLToR(tuple...);
}

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes))
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<Condition>>
size_t CoreTools::Lattice<OrderLToR, Sizes...>::GetIndex(const std::array<size_t, sizeof...(Sizes)>& coordinate) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetIndexLToR(coordinate);
}

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes))
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<Condition>>
std::array<size_t, sizeof...(Sizes)> CoreTools::Lattice<OrderLToR, Sizes...>::GetCoordinate(size_t index) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    std::array<size_t, sizeof...(Sizes)> tuple{};

    for (auto dimension = 0u; dimension < sizeof...(Sizes); ++dimension)
    {
        const auto bound = GetSize(dimension);
        const auto j = index;
        index /= bound;
        tuple[dimension] = j - bound * index;
    }

    return tuple;
}

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes))
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<!Condition>>
requires(sizeof...(IndexTypes) == sizeof...(Sizes))
size_t CoreTools::Lattice<OrderLToR, Sizes...>::GetIndex(IndexTypes... tuple) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    using Type = typename std::tuple_element_t<0, std::tuple<IndexTypes...>>;

    return MetaGetIndexRToL(static_cast<Type>(0), tuple...);
}

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes))
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<!Condition>>
size_t CoreTools::Lattice<OrderLToR, Sizes...>::GetIndex(const std::array<size_t, sizeof...(Sizes)>& coordinate) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetIndexRToL(coordinate);
}

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes))
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<!Condition>>
std::array<size_t, sizeof...(Sizes)> CoreTools::Lattice<OrderLToR, Sizes...>::GetCoordinate(size_t index) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    std::array<size_t, sizeof...(Sizes)> tuple{};

    for (auto k = 0u, dimension = sizeof...(Sizes) - 1; k < sizeof...(Sizes); ++k, --dimension)
    {
        const auto bound = GetSize(dimension);
        auto j = index;
        index /= bound;
        tuple[dimension] = j - bound * index;
    }

    return tuple;
}

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes))
template <size_t NumDimensions, CoreTools::TraitSelector<(NumDimensions > 1)>>
size_t CoreTools::Lattice<OrderLToR, Sizes...>::GetIndexLToR(const std::array<size_t, sizeof...(Sizes)>& coordinate) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    std::array<size_t, sizeof...(Sizes)> sizes{};

    MetaAssignSize<0, Sizes...>(sizes.data());
    auto dimension = coordinate.size() - 1;
    auto indexLToR = coordinate[dimension];
    --dimension;
    for (auto k = 1u; k < sizeof...(Sizes); ++k, --dimension)
    {
        indexLToR = sizes[dimension] * indexLToR + coordinate[dimension];
    }

    return indexLToR;
}

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes))
template <size_t NumDimensions, CoreTools::TraitSelector<NumDimensions == 1>>
size_t CoreTools::Lattice<OrderLToR, Sizes...>::GetIndexLToR(const std::array<size_t, 1>& coordinate) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return coordinate[0];
}

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes))
template <size_t NumDimensions, CoreTools::TraitSelector<(NumDimensions > 1)>>
size_t CoreTools::Lattice<OrderLToR, Sizes...>::GetIndexRToL(const std::array<size_t, sizeof...(Sizes)>& coordinate) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    std::array<size_t, sizeof...(Sizes)> sizes{};

    MetaAssignSize<0, Sizes...>(sizes.data());
    auto dimension = 0u;
    auto indexRtoL = coordinate[dimension];
    for (++dimension; dimension < sizeof...(Sizes); ++dimension)
    {
        indexRtoL = sizes[dimension] * indexRtoL + coordinate[dimension];
    }

    return indexRtoL;
}

template <bool OrderLToR, size_t... Sizes>
requires(1 <= sizeof...(Sizes))
template <size_t NumDimensions, CoreTools::TraitSelector<NumDimensions == 1>>
size_t CoreTools::Lattice<OrderLToR, Sizes...>::GetIndexRToL(const std::array<size_t, 1>& coordinate) const noexcept
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
CoreTools::Lattice<OrderLToR>::Lattice(const std::initializer_list<size_t>& sizes)
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
void CoreTools::Lattice<OrderLToR>::Reset(const SizeType& sizes)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    InternalReset(sizes);
}

template <bool OrderLToR>
void CoreTools::Lattice<OrderLToR>::Reset(const std::initializer_list<size_t>& sizes)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    InternalReset(sizes);
}

template <bool OrderLToR>
size_t CoreTools::Lattice<OrderLToR>::GetDimensions() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sizes.size();
}

template <bool OrderLToR>
size_t CoreTools::Lattice<OrderLToR>::GetSize(size_t dimension) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sizes.at(dimension);
}

template <bool OrderLToR>
size_t CoreTools::Lattice<OrderLToR>::GetSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numElements;
}

template <bool OrderLToR>
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<Condition>>
size_t CoreTools::Lattice<OrderLToR>::GetIndex(IndexTypes... tuple) const
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
size_t CoreTools::Lattice<OrderLToR>::GetIndex(const SizeType& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (sizes.empty() || sizes.size() != coordinate.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效索引参数"));
    }

    auto dimension = coordinate.size() - 1;
    auto indexLToR = coordinate[dimension];
    --dimension;
    for (auto k = 1u; k < coordinate.size(); ++k, --dimension)
    {
        indexLToR = sizes[dimension] * indexLToR + coordinate[dimension];
    }

    return indexLToR;
}

template <bool OrderLToR>
template <typename... IndexTypes, bool Condition, CoreTools::TraitSelector<!Condition>>
size_t CoreTools::Lattice<OrderLToR>::GetIndex(IndexTypes... tuple) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (sizes.empty() || sizes.size() != sizeof...(IndexTypes))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效索引参数"));
    }

    using Type = std::tuple_element_t<0, std::tuple<IndexTypes...>>;

    return MetaGetIndexRToL(static_cast<Type>(0), tuple...);
}

template <bool OrderLToR>
template <bool Condition, CoreTools::TraitSelector<!Condition>>
size_t CoreTools::Lattice<OrderLToR>::GetIndex(const SizeType& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (sizes.empty() || sizes.size() != coordinate.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效索引参数"));
    }

    auto dimension = 0u;
    auto indexRToL = coordinate[dimension];
    for (++dimension; dimension < coordinate.size(); ++dimension)
    {
        indexRToL = sizes[dimension] * indexRToL + coordinate[dimension];
    }

    return indexRToL;
}

template <bool OrderLToR>
template <bool Condition, CoreTools::TraitSelector<Condition>>
typename CoreTools::Lattice<OrderLToR>::SizeType CoreTools::Lattice<OrderLToR>::GetCoordinate(size_t index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto numDimensions = GetDimensions();

    SizeType tuple(numDimensions);
    for (auto dimension = 0u; dimension < numDimensions; ++dimension)
    {
        const auto bound = GetSize(dimension);
        const auto j = index;
        index /= bound;
        tuple[dimension] = j - bound * index;
    }

    return tuple;
}

template <bool OrderLToR>
template <bool Condition, CoreTools::TraitSelector<!Condition>>
typename CoreTools::Lattice<OrderLToR>::SizeType CoreTools::Lattice<OrderLToR>::GetCoordinate(size_t index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto numDimensions = GetDimensions();
    SizeType tuple(numDimensions);
    for (auto k = 0u, dimension = numDimensions - 1; k < numDimensions; ++k, --dimension)
    {
        const auto bound = GetSize(dimension);
        const auto j = index;
        index /= bound;
        tuple[dimension] = j - bound * index;
    }
    return tuple;
}

template <bool OrderLToR>
std::strong_ordering CoreTools::Lattice<OrderLToR>::operator<=>(const Lattice& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sizes <=> rhs.sizes;
}

template <bool OrderLToR>
template <typename Container>
void CoreTools::Lattice<OrderLToR>::InternalReset(const Container& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (container.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("容器大小为空"));
    }

    numElements = 1;
    sizes.resize(container.size());
    auto dimension = 0u;
    for (const auto& size : container)
    {
        if (size <= 0)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("维度必须为正数。"));
        }

        numElements *= size;
        sizes[dimension++] = size;
    }
}

template <bool OrderLToR>
template <typename First, typename... Successors>
requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
size_t CoreTools::Lattice<OrderLToR>::MetaGetIndexLToR(First first, Successors... successors) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return static_cast<size_t>(first) + sizes[sizes.size() - 1 - sizeof...(Successors)] * MetaGetIndexLToR(successors...);
}

template <bool OrderLToR>
template <typename Last>
requires(std::is_integral_v<Last> && !std::is_same_v<Last, bool>)
size_t CoreTools::Lattice<OrderLToR>::MetaGetIndexLToR(Last last) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return static_cast<size_t>(last);
}

template <bool OrderLToR>
template <typename Term, typename First, typename... Successors>
requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
size_t CoreTools::Lattice<OrderLToR>::MetaGetIndexRToL(Term t, First first, Successors... successors) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto size = sizes[sizes.size() - sizeof...(Successors)];

    return MetaGetIndexRToL(size * static_cast<size_t>(first + t), successors...);
}

template <bool OrderLToR>
template <typename Term, typename First>
requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
size_t CoreTools::Lattice<OrderLToR>::MetaGetIndexRToL(Term t, First first) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return static_cast<size_t>(first + t);
}

template <bool OrderLToR>
template <typename First>
requires(std::is_integral_v<First> && !std::is_same_v<First, bool>)
size_t CoreTools::Lattice<OrderLToR>::MetaGetIndexRToL(First first) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return static_cast<size_t>(first);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_LATTICE_DETAIL_H
