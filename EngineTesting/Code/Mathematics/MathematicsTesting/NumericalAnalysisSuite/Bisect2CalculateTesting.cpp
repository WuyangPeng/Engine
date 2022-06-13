///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/02 16:10)

#include "Bisect2CalculateTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect2Detail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Bisect2CalculateTesting)

void Mathematics::Bisect2CalculateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect2CalculateTesting::HaveSolutionTest() noexcept
{
}

void Mathematics::Bisect2CalculateTesting::NoSolutionTest() noexcept
{
}

void Mathematics::Bisect2CalculateTesting::UnknownTest() noexcept
{
}
