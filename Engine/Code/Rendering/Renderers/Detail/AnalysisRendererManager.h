// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:04)

#ifndef FRAMEWORK_APPLICATION_ANALYSIS_RENDERER_MANAGE_H
#define FRAMEWORK_APPLICATION_ANALYSIS_RENDERER_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

#include <boost/property_tree/ptree.hpp> 
#include <string>

namespace Rendering
{
	class Renderer;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE AnalysisRendererManager 
	{
	public:
		using ClassType = AnalysisRendererManager;
		using RendererPtr = std::shared_ptr<Rendering::Renderer>;

	public:
		explicit AnalysisRendererManager(const std::string& fileName);	

		CLASS_INVARIANT_DECLARE;

		RendererPtr GetRendererPtr() const;

	private:
		void Analysis();
		void AnalysisJson();
		void AnalysisRendererType();		 
		void AnalysisRendererTexture();	
		void AnalysisRendererClearColor();
		void AnalysisWindowParameter();

	private:
		RendererPtr m_RendererPtr;
		std::string m_FileName;
		boost::property_tree::ptree m_MainTree;
		boost::property_tree::ptree m_TextureTree;
		boost::property_tree::ptree m_ClearColorTree;
		boost::property_tree::ptree m_WindowParameterTree;

		RendererBasis m_RendererBasis;
		RendererTypes m_RendererType;	 
	};
}

#endif // FRAMEWORK_APPLICATION_ANALYSIS_RENDERER_MANAGE_H


