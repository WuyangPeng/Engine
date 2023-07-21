///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/02 20:51)

#ifndef DATABASE_TESTING_DATABASE_ENTITY_CODE_GENERATION_SUITE_ENTITY_SOURCE_FILE_GENERATION_TESTING_H
#define DATABASE_TESTING_DATABASE_ENTITY_CODE_GENERATION_SUITE_ENTITY_SOURCE_FILE_GENERATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class EntitySourceFileGenerationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EntitySourceFileGenerationTesting;
        using ParentType = UnitTest;

    public:
        explicit EntitySourceFileGenerationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CodeSourceFileGenerationTest();
    };
}

#endif  // DATABASE_TESTING_DATABASE_ENTITY_CODE_GENERATION_SUITE_ENTITY_SOURCE_FILE_GENERATION_TESTING_H