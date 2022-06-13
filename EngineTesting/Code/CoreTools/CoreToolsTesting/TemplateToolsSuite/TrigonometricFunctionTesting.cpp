///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 10:46)

#include "TrigonometricFunctionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/NonrecursiveCosine.h"
#include "CoreTools/TemplateTools/NonrecursiveSine.h"
#include "CoreTools/TemplateTools/NonrecursiveTangent.h"
#include "CoreTools/TemplateTools/RecursiveSine.h"
#include "CoreTools/TemplateTools/TrigonometricFunction.h"
#include "Mathematics/Base/MathDetail.h"

#include <cmath>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TrigonometricFunctionTesting)

void CoreTools::TrigonometricFunctionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursiveVsNonrecursiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NonrecursiveCorrectTest);
}

void CoreTools::TrigonometricFunctionTesting::RecursiveVsNonrecursiveTest()
{
    for (auto fRad = 0.0; fRad < 2 * Mathematics::MathD::GetPI(); fRad += 0.01)
    {
        ASSERT_APPROXIMATE(TrigonometricFunction::RecursiveSine(fRad), TrigonometricFunction::NonRecursiveSine(fRad), 1e-4);
    }
}

void CoreTools::TrigonometricFunctionTesting::NonrecursiveCorrectTest()
{
    for (auto fRad = 0.0; fRad < 2 * Mathematics::MathD::GetPI(); fRad += 0.01)
    {
        ASSERT_APPROXIMATE(sin(fRad), TrigonometricFunction::NonRecursiveSine(fRad), 1e-4);
    }
}
