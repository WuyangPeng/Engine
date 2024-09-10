/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/06 18:10)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_DIRECTORY_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_DIRECTORY_H

#include "System/Helper/EnumOperator.h"

namespace Framework
{
    enum class AnalysisDirectory
    {
        Null,
        Resource,
        Configuration,
        LittleEndian,
        BigEndian,
        Directory,
        Shader,
        Scene,
        Texture,
        Vertex,
        Image,
        Default,
        OpenGL,
        DirectX,
    };

    enum class UpperDirectory
    {
        Null,
        Resource = System::EnumCastUnderlying(AnalysisDirectory::Resource),
        Configuration = System::EnumCastUnderlying(AnalysisDirectory::Configuration),
    };

    enum class EndianDirectory
    {
        Null,
        LittleEndian = System::EnumCastUnderlying(AnalysisDirectory::LittleEndian),
        BigEndian = System::EnumCastUnderlying(AnalysisDirectory::BigEndian),
    };

    enum class RenderingAnalysisDirectory
    {
        Null,
        Directory = System::EnumCastUnderlying(AnalysisDirectory::Directory),
        Shader = System::EnumCastUnderlying(AnalysisDirectory::Shader),
        Scene = System::EnumCastUnderlying(AnalysisDirectory::Scene),
        Texture = System::EnumCastUnderlying(AnalysisDirectory::Texture),
        Vertex = System::EnumCastUnderlying(AnalysisDirectory::Vertex),
        Image = System::EnumCastUnderlying(AnalysisDirectory::Image),
    };

    enum class RenderingDirectory
    {
        Null,
        Default = System::EnumCastUnderlying(AnalysisDirectory::Default),
        OpenGL = System::EnumCastUnderlying(AnalysisDirectory::OpenGL),
        DirectX = System::EnumCastUnderlying(AnalysisDirectory::DirectX),
    };

    static_assert(System::EnumCastUnderlying(UpperDirectory::Resource) == System::EnumCastUnderlying(AnalysisDirectory::Resource));
    static_assert(System::EnumCastUnderlying(UpperDirectory::Configuration) == System::EnumCastUnderlying(AnalysisDirectory::Configuration));

    static_assert(System::EnumCastUnderlying(RenderingAnalysisDirectory::Directory) == System::EnumCastUnderlying(AnalysisDirectory::Directory));
    static_assert(System::EnumCastUnderlying(RenderingAnalysisDirectory::Shader) == System::EnumCastUnderlying(AnalysisDirectory::Shader));
    static_assert(System::EnumCastUnderlying(RenderingAnalysisDirectory::Scene) == System::EnumCastUnderlying(AnalysisDirectory::Scene));
    static_assert(System::EnumCastUnderlying(RenderingAnalysisDirectory::Texture) == System::EnumCastUnderlying(AnalysisDirectory::Texture));
    static_assert(System::EnumCastUnderlying(RenderingAnalysisDirectory::Vertex) == System::EnumCastUnderlying(AnalysisDirectory::Vertex));
    static_assert(System::EnumCastUnderlying(RenderingAnalysisDirectory::Image) == System::EnumCastUnderlying(AnalysisDirectory::Image));

    static_assert(System::EnumCastUnderlying(EndianDirectory::LittleEndian) == System::EnumCastUnderlying(AnalysisDirectory::LittleEndian));
    static_assert(System::EnumCastUnderlying(EndianDirectory::BigEndian) == System::EnumCastUnderlying(AnalysisDirectory::BigEndian));

    static_assert(System::EnumCastUnderlying(RenderingDirectory::Default) == System::EnumCastUnderlying(AnalysisDirectory::Default));
    static_assert(System::EnumCastUnderlying(RenderingDirectory::OpenGL) == System::EnumCastUnderlying(AnalysisDirectory::OpenGL));
    static_assert(System::EnumCastUnderlying(RenderingDirectory::DirectX) == System::EnumCastUnderlying(AnalysisDirectory::DirectX));
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_DIRECTORY_H