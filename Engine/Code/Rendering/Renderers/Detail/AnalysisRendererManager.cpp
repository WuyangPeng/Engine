///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/20 10:18)

#include "Rendering/RenderingExport.h"

#include "AnalysisRendererManager.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
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
        renderer = std::make_shared<Rendering::Renderer>(rendererType, rendererBasis);
    }
    else
    {
        renderer = std::make_shared<Rendering::Renderer>(Rendering::RendererTypes::Default, rendererBasis);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("��ʼ����Ⱦ������ʧ�ܣ�")
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

    auto colorFormat = textureTree.get("ColorFormat", Rendering::TextureFormat::A8R8G8B8);
    auto depthStencilFormat = textureTree.get("DepthStencilFormat", Rendering::TextureFormat::D24S8);
    auto numMultisamples = textureTree.get("MultisamplesNumber", 0);

    if (Rendering::TextureFormat::First <= colorFormat &&
        colorFormat < Rendering::TextureFormat::Max &&
        Rendering::TextureFormat::First <= depthStencilFormat &&
        depthStencilFormat < Rendering::TextureFormat::Max &&
        0 <= numMultisamples)
    {
        rendererBasis.SetTextureFormat(colorFormat, depthStencilFormat);
        rendererBasis.SetMultisamplesNumber(numMultisamples);
    }
    else
    {
        rendererBasis.SetTextureFormat(Rendering::TextureFormat::A8R8G8B8, Rendering::TextureFormat::D24S8);
        rendererBasis.SetMultisamplesNumber(0);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("��ʼ����Ⱦ��������ʽʧ�ܣ�")
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
