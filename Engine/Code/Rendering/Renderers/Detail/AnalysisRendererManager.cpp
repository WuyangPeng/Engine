///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:39)

#include "Rendering/RenderingExport.h"

#include "AnalysisRendererManager.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererBasis.h"

Rendering::AnalysisRendererManager::AnalysisRendererManager(const std::string& fileName)
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

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("��ʼ����Ⱦ������ʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
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
    rendererType = System::UnderlyingCastEnum<RendererTypes>(mainTree.get("RendererType", 0));
}

// private
void Rendering::AnalysisRendererManager::AnalysisRendererTexture()
{
    textureTree = mainTree.get_child("Texture");

    auto colorFormat = System::UnderlyingCastEnum<DataFormatType>(textureTree.get("ColorFormat", System::EnumCastUnderlying(Rendering::DataFormatType::R8G8B8A8Typeless)));
    auto depthStencilFormat = System::UnderlyingCastEnum<DataFormatType>(textureTree.get("DepthStencilFormat", System::EnumCastUnderlying(Rendering::DataFormatType::D32Float)));
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

        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("��ʼ����Ⱦ��������ʽʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
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
