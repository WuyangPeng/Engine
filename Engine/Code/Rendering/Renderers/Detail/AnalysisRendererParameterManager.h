// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:04)

#ifndef RENDERING_RENDERERS_ANALYSIS_RENDERER_PARAMETER_MANAGE_H
#define RENDERING_RENDERERS_ANALYSIS_RENDERER_PARAMETER_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include <string>

namespace Rendering
{
	class RendererParameterImpl;

	class RENDERING_HIDDEN_DECLARE AnalysisRendererParameterManager 
	{
	public:
		using ClassType = AnalysisRendererParameterManager;
		using RendererParameterPtr = std::shared_ptr<RendererParameterImpl>;

	public:
		explicit AnalysisRendererParameterManager(const std::string& fileName);	

		CLASS_INVARIANT_DECLARE;

		const RendererParameterPtr GetRendererParameterPtr() const;

	private:
		void Analysis();
		void AnalysisJson();
		void AnalysisRendererType();		 
		void AnalysisRendererTexture();	
		void AnalysisRendererClearColor();
		void AnalysisWindowParameter();

	private:
		RendererParameterPtr m_RendererParameterPtr;
		std::string m_FileName;
		boost::property_tree::ptree m_MainTree;
		boost::property_tree::ptree m_TextureTree;
		boost::property_tree::ptree m_ClearColorTree;
		boost::property_tree::ptree m_WindowParameterTree;
	};
}

#endif // RENDERING_RENDERERS_ANALYSIS_RENDERER_PARAMETER_MANAGE_H


