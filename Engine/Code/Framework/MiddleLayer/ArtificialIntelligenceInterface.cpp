///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:24)

#include "Framework/FrameworkExport.h"

#include "ArtificialIntelligenceInterface.h"
#include "Flags/ObjectLogicManagerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::ArtificialIntelligenceInterface::ArtificialIntelligenceInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ System::EnumCastUnderlying(ObjectLogicMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ArtificialIntelligenceInterface)

ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ArtificialIntelligence, ObjectLogic, Input)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ArtificialIntelligence, ObjectLogic, Network)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ArtificialIntelligence, ObjectLogic, PhysicalModelling)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ArtificialIntelligence, ObjectLogic, Message)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ArtificialIntelligence, ObjectLogic, System)