/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 21:34)

#include "ResourceTestingBase.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/System/ResourcesLibrary/resource.h"

System::ResourceTestingBase::ResourceTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      container{ { static_cast<WindowsWord>(IDI_ICON1), predefinedResourceTypesGroupIcon },
                 { static_cast<WindowsWord>(IDI_ICON2), predefinedResourceTypesGroupIcon },
                 { static_cast<WindowsWord>(IDC_CURSOR1), predefinedResourceTypesGroupCursor },
                 { static_cast<WindowsWord>(IDC_CURSOR2), predefinedResourceTypesGroupCursor },
                 { static_cast<WindowsWord>(IDB_BITMAP1), predefinedResourceTypesBitmap },
                 { static_cast<WindowsWord>(IDR_MENU1), predefinedResourceTypesMenu } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ResourceTestingBase)

System::ResourceTestingBase::TypeNameContainerConstIter System::ResourceTestingBase::begin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return container.cbegin();
}

System::ResourceTestingBase::TypeNameContainerConstIter System::ResourceTestingBase::end() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return container.cend();
}
