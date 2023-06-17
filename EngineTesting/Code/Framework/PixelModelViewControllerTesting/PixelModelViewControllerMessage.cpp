///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:33)

#include "PixelModelViewControllerMessage.h"
#include "Testing.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/ControllerMiddleLayerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

PixelModelViewController::PixelModelViewControllerMessage::PixelModelViewControllerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType(delta, environmentDirectory), alloc(CoreTools::ConsoleAlloc::Create())
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(PixelModelViewController, PixelModelViewControllerMessage)
