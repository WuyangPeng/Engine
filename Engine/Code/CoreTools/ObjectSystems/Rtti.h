/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:56)

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

        NODISCARD const char* GetName() const noexcept;
        NODISCARD bool IsExactly(const Rtti& type) const noexcept;
        NODISCARD bool IsDerived(const Rtti& type) const noexcept;

    private:
        const char* name;
        const Rtti* baseType;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_RTTI_H
