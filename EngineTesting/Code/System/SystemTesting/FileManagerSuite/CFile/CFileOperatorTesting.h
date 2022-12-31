///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/12 22:17)

#ifndef SYSTEM_FILE_MANAGER_SUITE_CFILE_OPERATOR_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_CFILE_OPERATOR_TESTING_H

#include "CFileTestingBase.h"

namespace System
{
    class CFileOperatorTesting final : public CFileTestingBase
    {
    public:
        using ClassType = CFileOperatorTesting;
        using ParentType = CFileTestingBase;

    public:
        explicit CFileOperatorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OperatorTest();

        void IsEOFTest(FILE* file);
        void FlushTest(FILE* file);
        void TellTest(FILE* file);
        void PositionTest(FILE* file);
        void RewindTest(FILE* file) noexcept;

        NODISCARD CFileString GetFileName() const override;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_CFILE_OPERATOR_TESTING_H