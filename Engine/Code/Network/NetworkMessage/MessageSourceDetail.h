//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:34)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_DETAIL_H

#include "MessageSource.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <typename T>
void Network::MessageSource::Read(T& datum)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto typeSize = CoreTools::GetStreamSize<T>();

    m_Source->Read(typeSize, &datum);
}

template <typename T>
void Network::MessageSource::Read(int elementsNumber, T* data)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < elementsNumber)
    {
        const auto typeSize = CoreTools::GetStreamSize<T>();

        m_Source->Read(typeSize, elementsNumber, data);
    }
}

template <typename T>
void Network::MessageSource::Read(std::vector<T>& datum)
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t elementsNumber{ 0 };

    Read(elementsNumber);

    if (0 < elementsNumber)
    {
        datum.resize(elementsNumber);
        Read(elementsNumber, datum.data());
    }
}

template <typename T>
void Network::MessageSource::ReadEnum(T& datum)
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    using UnderlyingType = std::underlying_type_t<T>;

    UnderlyingType value{ 0 };

    Read(value);

    datum = System::UnderlyingCastEnum<T>(value);
}

template <typename T>
void Network::MessageSource::ReadEnum(int elementsNumber, T* data)
{
    static_assert(std::is_enum_v<T>, "T is not enum");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        ReadEnum(data[i]);
    }
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_DETAIL_H
