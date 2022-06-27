///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 10:53)

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

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_DESCRIPTION_FLAGS_H