///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:36)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY2_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY2_DETAIL_H

#include "Array2.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <gsl/util>

template <typename T>
CoreTools::Array2<T>::Array2() noexcept
    : bound0{}, bound1{}, objects{}, indirect{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::Array2<T>::Array2(int bound0, int bound1)
    : bound0{ bound0 }, bound1{ bound1 }, objects(GetObjectSize(bound0, bound1)), indirect(bound1)
{
    SetPointers();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
void CoreTools::Array2<T>::SetPointers()
{
    for (auto bound1Index = 0; bound1Index < bound1; ++bound1Index)
    {
        const auto objectsIndex = bound0 * bound1Index;
        indirect.at(bound1Index) = &objects.at(objectsIndex);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::Array2<T>::IsValid() const noexcept
{
    if (gsl::narrow_cast<int>(objects.size()) == bound0 * bound1 &&
        gsl::narrow_cast<int>(indirect.size()) == bound1)
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
int CoreTools::Array2<T>::GetBound0() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound0;
}

template <typename T>
int CoreTools::Array2<T>::GetBound1() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound1;
}

template <typename T>
const T* CoreTools::Array2<T>::operator[](int row) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return indirect.at(row);
}

template <typename T>
T* CoreTools::Array2<T>::operator[](int row)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return OPERATOR_SQUARE_BRACKETS_TO_POINTER(T, row);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY2_DETAIL_H