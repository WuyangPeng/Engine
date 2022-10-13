///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 10:56)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE ObjectLogicInterface : public EngineMiddleLayerInterface
    {
    public:
        using ObjectLogicInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(ObjectLogicInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        ObjectLogicInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(PhysicalModelling);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

    private:
        PackageType impl;
    };

    using ObjectLogicInterfaceSharedPtr = std::shared_ptr<ObjectLogicInterface>;
    using ConstObjectLogicInterfaceSharedPtr = std::shared_ptr<const ObjectLogicInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_INTERFACE_H
