// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 14:20)

#ifndef CORE_TOOLS_FILE_MANAGER_ENDIAN_H
#define CORE_TOOLS_FILE_MANAGER_ENDIAN_H

#include "CoreTools/CoreToolsDll.h"

// 字节存储顺序，结果将通过参数返回，调用者必须保持输入和输出数组的有效性。
namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Endian
	{
	public:
		// 测试机器的字节顺序是否是big endian。
		static bool IsBigEndian() noexcept;

		// 测试机器的字节顺序是否是little endian。
		static bool IsLittleEndian() noexcept;

		// 交换字节顺序
		static void Swap2ByteOrder(void* data) noexcept;
		static void Swap2ByteOrder(int itemsNumber, void* data) noexcept;
		static void Swap4ByteOrder(void* data) noexcept;
		static void Swap4ByteOrder(int itemsNumber, void* data) noexcept;
		static void Swap8ByteOrder(void* data) noexcept;
		static void Swap8ByteOrder(int itemsNumber, void* data) noexcept;

		static void SwapByteOrder(int itemSize, void* data) noexcept;
		static void SwapByteOrder(int itemSize, int itemsNumber, void* data) noexcept;

		static void Swap2ByteOrderToTarget(int itemsNumber, const uint16_t* source, uint16_t* target) noexcept;
		static void Swap4ByteOrderToTarget(int itemsNumber, const uint32_t* source, uint32_t* target) noexcept;
		static void Swap8ByteOrderToTarget(int itemsNumber, const uint64_t* source, uint64_t* target) noexcept;

	private:
		static const bool sm_IsLittleEndian;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_ENDIAN_H
