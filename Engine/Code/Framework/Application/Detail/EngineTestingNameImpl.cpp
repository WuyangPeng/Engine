// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:49)

#include "Framework/FrameworkExport.h"

#include "EngineTestingNameImpl.h" 
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
 
using std::string;
using std::for_each;
using namespace std::literals;

Framework::EngineTestingNameImpl
	::EngineTestingNameImpl(const String& endName)
	:m_Container{ GenerateEngineTestingName(endName) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// static
// private
string Framework::EngineTestingNameImpl
	::GetProjectTestingName()
{
	Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };

	return CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(Framework::UpperDirectory::Configuration) + SYSTEM_TEXT("ProjectTesting.json"));
}

// static
// private
Framework::EngineTestingNameImpl::TestingNameContainer Framework::EngineTestingNameImpl
	::GenerateEngineTestingName(const String& endName)
{
	auto projectTestingName = GetProjectTestingName();

	boost::property_tree::basic_ptree<String, String> mainTree{ };
	read_json(projectTestingName, mainTree);

	TestingNameContainer engineTestingName{ endName };

	for_each(mainTree.begin(), mainTree.end(), [&engineTestingName](const auto& value)
	{
		if (0 < value.second.get_value<int>())
		{
			engineTestingName.push_back(value.first);
		}
	});

	return engineTestingName;	 
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineTestingNameImpl)

void Framework::EngineTestingNameImpl
	::PrintSelect(OStreamShared stream)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	auto index = 0;
	stream << "请选择要执行的单元测试工程：\n";
	for (const auto& value : m_Container)
	{
		stream << (index++) << "：" << CoreTools::StringConversion::StandardConversionMultiByte(value) << "\n";
	}
}

bool Framework::EngineTestingNameImpl
	::IsSelectValid(int select) const 
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return 0 < select && select < boost::numeric_cast<int>(m_Container.size());
}

const System::String Framework::EngineTestingNameImpl
	::GetEngineTestingName(int select) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;
	
	return m_Container.at(select);
}

