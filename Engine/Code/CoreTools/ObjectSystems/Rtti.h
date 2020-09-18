//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.2 (2020/09/11 12:56)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_RTTI_H
#define CORE_TOOLS_OBJECT_SYSTEMS_RTTI_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Rtti
    {
    public:
        using ClassType = Rtti;

    public:
        // �����Ʊ�����ϵͳ�б����Ƕ��صġ���CoreTools�����ռ䣬��FooӦ��ʹ�á�CoreTools.Foo����
        // ���һ��Ӧ�ó�������һ�������ռ�SomeName��Ȼ�������ӦΪ��SomeName.Foo����
        Rtti(const char* name, const Rtti* baseType) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const char* GetName() const noexcept;
        [[nodiscard]] bool IsExactly(const Rtti& type) const noexcept;
        [[nodiscard]] bool IsDerived(const Rtti& type) const noexcept;

    private:
        const char* m_Name;
        const Rtti* m_BaseType;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_RTTI_H
