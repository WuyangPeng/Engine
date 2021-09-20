// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:35)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_FOURTH_SUBCLASS_SMART_POINTER_TEST_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_FOURTH_SUBCLASS_SMART_POINTER_TEST_H

#include "ThirdSubclassSmartPointerTest.h"

#include <string>

namespace CoreTools
{
	class FourthSubclassSmartPointerTest : public ThirdSubclassSmartPointerTest
	{
	public:
		using ClassType = FourthSubclassSmartPointerTest;
		using ParentType = ThirdSubclassSmartPointerTest;

	public:
		explicit FourthSubclassSmartPointerTest(int value, const std::string& name); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const std::string GetName() const;

	private:
		std::string m_Name;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUITE_FOURTH_SUBCLASS_SMART_POINTER_TEST_H