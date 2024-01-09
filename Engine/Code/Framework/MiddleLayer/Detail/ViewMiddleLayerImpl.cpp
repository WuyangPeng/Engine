///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 14:52)

#include "Framework/FrameworkExport.h"

#include "ViewMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/RendererEngine/BaseRenderer.h"

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

void Framework::ViewMiddleLayerImpl::ResetRenderer(const std::string& fileName, const EnvironmentParameter& environmentParameter)
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

void Framework::ViewMiddleLayerImpl::DrawFrameRate(int x, int y, const Colour& color, const std::string& message)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer != nullptr)
    {
        if (!renderer->Draw(x, y, color, message))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework, SYSTEM_TEXT("Draw ʧ�ܡ�"));
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

void Framework::ViewMiddleLayerImpl::ClearBuffers()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer != nullptr)
    {
        renderer->ClearBuffers();
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

    renderer->DisplayColorBuffer(0);
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
    THROW_EXCEPTION(SYSTEM_TEXT("��Ⱦ��δ��ʼ��������Create�ж���Ⱦ�����г�ʼ����"s))
}