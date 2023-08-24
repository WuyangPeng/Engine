///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/01 21:51)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_TESTING_ARTIFICIAL_INTELLIGENCE_MANAGER_TESTING_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_TESTING_ARTIFICIAL_INTELLIGENCE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerMiddleLayerTesting
{
    class ArtificialIntelligenceManagerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ArtificialIntelligenceManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit ArtificialIntelligenceManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ArtificialIntelligenceManagerTest();
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_TESTING_ARTIFICIAL_INTELLIGENCE_MANAGER_TESTING_H