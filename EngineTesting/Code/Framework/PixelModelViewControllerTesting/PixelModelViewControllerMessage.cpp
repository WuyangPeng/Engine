///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 17:07)

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
