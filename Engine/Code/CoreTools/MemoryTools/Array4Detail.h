///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/28 20:52)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY4_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY4_DETAIL_H

#include "Array4.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::Array4<T>::Array4(size_t bound0, size_t bound1, size_t bound2, size_t bound3)
    : bound0{ bound0 },
      bound1{ bound1 },
      bound2{ bound2 },
      bound3{ bound3 },
      objects(bound0 * bound1 * bound2 * bound3),
      indirect1(bound1 * bound2 * bound3),
      indirect2(bound2 * bound3),
      indirect3(bound3)
{
    SetPointers();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
void CoreTools::Array4<T>::SetPointers()
{
    for (auto bound3Index = 0u; bound3Index < bound3; ++bound3Index)
    {
        auto indirect2Index = bound2 * bound3Index;
        indirect3[bound3Index] = &indirect2[indirect2Index];

        for (auto bound2Index = 0u; bound2Index < bound2; ++bound2Index)
        {
            auto indirect1Index = bound0 * (bound2Index + indirect2Index);
            indirect3[bound3Index][bound2Index] = &indirect1[indirect1Index];

            for (auto bound1Index = 0; bound1Index < bound1; ++bound1Index)
            {
                auto objectsIndex = bound0 * (bound1Index + indirect1Index);
                indirect3[bound3Index][bound2Index][bound1Index] = &objects[objectsIndex];
            }
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::Array4<T>::IsValid() const noexcept
{
    if (objects.size() == bound0 * bound1 * bound2 * bound3 &&
        indirect1.size() == bound1 * bound2 * bound3 &&
        indirect2.size() == bound2 * bound3 &&
        indirect3.size() == bound3)
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
size_t CoreTools::Array4<T>::GetBound0() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound0;
}

template <typename T>
size_t CoreTools::Array4<T>::GetBound1() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound1;
}

template <typename T>
size_t CoreTools::Array4<T>::GetBound2() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound2;
}

template <typename T>
size_t CoreTools::Array4<T>::GetBound3() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound3;
}

template <typename T>
T** const* CoreTools::Array4<T>::operator[](int cuboid) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return indirect3[cuboid];
}

template <typename T>
T*** CoreTools::Array4<T>::operator[](int cuboid) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return OPERATOR_SQUARE_BRACKETS_TO_POINTER(T***, cuboid);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY3_DETAIL_H
