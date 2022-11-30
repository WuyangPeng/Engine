///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/09 22:26)

#include "EnumResourceToolsWindowsTesting.h"
#include "System/DynamicLink/EnumResourceTools.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumResourceToolsWindowsTesting::EnumResourceToolsWindowsTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, enumResourceDataContainer{}, instance{ instance }
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
    ASSERT_TRUE(EnumResourceTypesInLibrary(instance, TypeProcess, reinterpret_cast<WindowsLongPtrSizeType>(this)));

    ASSERT_LESS(0u, enumResourceDataContainer.size());

    for (const auto& data : enumResourceDataContainer)
    {
        auto resource = FindResourceInLibrary(instance, data.GetType(), data.GetName(), data.GetLanguage());

        ASSERT_UNEQUAL_NULL_PTR(resource);
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

System::WindowsBool System::EnumResourceToolsWindowsTesting::TypeProcess(DynamicLinkModule module, DynamicLinkCharType* type, WindowsLongPtrSizeType lParam) noexcept
{
    return EnumResourceNamesInLibrary(module, type, NameProcess, lParam);
}

System::WindowsBool System::EnumResourceToolsWindowsTesting::NameProcess(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowsLongPtrSizeType lParam) noexcept
{
    return EnumResourceLanguagesInLibrary(module, type, name, LanguageProcess, lParam);
}

#include STSTEM_WARNING_POP

System::WindowsBool System::EnumResourceToolsWindowsTesting::LanguageProcess(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language, WindowsLongPtrSizeType lParam)
{
    UnusedFunction(module);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto testing = reinterpret_cast<ClassType*>(lParam);

#include STSTEM_WARNING_POP

    testing->AddEnumResourceData(EnumResourceData{ type, name, language });

    return gTrue;
}

void System::EnumResourceToolsWindowsTesting::AddEnumResourceData(const EnumResourceData& data)
{
    SYSTEM_CLASS_IS_VALID_1;

    enumResourceDataContainer.emplace_back(data);
}
