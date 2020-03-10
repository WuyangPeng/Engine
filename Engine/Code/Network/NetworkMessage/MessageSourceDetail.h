// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 15:47)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_DETAIL_H

#include "MessageSource.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

template <typename T>
void Network::MessageSource
	::Read(T& datum)
{
	static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	constexpr auto typeSize = sizeof(T);

	m_Source->Read(typeSize, &datum);
}

template <typename T>
void Network::MessageSource
	::Read(int elementsNumber, T* data)
{
	static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (0 < elementsNumber)
	{
		const auto typeSize = CORE_TOOLS_STREAM_SIZE(T{});

		m_Source->Read(typeSize, elementsNumber, data);
	}
}

template <typename T>
void Network::MessageSource
	::Read(std::vector<T>& datum)
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
void Network::MessageSource
	::ReadEnum(T& datum)
{
	static_assert(std::is_enum_v<T>, "T is not enum");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	using UnderlyingType = std::underlying_type_t<T>;

	UnderlyingType value{ 0 };
	Read(value);

	datum = System::UnderlyingCastEnum<T>(value);
}

template <typename T>
void Network::MessageSource
	::ReadEnum(int elementsNumber, T* data)
{
	static_assert(std::is_enum_v<T>, "T is not enum");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		ReadEnum(data[i]);
	}
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_SOURCE_DETAIL_H
