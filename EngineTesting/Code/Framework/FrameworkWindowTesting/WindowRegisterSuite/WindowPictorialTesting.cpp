///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 13:59)

#include "WindowPictorialTesting.h"
#include "resource.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowRegister/WindowPictorial.h"

Framework::WindowPictorialTesting::WindowPictorialTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, instance{ instance },
      iconContainer{ { 0, System::gApplication },
                     { 32512, System::gApplication },
                     { 32513, System::gIdiHand },
                     { 32514, System::gQuestion },
                     { 32515, System::gExclamation },
                     { 32516, System::gAsterisk },
                     { 32517, System::gWinLogo },
                     { 32518, System::gShield },
                     { 32515, System::gWarning },
                     { 32513, System::gError },
                     { 32516, System::gInformation } },
      cursorContainer{ { 0, System::gArrow },
                       { 32512, System::gArrow },
                       { 32513, System::gIbeam },
                       { 32514, System::gWait },
                       { 32515, System::gCross },
                       { 32516, System::gUpArrow },
                       { 32642, System::gSizeNwse },
                       { 32643, System::gSizeNesw },
                       { 32644, System::gSizeWe },
                       { 32645, System::gSizeNs },
                       { 32646, System::gSizeAll },
                       { 32648, System::gNo },
                       { 32649, System::gIdcHand },
                       { 32650, System::gAppStarting },
                       { 32651, System::gHelp } },
      brushContainer{ System::WindowsBrushTypes::WhiteBrush,
                      System::WindowsBrushTypes::LightGrayBrush,
                      System::WindowsBrushTypes::GrayBrush,
                      System::WindowsBrushTypes::DarkGrayBrush,
                      System::WindowsBrushTypes::BlackBrush,
                      System::WindowsBrushTypes::NullBrush },
      generator{ GetEngineRandomSeed() },
      index{ 0 }
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

    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ExecuteWindowPictorialTest);
}

void Framework::WindowPictorialTesting::BrushTest()
{
    std::ranges::for_each(brushContainer, [this](const auto& element) {
        const WindowPictorial pictorial{ element };

        ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, System::gApplication));
        ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, System::gArrow));
        ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(element));
    });

    const WindowPictorial nullPictorial{ System::WindowsBrushTypes::Null };

    ASSERT_EQUAL(nullPictorial.GetHIcon(), System::LoadSystemIcon(nullptr, System::gApplication));
    ASSERT_EQUAL(nullPictorial.GetHCursor(), System::LoadSystemCursor(nullptr, System::gArrow));
    ASSERT_EQUAL(nullPictorial.GetHBrush(), nullptr);
}

void Framework::WindowPictorialTesting::RandomContainer()
{
    std::ranges::shuffle(iconContainer, generator);
    std::ranges::shuffle(cursorContainer, generator);
    std::ranges::shuffle(brushContainer, generator);
}

bool Framework::WindowPictorialTesting::ExecuteWindowPictorialTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomContainer);

    ASSERT_NOT_THROW_EXCEPTION_0(RandomIconTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RandomCursorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RandomBrushTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RandomIconAndCursorTest);

    ASSERT_NOT_THROW_EXCEPTION_0(DefaultIconTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultCursorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultIconAndCursorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CustomIconAndCursorTest);

    ++index;

    return true;
}

void Framework::WindowPictorialTesting::RandomIconTest()
{
    const auto iconIndex = index % iconContainer.size();
    const auto brushIndex = index % brushContainer.size();

    const WindowPictorial pictorial{ instance, iconContainer.at(iconIndex).second, IDC_CURSOR1, brushContainer.at(brushIndex) };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, iconContainer.at(iconIndex).second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntResource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(brushContainer.at(brushIndex)));
}

void Framework::WindowPictorialTesting::RandomCursorTest()
{
    const auto cursorIndex = index % cursorContainer.size();
    const auto brushIndex = index % brushContainer.size();

    const WindowPictorial pictorial{ instance, IDI_ICON1, cursorContainer.at(cursorIndex).second, brushContainer.at(brushIndex) };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntResource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, cursorContainer.at(cursorIndex).second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(brushContainer.at(brushIndex)));
}

void Framework::WindowPictorialTesting::RandomBrushTest()
{
    const auto brushIndex = index % brushContainer.size();

    const WindowPictorial pictorial{ instance, IDI_ICON1, IDC_CURSOR1, brushContainer.at(brushIndex) };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntResource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntResource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(brushContainer.at(brushIndex)));
}

void Framework::WindowPictorialTesting::RandomIconAndCursorTest()
{
    const auto iconIndex = index % iconContainer.size();
    const auto cursorIndex = index % cursorContainer.size();
    const auto brushIndex = index % brushContainer.size();

    const WindowPictorial pictorial{ iconContainer.at(iconIndex).second, cursorContainer.at(cursorIndex).second, brushContainer.at(brushIndex) };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, iconContainer.at(iconIndex).second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, cursorContainer.at(cursorIndex).second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(brushContainer.at(brushIndex)));
}

void Framework::WindowPictorialTesting::DefaultIconTest()
{
    const auto iconIndex = index % iconContainer.size();
    const auto brushIndex = index % brushContainer.size();

    const WindowPictorial pictorial{ instance, true, iconContainer.at(iconIndex).first, false, IDC_CURSOR1, brushContainer.at(brushIndex) };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, iconContainer.at(iconIndex).second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntResource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(brushContainer.at(brushIndex)));
}

void Framework::WindowPictorialTesting::DefaultCursorTest()
{
    const auto cursorIndex = index % cursorContainer.size();
    const auto brushIndex = index % brushContainer.size();

    const WindowPictorial pictorial{ instance, false, IDI_ICON1, true, cursorContainer.at(cursorIndex).first, brushContainer.at(brushIndex) };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntResource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, cursorContainer.at(cursorIndex).second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(brushContainer.at(brushIndex)));
}

void Framework::WindowPictorialTesting::DefaultIconAndCursorTest()
{
    const auto iconIndex = index % iconContainer.size();
    const auto cursorIndex = index % cursorContainer.size();
    const auto brushIndex = index % brushContainer.size();

    const WindowPictorial pictorial{ instance, true, iconContainer.at(iconIndex).first, true, cursorContainer.at(cursorIndex).first, brushContainer.at(brushIndex) };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, iconContainer.at(iconIndex).second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, cursorContainer.at(cursorIndex).second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(brushContainer.at(brushIndex)));
}

void Framework::WindowPictorialTesting::CustomIconAndCursorTest()
{
    const auto brushIndex = index % brushContainer.size();

    const WindowPictorial pictorial{ instance, false, IDI_ICON1, false, IDC_CURSOR1, brushContainer.at(brushIndex) };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntResource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntResource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(brushContainer.at(brushIndex)));
}
