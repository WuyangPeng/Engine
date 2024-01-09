/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 16:21)

#include "Rendering/RenderingExport.h"

#include "RendererParameter.h"
#include "Flags/RendererTypes.h"
#include "Detail/AnalysisRendererParameter.h"
#include "Detail/RendererParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RendererParameter)

Rendering::RendererParameter::RendererParameter(const std::string& fileName)
    : impl{ CreateRendererParameter(fileName) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::RendererParameter::PackageType Rendering::RendererParameter::CreateRendererParameter(const std::string& fileName)
{
    try
    {
        const AnalysisRendererParameter manager{ fileName };

        return manager.GetRendererParameter();
    }
    catch (const boost::property_tree::ptree_error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    return PackageType{ RendererTypes::Default };
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererParameter)

void Rendering::RendererParameter::Resize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Resize(width, height);
}

Rendering::RendererTypes Rendering::RendererParameter::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRendererType();
}

Rendering::DataFormatType Rendering::RendererParameter::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetColorFormat();
}

Rendering::DataFormatType Rendering::RendererParameter::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDepthStencilFormat();
}

int Rendering::RendererParameter::GetNumMultiSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumMultiSamples();
}

Rendering::RendererParameter::ColourType Rendering::RendererParameter::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetClearColor();
}

std::string Rendering::RendererParameter::GetWindowTitle() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowTitle();
}

int Rendering::RendererParameter::GetXPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetXPosition();
}

int Rendering::RendererParameter::GetYPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetYPosition();
}

int Rendering::RendererParameter::GetWidth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWidth();
}

int Rendering::RendererParameter::GetHeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetHeight();
}

bool Rendering::RendererParameter::IsAllowResize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsAllowResize();
}

Rendering::RendererBasis Rendering::RendererParameter::GetRendererBasis() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRendererBasis();
}

Rendering::RendererParameter::String Rendering::RendererParameter::GetWindowMenuName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowMenuName();
}

Rendering::RendererParameter::String Rendering::RendererParameter::GetWindowClassName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowClassName();
}

int Rendering::RendererParameter::GetIcon() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIcon();
}

bool Rendering::RendererParameter::IsIconDefault() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsIconDefault();
}

int Rendering::RendererParameter::GetCursor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCursor();
}

bool Rendering::RendererParameter::IsCursorDefault() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsCursorDefault();
}

Rendering::RendererParameter::WindowsBrushTypes Rendering::RendererParameter::GetBackground() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBackground();
}