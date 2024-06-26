///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 19:19)

#ifndef FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_H
#define FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_H

#include "ChildHelperInterfaceImpl.h"
#include "ChildHelperMiddleLayerFlags.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"
#include "Framework/MiddleLayer/EngineMiddleLayerInterface.h"

namespace Framework
{
    class ChildHelperInterface final : public EngineMiddleLayerInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(ChildHelperInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        ChildHelperInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Event)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Resource)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Audio)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(CameraSystems)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Rendering)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Engine)

    public:
        // 开启protected接口为public，以供测试。
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetManager(ChildHelperMiddleLayer childHelperMiddleLayer) const;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_H
