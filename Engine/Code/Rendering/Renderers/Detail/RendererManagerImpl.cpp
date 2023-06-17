///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:44)

#include "Rendering/RenderingExport.h"

#include "RendererManagerImpl.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Renderer.h"

Rendering::RendererManagerImpl::RendererManagerImpl() noexcept
    : renderers{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererManagerImpl)

int64_t Rendering::RendererManagerImpl::Insert(const RendererSharedPtr& renderer)
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& value : renderers)
    {
        const auto& current = value.second.lock();
        if (current == renderer)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("重复插入渲染器，是否调用多次Init。"s));
        }
    }

    auto id = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Renderer);
    renderers.emplace(id, renderer);

    return id;
}

bool Rendering::RendererManagerImpl::Erase(int64_t rendererID)
{
    RENDERING_CLASS_IS_VALID_9;

    return 0 < renderers.erase(rendererID);
}

void Rendering::RendererManagerImpl::BindAll(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Bind(vertexFormat);
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Bind(vertexBuffer);
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(const ConstIndexBufferSharedPtr& indexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Bind(indexBuffer);
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(const ConstTexture1DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Bind(texture);
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(const ConstTexture2DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Bind(texture);
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(const ConstTexture3DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Bind(texture);
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(const ConstTextureCubeSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Bind(texture);
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Bind(renderTarget);
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(const ConstVertexShaderSharedPtr& vertexShader)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Bind(vertexShader);
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(const ConstPixelShaderSharedPtr& pixelShader)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Bind(pixelShader);
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Unbind(vertexFormat);
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Unbind(vertexBuffer);
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(const ConstIndexBufferSharedPtr& indexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Unbind(indexBuffer);
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(const ConstTexture1DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Unbind(texture);
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(const ConstTexture2DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Unbind(texture);
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(const ConstTexture3DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Unbind(texture);
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(const ConstTextureCubeSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Unbind(texture);
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Unbind(renderTarget);
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(const ConstVertexShaderSharedPtr& vertexShader)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Unbind(vertexShader);
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(const ConstPixelShaderSharedPtr& pixelShader)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Unbind(pixelShader);
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Update(vertexBuffer);
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(const ConstIndexBufferSharedPtr& indexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Update(indexBuffer);
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(const ConstTexture1DSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Update(texture, level);
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(const ConstTexture2DSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Update(texture, level);
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(const ConstTexture3DSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Update(texture, level);
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(const ConstTextureCubeSharedPtr& texture, int face, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = renderers.begin(); iter != renderers.end(); ++iter)
    {
        const auto& value = iter->second.lock();
        if (value)
        {
            value->Update(texture, face, level);
        }
    }
}
