// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:03)

#ifndef SYSTEM_HELPER_GL_ARB_ES_FLAGS_H
#define SYSTEM_HELPER_GL_ARB_ES_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
	enum class GLARBES2CompatibilityFlags
	{
		ClearDepthf,
		DepthRangef,
		GetShaderPrecisionFormat,
		ReleaseShaderCompiler,
		ShaderBinary,
	};

	enum class GLARBES3CompatibilityFlags
	{
		MemoryBarrierByRegion,
	};
}

#endif // SYSTEM_HELPER_GL_ARB_ES_FLAGS_H
