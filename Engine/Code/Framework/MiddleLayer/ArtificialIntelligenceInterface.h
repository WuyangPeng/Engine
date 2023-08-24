///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/05 16:13)

#ifndef FRAMEWORK_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE ArtificialIntelligenceInterface : public EngineMiddleLayerInterface
    {
    public:
        using ArtificialIntelligenceInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(ArtificialIntelligenceInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        ArtificialIntelligenceInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(PhysicalModelling)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message)
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System)

    private:
        PackageType impl;
    };

    using ArtificialIntelligenceInterfaceSharedPtr = std::shared_ptr<ArtificialIntelligenceInterface>;
    using ConstArtificialIntelligenceInterfaceSharedPtr = std::shared_ptr<const ArtificialIntelligenceInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_INTERFACE_H
