/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 11:13)

#ifndef SYSTEM_FILE_MANAGER_SUITE_C_FILE_CHARACTER_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_C_FILE_CHARACTER_TESTING_H

#include "CFileTestingBase.h"

namespace System
{
    class CFileCharacterTesting final : public CFileTestingBase
    {
    public:
        using ClassType = CFileCharacterTesting;
        using ParentType = CFileTestingBase;

    public:
        explicit CFileCharacterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PutCharacterTest();
        void PutStringTest();
        void GetStringTest();

        void DoPutCharacterTest(FILE* file);
        void DoPutStringTest(FILE* file);
        void DoGetStringTest(FILE* file);

        NODISCARD CFileString GetFileName() const override;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_C_FILE_CHARACTER_TESTING_H