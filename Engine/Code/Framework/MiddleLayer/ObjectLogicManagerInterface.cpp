// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:56)

#include "Framework/FrameworkExport.h"

#include "ObjectLogicManagerInterface.h"
#include "Flags/ObjectLogicManagerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::ObjectLogicManagerInterface
::ObjectLogicManagerInterface(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, impl{  System::EnumCastUnderlying(ObjectLogicMiddleLayer::Count) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ObjectLogicManagerInterface)

bool Framework::ObjectLogicManagerInterface
	::Paint()
{
	;

	return ParentType::Paint();
}

bool Framework::ObjectLogicManagerInterface
	::Move(const WindowPoint& point)
{
	;

	return ParentType::Move(point);
}

bool Framework::ObjectLogicManagerInterface
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	;

	return ParentType::Resize(windowDisplay, size);
}

bool Framework::ObjectLogicManagerInterface
	::KeyUp(int key, const WindowPoint& point)
{
	;

	return ParentType::KeyUp(key, point);
}

bool Framework::ObjectLogicManagerInterface
	::KeyDown(int key, const WindowPoint& point)
{
	;

	return ParentType::KeyDown(key, point);
}

bool Framework::ObjectLogicManagerInterface
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	;

	return ParentType::SpecialKeyUp(key, point);
}

bool Framework::ObjectLogicManagerInterface
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	;

	return ParentType::SpecialKeyDown(key, point);
}

bool Framework::ObjectLogicManagerInterface
	::PassiveMotion(const WindowPoint& point)
{
	;

	return ParentType::PassiveMotion(point);
}

bool Framework::ObjectLogicManagerInterface
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::Motion(point, virtualKeys);
}

bool Framework::ObjectLogicManagerInterface
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::ObjectLogicManagerInterface
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::MouseClick(button, state, point, virtualKeys);
}

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, ObjectLogic, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, ObjectLogic, Network)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, ObjectLogic, PhysicalModelling)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, ObjectLogic, Message)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, ObjectLogic, System)