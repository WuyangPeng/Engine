/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 16:03)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY3_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY3_DETAIL_H

#include "Array3.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <gsl/util>

template <typename T>
CoreTools::Array3<T>::Array3() noexcept
    : bound0{}, bound1{}, bound2{}, objects{}, indirect1{}, indirect2{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::Array3<T>::Array3(int bound0, int bound1, int bound2)
    : bound0{ bound0 }, bound1{ bound1 }, bound2{ bound2 }, objects(GetObjectSize(bound0, bound1, bound2)), indirect1(GetObjectSize(bound1, bound2)), indirect2(bound2)
{
    SetPointers();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::Array3<T>::Array3(const Array3& rhs)
    : bound0{ rhs.bound0 }, bound1{ rhs.bound1 }, bound2{ rhs.bound2 }, objects{ rhs.objects }, indirect1(GetObjectSize(rhs.bound1, rhs.bound2)), indirect2(rhs.bound2)
{
    SetPointers();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::Array3<T>& CoreTools::Array3<T>::operator=(const Array3& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    bound0 = rhs.bound0;
    bound1 = rhs.bound1;
    bound2 = rhs.bound2;
    objects = rhs.objects;

    SetPointers();

    return *this;
}

template <typename T>
CoreTools::Array3<T>::Array3(Array3&& rhs) noexcept
    : bound0{ rhs.bound0 }, bound1{ rhs.bound1 }, bound2{ rhs.bound2 }, objects{ std::move(rhs.objects) }, indirect1{ std::move(rhs.indirect1) }, indirect2{ std::move(rhs.indirect2) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
CoreTools::Array3<T>& CoreTools::Array3<T>::operator=(Array3&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    bound0 = rhs.bound0;
    bound1 = rhs.bound1;
    bound2 = rhs.bound2;
    objects = std::move(rhs.objects);
    indirect1 = std::move(rhs.indirect1);
    indirect2 = std::move(rhs.indirect2);

    return *this;
}

template <typename T>
void CoreTools::Array3<T>::SetPointers()
{
    for (auto bound2Index = 0; bound2Index < bound2; ++bound2Index)
    {
        const auto indirect1Index = bound1 * bound2Index;
        indirect2.at(bound2Index) = &indirect1.at(indirect1Index);

        for (auto bound1Index = 0; bound1Index < bound1; ++bound1Index)
        {
            const auto objectsIndex = bound0 * (bound1Index + indirect1Index);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            indirect2.at(bound2Index)[bound1Index] = &objects.at(objectsIndex);

#include SYSTEM_WARNING_POP
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::Array3<T>::IsValid() const noexcept
{
    return gsl::narrow_cast<int>(objects.size()) == bound0 * bound1 * bound2 &&
           gsl::narrow_cast<int>(indirect1.size()) == bound1 * bound2 &&
           gsl::narrow_cast<int>(indirect2.size()) == bound2;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int CoreTools::Array3<T>::GetBound0() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound0;
}

template <typename T>
int CoreTools::Array3<T>::GetBound1() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bound1;
}

template <typename T>
int CoreTools::Array3<T>::GetBound2() const noexcept
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
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T**>(static_cast<const ClassType&>(*this)[slice]);

#include SYSTEM_WARNING_POP
}

template <typename T>
const T* CoreTools::Array3<T>::operator()(int slice, int row) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto index = row + slice * bound1;

    return indirect1.at(index);
}

template <typename T>
T* CoreTools::Array3<T>::operator()(int slice, int row)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T*>(static_cast<const ClassType&>(*this)(slice, row));

#include SYSTEM_WARNING_POP
}

template <typename T>
const T& CoreTools::Array3<T>::operator()(int slice, int row, int column) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto index = column + row * bound0 + slice * (bound0 * bound1);

    return objects.at(index);
}

template <typename T>
T& CoreTools::Array3<T>::operator()(int slice, int row, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T&>(static_cast<const ClassType&>(*this)(slice, row, column));

#include SYSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY3_DETAIL_H
