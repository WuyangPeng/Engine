///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:19)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H

#include "ObjectLogicManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename ObjectLogic, typename ArtificialIntelligence>
Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::ObjectLogicManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, objectLogic{ middleLayerPlatform, environmentDirectory }, artificialIntellegence{ middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
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
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::PreCreate() &&
        objectLogic.PreCreate() &&
        artificialIntellegence.PreCreate())
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
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Initialize() &&
        objectLogic.Initialize() &&
        artificialIntellegence.Initialize())
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
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::PreIdle();
    objectLogic.PreIdle();
    artificialIntellegence.PreIdle();
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::Terminate();
    objectLogic.Terminate();
    artificialIntellegence.Terminate();
}

template <typename ObjectLogic, typename ArtificialIntelligence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Create(environmentParameter) && objectLogic.Create(environmentParameter) && artificialIntellegence.Create(environmentParameter))
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
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Destroy() && objectLogic.Destroy() && artificialIntellegence.Destroy())
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
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Idle(timeDelta) && objectLogic.Idle(timeDelta) && artificialIntellegence.Idle(timeDelta))
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
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::SetSystemManager(systemManager);
    objectLogic.SetSystemManager(systemManager);
    artificialIntellegence.SetSystemManager(systemManager);
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::SetPhysicalModellingManager(physicalModellingManager);
    objectLogic.SetPhysicalModellingManager(physicalModellingManager);
    artificialIntellegence.SetPhysicalModellingManager(physicalModellingManager);
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::SetMessageManager(messageManager);
    objectLogic.SetMessageManager(messageManager);
    artificialIntellegence.SetMessageManager(messageManager);
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::SetInputManager(inputManager);
    objectLogic.SetInputManager(inputManager);
    artificialIntellegence.SetInputManager(inputManager);
}

template <typename ObjectLogic, typename ArtificialIntelligence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntelligence>::SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::SetNetworkManager(networkManager);
    objectLogic.SetNetworkManager(networkManager);
    artificialIntellegence.SetNetworkManager(networkManager);
}

#endif  // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H
