///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 22:28)

#ifndef SYSTEM_CHARACTER_STRING_STRING_CONVERSION_FLAGS_H
#define SYSTEM_CHARACTER_STRING_STRING_CONVERSION_FLAGS_H

#include "System/Helper/Platform.h"
#include "System/Helper/WindowsMacro.h"

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

    enum class LocaleSort
    {
        Default = SORT_DEFAULT,

        InvariantMath = SORT_INVARIANT_MATH,

        JapaneseXjis = SORT_JAPANESE_XJIS,
        JapaneseUnicode = SORT_JAPANESE_UNICODE,
        JapaneseRadicalStroke = SORT_JAPANESE_RADICALSTROKE,

        ChineseBig5 = SORT_CHINESE_BIG5,
        ChinesePRCP = SORT_CHINESE_PRCP,
        ChineseUnicode = SORT_CHINESE_UNICODE,
        ChinesePRC = SORT_CHINESE_PRC,
        ChineseBopomofo = SORT_CHINESE_BOPOMOFO,
        ChineseRadicalStroke = SORT_CHINESE_RADICALSTROKE,

        KoreanKSC = SORT_KOREAN_KSC,
        KoreanUnicode = SORT_KOREAN_UNICODE,

        GermanPhoneBook = SORT_GERMAN_PHONE_BOOK,

        HungarianDefault = SORT_HUNGARIAN_DEFAULT,
        HungarianTechnical = SORT_HUNGARIAN_TECHNICAL,

        GeorgianTraditional = SORT_GEORGIAN_TRADITIONAL,
        GeorgianModern = SORT_GEORGIAN_MODERN,
    };

    enum class LanguageLocale
    {
        SystemDefault = LOCALE_SYSTEM_DEFAULT,
        UserDefault = LOCALE_USER_DEFAULT,

        CustomDefault = LOCALE_CUSTOM_DEFAULT,

        CustomUnspecified = LOCALE_CUSTOM_UNSPECIFIED,

        CustomUIDefault = LOCALE_CUSTOM_UI_DEFAULT,

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
        IgnoreWidth = NORM_IGNOREWIDTH,
        LinguisticCasing = NORM_LINGUISTIC_CASING,

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

    enum class LocaleSort
    {
        Default = 0x0,

        InvariantMath = 0x1,

        JapaneseXjis = 0x0,
        JapaneseUnicode = 0x1,
        JapaneseRadicalStroke = 0x4,

        ChineseBig5 = 0x0,
        ChinesePRCP = 0x0,
        ChineseUnicode = 0x1,
        ChinesePRC = 0x2,
        ChineseBopomofo = 0x3,
        ChineseRadicalStroke = 0x4,

        KoreanKSC = 0x0,
        KoreanUnicode = 0x1,

        GermanPhoneBook = 0x1,

        HungarianDefault = 0x0,
        HungarianTechnical = 0x1,

        GeorgianTraditional = 0x0,
        GeorgianModern = 0x1,
    };

    static constexpr auto g_LanguageSystemDefault = MakeLanguageID(PrimaryLanguage::Neutral, SubLanguage::SysDefault);
    static constexpr auto g_LanguageUserDefault = MakeLanguageID(PrimaryLanguage::Neutral, SubLanguage::Default);

    enum class LanguageLocale
    {
        SystemDefault = MakeLanguageCID(g_LanguageSystemDefault, LocaleSort::Default),
        UserDefault = MakeLanguageCID(g_LanguageUserDefault, LocaleSort::Default),

        CustomDefault = MakeLanguageCID(MakeLanguageID(PrimaryLanguage::Neutral, SubLanguage::CustomDefault), LocaleSort::Default),

        CustomUnspecified = MakeLanguageCID(MakeLanguageID(PrimaryLanguage::Neutral, SubLanguage::CustomUnspecified), LocaleSort::Default),

        CustomUIDefault = MakeLanguageCID(MakeLanguageID(PrimaryLanguage::Neutral, SubLanguage::UICustomDefault), LocaleSort::Default),

        Neutral = MakeLanguageCID(MakeLanguageID(PrimaryLanguage::Neutral, SubLanguage::Neutral), LocaleSort::Default),

        Invariant = MakeLanguageCID(MakeLanguageID(PrimaryLanguage::Invariant, SubLanguage::Neutral), LocaleSort::Default),
    };

    enum class Compares
    {
        NormIgnoreCase = 0x00000001,
        NormIgnoreNonSpace = 0x00000002,
        NormIgnoreSymbols = 0x00000004,

        LinguisticIgnoreCase = 0x00000010,
        LinguisticIgnoreDiacritic = 0x00000020,

        NormIgnoreKanaType = 0x00010000,
        IgnoreWidth = 0x00020000,
        LinguisticCasing = 0x08000000,

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
