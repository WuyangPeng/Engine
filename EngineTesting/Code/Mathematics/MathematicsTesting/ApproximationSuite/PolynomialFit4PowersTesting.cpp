///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:19)

#include "PolynomialFit4PowersTesting.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit4PowersDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

namespace Mathematics
{
    template class PolynomialFit4Powers<float>;
    template class PolynomialFit4Powers<double>;
}

Mathematics::PolynomialFit4PowersTesting::PolynomialFit4PowersTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolynomialFit4PowersTesting)

void Mathematics::PolynomialFit4PowersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolynomialFit4PowersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit4PowersTesting::FitTest() noexcept
{
}
