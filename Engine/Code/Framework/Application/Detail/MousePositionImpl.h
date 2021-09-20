// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.3.0.1 (2020/05/21 13:39)

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
        using HWnd = System::WindowsHWnd;
        using FactoryType = ClassType;

    public:
        MousePositionImpl() noexcept = default;
        virtual ~MousePositionImpl() = default;
        MousePositionImpl(const MousePositionImpl&) noexcept = default;
        MousePositionImpl(MousePositionImpl&&) noexcept = default;
        MousePositionImpl& operator=(const MousePositionImpl&) noexcept = default;
        MousePositionImpl& operator=(MousePositionImpl&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        static MousePositionImplSharedPtr Create(HWnd hwnd);

        // ���λ��
        virtual const WindowPoint GetMousePosition() const = 0;
        virtual void SetMousePosition(const WindowPoint& windowPoint) = 0;

        virtual MousePositionImplSharedPtr Clone() const = 0;
    };
}

#endif  // FRAMEWORK_APPLICATION_MOUSE_POSITION_IMPL_H
