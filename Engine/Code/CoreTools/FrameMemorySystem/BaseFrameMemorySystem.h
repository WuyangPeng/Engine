// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:15)

#ifndef CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_H
#define CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "FrameMemorySystemFwd.h"
#include "FrameMemorySystemPointerShare.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(BaseFrameMemorySystemImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE BaseFrameMemorySystem : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(BaseFrameMemorySystem);

	public:
		BaseFrameMemorySystem(int sizeInBytes, int byteAlignment);

		CLASS_INVARIANT_DECLARE;

		const FrameMemorySystemPointerShare	AllocFrameMemory(int bytes, FrameMemorySystemHeap heapType);

		void ReleaseFrame(FrameMemorySystemPointerShare ptr);

	private:
		IMPL_TYPE_DECLARE(BaseFrameMemorySystem);
	};
}

#endif // CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_H