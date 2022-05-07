///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:17)

#include "Framework/FrameworkExport.h"

#include "ViewMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Renderers/Renderer.h"

using std::const_pointer_cast;
using std::make_shared;
using std::move;
using std::string;
using namespace std::literals;

Framework::ViewMiddleLayerImpl::ViewMiddleLayerImpl() noexcept
    : renderer{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::ViewMiddleLayerImpl::ViewMiddleLayerImpl(ViewMiddleLayerImpl&& rhs) noexcept
    : renderer{ move(rhs.renderer) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::ViewMiddleLayerImpl& Framework::ViewMiddleLayerImpl::operator=(ViewMiddleLayerImpl&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    renderer = move(rhs.renderer);

    return *this;
}

void Framework::ViewMiddleLayerImpl::ResetRenderer(const string& fileName)
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;

    renderer = make_shared<Renderer>(fileName);
    renderer->Init();
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ViewMiddleLayerImpl)

void Framework::ViewMiddleLayerImpl::Resize(int width, int height)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer)
    {
        renderer->Resize(width, height);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("渲染器未初始化！"s));
    }
}

void Framework::ViewMiddleLayerImpl::DrawFrameRate(int x, int y, const Colour& color, const string& message)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer)
    {
        if (renderer->PreDraw())
        {
            renderer->Draw(x, y, color, message);
            renderer->PostDraw();
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("渲染器未初始化！"s));
    }
}

void Framework::ViewMiddleLayerImpl::ClearColorBuffer()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer)
    {
        renderer->ClearColorBuffer();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("渲染器未初始化！"s));
    }
}

Framework::ViewMiddleLayerImpl::RendererSharedPtr Framework::ViewMiddleLayerImpl::GetRenderer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return const_pointer_cast<Renderer>(static_cast<const ClassType*>(this)->GetRenderer());

#include STSTEM_WARNING_POP
}

Framework::ViewMiddleLayerImpl::ConstRendererSharedPtr Framework::ViewMiddleLayerImpl::GetRenderer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return renderer;
}

Framework::ViewMiddleLayerImpl::Colour Framework::ViewMiddleLayerImpl::GetClearColor() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (renderer)
    {
        return renderer->GetClearColor();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("渲染器未初始化！"s));
    }
}

void Framework::ViewMiddleLayerImpl::SetClearColor(const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer)
    {
        return renderer->SetClearColor(colour);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("渲染器未初始化！"s));
    }
}
