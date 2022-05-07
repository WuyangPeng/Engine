///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 15:51)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H

#include "ObjectLogicManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename ObjectLogic, typename ArtificialIntellegence>
Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::ObjectLogicManager(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }, objectLogic{ middleLayerPlatform }, artificialIntellegence{ middleLayerPlatform }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename ObjectLogic, typename ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ObjectLogic, typename ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::PreCreate(environmentDirectory) &&
        objectLogic.PreCreate(environmentDirectory) &&
        artificialIntellegence.PreCreate(environmentDirectory))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ObjectLogic, typename ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::Initialize()
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

template <typename ObjectLogic, typename ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::PreIdle();
    objectLogic.PreIdle();
    artificialIntellegence.PreIdle();
}

template <typename ObjectLogic, typename ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::Terminate();
    objectLogic.Terminate();
    artificialIntellegence.Terminate();
}

template <typename ObjectLogic, typename ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::Create()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Create() && objectLogic.Create() && artificialIntellegence.Create())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ObjectLogic, typename ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::Destroy()
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

template <typename ObjectLogic, typename ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::Idle(int64_t timeDelta)
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

template <typename ObjectLogic, typename ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::SetSystemManager(systemManager);
    objectLogic.SetSystemManager(systemManager);
    artificialIntellegence.SetSystemManager(systemManager);
}

template <typename ObjectLogic, typename ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::SetPhysicalModellingManager(physicalModellingManager);
    objectLogic.SetPhysicalModellingManager(physicalModellingManager);
    artificialIntellegence.SetPhysicalModellingManager(physicalModellingManager);
}

template <typename ObjectLogic, typename ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::SetMessageManager(messageManager);
    objectLogic.SetMessageManager(messageManager);
    artificialIntellegence.SetMessageManager(messageManager);
}

template <typename ObjectLogic, typename ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::SetInputManager(inputManager);
    objectLogic.SetInputManager(inputManager);
    artificialIntellegence.SetInputManager(inputManager);
}

template <typename ObjectLogic, typename ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>::SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::SetNetworkManager(networkManager);
    objectLogic.SetNetworkManager(networkManager);
    artificialIntellegence.SetNetworkManager(networkManager);
}

#endif  // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H
