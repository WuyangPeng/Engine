/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:43)

#include "TrigonometricFunctionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/NonRecursiveCosine.h"
#include "CoreTools/TemplateTools/NonRecursiveSine.h"
#include "CoreTools/TemplateTools/NonRecursiveTangent.h"
#include "CoreTools/TemplateTools/RecursiveSine.h"
#include "CoreTools/TemplateTools/TrigonometricFunction.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::TrigonometricFunctionTesting::TrigonometricFunctionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TrigonometricFunctionTesting)

void CoreTools::TrigonometricFunctionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TrigonometricFunctionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursiveVsNonRecursiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NonRecursiveCorrectTest);
}

void CoreTools::TrigonometricFunctionTesting::RecursiveVsNonRecursiveTest()
{
    for (auto rad = 0.0; rad < 2 * Mathematics::MathD::GetPI(); rad += 0.01)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoRecursiveVsNonRecursiveTest, rad);
    }
}

void CoreTools::TrigonometricFunctionTesting::DoRecursiveVsNonRecursiveTest(double rad)
{
    ASSERT_APPROXIMATE(TrigonometricFunction::RecursiveSine(rad), TrigonometricFunction::NonRecursiveSine(rad), 1e-04);
    ASSERT_APPROXIMATE(NON_RECURSIVE_SINE(rad), TrigonometricFunction::NonRecursiveSine(rad), Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::TrigonometricFunctionTesting::NonRecursiveCorrectTest()
{
    for (auto rad = 0.0; rad < 2 * Mathematics::MathD::GetPI(); rad += 0.01)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoNonRecursiveCorrectTest, rad);
    }
}

void CoreTools::TrigonometricFunctionTesting::DoNonRecursiveCorrectTest(double rad)
{
    ASSERT_APPROXIMATE(Mathematics::MathD::Sin(rad), TrigonometricFunction::NonRecursiveSine(rad), 1e-04);
    ASSERT_APPROXIMATE(NON_RECURSIVE_COSINE(rad) * NON_RECURSIVE_TANGENT(rad), TrigonometricFunction::NonRecursiveSine(rad), Mathematics::MathD::GetZeroTolerance());
}