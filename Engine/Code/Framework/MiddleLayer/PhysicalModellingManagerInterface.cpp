// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:56)

#include "Framework/FrameworkExport.h"

#include "PhysicalModellingManagerInterface.h"
#include "Flags/PhysicalModellingMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::PhysicalModellingManagerInterface
	::PhysicalModellingManagerInterface(MiddleLayerPlatform middleLayerPlatform)
	: ParentType{ middleLayerPlatform }, impl{  System::EnumCastUnderlying(PhysicalModellingMiddleLayer::Count)  }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, PhysicalModellingManagerInterface)

bool Framework::PhysicalModellingManagerInterface
	::Paint()
{
	;

	return ParentType::Paint();
}

bool Framework::PhysicalModellingManagerInterface
	::Move(const WindowPoint& point)
{
	;

	return ParentType::Move(point);
}

bool Framework::PhysicalModellingManagerInterface
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	;

	return ParentType::Resize(windowDisplay, size);
}

bool Framework::PhysicalModellingManagerInterface
	::KeyUp(int key, const WindowPoint& point)
{
	;

	return ParentType::KeyUp(key, point);
}

bool Framework::PhysicalModellingManagerInterface
	::KeyDown(int key, const WindowPoint& point)
{
	;

	return ParentType::KeyDown(key, point);
}

bool Framework::PhysicalModellingManagerInterface
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	;

	return ParentType::SpecialKeyUp(key, point);
}

bool Framework::PhysicalModellingManagerInterface
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	;

	return ParentType::SpecialKeyDown(key, point);
}

bool Framework::PhysicalModellingManagerInterface
	::PassiveMotion(const WindowPoint& point)
{
	;

	return ParentType::PassiveMotion(point);
}

bool Framework::PhysicalModellingManagerInterface
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::Motion(point, virtualKeys);
}

bool Framework::PhysicalModellingManagerInterface
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::PhysicalModellingManagerInterface
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::MouseClick(button, state, point, virtualKeys);
}

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, PhysicalModelling, ObjectLogic)

