// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:16)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_INTERFACE_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE UnitTestInterface
	{
	public:
		using ClassType = UnitTestInterface;

	public:
		UnitTestInterface() noexcept;
		virtual ~UnitTestInterface() = default;

		UnitTestInterface(const UnitTestInterface& rhs) = default;
		UnitTestInterface& operator=(const UnitTestInterface& rhs) = default;
		UnitTestInterface(UnitTestInterface&& rhs) noexcept = default;
		UnitTestInterface& operator=(UnitTestInterface&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual const std::string GetName() const = 0;
		virtual int GetPassedNumber() const noexcept = 0;
		virtual int GetFailedNumber() const noexcept = 0;
		virtual int GetErrorNumber() const noexcept = 0;
		virtual void PrintReport() = 0;

		virtual void ResetTestData() = 0;
		virtual void RunUnitTest() = 0;

		virtual void PrintRunUnitTest() = 0;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_INTERFACE_H
