///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/19 15:10)

#include "GUIProjectManagerMock.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::GUIProjectManagerMock::GUIProjectManagerSharedPtr Framework::GUIProjectManagerMock::CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<ClassType>(middleLayerPlatform, environmentDirectory);
}

Framework::GUIProjectManagerMock::GUIProjectManagerMock(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      printSelect{ 0 },
      printEngineering{ 0 }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GUIProjectManagerMock)

void Framework::GUIProjectManagerMock::PrintSelect(const ProjectName& projectName) const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(projectName);

    ++printSelect;
}

void Framework::GUIProjectManagerMock::PrintEngineering(const String& engineeringName) const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(engineeringName);

    ++printEngineering;
}

void Framework::GUIProjectManagerMock::Clear() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    printSelect = 0;
    printEngineering = 0;
}

int Framework::GUIProjectManagerMock::GetPrintSelect() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return printSelect;
}

int Framework::GUIProjectManagerMock::GetPrintEngineering() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return printEngineering;
}