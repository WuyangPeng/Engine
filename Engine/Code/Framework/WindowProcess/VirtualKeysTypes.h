///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 16:25)

#ifndef FRAMEWORK_WINDOW_PROCESS_VIRTUAL_KEYS_TYPES_H
#define FRAMEWORK_WINDOW_PROCESS_VIRTUAL_KEYS_TYPES_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Using/WindowsUsing.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE VirtualKeysTypes
    {
    public:
        using ClassType = VirtualKeysTypes;
        using WParam = System::WindowsWParam;

    public:
        // ֻ֧��GLUT
        VirtualKeysTypes() noexcept = default;

        // ֻ֧��Window
        explicit VirtualKeysTypes(WParam wParam) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsCtrlKeyDown() const noexcept;
        NODISCARD bool IsLeftMouseDown() const noexcept;
        NODISCARD bool IsMiddleMouseDown() const noexcept;
        NODISCARD bool IsRightMouseDown() const noexcept;
        NODISCARD bool IsShiftKeyDown() const noexcept;
        NODISCARD bool IsMouseDown() const noexcept;

        // ֻ֧��GLUT
        void SetModifiers(int modifiers) noexcept;
        void SetMouseButtonsTypes(int button) noexcept;
        void ClearMouseButtonsTypes() noexcept;
        void ClearKeyDownTypes() noexcept;

    private:
        bool isCtrlKeyDown{ false };
        bool isLeftMouseDown{ false };
        bool isMiddleMouseDown{ false };
        bool isRightMouseDown{ false };
        bool isShiftKeyDown{ false };
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_VIRTUAL_KEYS_TYPES_H
