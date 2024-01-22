/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 22:58)

#include "Framework/FrameworkExport.h"

#include "SystemManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::SystemManagerImpl::SystemManagerImpl(DisableNotThrow disableNotThrow)
    : environment{ Environment::Create() }
{
    System::UnusedFunction(disableNotThrow);

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, SystemManagerImpl)
