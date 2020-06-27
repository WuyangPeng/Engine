// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 13:59)

#ifndef RENDERING_RENDERERS_RENDERER_TYPES_H
#define RENDERING_RENDERERS_RENDERER_TYPES_H

namespace Rendering
{
	enum class RendererTypes
    {
		First = 0,

		Default = First,
		Window = 1,
		Glut = 2,
		OpenGL = 3,
		OpenGLES = 4,
		Dx9 = 5,	
		Non,

		Max,
    };
}

#endif // RENDERING_RENDERERS_RENDERER_TYPES_H
