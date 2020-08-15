// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:51)

#include "CoreTools/CoreToolsExport.h"

#include "BufferTarget.h"
#include "ObjectRegister.h"
#include "StreamSize.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26486)
using std::array;
using std::string;

CoreTools::BufferTarget
	::BufferTarget(const FileBufferPtr& fileBufferPtr, ObjectRegister& objectRegister)
	:m_Target{ boost::numeric_cast<int>(fileBufferPtr->GetSize()), fileBufferPtr->GetBufferBegin() }, m_ObjectRegister{ objectRegister }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferTarget)

void CoreTools::BufferTarget
	::WriteBool(const bool datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	const uint32_t value{ datum ? 0xFFFFFFFFu : 0u };
	m_Target.Write(sizeof(uint32_t), &value);
}

void CoreTools::BufferTarget
	::WriteBoolWithNumber(int elementsNumber, const bool* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Target.Write(sizeof(int32_t), &elementsNumber);
	WriteBoolWithoutNumber(elementsNumber, data);
}

void CoreTools::BufferTarget
	::WriteBoolWithoutNumber(int elementsNumber, const bool* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		WriteBool(data[i]);
	}
}

void CoreTools::BufferTarget
	::WriteString(const string& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto length = boost::numeric_cast<int32_t>(datum.length());
	m_Target.Write(sizeof(int32_t), &length);

	if (0 < length)
	{
		m_Target.Write(sizeof(char), length, datum.c_str());

		// 字符串被写入为4字节的倍数。
		array<char, g_DefaultSize> zero{};
		auto padding = length % g_DefaultSize;
		if (0 < padding)
		{
			padding = g_DefaultSize - padding;
			m_Target.Write(sizeof(char), padding, zero.data());
		}
	}
}

void CoreTools::BufferTarget
	::WriteStringWithNumber(int elementsNumber, const string* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Target.Write(sizeof(int32_t), &elementsNumber);
	WriteStringWithoutNumber(elementsNumber, data);
}

void CoreTools::BufferTarget
	::WriteStringWithoutNumber(int elementsNumber, const string* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		WriteString(data[i]);
	}
}

int CoreTools::BufferTarget
	::GetBytesWritten() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Target.GetBytesProcessed();
}

void CoreTools::BufferTarget
	::WriteUniqueID(const ConstObjectInterfaceSmartPointer& object)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	const auto uniqueID = m_ObjectRegister.GetUniqueID(object);
	m_Target.Write(sizeof(uint64_t), &uniqueID);
}



#include STSTEM_WARNING_POP