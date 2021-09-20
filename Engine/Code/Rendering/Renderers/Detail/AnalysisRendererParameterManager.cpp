// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 17:22)

#include "Rendering/RenderingExport.h"

#include "AnalysisRendererParameterManager.h"
#include "RendererParameterImpl.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 
#include "CoreTools/CharacterString/StringConversion.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26493)
using std::string;
using boost::property_tree::ptree;
using boost::property_tree::ptree_error;
using namespace std::literals;

Rendering::AnalysisRendererParameterManager
	::AnalysisRendererParameterManager( const string& fileName )
	:m_RendererParameterPtr{ nullptr }, m_FileName{ fileName },m_MainTree{}, m_TextureTree{}, m_ClearColorTree{},m_WindowParameterTree{}
{
	Analysis();

	RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
void Rendering::AnalysisRendererParameterManager
	::Analysis()
{
	AnalysisJson();
	AnalysisRendererType();
	AnalysisRendererTexture();
	AnalysisRendererClearColor();
	AnalysisWindowParameter();
}

// private
void Rendering::AnalysisRendererParameterManager
	::AnalysisJson()
{
	read_json(m_FileName,m_MainTree);
}

// private
void Rendering::AnalysisRendererParameterManager
	::AnalysisRendererType()
{
	auto rendererType = Rendering::RendererTypes(m_MainTree.get("RendererType",0));

	if(Rendering::RendererTypes::First <= rendererType && rendererType < Rendering::RendererTypes::Max)
	{
		m_RendererParameterPtr = std::make_shared<RendererParameterImpl>(rendererType);	 
	}
	else
	{
		m_RendererParameterPtr = std::make_shared<RendererParameterImpl>(RendererTypes::Default);
 
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			 << SYSTEM_TEXT("初始化渲染器类型失败！")
			 << CoreTools::LogAppenderIOManageSign::TriggerAssert;
	}
}

// private
void Rendering::AnalysisRendererParameterManager
	::AnalysisRendererTexture()
{
	m_TextureTree = m_MainTree.get_child("Texture");		
 
	auto colorFormat = Rendering::TextureFormat(m_TextureTree.get("ColorFormat",8));
	auto depthStencilFormat = Rendering::TextureFormat(m_TextureTree.get("DepthStencilFormat",22));
	auto numMultisamples = m_TextureTree.get("MultisamplesNumber",0);

	if(Rendering::TextureFormat::First <= colorFormat && colorFormat < Rendering::TextureFormat::Max && 
   	   Rendering::TextureFormat::First <= depthStencilFormat && depthStencilFormat < Rendering::TextureFormat::Max && 0 <= numMultisamples)
	{
		m_RendererParameterPtr->SetTextureFormat(colorFormat, depthStencilFormat, numMultisamples);
	}
	else
	{ 
		m_RendererParameterPtr->SetTextureFormat(TextureFormat::DefaultColour,TextureFormat::DefaultDepth, 0);

		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			 << SYSTEM_TEXT("初始化渲染器纹理格式失败！")
			 << CoreTools::LogAppenderIOManageSign::TriggerAssert;
	}	
} 

// private
void Rendering::AnalysisRendererParameterManager
	::AnalysisRendererClearColor()
{
	m_ClearColorTree = m_MainTree.get_child("ClearColor");	

	auto red = m_ClearColorTree.get("Red",0.0f);
	auto green = m_ClearColorTree.get("Green",0.0f);
	auto blue = m_ClearColorTree.get("Blue",0.0f);
	auto alpha = m_ClearColorTree.get("Alpha",1.0f);

    if(0.0f <= red && red <= 1.0f && 0.0f <= green && green <= 1.0f && 
       0.0f <= blue && blue <= 1.0f && 0.0f <= alpha && alpha <= 1.0f)
    {
        m_RendererParameterPtr->SetClearColor(red, green, blue, alpha);
    }
    else
    {
        m_RendererParameterPtr->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			 << SYSTEM_TEXT("初始化渲染器清除颜色失败！")
			 << CoreTools::LogAppenderIOManageSign::TriggerAssert;
    }	
}

// private
void Rendering::AnalysisRendererParameterManager
	::AnalysisWindowParameter()
{
	m_WindowParameterTree = m_MainTree.get_child("WindowParameter");

	auto windowTitle = m_WindowParameterTree.get("WindowTitle","WindowTitle");
	auto width = m_WindowParameterTree.get("Width",800);
	auto height = m_WindowParameterTree.get("Height",600);
    int x = m_WindowParameterTree.get("X",0);
	auto y = m_WindowParameterTree.get("Y",0);
	auto allowResize = m_WindowParameterTree.get("AllowResize",true);

	if(0 < width && 0 < height)
	{
		m_RendererParameterPtr->SetWindowParameter(windowTitle,width,height,x,y, allowResize);
	}
	else
	{ 
		m_RendererParameterPtr->SetWindowParameter(windowTitle,800,600,x,y, allowResize);

		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			 << SYSTEM_TEXT("初始化窗口参数失败！")
			 << CoreTools::LogAppenderIOManageSign::TriggerAssert;
	}

	auto className = m_WindowParameterTree.get("ClassName", ""s);
	auto menuName = m_WindowParameterTree.get("MenuName", ""s);

	m_RendererParameterPtr->SetWindowClassName(CoreTools::StringConversion::MultiByteConversionStandard(className));
	m_RendererParameterPtr->SetWindowMenuName(CoreTools::StringConversion::MultiByteConversionStandard(menuName));


	int icon = m_WindowParameterTree.get("Icon", 0);
	bool isIconDefault = m_WindowParameterTree.get("IconDefault",true);
	int cursor = m_WindowParameterTree.get("Cursor", 0);
	bool isCursorDefault = m_WindowParameterTree.get("CursorDefault", true);
	System::WindowsBrushTypes background = System::UnderlyingCastEnum<System::WindowsBrushTypes>(m_WindowParameterTree.get("Background", 0));

	m_RendererParameterPtr->SetWindowPictorialParameter(icon, isIconDefault, cursor, isCursorDefault, background);
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::AnalysisRendererParameterManager
	::IsValid() const noexcept
{
	if(m_RendererParameterPtr != nullptr)
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const Rendering::AnalysisRendererParameterManager::RendererParameterPtr	Rendering::AnalysisRendererParameterManager
	::GetRendererParameterPtr() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_RendererParameterPtr;
}
#include STSTEM_WARNING_POP
