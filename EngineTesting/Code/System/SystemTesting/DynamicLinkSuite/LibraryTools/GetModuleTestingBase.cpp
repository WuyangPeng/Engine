///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/09 13:55)

#include "GetModuleTestingBase.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::GetModuleTestingBase::GetModuleTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetModuleTestingBase)

System::DynamicLinkString System::GetModuleTestingBase::GetResourcesLibraryName()
{
    return GetResource() + DYNAMIC_LINK_TEXT("/"s) + GetResourcesLibrary() + CoreTools::StringConversion::StandardConversionDynamicLinkString(GetEngineeringSuffix());
}

System::DynamicLinkModule System::GetModuleTestingBase::GetDynamicLibrary()
{
    const auto resourcesLibraryDll = GetResourcesLibraryName();

    return LoadDynamicLibrary(resourcesLibraryDll.c_str(), LoadLibraryType::DontResolveDllReferences);
}

void System::GetModuleTestingBase::Destroy(DynamicLinkModule dynamicLinkModule)
{
    ASSERT_TRUE(FreeDynamicLibrary(dynamicLinkModule));
}

System::DynamicLinkString System::GetModuleTestingBase::GetResource()
{
    return DYNAMIC_LINK_TEXT("Resource"s);
}

System::DynamicLinkString System::GetModuleTestingBase::GetResourcesLibrary()
{
    return DYNAMIC_LINK_TEXT("ResourcesLibrary"s);
}
