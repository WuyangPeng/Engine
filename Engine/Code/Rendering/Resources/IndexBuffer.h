// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 10:51)

#ifndef RENDERING_RESOURCES_INDEX_BUFFER_H
#define RENDERING_RESOURCES_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"

namespace Rendering
{	
	class RENDERING_DEFAULT_DECLARE IndexBuffer : public Buffer
	{
	public:
		using ClassType = IndexBuffer;
		using ParentType = Buffer;
		using IndexBufferSmartPointer = CoreTools::FourthSubclassSmartPointer<ClassType>;
		using ConstIndexBufferSmartPointer = CoreTools::ConstFourthSubclassSmartPointer<ClassType>;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		IndexBuffer ();
		IndexBuffer (int numIndices, int indexSize,BufferUsage usage = BufferUsage::Static);
		virtual ~IndexBuffer (); 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
				
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndexBuffer); 

		// 索引的偏移量被使用在渲染器绘制。
		// 设置这个的能力是在多个几何图元共享索引缓冲区时有用,
		// 每个基元使用一套连续索引。
		// 在这种情况下,应用程序对于每一个几何元素动态调用SetNumElements和SetOffset。
		void SetOffset (int offset);
		int GetOffset () const;

		void SaveToFile(WriteFileManager& outFile) const;
		void ReadFromFile(ReadFileManager& inFile);

		virtual IndexBufferSmartPointer Clone() const;

		void InitIndexBuffer();
		void InitIndexBufferInParticles();
		void InitIndexBufferInRectangle(int index, int firstRectangleIndex, int secondRectangleIndex, int thirdRectangleIndex,int fourthRectangleIndex);
		void InitIndexBufferInDisk(int radialSamplesMinus1, int shellSamplesMinus1);
		void InitIndexBuffer(const std::vector<int> indices);

		void SetIndexBuffer(int index, int original, int current);

	private:
		int m_Offset;
	};

	CORE_TOOLS_STREAM_REGISTER(IndexBuffer);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, IndexBuffer); 
}

#endif // RENDERING_RESOURCES_INDEX_BUFFER_H

