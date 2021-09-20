// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:56)

#include "Framework/FrameworkExport.h"

#include "SystemManagerInterface.h"
#include "Flags/SystemMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::SystemManagerInterface
	::SystemManagerInterface(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, impl{ System::EnumCastUnderlying(SystemMiddleLayer::Count) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SystemManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, ObjectLogic)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Message)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Event)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Resource)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Audio)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, CameraSystems)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Rendering)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Engine)

bool Framework::SystemManagerInterface
	::Paint()
{
	;

	return ParentType::Paint();
}

bool Framework::SystemManagerInterface
	::Move(const WindowPoint& point)
{
	;

	return ParentType::Move(point);
}

bool Framework::SystemManagerInterface
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	;

	return ParentType::Resize(windowDisplay, size);
}

bool Framework::SystemManagerInterface
	::KeyUp(int key, const WindowPoint& point)
{
	;

	return ParentType::KeyUp(key, point);
}

bool Framework::SystemManagerInterface
	::KeyDown(int key, const WindowPoint& point)
{
	;

	return ParentType::KeyDown(key, point);
}

bool Framework::SystemManagerInterface
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	;

	return ParentType::SpecialKeyUp(key, point);
}

bool Framework::SystemManagerInterface
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	;

	return ParentType::SpecialKeyDown(key, point);
}

bool Framework::SystemManagerInterface
	::PassiveMotion(const WindowPoint& point)
{
	;

	return ParentType::PassiveMotion(point);
}

bool Framework::SystemManagerInterface
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::Motion(point, virtualKeys);
}

bool Framework::SystemManagerInterface
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::SystemManagerInterface
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::MouseClick(button, state, point, virtualKeys);
}
