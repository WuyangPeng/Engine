// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:09)

#include "Framework/FrameworkExport.h"

#include "ResourceManagerInterface.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Flags/ResourceMiddleLayerFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::ResourceManagerInterface
	::ResourceManagerInterface()
	:ParentType{}, m_Impl(new ImplType(static_cast<int>(ResourceMiddleLayer::Count)))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ResourceManagerInterface
	::~ResourceManagerInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ResourceManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Resource, System)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Resource, Audio)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Resource, Rendering)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Resource, GUI) 
 
bool Framework::ResourceManagerInterface
	::PreCreate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate())
		return true;
	else	
		return false;	
}

bool Framework::ResourceManagerInterface
	::Create()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Create())
		return true;
	else	
		return false;	
}

bool Framework::ResourceManagerInterface
	::Initialize() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Initialize())
		return true;
	else	
		return false;
}

void Framework::ResourceManagerInterface
	::Terminate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();
}

bool Framework::ResourceManagerInterface
	::Destroy() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Destroy())
		return true;
	else
		return false;
}

void Framework::ResourceManagerInterface
	::PreIdle()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PreIdle();
}

bool Framework::ResourceManagerInterface
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Idle(timeDelta))
		return true;
	else
		return false;
}




