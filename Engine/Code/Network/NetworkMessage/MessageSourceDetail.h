/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:10)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_DETAIL_H

#include "MessageSource.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <typename T>
void Network::MessageSource::Read(T& datum)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    const auto typeSize = CoreTools::GetStreamSize<T>();

    source.Read(typeSize, &datum);
}

template <typename T>
void Network::MessageSource::Read(int elementsNumber, T* data)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    if (0 < elementsNumber)
    {
        const auto typeSize = CoreTools::GetStreamSize<T>();

        source.Read(typeSize, elementsNumber, data);
    }
}

template <typename T>
void Network::MessageSource::Read(std::vector<T>& datum)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

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
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_enum_v<T>, "T is not enum");

    using UnderlyingType = std::underlying_type_t<T>;

    UnderlyingType value{ 0 };
    Read(value);

    datum = System::UnderlyingCastEnum<T>(value);
}

template <typename T>
void Network::MessageSource::ReadEnum(int elementsNumber, T* data)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_enum_v<T>, "T is not enum");

    for (auto i = 0; i < elementsNumber; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ReadEnum(data[i]);

#include SYSTEM_WARNING_POP
    }
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_DETAIL_H
