// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:51)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_H

#include "Framework/FrameworkDll.h" 

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "EnvironmentDirectory.h"

#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(MainFunctionHelperBaseImpl);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE MainFunctionHelperBase : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(MainFunctionHelperBase);

	public:
		explicit MainFunctionHelperBase(const EnvironmentDirectory& environmentDirectory);
		virtual ~MainFunctionHelperBase();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		System::String GetEngineInstallationDirectory() const;
		
		int Run();

		virtual void Destroy();

	protected:
		bool IsDestroy() const;

	private:
        void MainFunctionHelperInit();
        void MainFunctionHelperDestroy();

		virtual int DoRun() = 0;
		virtual void MemoryCreate();

	private:
		IMPL_TYPE_DECLARE(MainFunctionHelperBase);

		bool m_Destroy;
		EnvironmentDirectory m_EnvironmentDirectory;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_MAIN_FUNCTION_HELPER_BASE_H