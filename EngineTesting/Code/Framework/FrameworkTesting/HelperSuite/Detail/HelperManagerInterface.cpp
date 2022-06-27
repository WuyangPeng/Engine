///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 11:04)

#include "HelperManagerInterface.h"
#include "HelperManagerInterfaceImpl.h"
#include "HelperMiddleLayerFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::HelperManagerInterface::HelperManagerInterface(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }, impl{ System::EnumCastUnderlying(HelperMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, HelperManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, ObjectLogic)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Message)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Event)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Resource)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Audio)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, CameraSystems)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Rendering)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Engine)

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::HelperManagerInterface::GetManager(HelperMiddleLayer helperMiddleLayer) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetMiddleLayerInterface(System::EnumCastUnderlying(helperMiddleLayer));
}
