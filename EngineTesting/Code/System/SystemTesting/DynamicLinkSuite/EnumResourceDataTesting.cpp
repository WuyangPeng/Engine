/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:34)

#include "EnumResourceDataTesting.h"
#include "System/DynamicLink/Data/EnumResourceData.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumResourceDataTesting::EnumResourceDataTesting(const OStreamShared& stream)
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
                    SubLanguage::SpanishUs },
      types{ predefinedResourceTypesCursor,
             predefinedResourceTypesBitmap,
             predefinedResourceTypesIcon,
             predefinedResourceTypesMenu,
             predefinedResourceTypesDialog,
             predefinedResourceTypesString,
             predefinedResourceTypesFontDir,
             predefinedResourceTypesFont,
             predefinedResourceTypesAccelerator,
             predefinedResourceTypesRcData,
             predefinedResourceTypesMessageTable,
             predefinedResourceTypesGroupCursor,
             predefinedResourceTypesGroupIcon,
             predefinedResourceTypesVersion,
             predefinedResourceTypesDlgInclude,
             predefinedResourceTypesPlugPlay,
             predefinedResourceTypesVxd,
             predefinedResourceTypesAniCursor,
             predefinedResourceTypesAniIcon,
             predefinedResourceTypesHtml,
             predefinedResourceTypesManifest,
             createProcessManifestResourceId,
             isolationAwareManifestResourceId,
             isolationAwareNoStaticImportManifestResourceId,
             minimumReservedManifestResourceId,
             maximumReservedManifestResourceId },
      names{ CreateNameFlags() },
      maxSize{ CoreTools::MaxElement({ primaryLanguages.size(), subLanguages.size(), types.size(), names.size() }) },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

System::EnumResourceDataTesting::NameContainer System::EnumResourceDataTesting::CreateNameFlags()
{
    NameContainer result{};

    constexpr auto nameBeginIndex = 100;
    constexpr auto nameEndIndex = 200;

    for (auto index = nameBeginIndex; index < nameEndIndex; ++index)
    {
        result.emplace_back(MakeIntResource(boost::numeric_cast<uint16_t>(index)));
    }

    return result;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumResourceDataTesting)

void System::EnumResourceDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumResourceDataTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::EnumResourceDataTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(primaryLanguages, randomEngine);
    std::ranges::shuffle(subLanguages, randomEngine);
    std::ranges::shuffle(types, randomEngine);
    std::ranges::shuffle(names, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(EnumResourceDataTest);

    return true;
}

void System::EnumResourceDataTesting::EnumResourceDataTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoEnumResourceDataTest, index);
    }
}

void System::EnumResourceDataTesting::DoEnumResourceDataTest(size_t index)
{
    const auto primaryLanguage = primaryLanguages.at(index % primaryLanguages.size());
    const auto subLanguage = subLanguages.at(index % subLanguages.size());

    const LanguageIdData languageIdData{ primaryLanguage, subLanguage };

    const auto* type = types.at(index % types.size());
    const auto* name = names.at(index % names.size());

    const EnumResourceData enumResourceData{ type, name, languageIdData.GetLanguageId() };

    ASSERT_TRUE(type == enumResourceData.GetType());
    ASSERT_TRUE(name == enumResourceData.GetName());
    ASSERT_EQUAL(languageIdData.GetLanguageId(), enumResourceData.GetLanguage().GetLanguageId());
}
