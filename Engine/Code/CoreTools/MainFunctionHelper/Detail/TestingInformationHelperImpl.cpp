/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:47)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformationHelperImpl.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

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

    for (const auto& [fileName, tree] : mainTree)
    {
        if (const auto isOpen = tree.get_value(0);
            isOpen != 0)
        {
            file.emplace_back(fileName);
        }
    }
}

void CoreTools::TestingInformationHelperImpl::AnalysisJson()
{
    for (const auto& fileName : file)
    {
        Tree tree{};
        read_json("Configuration/" + fileName + ".json", tree);
        AnalysisInformation(tree);
    }
}

void CoreTools::TestingInformationHelperImpl::AnalysisInformation(Tree& tree)
{
    for (const auto& [suiteName, element] : tree)
    {
        for (const auto& [testingName, testLoopCount] : element)
        {
            testingInformation.Insert(suiteName, testingName, testLoopCount.get_value(0));
        }
    }
}

void CoreTools::TestingInformationHelperImpl::AnalysisTestingInformation()
{
    if (const EnvironmentVariable printRunEnvironmentVariable{ SYSTEM_TEXT("PrintRun") };
        printRunEnvironmentVariable.GetVariable() != SYSTEM_TEXT("0"))
    {
        isPrintRun = true;
    }
    else
    {
        isPrintRun = false;
    }

    const EnvironmentVariable randomSeedEnvironmentVariable{ SYSTEM_TEXT("RandomSeed") };

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
