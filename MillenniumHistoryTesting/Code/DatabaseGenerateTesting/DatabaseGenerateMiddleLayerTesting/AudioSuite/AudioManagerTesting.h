/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 23:01)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_TESTING_AUDIO_MANAGER_TESTING_H
#define DATABASE_GENERATE_MIDDLE_LAYER_TESTING_AUDIO_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateMiddleLayerTesting
{
    class AudioManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AudioManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit AudioManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void AudioManagerTest();
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_TESTING_AUDIO_MANAGER_TESTING_H