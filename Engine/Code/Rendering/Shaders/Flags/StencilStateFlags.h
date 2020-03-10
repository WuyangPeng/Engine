// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 13:56)

#ifndef RENDERING_SHADERS_STENCIL_STATE_FLAGS_H
#define RENDERING_SHADERS_STENCIL_STATE_FLAGS_H

namespace Rendering
{
	namespace StencilStateFlags
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

		enum class OperationType
		{
			Keep,
			Zero,
			Replace,
			Increment,
			Decrement,
			Invert,
			Quantity
		};
	}    
}

#endif // RENDERING_SHADERS_STENCIL_STATE_FLAGS_H
