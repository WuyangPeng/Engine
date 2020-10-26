//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 11:36)

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
        // 该名称必须在系统中必须是独特的。在CoreTools命名空间，类Foo应该使用“CoreTools.Foo”。
        // 如果一个应用程序有另一个命名空间SomeName，然后的名称应为“SomeName.Foo”。
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
