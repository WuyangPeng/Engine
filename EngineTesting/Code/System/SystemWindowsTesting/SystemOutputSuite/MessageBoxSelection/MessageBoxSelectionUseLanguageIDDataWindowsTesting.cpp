///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/30 0:15)

#include "MessageBoxSelectionUseLanguageIDDataWindowsTesting.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxSelectionUseLanguageIDDataWindowsTesting::MessageBoxSelectionUseLanguageIDDataWindowsTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream },
      hwnd{ hwnd },
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
      maxSize{ std::max(primaryLanguageFlags.size(), subLanguageFlags.size()) },
      randomEngine{ GetEngineRandomSeed() }
{
    SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxSelectionUseLanguageIDDataWindowsTesting)

void System::MessageBoxSelectionUseLanguageIDDataWindowsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxSelectionUseLanguageIDDataWindowsTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::MessageBoxSelectionUseLanguageIDDataWindowsTesting::RandomShuffleFlags()
{
    shuffle(primaryLanguageFlags.begin(), primaryLanguageFlags.end(), randomEngine);
    shuffle(subLanguageFlags.begin(), subLanguageFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(MessageBoxTest);

    return true;
}

void System::MessageBoxSelectionUseLanguageIDDataWindowsTesting::MessageBoxTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoMessageBoxTest, index);
    }
}

void System::MessageBoxSelectionUseLanguageIDDataWindowsTesting::DoMessageBoxTest(size_t index)
{
    const auto primaryLanguageFlag = primaryLanguageFlags.at(index % primaryLanguageFlags.size());
    const auto subLanguageFlag = subLanguageFlags.at(index % subLanguageFlags.size());

    const LanguageIDData languageIDData{ primaryLanguageFlag, subLanguageFlag };

    constexpr MessageBoxFlagsData flagsData{ MessageBoxType::YesNoCancel,
                                             MessageBoxIcon::Error,
                                             MessageBoxDefault::Button1,
                                             MessageBoxMode::ApplModal,
                                             MessageBoxMisc::TopMost };

    const auto flag = MessageBoxSelection(hwnd,
                                          SYSTEM_TEXT("这个对话框只是测试语言标志，请点击任意按钮。"),
                                          SYSTEM_TEXT("测试"),
                                          flagsData,
                                          languageIDData);

    ASSERT_ENUM_UNEQUAL(DialogBoxCommand::IDCreationFailed, flag);
}
