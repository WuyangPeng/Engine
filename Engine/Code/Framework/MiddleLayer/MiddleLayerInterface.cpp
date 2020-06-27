// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:55)

#include "Framework/FrameworkExport.h"

#include "MiddleLayerInterface.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/ClassInvariant/NoexceptDetail.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::MiddleLayerInterface
	::MiddleLayerInterface(MiddleLayerPlatform middleLayerPlatform) noexcept
	:m_MiddleLayerPlatform{ middleLayerPlatform }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::MiddleLayerInterface
	::MiddleLayerInterface(MiddleLayerInterface&& rhs) noexcept
	:m_MiddleLayerPlatform{ rhs.m_MiddleLayerPlatform }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::MiddleLayerInterface& Framework::MiddleLayerInterface
	::operator=(MiddleLayerInterface&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_MiddleLayerPlatform = rhs.m_MiddleLayerPlatform;

	return *this;
}
 
CLASS_INVARIANT_STUB_DEFINE(Framework, MiddleLayerInterface)

bool Framework::MiddleLayerInterface
	::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(environmentDirectory);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::Create()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::Destroy()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();

	return true;
}

void Framework::MiddleLayerInterface
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();
}

void Framework::MiddleLayerInterface
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();
}

bool Framework::MiddleLayerInterface
	::Idle(int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(timeDelta);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::Paint()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::Move(const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(point);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(windowDisplay);
	SYSTEM_UNUSED_ARG(size);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::KeyUp(int key, const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(point);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::KeyDown(int key, const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(point);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(point);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(point);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::PassiveMotion(const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(point);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(point);
	SYSTEM_UNUSED_ARG(virtualKeys);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(delta);
	SYSTEM_UNUSED_ARG(point);
	SYSTEM_UNUSED_ARG(virtualKeys);

	CoreTools::DoNothing();

	return true;
}

bool Framework::MiddleLayerInterface
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(button);
	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(point);
	SYSTEM_UNUSED_ARG(virtualKeys);

	CoreTools::DoNothing();

	return true;
}

Framework::MiddleLayerPlatform Framework::MiddleLayerInterface
	::GetMiddleLayerPlatform() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_MiddleLayerPlatform;
}
