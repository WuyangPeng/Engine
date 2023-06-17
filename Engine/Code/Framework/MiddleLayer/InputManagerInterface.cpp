///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:25)

#include "Framework/FrameworkExport.h"

#include "InputManagerInterface.h"
#include "Flags/InputMiddleLayerFlags.h"
#include "Flags/MiddleLayerPlatformFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::InputManagerInterface::InputManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ System::EnumCastUnderlying(InputMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, InputManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, Network)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, ObjectLogic)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, System)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, CameraSystems)

bool Framework::InputManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Paint();
}

bool Framework::InputManagerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Move(point);
}

bool Framework::InputManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Resize(windowDisplay, size);
}
