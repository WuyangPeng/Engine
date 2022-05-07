///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/13 15:48)

#include "Rendering/RenderingExport.h"

#include "ShaderManager.h"
#include "Detail/ShaderManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(Rendering, ShaderManager);

Rendering::ShaderManager::ShaderManagerUniquePtr Rendering::ShaderManager::shaderManager{};

void Rendering::ShaderManager::Create()
{
    shaderManager = make_unique<Rendering::ShaderManager>(ShaderManagerCreate::Init);
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