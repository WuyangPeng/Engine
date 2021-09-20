///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/14 18:05)

#ifndef CORE_TOOLS_HELPER_SUITE_DELAY_COPY_UNSHARED_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_DELAY_COPY_UNSHARED_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DelayCopyUnsharedExportMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DelayCopyUnsharedExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit DelayCopyUnsharedExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ExportDelayCopyUnsharedTest();
        void CoreToolsDelayCopyUnsharedTest();
        void NetworkDelayCopyUnsharedTest();
        void DatabaseDelayCopyUnsharedTest();
        void ScriptDelayCopyUnsharedTest();
        void MathematicsDelayCopyUnsharedTest();
        void SoundEffectDelayCopyUnsharedTest();
        void InputOutputDelayCopyUnsharedTest();
        void ResourceManagerDelayCopyUnsharedTest();
        void RenderingDelayCopyUnsharedTest();
        void PhysicsDelayCopyUnsharedTest();
        void ImagicsDelayCopyUnsharedTest();
        void AnimationDelayCopyUnsharedTest();
        void ArtificialIntellegenceDelayCopyUnsharedTest();
        void UserInterfaceDelayCopyUnsharedTest();
        void AssistToolsDelayCopyUnsharedTest();
        void FrameworkDelayCopyUnsharedTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_DELAY_COPY_UNSHARED_EXPORT_MACRO_TESTING_H