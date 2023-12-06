/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 23:00)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_TESTING_ARTIFICIAL_INTELLIGENCE_MANAGER_TESTING_H
#define DATABASE_GENERATE_MIDDLE_LAYER_TESTING_ARTIFICIAL_INTELLIGENCE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateMiddleLayerTesting
{
    class AIManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AIManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit AIManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ArtificialIntelligenceManagerTest();
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_TESTING_ARTIFICIAL_INTELLIGENCE_MANAGER_TESTING_H