// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:29)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_DETAIL_H

#include "CoreTools/Exception/Error.h"
#include "AndroidMainFunctionHelper.h"
#include "Framework/AndroidFrame/AndroidProcessManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <stdexcept>
#include <iostream>

template <template<typename > class Build,typename Process>
Framework::AndroidMainFunctionHelper<Build, Process>
     ::AndroidMainFunctionHelper(AndroidApp* state,const EnvironmentDirectory& environmentDirectory)
	:ParentType{ environmentDirectory }, m_Build{}
{
    Initializers(state);

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <template<typename > class Build,typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>
     ::Initializers(AndroidApp* state)
{
	try
	{
		AndroidProcessManager::Create();	

		m_Build.reset(new BuildType(state));
	}
	catch (CoreTools::Error& error)
	{
		CERR << error.GetError() << SYSTEM_TEXT('\n');
	}
	catch(std::runtime_error& error)
	{
		std::cerr << error.what() << '\n';
	}
	catch(...)
	{
		CERR << SYSTEM_TEXT("Œ¥÷™¥ÌŒÛ\n");
	}
}

template <template<typename > class Build,typename Process>
Framework::AndroidMainFunctionHelper<Build, Process>
     ::~AndroidMainFunctionHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;

	if(!IsDestroy())
	{
        Destroy();
	}
}

template <template<typename > class Build,typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>
     ::Terminators()
{
	try
	{
		m_Build.reset();

		AndroidProcessManager::Destroy();
	}
	catch (CoreTools::Error& error)
	{
		CERR << error.GetError() << SYSTEM_TEXT('\n');
	}
	catch(std::runtime_error& error)
	{
		std::cerr << error.what() << '\n';
	}
	catch(...)
	{
		CERR << SYSTEM_TEXT("Œ¥÷™¥ÌŒÛ\n");
	}
}	

#ifdef OPEN_CLASS_INVARIANT
template <template<typename > class Build,typename Process>
bool Framework::AndroidMainFunctionHelper<Build, Process>
     ::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <template<typename > class Build,typename CallBack>
int Framework::AndroidMainFunctionHelper<Build, CallBack>
     ::DoRun()
{
	return RunAndroidMainLoop();
}

template <template<typename > class Build,typename Process>
int Framework::AndroidMainFunctionHelper<Build, Process>
     ::RunAndroidMainLoop()
{
	m_Build->EnterMessageLoop();

	return 0;
}

template <template<typename > class Build,typename Process>
void Framework::AndroidMainFunctionHelper<Build, Process>
    ::Destroy()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(!IsDestroy())
	{
		Terminators();

		ParentType::Destroy();
	}
}

template <template<typename > class Build,typename Process>
System::AndroidApp* Framework::AndroidMainFunctionHelper<Build, Process>
    ::GetAndroidApp() 
{
	return m_Build->GetAndroidApp();
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_ANDROID_MAIN_FUNCTION_HELPER_DETAIL_H
