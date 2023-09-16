///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:04)

/// ԭʼ�ļ���SystemTesting�£�SystemWindowsTesting�µ�Ϊ�Զ������ļ��������޸ġ�
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
      // ���ﲻ����ResourceEnum::Mui��ResourceEnum::MuiSystem
      resourceEnum{ ResourceEnum::Default,
                    ResourceEnum::Ln,
                    ResourceEnum::Validate,
                    ResourceEnum::ModuleExact,
                    ResourceEnum::Ln | ResourceEnum::Validate,
                    ResourceEnum::Validate | ResourceEnum::ModuleExact },
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

    // SystemWindowsTesting��dllModuleΪinstance�Ĳ��ԡ�
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
    constexpr LanguageIdData languageIdData{};

    ASSERT_TRUE(EnumResourceTypesInLibrary(GetDllModule(), TypeProcess, reinterpret_cast<WindowsLongPtrSizeType>(this), GetCurrentResourceEnum(), languageIdData));

    ASSERT_LESS(0u, GetEnumResourceDataSize());

    for (const auto& data : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(EnumResourceExistTest, data);
    }

    ClearEnumResourceData();
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

System::WindowsBool System::ResourceEnumTesting::TypeProcess(DynamicLinkModule module, DynamicLinkCharType* type, WindowsLongPtrSizeType lParam)
{
    constexpr LanguageIdData languageIdData{};

    if (const auto* testing = GetSelf(lParam);
        testing != nullptr)
    {
        return EnumResourceNamesInLibrary(module, type, NameProcess, lParam, testing->GetCurrentResourceEnum(), languageIdData);
    }
    else
    {
        return gFalse;
    }
}

System::WindowsBool System::ResourceEnumTesting::NameProcess(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowsLongPtrSizeType lParam)
{
    constexpr LanguageIdData languageIdData{};

    if (const auto* testing = GetSelf(lParam);
        testing != nullptr)
    {
        return EnumResourceLanguagesInLibrary(module, type, name, LanguageProcess, lParam, testing->GetCurrentResourceEnum(), languageIdData);
    }
    else
    {
        return gFalse;
    }
}

#include SYSTEM_WARNING_POP

System::WindowsBool System::ResourceEnumTesting::LanguageProcess(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language, WindowsLongPtrSizeType lParam)
{
    UnusedFunction(module);

    if (const auto testing = GetSelf(lParam);
        testing != nullptr)
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
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<ClassType*>(lParam);

#include SYSTEM_WARNING_POP
}
