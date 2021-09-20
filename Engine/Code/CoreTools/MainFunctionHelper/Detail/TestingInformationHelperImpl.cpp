//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 9:56)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformationHelperImpl.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <iostream>

using boost::property_tree::ptree;
using std::cerr;
using std::string;
using namespace std::literals;

CoreTools::TestingInformationHelperImpl::TestingInformationHelperImpl([[maybe_unused]] DisableNotThrow disableNotThrow)
    : m_TestingInformation{}, m_File{}, m_IsPrintRun{ false }, m_RandomSeed{ 0 }
{
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

    for (const auto& ptree : mainTree)
    {
        auto isOpen = ptree.second.get_value(0);
        if (isOpen != 0)
        {
            m_File.emplace_back(ptree.first);
        }
    }
}

void CoreTools::TestingInformationHelperImpl::AnalysisJson()
{
    for (const auto& fileName : m_File)
    {
        Tree tree{};
        read_json("Configuration/"s + fileName + ".json"s, tree);
        AnalysisInformation(tree);
    }
}

void CoreTools::TestingInformationHelperImpl::AnalysisInformation(Tree& tree)
{
    for (const auto& ptree : tree)
    {
        for (const auto& information : ptree.second)
        {
            m_TestingInformation.Insert(ptree.first, information.first, information.second.get_value(0));
        }
    }
}

void CoreTools::TestingInformationHelperImpl::AnalysisTestingInformation()
{
    EnvironmentVariable environmentVariable{ SYSTEM_TEXT("PrintRun"s) };
    if (environmentVariable.GetVariable() != SYSTEM_TEXT("0"s))
    {
        m_IsPrintRun = true;
    }
    else
    {
        m_IsPrintRun = false;
    }

    EnvironmentVariable randomSeed{ SYSTEM_TEXT("RandomSeed"s) };

    m_RandomSeed = std::stoi(randomSeed.GetVariable());
}

int CoreTools::TestingInformationHelperImpl::GetLoopCount(const string& suiteName, const string& testingName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_TestingInformation.GetLoopCount(suiteName, testingName);
}

bool CoreTools::TestingInformationHelperImpl::IsPrintRun() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_IsPrintRun;
}

int CoreTools::TestingInformationHelperImpl::GetRandomSeed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_RandomSeed;
}
