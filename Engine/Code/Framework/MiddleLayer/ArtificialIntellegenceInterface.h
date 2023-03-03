///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 16:13)

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
    class FRAMEWORK_DEFAULT_DECLARE ArtificialIntellegenceInterface : public EngineMiddleLayerInterface
    {
    public:
        using ArtificialIntellegenceInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(ArtificialIntellegenceInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        explicit ArtificialIntellegenceInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(PhysicalModelling);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

    private:
        PackageType impl;
    };

    using ArtificialIntellegenceInterfaceSharedPtr = std::shared_ptr<ArtificialIntellegenceInterface>;
    using ConstArtificialIntellegenceInterfaceSharedPtr = std::shared_ptr<const ArtificialIntellegenceInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_INTERFACE_H
