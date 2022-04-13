/*
 * can.c
 *
 *  Created on: Apr 13, 2022
 *      Author: Power
 */

/*
 * 函数名：CAN_Filter_Config
 * 描述  ：CAN的过滤器 配置
 * 输入  ：无
 * 输出  : 无
 * 调用  ：内部调用
 */
static void CAN_Filter_Config(void) {
	CAN_FilterTypeDef CAN_FilterTypeDef;

	/*CAN筛选器初始化*/
	CAN_FilterTypeDef.FilterBank = 0;						//筛选器组0
	CAN_FilterTypeDef.FilterMode = CAN_FILTERMODE_IDLIST;	//工作在列表模式
	CAN_FilterTypeDef.FilterScale = CAN_FILTERSCALE_32BIT;	//筛选器位宽为单个32位。
	/* 使能筛选器，按照标志的内容进行比对筛选，扩展ID不是如下的就抛弃掉，是的话，会存入FIFO0。 */

	CAN_FilterTypeDef.FilterIdHigh = ((((uint32_t) 0x2233 << 3) | CAN_ID_EXT
			| CAN_RTR_DATA) & 0xFFFF0000) >> 16;		//要筛选的ID高位
	CAN_FilterTypeDef.FilterIdLow = (((uint32_t) 0x2233 << 3) | CAN_ID_EXT
			| CAN_RTR_DATA) & 0xFFFF; //要筛选的ID低位
	CAN_FilterTypeDef.FilterMaskIdHigh = 0;		//第二个ID的高位
	CAN_FilterTypeDef.FilterMaskIdLow = 0;			//第二个ID的低位
	CAN_FilterTypeDef.FilterFIFOAssignment = CAN_FILTER_FIFO0;	//筛选器被关联到FIFO0
	CAN_FilterTypeDef.FilterActivation = ENABLE;			//使能筛选器
	HAL_CAN_ConfigFilter(&hcan1, &CAN_FilterTypeDef);
}
