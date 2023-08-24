///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 16:24)

#include "Framework/FrameworkExport.h"

#include "ObjectLogicInterface.h"
#include "Flags/ObjectLogicManagerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ObjectLogicInterface::ObjectLogicInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ System::EnumCastUnderlying(ObjectLogicMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ObjectLogicInterface)

ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ObjectLogic, ObjectLogic, Input)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ObjectLogic, ObjectLogic, Network)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ObjectLogic, ObjectLogic, PhysicalModelling)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ObjectLogic, ObjectLogic, Message)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ObjectLogic, ObjectLogic, System)