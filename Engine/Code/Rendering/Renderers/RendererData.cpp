// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:25)

#include "Rendering/RenderingExport.h"

#include "RendererData.h"
#include "RendererInputData.h"
#include "Detail/RendererDataImpl.h"
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

Rendering::RendererData::RendererDataUniquePtr Rendering::RendererData::sm_RendererData{};

void Rendering::RendererData::Create()
{
    sm_RendererData = make_unique<Rendering::RendererData>(RendererDataCreate::Init);
}

void Rendering::RendererData::Destroy() noexcept
{
    sm_RendererData.reset();
}

Rendering::RendererData::RendererData([[maybe_unused]] RendererDataCreate rendererDataCreate)
    : impl{0}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererData)

void Rendering::RendererData::LoadConfiguration(const string& fileName)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    impl->LoadConfiguration(fileName);
    CAMERA_MANAGE_SINGLETON.SetDefaultDepthType(impl->GetRendererType());
    RENDERER_INPUT_DATA_SINGLETON.Rebuild(impl->GetRendererType());
}

void Rendering::RendererData::ClearColor()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->ClearColor();
}

void Rendering::RendererData::Resize(int width, int height)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->Resize(width, height);
}

void Rendering::RendererData::DrawMessage(int x, int y, const Colour& color, const std::string& message)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->DrawMessage(x, y, color, message);
}

Rendering::TextureFormat Rendering::RendererData::GetColorFormat() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetColorFormat();
}

Rendering::TextureFormat Rendering::RendererData::GetDepthStencilFormat() const
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

const std::string Rendering::RendererData::GetWindowTitle() const
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
