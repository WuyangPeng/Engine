///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 19:25)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_DESCRIPTION_FLAGS_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_DESCRIPTION_FLAGS_H

#include "Framework/MainFunctionHelper/Flags/Directory.h"

namespace Framework
{
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

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_DESCRIPTION_FLAGS_H