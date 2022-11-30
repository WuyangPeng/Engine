///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/10 20:08)

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
      enumResourceDataContainer{},
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
        ASSERT_TRUE(EnumResourceTypesInLibrary(GetDllModule(), TypeProcess, reinterpret_cast<WindowsLongPtrSizeType>(this), GetCurrentResourceEnum(), languageIDData));

        ASSERT_LESS(0u, enumResourceDataContainer.size());

        for (const auto& data : enumResourceDataContainer)
        {
            auto resource = FindResourceInLibrary(GetDllModule(), data.GetType(), data.GetName(), data.GetLanguage());

            ASSERT_UNEQUAL_NULL_PTR(resource);
        }

        enumResourceDataContainer.clear();
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

System::WindowsBool System::ResourceEnumTesting::TypeProcess(DynamicLinkModule module, DynamicLinkCharType* type, WindowsLongPtrSizeType lParam)
{
    constexpr LanguageIDData languageIDData{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto testing = reinterpret_cast<const ClassType*>(lParam);

#include STSTEM_WARNING_POP

    return EnumResourceNamesInLibrary(module, type, NameProcess, lParam, testing->GetCurrentResourceEnum(), languageIDData);
}

System::WindowsBool System::ResourceEnumTesting::NameProcess(DynamicLinkModule module, const DynamicLinkCharType* type, DynamicLinkCharType* name, WindowsLongPtrSizeType lParam)
{
    constexpr LanguageIDData languageIDData{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto testing = reinterpret_cast<const ClassType*>(lParam);

#include STSTEM_WARNING_POP

    return EnumResourceLanguagesInLibrary(module, type, name, LanguageProcess, lParam, testing->GetCurrentResourceEnum(), languageIDData);
}

#include STSTEM_WARNING_POP

System::WindowsBool System::ResourceEnumTesting::LanguageProcess(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language, WindowsLongPtrSizeType lParam)
{
    UnusedFunction(module);

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

    enumResourceDataContainer.emplace_back(data);
}

System::ResourceEnum System::ResourceEnumTesting::GetCurrentResourceEnum() const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return resourceEnum.at(index);
}
