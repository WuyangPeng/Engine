// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:12)

// ��Ԫ�����׼��ࡣSuiteImplΪ�ڲ��ӿ��࣬�����ӻ�ɾ����Ԫ���ԣ�����ȡ���ԵĽ����
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

		void PrintReport();
		void ResetTestData();

		virtual int GetPassedNumber() const noexcept override;
		virtual int GetFailedNumber() const noexcept override;
		virtual int GetErrorNumber() const noexcept override;
		virtual const std::string GetName() const override;

		virtual void ClearUnitTestCollection() override; 
		virtual void AddUnitTest(UnitTestPtr unitTest) override;
		virtual void RunUnitTest() override;

		virtual void PrintRunUnitTest() override;

	private:
		using UnitTestPtrContainer = std::vector<UnitTestPtr>;

	private:
		std::string m_SuiteName;
		UnitTestPtrContainer m_UnitTestCollection;
		bool m_PrintRunUnitTest;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H
