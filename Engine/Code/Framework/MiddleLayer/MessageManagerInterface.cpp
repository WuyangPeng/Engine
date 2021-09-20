// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:55)

#include "Framework/FrameworkExport.h"

#include "MessageManagerInterface.h"
#include "Flags/MessageMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::MessageManagerInterface
	::MessageManagerInterface(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, impl{  System::EnumCastUnderlying(MessageMiddleLayer::Count)  }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MessageManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Message, ObjectLogic)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Message, System)

bool Framework::MessageManagerInterface
	::Paint()
{
	;

	return ParentType::Paint();
}

bool Framework::MessageManagerInterface
	::Move(const WindowPoint& point)
{
	;

	return ParentType::Move(point);
}

bool Framework::MessageManagerInterface
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	;

	return ParentType::Resize(windowDisplay, size);
}

bool Framework::MessageManagerInterface
	::KeyUp(int key, const WindowPoint& point)
{
	;

	return ParentType::KeyUp(key, point);
}

bool Framework::MessageManagerInterface
	::KeyDown(int key, const WindowPoint& point)
{
	;

	return ParentType::KeyDown(key, point);
}

bool Framework::MessageManagerInterface
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	;

	return ParentType::SpecialKeyUp(key, point);
}

bool Framework::MessageManagerInterface
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	;

	return ParentType::SpecialKeyDown(key, point);
}

bool Framework::MessageManagerInterface
	::PassiveMotion(const WindowPoint& point)
{
	;

	return ParentType::PassiveMotion(point);
}

bool Framework::MessageManagerInterface
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::Motion(point, virtualKeys);
}

bool Framework::MessageManagerInterface
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::MessageManagerInterface
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::MouseClick(button, state, point, virtualKeys);
}
