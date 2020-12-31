// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:55)

#include "Framework/FrameworkExport.h"

#include "MiddleLayerInterface.h"

#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
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

bool Framework::MiddleLayerInterface ::PreCreate([[maybe_unused]] const EnvironmentDirectory& environmentDirectory)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface
	::Create()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface
	::Destroy()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();

	return true;
}

void Framework::MiddleLayerInterface
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();
}

void Framework::MiddleLayerInterface
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();
}

bool Framework::MiddleLayerInterface ::Idle([[maybe_unused]] int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface
	::Paint()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface ::Move([[maybe_unused]] const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface ::Resize([[maybe_unused]] WindowDisplay windowDisplay, [[maybe_unused]] const WindowSize& size)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface ::KeyUp([[maybe_unused]] int key, [[maybe_unused]] const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface ::KeyDown([[maybe_unused]] int key, [[maybe_unused]] const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface ::SpecialKeyUp([[maybe_unused]] int key, [[maybe_unused]] const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;
 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface ::SpecialKeyDown([[maybe_unused]] int key, [[maybe_unused]] const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface ::PassiveMotion([[maybe_unused]] const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface ::Motion([[maybe_unused]] const WindowPoint& point, [[maybe_unused]] const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface ::MouseWheel([[maybe_unused]] int delta, [[maybe_unused]] const WindowPoint& point, [[maybe_unused]] const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::MiddleLayerInterface ::MouseClick([[maybe_unused]] MouseButtonsTypes button, [[maybe_unused]] MouseStateTypes state, [[maybe_unused]] const WindowPoint& point, [[maybe_unused]] const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_9;
 

	CoreTools::DisableNoexcept();

	return true;
}

Framework::MiddleLayerPlatform Framework::MiddleLayerInterface
	::GetMiddleLayerPlatform() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_MiddleLayerPlatform;
}
#include STSTEM_WARNING_POP