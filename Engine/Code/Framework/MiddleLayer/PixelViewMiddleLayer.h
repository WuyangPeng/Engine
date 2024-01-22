/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:01)

#ifndef FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ViewMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(PixelViewMiddleLayerImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE PixelViewMiddleLayer : public ViewMiddleLayer
    {
    public:
        NON_COPY_TYPE_DECLARE(PixelViewMiddleLayer);
        using ParentType = ViewMiddleLayer;

        using Colour = Rendering::Colour<uint8_t>;

    public:
        PixelViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Initialize() override;
        NODISCARD bool Idle(int64_t timeDelta) override;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

        // ������������Ⱦ��Ļ����κ����������Ⱦ����Ļ����Ӧʹ����Ⱦ�����ã�������ֱ�ӷ���screen���顣
        virtual void ScreenOverlay();

        NODISCARD bool IsDoFlip() const noexcept;

        void ClearScreen();

        void DoFlip(bool doFlip);

        void SetPixel(int x, int y, const Colour& colour);

        void SetThickPixel(int x, int y, int thick, const Colour& colour);

        NODISCARD Colour GetPixel(int x, int y) const;

        void DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& colour);

        void DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid = false);

        void DrawCircle(int xCenter, int yCenter, int radius, const Colour& colour, bool solid = false);

        void Fill(int x, int y, const Colour& foreColour, const Colour& backColour);

        NODISCARD int GetScreenWidth() const noexcept;
        NODISCARD int GetScreenHeight() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H
