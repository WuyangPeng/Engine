/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/17 10:17)

#ifndef FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/RendererEngine/BaseRenderer.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE RenderingManagerImpl
    {
    public:
        using ClassType = RenderingManagerImpl;

        using Colour = Rendering::Colour<float>;
        using Renderer = Rendering::BaseRenderer;
        using RendererSharedPtr = Rendering::BaseRendererSharedPtr;
        using ConstRendererSharedPtr = Rendering::ConstBaseRendererSharedPtr;
        using EnvironmentParameter = Rendering::EnvironmentParameter;
        using ProgramFactory = Rendering::ProgramFactory;
        using ProgramFactorySharedPtr = std::shared_ptr<ProgramFactory>;

    public:
        RenderingManagerImpl() noexcept;
        ~RenderingManagerImpl() noexcept = default;
        RenderingManagerImpl(const RenderingManagerImpl& rhs) noexcept = delete;
        RenderingManagerImpl& operator=(const RenderingManagerImpl& rhs) noexcept = delete;
        RenderingManagerImpl(RenderingManagerImpl&& rhs) noexcept;
        RenderingManagerImpl& operator=(RenderingManagerImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Resize(int width, int height);
        void DrawFrameRate(int x, int y, const Colour& color, const std::string& message);
        void ResetRenderer(const std::string& fileName, const EnvironmentParameter& environmentParameter); 
        void ClearBuffers();

        NODISCARD Colour GetClearColor() const;
        void SetClearColor(const Colour& colour);

        NODISCARD RendererSharedPtr GetRenderer();
        NODISCARD ConstRendererSharedPtr GetRenderer() const;

        void Release();
        void SwapBuffers();

    protected:
        SYSTEM_NORETURN static void ThrowException();

    private:
        /// ʹ��GPU�Ĵ���Ӧ�ó�������������ǡ�
        /// ��ʹ��GPU�Ŀ���̨Ӧ�ó�����ܲ���Ҫ�������ǡ�
        RendererSharedPtr renderer;
        ProgramFactorySharedPtr programFactory;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H
