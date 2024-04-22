/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 00:09)

#ifndef CORE_TOOLS_HELPER_SUITE_MODULE_CLASS_INVARIANT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MODULE_CLASS_INVARIANT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ModuleClassInvariantMacroTesting final : public UnitTest
    {
    public:
        using ClassType = ModuleClassInvariantMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ModuleClassInvariantMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LevelTest();
        void ValidTest();

        void SystemValidTest() noexcept;
        void CoreToolsValidTest() noexcept;
        void NetworkValidTest() noexcept;
        void DatabaseValidTest() noexcept;
        void ScriptValidTest() noexcept;
        void MathematicsValidTest() noexcept;
        void SoundEffectValidTest() noexcept;
        void InputOutputValidTest() noexcept;
        void ResourceManagerValidTest() noexcept;
        void RenderingValidTest() noexcept;
        void PhysicsValidTest() noexcept;
        void ImagicsValidTest() noexcept;
        void AnimationValidTest() noexcept;
        void ArtificialIntelligenceValidTest() noexcept;
        void UserInterfaceValidTest() noexcept;
        void AssistToolsValidTest() noexcept;
        void FrameworkValidTest() noexcept;
        void UserValidTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MODULE_CLASS_INVARIANT_MACRO_TESTING_H