// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:07)

#include "Framework/FrameworkExport.h"

#include "CameraSystemsManagerInterface.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Flags/CameraSystemsMiddleLayerFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::CameraSystemsManagerInterface
	::CameraSystemsManagerInterface()
	:ParentType{}, m_Impl(new ImplType(static_cast<int>(CameraSystemsMiddleLayer::Count)))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::CameraSystemsManagerInterface
	::~CameraSystemsManagerInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraSystemsManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, CameraSystems, System)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, CameraSystems, Rendering)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, CameraSystems, GUI) 

bool Framework::CameraSystemsManagerInterface
	::PreCreate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate())
		return true;
	else	
		return false;	
}

bool Framework::CameraSystemsManagerInterface
	::Create()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Create())
		return true;
	else	
		return false;	
}

bool Framework::CameraSystemsManagerInterface
	::Initialize() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Initialize())
		return true;
	else	
		return false;
}

void Framework::CameraSystemsManagerInterface
	::Terminate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();
}

bool Framework::CameraSystemsManagerInterface
	::Destroy() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Destroy())
		return true;
	else
		return false;
}

void Framework::CameraSystemsManagerInterface
	::PreIdle()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PreIdle();
}

bool Framework::CameraSystemsManagerInterface
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Idle(timeDelta))
		return true;
	else
		return false;
}




