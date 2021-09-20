///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/03/30 15:56)

#include "EnumResourceToolsTesting.h"
#include "System/DynamicLink/EnumResourceTools.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumResourceToolsTesting::EnumResourceToolsTesting(const OStreamShared& stream)
    : ParentType{ stream }, enumResourceDataGroup{}
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumResourceToolsTesting)

void System::EnumResourceToolsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumResourceToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadTestingLibrary);
    ASSERT_NOT_THROW_EXCEPTION_0(EnumResourceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FreeTestingLibrary);
}

void System::EnumResourceToolsTesting::EnumResourceTest()
{
    ASSERT_TRUE(EnumResourceTypesInLibrary(GetDllModule(), TypeProcess, reinterpret_cast<WindowsPtrLong>(this)));

    ASSERT_LESS(0u, enumResourceDataGroup.size());

    for (const auto& data : enumResourceDataGroup)
    {
        auto resource = FindResourceInLibrary(GetDllModule(), data.GetType(), data.GetName(), data.GetLanguage());

        ASSERT_UNEQUAL_NULL_PTR(resource);
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

System::WindowsBool System::EnumResourceToolsTesting::TypeProcess(DynamicLinkModule module, DynamicLinkCharType* type, WindowsPtrLong lParam) noexcept
{
    return EnumResourceNamesInLibrary(module, type, NameProcess, lParam);
}

System::WindowsBool System::EnumResourceToolsTesting::NameProcess(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowsPtrLong lParam) noexcept
{
    return EnumResourceLanguagesInLibrary(module, type, name, LanguageProcess, lParam);
}

#include STSTEM_WARNING_POP

System::WindowsBool System::EnumResourceToolsTesting::LanguageProcess(MAYBE_UNUSED DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language, WindowsPtrLong lParam)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    auto testing = reinterpret_cast<ClassType*>(lParam);
#include STSTEM_WARNING_POP

    testing->AddEnumResourceData(EnumResourceData{ type, name, language });

    return g_True;
}

void System::EnumResourceToolsTesting::AddEnumResourceData(const EnumResourceData& data)
{
    SYSTEM_CLASS_IS_VALID_1;

    enumResourceDataGroup.emplace_back(data);
}
