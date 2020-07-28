// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 17:07)

#include "CoreTools/CoreToolsExport.h"

#include "Endian.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <algorithm>

using std::swap;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
namespace
{
	int g_One{ 1 };
}

const bool CoreTools::Endian
	::sm_IsLittleEndian{ (*reinterpret_cast<char*>(&g_One) != 0) };

bool CoreTools::Endian
	::IsBigEndian() noexcept
{
	return !IsLittleEndian();
}

bool CoreTools::Endian
	::IsLittleEndian() noexcept
{
	return sm_IsLittleEndian;
}

void CoreTools::Endian
	::Swap2ByteOrder(void* data) noexcept
{
	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(data != nullptr,"指针无效！");

		auto bytes = static_cast<char*>(data);

		if (bytes != nullptr)
		{
			swap(bytes[0], bytes[1]);
		}
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::Endian
	::Swap2ByteOrder(int itemsNumber, void* data) noexcept
{
	EXCEPTION_TRY
	{
		constexpr auto step = 2;
		CORE_TOOLS_ASSERTION_0(data != nullptr,"指针无效！");
		CORE_TOOLS_ASSERTION_2(0 < itemsNumber,"itemsNumber必须大于零！");

		auto bytes = static_cast<char*>(data);

		for (auto i = 0; i < itemsNumber; ++i)
		{
			Swap2ByteOrder(bytes);
			bytes += step;
		}
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::Endian
	::Swap4ByteOrder(void* data) noexcept
{
	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(data != nullptr,"指针无效！");

		auto bytes = static_cast<char*>(data);

		if (bytes != nullptr)
		{
			swap(bytes[0], bytes[3]);
			swap(bytes[1], bytes[2]);
		}
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::Endian
	::Swap4ByteOrder(int itemsNumber, void* data) noexcept
{
	EXCEPTION_TRY
	{
		constexpr auto step = 4;

		CORE_TOOLS_ASSERTION_0(data != nullptr,"指针无效！");
		CORE_TOOLS_ASSERTION_2(0 < itemsNumber,"itemsNumber必须大于零！");

		auto bytes = static_cast<char*>(data);

		for (auto i = 0; i < itemsNumber; ++i)
		{
			Swap4ByteOrder(bytes);
			bytes += step;
		}
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::Endian
	::Swap8ByteOrder(void* data) noexcept
{
	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(data != nullptr,"指针无效！");

		auto bytes = static_cast<char*>(data);

		if (bytes != nullptr)
		{
			swap(bytes[0], bytes[7]);
			swap(bytes[1], bytes[6]);
			swap(bytes[2], bytes[5]);
			swap(bytes[3], bytes[4]);
		}
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::Endian
	::Swap8ByteOrder(int itemsNumber, void* data) noexcept
{
	EXCEPTION_TRY
	{
		constexpr auto step = 8;

		CORE_TOOLS_ASSERTION_0(data != nullptr,"指针无效！");
		CORE_TOOLS_ASSERTION_2(0 < itemsNumber,"itemsNumber必须大于零！");

		auto bytes = static_cast<char*>(data);

		for (auto i = 0; i < itemsNumber; ++i)
		{
			Swap8ByteOrder(bytes);
			bytes += step;
		}
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::Endian
	::SwapByteOrder(int itemSize, void* data) noexcept
{
	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(data != nullptr,"指针无效！");
		CORE_TOOLS_ASSERTION_2(itemSize == 2 || itemSize == 4 || itemSize == 8,"大小必须为2，4或8\n");

		const auto halfSize = itemSize / 2;
		auto bytes = static_cast<char*>(data);

		for (auto begin = 0,end = itemSize - 1; begin < halfSize; ++begin,--end)
		{
			if (bytes != nullptr)
			{
				swap(bytes[begin], bytes[end]);
			}
		}
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::Endian
	::SwapByteOrder(int itemSize, int itemsNumber, void* data) noexcept
{
	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(data != nullptr,"指针无效！");
		CORE_TOOLS_ASSERTION_2(0 < itemsNumber,"itemsNumber必须大于零！");
		CORE_TOOLS_ASSERTION_2(itemSize == 2 || itemSize == 4 || itemSize == 8,"大小必须为2，4或8\n");

		auto bytes = static_cast<char*>(data);

		for (auto i = 0; i < itemsNumber; ++i)
		{
			SwapByteOrder(itemSize,bytes);
			bytes += itemSize;
		}
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::Endian
	::Swap2ByteOrderToTarget(int itemsNumber, const uint16_t* source, uint16_t* target) noexcept
{
	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(source != nullptr,"指针无效！");
		CORE_TOOLS_ASSERTION_2(0 < itemsNumber,"itemsNumber必须大于零！");
		CORE_TOOLS_ASSERTION_0(target != nullptr,"指针无效！");

		System::MemoryCopy(target, source, itemsNumber * sizeof(uint16_t));

		Endian::Swap2ByteOrder(itemsNumber,target);
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::Endian
	::Swap4ByteOrderToTarget(int itemsNumber, const uint32_t* source, uint32_t* target) noexcept
{
	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(source != nullptr,"指针无效！");
		CORE_TOOLS_ASSERTION_2(0 < itemsNumber,"itemsNumber必须大于零！");
		CORE_TOOLS_ASSERTION_0(target != nullptr,"指针无效！");

		System::MemoryCopy(target, source, itemsNumber * sizeof(uint32_t));

		Endian::Swap4ByteOrder(itemsNumber,target);
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::Endian
	::Swap8ByteOrderToTarget(int itemsNumber, const uint64_t* source, uint64_t* target) noexcept
{
	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(source != nullptr,"指针无效！");
		CORE_TOOLS_ASSERTION_2(0 < itemsNumber,"itemsNumber必须大于零！");
		CORE_TOOLS_ASSERTION_0(target != nullptr,"指针无效！");

		System::MemoryCopy(target, source, itemsNumber * sizeof(uint64_t));

		Endian::Swap8ByteOrder(itemsNumber,target);
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

#include STSTEM_WARNING_POP