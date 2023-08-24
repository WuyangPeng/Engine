///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 14:01)

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
        ArtificialIntelligence artificialIntelligence;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_H
