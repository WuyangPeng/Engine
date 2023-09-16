///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:14)

#include "LanguageIdDataTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Data/LanguageIdData.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LanguageIdDataTesting::LanguageIdDataTesting(const OStreamShared& stream)
    : ParentType{ stream },
      primaryLanguages{ PrimaryLanguage::Neutral,
                        PrimaryLanguage::Invariant,
                        PrimaryLanguage::Afrikaans,
                        PrimaryLanguage::Albanian,
                        PrimaryLanguage::Alsatian,
                        PrimaryLanguage::Amharic,
                        PrimaryLanguage::Arabic,
                        PrimaryLanguage::Armenian,
                        PrimaryLanguage::Assamese,
                        PrimaryLanguage::Azeri,
                        PrimaryLanguage::Bashkir,
                        PrimaryLanguage::Basque,
                        PrimaryLanguage::Belarusian,
                        PrimaryLanguage::Bengali,
                        PrimaryLanguage::Breton,
                        PrimaryLanguage::Bosnian,
                        PrimaryLanguage::BosnianNeutral,
                        PrimaryLanguage::Bulgarian,
                        PrimaryLanguage::Catalan,
                        PrimaryLanguage::Chinese,
                        PrimaryLanguage::ChineseSimplified,
                        PrimaryLanguage::ChineseTraditional,
                        PrimaryLanguage::Corsican,
                        PrimaryLanguage::Croatian,
                        PrimaryLanguage::Czech,
                        PrimaryLanguage::Danish,
                        PrimaryLanguage::Dari,
                        PrimaryLanguage::Divehi,
                        PrimaryLanguage::Dutch,
                        PrimaryLanguage::English,
                        PrimaryLanguage::Estonian,
                        PrimaryLanguage::Faeroese,
                        PrimaryLanguage::Farsi,
                        PrimaryLanguage::Filipino,
                        PrimaryLanguage::Finnish,
                        PrimaryLanguage::French,
                        PrimaryLanguage::Frisian,
                        PrimaryLanguage::Galician,
                        PrimaryLanguage::Georgian,
                        PrimaryLanguage::German,
                        PrimaryLanguage::Greek,
                        PrimaryLanguage::Greenlandic,
                        PrimaryLanguage::Gujarati,
                        PrimaryLanguage::Hausa,
                        PrimaryLanguage::Hebrew,
                        PrimaryLanguage::Hindi,
                        PrimaryLanguage::Hungarian,
                        PrimaryLanguage::Icelandic,
                        PrimaryLanguage::Igbo,
                        PrimaryLanguage::Indonesian,
                        PrimaryLanguage::Inuktitut,
                        PrimaryLanguage::Irish,
                        PrimaryLanguage::Italian,
                        PrimaryLanguage::Japanese,
                        PrimaryLanguage::Kannada,
                        PrimaryLanguage::Kashmiri,
                        PrimaryLanguage::Kazak,
                        PrimaryLanguage::Khmer,
                        PrimaryLanguage::Kiche,
                        PrimaryLanguage::Kinyarwanda,
                        PrimaryLanguage::Konkani,
                        PrimaryLanguage::Korean,
                        PrimaryLanguage::Kyrgyz,
                        PrimaryLanguage::Lao,
                        PrimaryLanguage::Latvian,
                        PrimaryLanguage::Lithuanian,
                        PrimaryLanguage::LowerSorbian,
                        PrimaryLanguage::Luxembourgish,
                        PrimaryLanguage::Macedonian,
                        PrimaryLanguage::Malay,
                        PrimaryLanguage::Malayalam,
                        PrimaryLanguage::Maltese,
                        PrimaryLanguage::Manipuri,
                        PrimaryLanguage::Maori,
                        PrimaryLanguage::Mapudungun,
                        PrimaryLanguage::Marathi,
                        PrimaryLanguage::Mohawk,
                        PrimaryLanguage::Mongolian,
                        PrimaryLanguage::Nepali,
                        PrimaryLanguage::Norwegian,
                        PrimaryLanguage::Occitan,
                        PrimaryLanguage::Oriya,
                        PrimaryLanguage::Pashto,
                        PrimaryLanguage::Persian,
                        PrimaryLanguage::Polish,
                        PrimaryLanguage::Portuguese,
                        PrimaryLanguage::Punjabi,
                        PrimaryLanguage::Quechua,
                        PrimaryLanguage::Romanian,
                        PrimaryLanguage::Romansh,
                        PrimaryLanguage::Russian,
                        PrimaryLanguage::Sami,
                        PrimaryLanguage::Sanskrit,
                        PrimaryLanguage::ScottishGaelic,
                        PrimaryLanguage::Serbian,
                        PrimaryLanguage::SerbianNeutral,
                        PrimaryLanguage::Sindhi,
                        PrimaryLanguage::Sinhalese,
                        PrimaryLanguage::Slovak,
                        PrimaryLanguage::Slovenian,
                        PrimaryLanguage::Sotho,
                        PrimaryLanguage::Spanish,
                        PrimaryLanguage::Swahili,
                        PrimaryLanguage::Swedish,
                        PrimaryLanguage::Syriac,
                        PrimaryLanguage::Tajik,
                        PrimaryLanguage::Tamazight,
                        PrimaryLanguage::Tamil,
                        PrimaryLanguage::Tatar,
                        PrimaryLanguage::Telugu,
                        PrimaryLanguage::Thai,
                        PrimaryLanguage::Tibetan,
                        PrimaryLanguage::Tigrigna,
                        PrimaryLanguage::Tswana,
                        PrimaryLanguage::Turkish,
                        PrimaryLanguage::Turkmen,
                        PrimaryLanguage::Uighur,
                        PrimaryLanguage::Ukrainian,
                        PrimaryLanguage::UpperSorbian,
                        PrimaryLanguage::Urdu,
                        PrimaryLanguage::Uzbek,
                        PrimaryLanguage::Vietnamese,
                        PrimaryLanguage::Welsh,
                        PrimaryLanguage::Wolof,
                        PrimaryLanguage::Xhosa,
                        PrimaryLanguage::Yakut,
                        PrimaryLanguage::Yi,
                        PrimaryLanguage::Yoruba,
                        PrimaryLanguage::Zulu },
      subLanguages{ SubLanguage::Neutral,
                    SubLanguage::Spanish,
                    SubLanguage::SpanishMexico,
                    SubLanguage::SpanishModern,
                    SubLanguage::SpanishGuatemala,
                    SubLanguage::SpanishCostaRica,
                    SubLanguage::SpanishPanama,
                    SubLanguage::SpanishDominicanRepublic,
                    SubLanguage::SpanishVenezuela,
                    SubLanguage::SpanishColombia,
                    SubLanguage::SpanishPeru,
                    SubLanguage::SpanishArgentina,
                    SubLanguage::SpanishEcuador,
                    SubLanguage::SpanishChile,
                    SubLanguage::SpanishUruguay,
                    SubLanguage::SpanishParaguay,
                    SubLanguage::SpanishBolivia,
                    SubLanguage::SpanishElSalvador,
                    SubLanguage::SpanishHonduras,
                    SubLanguage::SpanishNicaragua,
                    SubLanguage::SpanishPuertoRico,
                    SubLanguage::SpanishUS },
      maxSize{ std::max(primaryLanguages.size(), subLanguages.size()) },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LanguageIdDataTesting)

