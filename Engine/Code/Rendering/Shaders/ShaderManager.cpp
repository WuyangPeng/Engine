///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:53)

#include "Rendering/RenderingExport.h"

#include "ShaderManager.h"
#include "Detail/ShaderManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

SINGLETON_GET_PTR_DEFINE(Rendering, ShaderManager);

Rendering::ShaderManager::ShaderManagerUniquePtr Rendering::ShaderManager::shaderManager{};

void Rendering::ShaderManager::Create()
{
    shaderManager = std::make_unique<Rendering::ShaderManager>(ShaderManagerCreate::Init);
}

void Rendering::ShaderManager::Destroy() noexcept
{
    shaderManager.reset();
}

Rendering::ShaderManager::ShaderManager(MAYBE_UNUSED ShaderManagerCreate shaderManagerCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderManager)

void Rendering::ShaderManager::SetVertexProfile(VertexShaderProfile profile)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVertexProfile(profile);
}

Rendering::ShaderManager::VertexShaderProfile Rendering::ShaderManager::GetVertexProfile() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertexProfile();
}

void Rendering::ShaderManager::SetPixelProfile(PixelShaderProfile profile)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPixelProfile(profile);
}

Rendering::ShaderManager::PixelShaderProfile Rendering::ShaderManager::GetPixelProfile() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPixelProfile();
}