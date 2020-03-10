// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:16)

// 使用组合模式封装UnitTest类和SuiteImpl类。
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "UnitTestStream.h"
#include "UnitTestInterface.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE UnitTestComposite : public UnitTestStream, public UnitTestInterface
	{
	public:
		using ClassType = UnitTestComposite;
		using ParentType = UnitTestStream;
		using InterfaceType = UnitTestInterface;
		using ClassShareType = NonCopyClasses;
		using UnitTestCompositePtr = std::shared_ptr<UnitTestComposite>;

	public:
		explicit UnitTestComposite(std::ostream* osPtr);
		virtual ~UnitTestComposite();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual void ClearUnitTestCollection();
		virtual void AddUnitTest(UnitTestCompositePtr unitTest);

		void SetTestLoopCount(int TestLoopCount) noexcept;
		void SetRandomSeed(int randomSeed) noexcept;

		int GetEngineeringOffsetValue() const noexcept;
		int GetRandomSeed() const noexcept;

	protected:
		int GetTestLoopCount() const noexcept;

	private:
		int m_TestLoopCount;
		int m_RandomSeed;
	};
}
#endif // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H
