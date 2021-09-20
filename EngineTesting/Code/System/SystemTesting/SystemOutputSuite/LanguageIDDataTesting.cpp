///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/23 11:01)

#include "LanguageIDDataTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::max;

System::LanguageIDDataTesting::LanguageIDDataTesting(const OStreamShared& stream)
    : ParentType{ stream },
      primaryLanguageFlags{ PrimaryLanguage::Neutral,
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
      subLanguageFlags{ SubLanguage::Neutral,
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
      maxSize{ max(primaryLanguageFlags.size(), subLanguageFlags.size()) },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LanguageIDDataTesting)

void System::LanguageIDDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LanguageIDDataTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultFlagTest);
}

bool System::LanguageIDDataTesting::RandomShuffleFlags()
{
    shuffle(primaryLanguageFlags.begin(), primaryLanguageFlags.end(), randomEngine);
    shuffle(subLanguageFlags.begin(), subLanguageFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(FlagsTest);

    return true;
}

void System::LanguageIDDataTesting::FlagsTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        const auto primaryLanguageFlag = primaryLanguageFlags.at(index % primaryLanguageFlags.size());
        const auto subLanguageFlag = subLanguageFlags.at(index % subLanguageFlags.size());

        const LanguageIDData languageIDData{ primaryLanguageFlag, subLanguageFlag };

        ASSERT_ENUM_EQUAL(languageIDData.GetPrimaryLanguage(), primaryLanguageFlag);
        ASSERT_ENUM_EQUAL(languageIDData.GetSubLanguage(), subLanguageFlag);

        const auto languageID = MakeLanguageID(EnumCastUnderlying<uint16_t>(primaryLanguageFlag), EnumCastUnderlying<uint16_t>(subLanguageFlag));

        ASSERT_EQUAL(languageIDData.GetLanguageID(), languageID);
    }
}

void System::LanguageIDDataTesting::DefaultFlagTest() noexcept
{
    constexpr LanguageIDData languageIDData{};

    static_assert(languageIDData.GetPrimaryLanguage() == PrimaryLanguage::Neutral);
    static_assert(languageIDData.GetSubLanguage() == SubLanguage::Neutral);
}
