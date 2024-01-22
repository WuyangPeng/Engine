/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:03)

#include "Framework/FrameworkExport.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Framework::EngineMiddleLayerInterface::EngineMiddleLayerInterface(MiddleLayerPlatform modelViewController, const EnvironmentDirectory& environmentDirectory) noexcept
    : ParentType{ modelViewController, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EngineMiddleLayerInterface)

void Framework::EngineMiddleLayerInterface::SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(networkManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(inputManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetObjectLogicManager(const MiddleLayerInterfaceSharedPtr& objectLogicManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(objectLogicManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(physicalModellingManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetEventManager(const MiddleLayerInterfaceSharedPtr& eventManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(systemManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetResourceManager(const MiddleLayerInterfaceSharedPtr& resourceManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(resourceManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetAudioManager(const MiddleLayerInterfaceSharedPtr& audioManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(audioManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetCameraSystemsManager(const MiddleLayerInterfaceSharedPtr& cameraSystemsManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(cameraSystemsManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetRenderingManager(const MiddleLayerInterfaceSharedPtr& renderingManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(renderingManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetGUIManager(const MiddleLayerInterfaceSharedPtr& guiManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(guiManager);

    ThrowException();
}

void Framework::EngineMiddleLayerInterface::SetEngineManager(const MiddleLayerInterfaceSharedPtr& engineManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(engineManager);

    ThrowException();
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
    THROW_EXCEPTION(SYSTEM_TEXT("EngineMiddleLayerInterface ��������ֹ���á�"s))
}