/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/17 10:17)

#include "Framework/FrameworkExport.h"

#include "RenderingManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Shaders/ProgramFactory.h"

Framework::RenderingManagerImpl::RenderingManagerImpl() noexcept
    : renderer{}, programFactory{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::RenderingManagerImpl::RenderingManagerImpl(RenderingManagerImpl&& rhs) noexcept
    : renderer{ std::move(rhs.renderer) }, programFactory{ std::move(rhs.programFactory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::RenderingManagerImpl& Framework::RenderingManagerImpl::operator=(RenderingManagerImpl&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    renderer = std::move(rhs.renderer);
    programFactory = std::move(rhs.programFactory);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, RenderingManagerImpl)

void Framework::RenderingManagerImpl::ResetRenderer(const std::string& fileName, const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;

    renderer = Renderer::Create(fileName, environmentParameter);
    renderer->InitDevice();

    programFactory = std::make_shared<ProgramFactory>(renderer->GetRendererType());
}

void Framework::RenderingManagerImpl::Resize(int width, int height)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer != nullptr)
    {
        renderer->Resize(width, height);
    }
    else
    {
        ThrowException();
    }
}

void Framework::RenderingManagerImpl::DrawFrameRate(int x, int y, const Colour& color, const std::string& message)
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

void Framework::RenderingManagerImpl::ClearBuffers()
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

Framework::RenderingManagerImpl::Colour Framework::RenderingManagerImpl::GetClearColor() const
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

void Framework::RenderingManagerImpl::SetClearColor(const Colour& colour)
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

void Framework::RenderingManagerImpl::Release()
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

void Framework::RenderingManagerImpl::SwapBuffers()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (renderer == nullptr)
    {
        ThrowException();
    }

    renderer->DisplayColorBuffer(0);
}

Framework::RenderingManagerImpl::ConstRendererSharedPtr Framework::RenderingManagerImpl::GetRenderer() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (renderer == nullptr)
    {
        ThrowException();
    }

    return renderer;
}

Framework::RenderingManagerImpl::RendererSharedPtr Framework::RenderingManagerImpl::GetRenderer()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<Renderer>(static_cast<const ClassType&>(*this).GetRenderer());
}

void Framework::RenderingManagerImpl::ThrowException()
{
    THROW_EXCEPTION(SYSTEM_TEXT("��Ⱦ��δ��ʼ��������Create�ж���Ⱦ�����г�ʼ����"s))
}