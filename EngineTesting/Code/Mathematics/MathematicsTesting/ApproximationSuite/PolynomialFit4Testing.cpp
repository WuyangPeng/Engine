///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:19)

#include "PolynomialFit4Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit4Detail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

namespace Mathematics
{
    template class PolynomialFit4<float>;
    template class PolynomialFit4<double>;
}

Mathematics::PolynomialFit4Testing::PolynomialFit4Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolynomialFit4Testing)

void Mathematics::PolynomialFit4Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolynomialFit4Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit4Testing::FitTest() noexcept
{
}
