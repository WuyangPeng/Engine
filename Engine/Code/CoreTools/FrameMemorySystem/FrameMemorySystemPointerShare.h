// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:15)

#ifndef CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_POINTER_SHARE_H
#define CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_POINTER_SHARE_H

#include "CoreTools/CoreToolsDll.h"

#include "FrameMemorySystemFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(FrameMemorySystemPointerShareImpl);

namespace CoreTools
{
	// π≤œÌ¿‡
	class CORE_TOOLS_DEFAULT_DECLARE FrameMemorySystemPointerShare
	{
	public:
		SHARE_CLASSES_TYPE_DECLARE(FrameMemorySystemPointerShare);

	public:
		FrameMemorySystemPointerShare(uint8_t* ptr, int size, uint8_t*& lowerFramePointer, uint8_t*& upperFramePointer, FrameMemorySystemHeap type);

		CLASS_INVARIANT_DECLARE;

		const uint8_t* GetFramePointer() const;
		uint8_t* GetFramePointer();
		int GetPtrSize() const noexcept;
		FrameMemorySystemHeap GetFrameMemorySystemHeapType() const noexcept;

	private:
		IMPL_TYPE_DECLARE(FrameMemorySystemPointerShare);
	};
}

#endif // CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_POINTER_SHARE_H