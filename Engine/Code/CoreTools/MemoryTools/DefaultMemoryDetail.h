//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/20 11:03)

#ifndef CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_DETAIL_H

#include "DefaultMemory.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

// static
template <typename T>
T* CoreTools::DefaultMemory::New1DArray(const int bound)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26402)
#include SYSTEM_WARNING_DISABLE(26409)
    return new T[bound];
#include STSTEM_WARNING_POP
}

// static
template <typename T>
T** CoreTools::DefaultMemory::New2DArray(const int bound1, const int bound2)
{
    CORE_TOOLS_ASSERTION_0(0 < bound1, "要生成的数组大小必须大于0！");
    CORE_TOOLS_ASSERTION_0(0 < bound2, "要生成的数组大小必须大于0！");

    const auto bound = bound1 * bound2;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26403)
#include SYSTEM_WARNING_DISABLE(26409)
    auto data = new T*[bound2];
#include STSTEM_WARNING_POP

    NewArrayUseFailureDelete(data, bound);

    for (auto index = 1; index < bound2; ++index)
    {
        auto position = bound1 * index;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        data[index] = &data[0][position];
#include STSTEM_WARNING_POP
    }

    return data;
}

// private
template <typename T>
void CoreTools::DefaultMemory::NewArrayUseFailureDelete(T**& data, int bound)
{
    try
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26481)
        data[0] = new T[bound];

#include STSTEM_WARNING_POP
    }
    catch (...)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)
        delete[] data;
#include STSTEM_WARNING_POP
        throw;
    }
}

// static
template <typename T>
T*** CoreTools::DefaultMemory::New3DArray(const int bound1, const int bound2, const int bound3)
{
    const auto innerBound = bound2 * bound3;
    const auto bound = bound1 * innerBound;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26403)
#include SYSTEM_WARNING_DISABLE(26409)
    auto data = new T**[bound3];
#include STSTEM_WARNING_POP

    NewArrayUseFailureDelete(data, bound, innerBound);

    for (auto index3 = 0; index3 < bound3; ++index3)
    {
        auto position2 = bound2 * index3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        data[index3] = &data[0][position2];
#include STSTEM_WARNING_POP

        for (auto index2 = 0; index2 < bound2; ++index2)
        {
            auto position1 = bound1 * (index2 + position2);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            data[index3][index2] = &data[0][0][position1];
#include STSTEM_WARNING_POP
        }
    }

    return data;
}

// private
template <typename T>
void CoreTools::DefaultMemory::NewArrayUseFailureDelete(T***& data, int bound, int innerBound)
{
    try
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26481)
        data[0] = new T*[innerBound];
#include STSTEM_WARNING_POP

        NewArrayUseFailureDelete(data[0], bound);
    }
    catch (...)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)
        delete[] data;
#include STSTEM_WARNING_POP

        throw;
    }
}

// static
template <typename T>
T**** CoreTools::DefaultMemory::New4DArray(const int bound1, const int bound2, const int bound3, const int bound4)
{
    const auto innermostBound = bound3 * bound4;
    const auto innerBound = bound2 * innermostBound;
    const auto bound = bound1 * innerBound;

    auto data = new T***[bound4];

    NewArrayUseFailureDelete(data, bound, innerBound, innermostBound);

    for (auto index4 = 0; index4 < bound4; ++index4)
    {
        auto position3 = bound3 * index4;
        data[index4] = &data[0][position3];

        for (auto index3 = 0; index3 < bound3; ++index3)
        {
            auto position2 = bound2 * (index3 + position3);
            data[index4][index3] = &data[0][0][position2];

            for (auto index2 = 0; index2 < bound2; ++index2)
            {
                auto position1 = bound1 * (index2 + position2);
                data[index4][index3][index2] = &data[0][0][0][position1];
            }
        }
    }

    return data;
}

// private
template <typename T>
void CoreTools::DefaultMemory::NewArrayUseFailureDelete(T****& data, int bound, int innerBound, int innermostBound)
{
    try
    {
        data[0] = new T**[innermostBound];

        NewArrayUseFailureDelete(data[0], bound, innerBound);
    }
    catch (...)
    {
        delete[] data;
        throw;
    }
}

// static
template <typename T>
void CoreTools::DefaultMemory::DeleteSingle(T*& data) noexcept
{
    delete data;
    data = nullptr;
}

// static
template <typename T>
void CoreTools::DefaultMemory::Delete1DArray(T*& data) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)
    delete[] data;
#include STSTEM_WARNING_POP

    data = nullptr;
}

// static
template <typename T>
void CoreTools::DefaultMemory::Delete2DArray(T**& data) noexcept
{
    if (data != nullptr)
    {
        Delete1DArray(data[0]);
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)
    delete[] data;
#include STSTEM_WARNING_POP

    data = nullptr;
}

// static
template <typename T>
void CoreTools::DefaultMemory::Delete3DArray(T***& data) noexcept
{
    if (data != nullptr)
    {
        Delete2DArray(data[0]);
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)
    delete[] data;
#include STSTEM_WARNING_POP

    data = nullptr;
}

// static
template <typename T>
void CoreTools::DefaultMemory::Delete4DArray(T****& data) noexcept
{
    if (data != nullptr)
    {
        Delete3DArray(data[0]);
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)
    delete[] data;
#include STSTEM_WARNING_POP

    data = nullptr;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_DETAIL_H
