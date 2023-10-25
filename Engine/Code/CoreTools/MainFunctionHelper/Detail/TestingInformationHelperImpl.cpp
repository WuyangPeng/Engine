///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:39)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformationHelperImpl.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::TestingInformationHelperImpl::TestingInformationHelperImpl(DisableNotThrow disableNotThrow)
    : testingInformation{}, file{}, isPrintRun{ false }, randomSeed{ 0 }
{
    System::UnusedFunction(disableNotThrow);

    Analysis();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestingInformationHelperImpl)

void CoreTools::TestingInformationHelperImpl::Analysis()
{
    AnalysisFile();
    AnalysisJson();
    AnalysisTestingInformation();
}

void CoreTools::TestingInformationHelperImpl::AnalysisFile()
{
    Tree mainTree{};
    read_json("Configuration/Testing.json", mainTree);

    for (const auto& tree : mainTree)
    {
        if (const auto isOpen = tree.second.get_value(0); isOpen != 0)
        {
            file.emplace_back(tree.first);
        }
    }
}

void CoreTools::TestingInformationHelperImpl::AnalysisJson()
{
    for (const auto& fileName : file)
    {
        Tree tree{};
        read_json("Configuration/"s + fileName + ".json"s, tree);
        AnalysisInformation(tree);
    }
}

void CoreTools::TestingInformationHelperImpl::AnalysisInformation(Tree& tree)
{
    for (const auto& [suiteName, element] : tree)
    {
        for (const auto& information : element)
        {
            testingInformation.Insert(suiteName, information.first, information.second.get_value(0));
        }
    }
}

void CoreTools::TestingInformationHelperImpl::AnalysisTestingInformation()
{
    if (const EnvironmentVariable printRunEnvironmentVariable{ SYSTEM_TEXT("PrintRun"s) }; printRunEnvironmentVariable.GetVariable() != SYSTEM_TEXT("0"s))
    {
        isPrintRun = true;
    }
    else
    {
        isPrintRun = false;
    }

    const EnvironmentVariable randomSeedEnvironmentVariable{ SYSTEM_TEXT("RandomSeed"s) };

    randomSeed = std::stoi(randomSeedEnvironmentVariable.GetVariable());
}

int CoreTools::TestingInformationHelperImpl::GetLoopCount(const std::string& suiteName, const std::string& testingName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return testingInformation.GetLoopCount(suiteName, testingName);
}

bool CoreTools::TestingInformationHelperImpl::IsPrintRun() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return isPrintRun;
}

int CoreTools::TestingInformationHelperImpl::GetRandomSeed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return randomSeed;
}
