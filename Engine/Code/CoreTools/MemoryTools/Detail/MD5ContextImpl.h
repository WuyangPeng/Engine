// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:39)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_IMPL_H
#define CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/MemoryTools/MemoryToolsFwd.h"

#include <array>

namespace CoreTools
{ 
	class CORE_TOOLS_HIDDEN_DECLARE MD5ContextImpl
	{
	public:
		using ClassType = MD5ContextImpl;

	public:
		MD5ContextImpl();

		CLASS_INVARIANT_DECLARE;

		void MD5Init();

		// 允许多次调用MD5Update用于对多个数组进行更新
		void MD5Update(uint8_t const* buffer, uint32_t length);

		void MD5Final(uint8_t* digest);

	private:
		using CoreFunction = uint32_t(*)(uint32_t x, uint32_t y, uint32_t z);

	private:
		uint32_t UpdateBitCount();
		bool HandleOddSizedChunks(uint32_t originalLength);
		void ProcessDataIn64Byte();
		void InByteReverse();
		void BufferByteReverse();
		void MD5Transform();

		// 四大核心函数——CoreFunction1有所优化
		static uint32_t CoreFunction1(uint32_t x, uint32_t y, uint32_t z);
		static uint32_t CoreFunction2(uint32_t x, uint32_t y, uint32_t z);
		static uint32_t CoreFunction3(uint32_t x, uint32_t y, uint32_t z);
		static uint32_t CoreFunction4(uint32_t x, uint32_t y, uint32_t z);

		// 这是MD5主要的算法步骤
		static void MD5Step(CoreFunction function, uint32_t& w, uint32_t x, uint32_t y, uint32_t z, uint32_t data, uint32_t s);

	private:
		static constexpr auto sm_DealBufferByte = 64;
		static constexpr auto sm_BufferSize = 4;
		static constexpr auto sm_DealBufferSize = sm_DealBufferByte / sizeof(uint32_t);

		std::array<uint32_t, sm_BufferSize> m_Buffer;

		// 以64位二进制表示的填充前信息长度（单位为Bit），
		// 如果二进制表示的填充前信息长度超过64位，则取低64位。
		uint32_t m_LowBits;
		uint32_t m_HighBits;

		std::array<uint32_t, sm_DealBufferSize> m_In;

		uint8_t const* m_Source;
		uint32_t m_Length;

		MD5ContextStatus m_Status;
	};
}
#endif // CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_IMPL_H
