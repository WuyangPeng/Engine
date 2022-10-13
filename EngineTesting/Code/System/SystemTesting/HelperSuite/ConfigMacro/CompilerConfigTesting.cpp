///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/14 14:29)

#include "CompilerConfigTesting.h"
#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CompilerConfigTesting::CompilerConfigTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CompilerConfigTesting)

void System::CompilerConfigTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CompilerConfigTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CompilerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VisualcTest);
}

void System::CompilerConfigTesting::CompilerTest()
{
    auto& stream = GetStream();

    stream << "������ʹ�õ�C++��׼��C++" << SYSTEM_CPP_STANDARD << "\n";

    stream << "�������ǣ�" << TCRE_SYSTEM_COMPILER << "\n";

    stream << "������ʹ�õİ汾�ǣ�" << TCRE_COMPILER_VERSION << "\n";
}

void System::CompilerConfigTesting::VisualcTest() noexcept
{
#ifdef TCRE_USE_MSVC

    static_assert(MSVC_VERSION == TCRE_USE_MSVC);

    static_assert(0 < MSVC_FULL_VERSION);
    static_assert(0 < MSVC_COMPILER_VERSION);

#endif  // TCRE_USE_MSVC
}
