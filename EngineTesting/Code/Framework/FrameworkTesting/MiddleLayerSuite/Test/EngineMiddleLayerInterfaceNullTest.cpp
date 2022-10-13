///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/10 14:14)

#include "EngineMiddleLayerInterfaceNullTest.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::EngineMiddleLayerInterfaceNullTest::EngineMiddleLayerInterfaceNullTest(MiddleLayerInterfaceCreate middleLayerInterfaceCreate, MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory) noexcept
    : ParentType{ middleLayerInterfaceCreate, middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::EngineMiddleLayerInterfaceNullTest::MiddleLayerSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<ClassType>(MiddleLayerInterfaceCreate::Init, middleLayerPlatform, environmentDirectory);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EngineMiddleLayerInterfaceNullTest)

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetNetworkManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetInputManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetObjectLogicManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetPhysicalModellingManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetMessageManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetEventManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetSystemManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetResourceManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetAudioManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetCameraSystemsManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetRenderingManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetGUIManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetEngineManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return nullptr;
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetNetworkManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetNetworkManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetInputManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetInputManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetObjectLogicManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetObjectLogicManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetPhysicalModellingManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetPhysicalModellingManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetMessageManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetMessageManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetEventManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetEventManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetSystemManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetSystemManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetResourceManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetResourceManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetAudioManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetAudioManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetCameraSystemsManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetCameraSystemsManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetRenderingManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetRenderingManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetGUIManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetGUIManager();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceNullTest::GetEngineManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::GetEngineManager();
}
