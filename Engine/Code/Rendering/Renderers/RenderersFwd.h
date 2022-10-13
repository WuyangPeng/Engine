///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/05 14:44)

#ifndef RENDERING_RENDERERS_FWD_H
#define RENDERING_RENDERERS_FWD_H

#include <memory>

namespace Rendering
{
    class RendererBasis;
    class WindowsParameter;
    class RendererParameter;
    class EnvironmentParameter;
    class RenderingEnvironment;
    class RenderingDevice;

    class PlatformVertexFormat;
    class VertexFormatManagement;
    class PlatformIndexBuffer;
    class PlatformVertexBuffer;

    template <typename PlatformBufferType>
    class BufferLockManager;

    template <typename PlatformBufferType>
    class BufferManagement;

    template <typename BufferManagementType>
    class BufferManagementLockEncapsulation;

    class PlatformTexture1D;
    class PlatformTexture2D;
    class PlatformTexture3D;
    class PlatformTextureCube;

    template <typename PlatformTextureType>
    class TextureLockManager;

    template <typename TextureManagementType>
    class TextureManagementLockEncapsulation;

    template <typename PlatformTextureType>
    class TextureManagement;

    class PlatformRenderTarget;
    class RenderTargetManagement;

    enum class RendererTypes;

    class Renderer;

    class SamplerState;
    class RendererInput;

    class Font;
    class BlendState;
    class DepthStencilState;
    class RasterizerState;
}

#endif  // RENDERING_RENDERERS_FWD_H