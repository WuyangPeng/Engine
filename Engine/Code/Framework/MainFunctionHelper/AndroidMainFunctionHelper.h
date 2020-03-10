// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:51)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H

#include "MainFunctionHelperBase.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"

namespace Framework
{
	template <template<typename > class Build, typename Process>
	class AndroidMainFunctionHelper : public MainFunctionHelperBase
	{
	public:
		using ClassType = AndroidMainFunctionHelper<Build, Process>;
		using ParentType = MainFunctionHelperBase;
		using BuildType = Build<Process>;
	    using AndroidApp = System::AndroidApp;

	public:
		AndroidMainFunctionHelper(AndroidApp* state,const EnvironmentDirectory& environmentDirectory);
		virtual ~AndroidMainFunctionHelper();

		CLASS_INVARIANT_VIRTUAL_DECLARE;
		
		virtual void Destroy();

	protected:
		AndroidApp* GetAndroidApp();

	private:
		typedef std::shared_ptr<BuildType> BuildTypePtr;

	private:
		virtual int DoRun();
		virtual int RunAndroidMainLoop();

        void Initializers(AndroidApp* state);
        void Terminators();	

	private:
		BuildTypePtr m_Build;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_H
