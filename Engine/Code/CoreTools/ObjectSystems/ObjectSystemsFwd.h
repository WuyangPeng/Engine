//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/11 12:57)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FWD_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FWD_H

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

    class ObjectRegister;
    class BufferTarget;
    class BufferSource;
    class ObjectLink;

    using ObjectRegisterSharedPtr = std::shared_ptr<ObjectRegister>;
    using ConstObjectRegisterSharedPtr = std::shared_ptr<const ObjectRegister>;
    using BufferTargetSharedPtr = std::shared_ptr<BufferTarget>;
    using ConstBufferTargetSharedPtr = std::shared_ptr<const BufferTarget>;
    using BufferSourceSharedPtr = std::shared_ptr<BufferSource>;
    using ConstBufferSourceSharedPtr = std::shared_ptr<const BufferSource>;
    using ObjectLinkSharedPtr = std::shared_ptr<ObjectLink>;
    using ConstObjectLinkSharedPtr = std::shared_ptr<const ObjectLink>;

    class ObjectInterface;

    using ObjectInterfaceSharedPtr = std::shared_ptr<ObjectInterface>;
    using ConstObjectInterfaceSharedPtr = std::shared_ptr<const ObjectInterface>;

    class BufferOutStream;
    class FileOutStream;
    class BufferInStream;
    class FileInStream;
    class ObjectInterfaceSmartPointerLess;
    class Object;
    class ObjectManager;
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_FWD_H