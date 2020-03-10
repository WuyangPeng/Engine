// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:33)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CAST_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CAST_H

#include "NetworkMessageInternalFwd.h"
#include "Flags/MessageTypeFlags.h"

#include <string>

namespace Network
{
	template<MultipleMessageByteType byteType>
	struct MultipleMessageCast;

	template<>
	struct MultipleMessageCast<MultipleMessageByteType::String>
	{
		using ValueType = std::string;
	};

	template<>
	struct MultipleMessageCast<MultipleMessageByteType::Uint64>
	{
		using ValueType = uint64_t;
	};

	template<>
	struct MultipleMessageCast<MultipleMessageByteType::Int64>
	{
		using ValueType = int64_t;
	};

	template<>
	struct MultipleMessageCast<MultipleMessageByteType::Uint32>
	{
		using ValueType = uint32_t;
	};

	template<>
	struct MultipleMessageCast<MultipleMessageByteType::Int32>
	{
		using ValueType = int32_t;
	};

	template<>
	struct MultipleMessageCast<MultipleMessageByteType::Uint16>
	{
		using ValueType = uint16_t;
	};

	template<>
	struct MultipleMessageCast<MultipleMessageByteType::Int16>
	{
		using ValueType = int16_t;
	};

	template<>
	struct MultipleMessageCast<MultipleMessageByteType::Uint8>
	{
		using ValueType = uint8_t;
	};

	template<>
	struct MultipleMessageCast<MultipleMessageByteType::Int8>
	{
		using ValueType = int8_t;
	};

	template<MultipleMessageByteType ByteType>
	struct MultipleMessageParameterCast
	{
		using ValueType = typename MultipleMessageCast<ByteType>::ValueType;
	};

	template<>
	struct MultipleMessageParameterCast<MultipleMessageByteType::String>
	{
		using ValueType = const std::string&;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CAST_H
