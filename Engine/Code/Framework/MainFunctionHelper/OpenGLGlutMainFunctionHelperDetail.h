// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 17:53)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_DETAIL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_DETAIL_H

#include "OpenGLGlutMainFunctionHelper.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"
#include "Framework/Application/GlutApplicationInformation.h"

#include <stdexcept>

template <template<typename > class Build,typename Process>
Framework::OpenGLGlutMainFunctionHelper<Build, Process>
     ::OpenGLGlutMainFunctionHelper(int argc,char* argv[],const GLUTApplicationInformation& information,
			                        const EnvironmentDirectory& environmentDirectory)
	:ParentType{ environmentDirectory }, m_Build{}
{
    Initializers(argc,argv,information);

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <template<typename > class Build,typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
     ::Initializers(int argc,char* argv[],const GLUTApplicationInformation& information)
{
	try
	{
		OpenGLGlutProcessManager::Create();
		OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetMainFunctionHelperPtr(this);

		Rendering::CameraManager::Create(); 

		m_Build.reset(new BuildType(information));
		m_Build->InitOpenGLGlutContext(argc,argv);
	}
	catch (CoreTools::Error& error)
	{
		System::MessageBoxSelectionWithTChar(error.GetError().c_str(),SYSTEM_TEXT("´íÎó"));
	}
	catch(std::runtime_error& error)
	{
		System::MessageBoxSelectionWithChar(error.what(), "´íÎó");
	}
	catch(...)
	{
		System::MessageBoxSelectionWithTChar(SYSTEM_TEXT("Î´Öª´íÎó£¡"),SYSTEM_TEXT("´íÎó"));
	}
}

template <template<typename > class Build,typename Process>
Framework::OpenGLGlutMainFunctionHelper<Build, Process>
     ::~OpenGLGlutMainFunctionHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;

	if(!IsDestroy())
	{
        Destroy();
	}
}

template <template<typename > class Build,typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
    ::Terminators()
{
	try
	{
		m_Build.reset();

		Rendering::CameraManager::Destroy();

		OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.ClearMainFunctionHelperPtr();

		OpenGLGlutProcessManager::Destroy();
	}
	catch (CoreTools::Error& error)
	{
		System::MessageBoxSelectionWithTChar(error.GetError().c_str(),SYSTEM_TEXT("´íÎó"));
	}
	catch(std::runtime_error& error)
	{
		System::MessageBoxSelectionWithChar(error.what(), "´íÎó");
	}
	catch(...)
	{
		System::MessageBoxSelectionWithTChar(SYSTEM_TEXT("Î´Öª´íÎó£¡"),SYSTEM_TEXT("´íÎó"));
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <template<typename > class Build,typename Process>
bool Framework::OpenGLGlutMainFunctionHelper<Build, Process>
     ::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <template<typename > class Build,typename Process>
int Framework::OpenGLGlutMainFunctionHelper<Build, Process>
     ::DoRun()
{
	return RunOpenGLGlutMainLoop();
}

template <template<typename > class Build,typename Process>
int Framework::OpenGLGlutMainFunctionHelper<Build, Process>
     ::RunOpenGLGlutMainLoop()
{
	m_Build->RunOpenGLGlutMainLoop();

	return 0;
}

template <template<typename > class Build,typename Process>
void Framework::OpenGLGlutMainFunctionHelper<Build, Process>
    ::Destroy()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(!IsDestroy())
	{
		Terminators();

		ParentType::Destroy();
	}
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_OPENGL_GLUT_MAIN_FUNCTION_HELPER_DETAIL_H
