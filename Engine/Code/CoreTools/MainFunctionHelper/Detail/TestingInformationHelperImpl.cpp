// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:55)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformationHelperImpl.h" 
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/FileManager/EnvironmentVariable.h" 

#include <iostream>
#include "CoreTools/ClassInvariant/NoexceptDetail.h"

using boost::property_tree::ptree;
using std::cerr;
using std::string; 

CoreTools::TestingInformationHelperImpl
	::TestingInformationHelperImpl() noexcept
	:m_TestingInformation{}, m_File{}, m_IsPrintRun{ false }, m_RandomSeed{ 0 }
{
    CoreTools::NoexceptNoReturn(*this,&ClassType::Analysis);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestingInformationHelperImpl)

void CoreTools::TestingInformationHelperImpl
	::Analysis()
{
	EXCEPTION_TRY
	{
		AnalysisFile();
		AnalysisJson();
		AnalysisTestingInformation();
	}
	EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::TestingInformationHelperImpl
	::AnalysisFile()
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

void CoreTools::TestingInformationHelperImpl
	::AnalysisJson()
{
	for (const auto& fileName : m_File)
	{
		Tree tree{};
		read_json("Configuration/" + fileName + ".json", tree);
		AnalysisInformation(tree);
	}
}

void CoreTools::TestingInformationHelperImpl
	::AnalysisInformation(Tree& tree)
{
	for (const auto& ptree : tree)
	{
		for (const auto& information : ptree.second)
		{
			m_TestingInformation.Insert(ptree.first, information.first, information.second.get_value(0));
		}
	}
}

void CoreTools::TestingInformationHelperImpl
	::AnalysisTestingInformation()
{
	EnvironmentVariable environmentVariable{ SYSTEM_TEXT("PrintRun") };
	if (environmentVariable.GetVariable() != SYSTEM_TEXT("0"))
	{
		m_IsPrintRun = true;
	}
	else
	{
		m_IsPrintRun = false;
	}

	EnvironmentVariable randomSeed{ SYSTEM_TEXT("RandomSeed") };

	m_RandomSeed = std::stoi(randomSeed.GetVariable());
}

int CoreTools::TestingInformationHelperImpl
	::GetLoopCount(const string& suiteName, const string& testingName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_TestingInformation.GetLoopCount(suiteName, testingName);
}

bool CoreTools::TestingInformationHelperImpl
	::IsPrintRun() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_IsPrintRun;
}

int CoreTools::TestingInformationHelperImpl
	::GetRandomSeed() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_RandomSeed;
}



