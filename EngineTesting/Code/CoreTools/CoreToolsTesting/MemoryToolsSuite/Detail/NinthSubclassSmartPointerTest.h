// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:35)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_NINTH_SUBCLASS_SMART_POINTER_TEST_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_NINTH_SUBCLASS_SMART_POINTER_TEST_H

#include "CoreTools/Helper/UserMacro.h"

#include "EighthSubclassSmartPointerTest.h"

#include <string>

namespace CoreTools
{
	class NinthSubclassSmartPointerTest : public EighthSubclassSmartPointerTest
	{
	public:
		using ClassType = NinthSubclassSmartPointerTest;
		using ParentType = EighthSubclassSmartPointerTest;

	public:
		explicit NinthSubclassSmartPointerTest(int value, const std::string& name, double ratio);  

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		double GetRatio() const noexcept;

	private:
		double m_Ratio;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUITE_NINTH_SUBCLASS_SMART_POINTER_TEST_H