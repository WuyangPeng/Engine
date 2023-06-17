///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:16)

#include "Rendering/RenderingExport.h"

#include "CameraManager.h"
#include "Detail/CameraManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

SINGLETON_GET_PTR_DEFINE(Rendering, CameraManager);

Rendering::CameraManager::CameraManagerUniquePtr Rendering::CameraManager::cameraManager{};

void Rendering::CameraManager::Create()
{
    cameraManager = std::make_unique<Rendering::CameraManager>(CameraManagerCreate::Init);
}

void Rendering::CameraManager::Destroy() noexcept
{
    cameraManager.reset();
}

Rendering::CameraManager::CameraManager(MAYBE_UNUSED CameraManagerCreate cameraManagerCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CameraManager)

void Rendering::CameraManager::SetDefaultDepthType(RendererTypes type)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    impl->SetDefaultDepthType(type);
}

Rendering::DepthType Rendering::CameraManager::GetDepthType() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDepthType();
}