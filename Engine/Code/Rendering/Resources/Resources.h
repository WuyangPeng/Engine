///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:20)

#ifndef RENDERING_RENDERING_RESOURCES_H
#define RENDERING_RENDERING_RESOURCES_H

#include "Buffers/Buffer.h"
#include "Buffers/ConstantBufferDetail.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/IndirectArgumentsBuffer.h"
#include "Buffers/MemberLayout.h"
#include "Buffers/RawBuffer.h"
#include "Buffers/StructuredBuffer.h"
#include "Buffers/TextureBufferDetail.h"
#include "Buffers/TypedBuffer.h"
#include "Buffers/VertexBuffer.h"
#include "Buffers/VertexFormat.h"
#include "Buffers/VertexFormatAttribute.h"
#include "DataFormat.h"
#include "Resource.h"
#include "Textures/LoadTexture.h"
#include "Textures/SaveTexture.h"
#include "Textures/SubResource.h"
#include "Textures/Texture1D.h"
#include "Textures/Texture1DArray.h"
#include "Textures/Texture2D.h"
#include "Textures/Texture2DArray.h"
#include "Textures/Texture3D.h"
#include "Textures/TextureArray.h"
#include "Textures/TextureCube.h"
#include "Textures/TextureCubeArray.h"
#include "Textures/TextureDepthStencil.h"
#include "Textures/TextureRenderTarget.h"
#include "Textures/TextureSingle.h"

#include "Flags/ChannelType.h"
#include "Flags/CopyType.h"
#include "Flags/CounterType.h"
#include "Flags/CubeFaceType.h"
#include "Flags/DataFormatType.h"
#include "Flags/IndexFormat.h"
#include "Flags/UsageType.h"
#include "Flags/VertexFormatFlags.h"

#endif  // RENDERING_RENDERING_RESOURCES_H