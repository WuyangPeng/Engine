///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/09 21:04)

#include "ResourceWindowsTestingBase.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"
#include "System/SystemWindowsTesting/resource.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ResourceWindowsTestingBase::ResourceWindowsTestingBase(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream },
      instance{ instance },
      container{ { static_cast<WindowsWord>(IDI_TEST_ICON), predefinedResourceTypesGroupIcon },
                 { static_cast<WindowsWord>(IDC_TEST_CURSOR), predefinedResourceTypesGroupCursor },
                 { static_cast<WindowsWord>(IDB_TEST_BITMAP), predefinedResourceTypesBitmap },
                 { static_cast<WindowsWord>(IDR_TEST_MENU), predefinedResourceTypesMenu } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ResourceWindowsTestingBase)

System::ResourceWindowsTestingBase::TypeNameContainerConstIter System::ResourceWindowsTestingBase::begin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return container.cbegin();
}

System::ResourceWindowsTestingBase::TypeNameContainerConstIter System::ResourceWindowsTestingBase::end() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return container.cend();
}

System::WindowsHInstance System::ResourceWindowsTestingBase::GetInstance() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return instance;
}
