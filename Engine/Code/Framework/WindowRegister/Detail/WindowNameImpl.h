///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 16:51)

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
        explicit WindowNameImpl(const String& className, const String& menuName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetWindowClassName() const;
        NODISCARD String GetWindowMenuName() const;

    private:
        String className;
        String menuName;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_NAME_IMPL_H