///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 15:29)

#include "EngineMiddleLayerInterfaceTest.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::EngineMiddleLayerInterfaceTest::EngineMiddleLayerInterfaceTest(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory) noexcept
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::EngineMiddleLayerInterfaceTest::MiddleLayerSharedPtr Framework::EngineMiddleLayerInterfaceTest::CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<ClassType>(middleLayerPlatform, environmentDirectory);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EngineMiddleLayerInterfaceTest)

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetNetworkManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetNetworkManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetInputManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetInputManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetObjectLogicManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetObjectLogicManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetPhysicalModellingManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetPhysicalModellingManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetMessageManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetMessageManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetEventManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetEventManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetSystemManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetSystemManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetResourceManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetResourceManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetAudioManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetAudioManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetCameraSystemsManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetCameraSystemsManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetRenderingManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetRenderingManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetGUIManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetGUIManager();
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetEngineManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetEngineManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetNetworkManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetNetworkManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetInputManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetInputManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetObjectLogicManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetObjectLogicManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetPhysicalModellingManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetPhysicalModellingManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetMessageManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetMessageManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetEventManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetEventManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetSystemManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetSystemManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetResourceManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetResourceManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetAudioManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetAudioManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetCameraSystemsManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetCameraSystemsManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetRenderingManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetRenderingManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetGUIManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetGUIManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceTest::GetEngineManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetEngineManager();
}
