///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ²âÊÔ°æ±¾£º0.8.0.9 (2022/06/27 13:52)

#include "WindowPictorialTesting.h"
#include "resource.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowRegister/WindowPictorial.h"

using std::default_random_engine;
using std::uniform_int;

namespace Framework
{
    using TestingType = WindowPictorial;
}

Framework::WindowPictorialTesting::WindowPictorialTesting(const OStreamShared& stream, HInstance hInstance)
    : ParentType{ stream }, instance{ hInstance },
      iconContainer{ { 0, System::g_Application },
                       { 32512, System::g_Application },
                       { 32513, System::g_IDIHand },
                       { 32514, System::g_Question },
                       { 32515, System::g_Exclamation },
                       { 32516, System::g_Asterisk },
                       { 32517, System::g_WinLogo },
                       { 32518, System::g_Shield },
                       { 32515, System::g_Warning },
                       { 32513, System::g_Error },
                       { 32516, System::g_Information } },
      cursorContainer{ { 0, System::g_Arrow },
                         { 32512, System::g_Arrow },
                         { 32513, System::g_Ibeam },
                         { 32514, System::g_Wait },
                         { 32515, System::g_Cross },
                         { 32516, System::g_UpArrow },
                         { 32642, System::g_SizeNwse },
                         { 32643, System::g_SizeNesw },
                         { 32644, System::g_SizeWe },
                         { 32645, System::g_SizeNs },
                         { 32646, System::g_SizeAll },
                         { 32648, System::g_No },
                         { 32649, System::g_IDCHand },
                         { 32650, System::g_AppStarting },
                         { 32651, System::g_Help } },
      brushContainer{ System::WindowsBrushTypes::WhiteBrush,
                        System::WindowsBrushTypes::LtgrayBrush,
                        System::WindowsBrushTypes::GrayBrush,
                        System::WindowsBrushTypes::DkgrayBrush,
                        System::WindowsBrushTypes::BlackBrush,
                        System::WindowsBrushTypes::NullBrush },
      testIconContainer{},
      testCursorContainer{},
      testBrushContainer{},
      iconIter{ testIconContainer.cend() },
      cursorIter{ testCursorContainer.cend() },
      brushIter{ testBrushContainer.cend() }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowPictorialTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && instance != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Framework::WindowPictorialTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowPictorialTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BrushTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RandomTest);
}

void Framework::WindowPictorialTesting::BrushTest()
{
    for_each(brushContainer.begin(), brushContainer.end(), [this](const auto& value) {
        const TestingType pictorial{ value };

        ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, System::g_Application));
        ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, System::g_Arrow));
        ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(value));
    });

    TestingType nullPictorial{ System::WindowsBrushTypes::Null };

    ASSERT_EQUAL(nullPictorial.GetHIcon(), System::LoadSystemIcon(nullptr, System::g_Application));
    ASSERT_EQUAL(nullPictorial.GetHCursor(), System::LoadSystemCursor(nullptr, System::g_Arrow));
    ASSERT_EQUAL(nullPictorial.GetHBrush(), nullptr);
}

void Framework::WindowPictorialTesting::RandomTest()
{
    default_random_engine generator{ GetEngineRandomSeed() };
    RandomContainer(generator);

    const auto testLoopCount = GetTestLoopCount();

    for (auto i = 0; i < testLoopCount; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(RandomIconTest);
        ASSERT_NOT_THROW_EXCEPTION_0(RandomCursorTest);
        ASSERT_NOT_THROW_EXCEPTION_0(RandomBrushTest);
        ASSERT_NOT_THROW_EXCEPTION_0(RandomIconAndCursorTest);

        ASSERT_NOT_THROW_EXCEPTION_0(DefaultIconTest);
        ASSERT_NOT_THROW_EXCEPTION_0(DefaultCursorTest);
        ASSERT_NOT_THROW_EXCEPTION_0(DefaultIconAndCursorTest);
        ASSERT_NOT_THROW_EXCEPTION_0(CustomIconAndCursorTest);

        NextIcon(generator);
        NextCursor(generator);
        NextBrush(generator);
    }
}

