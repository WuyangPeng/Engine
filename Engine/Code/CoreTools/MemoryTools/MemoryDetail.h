//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/20 11:06)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MEMORY_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_MEMORY_DETAIL_H

#include "Memory.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
T* CoreTools::Memory::New1DArray(const int bound)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    // 插入T[]到内存映射。
    auto data = static_cast<T*>(MEMORY_MANAGER_SINGLETON.CreateBlock(bound * sizeof(T), 1, m_FunctionDescribed));

    CallConstructor(data, bound);

    return data;
}

// private
template <typename T>
void CoreTools::Memory::CallConstructor(T*& data, int bound)
{
    size_t constructorSuccess{ 0 };
    try
    {
        // 调用T的默认构造函数
        auto object = data;
        for (auto i = 0; i < bound; ++i)
        {
            ::new (object) T;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            ++object;
#include STSTEM_WARNING_POP

            ++constructorSuccess;
        }
    }
    catch (...)
    {
        DeleteArray(data, constructorSuccess);
        throw;
    }
}

template <typename T>
T** CoreTools::Memory::New2DArray(const int bound1, const int bound2)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto bound = bound1 * bound2;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
    // T*没有构造函数，插入T*[]到内存映射。
    auto data = static_cast<T**>(MEMORY_MANAGER_SINGLETON.CreateBlock(bound2 * sizeof(T*), 2, m_FunctionDescribed));
#include STSTEM_WARNING_POP

    try
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        // 插入T[]到内存映射。
        data[0] = static_cast<T*>(MEMORY_MANAGER_SINGLETON.CreateBlock(bound * sizeof(T), 1, m_FunctionDescribed));
#include STSTEM_WARNING_POP
    }
    catch (...)
    {
        MEMORY_MANAGER_SINGLETON.Delete(data);
        throw;
    }

    CallConstructor(data, bound);

    // 对2D数组挂接指针
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
void CoreTools::Memory::CallConstructor(T**& data, int bound)
{
    size_t constructorSuccess{ 0 };
    try
    {
        // 调用T的默认构造函数。如果T是指针类型，编译器不会对构造函数的调用生成任何代码。
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        T* object = data[0];
#include STSTEM_WARNING_POP

        for (auto i = 0; i < bound; ++i)
        {
            ::new (object) T;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            ++object;
#include STSTEM_WARNING_POP

            ++constructorSuccess;
        }
    }
    catch (...)
    {
        MEMORY_MANAGER_SINGLETON.Delete(data);
        DeleteArray(data[0], constructorSuccess);
        throw;
    }
}

template <typename T>
T*** CoreTools::Memory::New3DArray(const int bound1, const int bound2, const int bound3)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto innerBound = bound2 * bound3;
    const auto bound = bound1 * innerBound;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
    // T**没有构造函数，插入T**[]到内存映射。
    auto data = static_cast<T***>(MEMORY_MANAGER_SINGLETON.CreateBlock(bound3 * sizeof(T**), 3, m_FunctionDescribed));
#include STSTEM_WARNING_POP

    try
    {
        // T*没有构造函数，插入T*[]到内存映射。
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        data[0] = static_cast<T**>(MEMORY_MANAGER_SINGLETON.CreateBlock(innerBound * sizeof(T*), 2, m_FunctionDescribed));
#include STSTEM_WARNING_POP

        try
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            // 插入T[]到内存映射。
            data[0][0] = static_cast<T*>(MEMORY_MANAGER_SINGLETON.CreateBlock(bound * sizeof(T), 1, m_FunctionDescribed));
#include STSTEM_WARNING_POP
        }
        catch (...)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            MEMORY_MANAGER_SINGLETON.Delete(data[0]);
#include STSTEM_WARNING_POP

            throw;
        }
    }
    catch (...)
    {
        MEMORY_MANAGER_SINGLETON.Delete(data);
        throw;
    }

    CallConstructor(data, bound);

    // 对3D数组挂接指针
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
void CoreTools::Memory::CallConstructor(T***& data, int bound)
{
    size_t constructorSuccess{ 0 };
    try
    {
        // 调用T的默认构造函数。如果T是指针类型，
        // 编译器不会对构造函数的调用生成任何代码。
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        T* object = data[0][0];
#include STSTEM_WARNING_POP

        for (auto i = 0; i < bound; ++i)
        {
            ::new (object) T;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            ++object;
#include STSTEM_WARNING_POP

            ++constructorSuccess;
        }
    }
    catch (...)
    {
        MEMORY_MANAGER_SINGLETON.Delete(data);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        MEMORY_MANAGER_SINGLETON.Delete(data[0]);
        DeleteArray(data[0][0], constructorSuccess);

#include STSTEM_WARNING_POP

        throw;
    }
}

