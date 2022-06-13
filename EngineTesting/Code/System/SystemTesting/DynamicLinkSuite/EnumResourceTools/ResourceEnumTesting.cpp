///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 12:47)

#include "ResourceEnumTesting.h"
#include "System/DynamicLink/EnumResourceTools.h"
#include "System/DynamicLink/Flags/EnumResourceToolsFlags.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ResourceEnumTesting::ResourceEnumTesting(const OStreamShared& stream)
    : ParentType{ stream },
      enumResourceDataGroup{},
      resourceEnum{ ResourceEnum::Default,
                    ResourceEnum::Ln,
                    ResourceEnum::Validate,
                    ResourceEnum::ModouleExact,
                    ResourceEnum::Ln | ResourceEnum::Validate },
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
}

void System::ResourceEnumTesting::EnumResourceTest()
{
    constexpr LanguageIDData languageIDData{};

    for (index = 0; index < resourceEnum.size(); ++index)
    {
        ASSERT_TRUE(EnumResourceTypesInLibrary(GetDllModule(), TypeProcess, reinterpret_cast<WindowsPtrLong>(this), GetCurrentResourceEnum(), languageIDData));

        ASSERT_LESS(0u, enumResourceDataGroup.size());

        for (const auto& data : enumResourceDataGroup)
        {
            auto resource = FindResourceInLibrary(GetDllModule(), data.GetType(), data.GetName(), data.GetLanguage());

            ASSERT_UNEQUAL_NULL_PTR(resource);
        }

        enumResourceDataGroup.clear();
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

System::WindowsBool System::ResourceEnumTesting::TypeProcess(DynamicLinkModule module, DynamicLinkCharType* type, WindowsPtrLong lParam)
{
    constexpr LanguageIDData languageIDData{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto testing = reinterpret_cast<const ClassType*>(lParam);

#include STSTEM_WARNING_POP

    return EnumResourceNamesInLibrary(module, type, NameProcess, lParam, testing->GetCurrentResourceEnum(), languageIDData);
}

System::WindowsBool System::ResourceEnumTesting::NameProcess(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowsPtrLong lParam)
{
    constexpr LanguageIDData languageIDData{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto testing = reinterpret_cast<const ClassType*>(lParam);

#include STSTEM_WARNING_POP

    return EnumResourceLanguagesInLibrary(module, type, name, LanguageProcess, lParam, testing->GetCurrentResourceEnum(), languageIDData);
}

#include STSTEM_WARNING_POP

System::WindowsBool System::ResourceEnumTesting::LanguageProcess(MAYBE_UNUSED DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language, WindowsPtrLong lParam)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto testing = reinterpret_cast<ClassType*>(lParam);

#include STSTEM_WARNING_POP

    testing->AddEnumResourceData(EnumResourceData{ type, name, language });

    return gTrue;
}

void System::ResourceEnumTesting::AddEnumResourceData(const EnumResourceData& data)
{
    SYSTEM_CLASS_IS_VALID_1;

    enumResourceDataGroup.emplace_back(data);
}

System::ResourceEnum System::ResourceEnumTesting::GetCurrentResourceEnum() const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return resourceEnum.at(index);
}
