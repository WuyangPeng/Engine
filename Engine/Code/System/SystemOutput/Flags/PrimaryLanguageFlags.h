/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:27)

#ifndef SYSTEM_SYSTEM_OUTPUT_PRIMARY_LANGUAGE_FLAGS_H
#define SYSTEM_SYSTEM_OUTPUT_PRIMARY_LANGUAGE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    /// 不建议使用语言ID概念，请改用语言环境名称，例如：“en”，而不是像0x09这样的LANG_ID。
    enum class PrimaryLanguage
    {
        Neutral = LANG_NEUTRAL,
        Invariant = LANG_INVARIANT,
        Afrikaans = LANG_AFRIKAANS,
        Albanian = LANG_ALBANIAN,
        Alsatian = LANG_ALSATIAN,
        Amharic = LANG_AMHARIC,
        Arabic = LANG_ARABIC,
        Armenian = LANG_ARMENIAN,
        Assamese = LANG_ASSAMESE,
        Azeri = LANG_AZERI,
        Bashkir = LANG_BASHKIR,
        Basque = LANG_BASQUE,
        Belarusian = LANG_BELARUSIAN,
        Bengali = LANG_BENGALI,
        Breton = LANG_BRETON,
        Bosnian = LANG_BOSNIAN,  // 与Bosnian*子语言ID一起使用。
        BosnianNeutral = LANG_BOSNIAN_NEUTRAL,  // 与ConvertDefaultLocale函数一起使用。
        Bulgarian = LANG_BULGARIAN,
        Catalan = LANG_CATALAN,
        Chinese = LANG_CHINESE,  // 与Chinese*子语言ID一起使用。
        ChineseSimplified = LANG_CHINESE_SIMPLIFIED,  // 与ConvertDefaultLocale函数一起使用。
        ChineseTraditional = LANG_CHINESE_TRADITIONAL,  // 与ConvertDefaultLocale函数一起使用。
        Corsican = LANG_CORSICAN,
        Croatian = LANG_CROATIAN,
        Czech = LANG_CZECH,
        Danish = LANG_DANISH,
        Dari = LANG_DARI,
        Divehi = LANG_DIVEHI,
        Dutch = LANG_DUTCH,
        English = LANG_ENGLISH,
        Estonian = LANG_ESTONIAN,
        Faeroese = LANG_FAEROESE,
        Farsi = LANG_FARSI,  // 已弃用：改用Persian。
        Filipino = LANG_FILIPINO,
        Finnish = LANG_FINNISH,
        French = LANG_FRENCH,
        Frisian = LANG_FRISIAN,
        Galician = LANG_GALICIAN,
        Georgian = LANG_GEORGIAN,
        German = LANG_GERMAN,
        Greek = LANG_GREEK,
        Greenlandic = LANG_GREENLANDIC,
        Gujarati = LANG_GUJARATI,
        Hausa = LANG_HAUSA,
        Hebrew = LANG_HEBREW,
        Hindi = LANG_HINDI,
        Hungarian = LANG_HUNGARIAN,
        Icelandic = LANG_ICELANDIC,
        Igbo = LANG_IGBO,
        Indonesian = LANG_INDONESIAN,
        Inuktitut = LANG_INUKTITUT,
        Irish = LANG_IRISH,  // 与IrishIreland*子语言ID一起使用。
        Italian = LANG_ITALIAN,
        Japanese = LANG_JAPANESE,
        Kannada = LANG_KANNADA,
        Kashmiri = LANG_KASHMIRI,
        Kazak = LANG_KAZAK,
        Khmer = LANG_KHMER,
        Kiche = LANG_KICHE,
        Kinyarwanda = LANG_KINYARWANDA,
        Konkani = LANG_KONKANI,
        Korean = LANG_KOREAN,
        Kyrgyz = LANG_KYRGYZ,
        Lao = LANG_LAO,
        Latvian = LANG_LATVIAN,
        Lithuanian = LANG_LITHUANIAN,
        LowerSorbian = LANG_LOWER_SORBIAN,
        Luxembourgish = LANG_LUXEMBOURGISH,
        Macedonian = LANG_MACEDONIAN,  // 前南斯拉夫的马其顿共和国
        Malay = LANG_MALAY,
        Malayalam = LANG_MALAYALAM,
        Maltese = LANG_MALTESE,
        Manipuri = LANG_MANIPURI,
        Maori = LANG_MAORI,
        Mapudungun = LANG_MAPUDUNGUN,
        Marathi = LANG_MARATHI,
        Mohawk = LANG_MOHAWK,
        Mongolian = LANG_MONGOLIAN,
        Nepali = LANG_NEPALI,
        Norwegian = LANG_NORWEGIAN,
        Occitan = LANG_OCCITAN,
        Oriya = LANG_ORIYA,
        Pashto = LANG_PASHTO,
        Persian = LANG_PERSIAN,
        Polish = LANG_POLISH,
        Portuguese = LANG_PORTUGUESE,
        Punjabi = LANG_PUNJABI,
        Quechua = LANG_QUECHUA,
        Romanian = LANG_ROMANIAN,
        Romansh = LANG_ROMANSH,
        Russian = LANG_RUSSIAN,
        Sami = LANG_SAMI,
        Sanskrit = LANG_SANSKRIT,
        ScottishGaelic = LANG_SCOTTISH_GAELIC,
        Serbian = LANG_SERBIAN,  // 与Serbian*子语言ID一起使用。
        SerbianNeutral = LANG_SERBIAN_NEUTRAL,  // 与ConvertDefaultLocale函数一起使用。
        Sindhi = LANG_SINDHI,
        Sinhalese = LANG_SINHALESE,
        Slovak = LANG_SLOVAK,
        Slovenian = LANG_SLOVENIAN,
        Sotho = LANG_SOTHO,
        Spanish = LANG_SPANISH,
        Swahili = LANG_SWAHILI,
        Swedish = LANG_SWEDISH,
        Syriac = LANG_SYRIAC,
        Tajik = LANG_TAJIK,
        Tamazight = LANG_TAMAZIGHT,
        Tamil = LANG_TAMIL,
        Tatar = LANG_TATAR,
        Telugu = LANG_TELUGU,
        Thai = LANG_THAI,
        Tibetan = LANG_TIBETAN,
        Tigrigna = LANG_TIGRIGNA,
        Tswana = LANG_TSWANA,
        Turkish = LANG_TURKISH,
        Turkmen = LANG_TURKMEN,
        Uighur = LANG_UIGHUR,
        Ukrainian = LANG_UKRAINIAN,
        UpperSorbian = LANG_UPPER_SORBIAN,
        Urdu = LANG_URDU,
        Uzbek = LANG_UZBEK,
        Vietnamese = LANG_VIETNAMESE,
        Welsh = LANG_WELSH,
        Wolof = LANG_WOLOF,
        Xhosa = LANG_XHOSA,
        Yakut = LANG_YAKUT,
        Yi = LANG_YI,
        Yoruba = LANG_YORUBA,
        Zulu = LANG_ZULU,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class PrimaryLanguage
    {
        Neutral = 0x00,
        Invariant = 0x7f,
        Afrikaans = 0x36,
        Albanian = 0x1c,
        Alsatian = 0x84,
        Amharic = 0x5e,
        Arabic = 0x01,
        Armenian = 0x2b,
        Assamese = 0x4d,
        Azeri = 0x2c,
        Bashkir = 0x6d,
        Basque = 0x2d,
        Belarusian = 0x23,
        Bengali = 0x45,
        Breton = 0x7e,
        Bosnian = 0x1a,
        BosnianNeutral = 0x781a,
        Bulgarian = 0x02,
        Catalan = 0x03,
        Chinese = 0x04,
        ChineseSimplified = 0x04,
        ChineseTraditional = 0x7c04,
        Corsican = 0x83,
        Croatian = 0x1a,
        Czech = 0x05,
        Danish = 0x06,
        Dari = 0x8c,
        Divehi = 0x65,
        Dutch = 0x13,
        English = 0x09,
        Estonian = 0x25,
        Faeroese = 0x38,
        Farsi = 0x29,
        Filipino = 0x64,
        Finnish = 0x0b,
        French = 0x0c,
        Frisian = 0x62,
        Galician = 0x56,
        Georgian = 0x37,
        German = 0x07,
        Greek = 0x08,
        Greenlandic = 0x6f,
        Gujarati = 0x47,
        Hausa = 0x68,
        Hebrew = 0x0d,
        Hindi = 0x39,
        Hungarian = 0x0e,
        Icelandic = 0x0f,
        Igbo = 0x70,
        Indonesian = 0x21,
        Inuktitut = 0x5d,
        Irish = 0x3c,
        Italian = 0x10,
        Japanese = 0x11,
        Kannada = 0x4b,
        Kashmiri = 0x60,
        Kazak = 0x3f,
        Khmer = 0x53,
        Kiche = 0x86,
        Kinyarwanda = 0x87,
        Konkani = 0x57,
        Korean = 0x12,
        Kyrgyz = 0x40,
        Lao = 0x54,
        Latvian = 0x26,
        Lithuanian = 0x27,
        LowerSorbian = 0x2e,
        Luxembourgish = 0x6e,
        Macedonian = 0x2f,
        Malay = 0x3e,
        Malayalam = 0x4c,
        Maltese = 0x3a,
        Manipuri = 0x58,
        Maori = 0x81,
        Mapudungun = 0x7a,
        Marathi = 0x4e,
        Mohawk = 0x7c,
        Mongolian = 0x50,
        Nepali = 0x61,
        Norwegian = 0x14,
        Occitan = 0x82,
        Oriya = 0x48,
        Pashto = 0x63,
        Persian = 0x29,
        Polish = 0x15,
        Portuguese = 0x16,
        Punjabi = 0x46,
        Quechua = 0x6b,
        Romanian = 0x18,
        Romansh = 0x17,
        Russian = 0x19,
        Sami = 0x3b,
        Sanskrit = 0x4f,
        ScottishGaelic = 0x91,
        Serbian = 0x1a,
        SerbianNeutral = 0x7c1a,
        Sindhi = 0x59,
        Sinhalese = 0x5b,
        Slovak = 0x1b,
        Slovenian = 0x24,
        Sotho = 0x6c,
        Spanish = 0x0a,
        Swahili = 0x41,
        Swedish = 0x1d,
        Syriac = 0x5a,
        Tajik = 0x28,
        Tamazight = 0x5f,
        Tamil = 0x49,
        Tatar = 0x44,
        Telugu = 0x4a,
        Thai = 0x1e,
        Tibetan = 0x51,
        Tigrigna = 0x73,
        Tswana = 0x32,
        Turkish = 0x1f,
        Turkmen = 0x42,
        Uighur = 0x80,
        Ukrainian = 0x22,
        UpperSorbian = 0x2e,
        Urdu = 0x20,
        Uzbek = 0x43,
        Vietnamese = 0x2a,
        Welsh = 0x52,
        Wolof = 0x88,
        Xhosa = 0x34,
        Yakut = 0x85,
        Yi = 0x78,
        Yoruba = 0x6a,
        Zulu = 0x35,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SYSTEM_OUTPUT_PRIMARY_LANGUAGE_FLAGS_H