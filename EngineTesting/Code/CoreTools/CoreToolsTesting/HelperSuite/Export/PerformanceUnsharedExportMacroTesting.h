///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:17)

#ifndef CORE_TOOLS_HELPER_SUITE_PERFORMANCE_UNSHARED_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_PERFORMANCE_UNSHARED_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class PerformanceUnsharedExportMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PerformanceUnsharedExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit PerformanceUnsharedExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ExportPerformanceUnsharedTest();
        void CoreToolsPerformanceUnsharedTest();
        void NetworkPerformanceUnsharedTest();
        void DatabasePerformanceUnsharedTest();
        void ScriptPerformanceUnsharedTest();
        void MathematicsPerformanceUnsharedTest();
        void SoundEffectPerformanceUnsharedTest();
        void InputOutputPerformanceUnsharedTest();
        void ResourceManagerPerformanceUnsharedTest();
        void RenderingPerformanceUnsharedTest();
        void PhysicsPerformanceUnsharedTest();
        void ImagicsPerformanceUnsharedTest();
        void AnimationPerformanceUnsharedTest();
        void ArtificialIntellegencePerformanceUnsharedTest();
        void UserInterfacePerformanceUnsharedTest();
        void AssistToolsPerformanceUnsharedTest();
        void FrameworkPerformanceUnsharedTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_PERFORMANCE_UNSHARED_EXPORT_MACRO_TESTING_H