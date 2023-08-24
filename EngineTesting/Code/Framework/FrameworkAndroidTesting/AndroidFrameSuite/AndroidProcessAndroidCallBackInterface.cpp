///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 14:27)

#include "AndroidProcessAndroidCallBackInterface.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"

Framework::AndroidProcessAndroidCallBackInterface::AndroidProcessAndroidCallBackInterface(int64_t delta) noexcept
    : ParentType{ delta }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidProcessAndroidCallBackInterface);

namespace Framework
{

    template <>
    AndroidProcess<AndroidProcessAndroidCallBackInterface>::AndroidProcess(int64_t delta)
    {
        FRAMEWORK_SELF_CLASS_IS_VALID_9;

        System::UnusedFunction(delta);

        CoreTools::DisableNoexcept();
    }

    template <>
    AndroidProcess<AndroidProcessAndroidCallBackInterface>::~AndroidProcess() noexcept
    {
        FRAMEWORK_SELF_CLASS_IS_VALID_9;
    }
}
