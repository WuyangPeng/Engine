///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/29 19:52)

#ifndef SYSTEM_FILE_MANAGE_SUITE_CFILE_CHARACTER_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_CFILE_CHARACTER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CFileCharacterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CFileCharacterTesting;
        using ParentType = UnitTest;

    public:
        explicit CFileCharacterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void PutCharacterTest();
        void PutStringTest();
        void GetStringTest();

        NODISCARD static const String GetFileName();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_CFILE_CHARACTER_TESTING_H