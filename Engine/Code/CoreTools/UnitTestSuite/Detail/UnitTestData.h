// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:13)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DATA_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DATA_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE UnitTestData
	{
	public:
		using ClassType = UnitTestData;

	public:
		UnitTestData();

		CLASS_INVARIANT_DECLARE;

		int GetPassedNumber() const noexcept;
		int GetFailedNumber() const noexcept;
		int GetErrorNumber() const noexcept;
		bool IsEmpty() const noexcept;

		void AddPassedNumber() noexcept;
		void AddFailedNumber() noexcept;
		void AddErrorNumber() noexcept;
		void ClearData() noexcept;

	private:
		int m_Pass;
		int m_Fail;
		int m_Error;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DATA_H
