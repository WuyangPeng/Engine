///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/29 10:38)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY3_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY3_DETAIL_H

#include "Array3.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T>
CoreTools::Array3<T>::Array3(size_t bound0, size_t bound1, size_t bound2)
    : bound0{ bound0 }, bound1{ bound1 }, bound2{ bound2 }, objects(bound0 * bound1 * bound2), indirect1(bound1 * bound2), indirect2(bound2)
{
    SetPointers();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
void CoreTools::Array3<T>::SetPointers()
{
    for (auto bound2Index = 0u; bound2Index < bound2; ++bound2Index)
    {
        auto indirect1Index = bound1 * bound2Index;
        indirect2[bound2Index] = &indirect1[indirect1Index];

        for (auto bound1Index = 0u; bound1Index < bound1; ++bound1Index)
        {
            size_t objectsIndex = bound0 * (bound1Index + indirect1Index);
            indirect2[bound2Index][bound1Index] = &objects[objectsIndex];
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::Array3<T>::IsValid() const noexcept
{
    if (objects.size() == bound0 * bound1 * bound2 &&
        indirect1.size() == bound1 * bound2 &&
        indirect2.size() == bound2)
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
size_t CoreTools::Array3<T>::GetBound0() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound0;
}

template <typename T>
size_t CoreTools::Array3<T>::GetBound1() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound1;
}

template <typename T>
size_t CoreTools::Array3<T>::GetBound2() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound2;
}

template <typename T>
T* const* CoreTools::Array3<T>::operator[](int slice) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return indirect2.at(slice);
}

template <typename T>
T** CoreTools::Array3<T>::operator[](int slice)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return OPERATOR_SQUARE_BRACKETS_TO_POINTER(T**, slice);
}

template <typename T>
T CoreTools::Array3<T>::Get(int index0, int index1, int index2) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return objects.at(index0 * (bound1 + bound2) + index1 * bound2 + index2);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY3_DETAIL_H
