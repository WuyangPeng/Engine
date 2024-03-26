/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:05)

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