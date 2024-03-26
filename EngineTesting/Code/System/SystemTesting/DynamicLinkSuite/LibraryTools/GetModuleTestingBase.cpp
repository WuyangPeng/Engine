/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:29)

#include "GetModuleTestingBase.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetModuleTestingBase::GetModuleTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetModuleTestingBase)

System::DynamicLinkString System::GetModuleTestingBase::GetResourcesLibraryName()
{
    return GetResource() + DYNAMIC_LINK_TEXT("/") + GetResourcesLibrary() + CoreTools::StringConversion::StandardConversionDynamicLinkString(GetEngineeringSuffix());
}

System::DynamicLinkModule System::GetModuleTestingBase::GetDynamicLibrary()
{
    const auto resourcesLibraryDll = GetResourcesLibraryName();

    return LoadDynamicLibrary(resourcesLibraryDll.c_str(), LoadLibraryType::DoNotResolveDllReferences);
}

void System::GetModuleTestingBase::Destroy(DynamicLinkModule dynamicLinkModule)
{
    ASSERT_TRUE(FreeDynamicLibrary(dynamicLinkModule));
}

System::DynamicLinkString System::GetModuleTestingBase::GetResource()
{
    return DYNAMIC_LINK_TEXT("Resource");
}

System::DynamicLinkString System::GetModuleTestingBase::GetResourcesLibrary()
{
    return DYNAMIC_LINK_TEXT("ResourcesLibrary");
}
