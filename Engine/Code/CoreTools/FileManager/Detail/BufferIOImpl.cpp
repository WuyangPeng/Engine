// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 14:44)

#include "CoreTools/CoreToolsExport.h"

#include "BufferIOImpl.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BufferIOImpl
	::BufferIOImpl(int bytesTotal, BufferIO type)
	:m_BytesTotal{ bytesTotal }, m_BytesProcessed{ 0 }, m_BufferIOType{ type }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::BufferIOImpl
	::~BufferIOImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BufferIOImpl
	::IsValid() const noexcept
{
	if (0 < m_BytesTotal && 0 <= m_BytesProcessed)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::BufferIOImpl
	::GetBytesTotal() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_BytesTotal;
}

int CoreTools::BufferIOImpl
	::GetBytesProcessed() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_BytesProcessed;
}

void CoreTools::BufferIOImpl
	::IncrementBytesProcessed(int bytesNumber) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_2(0 < bytesNumber, "增量必须是正数！\n");

		auto nextBytesProcessed = m_BytesProcessed + bytesNumber;

		CORE_TOOLS_ASSERTION_2(nextBytesProcessed <= m_BytesTotal, "增量超过了缓冲区大小！\n");

		m_BytesProcessed = nextBytesProcessed;
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

CoreTools::BufferIO CoreTools::BufferIOImpl
	::GetBufferIOType() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_BufferIOType;
}

void CoreTools::BufferIOImpl
	::SetBytesProcessed(int bytesProcessed) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_BytesProcessed = bytesProcessed;
}

