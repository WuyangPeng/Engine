// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:01)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_OS_PTR_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_OS_PTR_H

#include "Framework/FrameworkDll.h"

#include <iosfwd>
#include <string>

namespace CoreTools
{
	class CommandHandle;
}

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowMessageUnitTestSuiteOsPtr
	{
	public:	
		using ClassType = WindowMessageUnitTestSuiteOsPtr;

	public:
		WindowMessageUnitTestSuiteOsPtr();	
		~WindowMessageUnitTestSuiteOsPtr();
	
		CLASS_INVARIANT_DECLARE;	

		std::ostream* GetOsPtr();

	private:
		using Command = CoreTools::CommandHandle;
		using CommandPtr = std::shared_ptr<Command>;

	private:
		void GenerateOsPtr();	
		void Destroy();
		void OpenFile();

		static CommandPtr GenerateCommandPtr();
		static std::string GetMultiByteCommandLine();	

	private:
		std::ostream* m_OsPtr;
		bool m_IsFile;
		CommandPtr m_CommandPtr;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_OS_PTR_H
