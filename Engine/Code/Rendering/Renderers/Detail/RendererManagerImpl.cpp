// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/29 10:03)

#include "Rendering/RenderingExport.h"

#include "RendererManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Renderer.h"

#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Contract/Noexcept.h"

using std::string;

Rendering::RendererManagerImpl::RendererManagerImpl(MAYBE_UNUSED int count) noexcept
    : m_Renderers()
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererManagerImpl)

int64_t Rendering::RendererManagerImpl::Insert(RendererPtr ptr)
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& value : m_Renderers)
    {
        const auto& renderer = value.second.lock();
        if (renderer == ptr)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("重复插入渲染器，是否调用多次Init。"s));
        }
    }

    auto id = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Renderer);
    m_Renderers.insert({ id, ptr });

    return id;
}

bool Rendering::RendererManagerImpl::Erase(int64_t rendererID)
{
    RENDERING_CLASS_IS_VALID_9;

    return 0 < m_Renderers.erase(rendererID);
}

void Rendering::RendererManagerImpl::BindAll(VertexFormatConstPtr vertexFormat)
{
    RENDERING_CLASS_IS_VALID_9;

 //   if (SMART_POINTER_SINGLETON.IsSmartPointer(vertexFormat))
    {
        ConstVertexFormatSharedPtr pointer{ vertexFormat };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Bind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(VertexBufferConstPtr vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(vertexBuffer))
    {
        ConstVertexBufferSharedPtr pointer{ vertexBuffer };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Bind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(IndexBufferConstPtr indexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

 //   if (SMART_POINTER_SINGLETON.IsSmartPointer(indexBuffer))
    {
        ConstIndexBufferSharedPtr pointer{ indexBuffer };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Bind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(Texture1DConstPtr texture)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTexture1DSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Bind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(Texture2DConstPtr texture)
{
    RENDERING_CLASS_IS_VALID_9;

//    if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTexture2DSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Bind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(Texture3DConstPtr texture)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTexture3DSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Bind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(TextureCubeConstPtr texture)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTextureCubeSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Bind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(RenderTargetConstPtr renderTarget)
{
    RENDERING_CLASS_IS_VALID_9;

//    if (SMART_POINTER_SINGLETON.IsSmartPointer(renderTarget))
    {
        ConstRenderTargetSharedPtr pointer{ renderTarget };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Bind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::BindAll(VertexShaderConstPtr vertexShader)
{
    RENDERING_CLASS_IS_VALID_9;
    CoreTools::DisableNoexcept();

    // for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        vertexShader;
        //         auto renderer = *iter;
        //
        // 		if (renderer)
        // 		{
        // 			renderer->Bind(vertexShader);
        // 		}
    }
}

void Rendering::RendererManagerImpl::BindAll(PixelShaderConstPtr pixelShader)
{
    RENDERING_CLASS_IS_VALID_9;
    CoreTools::DisableNoexcept();
    //    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        pixelShader;
        //         RendererSharedPtr renderer = iter->lock();
        //
        //         if(renderer)
        //             renderer->Bind(pixelShader);
    }
}

void Rendering::RendererManagerImpl::UnbindAll(VertexFormatConstPtr vertexFormat)
{
    RENDERING_CLASS_IS_VALID_9;

    //if (SMART_POINTER_SINGLETON.IsSmartPointer(vertexFormat))
    {
        ConstVertexFormatSharedPtr pointer{ vertexFormat };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Unbind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(VertexBufferConstPtr vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;
  //  if (SMART_POINTER_SINGLETON.IsSmartPointer(vertexBuffer))
    {
        ConstVertexBufferSharedPtr pointer{ vertexBuffer };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Unbind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(IndexBufferConstPtr indexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

  //  if (SMART_POINTER_SINGLETON.IsSmartPointer(indexBuffer))
    {
        ConstIndexBufferSharedPtr pointer{ indexBuffer };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Unbind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(Texture1DConstPtr texture)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTexture1DSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Unbind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(Texture2DConstPtr texture)
{
    RENDERING_CLASS_IS_VALID_9;

  //  if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTexture2DSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Unbind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(Texture3DConstPtr texture)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTexture3DSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Unbind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(TextureCubeConstPtr texture)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTextureCubeSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Unbind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(RenderTargetConstPtr renderTarget)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(renderTarget))
    {
        ConstRenderTargetSharedPtr pointer{ renderTarget };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Unbind(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UnbindAll(VertexShaderConstPtr vertexShader)
{
    RENDERING_CLASS_IS_VALID_9;
    CoreTools::DisableNoexcept();
    //    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        vertexShader;
        //         RendererSharedPtr renderer = iter->lock();
        //
        //         if(renderer)
        //             renderer->Unbind(vertexShader);
    }
}

void Rendering::RendererManagerImpl::UnbindAll(PixelShaderConstPtr pixelShader)
{
    RENDERING_CLASS_IS_VALID_9;
    CoreTools::DisableNoexcept();
    //    for (auto iter = m_Renderers.begin(),end = m_Renderers.end();iter != end; ++iter)
    {
        pixelShader;
        //         RendererSharedPtr renderer = iter->lock();
        //
        //         if(renderer)
        //             renderer->Unbind(pixelShader);
    }
}

void Rendering::RendererManagerImpl::UpdateAll(VertexBufferConstPtr vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

  //  if (SMART_POINTER_SINGLETON.IsSmartPointer(vertexBuffer))
    {
        ConstVertexBufferSharedPtr pointer{ vertexBuffer };

        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Update(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(IndexBufferConstPtr indexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;
  //  if (SMART_POINTER_SINGLETON.IsSmartPointer(indexBuffer))
    {
        ConstIndexBufferSharedPtr pointer{ indexBuffer };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Update(pointer);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(Texture1DConstPtr texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

  //  if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTexture1DSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Update(pointer, level);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(Texture2DConstPtr texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTexture2DSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Update(pointer, level);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(Texture3DConstPtr texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTexture3DSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Update(pointer, level);
            }
        }
    }
}

void Rendering::RendererManagerImpl::UpdateAll(TextureCubeConstPtr texture, int face, int level)
{
    RENDERING_CLASS_IS_VALID_9;

   // if (SMART_POINTER_SINGLETON.IsSmartPointer(texture))
    {
        ConstTextureCubeSharedPtr pointer{ texture };
        const auto end = m_Renderers.end();
        for (auto iter = m_Renderers.begin(); iter != end; ++iter)
        {
            const auto& value = iter->second.lock();
            if (value)
            {
                value->Update(pointer, face, level);
            }
        }
    }
}
