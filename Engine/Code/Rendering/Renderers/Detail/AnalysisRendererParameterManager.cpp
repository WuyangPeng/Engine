///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 10:45)

#include "Rendering/RenderingExport.h"

#include "AnalysisRendererParameterManager.h"
#include "RendererParameterImpl.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

using boost::property_tree::ptree;
using boost::property_tree::ptree_error;
using std::string;
using namespace std::literals;

Rendering::AnalysisRendererParameterManager::AnalysisRendererParameterManager(const string& fileName)
    : rendererParameter{ nullptr }, fileName{ fileName }, mainTree{}, textureTree{}, clearColorTree{}, windowParameterTree{}
{
    Analysis();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
void Rendering::AnalysisRendererParameterManager::Analysis()
{
    AnalysisJson();
    AnalysisRendererType();
    AnalysisRendererTexture();
    AnalysisRendererClearColor();
    AnalysisWindowParameter();
}

// private
void Rendering::AnalysisRendererParameterManager::AnalysisJson()
{
    read_json(fileName, mainTree);
}

// private
void Rendering::AnalysisRendererParameterManager::AnalysisRendererType()
{
    auto rendererType = mainTree.get("RendererType", Rendering::RendererTypes::Default);

    if (Rendering::RendererTypes::First <= rendererType && rendererType < Rendering::RendererTypes::Max)
    {
        rendererParameter = std::make_shared<RendererParameterImpl>(rendererType);
    }
    else
    {
        rendererParameter = std::make_shared<RendererParameterImpl>(RendererTypes::Default);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("初始化渲染器类型失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
void Rendering::AnalysisRendererParameterManager::AnalysisRendererTexture()
{
    textureTree = mainTree.get_child("Texture");

    auto colorFormat = (textureTree.get("ColorFormat", Rendering::TextureFormat::A8R8G8B8));
    auto depthStencilFormat = (textureTree.get("DepthStencilFormat", Rendering::TextureFormat::D24S8));
    auto numMultisamples = textureTree.get("MultisamplesNumber", 0);

    if (Rendering::TextureFormat::First <= colorFormat &&
        colorFormat < Rendering::TextureFormat::Max &&
        Rendering::TextureFormat::First <= depthStencilFormat &&
        depthStencilFormat < Rendering::TextureFormat::Max &&
        0 <= numMultisamples)
    {
        rendererParameter->SetTextureFormat(colorFormat, depthStencilFormat, numMultisamples);
    }
    else
    {
        rendererParameter->SetTextureFormat(TextureFormat::DefaultColour, TextureFormat::DefaultDepth, 0);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("初始化渲染器纹理格式失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
void Rendering::AnalysisRendererParameterManager::AnalysisRendererClearColor()
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

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("初始化渲染器清除颜色失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
void Rendering::AnalysisRendererParameterManager::AnalysisWindowParameter()
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

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("初始化窗口参数失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    auto className = windowParameterTree.get("ClassName", ""s);
    auto menuName = windowParameterTree.get("MenuName", ""s);

    rendererParameter->SetWindowClassName(CoreTools::StringConversion::MultiByteConversionStandard(className));
    rendererParameter->SetWindowMenuName(CoreTools::StringConversion::MultiByteConversionStandard(menuName));

    auto icon = windowParameterTree.get("Icon", 0);
    auto isIconDefault = windowParameterTree.get("IconDefault", true);
    auto cursor = windowParameterTree.get("Cursor", 0);
    auto isCursorDefault = windowParameterTree.get("CursorDefault", true);
    auto background = System::UnderlyingCastEnum<System::WindowsBrushTypes>(windowParameterTree.get("Background", 0));

    rendererParameter->SetWindowPictorialParameter(icon, isIconDefault, cursor, isCursorDefault, background);
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::AnalysisRendererParameterManager::IsValid() const noexcept
{
    if (rendererParameter != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::AnalysisRendererParameterManager::RendererParameterSharedPtr Rendering::AnalysisRendererParameterManager::GetRendererParameterPtr() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return rendererParameter;
}
