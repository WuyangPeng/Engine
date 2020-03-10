// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 13:49)

#ifndef RENDERING_SHADERS_DEPTH_STATE_FLAGS_H
#define RENDERING_SHADERS_DEPTH_STATE_FLAGS_H

namespace Rendering
{
	namespace DepthStateFlags
	{
		enum class CompareMode
		{
			Never,
			Less,
			Equal,
			LessEqual,
			Greater,
			NotEqual,
			GreaterEqual,
			Always,
			Quantity
		};
	}    
}

#endif // RENDERING_SHADERS_DEPTH_STATE_FLAGS_H
