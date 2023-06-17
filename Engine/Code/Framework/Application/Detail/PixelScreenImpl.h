///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:43)

#ifndef FRAMEWORK_APPLICATION_PIXEL_SCREEN_IMPL_H
#define FRAMEWORK_APPLICATION_PIXEL_SCREEN_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Framework/WindowCreate/WindowSize.h"

#include <vector>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE PixelScreenImpl
    {
    public:
        using ClassType = PixelScreenImpl;
        using Colour = Rendering::Colour<uint8_t>;
        using RendererSharedPtr = std::shared_ptr<Rendering::Renderer>;
        using ConstRendererSharedPtr = std::shared_ptr<const Rendering::Renderer>;

    public:
        explicit PixelScreenImpl(const WindowSize& size);

        CLASS_INVARIANT_DECLARE;

#ifdef OPEN_CLASS_INVARIANT

        bool IsScreenSizeValid() const;

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD int GetScreenWidth() const noexcept;
        NODISCARD int GetScreenHeight() const noexcept;

        void Resize(const WindowSize& size, const Colour& color);

        void Draw(const RendererSharedPtr& renderer);

        void ClearScreen(const Colour& color);

        // ��������ֻ��ơ��������Ի��Ƶ�������Ļ������������֮ǰ����Ļ�����Ƶ�����һ�����л�������
        // ��ֻ��Ҫ��Ӧ�ó������DoFlip (true)һ�εġ�Ĭ��ֵ�ǡ�false����
        void DoFlip(bool doFlip) noexcept;

        NODISCARD bool IsDoFlip() const noexcept;

        // ����λ��(x,y)������Ϊָ������ɫ��
        void SetPixel(int x, int y, const Colour& color);

        // �������� (x',y') �� x - thick <= x' <= x + thick �� y - thick <= y' <= y + thick.
        void SetThickPixel(int x, int y, int thick, const Colour& color);

        // ��ȡλ��(x,y)��������ɫ��
        NODISCARD Colour GetPixel(int x, int y) const;

        // ʹ��Bresenham�㷨��������Ϊָ���ĵ���ɫ�ӻ���(xMin, yMin) �� (xMax, yMax)��
        // ���㷨����ƫ��ģ�ͨ��DrawLine(xMin, yMin, xMax, yMax)�趨�����ز�һ��ͬDrawLine(xMax, yMax, xMin, yMin)���õ���ͬ��
        void DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& color);

        // ʹ��ָ������ɫ�����������Ρ�solid����ָʾ�Ƿ������Ρ�
        void DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& color, bool solid = false);

        // ʹ��Bresenham�㷨����������(xCenter,yCenter)��ָ�����뾶����
        // ��ʹ��ָ������ɫ��Բ����solid������ָʾ�Ƿ����Ȧ��
        void DrawCircle(int xCenter, int yCenter, int radius, const Colour& color, bool solid = false);

        // ��ˮ���һ������ͨ���ı���������ɫ������ɫ��Ϊ��ǰ��ɫ����
        // ��䴦��4������Ҳ����˵����(x,y)�����ʣ���(x + 1,y), (x,y - 1), �� (x,y + 1) �����ʣ���Ϊ����������Ļ�ı߽磩��
        // �ú���ͨ��ʹ��ջ���Ӷ������������ĵݹ���ۺ͵��ö�ջ����Ŀ��ܡ�
        void Fill(int x, int y, const Colour& foreColor, const Colour& backColor);

    private:
        using ColourContainer = std::vector<Colour>;

    private:
        void DrawSolidCircle(int xCenter, int yCenter, int radius, const Colour& color);
        void DrawHollowCircle(int xCenter, int yCenter, int radius, const Colour& color);

        void SetLineOnX(int xMin, int xMax, int y, const Colour& color);
        void SetLineOnY(int x, int yMin, int yMax, const Colour& color);

        void DoDrawSolidCircle1(int xCenter, int yCenter, int x, int y, const Colour& color);
        void DoDrawSolidCircle2(int xCenter, int yCenter, int x, int y, const Colour& color);

    private:
        int screenWidth;
        int screenHeight;
        ColourContainer screen;
        bool doFlip;
    };
}

#endif  // FRAMEWORK_APPLICATION_PIXEL_SCREEN_IMPL_H
