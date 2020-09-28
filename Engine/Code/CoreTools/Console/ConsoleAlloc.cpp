// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:03)

#include "CoreTools/CoreToolsExport.h"

#include "ConsoleAlloc.h"
#include "System/Console/ConsoleCreate.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "CoreTools/ClassInvariant/NoexceptDetail.h"
#include <string>

using std::string;

CoreTools::ConsoleAlloc ::ConsoleAlloc() noexcept
    : m_OutPtr{ nullptr }, m_InPtr{ nullptr }, m_ErrPtr{ nullptr }
{
    CoreTools::NoexceptNoReturn(*this, &ClassType::OpenConsole);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ConsoleAlloc ::~ConsoleAlloc() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CloseConsole();
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ConsoleAlloc ::IsValid() const noexcept
{
    if (m_OutPtr != nullptr && m_InPtr != nullptr && m_ErrPtr != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::ConsoleAlloc ::OpenConsole()
{
    auto result = System::AllocConsole();

    const string outPath{ "CONOUT$" };
    const string inPath{ "CONOUT$" };
    const string outMode{ "w+t" };
    const string inMode{ "r+t" };

    result = System::FReOpenConsole(m_OutPtr, outPath.c_str(), outMode.c_str(), stdout);
    result = System::FReOpenConsole(m_InPtr, inPath.c_str(), inMode.c_str(), stdin);
    result = System::FReOpenConsole(m_ErrPtr, outPath.c_str(), outMode.c_str(), stderr);

    result = System::RemoveConsoleCloseButton();
}

void CoreTools::ConsoleAlloc ::CloseConsole() noexcept
{
   auto result = System::FCloseConsole(m_OutPtr);
    result = System::FCloseConsole(m_InPtr);
   result = System::FCloseConsole(m_ErrPtr);

   result = System::FreeConsole();
}
