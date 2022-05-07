///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/05 19:15)

#ifndef FRAMEWORK_APPLICATION_MOUSE_POSITION_IMPL_H
#define FRAMEWORK_APPLICATION_MOUSE_POSITION_IMPL_H

#include "System/Windows/Flags/WindowsFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"

#include <memory>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE MousePositionImpl
    {
    public:
        using ClassType = MousePositionImpl;
        using MousePositionImplSharedPtr = std::shared_ptr<ClassType>;
        using WindowsHWnd = System::WindowsHWnd;
        using FactoryType = ClassType;

    public:
        MousePositionImpl() noexcept = default;
        virtual ~MousePositionImpl() noexcept = default;
        MousePositionImpl(const MousePositionImpl& rhs) noexcept = default;
        MousePositionImpl(MousePositionImpl&& rhs) noexcept = default;
        MousePositionImpl& operator=(const MousePositionImpl& rhs) noexcept = default;
        MousePositionImpl& operator=(MousePositionImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD static MousePositionImplSharedPtr Create(WindowsHWnd hwnd);

        // ���λ��
        NODISCARD virtual WindowPoint GetMousePosition() const = 0;
        virtual void SetMousePosition(const WindowPoint& windowPoint) = 0;

        NODISCARD virtual MousePositionImplSharedPtr Clone() const = 0;
    };
}

#endif  // FRAMEWORK_APPLICATION_MOUSE_POSITION_IMPL_H
