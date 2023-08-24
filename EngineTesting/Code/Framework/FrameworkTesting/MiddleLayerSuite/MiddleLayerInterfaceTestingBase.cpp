///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 10:45)

#include "MiddleLayerInterfaceTestingBase.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

Framework::MiddleLayerInterfaceTestingBase::MiddleLayerInterfaceTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      middleLayerPlatform{ MiddleLayerPlatform::Windows },
      environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") },
      point{ 100, 200 },
      size{ 1024, 768 },
      virtualKeysTypes{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MiddleLayerInterfaceTestingBase)

Framework::MiddleLayerPlatform Framework::MiddleLayerInterfaceTestingBase::GetMiddleLayerPlatform() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return middleLayerPlatform;
}

Framework::EnvironmentDirectory Framework::MiddleLayerInterfaceTestingBase::GetEnvironmentDirectory() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return environmentDirectory;
}

Framework::WindowPoint Framework::MiddleLayerInterfaceTestingBase::GetWindowPoint() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return point;
}

Framework::WindowSize Framework::MiddleLayerInterfaceTestingBase::GetWindowSize() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return size;
}
