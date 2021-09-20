///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/05 20:58)

#include "ModuleClassInvariantMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ModuleClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ModuleClassInvariantMacroTesting::ModuleClassInvariantMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ModuleClassInvariantMacroTesting)

void CoreTools::ModuleClassInvariantMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ModuleClassInvariantMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LevelTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ValidTest);
}

void CoreTools::ModuleClassInvariantMacroTesting::LevelTest()
{
    ASSERT_RANGE(SYSTEM_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(CORE_TOOLS_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(NETWORK_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(DATABASE_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(SCRIPT_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(MATHEMATICS_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(SOUND_EFFECT_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(INPUT_OUTPUT_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(RESOURCE_MANAGER_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(RENDERING_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(PHYSICS_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(IMAGICS_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(ANIMATION_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(USER_INTERFACE_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(ASSIST_TOOLS_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(FRAMEWORK_CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(USER_CLASS_INVARIANT_LEVEL, 0, 9);

    ASSERT_RANGE(SYSTEM_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(CORE_TOOLS_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(NETWORK_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(DATABASE_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(SCRIPT_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(MATHEMATICS_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(SOUND_EFFECT_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(RESOURCE_MANAGER_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(RENDERING_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(PHYSICS_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(IMAGICS_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(ANIMATION_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(USER_INTERFACE_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(ASSIST_TOOLS_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(FRAMEWORK_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
    ASSERT_RANGE(USER_CLASS_INVARIANT_CONST_LEVEL, 0, 9);
}

void CoreTools::ModuleClassInvariantMacroTesting::ValidTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SystemValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CoreToolsValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScriptValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MathematicsValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SoundEffectValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InputOutputValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RenderingValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicsValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImagicsValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AnimationValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntellegenceValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserInterfaceValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssistToolsValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameworkValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserValidTest);
}

void CoreTools::ModuleClassInvariantMacroTesting::SystemValidTest() noexcept
{
    SYSTEM_CLASS_IS_VALID_0;
    SYSTEM_CLASS_IS_VALID_CONST_0;
    SYSTEM_SELF_CLASS_IS_VALID_0;

    SYSTEM_CLASS_IS_VALID_1;
    SYSTEM_CLASS_IS_VALID_CONST_1;
    SYSTEM_SELF_CLASS_IS_VALID_1;

    SYSTEM_CLASS_IS_VALID_2;
    SYSTEM_CLASS_IS_VALID_CONST_2;
    SYSTEM_SELF_CLASS_IS_VALID_2;

    SYSTEM_CLASS_IS_VALID_3;
    SYSTEM_CLASS_IS_VALID_CONST_3;
    SYSTEM_SELF_CLASS_IS_VALID_3;

    SYSTEM_CLASS_IS_VALID_4;
    SYSTEM_CLASS_IS_VALID_CONST_4;
    SYSTEM_SELF_CLASS_IS_VALID_4;

    SYSTEM_CLASS_IS_VALID_5;
    SYSTEM_CLASS_IS_VALID_CONST_5;
    SYSTEM_SELF_CLASS_IS_VALID_5;

    SYSTEM_CLASS_IS_VALID_6;
    SYSTEM_CLASS_IS_VALID_CONST_6;
    SYSTEM_SELF_CLASS_IS_VALID_6;

    SYSTEM_CLASS_IS_VALID_7;
    SYSTEM_CLASS_IS_VALID_CONST_7;
    SYSTEM_SELF_CLASS_IS_VALID_7;

    SYSTEM_CLASS_IS_VALID_8;
    SYSTEM_CLASS_IS_VALID_CONST_8;
    SYSTEM_SELF_CLASS_IS_VALID_8;

    SYSTEM_CLASS_IS_VALID_9;
    SYSTEM_CLASS_IS_VALID_CONST_9;
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::CoreToolsValidTest() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_0;
    CORE_TOOLS_CLASS_IS_VALID_CONST_0;
    CORE_TOOLS_SELF_CLASS_IS_VALID_0;

    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CORE_TOOLS_CLASS_IS_VALID_2;
    CORE_TOOLS_CLASS_IS_VALID_CONST_2;
    CORE_TOOLS_SELF_CLASS_IS_VALID_2;

    CORE_TOOLS_CLASS_IS_VALID_3;
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;
    CORE_TOOLS_SELF_CLASS_IS_VALID_3;

    CORE_TOOLS_CLASS_IS_VALID_4;
    CORE_TOOLS_CLASS_IS_VALID_CONST_4;
    CORE_TOOLS_SELF_CLASS_IS_VALID_4;

    CORE_TOOLS_CLASS_IS_VALID_5;
    CORE_TOOLS_CLASS_IS_VALID_CONST_5;
    CORE_TOOLS_SELF_CLASS_IS_VALID_5;

    CORE_TOOLS_CLASS_IS_VALID_6;
    CORE_TOOLS_CLASS_IS_VALID_CONST_6;
    CORE_TOOLS_SELF_CLASS_IS_VALID_6;

    CORE_TOOLS_CLASS_IS_VALID_7;
    CORE_TOOLS_CLASS_IS_VALID_CONST_7;
    CORE_TOOLS_SELF_CLASS_IS_VALID_7;

    CORE_TOOLS_CLASS_IS_VALID_8;
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;
    CORE_TOOLS_SELF_CLASS_IS_VALID_8;

    CORE_TOOLS_CLASS_IS_VALID_9;
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::NetworkValidTest() noexcept
{
    NETWORK_CLASS_IS_VALID_0;
    NETWORK_CLASS_IS_VALID_CONST_0;
    NETWORK_SELF_CLASS_IS_VALID_0;

    NETWORK_CLASS_IS_VALID_1;
    NETWORK_CLASS_IS_VALID_CONST_1;
    NETWORK_SELF_CLASS_IS_VALID_1;

    NETWORK_CLASS_IS_VALID_2;
    NETWORK_CLASS_IS_VALID_CONST_2;
    NETWORK_SELF_CLASS_IS_VALID_2;

    NETWORK_CLASS_IS_VALID_3;
    NETWORK_CLASS_IS_VALID_CONST_3;
    NETWORK_SELF_CLASS_IS_VALID_3;

    NETWORK_CLASS_IS_VALID_4;
    NETWORK_CLASS_IS_VALID_CONST_4;
    NETWORK_SELF_CLASS_IS_VALID_4;

    NETWORK_CLASS_IS_VALID_5;
    NETWORK_CLASS_IS_VALID_CONST_5;
    NETWORK_SELF_CLASS_IS_VALID_5;

    NETWORK_CLASS_IS_VALID_6;
    NETWORK_CLASS_IS_VALID_CONST_6;
    NETWORK_SELF_CLASS_IS_VALID_6;

    NETWORK_CLASS_IS_VALID_7;
    NETWORK_CLASS_IS_VALID_CONST_7;
    NETWORK_SELF_CLASS_IS_VALID_7;

    NETWORK_CLASS_IS_VALID_8;
    NETWORK_CLASS_IS_VALID_CONST_8;
    NETWORK_SELF_CLASS_IS_VALID_8;

    NETWORK_CLASS_IS_VALID_9;
    NETWORK_CLASS_IS_VALID_CONST_9;
    NETWORK_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::DatabaseValidTest() noexcept
{
    DATABASE_CLASS_IS_VALID_0;
    DATABASE_CLASS_IS_VALID_CONST_0;
    DATABASE_SELF_CLASS_IS_VALID_0;

    DATABASE_CLASS_IS_VALID_1;
    DATABASE_CLASS_IS_VALID_CONST_1;
    DATABASE_SELF_CLASS_IS_VALID_1;

    DATABASE_CLASS_IS_VALID_2;
    DATABASE_CLASS_IS_VALID_CONST_2;
    DATABASE_SELF_CLASS_IS_VALID_2;

    DATABASE_CLASS_IS_VALID_3;
    DATABASE_CLASS_IS_VALID_CONST_3;
    DATABASE_SELF_CLASS_IS_VALID_3;

    DATABASE_CLASS_IS_VALID_4;
    DATABASE_CLASS_IS_VALID_CONST_4;
    DATABASE_SELF_CLASS_IS_VALID_4;

    DATABASE_CLASS_IS_VALID_5;
    DATABASE_CLASS_IS_VALID_CONST_5;
    DATABASE_SELF_CLASS_IS_VALID_5;

    DATABASE_CLASS_IS_VALID_6;
    DATABASE_CLASS_IS_VALID_CONST_6;
    DATABASE_SELF_CLASS_IS_VALID_6;

    DATABASE_CLASS_IS_VALID_7;
    DATABASE_CLASS_IS_VALID_CONST_7;
    DATABASE_SELF_CLASS_IS_VALID_7;

    DATABASE_CLASS_IS_VALID_8;
    DATABASE_CLASS_IS_VALID_CONST_8;
    DATABASE_SELF_CLASS_IS_VALID_8;

    DATABASE_CLASS_IS_VALID_9;
    DATABASE_CLASS_IS_VALID_CONST_9;
    DATABASE_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::ScriptValidTest() noexcept
{
    SCRIPT_CLASS_IS_VALID_0;
    SCRIPT_CLASS_IS_VALID_CONST_0;
    SCRIPT_SELF_CLASS_IS_VALID_0;

    SCRIPT_CLASS_IS_VALID_1;
    SCRIPT_CLASS_IS_VALID_CONST_1;
    SCRIPT_SELF_CLASS_IS_VALID_1;

    SCRIPT_CLASS_IS_VALID_2;
    SCRIPT_CLASS_IS_VALID_CONST_2;
    SCRIPT_SELF_CLASS_IS_VALID_2;

    SCRIPT_CLASS_IS_VALID_3;
    SCRIPT_CLASS_IS_VALID_CONST_3;
    SCRIPT_SELF_CLASS_IS_VALID_3;

    SCRIPT_CLASS_IS_VALID_4;
    SCRIPT_CLASS_IS_VALID_CONST_4;
    SCRIPT_SELF_CLASS_IS_VALID_4;

    SCRIPT_CLASS_IS_VALID_5;
    SCRIPT_CLASS_IS_VALID_CONST_5;
    SCRIPT_SELF_CLASS_IS_VALID_5;

    SCRIPT_CLASS_IS_VALID_6;
    SCRIPT_CLASS_IS_VALID_CONST_6;
    SCRIPT_SELF_CLASS_IS_VALID_6;

    SCRIPT_CLASS_IS_VALID_7;
    SCRIPT_CLASS_IS_VALID_CONST_7;
    SCRIPT_SELF_CLASS_IS_VALID_7;

    SCRIPT_CLASS_IS_VALID_8;
    SCRIPT_CLASS_IS_VALID_CONST_8;
    SCRIPT_SELF_CLASS_IS_VALID_8;

    SCRIPT_CLASS_IS_VALID_9;
    SCRIPT_CLASS_IS_VALID_CONST_9;
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::MathematicsValidTest() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_0;
    MATHEMATICS_CLASS_IS_VALID_CONST_0;
    MATHEMATICS_SELF_CLASS_IS_VALID_0;

    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_SELF_CLASS_IS_VALID_1;

    MATHEMATICS_CLASS_IS_VALID_2;
    MATHEMATICS_CLASS_IS_VALID_CONST_2;
    MATHEMATICS_SELF_CLASS_IS_VALID_2;

    MATHEMATICS_CLASS_IS_VALID_3;
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_SELF_CLASS_IS_VALID_3;

    MATHEMATICS_CLASS_IS_VALID_4;
    MATHEMATICS_CLASS_IS_VALID_CONST_4;
    MATHEMATICS_SELF_CLASS_IS_VALID_4;

    MATHEMATICS_CLASS_IS_VALID_5;
    MATHEMATICS_CLASS_IS_VALID_CONST_5;
    MATHEMATICS_SELF_CLASS_IS_VALID_5;

    MATHEMATICS_CLASS_IS_VALID_6;
    MATHEMATICS_CLASS_IS_VALID_CONST_6;
    MATHEMATICS_SELF_CLASS_IS_VALID_6;

    MATHEMATICS_CLASS_IS_VALID_7;
    MATHEMATICS_CLASS_IS_VALID_CONST_7;
    MATHEMATICS_SELF_CLASS_IS_VALID_7;

    MATHEMATICS_CLASS_IS_VALID_8;
    MATHEMATICS_CLASS_IS_VALID_CONST_8;
    MATHEMATICS_SELF_CLASS_IS_VALID_8;

    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::SoundEffectValidTest() noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_0;
    SOUND_EFFECT_CLASS_IS_VALID_CONST_0;
    SOUND_EFFECT_SELF_CLASS_IS_VALID_0;

    SOUND_EFFECT_CLASS_IS_VALID_1;
    SOUND_EFFECT_CLASS_IS_VALID_CONST_1;
    SOUND_EFFECT_SELF_CLASS_IS_VALID_1;

    SOUND_EFFECT_CLASS_IS_VALID_2;
    SOUND_EFFECT_CLASS_IS_VALID_CONST_2;
    SOUND_EFFECT_SELF_CLASS_IS_VALID_2;

    SOUND_EFFECT_CLASS_IS_VALID_3;
    SOUND_EFFECT_CLASS_IS_VALID_CONST_3;
    SOUND_EFFECT_SELF_CLASS_IS_VALID_3;

    SOUND_EFFECT_CLASS_IS_VALID_4;
    SOUND_EFFECT_CLASS_IS_VALID_CONST_4;
    SOUND_EFFECT_SELF_CLASS_IS_VALID_4;

    SOUND_EFFECT_CLASS_IS_VALID_5;
    SOUND_EFFECT_CLASS_IS_VALID_CONST_5;
    SOUND_EFFECT_SELF_CLASS_IS_VALID_5;

    SOUND_EFFECT_CLASS_IS_VALID_6;
    SOUND_EFFECT_CLASS_IS_VALID_CONST_6;
    SOUND_EFFECT_SELF_CLASS_IS_VALID_6;

    SOUND_EFFECT_CLASS_IS_VALID_7;
    SOUND_EFFECT_CLASS_IS_VALID_CONST_7;
    SOUND_EFFECT_SELF_CLASS_IS_VALID_7;

    SOUND_EFFECT_CLASS_IS_VALID_8;
    SOUND_EFFECT_CLASS_IS_VALID_CONST_8;
    SOUND_EFFECT_SELF_CLASS_IS_VALID_8;

    SOUND_EFFECT_CLASS_IS_VALID_9;
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;
    SOUND_EFFECT_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::InputOutputValidTest() noexcept
{
    INPUT_OUTPUT_CLASS_IS_VALID_0;
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_0;
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_0;

    INPUT_OUTPUT_CLASS_IS_VALID_1;
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_1;
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_1;

    INPUT_OUTPUT_CLASS_IS_VALID_2;
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_2;
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_2;

    INPUT_OUTPUT_CLASS_IS_VALID_3;
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_3;
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_3;

    INPUT_OUTPUT_CLASS_IS_VALID_4;
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_4;
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_4;

    INPUT_OUTPUT_CLASS_IS_VALID_5;
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_5;
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_5;

    INPUT_OUTPUT_CLASS_IS_VALID_6;
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_6;
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_6;

    INPUT_OUTPUT_CLASS_IS_VALID_7;
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_7;
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_7;

    INPUT_OUTPUT_CLASS_IS_VALID_8;
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_8;
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_8;

    INPUT_OUTPUT_CLASS_IS_VALID_9;
    INPUT_OUTPUT_CLASS_IS_VALID_CONST_9;
    INPUT_OUTPUT_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::ResourceManagerValidTest() noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_0;
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_0;
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_0;

    RESOURCE_MANAGER_CLASS_IS_VALID_1;
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_1;
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_1;

    RESOURCE_MANAGER_CLASS_IS_VALID_2;
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_2;
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_2;

    RESOURCE_MANAGER_CLASS_IS_VALID_3;
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_3;
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_3;

    RESOURCE_MANAGER_CLASS_IS_VALID_4;
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_4;
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_4;

    RESOURCE_MANAGER_CLASS_IS_VALID_5;
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_5;
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_5;

    RESOURCE_MANAGER_CLASS_IS_VALID_6;
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_6;
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_6;

    RESOURCE_MANAGER_CLASS_IS_VALID_7;
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_7;
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_7;

    RESOURCE_MANAGER_CLASS_IS_VALID_8;
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_8;
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_8;

    RESOURCE_MANAGER_CLASS_IS_VALID_9;
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_9;
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::RenderingValidTest() noexcept
{
    RENDERING_CLASS_IS_VALID_0;
    RENDERING_CLASS_IS_VALID_CONST_0;
    RENDERING_SELF_CLASS_IS_VALID_0;

    RENDERING_CLASS_IS_VALID_1;
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_SELF_CLASS_IS_VALID_1;

    RENDERING_CLASS_IS_VALID_2;
    RENDERING_CLASS_IS_VALID_CONST_2;
    RENDERING_SELF_CLASS_IS_VALID_2;

    RENDERING_CLASS_IS_VALID_3;
    RENDERING_CLASS_IS_VALID_CONST_3;
    RENDERING_SELF_CLASS_IS_VALID_3;

    RENDERING_CLASS_IS_VALID_4;
    RENDERING_CLASS_IS_VALID_CONST_4;
    RENDERING_SELF_CLASS_IS_VALID_4;

    RENDERING_CLASS_IS_VALID_5;
    RENDERING_CLASS_IS_VALID_CONST_5;
    RENDERING_SELF_CLASS_IS_VALID_5;

    RENDERING_CLASS_IS_VALID_6;
    RENDERING_CLASS_IS_VALID_CONST_6;
    RENDERING_SELF_CLASS_IS_VALID_6;

    RENDERING_CLASS_IS_VALID_7;
    RENDERING_CLASS_IS_VALID_CONST_7;
    RENDERING_SELF_CLASS_IS_VALID_7;

    RENDERING_CLASS_IS_VALID_8;
    RENDERING_CLASS_IS_VALID_CONST_8;
    RENDERING_SELF_CLASS_IS_VALID_8;

    RENDERING_CLASS_IS_VALID_9;
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::PhysicsValidTest() noexcept
{
    PHYSICS_CLASS_IS_VALID_0;
    PHYSICS_CLASS_IS_VALID_CONST_0;
    PHYSICS_SELF_CLASS_IS_VALID_0;

    PHYSICS_CLASS_IS_VALID_1;
    PHYSICS_CLASS_IS_VALID_CONST_1;
    PHYSICS_SELF_CLASS_IS_VALID_1;

    PHYSICS_CLASS_IS_VALID_2;
    PHYSICS_CLASS_IS_VALID_CONST_2;
    PHYSICS_SELF_CLASS_IS_VALID_2;

    PHYSICS_CLASS_IS_VALID_3;
    PHYSICS_CLASS_IS_VALID_CONST_3;
    PHYSICS_SELF_CLASS_IS_VALID_3;

    PHYSICS_CLASS_IS_VALID_4;
    PHYSICS_CLASS_IS_VALID_CONST_4;
    PHYSICS_SELF_CLASS_IS_VALID_4;

    PHYSICS_CLASS_IS_VALID_5;
    PHYSICS_CLASS_IS_VALID_CONST_5;
    PHYSICS_SELF_CLASS_IS_VALID_5;

    PHYSICS_CLASS_IS_VALID_6;
    PHYSICS_CLASS_IS_VALID_CONST_6;
    PHYSICS_SELF_CLASS_IS_VALID_6;

    PHYSICS_CLASS_IS_VALID_7;
    PHYSICS_CLASS_IS_VALID_CONST_7;
    PHYSICS_SELF_CLASS_IS_VALID_7;

    PHYSICS_CLASS_IS_VALID_8;
    PHYSICS_CLASS_IS_VALID_CONST_8;
    PHYSICS_SELF_CLASS_IS_VALID_8;

    PHYSICS_CLASS_IS_VALID_9;
    PHYSICS_CLASS_IS_VALID_CONST_9;
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::ImagicsValidTest() noexcept
{
    IMAGICS_CLASS_IS_VALID_0;
    IMAGICS_CLASS_IS_VALID_CONST_0;
    IMAGICS_SELF_CLASS_IS_VALID_0;

    IMAGICS_CLASS_IS_VALID_1;
    IMAGICS_CLASS_IS_VALID_CONST_1;
    IMAGICS_SELF_CLASS_IS_VALID_1;

    IMAGICS_CLASS_IS_VALID_2;
    IMAGICS_CLASS_IS_VALID_CONST_2;
    IMAGICS_SELF_CLASS_IS_VALID_2;

    IMAGICS_CLASS_IS_VALID_3;
    IMAGICS_CLASS_IS_VALID_CONST_3;
    IMAGICS_SELF_CLASS_IS_VALID_3;

    IMAGICS_CLASS_IS_VALID_4;
    IMAGICS_CLASS_IS_VALID_CONST_4;
    IMAGICS_SELF_CLASS_IS_VALID_4;

    IMAGICS_CLASS_IS_VALID_5;
    IMAGICS_CLASS_IS_VALID_CONST_5;
    IMAGICS_SELF_CLASS_IS_VALID_5;

    IMAGICS_CLASS_IS_VALID_6;
    IMAGICS_CLASS_IS_VALID_CONST_6;
    IMAGICS_SELF_CLASS_IS_VALID_6;

    IMAGICS_CLASS_IS_VALID_7;
    IMAGICS_CLASS_IS_VALID_CONST_7;
    IMAGICS_SELF_CLASS_IS_VALID_7;

    IMAGICS_CLASS_IS_VALID_8;
    IMAGICS_CLASS_IS_VALID_CONST_8;
    IMAGICS_SELF_CLASS_IS_VALID_8;

    IMAGICS_CLASS_IS_VALID_9;
    IMAGICS_CLASS_IS_VALID_CONST_9;
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::AnimationValidTest() noexcept
{
    ANIMATION_CLASS_IS_VALID_0;
    ANIMATION_CLASS_IS_VALID_CONST_0;
    ANIMATION_SELF_CLASS_IS_VALID_0;

    ANIMATION_CLASS_IS_VALID_1;
    ANIMATION_CLASS_IS_VALID_CONST_1;
    ANIMATION_SELF_CLASS_IS_VALID_1;

    ANIMATION_CLASS_IS_VALID_2;
    ANIMATION_CLASS_IS_VALID_CONST_2;
    ANIMATION_SELF_CLASS_IS_VALID_2;

    ANIMATION_CLASS_IS_VALID_3;
    ANIMATION_CLASS_IS_VALID_CONST_3;
    ANIMATION_SELF_CLASS_IS_VALID_3;

    ANIMATION_CLASS_IS_VALID_4;
    ANIMATION_CLASS_IS_VALID_CONST_4;
    ANIMATION_SELF_CLASS_IS_VALID_4;

    ANIMATION_CLASS_IS_VALID_5;
    ANIMATION_CLASS_IS_VALID_CONST_5;
    ANIMATION_SELF_CLASS_IS_VALID_5;

    ANIMATION_CLASS_IS_VALID_6;
    ANIMATION_CLASS_IS_VALID_CONST_6;
    ANIMATION_SELF_CLASS_IS_VALID_6;

    ANIMATION_CLASS_IS_VALID_7;
    ANIMATION_CLASS_IS_VALID_CONST_7;
    ANIMATION_SELF_CLASS_IS_VALID_7;

    ANIMATION_CLASS_IS_VALID_8;
    ANIMATION_CLASS_IS_VALID_CONST_8;
    ANIMATION_SELF_CLASS_IS_VALID_8;

    ANIMATION_CLASS_IS_VALID_9;
    ANIMATION_CLASS_IS_VALID_CONST_9;
    ANIMATION_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::ArtificialIntellegenceValidTest() noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_0;
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_0;
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_0;

    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_1;
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_1;
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_1;

    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_2;
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_2;
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_2;

    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_3;
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_3;
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_3;

    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_4;
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_4;
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_4;

    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_5;
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_5;
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_5;

    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_6;
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_6;
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_6;

    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_7;
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_7;
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_7;

    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_8;
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_8;
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_8;

    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_9;
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_9;
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::UserInterfaceValidTest() noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_0;
    USER_INTERFACE_CLASS_IS_VALID_CONST_0;
    USER_INTERFACE_SELF_CLASS_IS_VALID_0;

    USER_INTERFACE_CLASS_IS_VALID_1;
    USER_INTERFACE_CLASS_IS_VALID_CONST_1;
    USER_INTERFACE_SELF_CLASS_IS_VALID_1;

    USER_INTERFACE_CLASS_IS_VALID_2;
    USER_INTERFACE_CLASS_IS_VALID_CONST_2;
    USER_INTERFACE_SELF_CLASS_IS_VALID_2;

    USER_INTERFACE_CLASS_IS_VALID_3;
    USER_INTERFACE_CLASS_IS_VALID_CONST_3;
    USER_INTERFACE_SELF_CLASS_IS_VALID_3;

    USER_INTERFACE_CLASS_IS_VALID_4;
    USER_INTERFACE_CLASS_IS_VALID_CONST_4;
    USER_INTERFACE_SELF_CLASS_IS_VALID_4;

    USER_INTERFACE_CLASS_IS_VALID_5;
    USER_INTERFACE_CLASS_IS_VALID_CONST_5;
    USER_INTERFACE_SELF_CLASS_IS_VALID_5;

    USER_INTERFACE_CLASS_IS_VALID_6;
    USER_INTERFACE_CLASS_IS_VALID_CONST_6;
    USER_INTERFACE_SELF_CLASS_IS_VALID_6;

    USER_INTERFACE_CLASS_IS_VALID_7;
    USER_INTERFACE_CLASS_IS_VALID_CONST_7;
    USER_INTERFACE_SELF_CLASS_IS_VALID_7;

    USER_INTERFACE_CLASS_IS_VALID_8;
    USER_INTERFACE_CLASS_IS_VALID_CONST_8;
    USER_INTERFACE_SELF_CLASS_IS_VALID_8;

    USER_INTERFACE_CLASS_IS_VALID_9;
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::AssistToolsValidTest() noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_0;
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_0;
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_0;

    ASSIST_TOOLS_CLASS_IS_VALID_1;
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;

    ASSIST_TOOLS_CLASS_IS_VALID_2;
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_2;
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_2;

    ASSIST_TOOLS_CLASS_IS_VALID_3;
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_3;
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_3;

    ASSIST_TOOLS_CLASS_IS_VALID_4;
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_4;
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_4;

    ASSIST_TOOLS_CLASS_IS_VALID_5;
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_5;
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_5;

    ASSIST_TOOLS_CLASS_IS_VALID_6;
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_6;
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_6;

    ASSIST_TOOLS_CLASS_IS_VALID_7;
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_7;
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_7;

    ASSIST_TOOLS_CLASS_IS_VALID_8;
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_8;
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_8;

    ASSIST_TOOLS_CLASS_IS_VALID_9;
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::FrameworkValidTest() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_0;
    FRAMEWORK_CLASS_IS_VALID_CONST_0;
    FRAMEWORK_SELF_CLASS_IS_VALID_0;

    FRAMEWORK_CLASS_IS_VALID_1;
    FRAMEWORK_CLASS_IS_VALID_CONST_1;
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    FRAMEWORK_CLASS_IS_VALID_2;
    FRAMEWORK_CLASS_IS_VALID_CONST_2;
    FRAMEWORK_SELF_CLASS_IS_VALID_2;

    FRAMEWORK_CLASS_IS_VALID_3;
    FRAMEWORK_CLASS_IS_VALID_CONST_3;
    FRAMEWORK_SELF_CLASS_IS_VALID_3;

    FRAMEWORK_CLASS_IS_VALID_4;
    FRAMEWORK_CLASS_IS_VALID_CONST_4;
    FRAMEWORK_SELF_CLASS_IS_VALID_4;

    FRAMEWORK_CLASS_IS_VALID_5;
    FRAMEWORK_CLASS_IS_VALID_CONST_5;
    FRAMEWORK_SELF_CLASS_IS_VALID_5;

    FRAMEWORK_CLASS_IS_VALID_6;
    FRAMEWORK_CLASS_IS_VALID_CONST_6;
    FRAMEWORK_SELF_CLASS_IS_VALID_6;

    FRAMEWORK_CLASS_IS_VALID_7;
    FRAMEWORK_CLASS_IS_VALID_CONST_7;
    FRAMEWORK_SELF_CLASS_IS_VALID_7;

    FRAMEWORK_CLASS_IS_VALID_8;
    FRAMEWORK_CLASS_IS_VALID_CONST_8;
    FRAMEWORK_SELF_CLASS_IS_VALID_8;

    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_CLASS_IS_VALID_CONST_9;
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

void CoreTools::ModuleClassInvariantMacroTesting::UserValidTest() noexcept
{
    USER_CLASS_IS_VALID_0;
    USER_CLASS_IS_VALID_CONST_0;
    USER_SELF_CLASS_IS_VALID_0;

    USER_CLASS_IS_VALID_1;
    USER_CLASS_IS_VALID_CONST_1;
    SELF_CLASS_IS_VALID_1;

    USER_CLASS_IS_VALID_2;
    USER_CLASS_IS_VALID_CONST_2;
    USER_SELF_CLASS_IS_VALID_2;

    USER_CLASS_IS_VALID_3;
    USER_CLASS_IS_VALID_CONST_3;
    USER_SELF_CLASS_IS_VALID_3;

    USER_CLASS_IS_VALID_4;
    USER_CLASS_IS_VALID_CONST_4;
    USER_SELF_CLASS_IS_VALID_4;

    USER_CLASS_IS_VALID_5;
    USER_CLASS_IS_VALID_CONST_5;
    USER_SELF_CLASS_IS_VALID_5;

    USER_CLASS_IS_VALID_6;
    USER_CLASS_IS_VALID_CONST_6;
    USER_SELF_CLASS_IS_VALID_6;

    USER_CLASS_IS_VALID_7;
    USER_CLASS_IS_VALID_CONST_7;
    USER_SELF_CLASS_IS_VALID_7;

    USER_CLASS_IS_VALID_8;
    USER_CLASS_IS_VALID_CONST_8;
    USER_SELF_CLASS_IS_VALID_8;

    USER_CLASS_IS_VALID_9;
    USER_CLASS_IS_VALID_CONST_9;
    USER_SELF_CLASS_IS_VALID_9;
}
