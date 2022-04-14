///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/01 10:57)

#include "Rendering/RenderingExport.h"

#include "CameraManager.h"
#include "Detail/CameraManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;
using std::string;

SINGLETON_GET_PTR_DEFINE(Rendering, CameraManager);

Rendering::CameraManager::CameraManagerUniquePtr Rendering::CameraManager::cameraManager{};

void Rendering::CameraManager::Create()
{
    cameraManager = make_unique<Rendering::CameraManager>(CameraManagerCreate::Init);
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