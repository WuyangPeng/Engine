// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:15)

#ifndef CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_POINTER_SHARE_IMPL_H
#define CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_POINTER_SHARE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FrameMemorySystem/Flags/FrameMemorySystemFlags.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE FrameMemorySystemPointerShareImpl : private boost::noncopyable
	{
	public:
		using ClassType = FrameMemorySystemPointerShareImpl;

	public:
		FrameMemorySystemPointerShareImpl(uint8_t* ptr, int size, uint8_t*& lowerFramePointer, uint8_t*& upperFramePointer, FrameMemorySystemHeap type) noexcept;

		CLASS_INVARIANT_DECLARE;

		uint8_t* GetFramePointer();
		const uint8_t* GetFramePointer() const;
		int GetPtrSize() const noexcept;
		FrameMemorySystemHeap GetFrameMemorySystemHeapType() const noexcept;

	private:
		uint8_t* m_Ptr;
		int m_Size;
		uint8_t*& m_LowerFramePointer;
		uint8_t*& m_UpperFramePointer;
		FrameMemorySystemHeap m_Type;
	};
}

#endif // CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_POINTER_SHARE_IMPL_H