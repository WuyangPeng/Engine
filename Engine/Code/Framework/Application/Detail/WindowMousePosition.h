///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 14:50)

#ifndef FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H
#define FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H

#include "Framework/FrameworkDll.h"

#include "MousePositionImpl.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowMousePosition final : public MousePositionImpl
    {
    public:
        using ClassType = WindowMousePosition;
        using ParentType = MousePositionImpl;

    public:
        explicit WindowMousePosition(WindowsHWnd hWnd) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ���λ��
        NODISCARD WindowPoint GetMousePosition() const noexcept override;
        void SetMousePosition(const WindowPoint& windowPoint) noexcept override;
        NODISCARD MousePositionImplSharedPtr Clone() const override;

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H
