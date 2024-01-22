/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:10)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_DETAIL_H

#include "MessageTarget.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <typename T>
void Network::MessageTarget::Write(T datum)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    const auto typeSize = CoreTools::GetStreamSize<T>();

    return target.Write(typeSize, &datum);
}

template <typename T>
void Network::MessageTarget::WriteWithNumber(int32_t elementsNumber, const T* data)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    Write(elementsNumber);
    WriteWithoutNumber(elementsNumber, data);
}

template <typename T>
void Network::MessageTarget::WriteWithoutNumber(int32_t elementsNumber, const T* data)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    if (0 < elementsNumber)
    {
        const auto typeSize = CoreTools::GetStreamSize<T>();

        target.Write(typeSize, elementsNumber, data);
    }
}

template <typename T>
void Network::MessageTarget::Write(const std::vector<T>& datum)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");

    auto elementsNumber = boost::numeric_cast<int32_t>(datum.size());

    Write(elementsNumber);
    if (0 < elementsNumber)
    {
        WriteWithoutNumber(elementsNumber, datum.data());
    }
}

template <typename T>
void Network::MessageTarget::WriteEnum(T datum)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_enum_v<T>, "T is not enum");

    const auto value = System::EnumCastUnderlying(datum);
    Write(value);
}

template <typename T>
void Network::MessageTarget::WriteEnumWithNumber(int32_t elementsNumber, const T* data)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_enum_v<T>, "T is not enum");

    Write(elementsNumber);
    WriteEnumWithoutNumber(elementsNumber, data);
}

template <typename T>
void Network::MessageTarget::WriteEnumWithoutNumber(int32_t elementsNumber, const T* data)
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    static_assert(std::is_enum_v<T>, "T is not enum");

    for (auto i = 0; i < elementsNumber; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        WriteEnum(data[i]);

#include SYSTEM_WARNING_POP
    }
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_DETAIL_H