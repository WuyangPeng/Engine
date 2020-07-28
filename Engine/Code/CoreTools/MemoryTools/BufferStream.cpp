// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 13:33)

#include "CoreTools/CoreToolsExport.h"

#include "BufferStream.h"
#include "Detail/BufferStreamImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;

CoreTools::BufferStream
	::BufferStream(BufferPool* pool, int minSize)
	:m_Impl{ make_shared<ImplType>(pool,minSize) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::BufferStream
	::BufferStream(BufferPool* pool)
	:m_Impl{ make_shared<ImplType>(pool) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, BufferStream)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, ResetData, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferStream, GetOriginalMemoryLength, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, Append, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, SetDataLength, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, AddDataLength, int, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferStream, GetDataLength, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferStream, GetTotalMemoryLength, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferStream, GetRemainDataLength, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, AdvanceDataStartPosition, int, void)

void CoreTools::BufferStream
	::Set(int index, uint32_t data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Set(index, data);
}

void CoreTools::BufferStream
	::Set(int index, int32_t data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Set(index, data);
}

void CoreTools::BufferStream
	::Set(int index, uint16_t data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Set(index, data);;
}

void CoreTools::BufferStream
	::Set(int index, int16_t data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Set(index, data);
}

void CoreTools::BufferStream
	::Set(int index, uint8_t data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Set(index, data);
}

void CoreTools::BufferStream
	::Set(int index, int8_t data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Set(index, data);
}

void CoreTools::BufferStream
	::Set(int index, bool data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Set(index, data);
}

void CoreTools::BufferStream
	::Set(int index, const uint8_t* buffer, int bufferLength)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Set(index, buffer, bufferLength);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, Add, uint32_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, Add, int32_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, Add, uint16_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, Add, int16_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, Add, uint8_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, Add, int8_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, Add, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, BufferStream, AddString, string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, BufferStream, AddTerminatedString, string, void)

void CoreTools::BufferStream
	::Add(const uint8_t* buffer, int bufferLength)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Add(buffer, bufferLength);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferStream, InitRead, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, InitRead, int, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferStream, GetReadPosition, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferStream, GetReadableLength, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BufferStream, SetReadPosition, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, ReadUInt32, uint32_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, ReadInt32, int32_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, ReadUInt16, uint16_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, ReadInt16, int16_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, ReadUInt8, uint8_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, ReadInt8, int8_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, ReadBool, bool)

void CoreTools::BufferStream
	::Read(uint8_t* buffer, int bufferLength)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Read(buffer, bufferLength);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, PeekUInt32, uint32_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, PeekInt32, int32_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, PeekUInt16, uint16_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, PeekInt16, int16_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, PeekUInt8, uint8_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, PeekInt8, int8_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BufferStream, PeekBool, bool)

void CoreTools::BufferStream
	::Peek(uint8_t* buffer, int bufferLength)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Peek(buffer, bufferLength);
}
