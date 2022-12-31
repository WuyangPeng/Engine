///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/12 22:17)

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