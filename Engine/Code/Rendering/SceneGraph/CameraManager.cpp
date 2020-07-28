// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/22 17:22)

#include "Rendering/RenderingExport.h"

#include "CameraManager.h"
#include "Detail/CameraManagerImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(Rendering, CameraManager);

Rendering::CameraManager::CameraManagerUniquePtr Rendering::CameraManager
::sm_CameraManager{ };

void Rendering::CameraManager
::Create()
{
	sm_CameraManager = make_unique<Rendering::CameraManager>(CameraManagerCreate::Init);
}

void Rendering::CameraManager
::Destroy() noexcept
{
	sm_CameraManager.reset();
}

Rendering::CameraManager
::CameraManager(CameraManagerCreate cameraManagerCreate)
	:m_Impl{ make_shared<ImplType>() }
{
	SYSTEM_UNUSED_ARG(cameraManagerCreate);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, CameraManager)

void Rendering::CameraManager
	::SetDefaultDepthType(RendererTypes type)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->SetDefaultDepthType(type);
}

Rendering::DepthType Rendering::CameraManager
	::GetDepthType() const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetDepthType();
}