///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:29)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CAST_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CAST_H

#include "NetworkMessageInternalFwd.h"
#include "Flags/MessageTypeFlags.h"

#include <string>

namespace Network
{
    template <MultipleMessageByteType ByteType>
    struct MultipleMessageCast;

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::String>
    {
        using ValueType = std::string;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Uint64>
    {
        using ValueType = uint64_t;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Int64>
    {
        using ValueType = int64_t;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Uint32>
    {
        using ValueType = uint32_t;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Int32>
    {
        using ValueType = int32_t;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Uint16>
    {
        using ValueType = uint16_t;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Int16>
    {
        using ValueType = int16_t;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Uint8>
    {
        using ValueType = uint8_t;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Int8>
    {
        using ValueType = int8_t;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Bool>
    {
        using ValueType = bool;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Float>
    {
        using ValueType = float;
    };

    template <>
    struct MultipleMessageCast<MultipleMessageByteType::Double>
    {
        using ValueType = double;
    };

    template <MultipleMessageByteType ByteType>
    struct MultipleMessageParameterCast
    {
        using ValueType = typename MultipleMessageCast<ByteType>::ValueType;
    };

    template <>
    struct MultipleMessageParameterCast<MultipleMessageByteType::String>
    {
        using ValueType = const std::string&;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CAST_H
