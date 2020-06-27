// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:32)

#include "Rendering/RenderingExport.h"

#include "RendererParameter.h"
#include "Detail/RendererParameterImpl.h"
#include "Detail/AnalysisRendererParameterManager.h" 
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using boost::property_tree::ptree_error;

Rendering::RendererParameter
	::RendererParameter(const string& fileName)
	:m_Impl{}
{
	DoLoadConfiguration(fileName); 

	RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::RendererParameter
	::DoLoadConfiguration(const string& fileName)
{
	try
	{
		AnalysisRendererParameterManager manager{ fileName };
	    m_Impl = manager.GetRendererParameterPtr();
	}
	catch (ptree_error& error)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< error.what()
			<< CoreTools::LogAppenderIOManageSign::TriggerAssert;	
	}
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,RendererParameter)


DELAY_COPY_CONSTRUCTION_DEFINE(Rendering, RendererParameter)

void Rendering::RendererParameter
	::LoadConfiguration(const string& fileName)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	DoLoadConfiguration(fileName);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetColorFormat,Rendering::TextureFormat)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetDepthStencilFormat,Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetNumMultisamples,int); 
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetClearColor,Rendering::RendererParameter::Colour);  

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetWindowTitle,const string); 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetXPosition,int);  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetYPosition,int);  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetWidth,int); 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetHeight,int); 
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,IsAllowResize,bool); 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetRendererType,Rendering::RendererTypes);  

 

void Rendering::RendererParameter
	::Resize( int width,int height )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Resize(width,height);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RendererParameter,GetRendererBasis,const Rendering::RendererBasis);  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererParameter, GetWindowMenuName, System::String);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererParameter, GetWindowClassName, System::String);
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererParameter, GetIcon, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererParameter, IsIconDefault, bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererParameter, GetCursor, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererParameter, IsCursorDefault, bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererParameter, GetBackground, System::WindowBrushTypes); 