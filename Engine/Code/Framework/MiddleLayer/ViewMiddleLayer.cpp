///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 16:27)

#include "Framework/FrameworkExport.h"

#include "ModelMiddleLayer.h"
#include "ViewMiddleLayer.h"
#include "Detail/ViewMiddleLayerImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"

Framework::ViewMiddleLayer::ViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ViewMiddleLayer)

void Framework::ViewMiddleLayer::SetClearColour(const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetClearColor(colour);
}

Framework::ViewMiddleLayer::RendererSharedPtr Framework::ViewMiddleLayer::GetRenderer()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->GetRenderer();
}

Framework::ViewMiddleLayer::ConstRendererSharedPtr Framework::ViewMiddleLayer::GetRenderer() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetRenderer();
}

bool Framework::ViewMiddleLayer::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Create(environmentParameter))
    {
        const auto rendererFileName = GetEnvironmentDirectory().GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Renderer.json");

        impl->ResetRenderer(CoreTools::StringConversion::StandardConversionMultiByte(rendererFileName), environmentParameter);

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::ViewMiddleLayer::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Initialize())
    {
        // 设备创建与平台相关的代码在EnterMessageLoop前调用Initialize。
        // 因此此时设备状态可能会修改。

        impl->ClearColorBuffer();

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::ViewMiddleLayer::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Paint())
    {
        const auto modelMiddleLayer = boost::polymorphic_pointer_cast<ModelMiddleLayer>(GetModelMiddleLayer());

        modelMiddleLayer->UpdateFrameCount();

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::ViewMiddleLayer::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Resize(windowDisplay, size))
    {
        impl->Resize(size.GetWindowWidth(), size.GetWindowHeight());

        return true;
    }
    else
    {
        return false;
    }
}

void Framework::ViewMiddleLayer::DrawFrameRate(const WindowPoint& point, const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    const auto modelMiddleLayer = boost::polymorphic_pointer_cast<const ModelMiddleLayer>(GetConstModelMiddleLayer());

    const auto frameRateMessage = modelMiddleLayer->GetFrameRateMessage();

    impl->DrawFrameRate(point.GetWindowX(), point.GetWindowY(), colour, frameRateMessage);
}

Framework::ViewMiddleLayer::Colour Framework::ViewMiddleLayer::GetClearColour() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetClearColor();
}

bool Framework::ViewMiddleLayer::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::KeyUp(key, point);
}

bool Framework::ViewMiddleLayer::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::KeyDown(key, point);
}

bool Framework::ViewMiddleLayer::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::ViewMiddleLayer::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::ViewMiddleLayer::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::PassiveMotion(point);
}

bool Framework::ViewMiddleLayer::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::ViewMiddleLayer::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::ViewMiddleLayer::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
