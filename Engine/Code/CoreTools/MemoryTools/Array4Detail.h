/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 16:06)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY4_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY4_DETAIL_H

#include "Array4.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <gsl/util>

template <typename T>
CoreTools::Array4<T>::Array4() noexcept
    : bound0{},
      bound1{},
      bound2{},
      bound3{},
      objects{},
      indirect1{},
      indirect2{},
      indirect3{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::Array4<T>::Array4(int bound0, int bound1, int bound2, int bound3)
    : bound0{ bound0 },
      bound1{ bound1 },
      bound2{ bound2 },
      bound3{ bound3 },
      objects(GetObjectSize(bound0, bound1, bound2, bound3)),
      indirect1(GetObjectSize(bound1, bound2, bound3)),
      indirect2(GetObjectSize(bound2, bound3)),
      indirect3(bound3)
{
    SetPointers();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::Array4<T>::Array4(const Array4& rhs)
    : bound0{ rhs.bound0 },
      bound1{ rhs.bound1 },
      bound2{ rhs.bound2 },
      bound3{ rhs.bound3 },
      objects{ rhs.objects },
      indirect1(GetObjectSize(rhs.bound1, rhs.bound2, rhs.bound3)),
      indirect2(GetObjectSize(rhs.bound2, rhs.bound3)),
      indirect3(rhs.bound3)
{
    SetPointers();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::Array4<T>& CoreTools::Array4<T>::operator=(const Array4& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    bound0 = rhs.bound0;
    bound1 = rhs.bound1;
    bound2 = rhs.bound2;
    bound3 = rhs.bound3;
    objects = rhs.objects;

    SetPointers();

    return *this;
}

template <typename T>
CoreTools::Array4<T>::Array4(Array4&& rhs) noexcept
    : bound0{ rhs.bound0 },
      bound1{ rhs.bound1 },
      bound2{ rhs.bound2 },
      bound3{ rhs.bound3 },
      objects{ std::move(rhs.objects) },
      indirect1{ std::move(rhs.indirect1) },
      indirect2{ std::move(rhs.indirect2) },
      indirect3{ std::move(rhs.indirect3) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::Array4<T>& CoreTools::Array4<T>::operator=(Array4&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    bound0 = rhs.bound0;
    bound1 = rhs.bound1;
    bound2 = rhs.bound2;
    bound3 = rhs.bound3;
    objects = std::move(rhs.objects);
    indirect1 = std::move(rhs.indirect1);
    indirect2 = std::move(rhs.indirect2);
    indirect3 = std::move(rhs.indirect3);

    return *this;
}

template <typename T>
void CoreTools::Array4<T>::SetPointers()
{
    for (auto bound3Index = 0; bound3Index < bound3; ++bound3Index)
    {
        const auto indirect2Index = bound2 * bound3Index;
        indirect3.at(bound3Index) = &indirect2.at(indirect2Index);

        for (auto bound2Index = 0; bound2Index < bound2; ++bound2Index)
        {
            const auto indirect1Index = bound1 * (bound2Index + indirect2Index);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            indirect3.at(bound3Index)[bound2Index] = &indirect1.at(indirect1Index);

#include SYSTEM_WARNING_POP

            for (auto bound1Index = 0; bound1Index < bound1; ++bound1Index)
            {
                const auto objectsIndex = bound0 * (bound1Index + indirect1Index);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indirect3.at(bound3Index)[bound2Index][bound1Index] = &objects.at(objectsIndex);

#include SYSTEM_WARNING_POP
            }
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::Array4<T>::IsValid() const noexcept
{
    return gsl::narrow_cast<int>(objects.size()) == bound0 * bound1 * bound2 * bound3 &&
           gsl::narrow_cast<int>(indirect1.size()) == bound1 * bound2 * bound3 &&
           gsl::narrow_cast<int>(indirect2.size()) == bound2 * bound3 &&
           gsl::narrow_cast<int>(indirect3.size()) == bound3;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int CoreTools::Array4<T>::GetBound0() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound0;
}

template <typename T>
int CoreTools::Array4<T>::GetBound1() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound1;
}

template <typename T>
int CoreTools::Array4<T>::GetBound2() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound2;
}

template <typename T>
int CoreTools::Array4<T>::GetBound3() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound3;
}

template <typename T>
T** const* CoreTools::Array4<T>::operator[](int cuboid) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return indirect3.at(cuboid);
}

template <typename T>
T*** CoreTools::Array4<T>::operator[](int cuboid)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T***>(static_cast<const ClassType&>(*this)[cuboid]);

#include SYSTEM_WARNING_POP
}

template <typename T>
T* const* CoreTools::Array4<T>::operator()(int cuboid, int slice) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto index = slice + cuboid * bound2;

    return indirect2.at(index);
}

template <typename T>
T** CoreTools::Array4<T>::operator()(int cuboid, int slice)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T**>(static_cast<const ClassType&>(*this)(cuboid, slice));

#include SYSTEM_WARNING_POP
}

template <typename T>
const T* CoreTools::Array4<T>::operator()(int cuboid, int slice, int row) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto index = row + slice * bound1 + cuboid * (bound1 * bound2);

    return indirect1.at(index);
}

template <typename T>
T* CoreTools::Array4<T>::operator()(int cuboid, int slice, int row)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T*>(static_cast<const ClassType&>(*this)(cuboid, slice, row));

#include SYSTEM_WARNING_POP
}

template <typename T>
const T& CoreTools::Array4<T>::operator()(int cuboid, int slice, int row, int column) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto index = column + row * bound0 + slice * (bound0 * bound1) + cuboid * (bound0 * bound1 * bound2);

    return objects.at(index);
}

template <typename T>
T& CoreTools::Array4<T>::operator()(int cuboid, int slice, int row, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T&>(static_cast<const ClassType&>(*this)(cuboid, slice, row, column));

#include SYSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY3_DETAIL_H
