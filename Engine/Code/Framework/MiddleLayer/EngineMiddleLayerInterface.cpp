///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/10 14:10)

#include "Framework/FrameworkExport.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Framework::EngineMiddleLayerInterface::EngineMiddleLayerInterface(MiddleLayerInterfaceCreate middleLayerInterfaceCreate, MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory) noexcept
    : ParentType{ middleLayerInterfaceCreate, middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::EngineMiddleLayerInterface::EngineMiddleLayerInterface(MiddleLayerPlatform modelViewController, const EnvironmentDirectory& environmentDirectory) noexcept
    : ParentType{ modelViewController, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::EngineMiddleLayerInterface::MiddleLayerSharedPtr Framework::EngineMiddleLayerInterface::CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<ClassType>(MiddleLayerInterfaceCreate::Init, middleLayerPlatform, environmentDirectory);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EngineMiddleLayerInterface)

void Framework::EngineMiddleLayerInterface::SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (networkManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (inputManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetObjectLogicManager(const MiddleLayerInterfaceSharedPtr& objectLogicManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectLogicManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (physicalModellingManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (messageManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetEventManager(const MiddleLayerInterfaceSharedPtr& eventManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (eventManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (systemManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetResourceManager(const MiddleLayerInterfaceSharedPtr& resourceManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (resourceManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetAudioManager(const MiddleLayerInterfaceSharedPtr& audioManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (audioManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetCameraSystemsManager(const MiddleLayerInterfaceSharedPtr& cameraSystemsManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraSystemsManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetRenderingManager(const MiddleLayerInterfaceSharedPtr& renderingManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderingManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetGUIManager(const MiddleLayerInterfaceSharedPtr& guiManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (guiManager != nullptr)
    {
        ThrowException();
    }
}

void Framework::EngineMiddleLayerInterface::SetEngineManager(const MiddleLayerInterfaceSharedPtr& engineManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (engineManager != nullptr)
    {
        ThrowException();
    }
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetNetworkManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetNetworkManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetNetworkManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetInputManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetInputManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetInputManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetObjectLogicManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetObjectLogicManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetObjectLogicManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetPhysicalModellingManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetPhysicalModellingManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetPhysicalModellingManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetMessageManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetMessageManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetMessageManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetEventManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetEventManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetEventManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetSystemManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetSystemManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetSystemManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetResourceManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetResourceManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetResourceManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetAudioManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetAudioManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetAudioManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetCameraSystemsManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetCameraSystemsManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetCameraSystemsManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetRenderingManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetRenderingManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetRenderingManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetGUIManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetGUIManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetGUIManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetEngineManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetEngineManager());
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetEngineManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::ThrowException()
{
    THROW_EXCEPTION(SYSTEM_TEXT("EngineMiddleLayerInterface 函数被禁止调用。"s));
}