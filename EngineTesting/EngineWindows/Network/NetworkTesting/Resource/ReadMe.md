@ingroup group_NetworkTesting_Documentation

----------------------------
����ⵥԪ����

----------------------------
1.   HelperSuite  

�԰���ģ��ĵ�Ԫ���ԣ� 
��1������������꣺StreamMacroTesting��
��2���û��꣺UserMacroTesting��

----------------------------
2.	ConfigurationSuite  

�����������ģ��ĵ�Ԫ���ԣ�
��1�����ò��ԣ�ConfigurationStrategyTesting��
��2�������Ӳ��ԣ�ConfigurationSubStrategyTesting��
��3�����ò�����ConfigurationParameterTesting��
��4�����ý�����AnalysisNetworkConfigurationTesting��

----------------------------
3.	NetworkMessageSuite  

��������Ϣģ��ĵ�Ԫ���ԣ�
��1����Ϣ�ӿڣ�MessageInterfaceTesting��
			   NullMessageTesting��
			   NullDoubleMessageTesting�� 
			   MessageContainerTesting��
			   IntegerMessageTesting��
			   StringMessageTesting��
			   MultipleMessageCastTesting��
			   MultipleMessageElementTesting��
			   MultipleMessageSizeTesting��
			   MultipleMessageInitValueTesting��			   
			   MultipleMessageStreamingLoadTesting��
			   MultipleMessageStreamingSaveTesting��
			   MultipleMessageStreamingSizeTesting��
			   MultipleMessageContainerTesting��			  
			   MultipleMessageTesting��	
			   MessageContainerGroupTesting��			   
			   MessageInterfaceSharedPtrLessTesting��
			   MessageManagerTesting��		   
			   MultipleMessageContainerGroupTesting��			   
��2����Ϣ�¼���NetworkMessageEventTesting��
			   MessageEventContainerTesting��
			   MessageEventManagerTesting��
��3����Ϣ���ͣ�MessageTypeConditionTesting��
			   MessageTypeConditionOperatingTesting��
��4����Ϣ����BufferReceiveStreamTesting��
			 BufferSendStreamTesting��
			 MessageBufferTesting��
			 MessageSourceTesting��
			 MessageTargetTesting��
			 ReceiveMessageLevelTesting��
			 SendMessageLevelTesting�� 
��5��protobuf�� ProtoBufMessageTesting��
��6��json�� JsonMessageTesting��
----------------------------
4.	ServiceWrappersSuite 

�Է����װ���ӿ�ģ��ĵ�Ԫ���ԣ�
��1�������װ����

----------------------------
5.	InterfaceSuite 

�������ӿ�ģ��ĵ�Ԫ���ԣ�
��1������������BaseMainManagerTesting��
				 SingletonTesting��
��2�������ַ��SockAddressTesting��
��3����������SockAcceptorTesting��
��4����������SockConnectorTesting��
��5������SockStreamTesting��
��6���������HandleSetIteratorTesting��
		     HandleSetTesting��

----------------------------
6.	ACEWrappersSuite

��ACE��װ��ģ��ĵ�Ԫ���ԣ�
��1������������ACEMainManagerTesting��
��2�������ַ��ACESockInetAddressTesting��
��3����������ACESockAcceptorTesting��
��4����������ACESockConnectorTesting��
��5������ACEIovecSockStreamTesting��
		 ACESockStreamTesting��
��6���������SockACEHandleSetIteratorTesting��
		     SockACEHandleSetTesting��

----------------------------
7.	BoostWrappersSuite 

��boost��װ��ģ��ĵ�Ԫ���ԣ�
��1������������BoostMainManagerTesting��
				 BoostMainManagerUseMultiContextTesting��
				 BoostMainManagerUseThreadsTesting��
��2�������ַ��BoostSockInetAddressTesting��
��3����������BoostSockAcceptorAsynchronousTesting��
			 BoostSockAcceptorHandleTesting��
			 BoostSockAcceptorNonBlockingTesting��
			 BoostSockAcceptorSynchronizeTesting��
			 BoostSockAcceptorTesting��
��4����������BoostSockConnectorAsynchronousTesting��
			 BoostSockConnectorHandleTesting��
			 BoostSockConnectorSynchronizeTesting��
			 BoostSockConnectorTesting��
��5������BoostFixedSockStreamAsynchronousTesting��
		 BoostFixedSockStreamNonBlockingTesting��
		 BoostFixedSockStreamSynchronizeTesting��
		 BoostSegmentationSockStreamAsynchronousTesting��
		 BoostSegmentationSockStreamNonBlockingTesting��
		 BoostSegmentationSockStreamSynchronizeTesting��
		 BoostSockStreamHandleTesting��
		 BoostSockStreamTesting��

----------------------------
8.	NetworkWrappersSuite 

��Network��װ��ģ��ĵ�Ԫ���ԣ�
��1������������NetworkMainManagerTesting��
��2�������ַ��NetworkSockInetAddressTesting��
��3����������NetworkSockAcceptorTesting��
��4����������NetworkSockConnectorTesting��
��5������NetworkSockStreamTesting��

----------------------------
9.	OpensslSuite

��opensslģ��ĵ�Ԫ���ԣ�
��1��openssl��

----------------------------
10.	MessageOrientedMiddlewareSuite

����Ϣ�м��ģ��ĵ�Ԫ���ԣ�
��1����Ϣ�м����ConsumerTesting��
				 ProducerTesting��
				 RouteServiceManagerTesting��
				 RouteServiceTesting��

----------------------------
11.	ActiveMQSuite

��ActiveMQģ��ĵ�Ԫ���ԣ�
��1��ActiveMQ��ActiveMQConsumerTesting��
			   ActiveMQProducerTesting��
			   ActiveMQRouteServiceManagerTesting��
			   ActiveMQRouteServiceTesting��

----------------------------
12.	NatsSuite

��Natsģ��ĵ�Ԫ���ԣ�
��1��Nats��

----------------------------
13.	KafkaSuite

��Kafkaģ��ĵ�Ԫ���ԣ�
��1��Kafka��

----------------------------