///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 11:37)

#include "Torus3ParametersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Objects3D/Torus3ParametersDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Torus3Parameters<float>;
    template class Torus3Parameters<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::Torus3ParametersTesting::Torus3ParametersTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Torus3ParametersTesting)

void Mathematics::Torus3ParametersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
