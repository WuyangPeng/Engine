/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 09:56)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_RTTI_H
#define CORE_TOOLS_OBJECT_SYSTEMS_RTTI_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Rtti final
    {
    public:
        using ClassType = Rtti;

    public:
        // �����Ʊ�����ϵͳ�б����Ƕ��صġ���CoreTools�����ռ䣬��FooӦ��ʹ�á�CoreTools.Foo����
        // ���һ��Ӧ�ó�������һ�������ռ�SomeName��Ȼ�������ӦΪ��SomeName.Foo����
        Rtti(const char* name, const Rtti* baseType) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD const char* GetName() const noexcept;
        NODISCARD bool IsExactly(const Rtti& type) const noexcept;
        NODISCARD bool IsDerived(const Rtti& type) const noexcept;

    private:
        const char* name;
        const Rtti* baseType;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_RTTI_H
