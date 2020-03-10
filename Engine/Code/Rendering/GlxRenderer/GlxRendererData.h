// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 13:52)
#ifndef RENDERING_GLX_RENDERER_GLX_RENDERER_DATA_H
#define RENDERING_GLX_RENDERER_GLX_RENDERER_DATA_H

#include "Rendering/RenderingDll.h" 

#include "Rendering/OpenGLRenderer/OpenGLRendererData.h"
//#include "GlxExtensions.h"

namespace Rendering
{

	class Renderer;

	class GlxRendererData : public RendererData
	{
	public:
		// Platform-dependent data.
		//Display* mDisplay;
		//XVisualInfo* mVisual;
		//Window mWindow;
		//GLXContext mContext;

		//bool FinishConstruction (Window window, Renderer* renderer);
	};

}

#endif // RENDERING_GLX_RENDERER_GLX_RENDERER_DATA_H
