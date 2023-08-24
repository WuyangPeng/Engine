///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 14:38)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H

#include "ObjectLogicManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename ObjectLogic, typename ArtificialIntelligence>
Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::ObjectLogicManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, objectLogic{ middleLayerPlatform, environmentDirectory }, artificialIntelligence{ middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename ObjectLogic, typename ArtificialIntelligence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ObjectLogic, typename ArtificialIntelligence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::PreCreate() &&
        objectLogic.PreCreate() &&
        artificialIntelligence.PreCreate())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ObjectLogic, typename ArtificialIntelligence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Initialize() &&
        objectLogic.Initialize() &&
        artificialIntelligence.Initialize())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ParentType::PreIdle();
    objectLogic.PreIdle();
    artificialIntelligence.PreIdle();
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ParentType::Terminate();
    objectLogic.Terminate();
    artificialIntelligence.Terminate();
}

template <typename ObjectLogic, typename ArtificialIntelligence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Create(environmentParameter) && objectLogic.Create(environmentParameter) && artificialIntelligence.Create(environmentParameter))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ObjectLogic, typename ArtificialIntelligence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Destroy() && objectLogic.Destroy() && artificialIntelligence.Destroy())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ObjectLogic, typename ArtificialIntelligence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::Idle(int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Idle(timeDelta) && objectLogic.Idle(timeDelta) && artificialIntelligence.Idle(timeDelta))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ParentType::SetSystemManager(systemManager);
    objectLogic.SetSystemManager(systemManager);
    artificialIntelligence.SetSystemManager(systemManager);
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ParentType::SetPhysicalModellingManager(physicalModellingManager);
    objectLogic.SetPhysicalModellingManager(physicalModellingManager);
    artificialIntelligence.SetPhysicalModellingManager(physicalModellingManager);
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ParentType::SetMessageManager(messageManager);
    objectLogic.SetMessageManager(messageManager);
    artificialIntelligence.SetMessageManager(messageManager);
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ParentType::SetInputManager(inputManager);
    objectLogic.SetInputManager(inputManager);
    artificialIntelligence.SetInputManager(inputManager);
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    ParentType::SetNetworkManager(networkManager);
    objectLogic.SetNetworkManager(networkManager);
    artificialIntelligence.SetNetworkManager(networkManager);
}

#endif  // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H
