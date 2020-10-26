//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 13:17)

// ��Ԫ�����׼��ࡣSuiteΪ�ⲿ�ӿ��࣬�����ӻ�ɾ����Ԫ���ԣ�����ȡ���ԵĽ����
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_H

#include "CoreTools/CoreToolsDll.h"

#include "UnitTestSuiteFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <iostream>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(UnitTestComposite);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Suite final
    {
    public:
        using ClassType = Suite;
        using UnitTestPtr = std::shared_ptr<UnitTestComposite>;
        using ClassShareType = NonCopyClasses;

    public:
        Suite(const std::string& name, const OStreamShared& streamShared, bool printRunUnitTest);

        ~Suite() noexcept = default;
        Suite(const Suite& rhs) noexcept = delete;
        Suite& operator=(const Suite& rhs) noexcept = delete;
        Suite(Suite&& rhs) noexcept;
        Suite& operator=(Suite&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const std::string GetName() const;
        [[nodiscard]] int GetPassedNumber() const noexcept;
        [[nodiscard]] int GetFailedNumber() const noexcept;
        [[nodiscard]] int GetErrorNumber() const noexcept;

        [[nodiscard]] OStreamShared& GetStream() noexcept;
        void PrintReport();
        void RunUnitTest();
        void ClearUnitTestCollection();
        void ResetTestData();
        void AddTest(const UnitTestPtr& unitTest);
        void AddSuite(const Suite& suite);

    private:
        using SuiteImplSharedPtr = std::shared_ptr<UnitTestComposite>;

    private:
        SuiteImplSharedPtr m_Impl;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_H
