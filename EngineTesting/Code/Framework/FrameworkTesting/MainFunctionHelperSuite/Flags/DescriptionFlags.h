// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/28 09:51)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_DESCRIPTION_FLAGS_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_DESCRIPTION_FLAGS_H

#include "Framework/MainFunctionHelper/Flags/Directory.h"

namespace Framework
{
	enum class AnalysisDirectory;

	enum class Description
	{
		Resource = System::EnumCastUnderlying(AnalysisDirectory::Resource),
		Configuration = System::EnumCastUnderlying(AnalysisDirectory::Configuration),
		Directory = System::EnumCastUnderlying(AnalysisDirectory::Directory),
		LittleEndian = System::EnumCastUnderlying(AnalysisDirectory::LittleEndian),
		BigEndian = System::EnumCastUnderlying(AnalysisDirectory::BigEndian),
		Shader = System::EnumCastUnderlying(AnalysisDirectory::Shader),
		Scene = System::EnumCastUnderlying(AnalysisDirectory::Scene),
		Texture = System::EnumCastUnderlying(AnalysisDirectory::Texture),
		Vertex = System::EnumCastUnderlying(AnalysisDirectory::Vertex),
		Image = System::EnumCastUnderlying(AnalysisDirectory::Image),
		Default = System::EnumCastUnderlying(AnalysisDirectory::Default),
		OpenGL = System::EnumCastUnderlying(AnalysisDirectory::OpenGL),
		DirectX = System::EnumCastUnderlying(AnalysisDirectory::DirectX),
		Null,
		Framework,
		EngineEnvironment,		
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_DESCRIPTION_FLAGS_H