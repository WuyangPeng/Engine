//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:36)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_DETAIL_H

#include "MessageTarget.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <typename T>
void Network::MessageTarget::Write(T datum)
{

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto typeSize = CoreTools::GetStreamSize<T>(); 

    return m_Target->Write(typeSize, &datum);
}

template <typename T>
void Network::MessageTarget::WriteWithNumber(int32_t elementsNumber, const T* data)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(elementsNumber);
    WriteWithoutNumber(elementsNumber, data);
}

template <typename T>
void Network::MessageTarget::WriteWithoutNumber(int32_t elementsNumber, const T* data)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        const auto typeSize = CoreTools::GetStreamSize<T>();

        m_Target->Write(typeSize, elementsNumber, data);
    }
}

template <typename T>
void Network::MessageTarget::Write(const std::vector<T>& datum)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto elementsNumber = boost::numeric_cast<int32_t>(datum.size());

    Write(elementsNumber);
    if (0 < elementsNumber)
    {
        WriteWithoutNumber(elementsNumber, datum.data());
    }
}

template <typename T>
void Network::MessageTarget::WriteEnum(const T datum)
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto value = System::EnumCastUnderlying(datum);
    Write(value);
}

template <typename T>
void Network::MessageTarget::WriteEnumWithNumber(int32_t elementsNumber, const T* data)
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(elementsNumber);
    WriteEnumWithoutNumber(elementsNumber, data);
}

template <typename T>
void Network::MessageTarget::WriteEnumWithoutNumber(int32_t elementsNumber, const T* data)
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        WriteEnum(data[i]);
    }
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_DETAIL_H