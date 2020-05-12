#include "bsp_spi_x.h"


void SPI_FLASH_Init(void){
	
  SPI_InitTypeDef  	SPI_InitStructure;
  GPIO_InitTypeDef 	GPIO_InitStructure;
  
  RCC_AHB1PeriphClockCmd (x1_SPI_SCK_GPIO_CLK | x1_SPI_MISO_GPIO_CLK |
													x1_SPI_MOSI_GPIO_CLK | x1_CS_GPIO_CLK, ENABLE);

  /*!< SPI_FLASH_SPI ʱ��ʹ�� */
  FLASH_SPI_CLK_INIT(x1_SPI_CLK, ENABLE);
 
  //�������Ÿ���
  GPIO_PinAFConfig(x1_SPI_SCK_GPIO_PORT ,x1_SPI_SCK_PINSOURCE ,x1_SPI_SCK_AF); 
	GPIO_PinAFConfig(x1_SPI_MISO_GPIO_PORT,x1_SPI_MISO_PINSOURCE,x1_SPI_MISO_AF); 
	GPIO_PinAFConfig(x1_SPI_MOSI_GPIO_PORT,x1_SPI_MOSI_PINSOURCE,x1_SPI_MOSI_AF); 
  
  /*!< ���� SPI_FLASH_SPI ����: SCK */
  GPIO_InitStructure.GPIO_Pin   = x1_SPI_SCK_PIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;  
  GPIO_Init(x1_SPI_SCK_GPIO_PORT, &GPIO_InitStructure);
  
	/*!< ���� SPI_FLASH_SPI ����: MISO */
  GPIO_InitStructure.GPIO_Pin = x1_SPI_MISO_PIN;
  GPIO_Init(x1_SPI_MISO_GPIO_PORT, &GPIO_InitStructure);
  
	/*!< ���� SPI_FLASH_SPI ����: MOSI */
  GPIO_InitStructure.GPIO_Pin = x1_SPI_MOSI_PIN;
  GPIO_Init(x1_SPI_MOSI_GPIO_PORT, &GPIO_InitStructure);  

	/*!< ���� SPI_FLASH_SPI ����: CS */
  GPIO_InitStructure.GPIO_Pin  = x1_CS_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(x1_CS_GPIO_PORT, &GPIO_InitStructure);

  /* ֹͣ�ź� FLASH: CS���Ÿߵ�ƽ*/
  SPI_FLASH_CS_HIGH();

  /* FLASH_SPI ģʽ���� */
  // FLASHоƬ ֧��SPIģʽ0��ģʽ3���ݴ�����CPOL CPHA
  SPI_InitStructure.SPI_Direction 				= SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode 							= SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize 					= SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL 							= SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA 							= SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS 							= SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
  SPI_InitStructure.SPI_FirstBit 					= SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial 		= 7;
  SPI_Init(x1_SPI, &SPI_InitStructure);

  /* ʹ�� FLASH_SPI  */
  SPI_Cmd(x1_SPI, ENABLE);

}
