/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:01)

#ifndef FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ModelViewControllerMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"

// 视图层类
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE ViewMiddleLayer : public ModelViewControllerMiddleLayer
    {
    public:
        using ViewMiddleLayerImpl = RenderingManagerImpl;
        NON_COPY_TYPE_DECLARE(ViewMiddleLayer);
        using ParentType = ModelViewControllerMiddleLayer;

        using Colour = Rendering::Colour<float>;
        using BaseRenderer = Rendering::BaseRenderer;
        using RendererSharedPtr = std::shared_ptr<BaseRenderer>;
        using ConstRendererSharedPtr = std::shared_ptr<const BaseRenderer>;

    public:
        ViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Initialize() override;
        NODISCARD bool Paint() override;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

        // 按键消息中间层处理
        NODISCARD bool KeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool KeyDown(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) final;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) final;

        // 鼠标消息中间层处理
        NODISCARD bool PassiveMotion(const WindowPoint& point) final;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

        void DrawFrameRate(const WindowPoint& point, const Colour& colour);

        NODISCARD Colour GetClearColour() const;
        void SetClearColour(const Colour& colour);

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
