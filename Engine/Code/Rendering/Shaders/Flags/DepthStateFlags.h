// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 13:49)

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
