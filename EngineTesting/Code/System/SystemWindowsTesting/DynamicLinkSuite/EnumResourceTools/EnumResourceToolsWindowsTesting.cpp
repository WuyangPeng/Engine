///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/03/31 12:52)

#include "EnumResourceToolsWindowsTesting.h"
#include "System/DynamicLink/EnumResourceTools.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumResourceToolsWindowsTesting::EnumResourceToolsWindowsTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, enumResourceDataGroup{}, instance{ instance }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumResourceToolsWindowsTesting)

void System::EnumResourceToolsWindowsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumResourceToolsWindowsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EnumResourceTest);
}

void System::EnumResourceToolsWindowsTesting::EnumResourceTest()
{
    ASSERT_TRUE(EnumResourceTypesInLibrary(instance, TypeProcess, reinterpret_cast<WindowsPtrLong>(this)));

    ASSERT_LESS(0u, enumResourceDataGroup.size());

    for (const auto& data : enumResourceDataGroup)
    {
        auto resource = FindResourceInLibrary(instance, data.GetType(), data.GetName(), data.GetLanguage());

        ASSERT_UNEQUAL_NULL_PTR(resource);
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

System::WindowsBool System::EnumResourceToolsWindowsTesting::TypeProcess(DynamicLinkModule module, DynamicLinkCharType* type, WindowsPtrLong lParam) noexcept
{
    return EnumResourceNamesInLibrary(module, type, NameProcess, lParam);
}

System::WindowsBool System::EnumResourceToolsWindowsTesting::NameProcess(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowsPtrLong lParam) noexcept
{
    return EnumResourceLanguagesInLibrary(module, type, name, LanguageProcess, lParam);
}

#include STSTEM_WARNING_POP

System::WindowsBool System::EnumResourceToolsWindowsTesting::LanguageProcess(MAYBE_UNUSED DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language, WindowsPtrLong lParam)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    auto testing = reinterpret_cast<ClassType*>(lParam);
#include STSTEM_WARNING_POP

    testing->AddEnumResourceData(EnumResourceData{ type, name, language });

    return g_True;
}

void System::EnumResourceToolsWindowsTesting::AddEnumResourceData(const EnumResourceData& data)
{
    SYSTEM_CLASS_IS_VALID_1;

    enumResourceDataGroup.emplace_back(data);
}
