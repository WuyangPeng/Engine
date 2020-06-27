// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/07 23:34)

#ifndef SYSTEM_HELPER_GL_15_FLAGS_H
#define SYSTEM_HELPER_GL_15_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
	enum class GL15Flags
	{
		GenQueries,
		DeleteQueries,
		IsQuery,
		BeginQuery,
		EndQuery,
		GetQueryiv,
		GetQueryObjectiv,
		GetQueryObjectuiv,
		BindBuffer,
		DeleteBuffers,
		GenBuffers,
		IsBuffer,
		BufferData,
		BufferSubData,
		GetBufferSubData,
		MapBuffer,
		UnmapBuffer,
		GetBufferParameteriv,
		GetBufferPointerv,
	};
}

#endif // SYSTEM_HELPER_GL_15_FLAGS_H
