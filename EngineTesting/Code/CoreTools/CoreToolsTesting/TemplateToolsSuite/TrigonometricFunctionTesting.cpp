///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 10:46)

#include "TrigonometricFunctionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/NonRecursiveCosine.h"
#include "CoreTools/TemplateTools/NonRecursiveSine.h"
#include "CoreTools/TemplateTools/NonRecursiveTangent.h"
#include "CoreTools/TemplateTools/RecursiveSine.h"
#include "CoreTools/TemplateTools/TrigonometricFunction.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <cmath>

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
