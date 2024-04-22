/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/28 10:51)

#ifndef CORE_TOOLS_HELPER_USER_MACRO_H
#define CORE_TOOLS_HELPER_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"

#define CORE_TOOLS_ClOSE_BEGIN (0x01)

#define CLOSE_ASSERT (CORE_TOOLS_ClOSE_BEGIN)
#define CLOSE_CLASS_INVARIANT (CORE_TOOLS_ClOSE_BEGIN << 1)
#define CLOSE_USE_IMPORTANT_EXCEPTION_ASSERT (CORE_TOOLS_ClOSE_BEGIN << 2)
#define CLOSE_USE_SAFETY_LIMIT (CORE_TOOLS_ClOSE_BEGIN << 3)
#define CLOSE_USE_OPEN_XLSX (CORE_TOOLS_ClOSE_BEGIN << 4)  /// Ĭ�ϲ�ʹ��

#define CORE_TOOLS_ClOSE_END CLOSE_USE_OPEN_XLSX

#define CLOSE_CORE_TOOLS_MAX (((CORE_TOOLS_ClOSE_END) << 1) - 1)

/// ������ԣ�Ĭ��Ϊ0B0001'0000�����ֵΪ0B0001'1111��
#define COMPILE_CORE_TOOLS_CLOSE 0B0000'0000

static_assert(0 <= COMPILE_CORE_TOOLS_CLOSE, "COMPILE_CORE_TOOLS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CORE_TOOLS_CLOSE <= CLOSE_CORE_TOOLS_MAX, "COMPILE_CORE_TOOLS_CLOSE Must be less than or equal CLOSE_CORE_TOOLS_MAX.");

#if defined(SYSTEM_PLATFORM_WIN32) && defined(_DEBUG)

    /// �Ƿ�ʹ�ö��ԣ�Ĭ��WIN32 DEBUG�汾ʹ�á�
    #if !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_ASSERT) != CLOSE_ASSERT

        #define OPEN_ASSERT static_cast<void>(0)

    #endif  // !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_ASSERT) != CLOSE_ASSERT

    /// �Ƿ�ʹ���಻��ʽ��Ĭ��WIN32 DEBUG�汾ʹ�á�
    #if !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_CLASS_INVARIANT) != CLOSE_CLASS_INVARIANT

        #define OPEN_CLASS_INVARIANT static_cast<void>(0)

    #endif  // !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_CLASS_INVARIANT) != CLOSE_CLASS_INVARIANT

#else  // !defined(SYSTEM_PLATFORM_WIN32) || !defined(_DEBUG)

    /// ����Release�汾��߼���Ķ��ԣ������׳��쳣����ѡ��Ի���
    #if !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_IMPORTANT_EXCEPTION_ASSERT) != CLOSE_USE_IMPORTANT_EXCEPTION_ASSERT

        #define OPEN_IMPORTANT_EXCEPTION_ASSERT static_cast<void>(0)

    #endif  // !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_IMPORTANT_EXCEPTION_ASSERT) != CLOSE_USE_IMPORTANT_EXCEPTION_ASSERT

#endif  // defined(SYSTEM_PLATFORM_WIN32) && defined(_DEBUG)

#if defined(OPEN_CLASS_INVARIANT) || defined(OPEN_ASSERT) || defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

    #if defined(SYSTEM_PLATFORM_WIN32) && defined(TCRE_USE_MSVC)

        #define CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW static_cast<void>(0)
        #define CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX static_cast<void>(0)

    #endif  // defined(SYSTEM_PLATFORM_WIN32) && defined(TCRE_USE_MSVC)

#endif  // defined(OPEN_CLASS_INVARIANT) || defined(OPEN_ASSERT) || defined(OPEN_IMPORTANT_EXCEPTION_ASSERT)

#if !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_SAFETY_LIMIT) != CLOSE_USE_SAFETY_LIMIT

    /// ����ȫ��������whileѭ����
    #define CORE_TOOLS_USE_SAFETY_LIMIT static_cast<void>(0)

#endif  // !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_USE_SAFETY_LIMIT) != CLOSE_USE_USE_SAFETY_LIMIT

#if !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_OPEN_XLSX) != CLOSE_USE_OPEN_XLSX

    #if defined(SYSTEM_PLATFORM_WIN32)

        /// �Ƿ�ʹ��OpenXLSX
        #define CORE_TOOLS_USE_OPEN_XLSX static_cast<void>(0)

    #endif  // defined(SYSTEM_PLATFORM_WIN32)

#endif  // !defined(COMPILE_CORE_TOOLS_CLOSE) || (COMPILE_CORE_TOOLS_CLOSE & CLOSE_USE_USE_OPENXLSX) != CLOSE_USE_USE_OPENXLSX

#ifdef BUILDING_STATIC

    #define BUILDING_CORE_TOOLS_STATIC static_cast<void>(0)

#endif  // BUILDING_STATIC

#ifdef OPEN_CLASS_INVARIANT

    /// �޼̳�
    #define CLASS_INVARIANT_DECLARE NODISCARD bool IsValid() const noexcept
    /// ����
    #define CLASS_INVARIANT_VIRTUAL_DECLARE NODISCARD virtual bool IsValid() const noexcept
    /// ����
    #define CLASS_INVARIANT_OVERRIDE_DECLARE NODISCARD bool IsValid() const noexcept override
    /// ��������
    #define CLASS_INVARIANT_FINAL_DECLARE NODISCARD bool IsValid() const noexcept final
    /// �����
    #define CLASS_INVARIANT_PURE_VIRTUAL_DECLARE NODISCARD virtual bool IsValid() const noexcept = 0

constexpr auto gOpenClassInvariant = true;

#else  // !OPEN_CLASS_INVARIANT

    #define CLASS_INVARIANT_DECLARE
    #define CLASS_INVARIANT_VIRTUAL_DECLARE
    #define CLASS_INVARIANT_OVERRIDE_DECLARE
    #define CLASS_INVARIANT_FINAL_DECLARE
    #define CLASS_INVARIANT_PURE_VIRTUAL_DECLARE

constexpr auto gOpenClassInvariant = false;

#endif  // OPEN_CLASS_INVARIANT

#define BOOST_LIB_DIAGNOSTIC static_cast<void>(0)

#include "System/Helper/PragmaWarning/Disable26444.inl"
#include "System/Helper/PragmaWarning/Disable26456.inl"

#endif  // CORE_TOOLS_HELPER_USER_MACRO_H
