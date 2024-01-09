/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/02 15:18)

#ifndef RENDERING_RENDERER_ENGINE_VIEWPORT_H
#define RENDERING_RENDERER_ENGINE_VIEWPORT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

/// �Ӵ���������ֵ�ڴ��������С�
/// ���ڵ�ԭ��Ϊ(xPosition��yPosition)�����ڿ��Ϊwidth�����ڸ߶�Ϊheight��
/// DirectX�Ӵ�Ϊ��������ϵ��ԭ���ڴ��ڵ����Ͻǣ�x��ָ���Ҳ࣬y��ָ���·���
/// OpenGL�Ӵ�����������ϵ��ԭ���ڴ��ڵ����½ǣ�x��ָ���Ҳ࣬y��ָ���Ϸ���
namespace Rendering
{
    class Viewport final
    {
    public:
        using ClassType = Viewport;

    public:
        constexpr Viewport(const int xPosition, const int yPosition, const int width, const int height) noexcept
            : xPosition{ xPosition }, yPosition{ yPosition }, width{ width }, height{ height }
        {
        }

        NODISCARD constexpr int GetXPosition() const noexcept
        {
            return xPosition;
        }

        NODISCARD constexpr int GetYPosition() const noexcept
        {
            return yPosition;
        }

        NODISCARD constexpr int GetWidth() const noexcept
        {
            return width;
        }

        NODISCARD constexpr int GetHeight() const noexcept
        {
            return height;
        }

        NODISCARD constexpr bool IsInViewport(const int x, const int y) const noexcept
        {
            return (xPosition <= x) && (x <= xPosition + width) && (yPosition <= y) && (y <= yPosition + height);
        }

    private:
        int xPosition;
        int yPosition;
        int width;
        int height;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_VIEWPORT_H
