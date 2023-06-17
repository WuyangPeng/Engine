///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:20)

#ifndef RENDERING_RENDERING_RESOURCES_FWD_H
#define RENDERING_RENDERING_RESOURCES_FWD_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class DataFormat;
    class Resource;
    class Buffer;
    class MemberLayout;
    class ConstantBuffer;
    class IndirectArgumentsBuffer;
    class RawBuffer;
    class StructuredBuffer;
    class TextureBuffer;
    class TypedBuffer;
    class IndexBuffer;
    class VertexFormatAttribute;
    class VertexFormat;
    class VertexBuffer;

    enum class DataFormatType;
    enum class ChannelType;
    enum class UsageType;
    enum class CopyType;
    enum class IndexFormatType : uint32_t;
    enum class CounterType;
    enum class CubeFaceType;

    namespace VertexFormatFlags
    {
        enum class MaximumNumber;
        enum class Semantic;
    }

    class SubResource;
    class Texture;
    class TextureSingle;
    class Texture1D;
    class Texture2D;
    class TextureDepthStencil;
    class TextureRenderTarget;
    class Texture3D;
    class TextureArray;
    class Texture1DArray;
    class Texture2DArray;
    class TextureCube;
    class TextureCubeArray;
    class DrawTarget;

    class LoadTexture;
    class SaveTexture;

    enum class BufferUsage;
    enum class BufferLocking;
}

#endif  // RENDERING_RENDERING_RESOURCES_FWD_H