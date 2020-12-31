// Copyright (c) 2010-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.3.0.1 (2020/05/29 11:22)

#include "Framework/FrameworkExport.h"

#include "EnvironmentDirectory.h" 
#include "Detail/EnvironmentDirectoryImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::EnvironmentDirectory
	::EnvironmentDirectory(const String& engineEnvironment, const String& engineDirectory)
	:m_Impl{ make_shared<ImplType>(engineEnvironment,engineDirectory) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, EnvironmentDirectory)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, EnvironmentDirectory, GetEngineEnvironment, const System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, EnvironmentDirectory, GetEngineDirectory, const System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, EnvironmentDirectory, GetDirectory, UpperDirectory, const System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, EnvironmentDirectory, GetPath, RenderingAnalysisDirectory, const System::String)

const System::String Framework::EnvironmentDirectory
	::GetPath(RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPath(renderingDirectory, analysisDirectory);
}

const System::String Framework::EnvironmentDirectory
	::GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPath(endianDirectory, renderingDirectory, analysisDirectory);
}
