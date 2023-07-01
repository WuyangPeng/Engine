///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 15:10)

#include "ResourceProjectManagerMock.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ResourceProjectManagerMock::ResourceProjectManagerSharedPtr Framework::ResourceProjectManagerMock::CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<ClassType>(middleLayerPlatform, environmentDirectory);
}

Framework::ResourceProjectManagerMock::ResourceProjectManagerMock(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      printEngineering{ 0 }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ResourceProjectManagerMock)

bool Framework::ResourceProjectManagerMock::IsSelectValid(int select) const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(select);

    return true;
}

System::String Framework::ResourceProjectManagerMock::GetEngineeringName(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(select);

    if (select == 0)
        return SYSTEM_TEXT("WindowsAPIFrameTesting");
    else
        return SYSTEM_TEXT("InvalidTesting");
}

void Framework::ResourceProjectManagerMock::PrintEngineering(const String& engineeringName) const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::UnusedFunction(engineeringName);

    ++printEngineering;
}

void Framework::ResourceProjectManagerMock::Clear() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    printEngineering = 0;
}

int Framework::ResourceProjectManagerMock::GetPrintEngineering() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return printEngineering;
}
