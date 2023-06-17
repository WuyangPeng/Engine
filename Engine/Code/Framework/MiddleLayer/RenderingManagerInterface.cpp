///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:36)

#include "Framework/FrameworkExport.h"

#include "RenderingManagerInterface.h"
#include "Flags/RenderingMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "Detail/ViewMiddleLayerImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/WindowCreate/WindowSize.h"

using namespace std::literals;

Framework::RenderingManagerInterface::MiddleLayerSharedPtr Framework::RenderingManagerInterface::CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<ClassType>(MiddleLayerInterfaceCreate::Init, middleLayerPlatform, environmentDirectory);
}

Framework::RenderingManagerInterface::RenderingManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ClassType{ MiddleLayerInterfaceCreate::Init, middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::RenderingManagerInterface::RenderingManagerInterface(MiddleLayerInterfaceCreate middleLayerInterfaceCreate, MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerInterfaceCreate, middleLayerPlatform, environmentDirectory },
      impl{ System::EnumCastUnderlying(RenderingMiddleLayer::Count) },
      viewMiddleLayer{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, RenderingManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Rendering, System)

bool Framework::RenderingManagerInterface::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Create(environmentParameter))
    {
        auto rendererFileName = GetEnvironmentDirectory().GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Renderer.json"s);

        viewMiddleLayer->ResetRenderer(CoreTools::StringConversion::StandardConversionMultiByte(rendererFileName), environmentParameter);

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

bool Framework::RenderingManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Paint())
    {
        viewMiddleLayer->SwapBuffers();

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::RenderingManagerInterface::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Destroy())
    {
        viewMiddleLayer->Release();

        return true;
    }
    else
    {
        return false;
    }
}

Rendering::RendererSharedPtr Framework::RenderingManagerInterface::GetRenderer()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return viewMiddleLayer->GetRenderer();
}

Rendering::ConstRendererSharedPtr Framework::RenderingManagerInterface::GetRenderer() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return viewMiddleLayer->GetRenderer();
}

bool Framework::RenderingManagerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::UnusedFunction(key, point);

    ThrowException();
}

bool Framework::RenderingManagerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::UnusedFunction(key, point);

    ThrowException();
}

bool Framework::RenderingManagerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::UnusedFunction(key, point);

    ThrowException();
}

bool Framework::RenderingManagerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::UnusedFunction(key, point);

    ThrowException();
}

bool Framework::RenderingManagerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::UnusedFunction(point);

    ThrowException();
}

bool Framework::RenderingManagerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::UnusedFunction(point, virtualKeys);

    ThrowException();
}

bool Framework::RenderingManagerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::UnusedFunction(delta, point, virtualKeys);

    ThrowException();
}

bool Framework::RenderingManagerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::UnusedFunction(button, state, point, virtualKeys);

    ThrowException();
}
