// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/24 17:04)

#include "Rendering/RenderingExport.h"

#include "ShaderManager.h"
#include "Detail/ShaderManagerImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(Rendering, ShaderManager);

Rendering::ShaderManager::ShaderManagerUniquePtr Rendering::ShaderManager
::sm_ShaderManager{ };

void Rendering::ShaderManager
::Create()
{
	sm_ShaderManager = make_unique<Rendering::ShaderManager>(ShaderManagerCreate::Init);
}

void Rendering::ShaderManager
::Destroy() noexcept
{
	sm_ShaderManager.reset();
}

Rendering::ShaderManager
::ShaderManager(ShaderManagerCreate shaderManagerCreate)
	:m_Impl{ make_shared<ImplType>() }
{
	SYSTEM_UNUSED_ARG(shaderManagerCreate);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, ShaderManager)


void Rendering::ShaderManager
    ::SetVertexProfile (VertexShaderProfile profile)
{    
    SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_Impl->SetVertexProfile(profile);
}

Rendering::ShaderManager::VertexShaderProfile Rendering::ShaderManager
    ::GetVertexProfile () const
{
    SINGLETON_MUTEX_ENTER_MEMBER;
    
	RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Impl->GetVertexProfile();
}

void Rendering::ShaderManager
    ::SetPixelProfile (PixelShaderProfile profile)
{    
    SINGLETON_MUTEX_ENTER_MEMBER;
    
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_Impl->SetPixelProfile(profile);
}

Rendering::ShaderManager::PixelShaderProfile Rendering::ShaderManager
    ::GetPixelProfile () const
{
    SINGLETON_MUTEX_ENTER_MEMBER;
    
	RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Impl->GetPixelProfile();
}