// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:25)

#include "Framework/FrameworkExport.h"

#include "WindowApplicationInformation.h"
#include "Detail/WindowApplicationInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::WindowApplicationInformation
	::WindowApplicationInformation( const System::String& windowTitle,const WindowSize& size, const WindowPoint& point,bool allowResize)
	:m_Impl(new ImplType(windowTitle,size,point,allowResize))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowApplicationInformation
	::WindowApplicationInformation( const System::String& windowTitle,const WindowSize& size )
	:m_Impl(new ImplType(windowTitle,size))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,WindowApplicationInformation)

DELAY_COPY_CONSTRUCTION_DEFINE(Framework,WindowApplicationInformation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowApplicationInformation,GetWindowTitle,const System::String&);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowApplicationInformation,GetWindowTitleWithMultiByte,const std::string);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowApplicationInformation,GetXPosition,int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowApplicationInformation,GetYPosition,int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowApplicationInformation,GetWidth,int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowApplicationInformation,GetHeight,int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowApplicationInformation,GetWindowSize,const Framework::WindowSize);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowApplicationInformation,GetAspectRatio,float); 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowApplicationInformation,GetStyle,System::WindowStyles);

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework, WindowApplicationInformation, SetWindowSize,WindowSize,void);