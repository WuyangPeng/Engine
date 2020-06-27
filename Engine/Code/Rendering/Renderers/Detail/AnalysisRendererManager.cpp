// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 17:16)

#include "Rendering/RenderingExport.h"

#include "AnalysisRendererManager.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"

using std::string;
using boost::property_tree::ptree;
using boost::property_tree::ptree_error;

Rendering::AnalysisRendererManager
	::AnalysisRendererManager( const string& fileName )
	:m_RendererPtr{ nullptr }, m_FileName{ fileName }, m_MainTree{}, m_TextureTree{}, 
	m_ClearColorTree{}, m_WindowParameterTree{}, m_RendererBasis{}, m_RendererType{ RendererTypes::First }
{
	Analysis();

	RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
void Rendering::AnalysisRendererManager
	::Analysis()
{
	AnalysisJson();
	AnalysisRendererType();
	AnalysisRendererTexture();
	AnalysisRendererClearColor();
	AnalysisWindowParameter();

	if (Rendering::RendererTypes::First <= m_RendererType && m_RendererType < Rendering::RendererTypes::Max)
	{
		m_RendererPtr = std::make_shared<Rendering::Renderer>(m_RendererType, m_RendererBasis);		
	}
	else
	{
		m_RendererPtr = std::make_shared<Rendering::Renderer>(Rendering::RendererTypes::Default, m_RendererBasis);

		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< SYSTEM_TEXT("初始化渲染器类型失败！")
			<< CoreTools::LogAppenderIOManageSign::TriggerAssert;
	}	

	m_RendererPtr->Init();
}

// private
void Rendering::AnalysisRendererManager
	::AnalysisJson()
{
	read_json(m_FileName,m_MainTree);
}

// private
void Rendering::AnalysisRendererManager
	::AnalysisRendererType()
{
	m_RendererType = Rendering::RendererTypes(m_MainTree.get("RendererType",0));
}

// private
void Rendering::AnalysisRendererManager
	::AnalysisRendererTexture()
{
	m_TextureTree = m_MainTree.get_child("Texture");		
 
	auto colorFormat = Rendering::TextureFormat(m_TextureTree.get("ColorFormat",8));
	auto depthStencilFormat = Rendering::TextureFormat(m_TextureTree.get("DepthStencilFormat",22));
	int numMultisamples = m_TextureTree.get("MultisamplesNumber",0);

	if(Rendering::TextureFormat::First <= colorFormat && colorFormat < Rendering::TextureFormat::Max && 
   	   Rendering::TextureFormat::First <= depthStencilFormat && depthStencilFormat < Rendering::TextureFormat::Max && 0 <= numMultisamples)
	{
		m_RendererBasis.SetTextureFormat(colorFormat, depthStencilFormat);
		m_RendererBasis.SetMultisamplesNumber(numMultisamples);
	}
	else
	{ 
		m_RendererBasis.SetTextureFormat(Rendering::TextureFormat::A8R8G8B8,Rendering::TextureFormat::D24S8);
		m_RendererBasis.SetMultisamplesNumber(0);

		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			 << SYSTEM_TEXT("初始化渲染器纹理格式失败！")
			 << CoreTools::LogAppenderIOManageSign::TriggerAssert;
	}	
} 

// private
void Rendering::AnalysisRendererManager
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
		// m_RendererParameter.SetClearColor(red, green, blue, alpha);
    }
    else
    {
	//	m_RendererParameter.SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			 << SYSTEM_TEXT("初始化渲染器清除颜色失败！")
			 << CoreTools::LogAppenderIOManageSign::TriggerAssert;
    }	
}

// private
void Rendering::AnalysisRendererManager
	::AnalysisWindowParameter()
{
	m_WindowParameterTree = m_MainTree.get_child("WindowParameter");

    string windowTitle = m_WindowParameterTree.get("WindowTitle","WindowTitle");
    int width = m_WindowParameterTree.get("Width",800);
    int height = m_WindowParameterTree.get("Height",600);
 //   int x = m_WindowParameterTree.get("X",0);
  //  int y = m_WindowParameterTree.get("Y",0);
   // bool allowResize = m_WindowParameterTree.get("AllowResize",true);

	if(0 < width && 0 < height)
	{
		//m_RendererParameter.SetWindowParameter(windowTitle, width, height,    x,y, allowResize);
	}
	else
	{ 
		//m_RendererParameter.SetWindowParameter(windowTitle, 800, 600,  x,y, allowResize);

		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			 << SYSTEM_TEXT("初始化窗口参数失败！")
			 << CoreTools::LogAppenderIOManageSign::TriggerAssert;
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::AnalysisRendererManager
	::IsValid() const noexcept
{
	if(m_RendererPtr != nullptr)
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Rendering::AnalysisRendererManager::RendererPtr	Rendering::AnalysisRendererManager
	::GetRendererPtr() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_RendererPtr;
}

