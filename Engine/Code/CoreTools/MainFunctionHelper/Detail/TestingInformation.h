// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:28)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_H

#include "CoreTools/CoreToolsDll.h"

#include <string>
#include <map>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE TestingInformation
	{
	public:
		using ClassType = TestingInformation;

	public:
		TestingInformation() noexcept;

		CLASS_INVARIANT_DECLARE;

		void Insert(const std::string& suiteName, const std::string& testingName, int testLoopCount);

		int GetLoopCount(const std::string& suiteName, const std::string& testingName) const;

	private:
		using TestingContainer = std::map<std::string, int>;
		using SuiteContainer = std::map<std::string, TestingContainer>;

	private:
		SuiteContainer m_SuiteContainer;
	};
}

#endif // CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_H