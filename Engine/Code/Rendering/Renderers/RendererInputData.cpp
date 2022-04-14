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
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(Rendering, RendererInputData);

Rendering::RendererInputData::RendererInputDataUniquePtr Rendering::RendererInputData
::sm_RendererInputData{ };

void Rendering::RendererInputData
::Create()
{
	sm_RendererInputData = make_unique<Rendering::RendererInputData>(RendererInputDataCreate::Init);
}

void Rendering::RendererInputData
::Destroy() noexcept
{
	sm_RendererInputData.reset();
}

Rendering::RendererInputData::RendererInputData([[maybe_unused]] RendererInputDataCreate rendererInputDataCreate)
    : impl{ 0  }
{
 

	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererInputData)

void Rendering::RendererInputData
	::Rebuild(RendererTypes type)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	;

	impl->Rebuild(type);
}

