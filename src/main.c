
#include "main.h"
#include "ADC_conf.h"

__IO uint16_t  ADC1ConvertedValue = 0, ADC1ConvertedVoltage = 0;
uint32_t v=0,mv=0;
int main(void)
{
  ADC_conf();
  LED_Config();
  while (1)
  {
    while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
    
    /* Get ADC1 converted data */
    ADC1ConvertedValue =ADC_GetConversionValue(ADC1);
    
    /* Compute the voltage */
    ADC1ConvertedVoltage = (ADC1ConvertedValue *3300)/0xFFF;
    
   v=(ADC1ConvertedVoltage)/1000;
   mv = (ADC1ConvertedVoltage%1000)/100;
   
    switch(mv)
    {
      case 1:
        GPIO_SetBits(GPIOC,GPIO_Pin_6);
      
  }
}

#ifdef  USE_FULL_ASSERT


void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
}
