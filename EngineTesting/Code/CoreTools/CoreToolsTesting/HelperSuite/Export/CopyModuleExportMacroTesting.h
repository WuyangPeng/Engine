///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:17)

#ifndef CORE_TOOLS_HELPER_SUITE_COPY_MODULE_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_COPY_MODULE_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CopyModuleExportMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CopyModuleExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit CopyModuleExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CoreToolsCopyExportTest();
        void NetworkCopyExportTest();
        void DatabaseCopyExportTest();
        void ScriptCopyExportTest();
        void MathematicsCopyExportTest();
        void SoundEffectCopyExportTest();
        void InputOutputCopyExportTest();
        void ResourceManagerCopyExportTest();
        void RenderingCopyExportTest();
        void PhysicsCopyExportTest();
        void ImagicsCopyExportTest();
        void AnimationCopyExportTest();
        void ArtificialIntellegenceCopyExportTest();
        void UserInterfaceCopyExportTest();
        void AssistToolsCopyExportTest();
        void FrameworkCopyExportTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_COPY_MODULE_EXPORT_MACRO_TESTING_H