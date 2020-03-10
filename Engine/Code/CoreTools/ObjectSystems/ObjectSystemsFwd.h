// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:18)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FWD_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FWD_H

namespace CoreTools
{
	class InitTerm;
	class Rtti;
	class ObjectName;
	class OutTopLevel;
	class ObjectRegister;
	class BufferTarget;
	class BufferOutStream;
	class FileOutStream;

	template <typename T, typename Enable>
	struct StreamSize;

	class Stream;

	template <typename T>
	int GetStreamSize(T value);

	class BufferSource;
	class InTopLevel;
	class ObjectLink;
	class BufferInStream;
	class FileInStream;
	class ObjectInterface;
	class ObjectInterfaceSmartPointerLess;
	class Object;
	class ObjectManager;
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_FWD_H