///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/09 11:37)

/// 原始文件在SystemTesting下，SystemWindowsTesting下的为自动复制文件，请勿修改。
#include "ResourceEnumTesting.h"
#include "System/DynamicLink/EnumResourceTools.h"
#include "System/DynamicLink/Flags/EnumResourceToolsFlags.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ResourceEnumTesting::ResourceEnumTesting(const OStreamShared& stream)
    : ParentType{ stream },
      // 这里不测试ResourceEnum::Mui、ResourceEnum::MuiSystem
      resourceEnum{ ResourceEnum::Default,
                    ResourceEnum::Ln,
                    ResourceEnum::Validate,
                    ResourceEnum::ModouleExact,
                    ResourceEnum::Ln | ResourceEnum::Validate,
                    ResourceEnum::Validate | ResourceEnum::ModouleExact },
      index{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ResourceEnumTesting)

void System::ResourceEnumTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ResourceEnumTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadTestingLibrary);

    ASSERT_NOT_THROW_EXCEPTION_0(EnumResourceTest);

    ASSERT_NOT_THROW_EXCEPTION_0(FreeTestingLibrary);

    // SystemWindowsTesting有dllModule为instance的测试。
}

void System::ResourceEnumTesting::EnumResourceTest()
{
    for (index = 0u; index < resourceEnum.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(DoEnumResourceTest);
    }
}

void System::ResourceEnumTesting::DoEnumResourceTest()
{
    constexpr LanguageIDData languageIDData{};

    ASSERT_TRUE(EnumResourceTypesInLibrary(GetDllModule(), TypeProcess, reinterpret_cast<WindowsLongPtrSizeType>(this), GetCurrentResourceEnum(), languageIDData));

    ASSERT_LESS(0u, GetEnumResourceDataSize());

    for (const auto& data : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(EnumResourceExistTest, data);
    }

    ClearEnumResourceData();
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

System::WindowsBool System::ResourceEnumTesting::TypeProcess(DynamicLinkModule module, DynamicLinkCharType* type, WindowsLongPtrSizeType lParam)
{
    constexpr LanguageIDData languageIDData{};

    const auto* testing = GetSelf(lParam);

    if (testing != nullptr)
    {
        return EnumResourceNamesInLibrary(module, type, NameProcess, lParam, testing->GetCurrentResourceEnum(), languageIDData);
    }
    else
    {
        return gFalse;
    }
}

System::WindowsBool System::ResourceEnumTesting::NameProcess(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowsLongPtrSizeType lParam)
{
    constexpr LanguageIDData languageIDData{};

    const auto* testing = GetSelf(lParam);

    if (testing != nullptr)
    {
        return EnumResourceLanguagesInLibrary(module, type, name, LanguageProcess, lParam, testing->GetCurrentResourceEnum(), languageIDData);
    }
    else
    {
        return gFalse;
    }
}

#include STSTEM_WARNING_POP

System::WindowsBool System::ResourceEnumTesting::LanguageProcess(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language, WindowsLongPtrSizeType lParam)
{
    UnusedFunction(module);

    auto testing = GetSelf(lParam);

    if (testing != nullptr)
    {
        testing->AddEnumResourceData(type, name, language);
    }

    return gTrue;
}

System::ResourceEnum System::ResourceEnumTesting::GetCurrentResourceEnum() const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return resourceEnum.at(index);
}

void System::ResourceEnumTesting::EnumResourceExistTest(const EnumResourceData& data)
{
    const auto resource = FindResourceInLibrary(GetDllModule(), data.GetType(), data.GetName(), data.GetLanguage());

    ASSERT_UNEQUAL_NULL_PTR(resource);
}

System::ResourceEnumTesting* System::ResourceEnumTesting::GetSelf(WindowsLongPtrSizeType lParam) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<ClassType*>(lParam);

#include STSTEM_WARNING_POP
}
