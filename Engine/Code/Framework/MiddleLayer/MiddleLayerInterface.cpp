///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:46)

#include "Framework/FrameworkExport.h"

#include "MiddleLayerInterface.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::MiddleLayerInterface::MiddleLayerInterface(MiddleLayerPlatform middleLayerPlatform) noexcept
    : middleLayerPlatform{ middleLayerPlatform }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::MiddleLayerInterface::MiddleLayerInterface(MiddleLayerInterface&& rhs) noexcept
    : middleLayerPlatform{ rhs.middleLayerPlatform }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::MiddleLayerInterface& Framework::MiddleLayerInterface::operator=(MiddleLayerInterface&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    middleLayerPlatform = rhs.middleLayerPlatform;

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, MiddleLayerInterface)

bool Framework::MiddleLayerInterface::PreCreate(MAYBE_UNUSED const EnvironmentDirectory& environmentDirectory)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::Create()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

void Framework::MiddleLayerInterface::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void Framework::MiddleLayerInterface::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

bool Framework::MiddleLayerInterface::Idle(MAYBE_UNUSED int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::Move(MAYBE_UNUSED const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::Resize(MAYBE_UNUSED WindowDisplay windowDisplay, MAYBE_UNUSED const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::KeyUp(MAYBE_UNUSED int key, MAYBE_UNUSED const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::KeyDown(MAYBE_UNUSED int key, MAYBE_UNUSED const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::SpecialKeyUp(MAYBE_UNUSED int key, MAYBE_UNUSED const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::SpecialKeyDown(MAYBE_UNUSED int key, MAYBE_UNUSED const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::PassiveMotion(MAYBE_UNUSED const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::Motion(MAYBE_UNUSED const WindowPoint& point, MAYBE_UNUSED const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::MouseWheel(MAYBE_UNUSED int delta, MAYBE_UNUSED const WindowPoint& point, MAYBE_UNUSED const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::MouseClick(MAYBE_UNUSED MouseButtonsTypes button, MAYBE_UNUSED MouseStateTypes state, MAYBE_UNUSED const WindowPoint& point, MAYBE_UNUSED const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

Framework::MiddleLayerPlatform Framework::MiddleLayerInterface::GetMiddleLayerPlatform() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return middleLayerPlatform;
}
