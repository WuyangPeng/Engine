///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/10 20:03)

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
      typeFlags{ predefinedResourceTypesCursor,
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
                 predefinedResourceTypesDlgInclude },
      nameFlags{ CreateNameFlags() },
      maxSize{ CoreTools::MaxElement<size_t>({ primaryLanguageFlags.size(), subLanguageFlags.size(), typeFlags.size(), nameFlags.size() }) },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

System::EnumResourceDataTesting::NameFlagsContainer System::EnumResourceDataTesting::CreateNameFlags()
{
    NameFlagsContainer result{};

    constexpr auto nameBeginIndex = 100;
    constexpr auto nameEndIndex = 200;

    for (auto index = nameBeginIndex; index < nameEndIndex; ++index)
    {
        result.emplace_back(MakeIntreSource(boost::numeric_cast<uint16_t>(index)));
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
    shuffle(primaryLanguageFlags.begin(), primaryLanguageFlags.end(), randomEngine);
    shuffle(subLanguageFlags.begin(), subLanguageFlags.end(), randomEngine);
    shuffle(typeFlags.begin(), typeFlags.end(), randomEngine);
    shuffle(nameFlags.begin(), nameFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(DataTest);

    return true;
}

void System::EnumResourceDataTesting::DataTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto primaryLanguageFlag = primaryLanguageFlags.at(index % primaryLanguageFlags.size());
        auto subLanguageFlag = subLanguageFlags.at(index % subLanguageFlags.size());

        const LanguageIDData languageIDData{ primaryLanguageFlag, subLanguageFlag };

        const DynamicLinkCharType* type{ typeFlags.at(index % typeFlags.size()) };
        const DynamicLinkCharType* name{ nameFlags.at(index % nameFlags.size()) };

        const EnumResourceData enumResourceData{ type, name, languageIDData.GetLanguageID() };

        ASSERT_TRUE(type == enumResourceData.GetType());
        ASSERT_TRUE(name == enumResourceData.GetName());
        ASSERT_EQUAL(languageIDData.GetLanguageID(), enumResourceData.GetLanguage().GetLanguageID());
    }
}
