///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:17)

#ifndef CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class NonCopyExportMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = NonCopyExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit NonCopyExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ExportNonCopyTest();
        void CoreToolsNonCopyTest();
        void NetworkNonCopyTest();
        void DatabaseNonCopyTest();
        void ScriptNonCopyTest();
        void MathematicsNonCopyTest();
        void SoundEffectNonCopyTest();
        void InputOutputNonCopyTest();
        void ResourceManagerNonCopyTest();
        void RenderingNonCopyTest();
        void PhysicsNonCopyTest();
        void ImagicsNonCopyTest();
        void AnimationNonCopyTest();
        void ArtificialIntellegenceNonCopyTest();
        void UserInterfaceNonCopyTest();
        void AssistToolsNonCopyTest();
        void FrameworkNonCopyTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_H