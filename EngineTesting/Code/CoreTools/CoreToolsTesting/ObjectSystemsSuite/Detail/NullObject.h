// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 13:28)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_NULL_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_NULL_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/ObjectInterface.h"

namespace CoreTools
{
    class NullObject : public ObjectInterface
    {
    public:
        using ClassType = NullObject;
        using ParentType = ObjectInterface;

    public:
        NullObject();
        virtual ~NullObject();

        CLASS_INVARIANT_OVERRIDE_DECLARE;
        ObjectInterfaceSharedPtr CloneObject() const override;
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(NullObject);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(NullObject);
#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(NullObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_NULL_OBJECT_H
