// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:13)

#ifndef CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_IMPL_DETAIL_H
#define CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_IMPL_DETAIL_H

#include "BaseFrameMemorySystemImpl.h"

// static
// private
template<typename T>
int CoreTools::BaseFrameMemorySystemImpl
	::AlignUp(T sizeInBytes, int byteAlignment) noexcept
{
	return (reinterpret_cast<size_t>(sizeInBytes) + byteAlignment - 1) & (~(byteAlignment - 1));
}

#endif // CORE_TOOLS_FRAME_MEMORY_SYSTEM_FRAME_MEMORY_SYSTEM_IMPL_DETAIL_H