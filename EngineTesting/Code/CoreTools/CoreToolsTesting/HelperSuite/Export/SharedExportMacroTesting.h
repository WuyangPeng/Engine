///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:17)

#ifndef CORE_TOOLS_HELPER_SUITE_SHARED_EXPORT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_SHARED_EXPORT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SharedExportMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SharedExportMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit SharedExportMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ExportSharedTest();
        void CoreToolsSharedTest();
        void NetworkSharedTest();
        void DatabaseSharedTest();
        void ScriptSharedTest();
        void MathematicsSharedTest();
        void SoundEffectSharedTest();
        void InputOutputSharedTest();
        void ResourceManagerSharedTest();
        void RenderingSharedTest();
        void PhysicsSharedTest();
        void ImagicsSharedTest();
        void AnimationSharedTest();
        void ArtificialIntellegenceSharedTest();
        void UserInterfaceSharedTest();
        void AssistToolsSharedTest();
        void FrameworkSharedTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_SHARED_EXPORT_MACRO_TESTING_H