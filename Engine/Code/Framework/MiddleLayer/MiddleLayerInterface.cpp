/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:03)

#include "Framework/FrameworkExport.h"

#include "MiddleLayerInterface.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::MiddleLayerInterface::MiddleLayerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory) noexcept
    : middleLayerPlatform{ middleLayerPlatform }, environmentDirectory{ environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::MiddleLayerInterface::MiddleLayerInterface(MiddleLayerInterface&& rhs) noexcept
    : middleLayerPlatform{ rhs.middleLayerPlatform }, environmentDirectory{ std::move(rhs.environmentDirectory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::MiddleLayerInterface& Framework::MiddleLayerInterface::operator=(MiddleLayerInterface&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    middleLayerPlatform = rhs.middleLayerPlatform;
    environmentDirectory = std::move(rhs.environmentDirectory);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, MiddleLayerInterface)

bool Framework::MiddleLayerInterface::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(environmentParameter);

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

bool Framework::MiddleLayerInterface::Idle(int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(timeDelta);

    return true;
}

bool Framework::MiddleLayerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::MiddleLayerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(point);

    return true;
}

bool Framework::MiddleLayerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(windowDisplay, size);

    return true;
}

bool Framework::MiddleLayerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(key, point);

    return true;
}

bool Framework::MiddleLayerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(key, point);

    return true;
}

bool Framework::MiddleLayerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(key, point);

    return true;
}

bool Framework::MiddleLayerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(key, point);

    return true;
}

bool Framework::MiddleLayerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(point);

    return true;
}

bool Framework::MiddleLayerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(point, virtualKeys);

    return true;
}

bool Framework::MiddleLayerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(delta, point, virtualKeys);

    return true;
}

bool Framework::MiddleLayerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(button, state, point, virtualKeys);

    return true;
}

Framework::MiddleLayerPlatform Framework::MiddleLayerInterface::GetMiddleLayerPlatform() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return middleLayerPlatform;
}

Framework::EnvironmentDirectory Framework::MiddleLayerInterface::GetEnvironmentDirectory() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return environmentDirectory;
}
