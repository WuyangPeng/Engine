///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:17)

#ifndef CORE_TOOLS_HELPER_SUITE_MODULE_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MODULE_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ModuleExportMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ModuleExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ModuleExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CoreToolsExportTest();
        void NetworkExportTest();
        void DatabaseExportTest();
        void ScriptExportTest();
        void MathematicsExportTest();
        void SoundEffectExportTest();
        void InputOutputExportTest();
        void ResourceManagerExportTest();
        void RenderingExportTest();
        void PhysicsExportTest();
        void ImagicsExportTest();
        void AnimationExportTest();
        void ArtificialIntellegenceExportTest();
        void UserInterfaceExportTest();
        void AssistToolsExportTest();
        void FrameworkExportTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MODULE_EXPORT_MACRO_TESTING_H