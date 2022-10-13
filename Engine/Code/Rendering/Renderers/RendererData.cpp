///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 19:10)

#include "Rendering/RenderingExport.h"

#include "RendererData.h"
#include "RendererInputData.h"
#include "Detail/RendererDataImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "Rendering/SceneGraph/CameraManager.h"

using std::make_shared;
using std::make_unique;
using std::string;

SINGLETON_GET_PTR_DEFINE(Rendering, RendererData);

Rendering::RendererData::RendererDataUniquePtr Rendering::RendererData::rendererData{};

void Rendering::RendererData::Create()
{
    rendererData = make_unique<Rendering::RendererData>(RendererDataCreate::Init);
}

void Rendering::RendererData::Destroy() noexcept
{
    rendererData.reset();
}

Rendering::RendererData::RendererData(MAYBE_UNUSED RendererDataCreate rendererDataCreate)
    : impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererData)

void Rendering::RendererData::LoadConfiguration(const string& fileName)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    impl->LoadConfiguration(fileName);
    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(impl->GetRendererType());
    RENDERER_INPUT_DATA_SINGLETON.Rebuild(impl->GetRendererType());
}

void Rendering::RendererData::ClearColor()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->ClearColor();
}

void Rendering::RendererData::Resize(int width, int height)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->Resize(width, height);
}

void Rendering::RendererData::DrawMessage(int x, int y, const Colour& color, const std::string& message)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    return impl->DrawMessage(x, y, color, message);
}

Rendering::DataFormatType Rendering::RendererData::GetColorFormat() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetColorFormat();
}

Rendering::DataFormatType Rendering::RendererData::GetDepthStencilFormat() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDepthStencilFormat();
}

int Rendering::RendererData::GetNumMultisamples() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumMultisamples();
}

Rendering::RendererData::Colour Rendering::RendererData::GetClearColor() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetClearColor();
}

std::string Rendering::RendererData::GetWindowTitle() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWindowTitle();
}

int Rendering::RendererData::GetXPosition() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetXPosition();
}

int Rendering::RendererData::GetYPosition() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetYPosition();
}

int Rendering::RendererData::GetWidth() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWidth();
}

int Rendering::RendererData::GetHeight() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetHeight();
}

bool Rendering::RendererData::IsAllowResize() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->IsAllowResize();
}