template <typename T>
T**** CoreTools::Memory::New4DArray(const int bound1, const int bound2, const int bound3, const int bound4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto innermostBound = bound3 * bound4;
    const auto innerBound = bound2 * innermostBound;
    const auto bound = bound1 * innerBound;

    // T***没有构造函数，插入T***[]到内存映射。
    auto data = static_cast<T****>(MEMORY_MANAGER_SINGLETON.CreateBlock(bound4 * sizeof(T***), 4, m_FunctionDescribed));

    try
    {
        // T**没有构造函数，插入T**[]到内存映射。
        data[0] = static_cast<T***>(MEMORY_MANAGER_SINGLETON.CreateBlock(innermostBound * sizeof(T**), 3, m_FunctionDescribed));

        try
        {
            // T*没有构造函数，插入T*[]到内存映射。
            data[0][0] = static_cast<T**>(MEMORY_MANAGER_SINGLETON.CreateBlock(innerBound * sizeof(T*), 2, m_FunctionDescribed));
            try
            {
                // 插入T[]到内存映射。
                data[0][0][0] = static_cast<T*>(MEMORY_MANAGER_SINGLETON.CreateBlock(bound * sizeof(T), 1, m_FunctionDescribed));
            }
            catch (...)
            {
                MEMORY_MANAGER_SINGLETON.Delete(data[0][0]);
                throw;
            }
        }
        catch (...)
        {
            MEMORY_MANAGER_SINGLETON.Delete(data[0]);
            throw;
        }
    }
    catch (...)
    {
        MEMORY_MANAGER_SINGLETON.Delete(data);
        throw;
    }

    CallConstructor(data, bound);

    // 对4D数组挂接指针
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
void CoreTools::Memory ::CallConstructor(T****& data, int bound)
{
    size_t constructorSuccess{ 0 };
    try
    {
        // 调用T的默认构造函数。如果T是指针类型，编译器不会对构造函数的调用生成任何代码。
        T* object = data[0][0][0];
        for (auto i = 0; i < bound; ++i)
        {
            ::new (object) T;
            ++object;
            ++constructorSuccess;
        }
    }
    catch (...)
    {
        MEMORY_MANAGER_SINGLETON.Delete(data);
        MEMORY_MANAGER_SINGLETON.Delete(data[0]);
        MEMORY_MANAGER_SINGLETON.Delete(data[0][0]);
        DeleteArray(data[0][0][0], constructorSuccess);
        throw;
    }
}

template <typename T>
void CoreTools::Memory::DeleteSingle(T*& data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (data != nullptr)
    {
        CORE_TOOLS_ASSERTION_2(MEMORY_MANAGER_SINGLETON.GetMemBlockDimensions(data) == 0, "维度不匹配！");

        // 调用T的析构函数。如果T是指针类型，编译器不会对析构函数的调用生成任何代码。
        data->~T();

        // 从内存映射中移除T
        MEMORY_MANAGER_SINGLETON.Delete(data);

        data = nullptr;
    }
}

template <typename T>
void CoreTools::Memory::Delete1DArray(T*& data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (data != nullptr)
    {
        CORE_TOOLS_ASSERTION_2(MEMORY_MANAGER_SINGLETON.GetMemBlockDimensions(data) == 1, "维度不匹配！");

        const auto bytesNumber = MEMORY_MANAGER_SINGLETON.GetBytesNumber(data) / sizeof(T);

        DeleteArray(data, bytesNumber);

        data = nullptr;
    }
}

// private
template <typename T>
void CoreTools::Memory::DeleteArray(T*& data, size_t constructorSuccess)
{
    // 调用T的析构函数。如果T是指针类型，编译器不会对析构函数的调用生成任何代码。
    if (0 < constructorSuccess)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
        T* object = data;
#include STSTEM_WARNING_POP

        for (auto i = 0u; i < constructorSuccess; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26493)
            object->~T();
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            ++object;
#include STSTEM_WARNING_POP
        }
    }

    // 从内存映射中移除T[]
    MEMORY_MANAGER_SINGLETON.Delete(data);
}

template <typename T>
void CoreTools::Memory::Delete2DArray(T**& data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (data != nullptr)
    {
        CORE_TOOLS_ASSERTION_2(MEMORY_MANAGER_SINGLETON.GetMemBlockDimensions(data) == 2, "维度不匹配！");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        const auto bytesNumber = MEMORY_MANAGER_SINGLETON.GetBytesNumber(data[0]) / sizeof(T);
#include STSTEM_WARNING_POP

        DeleteArray(data[0], bytesNumber);

        // T*没有析构函数，从内存映射中移除T*[]
        MEMORY_MANAGER_SINGLETON.Delete(data);

        data = nullptr;
    }
}

template <typename T>
void CoreTools::Memory::Delete3DArray(T***& data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (data != nullptr)
    {
        CORE_TOOLS_ASSERTION_2(MEMORY_MANAGER_SINGLETON.GetMemBlockDimensions(data) == 3, "维度不匹配！");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        const auto bytesNumber = MEMORY_MANAGER_SINGLETON.GetBytesNumber(data[0][0]) / sizeof(T);

        DeleteArray(data[0][0], bytesNumber);

        // T*没有析构函数，从内存映射中移除T*[]
        MEMORY_MANAGER_SINGLETON.Delete(data[0]);

#include STSTEM_WARNING_POP

        // T**没有析构函数，从内存映射中移除T**[]
        MEMORY_MANAGER_SINGLETON.Delete(data);

        data = nullptr;
    }
}

template <typename T>
void CoreTools::Memory::Delete4DArray(T****& data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (data != nullptr)
    {
        CORE_TOOLS_ASSERTION_2(MEMORY_MANAGER_SINGLETON.GetMemBlockDimensions(data) == 4, "维度不匹配！");

        auto bytesNumber = MEMORY_MANAGER_SINGLETON.GetBytesNumber(data[0][0][0]) / sizeof(T);

        DeleteArray(data[0][0][0], bytesNumber);

        // T*没有析构函数，从内存映射中移除T*[]
        MEMORY_MANAGER_SINGLETON.Delete(data[0][0]);

        // T**没有析构函数，从内存映射中移除T**[]
        MEMORY_MANAGER_SINGLETON.Delete(data[0]);

        // T***没有析构函数，从内存映射中移除T***[]
        MEMORY_MANAGER_SINGLETON.Delete(data);

        data = nullptr;
    }
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MEMORY_DETAIL_H
