///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:29)

#include "Framework/FrameworkExport.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::move;
using namespace std::literals;

Framework::EngineMiddleLayerInterface::EngineMiddleLayerInterface(MiddleLayerPlatform modelViewController) noexcept
    : ParentType{ modelViewController }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::EngineMiddleLayerInterface::EngineMiddleLayerInterface(EngineMiddleLayerInterface&& rhs) noexcept
    : ParentType{ move(rhs) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::EngineMiddleLayerInterface& Framework::EngineMiddleLayerInterface::operator=(EngineMiddleLayerInterface&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ParentType::operator=(move(rhs));

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EngineMiddleLayerInterface)

void Framework::EngineMiddleLayerInterface::SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (networkManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (inputManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetObjectLogicManager(const MiddleLayerInterfaceSharedPtr& objectLogicManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (objectLogicManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (physicalModellingManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (messageManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetEventManager(const MiddleLayerInterfaceSharedPtr& eventManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (eventManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (systemManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetResourceManager(const MiddleLayerInterfaceSharedPtr& resourceManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (resourceManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetAudioManager(const MiddleLayerInterfaceSharedPtr& audioManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (audioManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetCameraSystemsManager(const MiddleLayerInterfaceSharedPtr& cameraSystemsManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (cameraSystemsManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetRenderingManager(const MiddleLayerInterfaceSharedPtr& renderingManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderingManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetGUIManager(const MiddleLayerInterfaceSharedPtr& guiManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (guiManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

void Framework::EngineMiddleLayerInterface::SetEngineManager(const MiddleLayerInterfaceSharedPtr& engineManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (engineManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
    }
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetNetworkManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetNetworkManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetInputManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetInputManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetObjectLogicManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetObjectLogicManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetPhysicalModellingManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetPhysicalModellingManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetMessageManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetMessageManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetEventManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetEventManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetSystemManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetSystemManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetResourceManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetResourceManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetAudioManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetAudioManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetCameraSystemsManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetCameraSystemsManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetRenderingManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetRenderingManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetGUIManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetGUIManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetEngineManager()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterface::GetEngineManager() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"s));
}
