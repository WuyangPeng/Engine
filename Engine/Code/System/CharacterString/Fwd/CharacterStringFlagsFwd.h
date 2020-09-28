//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:16)

#ifndef SYSTEM_CHARACTER_STRING_CHARACTER_STRING_FLAGS_FWD_H
#define SYSTEM_CHARACTER_STRING_CHARACTER_STRING_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    // CodePage
    enum class CodePage;

    // FormatMessage
    enum class FormatMessageOption;
    enum class FormatMessageWidth;

    // FormatString
    enum class StringSafe;

    // StringConversion
    enum class MultiByte;
    enum class WideChar;
    enum class LocaleSort;
    enum class LanguageLocale;
    enum class Compares;
    enum class ComparesStringReturn;
    enum class LocaleIndependentMapping;
    enum class CharacterType;
    enum class CharacterTypeC1Bits;
    enum class CharacterTypeC2Bits;
    enum class CharacterTypeC3Bits;
}

#endif  // SYSTEM_CHARACTER_STRING_CHARACTER_STRING_FLAGS_FWD_H