///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 13:20)

#ifndef SYSTEM_THREADING_SUITE_PROCESS_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_PROCESS_TESTING_BASE_H

#include "System/Threading/Using/ProcessUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ProcessTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = ProcessTestingBase;
        using ParentType = UnitTest;

    public:
        explicit ProcessTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void CloseProcessTest(const ProcessInformation& processInformation);
        NODISCARD String GetProcessFullPath() const;

    private:
        String processFullPath;
    };
}

#endif  // SYSTEM_THREADING_SUITE_PROCESS_TESTING_BASE_H