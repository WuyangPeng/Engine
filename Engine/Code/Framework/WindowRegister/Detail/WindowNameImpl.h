/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:11)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_IMPL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowNameImpl
    {
    public:
        using ClassType = WindowNameImpl;

        using String = System::String;

    public:
        explicit WindowNameImpl(String className, String menuName);

        NODISCARD bool IsValid() const noexcept;

        NODISCARD String GetWindowClassName() const;
        NODISCARD String GetWindowMenuName() const;

    private:
        String className;
        String menuName;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_IMPL_H