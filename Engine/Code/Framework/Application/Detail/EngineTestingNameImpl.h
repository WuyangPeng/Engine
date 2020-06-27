// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:38)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_IMPL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <vector>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE EngineTestingNameImpl
	{
	public:
		using ClassType = EngineTestingNameImpl;
		using String = System::String;
		using OStreamShared = CoreTools::OStreamShared;

	public:
		explicit EngineTestingNameImpl(const String& endName);

		CLASS_INVARIANT_DECLARE;

		void PrintSelect(OStreamShared stream);
		bool IsSelectValid(int select) const;
		const String GetEngineTestingName(int select) const; 

	private:		
		using TestingNameContainer = std::vector<String>;

	private:		
		static std::string GetProjectTestingName();
		static TestingNameContainer GenerateEngineTestingName(const String& endName);

	private: 
		TestingNameContainer m_Container;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_IMPL_H