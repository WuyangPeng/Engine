// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:16)

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
		PreComposed = MB_PRECOMPOSED,
		Complsite = MB_COMPOSITE,
		UseGlyphChars = MB_USEGLYPHCHARS,
		ErrInvalidChars = MB_ERR_INVALID_CHARS,
	};

	enum class WideChar
	{
		NoFlags = 0,
		CompositeCheck = WC_COMPOSITECHECK,
		DiscardNS = WC_DISCARDNS,
		SepChars = WC_SEPCHARS,
		DefaultChar = WC_DEFAULTCHAR,
		ErrInvalidChars = WC_ERR_INVALID_CHARS,
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

	enum class LocaleIndependentMapping
	{
		FoldCzone = MAP_FOLDCZONE,
		PreComposed = MAP_PRECOMPOSED,
		Composite = MAP_COMPOSITE,
		FoldDigits = MAP_FOLDDIGITS,
		ExpandLigatures = MAP_EXPAND_LIGATURES,
	};

	enum class CharacterType
	{
		CharacterType1 = CT_CTYPE1,
		CharacterType2 = CT_CTYPE2,
		CharacterType3 = CT_CTYPE3,
	};

	enum class CharacterTypeC1Bits
	{
		Upper = C1_UPPER,
		Lower = C1_LOWER,
		Digit = C1_DIGIT,
		Space = C1_SPACE,
		Punct = C1_PUNCT,
		Cntrl = C1_CNTRL,
		Blank = C1_BLANK,
		Xdigit = C1_XDIGIT,
		Alpha = C1_ALPHA,
		Defined = C1_DEFINED,
	};

	enum class CharacterTypeC2Bits
	{
		LeftToRight = C2_LEFTTORIGHT,
		RightToLeft = C2_RIGHTTOLEFT,

		EuropeNumber = C2_EUROPENUMBER,
		EuropeSeparator = C2_EUROPESEPARATOR,
		EuropeTerminator = C2_EUROPETERMINATOR,
		ArabicNumber = C2_ARABICNUMBER,
		CommonSeparator = C2_COMMONSEPARATOR,

		BlockSepatator = C2_BLOCKSEPARATOR,
		SegmentSeparator = C2_SEGMENTSEPARATOR,
		WhiteSpace = C2_WHITESPACE,
		OtherNeutral = C2_OTHERNEUTRAL,

		NotApplicable = C2_NOTAPPLICABLE,
	};

	enum class CharacterTypeC3Bits
	{
		NonSpacing = C3_NONSPACING,
		Diactitic = C3_DIACRITIC,
		VowelMark = C3_VOWELMARK,
		Symbol = C3_SYMBOL,

		Katakana = C3_KATAKANA,
		Hiragana = C3_HIRAGANA,
		HalfWidth = C3_HALFWIDTH,
		FullWidth = C3_FULLWIDTH,
		IdeoGraph = C3_IDEOGRAPH,
		Kashida = C3_KASHIDA,
		Lexical = C3_LEXICAL,
		HighSurrogate = C3_HIGHSURROGATE,
		LowSurrogate = C3_LOWSURROGATE,

		Alpha = C3_ALPHA,

		NotApplicable = C3_NOTAPPLICABLE,
	};

#else // !SYSTEM_PLATFORM_WIN32

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
		SystemDefault = MakeLCID(g_LanguageSystemDefault, LocaleSort::Default),
		UserDefault = MakeLCID(g_LanguageUserDefault, LocaleSort::Default),

		CustomDefault = MakeLCID(MakeLanguageID(PrimaryLanguage::Neutral, SubLanguage::CustomDefault), LocaleSort::Default),

		CustomUnspecified = MakeLCID(MakeLanguageID(PrimaryLanguage::Neutral, SubLanguage::CustomUnspecified), LocaleSort::Default),

		CustomUIDefault = MakeLCID(MakeLanguageID(PrimaryLanguage::Neutral, SubLanguage::UICustomDefault), LocaleSort::Default),

		Neutral = MakeLCID(MakeLanguageID(PrimaryLanguage::Neutral, SubLanguage::Neutral), LocaleSort::Default),

		Invariant = MakeLCID(MakeLanguageID(PrimaryLanguage::Invariant, SubLanguage::Neutral), LocaleSort::Default),
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

	enum class LocaleIndependentMapping
	{
		FoldCzone = 0x00000010,
		PreComposed = 0x00000020,
		Composite = 0x00000040,
		FoldDigits = 0x00000080,
		ExpandLigatures = 0x00002000,
	};

	enum class CharacterType
	{
		CharacterType1 = 0x00000001,
		CharacterType2 = 0x00000002,
		CharacterType3 = 0x00000004,
	};

	enum class CharacterTypeC1Bits
	{
		Upper = 0x0001,
		Lower = 0x0002,
		Digit = 0x0004,
		Space = 0x0008,
		Punct = 0x0010,
		Cntrl = 0x0020,
		Blank = 0x0040,
		Xdigit = 0x0080,
		Alpha = 0x0100,
		Defined = 0x0200,
	};

	enum class CharacterTypeC2Bits
	{
		LeftToRight = 0x0001,
		RightToLeft = 0x0002,

		EuropeNumber = 0x0003,
		EuropeSeparator = 0x0004,
		EuropeTerminator = 0x0005,
		ArabicNumber = 0x0006,
		CommonSeparator = 0x0007,

		BlockSepatator = 0x0008,
		SegmentSeparator = 0x0009,
		WhiteSpace = 0x000A,
		OtherNeutral = 0x000B,

		NotApplicable = 0x0000,
	};

	enum class CharacterTypeC3Bits
	{
		NonSpacing = 0x0001,
		Diactitic = 0x0002,
		VowelMark = 0x0004,
		Symbol = 0x0008,

		Katakana = 0x0010,
		Hiragana = 0x0020,
		HalfWidth = 0x0040,
		FullWidth = 0x0080,
		IdeoGraph = 0x0100,
		Kashida = 0x0200,
		Lexical = 0x0400,
		HighSurrogate = 0x0800,
		LowSurrogate = 0x1000,

		Alpha = 0x8000,

		NotApplicable = 0x0000,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_CHARACTER_STRING_STRING_CONVERSION_FLAGS_H
