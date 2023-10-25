///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 15:31)

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