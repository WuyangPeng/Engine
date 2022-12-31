///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/12 21:41)

#ifndef SYSTEM_FILE_MANAGER_SUITE_CFILE_CHARACTER_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_CFILE_CHARACTER_TESTING_H

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
        void DoRunUnitTest() final;
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

#endif  // SYSTEM_FILE_MANAGER_SUITE_CFILE_CHARACTER_TESTING_H