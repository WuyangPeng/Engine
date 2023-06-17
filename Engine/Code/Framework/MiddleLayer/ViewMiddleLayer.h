///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:22)

#ifndef FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ModelViewControllerMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(ViewMiddleLayerImpl);

namespace Framework
{
    // ��ͼ����
    class FRAMEWORK_DEFAULT_DECLARE ViewMiddleLayer : public ModelViewControllerMiddleLayer
    {
    public:
        NON_COPY_TYPE_DECLARE(ViewMiddleLayer);
        using ParentType = ModelViewControllerMiddleLayer;
        using Colour = Rendering::Colour<float>;
        using Renderer = Rendering::Renderer;
        using RendererSharedPtr = std::shared_ptr<Rendering::Renderer>;
        using ConstRendererSharedPtr = std::shared_ptr<const Rendering::Renderer>;

    public:
        ViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);
        ~ViewMiddleLayer() noexcept = default;
        ViewMiddleLayer(const ViewMiddleLayer& rhs) noexcept = delete;
        ViewMiddleLayer& operator=(const ViewMiddleLayer& rhs) noexcept = delete;
        ViewMiddleLayer(ViewMiddleLayer&& rhs) noexcept;
        ViewMiddleLayer& operator=(ViewMiddleLayer&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Initialize() override;
        NODISCARD bool Paint() override;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

        void DrawFrameRate(const WindowPoint& point, const Colour& color);

        NODISCARD Colour GetClearColor() const;
        void SetClearColor(const Colour& colour);

        // ������Ϣ�м�㴦��
        NODISCARD bool KeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) final;

        // �����Ϣ�м�㴦��
        NODISCARD bool PassiveMotion(const WindowPoint& point) final;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

    protected:
        NODISCARD RendererSharedPtr GetRenderer();
        NODISCARD ConstRendererSharedPtr GetRenderer() const;

    private:
        PackageType impl;
    };

    using ViewMiddleLayerSharedPtr = std::shared_ptr<ViewMiddleLayer>;
    using ConstViewMiddleLayerSharedPtr = std::shared_ptr<const ViewMiddleLayer>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H
