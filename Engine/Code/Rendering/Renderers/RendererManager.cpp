///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:50)

#include "Rendering/RenderingExport.h"

#include "RendererManager.h"
#include "Detail/RendererManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

SINGLETON_GET_PTR_DEFINE(Rendering, RendererManager);

Rendering::RendererManager::RendererManagerUniquePtr Rendering::RendererManager::rendererManager{};

void Rendering::RendererManager::Create()
{
    rendererManager = std::make_unique<Rendering::RendererManager>(RendererManagerCreate::Init);
}

void Rendering::RendererManager::Destroy() noexcept
{
    rendererManager.reset();
}

Rendering::RendererManager::RendererManager(MAYBE_UNUSED RendererManagerCreate rendererManagerCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererManager)

int64_t Rendering::RendererManager::Insert(RendererPtr ptr)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->Insert(ptr);
}

bool Rendering::RendererManager::Erase(int64_t rendererID)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->Erase(rendererID);
}

void Rendering::RendererManager::BindAll(const ConstVertexFormatSharedPtr& vertexFormat)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->BindAll(vertexFormat);
}

void Rendering::RendererManager::BindAll(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->BindAll(vertexBuffer);
}

void Rendering::RendererManager::BindAll(const ConstIndexBufferSharedPtr& indexBuffer)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->BindAll(indexBuffer);
}

void Rendering::RendererManager::BindAll(const ConstTexture1DSharedPtr& texture)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->BindAll(texture);
}

void Rendering::RendererManager::BindAll(const ConstTexture2DSharedPtr& texture)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->BindAll(texture);
}

void Rendering::RendererManager::BindAll(const ConstTexture3DSharedPtr& texture)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->BindAll(texture);
}

void Rendering::RendererManager::BindAll(const ConstTextureCubeSharedPtr& texture)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->BindAll(texture);
}

void Rendering::RendererManager::BindAll(const ConstDrawTargetSharedPtr& renderTarget)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->BindAll(renderTarget);
}

void Rendering::RendererManager::BindAll(const ConstVertexShaderSharedPtr& vertexShader)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->BindAll(vertexShader);
}

void Rendering::RendererManager::BindAll(const ConstPixelShaderSharedPtr& pixelShader)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->BindAll(pixelShader);
}

void Rendering::RendererManager::UnbindAll(const ConstVertexFormatSharedPtr& vertexFormat)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UnbindAll(vertexFormat);
}

void Rendering::RendererManager::UnbindAll(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UnbindAll(vertexBuffer);
}

void Rendering::RendererManager::UnbindAll(const ConstIndexBufferSharedPtr& indexBuffer)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UnbindAll(indexBuffer);
}

void Rendering::RendererManager::UnbindAll(const ConstTexture1DSharedPtr& texture)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UnbindAll(texture);
}

void Rendering::RendererManager::UnbindAll(const ConstTexture2DSharedPtr& texture)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UnbindAll(texture);
}

void Rendering::RendererManager::UnbindAll(const ConstTexture3DSharedPtr& texture)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UnbindAll(texture);
}

void Rendering::RendererManager::UnbindAll(const ConstTextureCubeSharedPtr& texture)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UnbindAll(texture);
}

void Rendering::RendererManager::UnbindAll(const ConstDrawTargetSharedPtr& renderTarget)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UnbindAll(renderTarget);
}

void Rendering::RendererManager::UnbindAll(const ConstVertexShaderSharedPtr& vertexShader)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UnbindAll(vertexShader);
}

void Rendering::RendererManager::UnbindAll(const ConstPixelShaderSharedPtr& pixelShader)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UnbindAll(pixelShader);
}

void Rendering::RendererManager::UpdateAll(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateAll(vertexBuffer);
}

void Rendering::RendererManager::UpdateAll(const ConstIndexBufferSharedPtr& indexBuffer)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateAll(indexBuffer);
}

void Rendering::RendererManager::UpdateAll(const ConstTexture1DSharedPtr& texture, int level)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateAll(texture, level);
}

void Rendering::RendererManager::UpdateAll(const ConstTexture2DSharedPtr& texture, int level)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateAll(texture, level);
}

void Rendering::RendererManager::UpdateAll(const ConstTexture3DSharedPtr& texture, int level)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateAll(texture, level);
}

void Rendering::RendererManager::UpdateAll(const ConstTextureCubeSharedPtr& texture, int face, int level)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateAll(texture, face, level);
}
