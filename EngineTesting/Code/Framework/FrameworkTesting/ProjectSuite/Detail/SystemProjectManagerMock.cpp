///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 14:11)

#include "SystemProjectManagerMock.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::SystemProjectManagerMock::SystemProjectManagerSharedPtr Framework::SystemProjectManagerMock::CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<ClassType>(middleLayerPlatform, environmentDirectory);
}

Framework::SystemProjectManagerMock::SystemProjectManagerMock(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      execute{ 0 }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SystemProjectManagerMock)

void Framework::SystemProjectManagerMock::Execute(int select) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    execute = select;
}

int Framework::SystemProjectManagerMock::GetExecute() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return execute;
}

void Framework::SystemProjectManagerMock::Clear() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    execute = 0;
}
