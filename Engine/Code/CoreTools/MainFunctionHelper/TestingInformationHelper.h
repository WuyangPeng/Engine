// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:54)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

 
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(TestingInformationHelperImpl);
 

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE TestingInformationHelper 
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(TestingInformationHelper);

		TestingInformationHelper(TestingInformationHelper&& rhs) noexcept;
		TestingInformationHelper& operator=(TestingInformationHelper&& rhs) noexcept;

	public:
		TestingInformationHelper();
		~TestingInformationHelper() = default;
		TestingInformationHelper(const TestingInformationHelper& rhs) = delete;
		TestingInformationHelper& operator=(const TestingInformationHelper& rhs) = delete;

		CLASS_INVARIANT_DECLARE;

		int GetLoopCount(const std::string& suiteName, const std::string& testingName) const;

		bool IsPrintRun() const noexcept;

		int GetRandomSeed() const noexcept;

	private:
		IMPL_TYPE_DECLARE(TestingInformationHelper);
	};
}

#endif // CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_H