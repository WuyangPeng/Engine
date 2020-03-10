// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:01)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_RENDERER_DATA_H
#define RENDERING_OPENGL_RENDERER_OPENGL_RENDERER_DATA_H

#include "Rendering/RenderingDll.h"

#include "OpenGLBitmapFont.h" 
#include "Mathematics/Base/Float4.h"
#include "System/OpenGL/Using/Gl11ExtensionsUsing.h"

namespace Rendering
{

	class AlphaState;
	class CullState;
	class DepthState;
	class OffsetState;
	class StencilState;
	class WireState;

	class RendererData
	{
	public:
	#ifdef RENDERING_USE_TEXT_DISPLAY_LIST
		// Display list base indices for fonts/characters.
		class DisplayListInfo
		{
		public:
			int mQuantity;  // number of display lists, input to glGenLists
			int mStart;     // start index, output from glGenLists
			int mBase;      // base index for glListBase
		};

		DisplayListInfo mFont;
	#else // !RENDERING_USE_TEXT_DISPLAY_LIST
		// Bitmapped fonts/characters.
		void DrawCharacter (const BitmapFont& font, char c);
	#endif // RENDERING_USE_TEXT_DISPLAY_LIST

		// Maintain current render states to avoid redundant state changes.
		class RenderState
		{
		public:
			RenderState ();
			void Initialize (const AlphaState* astate,const CullState* cstate, const DepthState* dstate,
							 const OffsetState* ostate, const StencilState* sstate, const WireState* wstate);

			// AlphaState
			bool mAlphaBlendEnabled;
			GLenum mAlphaSrcBlend;
			GLenum mAlphaDstBlend;
			bool mAlphaCompareEnabled;
			GLenum mCompareFunction;
			float mAlphaReference;
			Mathematics::Float4 mBlendColor;

			// CullState
			bool mCullEnabled;
			bool mCCWOrder;

			// DepthState
			bool mDepthEnabled;
			bool mDepthWriteEnabled;
			GLenum mDepthCompareFunction;

			// OffsetState
			bool mFillEnabled;
			bool mLineEnabled;
			bool mPointEnabled;
			float mOffsetScale;
			float mOffsetBias;

			// StencilState
			bool mStencilEnabled;
			GLenum mStencilCompareFunction;
			GLuint mStencilReference;
			GLuint mStencilMask;
			GLuint mStencilWriteMask;
			GLenum mStencilOnFail;
			GLenum mStencilOnZFail;
			GLenum mStencilOnZPass;

			// WireState
			bool mWireEnabled;
		};

		RenderState mCurrentRS;

		// Maintain current sampler states to avoid redundant state changes.
		enum
		{
			MAX_NUM_VSAMPLERS = 4,  // VSModel 3 has 4, VSModel 2 has 0.
			MAX_NUM_PSAMPLERS = 16  // PSModel 2 and PSModel 3 have 16.
		};

		class SamplerState
		{
		public:
			SamplerState ();

			// Get the state of the currently enabled texture.  This state appears
			// to be associated with the OpenGL texture object.  How does this
			// relate to the sampler state?  In my opinion, OpenGL needs to have
			// the sampler state separate from the texture object state.
			void GetCurrent (GLenum target);

			float mAnisotropy;
			float mLodBias;
			GLint mMagFilter;
			GLint mMinFilter;
			Mathematics::Float4 mBorderColor;
			GLint mWrap[3];
		};

		SamplerState mCurrentSS[MAX_NUM_PSAMPLERS];

		// Capabilities (queried at run time).
		int mMaxVShaderImages;
		int mMaxPShaderImages;
		int mMaxCombinedImages;
	};

}

#endif // RENDERING_OPENGL_RENDERER_OPENGL_RENDERER_DATA_H
