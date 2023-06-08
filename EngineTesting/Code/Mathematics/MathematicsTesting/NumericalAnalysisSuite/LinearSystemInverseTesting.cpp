///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/02 18:17)

#include "LinearSystemInverseTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

Mathematics::LinearSystemInverseTesting::LinearSystemInverseTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, LinearSystemInverseTesting)

void Mathematics::LinearSystemInverseTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::LinearSystemInverseTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InverseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SolveTest);
}

void Mathematics::LinearSystemInverseTesting::InverseTest() noexcept
{
}

void Mathematics::LinearSystemInverseTesting::SolveTest() noexcept
{
}
