//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 11:34)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FWD_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

#include <memory>

namespace CoreTools
{
    class InitTermContainer;
    class InitTerm;
    class Rtti;
    class ObjectName;

    template <typename T, typename Enable>
    struct StreamSize;

    class Stream;
    class OutTopLevel;
    class InTopLevel;
    struct UniqueObject;

    template <typename T>
    struct ObjectAssociated;

    template <typename T>
    struct ConstObjectAssociated;

    template <typename T>
    struct WeakObjectAssociated;

    template <typename T>
    struct ConstWeakObjectAssociated;

    class ObjectRegister;
    class BufferTarget;
    class BufferSource;
    class ObjectLink;
    class ObjectInterface;
    class Object;

    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectRegister);
    CORE_TOOLS_SHARED_PTR_DECLARE(BufferTarget);
    CORE_TOOLS_SHARED_PTR_DECLARE(BufferSource);
    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectLink);
    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectInterface);
    CORE_TOOLS_SHARED_PTR_DECLARE(Object);

    class BufferOutStream;
    class FileOutStream;
    class BufferInStream;
    class FileInStream;
    class ObjectInterfaceSmartPointerLess;
    class ObjectManager;
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_FWD_H