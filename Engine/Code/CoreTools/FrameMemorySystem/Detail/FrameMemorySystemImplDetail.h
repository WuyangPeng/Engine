// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:13)

#ifndef CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_IMPL_DETAIL_H
#define CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_IMPL_DETAIL_H

#include "BaseFrameMemorySystemImpl.h"

#include "System/Helper/PragmaWarning.h"

// static
// private
template<typename T>
int CoreTools::BaseFrameMemorySystemImpl
	::AlignUp(T sizeInBytes, int byteAlignment) noexcept
{
#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26490)
	return (reinterpret_cast<size_t>(sizeInBytes) + byteAlignment - 1) & (~(byteAlignment - 1));
#include STSTEM_WARNING_POP
}

#endif // CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_IMPL_DETAIL_H