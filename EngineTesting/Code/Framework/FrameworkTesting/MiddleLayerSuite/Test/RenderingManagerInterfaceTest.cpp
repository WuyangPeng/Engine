///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:04)

#include "RenderingManagerInterfaceTest.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/Renderers/Renderer.h"

Framework::RenderingManagerInterfaceTest::RenderingManagerInterfaceTest(MiddleLayerInterfaceCreate middleLayerInterfaceCreate, MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerInterfaceCreate, middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::RenderingManagerInterfaceTest::MiddleLayerSharedPtr Framework::RenderingManagerInterfaceTest::CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<ClassType>(MiddleLayerInterfaceCreate::Init, middleLayerPlatform, environmentDirectory);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, RenderingManagerInterfaceTest)

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetNetworkManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetNetworkManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetInputManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetInputManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetObjectLogicManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetObjectLogicManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetPhysicalModellingManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetPhysicalModellingManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetMessageManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetMessageManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetEventManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetEventManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetSystemManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetSystemManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetResourceManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetResourceManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetAudioManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetAudioManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetCameraSystemsManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetCameraSystemsManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetRenderingManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetRenderingManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetGUIManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetGUIManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetEngineManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetEngineManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetNetworkManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetNetworkManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetInputManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetInputManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetObjectLogicManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetObjectLogicManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetPhysicalModellingManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetPhysicalModellingManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetMessageManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetMessageManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetEventManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetEventManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetSystemManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetSystemManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetResourceManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetResourceManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetAudioManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetAudioManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetCameraSystemsManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetCameraSystemsManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetRenderingManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetRenderingManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetGUIManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetGUIManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::RenderingManagerInterfaceTest::GetEngineManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetEngineManager();
}

Framework::RenderingManagerInterfaceTest::RendererSharedPtr Framework::RenderingManagerInterfaceTest::GetRendererSharedPtr()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetRenderer();
}

Framework::RenderingManagerInterfaceTest::ConstRendererSharedPtr Framework::RenderingManagerInterfaceTest::GetRendererSharedPtr() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetRenderer();
}