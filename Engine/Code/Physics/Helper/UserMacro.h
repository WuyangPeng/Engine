///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 16:36)

#ifndef PHYSICS_MACRO_USER_MACRO_H
#define PHYSICS_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Mathematics/Helper/UserMacro.h"

#define CLOSE_PHYSICS_USE_EXPORT_TEMPLATE (0x01)
#define CLOSE_LCPSOLVER_LOG (0x01 << 1)
#define CLOSE_LCPPOLYDIST_LOG (0x01 << 2)
#define CLOSE_USE_PHYSICS_TEMPLATE_TEST (0x01 << 3)
#define CLOSE_PHYSICS_MAX (((CLOSE_USE_PHYSICS_TEMPLATE_TEST) << 1) - 1)

// 编译测试（默认为0x08，最大值为0x0F）
#define COMPILE_PHYSICS_CLOSE 0x00

static_assert(0 <= COMPILE_PHYSICS_CLOSE, "COMPILE_PHYSICS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_PHYSICS_CLOSE <= CLOSE_PHYSICS_MAX, "COMPILE_PHYSICS_CLOSE Must be less than or equal CLOSE_MATHEMATICS_MAX.");

#if !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_PHYSICS_USE_EXPORT_TEMPLATE) != CLOSE_PHYSICS_USE_EXPORT_TEMPLATE

    #define PHYSICS_EXPORT_TEMPLATE

#endif  // !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_PHYSICS_USE_EXPORT_TEMPLATE) != CLOSE_PHYSICS_USE_EXPORT_TEMPLATE

#ifdef PHYSICS_EXPORT_TEMPLATE

    #define PHYSICS_TEMPLATE_DEFAULT_DECLARE PHYSICS_DEFAULT_DECLARE

#else  // !PHYSICS_EXPORT_TEMPLATE

    #define PHYSICS_TEMPLATE_DEFAULT_DECLARE

#endif  // PHYSICS_EXPORT_TEMPLATE

#if !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_LCPSOLVER_LOG) != CLOSE_LCPSOLVER_LOG

    #define PHYSICS_LCPSOLVER_LOG

#endif  // !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_LCPSOLVER_LOG) != CLOSE_LCPSOLVER_LOG

#if !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_LCPPOLYDIST_LOG) != CLOSE_LCPPOLYDIST_LOG

    #define PHYSICS_LCPPOLYDIST_LOG

#endif  // !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_LCPPOLYDIST_LOG) != CLOSE_LCPPOLYDIST_LOG

// 对于LCPSolver的测试和调试期间消息写入日志文件
#ifdef PHYSICS_LCPSOLVER_LOG

    #define PHYSICS_LCPSOLVER_FUNCTION(func) func

#else  // !PHYSICS_LCPSOLVER_LOG

    #define PHYSICS_LCPSOLVER_FUNCTION(func)

#endif  // PHYSICS_LCPSOLVER_LOG

// 对于LCPPolynomialDistance的测试和调试期间消息写入日志文件。如果启用此，在计算距离时显示会显著减慢。
#ifdef PHYSICS_LCPPOLYDIST_LOG

    #define PHYSICS_LCPPOLYDIST_FUNCTION(func) func

#else  // !PHYSICS_LCPPOLYDIST_LOG

    #define PHYSICS_LCPPOLYDIST_FUNCTION(func)

#endif  // PHYSICS_LCPPOLYDIST_LOG

#if !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_USE_PHYSICS_TEMPLATE_TEST) != CLOSE_USE_PHYSICS_TEMPLATE_TEST

    #ifndef BUILDING_STATIC

        #define PHYSICS_TEMPLATE_TEST static_cast<void>(0)

    #endif  // BUILDING_STATIC

#endif  // !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_USE_PHYSICS_TEMPLATE_TEST) != CLOSE_USE_PHYSICS_TEMPLATE_TEST

#ifdef BUILDING_STATIC

    #define BUILDING_PHYSICS_STATIC static_cast<void>(0)

#endif  // BUILDING_STATIC

#endif  // PHYSICS_MACRO_USER_MACRO_H
