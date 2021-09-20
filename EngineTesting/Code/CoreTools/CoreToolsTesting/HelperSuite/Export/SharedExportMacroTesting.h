///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/14 18:07)

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