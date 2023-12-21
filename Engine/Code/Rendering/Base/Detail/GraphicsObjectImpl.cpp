/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:46)

#include "Rendering/RenderingExport.h"

#include "GraphicsObjectImpl.h"
#include "RendererObjectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/Base/RendererObjectBridge.h"

Rendering::GraphicsObjectImpl::GraphicsObjectImpl(GraphicsObjectType graphicsObjectType) noexcept
    : graphicsObjectType{ graphicsObjectType }, rendererObjectBridge{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GraphicsObjectImpl)

Rendering::GraphicsObjectImpl::RendererObjectBridgeSharedPtr Rendering::GraphicsObjectImpl::GetRendererObjectBridge()
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    auto result = rendererObjectBridge.lock();

    if (result == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("RendererObjectBridge指针已释放。"))
    }

    return result;
}

void Rendering::GraphicsObjectImpl::SetRendererObjectBridge(const RendererObjectBridgeSharedPtr& aRendererObjectBridge) noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    rendererObjectBridge = aRendererObjectBridge;
}

Rendering::GraphicsObjectType Rendering::GraphicsObjectImpl::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return graphicsObjectType;
}

void Rendering::GraphicsObjectImpl::SetGraphicsObjectType(GraphicsObjectType aGraphicsObjectType) noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    graphicsObjectType = aGraphicsObjectType;
}

bool Rendering::GraphicsObjectImpl::IsBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GraphicsObjectType::Buffer <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::IndirectArgumentsBuffer;
}

bool Rendering::GraphicsObjectImpl::IsTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GraphicsObjectType::TextureSingle <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::Texture3;
}

bool Rendering::GraphicsObjectImpl::IsTextureArray() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GraphicsObjectType::TextureArray <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::TextureCubeArray;
}

bool Rendering::GraphicsObjectImpl::IsShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GraphicsObjectType::Shader <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::ComputeShader;
}

bool Rendering::GraphicsObjectImpl::IsDrawingState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GraphicsObjectType::DrawingState <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::RasterizerState;
}

int Rendering::GraphicsObjectImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return CoreTools::GetStreamSize(graphicsObjectType);
}

void Rendering::GraphicsObjectImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteEnum(graphicsObjectType);
}

void Rendering::GraphicsObjectImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadEnum(graphicsObjectType);
}
