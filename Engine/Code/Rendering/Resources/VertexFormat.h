// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 11:22)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "Flags/VertexFormatFlags.h"
#include "VertexFormatType.h"
#include "VertexFormatElement.h"
#include "CoreTools/ObjectSystems/Object.h"

#include <vector>

RENDERING_EXPORT_SHARED_PTR(VertexFormatImpl);

namespace CoreTools
{
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE VertexFormat : public CoreTools::Object
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(VertexFormat);
		using ParentType = Object;
		using VertexFormatSmartPointer = CoreTools::ThirdSubclassSmartPointer<ClassType>;
	    using ConstVertexFormatSmartPointer = CoreTools::ConstThirdSubclassSmartPointer<ClassType>;
		using AttributeType = VertexFormatFlags::AttributeType;
		using AttributeUsage = VertexFormatFlags::AttributeUsage;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:		
		virtual ~VertexFormat ();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
				
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VertexFormat) 		
		// 便利函数用于创建一个顶点格式通过指定它的所有属性。
		// 现在这个工作只有一个通用的流索引为零(流索引尚未实现任何数值)。
		static VertexFormatSmartPointer Create(const std::vector<VertexFormatType> triple);

		static VertexFormatSmartPointer	Create(const std::vector<VertexFormatElement> triple);

		static VertexFormatSmartPointer LoadFromFile(ReadFileManager& manager);
		
		// 支持延迟构造。调用构造函数之后，必须通过使用 SetAttribute 'numAttributes'次设置所有属性。
		// 当完成时，调用SetStride，这是一个信号，即构造已完成。然后创建相关的渲染资源。

		// 注意：VertexBufferAccessor所述的读/写条件是属性的偏移。
		// VertexFormat::Create保证这一点，但你也应该明确的使用SetAttribute。
		void SetAttribute (int attribute, unsigned int streamIndex,unsigned int offset, 
						   AttributeType type,AttributeUsage usage,unsigned int usageIndex);
						
		int GetNumAttributes () const;
		
		unsigned int GetStreamIndex (int attribute) const;
		unsigned int GetOffset (int attribute) const;
		AttributeType GetAttributeType (int attribute) const;
		AttributeUsage GetAttributeUsage (int attribute) const;
		unsigned int GetUsageIndex (int attribute) const;		
		
		int GetStride () const;
		
		// 返回指定属性的使用情况的索引。指定使用索引目前仅针对颜色通道和纹理坐标使用。
		// 当属性的使用出现在格式中，返回值的索引i在0 <= i < GetNumAttributes()。
		// 如果属性的使用不出现在格式中，返回值是-1。
		int GetIndex (AttributeUsage usage, unsigned int usageIndex = 0) const;
		
		// 属性的一个组件所需的字节数。
		static int GetComponentSize (AttributeType type);
		
		// 属性部件的数量。
		static int GetNumComponents (AttributeType type);
		
		// 属性的所有组件的字节数量。
		static int GetTypeSize (AttributeType type);

		void SaveToFile(WriteFileManager& outFile) const;
		void ReadFromFile(ReadFileManager& inFile); 	

		virtual VertexFormatSmartPointer Clone() const;

		void SetStride(int stride);

	private:
		explicit VertexFormat(int numAttributes);		

		void SetAttribute (int attribute, unsigned int streamIndex,unsigned int offset,const VertexFormatType& vertexFormatType);

		void SetAttribute(int attribute,const VertexFormatElement& vertexFormatElement);				

	private:
		IMPL_TYPE_DECLARE(VertexFormat);
	};
	
	CORE_TOOLS_STREAM_REGISTER(VertexFormat);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, VertexFormat); 
}

#endif // RENDERING_RESOURCES_VERTEX_FORMAT_H
