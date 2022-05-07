///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 13:54)

#include "Framework/FrameworkExport.h"

#include "RenderingManagerInterface.h"
#include "Flags/RenderingMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "Detail/ViewMiddleLayerImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/WindowCreate/WindowSize.h"

using std::make_shared;

Framework::RenderingManagerInterface::RenderingManagerInterface(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform },
      impl{ System::EnumCastUnderlying(RenderingMiddleLayer::Count) },
      viewMiddleLayer{ make_shared<ViewMiddleLayerImpl>() }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::RenderingManagerInterface::IsValid() const noexcept
{
    if (ParentType::IsValid() && viewMiddleLayer != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Rendering, System)

bool Framework::RenderingManagerInterface::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::PreCreate(environmentDirectory))
    {
        auto rendererFileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Renderer.json");

        viewMiddleLayer->ResetRenderer(CoreTools::StringConversion::StandardConversionMultiByte(rendererFileName));

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::RenderingManagerInterface::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Initialize())
    {
        viewMiddleLayer->ClearColorBuffer();

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::RenderingManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Resize(windowDisplay, size))
    {
        viewMiddleLayer->Resize(size.GetWindowWidth(), size.GetWindowHeight());

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::RenderingManagerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyUp(key, point);
}

bool Framework::RenderingManagerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyDown(key, point);
}

bool Framework::RenderingManagerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::RenderingManagerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::RenderingManagerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::PassiveMotion(point);
}

bool Framework::RenderingManagerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::RenderingManagerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::RenderingManagerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}

Rendering::RendererSharedPtr Framework::RenderingManagerInterface::GetRenderer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return viewMiddleLayer->GetRenderer();
}

Rendering::ConstRendererSharedPtr Framework::RenderingManagerInterface::GetRenderer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return viewMiddleLayer->GetRenderer();
}
