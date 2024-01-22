/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:45)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <iosfwd>

// ���ڴ�С���������û��ʹ��Implģʽ��ֻ������==��!=��<<�����������
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowSize : private boost::equality_comparable<WindowSize>
    {
    public:
        using ClassType = WindowSize;

        using WindowsLParam = System::WindowsLParam;

    public:
        WindowSize() noexcept;
        WindowSize(int width, int height);
        explicit WindowSize(WindowsLParam lParam);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetWindowWidth() const noexcept;
        NODISCARD int GetWindowHeight() const noexcept;

        void SetWindowSize(int width, int height);

    private:
        int windowWidth;
        int windowHeight;
    };

    NODISCARD bool FRAMEWORK_DEFAULT_DECLARE operator==(const WindowSize& lhs, const WindowSize& rhs) noexcept;
    FRAMEWORK_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const WindowSize& size);
}

#endif  // FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H
