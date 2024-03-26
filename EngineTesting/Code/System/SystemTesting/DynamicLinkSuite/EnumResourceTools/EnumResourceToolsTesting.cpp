/// 原始文件在SystemTesting下，SystemWindowsTesting下的为自动复制文件，请勿修改。

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:24)

#include "EnumResourceToolsTesting.h"
#include "System/DynamicLink/EnumResourceTools.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumResourceToolsTesting::EnumResourceToolsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumResourceToolsTesting)

void System::EnumResourceToolsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadTestingLibrary);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(FreeTestingLibrary);
}

void System::EnumResourceToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EnumResourceTest);
}

void System::EnumResourceToolsTesting::EnumResourceTest()
{
    ASSERT_TRUE(EnumResourceTypesInLibrary(GetDllModule(), TypeProcess, reinterpret_cast<WindowsLongPtrSizeType>(this)));

    ASSERT_LESS(0u, GetEnumResourceDataSize());

    for (const auto& data : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(EnumResourceExistTest, data);
    }
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

System::WindowsBool System::EnumResourceToolsTesting::TypeProcess(DynamicLinkModule module, DynamicLinkCharType* type, WindowsLongPtrSizeType lParam) noexcept
{
    return EnumResourceNamesInLibrary(module, type, NameProcess, lParam);
}

System::WindowsBool System::EnumResourceToolsTesting::NameProcess(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowsLongPtrSizeType lParam) noexcept
{
    return EnumResourceLanguagesInLibrary(module, type, name, LanguageProcess, lParam);
}

#include SYSTEM_WARNING_POP

System::WindowsBool System::EnumResourceToolsTesting::LanguageProcess(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language, WindowsLongPtrSizeType lParam)
{
    UnusedFunction(module);

    if (const auto testing = GetBase(lParam);
        testing != nullptr)
    {
        testing->AddEnumResourceData(type, name, language);
    }

    return gTrue;
}

void System::EnumResourceToolsTesting::EnumResourceExistTest(const EnumResourceData& data)
{
    const auto resource = FindResourceInLibrary(GetDllModule(), data.GetType(), data.GetName(), data.GetLanguage());

    ASSERT_UNEQUAL_NULL_PTR(resource);
}
