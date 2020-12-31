// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:54)

#include "Framework/FrameworkExport.h"

#include "EventManagerInterface.h"
#include "Flags/EventMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::EventManagerInterface
	::EventManagerInterface(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Impl{ make_shared<ImplType>(System::EnumCastUnderlying(EventMiddleLayer::Count)) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EventManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Event, Message)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Event, System)

bool Framework::EventManagerInterface
	::Paint()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Paint();
}

bool Framework::EventManagerInterface
	::Move(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Move(point);
}

bool Framework::EventManagerInterface
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Resize(windowDisplay, size);
}

bool Framework::EventManagerInterface
	::KeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::KeyUp(key, point);
}

bool Framework::EventManagerInterface
	::KeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::KeyDown(key, point);
}

bool Framework::EventManagerInterface
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::SpecialKeyUp(key, point);
}

bool Framework::EventManagerInterface
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::SpecialKeyDown(key, point);
}

bool Framework::EventManagerInterface
	::PassiveMotion(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::PassiveMotion(point);
}

bool Framework::EventManagerInterface
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Motion(point, virtualKeys);
}

bool Framework::EventManagerInterface
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::EventManagerInterface
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::MouseClick(button, state, point, virtualKeys);
}
