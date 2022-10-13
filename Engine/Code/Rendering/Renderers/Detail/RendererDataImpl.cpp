///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 14:13)

#include "Rendering/RenderingExport.h"

#include "AnalysisRendererManager.h"
#include "RendererDataImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererBasis.h"

using boost::property_tree::ptree_error;
using std::make_shared;
using namespace std::literals;

Rendering::RendererDataImpl::RendererDataImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : renderer{ make_shared<Renderer>(EnvironmentParameter::Create(), RendererParameter{ "" }) }
{
    renderer->Init();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::RendererDataImpl::IsValid() const noexcept
{
    if (renderer != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::RendererDataImpl::LoadConfiguration(const std::string& fileName)
{
    RENDERING_CLASS_IS_VALID_1;

    try
    {
        AnalysisRendererManager manager{ fileName };
        renderer = manager.GetRenderer();
    }
    catch (const ptree_error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << error.what()
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

void Rendering::RendererDataImpl::ClearColor()
{
    RENDERING_CLASS_IS_VALID_1;

    renderer->ClearColorBuffer();
}

void Rendering::RendererDataImpl::Resize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_1;

    renderer->Resize(width, height);
}

void Rendering::RendererDataImpl::DrawMessage(int x, int y, const Colour& color, const std::string& message)
{
    RENDERING_CLASS_IS_VALID_1;

    renderer->Draw(x, y, color, message);
}

Rendering::DataFormatType Rendering::RendererDataImpl::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderer->GetColorFormat();
}

Rendering::DataFormatType Rendering::RendererDataImpl::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderer->GetDepthStencilFormat();
}

int Rendering::RendererDataImpl::GetNumMultisamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderer->GetNumMultisamples();
}

Rendering::Colour<float> Rendering::RendererDataImpl::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderer->GetClearColor();
}

std::string Rendering::RendererDataImpl::GetWindowTitle() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ""s;
}

int Rendering::RendererDataImpl::GetXPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return 1024;
}

int Rendering::RendererDataImpl::GetYPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return 768;
}

int Rendering::RendererDataImpl::GetWidth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderer->GetWidth();
}

int Rendering::RendererDataImpl::GetHeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderer->GetHeight();
}

bool Rendering::RendererDataImpl::IsAllowResize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return true;
}

Rendering::RendererTypes Rendering::RendererDataImpl::GetRendererType() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return renderer->GetRendererType();
}
