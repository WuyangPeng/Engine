// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:08)

#include "Framework/FrameworkExport.h"

#include "ObjectLogicManagerInterface.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Flags/ObjectLogicManagerFlags.h"

Framework::ObjectLogicManagerInterface
	::ObjectLogicManagerInterface()
	:ParentType{}, m_Impl(new ImplType(static_cast<int>(ObjectLogicMiddleLayer::Count)))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ObjectLogicManagerInterface
	::~ObjectLogicManagerInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework, ObjectLogicManagerInterface) 

bool Framework::ObjectLogicManagerInterface
	::PreCreate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate())
		return true;
	else	
		return false;	
}

bool Framework::ObjectLogicManagerInterface
	::Create()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Create())
		return true;
	else	
		return false;	
}

bool Framework::ObjectLogicManagerInterface
	::Initialize() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Initialize())
		return true;
	else	
		return false;
}

void Framework::ObjectLogicManagerInterface
	::Terminate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();
}

bool Framework::ObjectLogicManagerInterface
	::Destroy() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Destroy())
		return true;
	else
		return false;
}

void Framework::ObjectLogicManagerInterface
	::PreIdle()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PreIdle();
}

bool Framework::ObjectLogicManagerInterface
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Idle(timeDelta))
		return true;
	else
		return false;
}

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, ObjectLogic, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, ObjectLogic, Network)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, ObjectLogic, PhysicalModelling)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, ObjectLogic, Message)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, ObjectLogic, System) 