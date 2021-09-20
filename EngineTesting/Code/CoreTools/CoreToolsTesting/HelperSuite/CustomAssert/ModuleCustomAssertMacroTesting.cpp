///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/05 20:59)

#include "ModuleCustomAssertMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ModuleCustomAssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ModuleCustomAssertMacroTesting::ModuleCustomAssertMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ModuleCustomAssertMacroTesting)

void CoreTools::ModuleCustomAssertMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ModuleCustomAssertMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LevelTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstexprTest);
}

void CoreTools::ModuleCustomAssertMacroTesting::AssertMacroTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SystemTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CoreToolsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScriptTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MathematicsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SoundEffectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InputOutputTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RenderingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImagicsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AnimationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntellegenceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserInterfaceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssistToolsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameworkTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserTest);
}

void CoreTools::ModuleCustomAssertMacroTesting::LevelTest()
{
    ASSERT_RANGE(SYSTEM_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(CORE_TOOLS_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(NETWORK_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(DATABASE_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(SCRIPT_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(MATHEMATICS_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(SOUND_EFFECT_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(INPUT_OUTPUT_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(RESOURCE_MANAGER_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(RENDERING_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(PHYSICS_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(IMAGICS_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(ANIMATION_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(ARTIFICIAL_INTELLEGENCE_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(USER_INTERFACE_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(ASSIST_TOOLS_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(FRAMEWORK_ASSERT_LEVEL, 0, 5);
    ASSERT_RANGE(USER_ASSERT_LEVEL, 0, 5);
}

void CoreTools::ModuleCustomAssertMacroTesting::ConstexprTest() noexcept
{
    static_assert(SYSTEM_ASSERT_LEVEL == g_SystemAssert);
    static_assert(CORE_TOOLS_ASSERT_LEVEL == g_CoreToolsAssert);
    static_assert(NETWORK_ASSERT_LEVEL == g_NetworkAssert);
    static_assert(DATABASE_ASSERT_LEVEL == g_DatabaseAssert);
    static_assert(SCRIPT_ASSERT_LEVEL == g_ScriptAssert);
    static_assert(MATHEMATICS_ASSERT_LEVEL == g_MathematicsAssert);
    static_assert(SOUND_EFFECT_ASSERT_LEVEL == g_SoundEffectAssert);
    static_assert(INPUT_OUTPUT_ASSERT_LEVEL == g_InputoOutputAssert);
    static_assert(RESOURCE_MANAGER_ASSERT_LEVEL == g_ResourceManagerAssert);
    static_assert(RENDERING_ASSERT_LEVEL == g_RenderingAssert);
    static_assert(PHYSICS_ASSERT_LEVEL == g_PhysicsAssert);
    static_assert(IMAGICS_ASSERT_LEVEL == g_ImagicsAssert);
    static_assert(ANIMATION_ASSERT_LEVEL == g_AnimationAssert);
    static_assert(ARTIFICIAL_INTELLEGENCE_ASSERT_LEVEL == g_ArtificialIntellegenceAssert);
    static_assert(USER_INTERFACE_ASSERT_LEVEL == g_UserInterfaceAssert);
    static_assert(ASSIST_TOOLS_ASSERT_LEVEL == g_AssistToolsAssert);
    static_assert(FRAMEWORK_ASSERT_LEVEL == g_FrameworkAssert);
    static_assert(USER_ASSERT_LEVEL == g_UserAssert);
}

void CoreTools::ModuleCustomAssertMacroTesting::SystemTest()
{
    SYSTEM_ASSERTION_0(true, "���Բ��ԣ�");
    SYSTEM_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SYSTEM_ASSERTION_1(true, "���Բ��ԣ�");
    SYSTEM_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SYSTEM_ASSERTION_2(true, "���Բ��ԣ�");
    SYSTEM_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SYSTEM_ASSERTION_3(true, "���Բ��ԣ�");
    SYSTEM_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SYSTEM_ASSERTION_4(true, "���Բ��ԣ�");
    SYSTEM_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::CoreToolsTest()
{
    CORE_TOOLS_ASSERTION_0(true, "���Բ��ԣ�");
    CORE_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    CORE_TOOLS_ASSERTION_1(true, "���Բ��ԣ�");
    CORE_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    CORE_TOOLS_ASSERTION_2(true, "���Բ��ԣ�");
    CORE_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    CORE_TOOLS_ASSERTION_3(true, "���Բ��ԣ�");
    CORE_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    CORE_TOOLS_ASSERTION_4(true, "���Բ��ԣ�");
    CORE_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::NetworkTest()
{
    NETWORK_ASSERTION_0(true, "���Բ��ԣ�");
    NETWORK_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    NETWORK_ASSERTION_1(true, "���Բ��ԣ�");
    NETWORK_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    NETWORK_ASSERTION_2(true, "���Բ��ԣ�");
    NETWORK_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    NETWORK_ASSERTION_3(true, "���Բ��ԣ�");
    NETWORK_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    NETWORK_ASSERTION_4(true, "���Բ��ԣ�");
    NETWORK_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::DatabaseTest()
{
    DATABASE_ASSERTION_0(true, "���Բ��ԣ�");
    DATABASE_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    DATABASE_ASSERTION_1(true, "���Բ��ԣ�");
    DATABASE_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    DATABASE_ASSERTION_2(true, "���Բ��ԣ�");
    DATABASE_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    DATABASE_ASSERTION_3(true, "���Բ��ԣ�");
    DATABASE_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    DATABASE_ASSERTION_4(true, "���Բ��ԣ�");
    DATABASE_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::ScriptTest()
{
    SCRIPT_ASSERTION_0(true, "���Բ��ԣ�");
    SCRIPT_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SCRIPT_ASSERTION_1(true, "���Բ��ԣ�");
    SCRIPT_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SCRIPT_ASSERTION_2(true, "���Բ��ԣ�");
    SCRIPT_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SCRIPT_ASSERTION_3(true, "���Բ��ԣ�");
    SCRIPT_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SCRIPT_ASSERTION_4(true, "���Բ��ԣ�");
    SCRIPT_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::MathematicsTest()
{
    MATHEMATICS_ASSERTION_0(true, "���Բ��ԣ�");
    MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    MATHEMATICS_ASSERTION_1(true, "���Բ��ԣ�");
    MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    MATHEMATICS_ASSERTION_2(true, "���Բ��ԣ�");
    MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    MATHEMATICS_ASSERTION_3(true, "���Բ��ԣ�");
    MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    MATHEMATICS_ASSERTION_4(true, "���Բ��ԣ�");
    MATHEMATICS_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::SoundEffectTest()
{
    SOUND_EFFECT_ASSERTION_0(true, "���Բ��ԣ�");
    SOUND_EFFECT_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SOUND_EFFECT_ASSERTION_1(true, "���Բ��ԣ�");
    SOUND_EFFECT_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SOUND_EFFECT_ASSERTION_2(true, "���Բ��ԣ�");
    SOUND_EFFECT_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SOUND_EFFECT_ASSERTION_3(true, "���Բ��ԣ�");
    SOUND_EFFECT_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    SOUND_EFFECT_ASSERTION_4(true, "���Բ��ԣ�");
    SOUND_EFFECT_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::InputOutputTest()
{
    INPUT_OUTPUT_ASSERTION_0(true, "���Բ��ԣ�");
    INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    INPUT_OUTPUT_ASSERTION_1(true, "���Բ��ԣ�");
    INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    INPUT_OUTPUT_ASSERTION_2(true, "���Բ��ԣ�");
    INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    INPUT_OUTPUT_ASSERTION_3(true, "���Բ��ԣ�");
    INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    INPUT_OUTPUT_ASSERTION_4(true, "���Բ��ԣ�");
    INPUT_OUTPUT_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::ResourceManagerTest()
{
    RESOURCE_MANAGER_ASSERTION_0(true, "���Բ��ԣ�");
    RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    RESOURCE_MANAGER_ASSERTION_1(true, "���Բ��ԣ�");
    RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    RESOURCE_MANAGER_ASSERTION_2(true, "���Բ��ԣ�");
    RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    RESOURCE_MANAGER_ASSERTION_3(true, "���Բ��ԣ�");
    RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    RESOURCE_MANAGER_ASSERTION_4(true, "���Բ��ԣ�");
    RESOURCE_MANAGER_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::RenderingTest()
{
    RENDERING_ASSERTION_0(true, "���Բ��ԣ�");
    RENDERING_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    RENDERING_ASSERTION_1(true, "���Բ��ԣ�");
    RENDERING_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    RENDERING_ASSERTION_2(true, "���Բ��ԣ�");
    RENDERING_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    RENDERING_ASSERTION_3(true, "���Բ��ԣ�");
    RENDERING_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    RENDERING_ASSERTION_4(true, "���Բ��ԣ�");
    RENDERING_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::PhysicsTest()
{
    PHYSICS_ASSERTION_0(true, "���Բ��ԣ�");
    PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    PHYSICS_ASSERTION_1(true, "���Բ��ԣ�");
    PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    PHYSICS_ASSERTION_2(true, "���Բ��ԣ�");
    PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    PHYSICS_ASSERTION_3(true, "���Բ��ԣ�");
    PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    PHYSICS_ASSERTION_4(true, "���Բ��ԣ�");
    PHYSICS_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::ImagicsTest()
{
    IMAGICS_ASSERTION_0(true, "���Բ��ԣ�");
    IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    IMAGICS_ASSERTION_1(true, "���Բ��ԣ�");
    IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    IMAGICS_ASSERTION_2(true, "���Բ��ԣ�");
    IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    IMAGICS_ASSERTION_3(true, "���Բ��ԣ�");
    IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    IMAGICS_ASSERTION_4(true, "���Բ��ԣ�");
    IMAGICS_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::AnimationTest()
{
    ANIMATION_ASSERTION_0(true, "���Բ��ԣ�");
    ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ANIMATION_ASSERTION_1(true, "���Բ��ԣ�");
    ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ANIMATION_ASSERTION_2(true, "���Բ��ԣ�");
    ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ANIMATION_ASSERTION_3(true, "���Բ��ԣ�");
    ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ANIMATION_ASSERTION_4(true, "���Բ��ԣ�");
    ANIMATION_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::ArtificialIntellegenceTest()
{
    ARTIFICIAL_INTELLEGENCE_ASSERTION_0(true, "���Բ��ԣ�");
    ARTIFICIAL_INTELLEGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ARTIFICIAL_INTELLEGENCE_ASSERTION_1(true, "���Բ��ԣ�");
    ARTIFICIAL_INTELLEGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ARTIFICIAL_INTELLEGENCE_ASSERTION_2(true, "���Բ��ԣ�");
    ARTIFICIAL_INTELLEGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ARTIFICIAL_INTELLEGENCE_ASSERTION_3(true, "���Բ��ԣ�");
    ARTIFICIAL_INTELLEGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ARTIFICIAL_INTELLEGENCE_ASSERTION_4(true, "���Բ��ԣ�");
    ARTIFICIAL_INTELLEGENCE_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::UserInterfaceTest()
{
    USER_INTERFACE_ASSERTION_0(true, "���Բ��ԣ�");
    USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    USER_INTERFACE_ASSERTION_1(true, "���Բ��ԣ�");
    USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    USER_INTERFACE_ASSERTION_2(true, "���Բ��ԣ�");
    USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    USER_INTERFACE_ASSERTION_3(true, "���Բ��ԣ�");
    USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    USER_INTERFACE_ASSERTION_4(true, "���Բ��ԣ�");
    USER_INTERFACE_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::AssistToolsTest()
{
    ASSIST_TOOLS_ASSERTION_0(true, "���Բ��ԣ�");
    ASSIST_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ASSIST_TOOLS_ASSERTION_1(true, "���Բ��ԣ�");
    ASSIST_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ASSIST_TOOLS_ASSERTION_2(true, "���Բ��ԣ�");
    ASSIST_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ASSIST_TOOLS_ASSERTION_3(true, "���Բ��ԣ�");
    ASSIST_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ASSIST_TOOLS_ASSERTION_4(true, "���Բ��ԣ�");
    ASSIST_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::FrameworkTest()
{
    FRAMEWORK_ASSERTION_0(true, "���Բ��ԣ�");
    FRAMEWORK_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    FRAMEWORK_ASSERTION_1(true, "���Բ��ԣ�");
    FRAMEWORK_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    FRAMEWORK_ASSERTION_2(true, "���Բ��ԣ�");
    FRAMEWORK_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    FRAMEWORK_ASSERTION_3(true, "���Բ��ԣ�");
    FRAMEWORK_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    FRAMEWORK_ASSERTION_4(true, "���Բ��ԣ�");
    FRAMEWORK_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}

void CoreTools::ModuleCustomAssertMacroTesting::UserTest()
{
    USER_ASSERTION_0(true, "���Բ��ԣ�");
    USER_ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    USER_ASSERTION_1(true, "���Բ��ԣ�");
    USER_ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    USER_ASSERTION_2(true, "���Բ��ԣ�");
    USER_ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    USER_ASSERTION_3(true, "���Բ��ԣ�");
    USER_ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    USER_ASSERTION_4(true, "���Բ��ԣ�");
    USER_ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
}
