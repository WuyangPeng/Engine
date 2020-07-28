// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 13:14)

#ifndef CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_IMPL_H
#define CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/FrameMemorySystem/FrameMemorySystemPointerShare.h"
#include "CoreTools/FrameMemorySystem/Flags/FrameMemorySystemFlags.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE BaseFrameMemorySystemImpl : private boost::noncopyable
	{
	public:
		using ClassType = BaseFrameMemorySystemImpl;

	public:
		BaseFrameMemorySystemImpl(int sizeInBytes, int byteAlignment);
		~BaseFrameMemorySystemImpl() noexcept;
		BaseFrameMemorySystemImpl(const BaseFrameMemorySystemImpl&) = delete;
		BaseFrameMemorySystemImpl operator=(const BaseFrameMemorySystemImpl&) = delete;
		BaseFrameMemorySystemImpl(BaseFrameMemorySystemImpl&&) = delete;
		BaseFrameMemorySystemImpl operator=(BaseFrameMemorySystemImpl&&) = delete;

		CLASS_INVARIANT_DECLARE;

		const FrameMemorySystemPointerShare	AllocFrameMemory(int bytes, FrameMemorySystemHeap heapType);

		void ReleaseFrame(FrameMemorySystemPointerShare ptr);

	private:
		template<typename T>
		static int AlignUp(T sizeInBytes, int byteAlignment) noexcept;

		static int AlignUp(int sizeInBytes, int byteAlignment);
		void Init();

	private:
		static constexpr auto sm_PointerCount = System::EnumCastUnderlying(FrameMemorySystemHeap::Count);
		static constexpr auto sm_Lower = System::EnumCastUnderlying(FrameMemorySystemHeap::Lower);
		static constexpr auto sm_Upper = System::EnumCastUnderlying(FrameMemorySystemHeap::Upper);

	private:
		int m_SizeInBytes;
		// ���ֽ�Ϊ��λ���ڴ����
		int m_ByteAlignment;
		// ��malloc()���ص�ֵ
		uint8_t* m_MemoryBlock;
		// [0]=��ָ��, [1]=����ָ��
		uint8_t* m_BaseAndCapPointer[sm_PointerCount];
		// [0]=��ָ֡��, [1]=��ָ֡��
		uint8_t* m_FramePointer[sm_PointerCount];
	};
}

#endif // CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_IMPL_H