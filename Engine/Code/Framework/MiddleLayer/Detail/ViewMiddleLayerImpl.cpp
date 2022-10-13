///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/01 21:31)

#include "Framework/FrameworkExport.h"

#include "ViewMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Renderers/Renderer.h"

using std::string;

Framework::ViewMiddleLayerImpl::ViewMiddleLayerImpl() noexcept
    : renderer{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::ViewMiddleLayerImpl::ViewMiddleLayerImpl(ViewMiddleLayerImpl&& rhs) noexcept
    : renderer{ std::move(rhs.renderer) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::ViewMiddleLayerImpl& Framework::ViewMiddleLayerImpl::operator=(ViewMiddleLayerImpl&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    renderer = std::move(rhs.renderer);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ViewMiddleLayerImpl)

void Framework::ViewMiddleLayerImpl::ResetRenderer(const string& fileName, const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;

    renderer = Renderer::Create(fileName, environmentParameter);
    renderer->InitDevice();
}

void Framework::ViewMiddleLayerImpl::Resize(int width, int height)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer != nullptr)
    {
        renderer->Resize(width, height);
        renderer->ResetSize();
    }
    else
    {
        ThrowException();
    }
}

void Framework::ViewMiddleLayerImpl::DrawFrameRate(int x, int y, const Colour& color, const string& message)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer != nullptr)
    {
        if (renderer->PreDraw())
        {
            renderer->Draw(x, y, color, message);
            renderer->PostDraw();
        }
    }
    else
    {
        ThrowException();
    }
}

void Framework::ViewMiddleLayerImpl::ClearColorBuffer()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer != nullptr)
    {
        renderer->ClearColorBuffer();
    }
    else
    {
        ThrowException();
    }
}

Framework::ViewMiddleLayerImpl::Colour Framework::ViewMiddleLayerImpl::GetClearColor() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (renderer != nullptr)
    {
        return renderer->GetClearColor();
    }
    else
    {
        ThrowException();
    }
}

void Framework::ViewMiddleLayerImpl::SetClearColor(const Colour& colour)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer != nullptr)
    {
        return renderer->SetClearColor(colour);
    }
    else
    {
        ThrowException();
    }
}

Framework::ViewMiddleLayerImpl::RendererSharedPtr Framework::ViewMiddleLayerImpl::GetRenderer()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<Renderer>(static_cast<const ClassType&>(*this).GetRenderer());
}

void Framework::ViewMiddleLayerImpl::Release()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer != nullptr)
    {
        renderer->Release();
    }
    else
    {
        ThrowException();
    }
}

void Framework::ViewMiddleLayerImpl::SwapBuffers()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer == nullptr)
    {
        ThrowException();
    }

    renderer->SwapBuffers();
}

Framework::ViewMiddleLayerImpl::ConstRendererSharedPtr Framework::ViewMiddleLayerImpl::GetRenderer() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (renderer == nullptr)
    {
        ThrowException();
    }

    return renderer;
}

void Framework::ViewMiddleLayerImpl::ThrowException()
{
    THROW_EXCEPTION(SYSTEM_TEXT("渲染器未初始化！请在Create中对渲染器进行初始化。"s));
}