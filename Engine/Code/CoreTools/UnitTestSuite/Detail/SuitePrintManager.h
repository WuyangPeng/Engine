///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/14 18:52)

// ��Ԫ�����׼��������Ϣ�����࣬SuitePrintManageΪ�ڲ��ӿ��࣬�������Ϣͷ�����ơ����Խ���͵�ǰʱ�䡣
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ReportOutput/ReportOutputFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SuitePrintManager final
    {
    public:
        using ClassType = SuitePrintManager;
        using MasterType = SuiteImpl;

    public:
        explicit SuitePrintManager(MasterType& suite, int borderLineLength = 75);
        ~SuitePrintManager() noexcept = default;
        SuitePrintManager(const SuitePrintManager& rhs) = delete;
        SuitePrintManager& operator=(const SuitePrintManager& rhs) = delete;
        SuitePrintManager(SuitePrintManager&& rhs) = delete;
        SuitePrintManager& operator=(SuitePrintManager&& rhs) = delete;

        CLASS_INVARIANT_DECLARE;

        void PrintCoreToolsHeader();
        void PrintSuiteName();
        void PrintSuiteResult();
        void PrintCurrentTime();

    private:
        using UnitTestSuiteReportOutputSharedPtr = std::shared_ptr<UnitTestSuiteReportOutput>;

    private:
        static constexpr auto characterWidth = 8;

    private:
        MasterType& suite;
        UnitTestSuiteReportOutputSharedPtr unitTestSuiteReportOutput;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H
