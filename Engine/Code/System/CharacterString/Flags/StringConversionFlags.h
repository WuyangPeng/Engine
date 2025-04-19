/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:04)

#ifndef SYSTEM_CHARACTER_STRING_STRING_CONVERSION_FLAGS_H
#define SYSTEM_CHARACTER_STRING_STRING_CONVERSION_FLAGS_H

#include "System/Helper/EnumCast.h"
#include "System/Helper/Platform.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Flags/PrimaryLanguageFlags.h"
#include "System/SystemOutput/Flags/SubLanguageFlags.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class MultiByte
    {
        NoFlags = 0,
        ErrInvalidChars = MB_ERR_INVALID_CHARS,
    };

    enum class WideChar
    {
        NoFlags = 0,
        NoBestFitChars = WC_NO_BEST_FIT_CHARS,
    };

    enum class LanguageLocale
    {
        SystemDefault = LOCALE_SYSTEM_DEFAULT,
        UserDefault = LOCALE_USER_DEFAULT,
        CustomDefault = LOCALE_CUSTOM_DEFAULT,
        CustomUnspecified = LOCALE_CUSTOM_UNSPECIFIED,
        CustomUiDefault = LOCALE_CUSTOM_UI_DEFAULT,
        Neutral = LOCALE_NEUTRAL,
        Invariant = LOCALE_INVARIANT,
    };

    enum class Compares
    {
        NormIgnoreCase = NORM_IGNORECASE,
        NormIgnoreNonSpace = NORM_IGNORENONSPACE,
        NormIgnoreSymbols = NORM_IGNORESYMBOLS,

        LinguisticIgnoreCase = LINGUISTIC_IGNORECASE,
        LinguisticIgnoreDiacritic = LINGUISTIC_IGNOREDIACRITIC,

        NormIgnoreKanaType = NORM_IGNOREKANATYPE,
        NormIgnoreWidth = NORM_IGNOREWIDTH,
        NormLinguisticCasing = NORM_LINGUISTIC_CASING,

        SortStringSort = SORT_STRINGSORT,
        SortDigitsAsNumbers = SORT_DIGITSASNUMBERS,
    };

    enum class ComparesStringReturn
    {
        ComparesNotSucceed = 0,
        LessThan = CSTR_LESS_THAN,
        Equal = CSTR_EQUAL,
        GreaterThan = CSTR_GREATER_THAN,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class MultiByte
    {
        NoFlags = 0,
        PreComposed = 0x00000001,
        Complsite = 0x00000002,
        UseGlyphChars = 0x00000004,
        ErrInvalidChars = 0x00000008,
    };

    enum class WideChar
    {
        NoFlags = 0,
        CompositeCheck = 0x00000200,
        DiscardNS = 0x00000010,
        SepChars = 0x00000020,
        DefaultChar = 0x00000040,
        ErrInvalidChars = 0x00000080,
        NoBestFitChars = 0x00000400,
    };

    static constexpr auto gLanguageSystemDefault = MakeLanguageId(EnumCastUnderlying(PrimaryLanguage::Neutral), EnumCastUnderlying(SubLanguage::SysDefault));
    static constexpr auto gLanguageUserDefault = MakeLanguageId(EnumCastUnderlying(PrimaryLanguage::Neutral), EnumCastUnderlying(SubLanguage::Default));

    enum class LanguageLocale
    {
        SystemDefault = MakeLanguageCid(gLanguageSystemDefault, 0x0),
        UserDefault = MakeLanguageCid(gLanguageUserDefault, 0x0),
        CustomDefault = MakeLanguageCid(MakeLanguageId(EnumCastUnderlying(PrimaryLanguage::Neutral), EnumCastUnderlying(SubLanguage::CustomDefault)), 0x0),
        CustomUnspecified = MakeLanguageCid(MakeLanguageId(EnumCastUnderlying(PrimaryLanguage::Neutral), EnumCastUnderlying(SubLanguage::CustomUnspecified)), 0x0),
        CustomUiDefault = MakeLanguageCid(MakeLanguageId(EnumCastUnderlying(PrimaryLanguage::Neutral), EnumCastUnderlying(SubLanguage::UICustomDefault)), 0x0),
        Neutral = MakeLanguageCid(MakeLanguageId(EnumCastUnderlying(PrimaryLanguage::Neutral), EnumCastUnderlying(SubLanguage::Neutral)), 0x0),
        Invariant = MakeLanguageCid(MakeLanguageId(EnumCastUnderlying(PrimaryLanguage::Invariant), EnumCastUnderlying(SubLanguage::Neutral)), 0x0),
    };

    enum class Compares
    {
        NormIgnoreCase = 0x00000001,
        NormIgnoreNonSpace = 0x00000002,
        NormIgnoreSymbols = 0x00000004,

        LinguisticIgnoreCase = 0x00000010,
        LinguisticIgnoreDiacritic = 0x00000020,

        NormIgnoreKanaType = 0x00010000,
        NormIgnoreWidth = 0x00020000,
        NormLinguisticCasing = 0x08000000,

        SortStringSort = 0x00001000,
        SortDigitsAsNumbers = 0x00000008,
    };

    enum class ComparesStringReturn
    {
        ComparesNotSucceed = 0,
        LessThan = 1,
        Equal = 2,
        GreaterThan = 3,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CHARACTER_STRING_STRING_CONVERSION_FLAGS_H
