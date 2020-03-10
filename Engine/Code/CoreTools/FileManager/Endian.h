// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 14:20)

#ifndef CORE_TOOLS_FILE_MANAGER_ENDIAN_H
#define CORE_TOOLS_FILE_MANAGER_ENDIAN_H

#include "CoreTools/CoreToolsDll.h"

// �ֽڴ洢˳�򣬽����ͨ���������أ������߱��뱣�����������������Ч�ԡ�
namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Endian
	{
	public:
		// ���Ի������ֽ�˳���Ƿ���big endian��
		static bool IsBigEndian() noexcept;

		// ���Ի������ֽ�˳���Ƿ���little endian��
		static bool IsLittleEndian() noexcept;

		// �����ֽ�˳��
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
