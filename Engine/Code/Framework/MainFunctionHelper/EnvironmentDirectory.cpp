// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:55)

#include "Framework/FrameworkExport.h"

#include "EnvironmentDirectory.h" 
#include "Detail/EnvironmentDirectoryImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::EnvironmentDirectory
	::EnvironmentDirectory(const System::String& engineEnvironment)
	:m_Impl(new ImplType(engineEnvironment))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,EnvironmentDirectory);

DELAY_COPY_CONSTRUCTION_DEFINE(Framework,EnvironmentDirectory);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,EnvironmentDirectory,GetEngineEnvironment,const System::String);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,EnvironmentDirectory,GetEngineDirectory,const System::String);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,EnvironmentDirectory,GetResourcePath,const System::String);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,EnvironmentDirectory,GetConfigurationPath,const System::String);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,EnvironmentDirectory,GetShaderPath,const System::String);	
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,EnvironmentDirectory,GetScenePath,const System::String);	
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,EnvironmentDirectory,GetTexturePath,const System::String);		
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,EnvironmentDirectory,GetVertexPath,const System::String);		
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,EnvironmentDirectory,GetImagePath,const System::String);				

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework,EnvironmentDirectory,SetResourcePath,System::String,void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework,EnvironmentDirectory,SetConfigurationPath,System::String,void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework,EnvironmentDirectory,SetShaderPath,System::String,void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework,EnvironmentDirectory,SetScenePath,System::String,void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework,EnvironmentDirectory,SetTexturePath,System::String,void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework,EnvironmentDirectory,SetVertexPath,System::String,void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework,EnvironmentDirectory,SetImagePath,System::String,void)

