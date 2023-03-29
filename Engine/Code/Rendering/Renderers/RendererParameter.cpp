///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/05 20:48)

#include "Rendering/RenderingExport.h"

#include "RendererParameter.h"
#include "Flags/RendererTypes.h"
#include "Detail/AnalysisRendererParameter.h"
#include "Detail/RendererParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RendererParameter)

Rendering::RendererParameter::RendererParameter(const string& fileName)
    : impl{ CreateRendererParameter(fileName) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::RendererParameter::PackageType Rendering::RendererParameter::CreateRendererParameter(const string& fileName)
{
    try
    {
        AnalysisRendererParameter manager{ fileName };

        return manager.GetRendererParameter();
    }
    catch (const boost::property_tree::ptree_error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    return PackageType{ RendererTypes::Default };
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererParameter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetColorFormat, Rendering::DataFormatType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetDepthStencilFormat, Rendering::DataFormatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetNumMultisamples, int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetClearColor, Rendering::RendererParameter::ColourType);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererParameter, GetWindowTitle, string);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetXPosition, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetYPosition, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetWidth, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetHeight, int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, IsAllowResize, bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetRendererType, Rendering::RendererTypes);

void Rendering::RendererParameter::Resize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Resize(width, height);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetRendererBasis, Rendering::RendererBasis);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererParameter, GetWindowMenuName, System::String);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RendererParameter, GetWindowClassName, System::String);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetIcon, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, IsIconDefault, bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetCursor, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, IsCursorDefault, bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetBackground, System::WindowsBrushTypes);