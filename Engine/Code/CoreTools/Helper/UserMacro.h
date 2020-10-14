//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/07 19:04)

#ifndef CORE_TOOLS_HELPER_USER_MACRO_H
#define CORE_TOOLS_HELPER_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"

#define CORE_TOOLS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_MEMORY_MANAGER (CORE_TOOLS_ClOSE_BEGIN)
#define CLOSE_ASSERT (CORE_TOOLS_ClOSE_BEGIN << 1)
#define CLOSE_CLASS_INVARIANT (CORE_TOOLS_ClOSE_BEGIN << 2)
#define CLOSE_USE_IMPORTANT_EXCPTION_ASSERT (CORE_TOOLS_ClOSE_BEGIN << 3)
#define CLOSE_USE_USE_SAFETY_LIMIT (CORE_TOOLS_ClOSE_BEGIN << 4)

#define CORE_TOOLS_ClOSE_END CLOSE_USE_USE_SAFETY_LIMIT

#define CLOSE_CORE_TOOLS_MAX (((CORE_TOOLS_ClOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x1F）
#define COMPILE_CORE_TOOLS_CLOSE 0x00

static_assert(0 <= COMPILE_CORE_TOOLS_CLOSE, "COMPILE_CORE_TOOLS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CORE_TOOLS_CLOSE <= CLOSE_CORE_TOOLS_MAX, "COMPILE_CORE_TOOLS_CLOSE Must be less than or equal CLOSE_CORE_TOOLS_MAX.");

#ifdef _DEBUG

    // 是否使用内存管理，默认DEBUG版本使用。
    #if !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_MEMORY_MANAGER) != CLOSE_USE_MEMORY_MANAGER
        #define OPEN_USE_MEMORY static_cast<void>(0)
    #endif  // !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_MEMORY_MANAGER) != CLOSE_USE_MEMORY_MANAGER

    #if defined(SYSTEM_PLATFORM_WIN32)

        // 是否使用断言，默认WIN32 DEBUG版本使用。
        #if !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_ASSERT) != CLOSE_ASSERT
            #define OPEN_ASSERT static_cast<void>(0)
        #endif  // !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_ASSERT) != CLOSE_ASSERT

        // 是否使用类不变式，默认WIN32 DEBUG版本使用。
        #if !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_CLASS_INVARIANT) != CLOSE_CLASS_INVARIANT
            #define OPEN_CLASS_INVARIANT static_cast<void>(0)
        #endif  // !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_CLASS_INVARIANT) != CLOSE_CLASS_INVARIANT

    #endif  // SYSTEM_PLATFORM_WIN32

    // 内存管理单例DEBUG版本默认创建。
    #define CORE_TOOLS_MEMORY_ALWAYS_CREATE static_cast<void>(0)

#else  // !_DEBUG

    // 开启Release版本最高级别的断言，并用抛出异常代替选择对话框。
    #if !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_IMPORTANT_EXCPTION_ASSERT) != CLOSE_USE_IMPORTANT_EXCPTION_ASSERT
        #define OPEN_IMPORTANT_EXCPTION_ASSERT static_cast<void>(0)
    #endif  // !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_IMPORTANT_EXCPTION_ASSERT) != CLOSE_USE_IMPORTANT_EXCPTION_ASSERT

#endif  // _DEBUG

#if defined(OPEN_CLASS_INVARIANT) || defined(OPEN_ASSERT) || defined(OPEN_IMPORTANT_EXCPTION_ASSERT)

    #if defined(SYSTEM_PLATFORM_WIN32) && defined(TCRE_USE_MSVC)

        #define CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW static_cast<void>(0)
        #define CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX static_cast<void>(0)

    #endif  // defined(SYSTEM_PLATFORM_WIN32) && defined(TCRE_USE_MSVC)

#endif  // defined(OPEN_CLASS_INVARIANT) || defined(OPEN_ASSERT) || defined(OPEN_IMPORTANT_EXCPTION_ASSERT)

// 带安全计数器的while循环。
#if !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_USE_SAFETY_LIMIT) != CLOSE_USE_USE_SAFETY_LIMIT
    #define CORE_TOOLS_USE_SAFETY_LIMIT static_cast<void>(0)
#endif  // !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_USE_SAFETY_LIMIT) != CLOSE_USE_USE_SAFETY_LIMIT

#ifdef OPEN_CLASS_INVARIANT

    // 无继承
    #define CLASS_INVARIANT_DECLARE [[nodiscard]] bool IsValid() const noexcept
    // 基类
    #define CLASS_INVARIANT_VIRTUAL_DECLARE [[nodiscard]] virtual bool IsValid() const noexcept
    // 子类
    #define CLASS_INVARIANT_OVERRIDE_DECLARE [[nodiscard]] bool IsValid() const noexcept override
    // 最终子类
    #define CLASS_INVARIANT_FINAL_DECLARE [[nodiscard]] bool IsValid() const noexcept final

#else  // !OPEN_CLASS_INVARIANT

    #define CLASS_INVARIANT_DECLARE
    #define CLASS_INVARIANT_VIRTUAL_DECLARE
    #define CLASS_INVARIANT_OVERRIDE_DECLARE
    #define CLASS_INVARIANT_FINAL_DECLARE

#endif  // OPEN_CLASS_INVARIANT

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_CORE_TOOLS_STATIC static_cast<void>(0)
#endif  // BUILDING_STATIC

#define BOOST_LIB_DIAGNOSTIC static_cast<void>(0)

#include "System/Helper/PragmaWarning/Disable26444.h"

#endif  // CORE_TOOLS_HELPER_USER_MACRO_H
