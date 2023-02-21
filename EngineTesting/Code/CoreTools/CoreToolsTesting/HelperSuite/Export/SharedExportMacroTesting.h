///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/12 0:04)

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

        template <typename T>
        void SharedExportTest();

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