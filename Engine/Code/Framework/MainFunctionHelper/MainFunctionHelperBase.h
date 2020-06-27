// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:47)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_H

#include "Framework/FrameworkDll.h" 

#include "EnvironmentDirectory.h"
#include "MainFunctionHelperFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(MainFunctionHelperBaseImpl);
template class FRAMEWORK_DEFAULT_DECLARE std::weak_ptr<Framework::MainFunctionHelperBase>;
template class FRAMEWORK_DEFAULT_DECLARE std::enable_shared_from_this<Framework::MainFunctionHelperBase>;

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE MainFunctionHelperBase : public std::enable_shared_from_this<MainFunctionHelperBase>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(MainFunctionHelperBase);
		using String = System::String;

	public:
		explicit MainFunctionHelperBase(const EnvironmentDirectory& environmentDirectory);
		virtual ~MainFunctionHelperBase() noexcept;
		MainFunctionHelperBase(const MainFunctionHelperBase& rhs) noexcept = delete;
		MainFunctionHelperBase& operator=(const MainFunctionHelperBase& rhs) noexcept = delete;
		MainFunctionHelperBase(MainFunctionHelperBase&& rhs) noexcept;
		MainFunctionHelperBase& operator=(MainFunctionHelperBase&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		String GetEngineInstallationDirectory() const;

		int Run();

		virtual void Destroy();

	protected:
		bool IsDestroy() const noexcept;
		EnvironmentDirectory GetEnvironmentDirectory() const;

	private:
		void MainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory);
		void DoMainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory);
		void MainFunctionHelperDestroy();

		void InitUniqueIDManager();
		void InitLog(const EnvironmentDirectory& environmentDirectory);
		void InitMemory() noexcept(CoreTools::g_MemoryNoexcept);
		void InitInitTerm();
		void InitEnvironment();
		void InitSmartPointer();
		void InitImpl(const EnvironmentDirectory& environmentDirectory);

		void DestroyImpl() noexcept;
		void DestroySmartPointer() noexcept;
		void DestroyEnvironment() noexcept;
		void DestroyInitTerm();
		void DestroyMemory() noexcept(CoreTools::g_MemoryNoexcept);
		void DestroyLog() noexcept;
		void DestroyUniqueIDManager();

		virtual int DoRun() = 0;
		virtual void MemoryCreate() noexcept(CoreTools::g_MemoryNoexcept);

	private:
		IMPL_TYPE_DECLARE(MainFunctionHelperBase);

		MainFunctionSchedule m_MainFunctionSchedule;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_H