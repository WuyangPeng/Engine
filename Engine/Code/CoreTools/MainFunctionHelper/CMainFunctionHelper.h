// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:29)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_HELPER_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_HELPER_H

#include "CoreTools/CoreToolsDll.h" 

#include <iosfwd>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CMainFunctionHelper
	{
	public:
		using ClassType = CMainFunctionHelper;

	public:
		CMainFunctionHelper(int argc, char* argv[]);
		virtual ~CMainFunctionHelper();

#ifdef OPEN_CLASS_INVARIANT
		CLASS_INVARIANT_VIRTUAL_DECLARE;
		bool ArgcEqualOneIsValid() const noexcept;
		bool ArgcUnequalOneIsValid() const noexcept;
#endif // OPEN_CLASS_INVARIANT	

		int GetArgc() const noexcept;
		char** GetArgv() noexcept;

		int Run();

	protected:
		std::ostream* GetOStream() noexcept;
		void SystemPause();

	private:
		void InitSingleton();
		void InitUniqueIDManager();
		void InitLog();
		void InitMemory();
		void InitSmartPointer();
		void GenerateOsPtr();
		void InitStreamLocale();

		void DestroySingleton();
		void DestroyOsPtr();
		void DestroySmartPointer();
		void DestroyMemory();
		void DestroyLog();
		void DestroyUniqueIDManager();

		virtual int DoRun() = 0;

	private:
		enum class ScheduleType   
		{
			Failure = 0,
			UniqueIDManager = 1,
			Log = 2,
			Memory = 3,
			SmartPointer = 4,
			Max = 5,
		};

	private:
		int m_Argc;
		char** m_Argv;
		std::ostream* m_OsPtr;
		ScheduleType m_Schedule;
	};
}

#endif // CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_HELPER_H