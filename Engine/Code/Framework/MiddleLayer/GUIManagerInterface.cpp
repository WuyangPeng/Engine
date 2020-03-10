// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:07)

#include "Framework/FrameworkExport.h"

#include "GUIManagerInterface.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Flags/GUIMiddleLayerFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::GUIManagerInterface
	::GUIManagerInterface()
	:ParentType{}, m_Impl(new ImplType(static_cast<int>(GUIMiddleLayer::Count)))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::GUIManagerInterface
	::~GUIManagerInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GUIManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, GUI, Rendering) 

bool Framework::GUIManagerInterface
	::PreCreate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate())
		return true;
	else	
		return false;	
}

bool Framework::GUIManagerInterface
	::Create()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Create())
		return true;
	else	
		return false;	
}

bool Framework::GUIManagerInterface
	::Initialize() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Initialize())
		return true;
	else	
		return false;
}

void Framework::GUIManagerInterface
	::Terminate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();
}

bool Framework::GUIManagerInterface
	::Destroy() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Destroy())
		return true;
	else
		return false;
}

void Framework::GUIManagerInterface
	::PreIdle()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PreIdle();
}

bool Framework::GUIManagerInterface
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Idle(timeDelta))
		return true;
	else
		return false;
}




