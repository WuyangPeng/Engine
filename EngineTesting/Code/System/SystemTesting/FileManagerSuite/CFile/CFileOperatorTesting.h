/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 11:14)

#ifndef SYSTEM_FILE_MANAGER_SUITE_C_FILE_OPERATOR_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_C_FILE_OPERATOR_TESTING_H

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
        void DoRunUnitTest() override;
        void MainTest();

        void OperatorTest();

        void IsEofTest(FILE* file);
        void FlushTest(FILE* file);
        void TellTest(FILE* file);
        void PositionTest(FILE* file);
        void DoOperatorTest(FILE* file);

        NODISCARD CFileString GetFileName() const override;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_C_FILE_OPERATOR_TESTING_H