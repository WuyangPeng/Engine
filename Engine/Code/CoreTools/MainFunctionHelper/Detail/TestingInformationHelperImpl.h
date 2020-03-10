// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:29)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_IMPL_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "TestingInformation.h" 
#include "System/Helper/PragmaWarning/PropertyTree.h" 

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE TestingInformationHelperImpl
	{
	public:
		using ClassType = TestingInformationHelperImpl;

	public:
		TestingInformationHelperImpl();

		CLASS_INVARIANT_DECLARE;

		int GetLoopCount(const std::string& suiteName, const std::string& testingName) const;

		bool IsPrintRun() const noexcept;

		int GetRandomSeed() const noexcept;

	private:
		using FileContainer = std::vector<std::string>;
		using Tree = boost::property_tree::ptree;

	private:
		void Analysis();
		void AnalysisFile();
		void AnalysisJson();
		void AnalysisInformation(Tree& tree);
		void AnalysisTestingInformation();

	private:
		TestingInformation m_TestingInformation;
		FileContainer m_File;
		bool m_IsPrintRun;
		int m_RandomSeed;
	};
}

#endif // CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_IMPL_H