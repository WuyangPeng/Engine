// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:08)

#include "Framework/FrameworkExport.h"

#include "NetworkManagerInterface.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Flags/NetworkMiddleLayerFlags.h"

Framework::NetworkManagerInterface
	::NetworkManagerInterface()
	:ParentType{}, m_Impl(new ImplType(static_cast<int>(NetworkMiddleLayer::Count)))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::NetworkManagerInterface
	::~NetworkManagerInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework, NetworkManagerInterface)

bool Framework::NetworkManagerInterface
	::PreCreate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate())
		return true;
	else	
		return false;	
}

bool Framework::NetworkManagerInterface
	::Create()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Create())
		return true;
	else	
		return false;	
}

bool Framework::NetworkManagerInterface
	::Initialize() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	// 连接服务器和监听客户端
	if (ParentType::Initialize())
		return true;
	else	
		return false;
}

void Framework::NetworkManagerInterface
	::Terminate() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();
}

bool Framework::NetworkManagerInterface
	::Destroy() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Destroy())
		return true;
	else
		return false;
}

void Framework::NetworkManagerInterface
	::PreIdle()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PreIdle();
}

bool Framework::NetworkManagerInterface
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	// 发送和接收消息
	if (ParentType::Idle(timeDelta))
		return true;
	else
		return false;
}

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Network, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Network, ObjectLogic)
 