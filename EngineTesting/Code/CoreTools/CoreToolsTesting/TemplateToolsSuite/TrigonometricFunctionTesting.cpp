// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:17)

#include "TrigonometricFunctionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/NonrecursiveCosine.h"
#include "CoreTools/TemplateTools/NonrecursiveSine.h"
#include "CoreTools/TemplateTools/NonrecursiveTangent.h"
#include "CoreTools/TemplateTools/RecursiveSine.h"
#include "CoreTools/TemplateTools/TrigonometricFunction.h"

#include <cmath>

// SINE_SPECIALIZATION_DEFINE(g_Value0_0, 0.0);
// SINE_SPECIALIZATION_DEFINE(g_Value0_1, 0.1);
// SINE_SPECIALIZATION_DEFINE(g_Value0_21, 0.21);
// SINE_SPECIALIZATION_DEFINE(g_Value0_3, 0.3);
// SINE_SPECIALIZATION_DEFINE(g_Value0_41, 0.41);
// SINE_SPECIALIZATION_DEFINE(g_Value0_501, 0.501);
// SINE_SPECIALIZATION_DEFINE(g_Value0_6001, 0.6001);
// SINE_SPECIALIZATION_DEFINE(g_Value0_7, 0.7);
// SINE_SPECIALIZATION_DEFINE(g_Value0_85, 0.85);
// SINE_SPECIALIZATION_DEFINE(g_Value0_9, 0.9);
// SINE_SPECIALIZATION_DEFINE(g_Value1_03, 1.03);
// SINE_SPECIALIZATION_DEFINE(g_Value2_22, 2.22);
// SINE_SPECIALIZATION_DEFINE(g_Value3_23, 3.23);
// SINE_SPECIALIZATION_DEFINE(g_Value4_89, 4.89);
// SINE_SPECIALIZATION_DEFINE(g_Value5_66, 5.66);
// SINE_SPECIALIZATION_DEFINE(g_Value6_1, 6.1);

constexpr double g_Pi{ 3.14159265358979323846264338328 };

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TrigonometricFunctionTesting)

void CoreTools::TrigonometricFunctionTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursiveVsNonrecursiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NonrecursiveCorrectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TemplateRecursiveVersionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TemplateNonrecursiveVersionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CosineTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TangentTest);
}

void CoreTools::TrigonometricFunctionTesting ::RecursiveVsNonrecursiveTest()
{
    for (auto fRad = 0.0; fRad < 2 * g_Pi; fRad += 0.01)
    {
        ASSERT_APPROXIMATE(TrigonometricFunction::RecursiveSine(fRad), TrigonometricFunction::NonRecursiveSine(fRad), 1e-4);
    }
}

void CoreTools::TrigonometricFunctionTesting ::NonrecursiveCorrectTest()
{
    for (auto fRad = 0.0; fRad < 2 * g_Pi; fRad += 0.01)
    {
        ASSERT_APPROXIMATE(sin(fRad), TrigonometricFunction::NonRecursiveSine(fRad), 1e-4);
    }
}

void CoreTools::TrigonometricFunctionTesting ::TemplateRecursiveVersionTest() noexcept
{
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value0_0), sin(g_Value0_0), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value0_1), sin(g_Value0_1), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value0_21), sin(g_Value0_21), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value0_3), sin(g_Value0_3), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value0_41), sin(g_Value0_41), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value0_501), sin(g_Value0_501), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value0_6001), sin(g_Value0_6001), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value0_7), sin(g_Value0_7), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value0_85), sin(g_Value0_85), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value0_9), sin(g_Value0_9), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value1_03), sin(g_Value1_03), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value2_22), sin(g_Value2_22), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value3_23), sin(g_Value3_23), 1e-10);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value4_89), sin(g_Value4_89), 1e-6);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value5_66), sin(g_Value5_66), 1e-5);
    // 	ASSERT_APPROXIMATE(RECURSIVE_SINE(g_Value6_1), sin(g_Value6_1), 1e-4);
}

void CoreTools::TrigonometricFunctionTesting ::TemplateNonrecursiveVersionTest() noexcept
{
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value0_0), sin(g_Value0_0), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value0_1), sin(g_Value0_1), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value0_21), sin(g_Value0_21), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value0_3), sin(g_Value0_3), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value0_41), sin(g_Value0_41), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value0_501), sin(g_Value0_501), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value0_6001), sin(g_Value0_6001), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value0_7), sin(g_Value0_7), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value0_85), sin(g_Value0_85), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value0_9), sin(g_Value0_9), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value1_03), sin(g_Value1_03), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value2_22), sin(g_Value2_22), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value3_23), sin(g_Value3_23), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value4_89), sin(g_Value4_89), 1e-6);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value5_66), sin(g_Value5_66), 1e-5);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_SINE(g_Value6_1), sin(g_Value6_1), 1e-4);
}

void CoreTools::TrigonometricFunctionTesting ::CosineTest() noexcept
{
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value0_0), cos(g_Value0_0), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value0_1), cos(g_Value0_1), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value0_21), cos(g_Value0_21), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value0_3), cos(g_Value0_3), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value0_41), cos(g_Value0_41), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value0_501), cos(g_Value0_501), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value0_6001), cos(g_Value0_6001), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value0_7), cos(g_Value0_7), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value0_85), cos(g_Value0_85), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value0_9), cos(g_Value0_9), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value1_03), cos(g_Value1_03), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value2_22), cos(g_Value2_22), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value3_23), cos(g_Value3_23), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value4_89), cos(g_Value4_89), 1e-6);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value5_66), cos(g_Value5_66), 1e-5);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_COSINE(g_Value6_1), cos(g_Value6_1), 1e-4);
}

void CoreTools::TrigonometricFunctionTesting ::TangentTest() noexcept
{
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value0_0), tan(g_Value0_0), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value0_1), tan(g_Value0_1), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value0_21), tan(g_Value0_21), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value0_3), tan(g_Value0_3), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value0_41), tan(g_Value0_41), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value0_501), tan(g_Value0_501), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value0_6001), tan(g_Value0_6001), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value0_7), tan(g_Value0_7), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value0_85), tan(g_Value0_85), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value0_9), tan(g_Value0_9), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value1_03), tan(g_Value1_03), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value2_22), tan(g_Value2_22), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value3_23), tan(g_Value3_23), 1e-10);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value4_89), tan(g_Value4_89), 1e-6);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value5_66), tan(g_Value5_66), 1e-5);
    // 	ASSERT_APPROXIMATE(NONRECURSIVE_TANGENT(g_Value6_1), tan(g_Value6_1), 1e-4);
}