void System::LanguageIdDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LanguageIdDataTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultFlagTest);
}

bool System::LanguageIdDataTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(primaryLanguages, randomEngine);
    std::ranges::shuffle(subLanguages, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(FlagsTest);

    return true;
}

void System::LanguageIdDataTesting::FlagsTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoFlagsTest, index);
    }
}

void System::LanguageIdDataTesting::DoFlagsTest(size_t index)
{
    const auto primaryLanguage = primaryLanguages.at(index % primaryLanguages.size());
    const auto subLanguage = subLanguages.at(index % subLanguages.size());

    const LanguageIdData languageIdData{ primaryLanguage, subLanguage };

    ASSERT_ENUM_EQUAL(languageIdData.GetPrimaryLanguage(), primaryLanguage);
    ASSERT_ENUM_EQUAL(languageIdData.GetSubLanguage(), subLanguage);

    const auto languageID = MakeLanguageId(EnumCastUnderlying<uint16_t>(primaryLanguage), EnumCastUnderlying<uint16_t>(subLanguage));

    ASSERT_EQUAL(languageIdData.GetLanguageId(), languageID);
}

void System::LanguageIdDataTesting::DefaultFlagTest() noexcept
{
    constexpr LanguageIdData languageIdData{};

    static_assert(languageIdData.GetPrimaryLanguage() == PrimaryLanguage::Neutral);
    static_assert(languageIdData.GetSubLanguage() == SubLanguage::Neutral);
}
