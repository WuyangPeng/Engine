///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/26 15:43)

#include "LoadResourceToolsTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LibraryTools.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using namespace std::literals;

System::LoadResourceToolsTesting::LoadResourceToolsTesting(const OStreamShared& stream)
    : ParentType{ stream }, m_DllModule{ nullptr }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadResourceToolsTesting)

void System::LoadResourceToolsTesting::LoadTestingLibrary()
{
    const auto resourcesLibrary = GetResourcesLibrary();

    const auto fullPath = DYNAMIC_LINK_TEXT("Resource/"s) + resourcesLibrary;

    m_DllModule = LoadDynamicLibrary(fullPath.c_str(), LoadLibraryType::DontResolveDllReferences);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(m_DllModule, "����ResourcesLibraryʧ��"s);
}

System::String System::LoadResourceToolsTesting::GetResourcesLibrary() const
{
    return DYNAMIC_LINK_TEXT("ResourcesLibrary"s) + GetEngineeringDynamicLinkSuffix();
}

void System::LoadResourceToolsTesting::FreeTestingLibrary()
{
    ASSERT_TRUE(FreeDynamicLibrary(m_DllModule));
}

System::DynamicLinkModule System::LoadResourceToolsTesting::GetDllModule() noexcept
{
    return m_DllModule;
}
