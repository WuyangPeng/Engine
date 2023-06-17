///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:39)

#include "Rendering/RenderingExport.h"

#include "AnalysisRendererParameter.h"
#include "RendererParameterImpl.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

using namespace std::literals;

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

// private
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

// private
void Rendering::AnalysisRendererParameter::AnalysisJson()
{
    read_json(fileName, mainTree);
}

// private
void Rendering::AnalysisRendererParameter::AnalysisRendererType()
{
    auto rendererType = System::UnderlyingCastEnum<RendererTypes>(mainTree.get("RendererType", 0));

    if (RendererTypes::First <= rendererType && rendererType < RendererTypes::Max)
    {
        rendererParameter->SetRendererType(rendererType);
    }
    else
    {
        rendererParameter->SetRendererType(RendererTypes::Default);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Rendering, SYSTEM_TEXT("初始化渲染器类型失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

// private
void Rendering::AnalysisRendererParameter::AnalysisRendererTexture()
{
    textureTree = mainTree.get_child("Texture");

    const auto colorFormat = System::UnderlyingCastEnum<DataFormatType>((textureTree.get("ColorFormat", System::EnumCastUnderlying(DataFormatType::R32G32B32A32Float))));
    const auto depthStencilFormat = System::UnderlyingCastEnum<DataFormatType>((textureTree.get("DepthStencilFormat", System::EnumCastUnderlying(DataFormatType::D24UNormS8UInt))));
    const auto numMultisamples = textureTree.get("MultisamplesNumber", 0);

    if (DataFormatType::Unknown < colorFormat &&
        colorFormat < DataFormatType::NumFormats &&
        DataFormatType::Unknown < depthStencilFormat &&
        depthStencilFormat < DataFormatType::NumFormats &&
        0 <= numMultisamples)
    {
        rendererParameter->SetTextureFormat(colorFormat, depthStencilFormat, numMultisamples);
    }
    else
    {
        rendererParameter->SetTextureFormat(DataFormatType::R32G32B32A32Float, DataFormatType::D24UNormS8UInt, 0);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Rendering, SYSTEM_TEXT("初始化渲染器纹理格式失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

// private
void Rendering::AnalysisRendererParameter::AnalysisRendererClearColor()
{
    clearColorTree = mainTree.get_child("ClearColor");

    auto red = clearColorTree.get("Red", 0.0f);
    auto green = clearColorTree.get("Green", 0.0f);
    auto blue = clearColorTree.get("Blue", 0.0f);
    auto alpha = clearColorTree.get("Alpha", 1.0f);

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

// private
void Rendering::AnalysisRendererParameter::AnalysisWindowParameter()
{
    windowParameterTree = mainTree.get_child("WindowParameter");

    auto windowTitle = windowParameterTree.get("WindowTitle", "WindowTitle");
    auto width = windowParameterTree.get("Width", 800);
    auto height = windowParameterTree.get("Height", 600);
    int x = windowParameterTree.get("X", 0);
    auto y = windowParameterTree.get("Y", 0);
    auto allowResize = windowParameterTree.get("AllowResize", true);

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
    auto className = windowParameterTree.get("ClassName", ""s);
    auto menuName = windowParameterTree.get("MenuName", ""s);

    rendererParameter->SetWindowClassName(CoreTools::StringConversion::MultiByteConversionStandard(className));
    rendererParameter->SetWindowMenuName(CoreTools::StringConversion::MultiByteConversionStandard(menuName));
}

void Rendering::AnalysisRendererParameter::AnalysisWindowPictorialParameter()
{
    auto icon = windowParameterTree.get("Icon", 0);
    auto isIconDefault = windowParameterTree.get("IconDefault", true);
    auto cursor = windowParameterTree.get("Cursor", 0);
    auto isCursorDefault = windowParameterTree.get("CursorDefault", true);
    auto background = windowParameterTree.get("Background", System::WindowsBrushTypes::Null);

    rendererParameter->SetWindowPictorialParameter(icon, isIconDefault, cursor, isCursorDefault, background);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, AnalysisRendererParameter)

Rendering::AnalysisRendererParameter::PackageType Rendering::AnalysisRendererParameter::GetRendererParameter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererParameter;
}
