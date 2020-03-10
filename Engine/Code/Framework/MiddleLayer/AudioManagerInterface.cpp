// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:06)

#include "Framework/FrameworkExport.h"

#include "AudioManagerInterface.h"
#include "Flags/AudioMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::AudioManagerInterface
	::AudioManagerInterface()
	:ParentType{}, m_Impl(new ImplType(static_cast<int>(AudioMiddleLayer::Count)))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AudioManagerInterface
	::~AudioManagerInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AudioManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Audio, System)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Audio, Resource) 

bool Framework::AudioManagerInterface
	::PreCreate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate())
		return true;
	else	
		return false;	
}

bool Framework::AudioManagerInterface
	::Create()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Create())
		return true;
	else	
		return false;	
}

bool Framework::AudioManagerInterface
	::Initialize() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Initialize())
		return true;
	else	
		return false;
}

void Framework::AudioManagerInterface
	::Terminate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();
}

bool Framework::AudioManagerInterface
	::Destroy() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Destroy())
		return true;
	else
		return false;
}

void Framework::AudioManagerInterface
	::PreIdle()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PreIdle();
}

bool Framework::AudioManagerInterface
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Idle(timeDelta))
		return true;
	else
		return false;
}




