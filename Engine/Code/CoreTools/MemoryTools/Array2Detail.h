///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/29 10:38)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY2_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY2_DETAIL_H

#include "Array2.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T>
CoreTools::Array2<T>::Array2() noexcept
    : bound0{}, bound1{}, objects{}, indirect{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::Array2<T>::Array2(size_t bound0, size_t bound1)
    : bound0{ bound0 }, bound1{ bound1 }, objects(bound0 * bound1), indirect(bound1)
{
    SetPointers();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
void CoreTools::Array2<T>::SetPointers()
{
    for (auto bound1Index = 0u; bound1Index < bound1; ++bound1Index)
    {
        const auto objectsIndex = bound0 * bound1Index;
        indirect.at(bound1Index) = &objects.at(bound1Index);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::Array2<T>::IsValid() const noexcept
{
    if (objects.size() == bound0 * bound1 &&
        indirect.size() == bound1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
size_t CoreTools::Array2<T>::GetBound0() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound0;
}

template <typename T>
size_t CoreTools::Array2<T>::GetBound1() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound1;
}

template <typename T>
T const* CoreTools::Array2<T>::operator[](int row) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return indirect[row];
}

template <typename T>
T* CoreTools::Array2<T>::operator[](int row) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return OPERATOR_SQUARE_BRACKETS_TO_POINTER(T, row);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY2_DETAIL_H