///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 15:56)

#include "CyclicRedundancyCheck16Testing.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheck16.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

CoreTools::CyclicRedundancyCheck16Testing::CyclicRedundancyCheck16Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CyclicRedundancyCheck16Testing)

void CoreTools::CyclicRedundancyCheck16Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CyclicRedundancyCheck16Testing::MainTest()
{
    CyclicRedundancyCheckHandle::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CheckTest);

    CyclicRedundancyCheckHandle::Destroy();
}

void CoreTools::CyclicRedundancyCheck16Testing::CheckTest()
{
    std::array buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5', '7', '7' };

    const CyclicRedundancyCheck16 cyclicRedundancyCheck0{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check0 = cyclicRedundancyCheck0.GetCyclicRedundancyCheck16();

    buff.at(4) = '2';

    const CyclicRedundancyCheck16 cyclicRedundancyCheck1{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check1 = cyclicRedundancyCheck1.GetCyclicRedundancyCheck16();

    ASSERT_UNEQUAL(check0, check1);
}
