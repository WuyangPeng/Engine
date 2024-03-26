/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 11:16)

#ifndef SYSTEM_FILE_MANAGER_SUITE_C_FILE_SET_V_BUFFER_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_C_FILE_SET_V_BUFFER_TESTING_H

#include "CFileTestingBase.h"

namespace System
{
    class CFileSetVBufferTesting final : public CFileTestingBase
    {
    public:
        using ClassType = CFileSetVBufferTesting;
        using ParentType = CFileTestingBase;

    public:
        explicit CFileSetVBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SetVBufferTest();
        void DoSetVBufferTest(FILE* file);
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_C_FILE_SET_V_BUFFER_TESTING_H