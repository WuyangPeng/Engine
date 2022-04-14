///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 17:13)

#ifndef RENDERING_RENDERING_RESOURCES_FWD_H
#define RENDERING_RENDERING_RESOURCES_FWD_H

namespace Rendering
{
    class Buffer;
    class IndexBuffer;
    class VertexBuffer;
    class Texture;
    class Texture1D;
    class Texture2D;
    class Texture3D;
    class TextureCube;
    class LoadTexture;
    class SaveTexture;
    class RenderTarget;
    class VertexFormatType;
    class VertexFormatElement;
    class VertexFormat;
    class VertexBufferAccessor;

    enum class BufferUsage;
    enum class BufferLocking;
}

#endif  // RENDERING_RENDERING_RESOURCES_FWD_H