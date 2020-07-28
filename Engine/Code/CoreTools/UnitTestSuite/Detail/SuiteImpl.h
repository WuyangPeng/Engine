// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:12)

// 单元测试套件类。SuiteImpl为内部接口类，可增加或删除单元测试，并获取测试的结果。
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/UnitTestSuite/UnitTestComposite.h"

#include <string>
#include <vector>
#include <iostream>

namespace CoreTools
{
	class OStreamShared;

	class CORE_TOOLS_HIDDEN_DECLARE SuiteImpl : public UnitTestComposite
	{
	public:
		using ClassType = SuiteImpl;
		using ParentType = UnitTestComposite;
		using UnitTestPtr = std::shared_ptr<UnitTestComposite>;

	public:
		explicit SuiteImpl(const std::string& name, const OStreamShared& osPtr, bool printRunUnitTest);

#ifdef OPEN_CLASS_INVARIANT
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		bool IsUnitTestValid() const noexcept;
#endif // OPEN_CLASS_INVARIANT

		void PrintReport() override;
		void ResetTestData() override;

		int GetPassedNumber() const noexcept override;
		int GetFailedNumber() const noexcept override;
		int GetErrorNumber() const noexcept override;
		const std::string GetName() const override;

		void ClearUnitTestCollection() noexcept override;
		void AddUnitTest(UnitTestPtr unitTest) override;
		void RunUnitTest() override;

		void PrintRunUnitTest() override;

	private:
		using UnitTestPtrContainer = std::vector<UnitTestPtr>;

	private:
		std::string m_SuiteName;
		UnitTestPtrContainer m_UnitTestCollection;
		bool m_PrintRunUnitTest;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H