void Framework::WindowPictorialTesting::RandomContainer(default_random_engine& generator)
{
    testIconContainer = iconContainer;
    testCursorContainer = cursorContainer;
    testBrushContainer = brushContainer;

    ASSERT_FALSE_FAILURE_THROW(testIconContainer.empty(), "iconÈÝÆ÷Îª¿Õ£¡");
    ASSERT_FALSE_FAILURE_THROW(testCursorContainer.empty(), "cursorÈÝÆ÷Îª¿Õ£¡");
    ASSERT_FALSE_FAILURE_THROW(testBrushContainer.empty(), "windowBrushÈÝÆ÷Îª¿Õ£¡");

    shuffle(testIconContainer.begin(), testIconContainer.end(), generator);
    shuffle(testCursorContainer.begin(), testCursorContainer.end(), generator);
    shuffle(testBrushContainer.begin(), testBrushContainer.end(), generator);

    iconIter = testIconContainer.cbegin();
    cursorIter = testCursorContainer.cbegin();
    brushIter = testBrushContainer.cbegin();
}

void Framework::WindowPictorialTesting::RandomIconTest()
{
    TestingType pictorial{ instance, iconIter->second, IDC_CURSOR1, *brushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, iconIter->second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntreSource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*brushIter));
}

void Framework::WindowPictorialTesting::RandomCursorTest()
{
    TestingType pictorial{ instance, IDI_ICON1, cursorIter->second, *brushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntreSource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, cursorIter->second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*brushIter));
}

void Framework::WindowPictorialTesting::RandomBrushTest()
{
    TestingType pictorial{ instance, IDI_ICON1, IDC_CURSOR1, *brushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntreSource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntreSource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*brushIter));
}

void Framework::WindowPictorialTesting::RandomIconAndCursorTest()
{
    TestingType pictorial{ iconIter->second, cursorIter->second, *brushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, iconIter->second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, cursorIter->second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*brushIter));
}

void Framework::WindowPictorialTesting::DefaultIconTest()
{
    TestingType pictorial{ instance, true, iconIter->first, false, IDC_CURSOR1, *brushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, iconIter->second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntreSource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*brushIter));
}

void Framework::WindowPictorialTesting::DefaultCursorTest()
{
    TestingType pictorial{ instance, false, IDI_ICON1, true, cursorIter->first, *brushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntreSource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, cursorIter->second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*brushIter));
}

void Framework::WindowPictorialTesting::DefaultIconAndCursorTest()
{
    TestingType pictorial{ instance, true, iconIter->first, true, cursorIter->first, *brushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, iconIter->second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, cursorIter->second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*brushIter));
}

void Framework::WindowPictorialTesting::CustomIconAndCursorTest()
{
    TestingType pictorial{ instance, false, IDI_ICON1, false, IDC_CURSOR1, *brushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntreSource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntreSource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*brushIter));
}

void Framework::WindowPictorialTesting::NextIcon(default_random_engine& generator)
{
    ++iconIter;
    if (iconIter == testIconContainer.cend())
    {
        shuffle(testIconContainer.begin(), testIconContainer.end(), generator);
        iconIter = testIconContainer.cbegin();
    }
}

void Framework::WindowPictorialTesting::NextCursor(default_random_engine& generator)
{
    ++cursorIter;
    if (cursorIter == testCursorContainer.cend())
    {
        shuffle(testCursorContainer.begin(), testCursorContainer.end(), generator);
        cursorIter = testCursorContainer.cbegin();
    }
}

void Framework::WindowPictorialTesting::NextBrush(default_random_engine& generator)
{
    ++brushIter;
    if (brushIter == testBrushContainer.cend())
    {
        shuffle(testBrushContainer.begin(), testBrushContainer.end(), generator);
        brushIter = testBrushContainer.cbegin();
    }
}