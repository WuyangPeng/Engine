// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:01)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_RENDERER_DATA_H
#define RENDERING_OPENGL_RENDERER_OPENGL_RENDERER_DATA_H

#include "Rendering/RenderingDll.h"

#include "OpenGLBitmapFont.h"
#include "System/Helper/GLExtensionsMacro.h"
#include "Mathematics/Base/Float.h"

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
            int mQuantity = 0;  // number of display lists, input to glGenLists
            int mStart = 0;  // start index, output from glGenLists
            int mBase = 0;  // base index for glListBase
        };

        DisplayListInfo mFont;
#else  // !RENDERING_USE_TEXT_DISPLAY_LIST \
    // Bitmapped fonts/characters.
        void DrawCharacter(const BitmapFont& font, char c);
#endif  // RENDERING_USE_TEXT_DISPLAY_LIST

        // Maintain current render states to avoid redundant state changes.
        class RenderState
        {
        public:
            RenderState() noexcept;
            void Initialize(const AlphaState* astate, const CullState* cstate, const DepthState* dstate,
                            const OffsetState* ostate, const StencilState* sstate, const WireState* wstate);

            // AlphaState
            bool mAlphaBlendEnabled = false;
            GLenum mAlphaSrcBlend = 0;
            GLenum mAlphaDstBlend = 0;
            bool mAlphaCompareEnabled = false;
            GLenum mCompareFunction = 0;
            float mAlphaReference = 0.0f;
            Mathematics::Float4 mBlendColor;

            // CullState
            bool mCullEnabled = false;
            bool mCCWOrder = false;

            // DepthState
            bool mDepthEnabled = false;
            bool mDepthWriteEnabled = false;
            GLenum mDepthCompareFunction = 0;

            // OffsetState
            bool mFillEnabled = false;
            bool mLineEnabled = false;
            bool mPointEnabled = false;
            float mOffsetScale = 0.0f;
            float mOffsetBias = 0.0f;

            // StencilState
            bool mStencilEnabled = 0.0f;
            GLenum mStencilCompareFunction = 0;
            GLuint mStencilReference = 0;
            GLuint mStencilMask = 0;
            GLuint mStencilWriteMask = 0;
            GLenum mStencilOnFail = 0;
            GLenum mStencilOnZFail = 0;
            GLenum mStencilOnZPass = 0;

            // WireState
            bool mWireEnabled = false;
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
            SamplerState();

            // Get the state of the currently enabled texture.  This state appears
            // to be associated with the OpenGL texture object.  How does this
            // relate to the sampler state?  In my opinion, OpenGL needs to have
            // the sampler state separate from the texture object state.
            void GetCurrent(GLenum target);

            float mAnisotropy = false;
            float mLodBias = false;
            GLint mMagFilter = 0;
            GLint mMinFilter = 0;
            Mathematics::Float4 mBorderColor;
            GLint mWrap[3]{};
        };

        SamplerState mCurrentSS[MAX_NUM_PSAMPLERS];

        // Capabilities (queried at run time).
        int mMaxVShaderImages = 0;
        int mMaxPShaderImages = 0;
        int mMaxCombinedImages = 0;
    };

}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_RENDERER_DATA_H
