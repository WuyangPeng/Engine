// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 13:52)

#ifndef RENDERING_GLUT_RENDERER_INPUT_H
#define RENDERING_GLUT_RENDERER_INPUT_H

#include "Rendering/RenderingDll.h" 

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#ifdef WIN32
// The glut.h has unreference local functions glutInit_ATEXIT_HACK,
// glutCreateWindow_ATEXIT_HACK, and glutCreateMenu_ATEXIT_HACK.
// Disable the warnings about these.
#pragma warning(disable : 4505)
#endif
//#include "WglExtensions.h"
#include <GL/glut.h>
#endif

namespace Rendering
{

	class GlutRendererInput
	{
	public:
		int mWindowID;
		bool mDisableVerticalSync;
	};

}

#endif // RENDERING_GLUT_RENDERER_INPUT_H
