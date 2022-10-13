///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 10:18)

#include "Rendering/RenderingExport.h"

#include "AnalysisRendererManager.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererBasis.h"

using boost::property_tree::ptree;
using boost::property_tree::ptree_error;
using std::string;

Rendering::AnalysisRendererManager::AnalysisRendererManager(const string& fileName)
    : renderer{ nullptr },
      fileName{ fileName },
      mainTree{},
      textureTree{},
      clearColorTree{},
      windowParameterTree{},
      rendererBasis{},
      rendererType{ RendererTypes::First }
{
    Analysis();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
void Rendering::AnalysisRendererManager::Analysis()
{
    AnalysisJson();
    AnalysisRendererType();
    AnalysisRendererTexture();

    if (Rendering::RendererTypes::First <= rendererType && rendererType < Rendering::RendererTypes::Max)
    {
        RendererParameter rendererParameter{ fileName };
        renderer = std::make_shared<Rendering::Renderer>(EnvironmentParameter::Create(), rendererParameter);
    }
    else
    {
        RendererParameter rendererParameter{ fileName };
        renderer = std::make_shared<Rendering::Renderer>(EnvironmentParameter::Create(), rendererParameter);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("初始化渲染器类型失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    renderer->Init();
}

// private
void Rendering::AnalysisRendererManager::AnalysisJson()
{
    read_json(fileName, mainTree);
}

// private
void Rendering::AnalysisRendererManager::AnalysisRendererType()
{
    rendererType = mainTree.get("RendererType", Rendering::RendererTypes::Default);
}

// private
void Rendering::AnalysisRendererManager::AnalysisRendererTexture()
{
    textureTree = mainTree.get_child("Texture");

    auto colorFormat = textureTree.get("ColorFormat", Rendering::DataFormatType::R8G8B8A8Typeless);
    auto depthStencilFormat = textureTree.get("DepthStencilFormat", Rendering::DataFormatType::D32Float);
    auto numMultisamples = textureTree.get("MultisamplesNumber", 0);

    if (Rendering::DataFormatType::Unknown <= colorFormat &&
        colorFormat < Rendering::DataFormatType::NumFormats &&
        Rendering::DataFormatType::Unknown <= depthStencilFormat &&
        depthStencilFormat < Rendering::DataFormatType::NumFormats &&
        0 <= numMultisamples)
    {
        rendererBasis.SetDataFormat(colorFormat, depthStencilFormat);
        rendererBasis.SetMultisamplesNumber(numMultisamples);
    }
    else
    {
        rendererBasis.SetDataFormat(Rendering::DataFormatType::R8G8B8A8Typeless, Rendering::DataFormatType::D32Float);
        rendererBasis.SetMultisamplesNumber(0);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("初始化渲染器纹理格式失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::AnalysisRendererManager::IsValid() const noexcept
{
    if (renderer != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::AnalysisRendererManager::RendererSharedPtr Rendering::AnalysisRendererManager::GetRenderer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderer;
}
