// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 10:51)

#ifndef RENDERING_RESOURCES_INDEX_BUFFER_H
#define RENDERING_RESOURCES_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{	
	class RENDERING_DEFAULT_DECLARE IndexBuffer : public Buffer
	{
	public:
		using ClassType = IndexBuffer;
		using ParentType = Buffer;
		using IndexBufferSharedPtr = std::shared_ptr<ClassType>;
		using ConstIndexBufferSharedPtr = std::shared_ptr<const ClassType>;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		IndexBuffer ();
		IndexBuffer (int numIndices, int indexSize,BufferUsage usage = BufferUsage::Static);
		  ~IndexBuffer (); 
		  IndexBuffer(const IndexBuffer&) = default;
		  IndexBuffer& operator=(const IndexBuffer&) = default;
		   IndexBuffer( IndexBuffer&&) = default;
		  IndexBuffer& operator=( IndexBuffer&&) = default;

		CLASS_INVARIANT_OVERRIDE_DECLARE;
				
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndexBuffer); 

		// 索引的偏移量被使用在渲染器绘制。
		// 设置这个的能力是在多个几何图元共享索引缓冲区时有用,
		// 每个基元使用一套连续索引。
		// 在这种情况下,应用程序对于每一个几何元素动态调用SetNumElements和SetOffset。
		void SetOffset (int offset) noexcept;
		int GetOffset () const noexcept;

		void SaveToFile(WriteFileManager& outFile) const;
		void ReadFromFile(ReadFileManager& inFile);

		virtual IndexBufferSharedPtr Clone() const;

		void InitIndexBuffer();
		void InitIndexBufferInParticles();
		void InitIndexBufferInRectangle(int index, int firstRectangleIndex, int secondRectangleIndex, int thirdRectangleIndex,int fourthRectangleIndex);
		void InitIndexBufferInDisk(int radialSamplesMinus1, int shellSamplesMinus1);
		void InitIndexBuffer(const std::vector<int> indices);

		void SetIndexBuffer(int index, int original, int current);
                ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		int m_Offset;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(IndexBuffer);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( IndexBuffer); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_RESOURCES_INDEX_BUFFER_H

