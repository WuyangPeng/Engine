///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 18:31)

#include "TransformTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/Transform.h"

#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TransformTesting)

void Rendering::TransformTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InverseTest);
}

void Rendering::TransformTesting::BaseTest() noexcept
{
}

void Rendering::TransformTesting::OperatorTest() noexcept
{
}

void Rendering::TransformTesting::InverseTest() noexcept
{
}