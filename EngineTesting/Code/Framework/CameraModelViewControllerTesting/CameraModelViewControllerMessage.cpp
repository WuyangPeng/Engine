///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/23 17:21)

#include "CameraModelViewControllerMessage.h"
#include "Testing.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/CameraControllerMiddleLayerDetail.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

CameraModelViewController::CameraModelViewControllerMessage::CameraModelViewControllerMessage(int64_t delta)
    : ParentType{ delta }, alloc{ CoreTools::ConsoleAlloc::Create() }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CameraModelViewController, CameraModelViewControllerMessage)
