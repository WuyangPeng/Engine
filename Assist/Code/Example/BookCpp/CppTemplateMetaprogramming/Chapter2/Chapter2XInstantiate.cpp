///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/08 23:04)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "Chapter2X.h"
#include "Chapter2XInstantiate.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#define OPEN_CHAPTER2X_ERROR1
#define OPEN_CHAPTER2X_ERROR2

#undef OPEN_CHAPTER2X_ERROR1
#undef OPEN_CHAPTER2X_ERROR2

BookTemplate::CppTemplateMetaprogramming::Chapter2XInstantiate::Chapter2XInstantiate() noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_SELF_CLASS_IS_VALID_9;
}

void BookTemplate::CppTemplateMetaprogramming::Chapter2XInstantiate::Main() const noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    typedef Chapter2X<int&, char> T1;  // OK����δʵ����

#ifdef OPEN_CHAPTER2X_ERROR1
    T1 x1;  // ����ָ��int&��ָ�벻�Ϸ�
#endif  // OPEN_CHAPTER2X_ERROR1

    typedef Chapter2X<int, char&> T2;
    T2 x2{};  // OK�������ϸ�

#ifdef OPEN_CHAPTER2X_ERROR2
    MAYBE_UNUSED int a = x2.f(nullptr);  // ����Ԫ��Ϊchar&������Ƿ���
#endif  // OPEN_CHAPTER2X_ERROR2
}
