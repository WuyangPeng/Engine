/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:31)

#include "CSVDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Data/IntVector2.h"
#include "CoreTools/TextParsing/Data/IntVector3.h"
#include "CoreTools/TextParsing/Data/IntVector4.h"
#include "CoreTools/TextParsing/Data/Vector2.h"
#include "CoreTools/TextParsing/Data/Vector3.h"
#include "CoreTools/TextParsing/Data/Vector4.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::CSVDataTesting::CSVDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVDataTesting)

void CoreTools::CSVDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CSVDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Vector2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Vector3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Vector4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(IntVector2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(IntVector3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(IntVector4Test);
}

void CoreTools::CSVDataTesting::Vector2Test()
{
    constexpr auto vector2 = Vector2{ 1.1, 2.3 };

    ASSERT_APPROXIMATE(vector2.GetX(), 1.1, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(vector2.GetY(), 2.3, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::CSVDataTesting::Vector3Test()
{
    constexpr auto vector3 = Vector3{ 1.1, 2.2, 3.3 };

    ASSERT_APPROXIMATE(vector3.GetX(), 1.1, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(vector3.GetY(), 2.2, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(vector3.GetZ(), 3.3, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::CSVDataTesting::Vector4Test()
{
    constexpr auto vector4 = Vector4{ 1.3, 2.2, 3.9, 4.3 };

    ASSERT_APPROXIMATE(vector4.GetX(), 1.3, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(vector4.GetY(), 2.2, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(vector4.GetZ(), 3.9, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(vector4.GetW(), 4.3, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::CSVDataTesting::IntVector2Test() noexcept
{
    constexpr auto intVector2 = IntVector2{ 1, 2 };

    static_assert(intVector2.GetX() == 1);
    static_assert(intVector2.GetY() == 2);
}

void CoreTools::CSVDataTesting::IntVector3Test() noexcept
{
    constexpr auto intVector3 = IntVector3{ 1, 2, 3 };

    static_assert(intVector3.GetX() == 1);
    static_assert(intVector3.GetY() == 2);
    static_assert(intVector3.GetZ() == 3);
}

void CoreTools::CSVDataTesting::IntVector4Test() noexcept
{
    constexpr auto intVector4 = IntVector4{ 1, 2, 3, 4 };

    static_assert(intVector4.GetX() == 1);
    static_assert(intVector4.GetY() == 2);
    static_assert(intVector4.GetZ() == 3);
    static_assert(intVector4.GetW() == 4);
}
