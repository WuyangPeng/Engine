///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:13)

#ifndef CORE_TOOLS_HELPER_SUITE_MODULE_CUSTOM_ASSERT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MODULE_CUSTOM_ASSERT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ModuleCustomAssertMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ModuleCustomAssertMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ModuleCustomAssertMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AssertMacroTest();
        void LevelTest();
        void ConstexprTest() noexcept;

        void SystemTest();
        void CoreToolsTest();
        void NetworkTest();
        void DatabaseTest();
        void ScriptTest();
        void MathematicsTest();
        void SoundEffectTest();
        void InputOutputTest();
        void ResourceManagerTest();
        void RenderingTest();
        void PhysicsTest();
        void ImagicsTest();
        void AnimationTest();
        void ArtificialIntellegenceTest();
        void UserInterfaceTest();
        void AssistToolsTest();
        void FrameworkTest();
        void UserTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MODULE_CUSTOM_ASSERT_MACRO_TESTING_H