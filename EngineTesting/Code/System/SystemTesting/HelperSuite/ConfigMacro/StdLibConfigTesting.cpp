/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 17:34)

#include "StdLibConfigTesting.h"
#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::StdLibConfigTesting::StdLibConfigTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StdLibConfigTesting)

void System::StdLibConfigTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StdLibConfigTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StdLibTest);
}

void System::StdLibConfigTesting::StdLibTest()
{
    auto& stream = GetStream();

    stream << "��׼��汾�ǣ�" << TCRE_CPP_LIB_VERSION << '\n';
    stream << "��׼���ǣ�" << TCRE_SYSTEM_STD_LIB << '\n';
}

void System::StdLibConfigTesting::DinkumwareTest() const noexcept
{
#ifdef TCRE_USE_DINKUMWARE

    static_assert(TCRE_DINKUMWARE_STD_LIB == _CPPLIB_VER);

#endif  // TCRE_USE_DINKUMWARE
}