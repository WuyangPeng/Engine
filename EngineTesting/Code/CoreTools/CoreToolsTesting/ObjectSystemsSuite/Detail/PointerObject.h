// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 13:28)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_POINTER_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_POINTER_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "NullObject.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

// PointerObject值对象，这个类用于演示Object使用指针和指针的数组。
namespace CoreTools
{
    class PointerObject : public NullObject, private boost::noncopyable
    {
    public:
        using ClassType = PointerObject;
        using ParentType = NullObject;

    public:
        PointerObject();
        virtual ~PointerObject();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(PointerObject);

    private:
        void Allocation();
        void Release() noexcept;
        bool IsLoadValidity() const;

    private:
        static constexpr auto bufferSize = 5;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(PointerObject);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(PointerObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_POINTER_OBJECT_H
