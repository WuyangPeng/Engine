// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:29)

#include "Rendering/RenderingExport.h"

#include "RendererInputData.h"
#include "Detail/RendererInputDataImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;

SINGLETON_MUTEX_DEFINE(Rendering,RendererInputData);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ GetRenderingMutex() }

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_RendererInputDataMutex }

SINGLETON_INITIALIZE_DEFINE(Rendering,RendererInputData)

Rendering::RendererInputData
	::RendererInputData()
	:m_Impl{ make_shared<ImplType>() }
{
	MUTEX_ENTER_MEMBER;

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::RendererInputData
	::~RendererInputData()
{
	MUTEX_ENTER_MEMBER;

	RENDERING_SELF_CLASS_IS_VALID_1;	
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::RendererInputData
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if(m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::RendererInputData
	::Rebuild(RendererTypes type)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->Rebuild(type);
}

