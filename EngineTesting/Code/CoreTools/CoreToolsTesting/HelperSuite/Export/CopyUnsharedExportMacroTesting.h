///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/14 17:59)

#ifndef CORE_TOOLS_HELPER_SUITE_COPY_UNSHARED_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_COPY_UNSHARED_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CopyUnsharedExportMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CopyUnsharedExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit CopyUnsharedExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ExportCopyUnsharedTest();
        void CoreToolsCopyUnsharedTest();
        void NetworkCopyUnsharedTest();
        void DatabaseCopyUnsharedTest();
        void ScriptCopyUnsharedTest();
        void MathematicsCopyUnsharedTest();
        void SoundEffectCopyUnsharedTest();
        void InputOutputCopyUnsharedTest();
        void ResourceManagerCopyUnsharedTest();
        void RenderingCopyUnsharedTest();
        void PhysicsCopyUnsharedTest();
        void ImagicsCopyUnsharedTest();
        void AnimationCopyUnsharedTest();
        void ArtificialIntellegenceCopyUnsharedTest();
        void UserInterfaceCopyUnsharedTest();
        void AssistToolsCopyUnsharedTest();
        void FrameworkCopyUnsharedTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_COPY_UNSHARED_EXPORT_MACRO_TESTING_H