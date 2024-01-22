/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:24)

#include "Framework/FrameworkExport.h"

#include "EngineTestingNameImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using namespace std::literals;

Framework::EngineTestingNameImpl::EngineTestingNameImpl(const String& endName)
    : container{ GenerateEngineTestingName(endName) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

std::string Framework::EngineTestingNameImpl::GetProjectTestingName()
{
    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };

    return CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(Framework::UpperDirectory::Configuration) + SYSTEM_TEXT("ProjectTesting.json"));
}

Framework::EngineTestingNameImpl::TestingNameContainer Framework::EngineTestingNameImpl::GenerateEngineTestingName(const String& endName)
{
    const auto projectTestingName = GetProjectTestingName();

    boost::property_tree::basic_ptree<String, String> mainTree{};
    read_json(projectTestingName, mainTree);

    TestingNameContainer engineTestingName{ endName };

    std::ranges::for_each(mainTree, [&engineTestingName](const auto& value) {
        if (0 < value.second.template get_value<int>())
        {
            engineTestingName.emplace_back(value.first);
        }
    });

    return engineTestingName;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineTestingNameImpl)

void Framework::EngineTestingNameImpl::PrintSelect(OStreamShared stream)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    auto index = 0;
    stream << "请选择要执行的单元测试工程：\n";
    for (const auto& value : container)
    {
        stream << (index++) << "：" << CoreTools::StringConversion::StandardConversionMultiByte(value) << "\n";
    }
}

bool Framework::EngineTestingNameImpl::IsSelectValid(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return 0 < select && select < boost::numeric_cast<int>(container.size());
}

NODISCARD System::String Framework::EngineTestingNameImpl::GetEngineTestingName(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return container.at(select);
}
