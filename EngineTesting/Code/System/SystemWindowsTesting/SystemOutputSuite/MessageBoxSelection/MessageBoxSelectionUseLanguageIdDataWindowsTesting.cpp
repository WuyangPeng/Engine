/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 12:28)

#include "MessageBoxSelectionUseLanguageIdDataWindowsTesting.h"
#include "System/SystemOutput/Data/LanguageIdData.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxSelectionUseLanguageIdDataWindowsTesting::MessageBoxSelectionUseLanguageIdDataWindowsTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream },
      hWnd{ hWnd },
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
                        SubLanguage::SpanishUs },
      maxSize{ std::max(primaryLanguageFlags.size(), subLanguageFlags.size()) },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxSelectionUseLanguageIdDataWindowsTesting)

void System::MessageBoxSelectionUseLanguageIdDataWindowsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxSelectionUseLanguageIdDataWindowsTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::MessageBoxSelectionUseLanguageIdDataWindowsTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(primaryLanguageFlags, randomEngine);
    std::ranges::shuffle(subLanguageFlags, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(MessageBoxTest);

    return true;
}

void System::MessageBoxSelectionUseLanguageIdDataWindowsTesting::MessageBoxTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoMessageBoxTest, index);
    }
}

void System::MessageBoxSelectionUseLanguageIdDataWindowsTesting::DoMessageBoxTest(size_t index)
{
    const auto primaryLanguageFlag = primaryLanguageFlags.at(index % primaryLanguageFlags.size());
    const auto subLanguageFlag = subLanguageFlags.at(index % subLanguageFlags.size());

    const LanguageIdData languageIdData{ primaryLanguageFlag, subLanguageFlag };

    constexpr MessageBoxFlagsData flagsData{ MessageBoxType::YesNoCancel,
                                             MessageBoxIcon::Error,
                                             MessageBoxDefault::Button1,
                                             MessageBoxMode::ApplicationModal,
                                             MessageBoxMisc::TopMost };

    const auto flag = MessageBoxSelection(hWnd,
                                          SYSTEM_TEXT("这个对话框只是测试语言标志，请点击任意按钮。"),
                                          SYSTEM_TEXT("测试"),
                                          flagsData,
                                          languageIdData);

    ASSERT_UNEQUAL(DialogBoxCommand::IdCreationFailed, flag);
}
