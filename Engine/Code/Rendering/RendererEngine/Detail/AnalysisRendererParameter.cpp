/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 16:05)

#include "Rendering/RenderingExport.h"

#include "AnalysisRendererParameter.h"
#include "RendererParameterImpl.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::AnalysisRendererParameter::AnalysisRendererParameter(const std::string& fileName)
    : rendererParameter{ RendererTypes::Default },
      fileName{ fileName },
      mainTree{},
      textureTree{},
      clearColorTree{},
      windowParameterTree{}
{
    Analysis();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::AnalysisRendererParameter::Analysis()
{
    AnalysisJson();
    AnalysisRendererType();
    AnalysisRendererTexture();
    AnalysisRendererClearColor();
    AnalysisWindowParameter();
    AnalysisWindowName();
    AnalysisWindowPictorialParameter();
}

void Rendering::AnalysisRendererParameter::AnalysisJson()
{
    read_json(fileName, mainTree);
}

void Rendering::AnalysisRendererParameter::AnalysisRendererType()
{
    if (const auto rendererType = System::UnderlyingCastEnum<RendererTypes>(mainTree.get("RendererType", 0));
        RendererTypes::First <= rendererType && rendererType < RendererTypes::Max)
    {
        rendererParameter->SetRendererType(rendererType);
    }
    else
    {
        rendererParameter->SetRendererType(RendererTypes::Default);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Rendering, SYSTEM_TEXT("初始化渲染器类型失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void Rendering::AnalysisRendererParameter::AnalysisRendererTexture()
{
    textureTree = mainTree.get_child("Texture");

    const auto colorFormat = System::UnderlyingCastEnum<DataFormatType>((textureTree.get("ColorFormat", System::EnumCastUnderlying(DataFormatType::R32G32B32A32Float))));
    const auto depthStencilFormat = System::UnderlyingCastEnum<DataFormatType>((textureTree.get("DepthStencilFormat", System::EnumCastUnderlying(DataFormatType::D24UNormS8UInt))));
    const auto numMultiSamples = textureTree.get("MultiSamplesNumber", 0);

    if (DataFormatType::Unknown < colorFormat &&
        colorFormat < DataFormatType::NumFormats &&
        DataFormatType::Unknown < depthStencilFormat &&
        depthStencilFormat < DataFormatType::NumFormats &&
        0 <= numMultiSamples)
    {
        rendererParameter->SetTextureFormat(colorFormat, depthStencilFormat, numMultiSamples);
    }
    else
    {
        rendererParameter->SetTextureFormat(DataFormatType::R32G32B32A32Float, DataFormatType::D24UNormS8UInt, 0);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Rendering, SYSTEM_TEXT("初始化渲染器纹理格式失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void Rendering::AnalysisRendererParameter::AnalysisRendererClearColor()
{
    clearColorTree = mainTree.get_child("ClearColor");

    const auto red = clearColorTree.get("Red", 0.0f);
    const auto green = clearColorTree.get("Green", 0.0f);
    const auto blue = clearColorTree.get("Blue", 0.0f);
    const auto alpha = clearColorTree.get("Alpha", 1.0f);

    if (0.0f <= red &&
        red <= 1.0f &&
        0.0f <= green &&
        green <= 1.0f &&
        0.0f <= blue &&
        blue <= 1.0f &&
        0.0f <= alpha &&
        alpha <= 1.0f)
    {
        rendererParameter->SetClearColor(red, green, blue, alpha);
    }
    else
    {
        rendererParameter->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Rendering, SYSTEM_TEXT("初始化渲染器清除颜色失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void Rendering::AnalysisRendererParameter::AnalysisWindowParameter()
{
    windowParameterTree = mainTree.get_child("WindowParameter");

    const auto windowTitle = windowParameterTree.get("WindowTitle", "WindowTitle");
    const auto width = windowParameterTree.get("Width", 800);
    const auto height = windowParameterTree.get("Height", 600);
    const auto x = windowParameterTree.get("X", 0);
    const auto y = windowParameterTree.get("Y", 0);
    const auto allowResize = windowParameterTree.get("AllowResize", true);

    if (0 < width && 0 < height)
    {
        rendererParameter->SetWindowParameter(windowTitle, width, height, x, y, allowResize);
    }
    else
    {
        rendererParameter->SetWindowParameter(windowTitle, 800, 600, x, y, allowResize);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Rendering, SYSTEM_TEXT("初始化窗口参数失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void Rendering::AnalysisRendererParameter::AnalysisWindowName()
{
    const auto className = windowParameterTree.get("ClassName", "");
    const auto menuName = windowParameterTree.get("MenuName", "");

    rendererParameter->SetWindowClassName(CoreTools::StringConversion::MultiByteConversionStandard(className));
    rendererParameter->SetWindowMenuName(CoreTools::StringConversion::MultiByteConversionStandard(menuName));
}

void Rendering::AnalysisRendererParameter::AnalysisWindowPictorialParameter()
{
    const auto icon = windowParameterTree.get("Icon", 0);
    const auto isIconDefault = windowParameterTree.get("IconDefault", true);
    const auto cursor = windowParameterTree.get("Cursor", 0);
    const auto isCursorDefault = windowParameterTree.get("CursorDefault", true);
    const auto background = windowParameterTree.get("Background", System::WindowsBrushTypes::Null);

    rendererParameter->SetWindowPictorialParameter(icon, isIconDefault, cursor, isCursorDefault, background);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, AnalysisRendererParameter)

Rendering::AnalysisRendererParameter::PackageType Rendering::AnalysisRendererParameter::GetRendererParameter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererParameter;
}
