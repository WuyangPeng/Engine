// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 17:02)

#include "CoreTools/CoreToolsExport.h"

#include "WriteBufferIOImpl.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

#include <boost/numeric/conversion/cast.hpp>

CoreTools::WriteBufferIOImpl
	::WriteBufferIOImpl(int bytesTotal, char* buffer)
	:ParentType{ bytesTotal,BufferIO::Write }, m_Buffer{ buffer }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::WriteBufferIOImpl
	::~WriteBufferIOImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::WriteBufferIOImpl
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_Buffer != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const char* CoreTools::WriteBufferIOImpl
	::GetBuffer() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Buffer;
}

void CoreTools::WriteBufferIOImpl
	::Write(size_t itemSize, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

	WriteToBuffer(itemSize, 1, data);
}

void CoreTools::WriteBufferIOImpl
	::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

	WriteToBuffer(itemSize, itemsNumber, data);
}

uint32_t CoreTools::WriteBufferIOImpl
	::WriteToBuffer(size_t itemSize, size_t itemsNumber, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "准备读取的数据无效！");
	CORE_TOOLS_ASSERTION_2(GetBufferIOType() == BufferIO::Write, "缓冲区不支持写入！");

	auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);
	auto nextBytesProcessed = GetBytesProcessed() + numberToCopy;
	if (nextBytesProcessed <= GetBytesTotal())
	{
		// 获得缓冲区当前指针位置。
		auto target = m_Buffer + GetBytesProcessed();

		SetBytesProcessed(nextBytesProcessed);
		System::MemoryCopy(target, data, numberToCopy);

#ifdef SYSTEM_BIG_ENDIAN
		if (1 < itemSize)
		{
			Endian::SwapByteOrder(itemSize, itemsNumber, target);
		}
#endif // SYSTEM_BIG_ENDIAN		

		return numberToCopy;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("要写入的字节数超过了缓冲区大小！"));
	}
}
