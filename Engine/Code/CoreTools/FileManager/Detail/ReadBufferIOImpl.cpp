// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 16:56)

#include "CoreTools/CoreToolsExport.h"

#include "ReadBufferIOImpl.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using namespace std::literals;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

CoreTools::ReadBufferIOImpl
	::ReadBufferIOImpl(int bytesTotal, const char* buffer) noexcept
	:ParentType{ bytesTotal,BufferIO::Read }, m_Buffer{ buffer }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
 
#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ReadBufferIOImpl
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_Buffer != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const char* CoreTools::ReadBufferIOImpl
	::GetBuffer() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_Buffer;
}

void CoreTools::ReadBufferIOImpl
	::Read(size_t itemSize, void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

	ReadFromBuffer(itemSize, 1, data);
}

void CoreTools::ReadBufferIOImpl
	::Read(size_t itemSize, size_t itemsNumber, void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

	ReadFromBuffer(itemSize, itemsNumber, data);
}

int CoreTools::ReadBufferIOImpl
	::ReadFromBuffer(size_t itemSize, size_t itemsNumber, void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "准备写入的数据无效！");
	CORE_TOOLS_ASSERTION_2(GetBufferIOType() == BufferIO::Read, "缓冲区不支持读取！");

	auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);
	auto nextBytesProcessed = GetBytesProcessed() + numberToCopy;
	if (nextBytesProcessed <= GetBytesTotal())
	{
		// 获得缓冲区当前指针位置。
		auto source = m_Buffer + GetBytesProcessed();

		SetBytesProcessed(nextBytesProcessed);

		System::MemoryCopy(data, source, numberToCopy);

#ifdef SYSTEM_BIG_ENDIAN
		if (1 < itemSize)
		{
			Endian::SwapByteOrder(itemSize, itemsNumber, data);
		}
#endif // SYSTEM_BIG_ENDIAN	

		return numberToCopy;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("要读取的字节数超过了缓冲区大小！"s));
	}
}


#include STSTEM_WARNING_POP