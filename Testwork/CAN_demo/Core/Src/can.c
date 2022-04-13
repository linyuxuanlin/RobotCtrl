/*
 * can.c
 *
 *  Created on: Apr 13, 2022
 *      Author: Power
 */

/*
 * ��������CAN_Filter_Config
 * ����  ��CAN�Ĺ����� ����
 * ����  ����
 * ���  : ��
 * ����  ���ڲ�����
 */
static void CAN_Filter_Config(void) {
	CAN_FilterTypeDef CAN_FilterTypeDef;

	/*CANɸѡ����ʼ��*/
	CAN_FilterTypeDef.FilterBank = 0;						//ɸѡ����0
	CAN_FilterTypeDef.FilterMode = CAN_FILTERMODE_IDLIST;	//�������б�ģʽ
	CAN_FilterTypeDef.FilterScale = CAN_FILTERSCALE_32BIT;	//ɸѡ��λ��Ϊ����32λ��
	/* ʹ��ɸѡ�������ձ�־�����ݽ��бȶ�ɸѡ����չID�������µľ����������ǵĻ��������FIFO0�� */

	CAN_FilterTypeDef.FilterIdHigh = ((((uint32_t) 0x2233 << 3) | CAN_ID_EXT
			| CAN_RTR_DATA) & 0xFFFF0000) >> 16;		//Ҫɸѡ��ID��λ
	CAN_FilterTypeDef.FilterIdLow = (((uint32_t) 0x2233 << 3) | CAN_ID_EXT
			| CAN_RTR_DATA) & 0xFFFF; //Ҫɸѡ��ID��λ
	CAN_FilterTypeDef.FilterMaskIdHigh = 0;		//�ڶ���ID�ĸ�λ
	CAN_FilterTypeDef.FilterMaskIdLow = 0;			//�ڶ���ID�ĵ�λ
	CAN_FilterTypeDef.FilterFIFOAssignment = CAN_FILTER_FIFO0;	//ɸѡ����������FIFO0
	CAN_FilterTypeDef.FilterActivation = ENABLE;			//ʹ��ɸѡ��
	HAL_CAN_ConfigFilter(&hcan1, &CAN_FilterTypeDef);
}
