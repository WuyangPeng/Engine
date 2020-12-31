// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:55)

#include "Framework/FrameworkExport.h"

#include "InputManagerInterface.h"
#include "Flags/InputMiddleLayerFlags.h"
#include "Flags/MiddleLayerPlatformFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::InputManagerInterface
	::InputManagerInterface(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Impl{ make_shared<ImplType>(System::EnumCastUnderlying(InputMiddleLayer::Count)) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, InputManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, Network)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, ObjectLogic)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, System)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, CameraSystems)

bool Framework::InputManagerInterface
	::Paint()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Paint();
}

bool Framework::InputManagerInterface
	::Move(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Move(point);
}

bool Framework::InputManagerInterface
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Resize(windowDisplay,size);
}
