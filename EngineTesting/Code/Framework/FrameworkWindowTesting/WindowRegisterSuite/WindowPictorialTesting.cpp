// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/10 22:18)

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
    : ParentType{ stream }, m_Instance{ hInstance },
      m_IconContainer{ { 0, System::g_Application },
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
      m_CursorContainer{ { 0, System::g_Arrow },
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
      m_BrushContainer{ System::WindowsBrushTypes::WhiteBrush,
                        System::WindowsBrushTypes::LtgrayBrush,
                        System::WindowsBrushTypes::GrayBrush,
                        System::WindowsBrushTypes::DkgrayBrush,
                        System::WindowsBrushTypes::BlackBrush,
                        System::WindowsBrushTypes::NullBrush },
      m_TestIconContainer{}, m_TestCursorContainer{}, m_TestBrushContainer{},
      m_IconIter{ m_TestIconContainer.cend() },
      m_CursorIter{ m_TestCursorContainer.cend() },
      m_BrushIter{ m_TestBrushContainer.cend() }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowPictorialTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Instance != nullptr)
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
    for_each(m_BrushContainer.begin(), m_BrushContainer.end(), [this](const auto& value) {
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
    m_TestIconContainer = m_IconContainer;
    m_TestCursorContainer = m_CursorContainer;
    m_TestBrushContainer = m_BrushContainer;

    ASSERT_FALSE_FAILURE_THROW(m_TestIconContainer.empty(), "icon»›∆˜Œ™ø’£°");
    ASSERT_FALSE_FAILURE_THROW(m_TestCursorContainer.empty(), "cursor»›∆˜Œ™ø’£°");
    ASSERT_FALSE_FAILURE_THROW(m_TestBrushContainer.empty(), "windowBrush»›∆˜Œ™ø’£°");

    shuffle(m_TestIconContainer.begin(), m_TestIconContainer.end(), generator);
    shuffle(m_TestCursorContainer.begin(), m_TestCursorContainer.end(), generator);
    shuffle(m_TestBrushContainer.begin(), m_TestBrushContainer.end(), generator);

    m_IconIter = m_TestIconContainer.cbegin();
    m_CursorIter = m_TestCursorContainer.cbegin();
    m_BrushIter = m_TestBrushContainer.cbegin();
}

void Framework::WindowPictorialTesting::RandomIconTest()
{
    TestingType pictorial{ m_Instance, m_IconIter->second, IDC_CURSOR1, *m_BrushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, m_IconIter->second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(m_Instance, System::MakeIntreSource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*m_BrushIter));
}

void Framework::WindowPictorialTesting::RandomCursorTest()
{
    TestingType pictorial{ m_Instance, IDI_ICON1, m_CursorIter->second, *m_BrushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(m_Instance, System::MakeIntreSource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, m_CursorIter->second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*m_BrushIter));
}

void Framework::WindowPictorialTesting::RandomBrushTest()
{
    TestingType pictorial{ m_Instance, IDI_ICON1, IDC_CURSOR1, *m_BrushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(m_Instance, System::MakeIntreSource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(m_Instance, System::MakeIntreSource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*m_BrushIter));
}

void Framework::WindowPictorialTesting::RandomIconAndCursorTest()
{
    TestingType pictorial{ m_IconIter->second, m_CursorIter->second, *m_BrushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, m_IconIter->second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, m_CursorIter->second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*m_BrushIter));
}

void Framework::WindowPictorialTesting::DefaultIconTest()
{
    TestingType pictorial{ m_Instance, true, m_IconIter->first, false, IDC_CURSOR1, *m_BrushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, m_IconIter->second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(m_Instance, System::MakeIntreSource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*m_BrushIter));
}

void Framework::WindowPictorialTesting::DefaultCursorTest()
{
    TestingType pictorial{ m_Instance, false, IDI_ICON1, true, m_CursorIter->first, *m_BrushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(m_Instance, System::MakeIntreSource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, m_CursorIter->second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*m_BrushIter));
}

void Framework::WindowPictorialTesting::DefaultIconAndCursorTest()
{
    TestingType pictorial{ m_Instance, true, m_IconIter->first, true, m_CursorIter->first, *m_BrushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(nullptr, m_IconIter->second));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(nullptr, m_CursorIter->second));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*m_BrushIter));
}

void Framework::WindowPictorialTesting::CustomIconAndCursorTest()
{
    TestingType pictorial{ m_Instance, false, IDI_ICON1, false, IDC_CURSOR1, *m_BrushIter };

    ASSERT_EQUAL(pictorial.GetHIcon(), System::LoadSystemIcon(m_Instance, System::MakeIntreSource(IDI_ICON1)));
    ASSERT_EQUAL(pictorial.GetHCursor(), System::LoadSystemCursor(m_Instance, System::MakeIntreSource(IDC_CURSOR1)));
    ASSERT_EQUAL(pictorial.GetHBrush(), System::GetSystemStockObject(*m_BrushIter));
}

void Framework::WindowPictorialTesting::NextIcon(default_random_engine& generator)
{
    ++m_IconIter;
    if (m_IconIter == m_TestIconContainer.cend())
    {
        shuffle(m_TestIconContainer.begin(), m_TestIconContainer.end(), generator);
        m_IconIter = m_TestIconContainer.cbegin();
    }
}

void Framework::WindowPictorialTesting::NextCursor(default_random_engine& generator)
{
    ++m_CursorIter;
    if (m_CursorIter == m_TestCursorContainer.cend())
    {
        shuffle(m_TestCursorContainer.begin(), m_TestCursorContainer.end(), generator);
        m_CursorIter = m_TestCursorContainer.cbegin();
    }
}

void Framework::WindowPictorialTesting::NextBrush(default_random_engine& generator)
{
    ++m_BrushIter;
    if (m_BrushIter == m_TestBrushContainer.cend())
    {
        shuffle(m_TestBrushContainer.begin(), m_TestBrushContainer.end(), generator);
        m_BrushIter = m_TestBrushContainer.cbegin();
    }
}