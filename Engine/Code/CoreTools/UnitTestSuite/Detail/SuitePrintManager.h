//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 11:26)

// ��Ԫ�����׼��������Ϣ�����࣬SuitePrintManageΪ�ڲ��ӿ��࣬�������Ϣͷ�����ơ����Խ���͵�ǰʱ�䡣
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ReportOutput/ReportOutputFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

#include <boost/noncopyable.hpp>
#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SuitePrintManager final : private boost::noncopyable
    {
    public:
        using ClassType = SuitePrintManager;
        using MasterType = SuiteImpl;

    public:
        explicit SuitePrintManager(MasterType& suite, int borderLineLength = 75);

        CLASS_INVARIANT_DECLARE;

        void PrintCoreToolsHeader();
        void PrintSuiteName();
        void PrintSuiteResult();
        void PrintCurrentTime();

    private:
        using UnitTestSuiteReportOutputSharedPtr = std::shared_ptr<UnitTestSuiteReportOutput>;

    private:
        static constexpr auto sm_CharacterWidth = 8;

    private:
        MasterType& m_Suite;
        UnitTestSuiteReportOutputSharedPtr m_UnitTestSuiteReportOutputPtr;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H
