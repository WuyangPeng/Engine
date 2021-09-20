///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/22 11:27)

#ifndef SYSTEM_SYSTEM_OUTPUT_SUB_LANGUAGE_FLAGS_H
#define SYSTEM_SYSTEM_OUTPUT_SUB_LANGUAGE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    // ���޳�ʹ��������ID�����������Ի������ƣ����硰en-US��������������0x0409��LCID��
    enum class SubLanguage
    {
        Neutral = SUBLANG_NEUTRAL,  // ��������
        Default = SUBLANG_DEFAULT,  // �û�Ĭ��
        SysDefault = SUBLANG_SYS_DEFAULT,  // ϵͳĬ��
        CustomDefault = SUBLANG_CUSTOM_DEFAULT,  // Ĭ���Զ�������/��������
        CustomUnspecified = SUBLANG_CUSTOM_UNSPECIFIED,  // �Զ�������/��������
        UICustomDefault = SUBLANG_UI_CUSTOM_DEFAULT,  // Ĭ���Զ���MUI����/��������
        AfrikaansSouthAfrica = SUBLANG_AFRIKAANS_SOUTH_AFRICA,  // �ϷǺ����� ���Ϸǣ�
        AlbanianAlbania = SUBLANG_ALBANIAN_ALBANIA,  // ��������������������ǣ�
        AlbanianFrance = SUBLANG_ALSATIAN_FRANCE,  // ������˹��������
        AmharicEthiopia = SUBLANG_AMHARIC_ETHIOPIA,  // ��ķ��������������ǣ�
        ArabicSaudiArabia = SUBLANG_ARABIC_SAUDI_ARABIA,  // �������ɳ�ذ�������
        ArabicIraq = SUBLANG_ARABIC_IRAQ,  // ������������ˣ�
        ArabicEgypt = SUBLANG_ARABIC_EGYPT,  // �������������
        ArabicLibya = SUBLANG_ARABIC_LIBYA,  // ������������ǣ�
        ArabicAlgeria = SUBLANG_ARABIC_ALGERIA,  // ����������������ǣ�
        ArabicMorocco = SUBLANG_ARABIC_MOROCCO,  // �������Ħ��磩
        ArabicTunisia = SUBLANG_ARABIC_TUNISIA,  // �������ͻ��˹��
        ArabicOman = SUBLANG_ARABIC_OMAN,  // �������������
        ArabicYemen = SUBLANG_ARABIC_YEMEN,  // �������Ҳ�ţ�
        ArabicSyria = SUBLANG_ARABIC_SYRIA,  // ������������ǣ�
        ArabicJordan = SUBLANG_ARABIC_JORDAN,  // �������Լ����
        ArabicLebanon = SUBLANG_ARABIC_LEBANON,  // �����������ۣ�
        ArabicKuwait = SUBLANG_ARABIC_KUWAIT,  // ������������أ�
        ArabicUae = SUBLANG_ARABIC_UAE,  // ���������������
        ArabicBahrain = SUBLANG_ARABIC_BAHRAIN,  // ����������֣�
        ArabicQatar = SUBLANG_ARABIC_QATAR,  // ���������������
        ArmenianArmenia = SUBLANG_ARMENIAN_ARMENIA,  // ����������������ǣ�
        AssameseIndia = SUBLANG_ASSAMESE_INDIA,  // ����ķ�ӡ�ȣ�
        AzeriKatin = SUBLANG_AZERI_LATIN,  // �����ݽ�������- �����ݽ�
        AzeriCyrillic = SUBLANG_AZERI_CYRILLIC,  // �����ݽ��������ģ� - �����ݽ�
        BashkirRussia = SUBLANG_BASHKIR_RUSSIA,  // ��ʲ����������˹��
        BasqueBasque = SUBLANG_BASQUE_BASQUE,  // ��˹���� (��˹��)
        BelarusianBelarus = SUBLANG_BELARUSIAN_BELARUS,  // �׶���˹��׶���˹��
        BengaliIndia = SUBLANG_BENGALI_INDIA,  // �ϼ����ӡ�ȣ�
        BengaliBangladesh = SUBLANG_BENGALI_BANGLADESH,  // �ϼ������ϼ�������
        BosnianBosniaHerzegovinaLatin = SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_LATIN,  // ��˹���ǣ���˹���Ǻͺ�����ά�� - �����
        BosnianBosniaHerzegovinaCyrilli = SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_CYRILLIC,  // ��˹���ǣ���˹���Ǻͺ�����ά�� - ������ģ�
        BretonFrance = SUBLANG_BRETON_FRANCE,  // ���׶٣�������
        BulgarianBulgaria = SUBLANG_BULGARIAN_BULGARIA,  // ����������������ǣ�
        CatalanCatalan = SUBLANG_CATALAN_CATALAN,  // ��̩���������̩�����ǣ�
        ChineseTraditional = SUBLANG_CHINESE_TRADITIONAL,  // ���ģ�̨�壩
        ChineseSimplified = SUBLANG_CHINESE_SIMPLIFIED,  // ���ģ��й���
        ChineseHongkong = SUBLANG_CHINESE_HONGKONG,  // ���ģ���ۣ�
        ChineseSingapore = SUBLANG_CHINESE_SINGAPORE,  // ���ģ��¼��£�
        ChineseMacau = SUBLANG_CHINESE_MACAU,  // ���ģ����ţ�
        CorsicanFrance = SUBLANG_CORSICAN_FRANCE,  // �����Σ�������
        CzechCzechRepublic = SUBLANG_CZECH_CZECH_REPUBLIC,  // �ݿ���ݿ˹��͹���
        CroatianCroatia = SUBLANG_CROATIAN_CROATIA,  // ���޵�������޵��ǣ�
        CroatianBosniaHerzegovinaLatin = SUBLANG_CROATIAN_BOSNIA_HERZEGOVINA_LATIN,  // ���޵������˹���Ǻͺ�����ά�� - �����
        DanishDenmark = SUBLANG_DANISH_DENMARK,  // ���������
        DariAfghanistan = SUBLANG_DARI_AFGHANISTAN,  // �����������
        DivehiMaldives = SUBLANG_DIVEHI_MALDIVES,  // ��άϣ����������
        Dutch = SUBLANG_DUTCH,  // ������
        DutchBelgian = SUBLANG_DUTCH_BELGIAN,  // ���������ʱ��
        EnglishUSA = SUBLANG_ENGLISH_US,  // Ӣ�������
        EnglishUK = SUBLANG_ENGLISH_UK,  // Ӣ�Ӣ����
        EnglishAustralian = SUBLANG_ENGLISH_AUS,  // Ӣ��Ĵ����ǣ�
        EnglishCanadian = SUBLANG_ENGLISH_CAN,  // Ӣ����ô�
        EnglishNewZealand = SUBLANG_ENGLISH_NZ,  // Ӣ���������
        EnglishIrish = SUBLANG_ENGLISH_EIRE,  // Ӣ���������
        EnglishSouthAfrica = SUBLANG_ENGLISH_SOUTH_AFRICA,  // Ӣ�� ���Ϸǣ�
        EnglishJamaica = SUBLANG_ENGLISH_JAMAICA,  // Ӣ�����ӣ�
        EnglishCaribbean = SUBLANG_ENGLISH_CARIBBEAN,  // Ӣ����ձȣ�
        EnglishBelize = SUBLANG_ENGLISH_BELIZE,  // Ӣ������ȣ�
        EnglishTrinidad = SUBLANG_ENGLISH_TRINIDAD,  // Ӣ�������
        EnglishZimbabwe = SUBLANG_ENGLISH_ZIMBABWE,  // Ӣ���Ͳ�Τ��
        EnglishPhilippines = SUBLANG_ENGLISH_PHILIPPINES,  // Ӣ����ɱ���
        EnglishIndia = SUBLANG_ENGLISH_INDIA,  // Ӣ�ӡ�ȣ�
        EnglishMalaysia = SUBLANG_ENGLISH_MALAYSIA,  // Ӣ��������ǣ�
        EnglishSingapore = SUBLANG_ENGLISH_SINGAPORE,  // Ӣ��¼��£�
        EstonianEstonia = SUBLANG_ESTONIAN_ESTONIA,  // ��ɳ�������ɳ���ǣ�
        FaroeseFaroeIslands = SUBLANG_FAEROESE_FAROE_ISLANDS,  // ����Ⱥ�������Ⱥ����
        FilipinoPhilippines = SUBLANG_FILIPINO_PHILIPPINES,  // ���ɱ�����ɱ���
        FinnishFinland = SUBLANG_FINNISH_FINLAND,  // �����������
        French = SUBLANG_FRENCH,  // ����
        FrenchBelgian = SUBLANG_FRENCH_BELGIAN,  // �������ʱ��
        FrenchCanadian = SUBLANG_FRENCH_CANADIAN,  // ������ô�
        FrenchSwiss = SUBLANG_FRENCH_SWISS,  // �����ʿ��
        FrenchLuxembourg = SUBLANG_FRENCH_LUXEMBOURG,  // ���¬ɭ����
        FrenchMonaco = SUBLANG_FRENCH_MONACO,  // ���Ħ�ɸ磩
        FrisianNetherlands = SUBLANG_FRISIAN_NETHERLANDS,  // ����˹���������
        GalicianGalician = SUBLANG_GALICIAN_GALICIAN,  // ����������������ǣ�
        GeorgianGeorgia = SUBLANG_GEORGIAN_GEORGIA,  // ��³������ (��³����)
        German = SUBLANG_GERMAN,  // ����
        GermanSwiss = SUBLANG_GERMAN_SWISS,  // �����ʿ��
        GermanAustrian = SUBLANG_GERMAN_AUSTRIAN,  // ����µ�����
        GermanLuxembourg = SUBLANG_GERMAN_LUXEMBOURG,  // ���¬ɭ����
        GermanLiechtenstein = SUBLANG_GERMAN_LIECHTENSTEIN,  // �����֧��ʿ�ǣ�
        GreekGreece = SUBLANG_GREEK_GREECE,  // ϣ���ϣ����
        GreenlandicGreenland = SUBLANG_GREENLANDIC_GREENLAND,  // ���������������
        GujaratiIndia = SUBLANG_GUJARATI_INDIA,  // �ż������ӡ�ȣ��ż�������ű�����
        HausaNigeriaLatin = SUBLANG_HAUSA_NIGERIA_LATIN,  // �����������������ǣ�
        HebrewIsrael = SUBLANG_HEBREW_ISRAEL,  // ϣ�������ɫ�У�
        HindiIndia = SUBLANG_HINDI_INDIA,  // ӡ���ӡ�ȣ�
        HungarianHungary = SUBLANG_HUNGARIAN_HUNGARY,  // ���������������
        IcelandicIceland = SUBLANG_ICELANDIC_ICELAND,  // �����������
        IgboNigeria = SUBLANG_IGBO_NIGERIA,  // ������������ǣ�
        IndonesianIndonesia = SUBLANG_INDONESIAN_INDONESIA,  // ӡ���ӡ�������ǣ�
        InuktitutCanada = SUBLANG_INUKTITUT_CANADA,  // ��Ŧ������ڣ������ô�
        InuktitutLatin = SUBLANG_INUKTITUT_CANADA_LATIN,  // ��Ŧ������ô� - �����ģ�
        IrishIreland = SUBLANG_IRISH_IRELAND,  // ���������������
        Italian = SUBLANG_ITALIAN,  // �������
        ItalianSwiss = SUBLANG_ITALIAN_SWISS,  // ������� ����ʿ��
        JapaneseJapan = SUBLANG_JAPANESE_JAPAN,  // ����ձ���
        KannadaIndia = SUBLANG_KANNADA_INDIA,  // ���ɴ��ӡ�ȣ����ɴ���ű�����
        KashmiriSouthAsia = SUBLANG_KASHMIRI_SASIA,  // ��ʲ�׶�����ǣ�
        KashmiriIndia = SUBLANG_KASHMIRI_INDIA,  // ��������Ӧ�ü�����
        KazakhKazakhstan = SUBLANG_KAZAK_KAZAKHSTAN,  // ������˹̹�� (������˹̹)
        KhmerCambodia = SUBLANG_KHMER_CAMBODIA,  // ���������կ��
        KicheGuatemala = SUBLANG_KICHE_GUATEMALA,  // ��ϣ�Σ��������
        KinyarwandaRwanda = SUBLANG_KINYARWANDA_RWANDA,  // ������¬�����¬���
        KonkaniIndia = SUBLANG_KONKANI_INDIA,  // �����ᣨӡ�ȣ�
        Korean = SUBLANG_KOREAN,  // �����չ��˳��
        KyrgyzKyrgyzstan = SUBLANG_KYRGYZ_KYRGYZSTAN,  // ������˹˹̹�� (������˹˹̹)
        LaoLao = SUBLANG_LAO_LAO,  // ������ (����)
        LatvianLatvia = SUBLANG_LATVIAN_LATVIA,  // ����ά���� (����ά��)
        Lithuanian = SUBLANG_LITHUANIAN,  // ��������
        LowerSorbianGermany = SUBLANG_LOWER_SORBIAN_GERMANY,  // ��������¹���
        LuxembourgishLuxembourg = SUBLANG_LUXEMBOURGISH_LUXEMBOURG,  // ¬ɭ���¬ɭ����
        MacedonianMacedonia = SUBLANG_MACEDONIAN_MACEDONIA,  // ����������٣�
        MalayMalaysia = SUBLANG_MALAY_MALAYSIA,  // ����������������ǣ�
        MalayBruneiDarussalam = SUBLANG_MALAY_BRUNEI_DARUSSALAM,  // �����������³��������
        MalayalamIndia = SUBLANG_MALAYALAM_INDIA,  // ��������ķ�ӡ�ȣ���������ķ��ű�����
        MalteseMalta = SUBLANG_MALTESE_MALTA,  // ���������������
        MaoriNewZealand = SUBLANG_MAORI_NEW_ZEALAND,  // ë�����������
        MapudungunChile = SUBLANG_MAPUDUNGUN_CHILE,  // ���Ϳ��� ��������
        MarathiIndia = SUBLANG_MARATHI_INDIA,  // ������ ��ӡ�ȣ�
        MohawkMohawk = SUBLANG_MOHAWK_MOHAWK,  // Ī���� (Ī����)
        MongolianCyrillicMongolia = SUBLANG_MONGOLIAN_CYRILLIC_MONGOLIA,  // �ɹ��������ģ��ɹţ�
        MongolianPRC = SUBLANG_MONGOLIAN_PRC,  // �ɹ���ɹţ�
        NepaliIndia = SUBLANG_NEPALI_INDIA,  // �Ჴ���ӡ�ȣ�
        NepaliNepal = SUBLANG_NEPALI_NEPAL,  // �Ჴ����Ჴ����
        NorwegianBokmal = SUBLANG_NORWEGIAN_BOKMAL,  // Ų�������������
        NorwegianNynorsk = SUBLANG_NORWEGIAN_NYNORSK,  // Ų�����ŵ˹���
        OccitanFrance = SUBLANG_OCCITAN_FRANCE,  // �¿����أ�������
        OriyaIndia = SUBLANG_ORIYA_INDIA,  // �������ӡ�ȣ���������ű�����
        PashtoAfghanistan = SUBLANG_PASHTO_AFGHANISTAN,  // ��ʲͼ���������
        PersianIran = SUBLANG_PERSIAN_IRAN,  // ��˹����ʣ�
        PolishPoland = SUBLANG_POLISH_POLAND,  // �����������
        Portuguese = SUBLANG_PORTUGUESE,  // ��������
        PortugueseBrazilian = SUBLANG_PORTUGUESE_BRAZILIAN,  // �������������
        PunjabiIndia = SUBLANG_PUNJABI_INDIA,  // �������ӡ�ȣ���³������ű�����
        QuechuaBolivia = SUBLANG_QUECHUA_BOLIVIA,  // �����������ά�ǣ�
        QuechuaEcuador = SUBLANG_QUECHUA_ECUADOR,  // ���������϶����
        QuechuaPeru = SUBLANG_QUECHUA_PERU,  // �������� ����³��
        RomanianRomania = SUBLANG_ROMANIAN_ROMANIA,  // ����������������ǣ�
        RomanshSwitzerland = SUBLANG_ROMANSH_SWITZERLAND,  // ����ʲ����ʿ��
        RussianRussia = SUBLANG_RUSSIAN_RUSSIA,  // ����˹�����˹��
        SamiNorthernNorway = SUBLANG_SAMI_NORTHERN_NORWAY,  // �������Ų����
        SamiNorthernSweden = SUBLANG_SAMI_NORTHERN_SWEDEN,  // ���������䣩
        SamiNorthernFinland = SUBLANG_SAMI_NORTHERN_FINLAND,  // �������������
        SamiLuleNorway = SUBLANG_SAMI_LULE_NORWAY,  // ����ŷ�����Ų����
        SamiLuleSweden = SUBLANG_SAMI_LULE_SWEDEN,  // ����ŷ�������䣩
        SamiSouthernNorway = SUBLANG_SAMI_SOUTHERN_NORWAY,  // �������Ų����
        SamiSouthernSweden = SUBLANG_SAMI_SOUTHERN_SWEDEN,  // ���������䣩
        SamiSkoltFinland = SUBLANG_SAMI_SKOLT_FINLAND,  // ˹���������������
        SamiInariFinland = SUBLANG_SAMI_INARI_FINLAND,  // �����������������
        SanskritIndia = SUBLANG_SANSKRIT_INDIA,  // ���ģ�ӡ�ȣ�
        ScottishGaelic = SUBLANG_SCOTTISH_GAELIC,  // �ո����Ƕ��Ӣ����
        SerbianBosniaHerzegovinaLatin = SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_LATIN,  // ����ά�����˹���Ǻͺ�����ά�� - �����
        SerbianBosniaHerzegovinaCyrillic = SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_CYRILLIC,  // ����ά�����˹���Ǻͺ�����ά�� - ������ģ�
        SerbianMontenegroLatn = SUBLANG_SERBIAN_MONTENEGRO_LATIN,  // ����ά�����ɽ - �����
        SerbianMontenegroCyrillic = SUBLANG_SERBIAN_MONTENEGRO_CYRILLIC,  // ����ά�����ɽ - ������ģ�
        SerbianSerbiaLatin = SUBLANG_SERBIAN_SERBIA_LATIN,  // ����ά�������ά�� - �����
        SerbianSerbiaCyrillic = SUBLANG_SERBIAN_SERBIA_CYRILLIC,  // ����ά�������ά�� - ������ģ�
        SerbianCroatia = SUBLANG_SERBIAN_CROATIA,  // ���޵�������޵��ǣ�
        SerbianLatin = SUBLANG_SERBIAN_LATIN,  // ����ά��������
        SerbianCyrillic = SUBLANG_SERBIAN_CYRILLIC,  // ����ά���� ��������ģ�
        SindhiIndia = SUBLANG_SINDHI_INDIA,  // ���ϣ�ӡ�ȣ�
        SindhiPakistan = SUBLANG_SINDHI_PAKISTAN,  // ���ϣ��ͻ�˹̹��
        SindhiAfghanistan = SUBLANG_SINDHI_AFGHANISTAN,  // ��������Ӧ�ü�����
        SinhaleseSriLanka = SUBLANG_SINHALESE_SRI_LANKA,  // ɮ٤���˹��������
        SothoNorthernSouthAfrica = SUBLANG_SOTHO_NORTHERN_SOUTH_AFRICA,  // �����У��Ϸǣ�
        SlovakSlovakia = SUBLANG_SLOVAK_SLOVAKIA,  // ˹�工���˹�工�ˣ�
        SlovenianSlovenia = SUBLANG_SLOVENIAN_SLOVENIA,  // ˹���������˹�������ǣ�
        Spanish = SUBLANG_SPANISH,  // ���������˹�����
        SpanishMexico = SUBLANG_SPANISH_MEXICAN,  // �������ī���磩
        SpanishModern = SUBLANG_SPANISH_MODERN,  // ��������ִ���
        SpanishGuatemala = SUBLANG_SPANISH_GUATEMALA,  // �������Σ��������
        SpanishCostaRica = SUBLANG_SPANISH_COSTA_RICA,  // ���������˹����ӣ�
        SpanishPanama = SUBLANG_SPANISH_PANAMA,  // ���������������
        SpanishDominicanRepublic = SUBLANG_SPANISH_DOMINICAN_REPUBLIC,  // �������������ӹ��͹���
        SpanishVenezuela = SUBLANG_SPANISH_VENEZUELA,  // �������ί��������
        SpanishColombia = SUBLANG_SPANISH_COLOMBIA,  // ����������ױ��ǣ�
        SpanishPeru = SUBLANG_SPANISH_PERU,  // ���������³��
        SpanishArgentina = SUBLANG_SPANISH_ARGENTINA,  // �����������͢��
        SpanishEcuador = SUBLANG_SPANISH_ECUADOR,  // ���������϶����
        SpanishChile = SUBLANG_SPANISH_CHILE,  // �������������
        SpanishUruguay = SUBLANG_SPANISH_URUGUAY,  // ������������磩
        SpanishParaguay = SUBLANG_SPANISH_PARAGUAY,  // ������������磩
        SpanishBolivia = SUBLANG_SPANISH_BOLIVIA,  // �����������ά�ǣ�
        SpanishElSalvador = SUBLANG_SPANISH_EL_SALVADOR,  // ������������߶ࣩ
        SpanishHonduras = SUBLANG_SPANISH_HONDURAS,  // ��������鶼��˹��
        SpanishNicaragua = SUBLANG_SPANISH_NICARAGUA,  // �������������ϣ�
        SpanishPuertoRico = SUBLANG_SPANISH_PUERTO_RICO,  // ����������������
        SpanishUS = SUBLANG_SPANISH_US,  // �������������
        SwahiliKenya = SUBLANG_SWAHILI_KENYA,  // ˹��ϣ��������ǣ�
        Swedish = SUBLANG_SWEDISH,  // �����
        SwedishFinland = SUBLANG_SWEDISH_FINLAND,  // ����������
        SyriacSyria = SUBLANG_SYRIAC_SYRIA,  // ������������ǣ�
        TajikTajikistan = SUBLANG_TAJIK_TAJIKISTAN,  // �������������˹̹��
        TamazightLatinAlgeria = SUBLANG_TAMAZIGHT_ALGERIA_LATIN,  // �����������������������ǣ�
        TamilIndia = SUBLANG_TAMIL_INDIA,  // ̩�׶��ӡ�ȣ�
        TatarRussia = SUBLANG_TATAR_RUSSIA,  // ���������˹��
        TeluguIndia = SUBLANG_TELUGU_INDIA,  // ̩¬���ӡ�ȣ�̩¬���Ľű�����
        ThaiThailand = SUBLANG_THAI_THAILAND,  // ̩���̩����
        TibetanPRC = SUBLANG_TIBETAN_PRC,  // ����й���
        TigrignaEritrea = SUBLANG_TIGRIGNA_ERITREA,  // �ٸ���������������ǣ�
        TswanaSouthAfrica = SUBLANG_TSWANA_SOUTH_AFRICA,  // ��������Ϸǣ�
        TurkishTurkey = SUBLANG_TURKISH_TURKEY,  // ������������䣩
        TurkmenTurkmenistan = SUBLANG_TURKMEN_TURKMENISTAN,  // �������������˹̹��
        UighurPRC = SUBLANG_UIGHUR_PRC,  // ά��й���
        UkrainianUkraine = SUBLANG_UKRAINIAN_UKRAINE,  // �ڿ�����ڿ�����
        UpperSorbianGermany = SUBLANG_UPPER_SORBIAN_GERMANY,  // ��������¹���
        UrduPakistan = SUBLANG_URDU_PAKISTAN,  // �ڶ�����ͻ�˹̹��
        UrduIndia = SUBLANG_URDU_INDIA,  // �ڶ����ӡ�ȣ�
        UzbekLatin = SUBLANG_UZBEK_LATIN,  // ���ȱ���������
        UzbekCyrillic = SUBLANG_UZBEK_CYRILLIC,  // ���ȱ����������
        VietnameseVietnam = SUBLANG_VIETNAMESE_VIETNAM,  // Խ���Խ�ϣ�
        WelshUnitedKingdom = SUBLANG_WELSH_UNITED_KINGDOM,  // ����ʿ�Ӣ����
        WolofSenegal = SUBLANG_WOLOF_SENEGAL,  // ����� �����ڼӶ���
        XhosaSouthAfrica = SUBLANG_XHOSA_SOUTH_AFRICA,  // ������ ���Ϸǣ�
        YakutRussia = SUBLANG_YAKUT_RUSSIA,  // �ſ��أ�����˹��
        YiPRC = SUBLANG_YI_PRC,  // ƴ�����й���
        YorubaNigeria = SUBLANG_YORUBA_NIGERIA,  // Լ³�ͣ��������ǣ�
        ZuluSouthAfrica = SUBLANG_ZULU_SOUTH_AFRICA,  // ��³ ���Ϸǣ�
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class SubLanguage
    {
        Neutral = 0x00,
        Default = 0x01,
        SysDefault = 0x02,
        CustomDefault = 0x03,
        CustomUnspecified = 0x04,
        UICustomDefault = 0x05,
        AfrikaansSouthAfrica = 0x01,
        AlbanianAlbania = 0x01,
        AlbanianFrance = 0x01,
        AmharicEthiopia = 0x01,
        ArabicSaudiArabia = 0x01,
        ArabicIraq = 0x02,
        ArabicEgypt = 0x03,
        ArabicLibya = 0x04,
        ArabicAlgeria = 0x05,
        ArabicMorocco = 0x06,
        ArabicTunisia = 0x07,
        ArabicOman = 0x08,
        ArabicYemen = 0x09,
        ArabicSyria = 0x0a,
        ArabicJordan = 0x0b,
        ArabicLebanon = 0x0c,
        ArabicKuwait = 0x0d,
        ArabicUae = 0x0e,
        ArabicBahrain = 0x0f,
        ArabicQatar = 0x10,
        ArmenianArmenia = 0x01,
        AssameseIndia = 0x01,
        AzeriKatin = 0x01,
        AzeriCyrillic = 0x02,
        BashkirRussia = 0x01,
        BasqueBasque = 0x01,
        BelarusianBelarus = 0x01,
        BengaliIndia = 0x01,
        BengaliBangladesh = 0x02,
        BosnianBosniaHerzegovinaLatin = 0x05,
        BosnianBosniaHerzegovinaCyrilli = 0x08,
        BretonFrance = 0x01,
        BulgarianBulgaria = 0x01,
        CatalanCatalan = 0x01,
        ChineseTraditional = 0x01,
        ChineseSimplified = 0x02,
        ChineseHongkong = 0x03,
        ChineseSingapore = 0x04,
        ChineseMacau = 0x05,
        CorsicanFrance = 0x01,
        CzechCzechRepublic = 0x01,
        CroatianCroatia = 0x01,
        CroatianBosniaHerzegovinaLatin = 0x04,
        DanishDenmark = 0x01,
        DariAfghanistan = 0x01,
        DivehiMaldives = 0x01,
        Dutch = 0x01,
        DutchBelgian = 0x02,
        EnglishUSA = 0x01,
        EnglishUK = 0x02,
        EnglishAustralian = 0x03,
        EnglishCanadian = 0x04,
        EnglishNewZealand = 0x05,
        EnglishIrish = 0x06,
        EnglishSouthAfrica = 0x07,
        EnglishJamaica = 0x08,
        EnglishCaribbean = 0x09,
        EnglishBelize = 0x0a,
        EnglishTrinidad = 0x0b,
        EnglishZimbabwe = 0x0c,
        EnglishPhilippines = 0x0d,
        EnglishIndia = 0x10,
        EnglishMalaysia = 0x11,
        EnglishSingapore = 0x12,
        EstonianEstonia = 0x01,
        FaroeseFaroeIslands = 0x01,
        FilipinoPhilippines = 0x01,
        FinnishFinland = 0x01,
        French = 0x01,
        FrenchBelgian = 0x02,
        FrenchCanadian = 0x03,
        FrenchSwiss = 0x04,
        FrenchLuxembourg = 0x05,
        FrenchMonaco = 0x06,
        FrisianNetherlands = 0x01,
        GalicianGalician = 0x01,
        GeorgianGeorgia = 0x01,
        German = 0x01,
        GermanSwiss = 0x02,
        GermanAustrian = 0x03,
        GermanLuxembourg = 0x04,
        GermanLiechtenstein = 0x05,
        GreekGreece = 0x01,
        GreenlandicGreenland = 0x01,
        GujaratiIndia = 0x01,
        HausaNigeriaLatin = 0x01,
        HebrewIsrael = 0x01,
        HindiIndia = 0x01,
        HungarianHungary = 0x01,
        IcelandicIceland = 0x01,
        IgboNigeria = 0x01,
        IndonesianIndonesia = 0x01,
        InuktitutCanada = 0x01,
        InuktitutLatin = 0x02,
        IrishIreland = 0x02,
        Italian = 0x01,
        ItalianSwiss = 0x02,
        JapaneseJapan = 0x01,
        KannadaIndia = 0x01,
        KashmiriSouthAsia = 0x02,
        KashmiriIndia = 0x02,
        KazakhKazakhstan = 0x01,
        KhmerCambodia = 0x01,
        KicheGuatemala = 0x01,
        KinyarwandaRwanda = 0x01,
        KonkaniIndia = 0x01,
        Korean = 0x01,
        KyrgyzKyrgyzstan = 0x01,
        LaoLao = 0x01,
        LatvianLatvia = 0x01,
        Lithuanian = 0x01,
        LowerSorbianGermany = 0x02,
        LuxembourgishLuxembourg = 0x01,
        MacedonianMacedonia = 0x01,
        MalayMalaysia = 0x01,
        MalayBruneiDarussalam = 0x02,
        MalayalamIndia = 0x01,
        MalteseMalta = 0x01,
        MaoriNewZealand = 0x01,
        MapudungunChile = 0x01,
        MarathiIndia = 0x01,
        MohawkMohawk = 0x01,
        MongolianCyrillicMongolia = 0x01,
        MongolianPRC = 0x02,
        NepaliIndia = 0x02,
        NepaliNepal = 0x01,
        NorwegianBokmal = 0x01,
        NorwegianNynorsk = 0x02,
        OccitanFrance = 0x01,
        OriyaIndia = 0x01,
        PashtoAfghanistan = 0x01,
        PersianIran = 0x01,
        PolishPoland = 0x01,
        Portuguese = 0x02,
        PortugueseBrazilian = 0x01,
        PunjabiIndia = 0x01,
        QuechuaBolivia = 0x01,
        QuechuaEcuador = 0x02,
        QuechuaPeru = 0x03,
        RomanianRomania = 0x01,
        RomanshSwitzerland = 0x01,
        RussianRussia = 0x01,
        SamiNorthernNorway = 0x01,
        SamiNorthernSweden = 0x02,
        SamiNorthernFinland = 0x03,
        SamiLuleNorway = 0x04,
        SamiLuleSweden = 0x05,
        SamiSouthernNorway = 0x06,
        SamiSouthernSweden = 0x07,
        SamiSkoltFinland = 0x08,
        SamiInariFinland = 0x09,
        SanskritIndia = 0x01,
        ScottishGaelic = 0x01,
        SerbianBosniaHerzegovinaLatin = 0x06,
        SerbianBosniaHerzegovinaCyrillic = 0x07,
        SerbianMontenegroLatn = 0x0b,
        SerbianMontenegroCyrillic = 0x0c,
        SerbianSerbiaLatin = 0x09,
        SerbianSerbiaCyrillic = 0x0a,
        SerbianCroatia = 0x01,
        SerbianLatin = 0x02,
        SerbianCyrillic = 0x03,
        SindhiIndia = 0x01,
        SindhiPakistan = 0x02,
        SindhiAfghanistan = 0x02,
        SinhaleseSriLanka = 0x01,
        SothoNorthernSouthAfrica = 0x01,
        SlovakSlovakia = 0x01,
        SlovenianSlovenia = 0x01,
        Spanish = 0x01,
        SpanishMexico = 0x02,
        SpanishModern = 0x03,
        SpanishGuatemala = 0x04,
        SpanishCostaRica = 0x05,
        SpanishPanama = 0x06,
        SpanishDominicanRepublic = 0x07,
        SpanishVenezuela = 0x08,
        SpanishColombia = 0x09,
        SpanishPeru = 0x0a,
        SpanishArgentina = 0x0b,
        SpanishEcuador = 0x0c,
        SpanishChile = 0x0d,
        SpanishUruguay = 0x0e,
        SpanishParaguay = 0x0f,
        SpanishBolivia = 0x10,
        SpanishElSalvador = 0x11,
        SpanishHonduras = 0x12,
        SpanishNicaragua = 0x13,
        SpanishPuertoRico = 0x14,
        SpanishUS = 0x15,
        SwahiliKenya = 0x01,
        Swedish = 0x01,
        SwedishFinland = 0x02,
        SyriacSyria = 0x01,
        TajikTajikistan = 0x01,
        TamazightLatinAlgeria = 0x02,
        TamilIndia = 0x01,
        TatarRussia = 0x01,
        TeluguIndia = 0x01,
        ThaiThailand = 0x01,
        TibetanPRC = 0x01,
        TigrignaEritrea = 0x02,
        TswanaSouthAfrica = 0x01,
        TurkishTurkey = 0x01,
        TurkmenTurkmenistan = 0x01,
        UighurPRC = 0x01,
        UkrainianUkraine = 0x01,
        UpperSorbianGermany = 0x01,
        UrduPakistan = 0x01,
        UrduIndia = 0x02,
        UzbekLatin = 0x01,
        UzbekCyrillic = 0x02,
        VietnameseVietnam = 0x01,
        WelshUnitedKingdom = 0x01,
        WolofSenegal = 0x01,
        XhosaSouthAfrica = 0x01,
        YakutRussia = 0x01,
        YiPRC = 0x01,
        YorubaNigeria = 0x01,
        ZuluSouthAfrica = 0x01,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SYSTEM_OUTPUT_SUB_LANGUAGE_FLAGS_H