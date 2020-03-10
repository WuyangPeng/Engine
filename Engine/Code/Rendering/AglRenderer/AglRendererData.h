// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 13:51)

#ifndef RENDERING_AGL_RENDERER_DATA_H
#define RENDERING_AGL_RENDERER_DATA_H

#include "Rendering/RenderingDll.h" 

#include "Rendering/OpenGLRenderer/OpenGLRendererData.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
//#include <AGL/agl.h>
//#include <Carbon/Carbon.h>
//#include <DrawSprocket/DrawSprocket.h>

namespace Rendering
{
	class Renderer;

	class AglRendererData : public RendererData
	{
	public:
		// Platform-dependent data.
		//AGLDevice mDevice;
		//WindowRef mWindow;
		//AGLDrawable mDrawable;
		//AGLContext mContext;
		//DSpContextReference mDSpContext;
		//GWorldPtr mBack;
		static System::OpenGLBoolean msDSpStarted;

		// Create a font.
		void LoadFont(const char* face, int size, bool fontBold,bool fontItalic);

		// Set up drawing area.
		void SetUpBufferRect(int winXPos, int winYPos, int winWidth,int winHeight);

		// Finalization after a context has been created.
		void Finalize(Renderer* renderer);

		// Display error message and terminate.
		void FatalErrorMessage(const char* message);
	};
}

#endif // RENDERING_AGL_RENDERER_DATA_H
