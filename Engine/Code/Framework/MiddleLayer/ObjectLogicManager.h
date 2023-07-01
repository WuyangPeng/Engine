///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:22)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_H

#include "ObjectLogicManagerInterface.h"

namespace Framework
{
    template <typename ObjectLogic, typename ArtificialIntelligence>
    class ObjectLogicManager : public ObjectLogicManagerInterface
    {
    public:
        using ClassType = ObjectLogicManager<ObjectLogic, ArtificialIntelligence>;
        using ParentType = ObjectLogicManagerInterface;
        using ClassShareType = CoreTools::NonCopyClasses;

    public:
        ObjectLogicManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool PreCreate() override;
        NODISCARD bool Initialize() override;
        void PreIdle() override;
        void Terminate() override;

        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Destroy() override;
        NODISCARD bool Idle(int64_t timeDelta) override;

        void SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager) override;
        void SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager) override;
        void SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager) override;
        void SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager) override;
        void SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager) override;

    private:
        ObjectLogic objectLogic;
        ArtificialIntelligence artificialIntellegence;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_H
