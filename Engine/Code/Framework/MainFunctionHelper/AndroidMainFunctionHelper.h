// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:46)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H

#include "MainFunctionHelperBase.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"

namespace Framework
{
	template <template<typename> class Build, typename Process>
	class AndroidMainFunctionHelper : public MainFunctionHelperBase
	{
	public:
		using ClassType = AndroidMainFunctionHelper<Build, Process>;
		using ParentType = MainFunctionHelperBase;
		using ClassShareType = CoreTools::NonCopyClasses;
		using BuildType = Build<Process>;
		using AndroidApp = System::AndroidApp;

	public:
		AndroidMainFunctionHelper(AndroidApp* androidApp, const EnvironmentDirectory& environmentDirectory);
		~AndroidMainFunctionHelper() noexcept;
		AndroidMainFunctionHelper(const AndroidMainFunctionHelper& rhs) noexcept = delete;
		AndroidMainFunctionHelper& operator=(const AndroidMainFunctionHelper& rhs) noexcept = delete;
		AndroidMainFunctionHelper(AndroidMainFunctionHelper&& rhs) noexcept;
		AndroidMainFunctionHelper& operator=(AndroidMainFunctionHelper&& rhs) noexcept;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void Destroy() override;

	protected:
		AndroidApp* GetAndroidApp();

	private:
		using BuildSharedPtr = std::shared_ptr<BuildType>;

	private:
		int DoRun() override;
		virtual int RunAndroidMainLoop();

		void Initializers(AndroidApp* androidApp);
		void Terminators();

		void InitAndroidProcess();
		void InitImpl(AndroidApp* androidApp);

		void DestroyImpl() noexcept;
		void DestroyAndroidProcess();

	private:
		BuildSharedPtr m_Build;
		AndroidMainFunctionSchedule m_AndroidMainFunctionSchedule;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H
