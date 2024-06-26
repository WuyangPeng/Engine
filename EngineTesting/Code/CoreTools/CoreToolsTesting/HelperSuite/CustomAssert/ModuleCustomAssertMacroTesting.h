/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 00:13)

#ifndef CORE_TOOLS_HELPER_SUITE_MODULE_CUSTOM_ASSERT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MODULE_CUSTOM_ASSERT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ModuleCustomAssertMacroTesting final : public UnitTest
    {
    public:
        using ClassType = ModuleCustomAssertMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ModuleCustomAssertMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
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
        void ArtificialIntelligenceTest();
        void UserInterfaceTest();
        void AssistToolsTest();
        void FrameworkTest();
        void UserTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MODULE_CUSTOM_ASSERT_MACRO_TESTING_H