// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:14)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuiteOsPtr.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "System/Window/WindowProcess.h"

#include <fstream>
#include <iostream>

using std::ostream;
using std::cout;
using std::string;
using std::ofstream;

Framework::WindowMessageUnitTestSuiteOsPtr
	::WindowMessageUnitTestSuiteOsPtr()
	:m_OsPtr(&cout),m_IsFile(false),
	 m_CommandPtr(GenerateCommandPtr())
{
	GenerateOsPtr();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowMessageUnitTestSuiteOsPtr
	::~WindowMessageUnitTestSuiteOsPtr()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;

	Destroy();
}

// private
void Framework::WindowMessageUnitTestSuiteOsPtr
	::GenerateOsPtr()
{
	m_IsFile = (m_CommandPtr->GetExcessArgumentsCount() != 0);

	if(m_IsFile)
	{
		OpenFile();
	}	
}

// static
// private
Framework::WindowMessageUnitTestSuiteOsPtr::CommandPtr 
	Framework::WindowMessageUnitTestSuiteOsPtr
	::GenerateCommandPtr()
{
	string commandLine = GetMultiByteCommandLine();

	return CommandPtr(new Command(const_cast<char*>(commandLine.c_str())));
}

// static
// private
string Framework::WindowMessageUnitTestSuiteOsPtr
	::GetMultiByteCommandLine() 
{
	System::String commandLine = System::GetSystemCommandLine();
	return CoreTools::StringConversion::StandardConversionMultiByte(commandLine);
}

// private
void Framework::WindowMessageUnitTestSuiteOsPtr
	::Destroy()
{
	if(m_IsFile)
	{
		DELETE0(m_OsPtr);
		m_IsFile = false;
		m_OsPtr = &cout;
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowMessageUnitTestSuiteOsPtr
	::IsValid() const noexcept
{
	if(!m_IsFile && m_OsPtr == &cout)
	    return true;
	else if(m_IsFile && m_OsPtr != nullptr && *m_OsPtr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

ostream* Framework::WindowMessageUnitTestSuiteOsPtr
	::GetOsPtr()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return m_OsPtr;
}

// private
void Framework::WindowMessageUnitTestSuiteOsPtr
	::OpenFile()
{
	m_OsPtr = NEW0 ofstream(m_CommandPtr->GetFileName().c_str(),
		                    ofstream::out | ofstream::app);

	if(!(m_OsPtr != nullptr && *m_OsPtr))
	{
		Destroy();
	}
}

