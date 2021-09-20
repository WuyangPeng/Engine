// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:54)

#include "Framework/FrameworkExport.h"

#include "CameraSystemsManagerInterface.h"
#include "Flags/CameraSystemsMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::CameraSystemsManagerInterface
	::CameraSystemsManagerInterface(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, impl{  System::EnumCastUnderlying(CameraSystemsMiddleLayer::Count)  }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, CameraSystemsManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, CameraSystems, System)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, CameraSystems, Rendering)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, CameraSystems, GUI)

bool Framework::CameraSystemsManagerInterface
	::Paint()
{
	;

	return ParentType::Paint();
}

bool Framework::CameraSystemsManagerInterface
	::Move(const WindowPoint& point)
{
	;

	return ParentType::Move(point);
}

bool Framework::CameraSystemsManagerInterface
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	;

	return ParentType::Resize(windowDisplay, size);
}

bool Framework::CameraSystemsManagerInterface
	::KeyUp(int key, const WindowPoint& point)
{
	;

	return ParentType::KeyUp(key, point);
}

bool Framework::CameraSystemsManagerInterface
	::KeyDown(int key, const WindowPoint& point)
{
	;

	return ParentType::KeyDown(key, point);
}

bool Framework::CameraSystemsManagerInterface
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	;

	return ParentType::SpecialKeyUp(key, point);
}

bool Framework::CameraSystemsManagerInterface
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	;

	return ParentType::SpecialKeyDown(key, point);
}

bool Framework::CameraSystemsManagerInterface
	::PassiveMotion(const WindowPoint& point)
{
	;

	return ParentType::PassiveMotion(point);
}

bool Framework::CameraSystemsManagerInterface
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::Motion(point, virtualKeys);
}

bool Framework::CameraSystemsManagerInterface
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::CameraSystemsManagerInterface
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	;

	return ParentType::MouseClick(button, state, point, virtualKeys);
}
