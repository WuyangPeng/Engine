/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:21)

#ifndef FRAMEWORK_APPLICATION_MOUSE_POSITION_IMPL_H
#define FRAMEWORK_APPLICATION_MOUSE_POSITION_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Flags/WindowsFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"

#include <memory>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE MousePositionImpl
    {
    public:
        using ClassType = MousePositionImpl;
        using FactoryType = ClassType;

        using WindowsHWnd = System::WindowsHWnd;
        using MousePositionImplSharedPtr = std::shared_ptr<ClassType>;

    public:
        MousePositionImpl() noexcept = default;
        virtual ~MousePositionImpl() noexcept = default;
        MousePositionImpl(const MousePositionImpl& rhs) noexcept = default;
        MousePositionImpl(MousePositionImpl&& rhs) noexcept = default;
        MousePositionImpl& operator=(const MousePositionImpl& rhs) noexcept = default;
        MousePositionImpl& operator=(MousePositionImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD static MousePositionImplSharedPtr Create(WindowsHWnd hWnd);

        // 鼠标位置
        NODISCARD virtual WindowPoint GetMousePosition() const = 0;
        virtual void SetMousePosition(const WindowPoint& windowPoint) = 0;

        NODISCARD virtual MousePositionImplSharedPtr Clone() const = 0;
    };
}

#endif  // FRAMEWORK_APPLICATION_MOUSE_POSITION_IMPL_H
