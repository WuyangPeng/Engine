///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 14:36)

#include "Rendering/RenderingExport.h"

#include "RendererParameter.h"
#include "Detail/AnalysisRendererParameterManager.h"
#include "Detail/RendererParameterImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using boost::property_tree::ptree_error;
using std::string;

Rendering::RendererParameter::RendererParameter(const string& fileName)
    : impl{ RendererTypes::Default }
{
    DoLoadConfiguration(fileName);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::RendererParameter::DoLoadConfiguration(const string& fileName)
{
    try
    {
        AnalysisRendererParameterManager manager{ fileName };
        impl = manager.GetRendererParameterPtr();
    }
    catch (const ptree_error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << error.what()
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererParameter)

void Rendering::RendererParameter::LoadConfiguration(const string& fileName)
{
    RENDERING_CLASS_IS_VALID_1;

    DoLoadConfiguration(fileName);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RendererParameter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetColorFormat, Rendering::TextureFormat)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetDepthStencilFormat, Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetNumMultisamples, int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RendererParameter, GetClearColor, Rendering::RendererParameter::Colour);

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