// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:14)

// ��Ԫ�����׼��ࡣSuiteΪ�ⲿ�ӿ��࣬�����ӻ�ɾ����Ԫ���ԣ�����ȡ���ԵĽ����
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>
#include <iostream>

CORE_TOOLS_EXPORT_SHARED_PTR(UnitTestComposite);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class OStreamShared;

	class CORE_TOOLS_DEFAULT_DECLARE Suite : private boost::noncopyable
	{
	public:
		using ClassType = Suite;
		using UnitTestPtr = std::shared_ptr<UnitTestComposite>;
		using ClassShareType = NonCopyClasses;

	public:
		explicit Suite(const std::string& name, const OStreamShared& osPtr, bool printRunUnitTest);

		~Suite() = default;
		Suite(const Suite& rhs) noexcept = delete;
		Suite& operator=(const Suite& rhs) noexcept = delete;
		Suite(Suite&& rhs) noexcept;
		Suite& operator=(Suite&& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

		const std::string GetName() const;
		int GetPassedNumber() const noexcept;
		int GetFailedNumber() const noexcept;
		int GetErrorNumber() const noexcept;

		OStreamShared& GetStream() noexcept;
		void PrintReport();
		void RunUnitTest();
		void ClearUnitTestCollection();
		void ResetTestData(); 
		void AddTest(const UnitTestPtr& unitTest);
		void AddSuite(const Suite& suite);

	private:
		using SuiteImplPtr = std::shared_ptr<UnitTestComposite>;

	private:
		SuiteImplPtr m_Impl;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_H
