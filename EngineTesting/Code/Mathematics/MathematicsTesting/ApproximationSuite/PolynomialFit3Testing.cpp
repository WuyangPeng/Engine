///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 16:45)

#include "PolynomialFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit3Detail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class PolynomialFit3<float>;
    template class PolynomialFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialFit3Testing)

void Mathematics::PolynomialFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit3Testing::FitTest() noexcept
{
}
