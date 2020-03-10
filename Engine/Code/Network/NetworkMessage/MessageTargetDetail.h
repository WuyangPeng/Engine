// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 15:49)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_DETAIL_H

#include "MessageTarget.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename T>
void Network::MessageTarget
	::Write(T datum)
{
	static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	const auto typeSize = CORE_TOOLS_STREAM_SIZE(T{});

	return m_Target->Write(typeSize, &datum);
}

template <typename T>
void Network::MessageTarget
	::WriteWithNumber(int32_t elementsNumber, const T* data)
{
	static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	Write(elementsNumber);
	WriteWithoutNumber(elementsNumber, data);
}

template <typename T>
void Network::MessageTarget
	::WriteWithoutNumber(int32_t elementsNumber, const T* data)
{
	static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (0 < elementsNumber)
	{
		const auto typeSize = CORE_TOOLS_STREAM_SIZE(T{});

		m_Target->Write(typeSize, elementsNumber, data);
	}
}

template <typename T>
void Network::MessageTarget
	::Write(const std::vector<T>& datum)
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
void Network::MessageTarget
	::WriteEnum(const T datum)
{
	static_assert(std::is_enum_v<T>, "T is not enum");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto value = System::EnumCastUnderlying(datum);
	Write(value);
}

template <typename T>
void Network::MessageTarget
	::WriteEnumWithNumber(int32_t elementsNumber, const T* data)
{
	static_assert(std::is_enum_v<T>, "T is not enum");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	Write(elementsNumber);
	WriteEnumWithoutNumber(elementsNumber, data);
}

template <typename T>
void Network::MessageTarget
	::WriteEnumWithoutNumber(int32_t elementsNumber, const T* data)
{
	static_assert(std::is_enum_v<T>, "T is not enum");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		WriteEnum(data[i]);
	}
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_TARGET_DETAIL_H