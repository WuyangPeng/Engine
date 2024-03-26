/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 17:07)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/VariableTemplateType.h"

#include <cstdarg>

namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE StringCat(char* destination, size_t sizeInBytes, const char* source) noexcept;

    NODISCARD size_t SYSTEM_DEFAULT_DECLARE StringLength(const char* string) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE StringCopy(char* destination, size_t sizeInBytes, char const* source) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE char* StringToken(char* string, char const* delimiter, char** context) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE const char* StringString(char const* string, char const* subString) noexcept;

    /// ���ش洢��buffer�е��ַ�����������ֹnull�ַ������󷵻� -1��
    NODISCARD int SYSTEM_DEFAULT_DECLARE VsnPrintF(char* buffer, size_t size, const char* format, va_list argList) noexcept;

    /// ���ش洢��buffer�е��ַ���
    /// ��������ֹnull�ַ���
    /// �����sizeInBytes��С������ֹnull�ַ���
    /// buffer�Ĵ�С����ΪsizeInBytes��
    /// ���󷵻�-1��
    template <typename... Types>
    NODISCARD int SnPrintF(char* buffer, size_t sizeInBytes, size_t maxCount, const char* format, Types... args) noexcept requires(std::is_same_v<typename IsScalar<Types...>::Type, std::true_type>);
    ;
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
