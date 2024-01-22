/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/13 14:31)

#include "Framework/FrameworkExport.h"

#include "RenderingManagerInterface.h"
#include "Flags/RenderingMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "Detail/RenderingManagerImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/WindowCreate/WindowSize.h"

Framework::RenderingManagerInterface::RenderingManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      impl{ System::EnumCastUnderlying(RenderingMiddleLayer::Count) },
      rendering{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, RenderingManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Rendering, System)

bool Framework::RenderingManagerInterface::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Create(environmentParameter))
    {
        const auto rendererFileName = GetEnvironmentDirectory().GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Renderer.json");

        rendering->ResetRenderer(CoreTools::StringConversion::StandardConversionMultiByte(rendererFileName), environmentParameter);

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::RenderingManagerInterface::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Initialize())
    {
        rendering->ClearBuffers();

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::RenderingManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Resize(windowDisplay, size))
    {
        rendering->Resize(size.GetWindowWidth(), size.GetWindowHeight());

        return true;
    }
    else
    {
        return false;
    }
}

void Framework::RenderingManagerInterface::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ParentType::PreIdle();

    rendering->ClearBuffers();
}

bool Framework::RenderingManagerInterface::Idle(int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Idle(timeDelta))
    {
        rendering->SwapBuffers();

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::RenderingManagerInterface::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Destroy())
    {
        rendering->Release();

        return true;
    }
    else
    {
        return false;
    }
}

Rendering::BaseRendererSharedPtr Framework::RenderingManagerInterface::GetRenderer()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return rendering->GetRenderer();
}

Rendering::ConstBaseRendererSharedPtr Framework::RenderingManagerInterface::GetRenderer() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return rendering->GetRenderer();
}

bool Framework::RenderingManagerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(key, point);

    ThrowException();
}

bool Framework::RenderingManagerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(key, point);

    ThrowException();
}

bool Framework::RenderingManagerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(key, point);

    ThrowException();
}

bool Framework::RenderingManagerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(key, point);

    ThrowException();
}

bool Framework::RenderingManagerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(point);

    ThrowException();
}

bool Framework::RenderingManagerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(point, virtualKeys);

    ThrowException();
}

bool Framework::RenderingManagerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(delta, point, virtualKeys);

    ThrowException();
}

bool Framework::RenderingManagerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(button, state, point, virtualKeys);

    ThrowException();
}
