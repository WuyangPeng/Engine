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

SINGLETON_MUTEX_DEFINE(Rendering, ShaderManager);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ GetRenderingMutex() }

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_ShaderManagerMutex }

SINGLETON_INITIALIZE_DEFINE(Rendering,ShaderManager)

Rendering::ShaderManager
    ::ShaderManager()
	:m_Impl{ make_shared<ImplType>() }
{
	MUTEX_ENTER_MEMBER;
    
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderManager
    ::~ShaderManager()
{
	MUTEX_ENTER_MEMBER;
    
	RENDERING_SELF_CLASS_IS_VALID_1;
}


#ifdef OPEN_CLASS_INVARIANT
bool Rendering::ShaderManager
    ::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;
    
	if(m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::ShaderManager
    ::SetVertexProfile (VertexShaderProfile profile)
{    
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_Impl->SetVertexProfile(profile);
}

Rendering::ShaderManager::VertexShaderProfile Rendering::ShaderManager
    ::GetVertexProfile () const
{
    MUTEX_ENTER_MEMBER;
    
	RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Impl->GetVertexProfile();
}

void Rendering::ShaderManager
    ::SetPixelProfile (PixelShaderProfile profile)
{    
	MUTEX_ENTER_MEMBER;
    
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_Impl->SetPixelProfile(profile);
}

Rendering::ShaderManager::PixelShaderProfile Rendering::ShaderManager
    ::GetPixelProfile () const
{
    MUTEX_ENTER_MEMBER;
    
	RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Impl->GetPixelProfile();
}