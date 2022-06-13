///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/31 11:37)

#include "Torus3ParametersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Objects3D/Torus3ParametersDetail.h"

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Torus3Parameters<float>;
    template class Torus3Parameters<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Torus3ParametersTesting)

void Mathematics::Torus3ParametersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ParametersTest);
}

void Mathematics::Torus3ParametersTesting::ParametersTest()
{
    const Torus3ParametersF parameters(0.5f, 0.2f);

    ASSERT_APPROXIMATE(parameters.GetS(), 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(parameters.GetT(), 0.2f, 1e-8f);
}
