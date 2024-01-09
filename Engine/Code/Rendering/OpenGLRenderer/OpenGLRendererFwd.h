/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/06 11:24)

#ifndef RENDERING_OPENGL_RENDERER_FWD_H
#define RENDERING_OPENGL_RENDERER_FWD_H

namespace Rendering
{
    class OpenGLRendererObject;

    class OpenGLBlendState;
    class OpenGLBlendStateTarget;
    class OpenGLDepthStencilState;
    class OpenGLDepthStencilStateFace;
    class OpenGLDrawingState;
    class OpenGLRasterizerState;
    class OpenGLSamplerState;

    class OpenGLAtomicCounterBuffer;
    class OpenGLBuffer;
    class OpenGLConstantBuffer;
    class OpenGLIndexBuffer;
    class OpenGLStructuredBuffer;
    class OpenGLVertexBuffer;

    class OpenGLDrawTarget;
    class OpenGLTexture;
    class OpenGLTexture1;
    class OpenGLTexture1Array;
    class OpenGLTexture2;
    class OpenGLTexture2Array;
    class OpenGLTexture3;
    class OpenGLTextureArray;
    class OpenGLTextureCube;
    class OpenGLTextureCubeArray;
    class OpenGLTextureDepthStencil;
    class OpenGLTextureRenderTarget;
    class OpenGLTextureSingle;

    class OpenGLInputLayout;
    class OpenGLInputLayoutAttribute;
    class OpenGLInputLayoutManager;

}

#endif  // RENDERING_OPENGL_RENDERER_FWD_H