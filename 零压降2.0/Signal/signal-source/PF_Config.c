/***********************************************************
*   函数库说明：硬件平台配置函数库                         *
*   版本：    Ver1.0                                       *
*   作者：    zzjjhh250/ZZJJHH250 @ (CopyRight)            *
*   创建日期：08/31/2010                                   *
* -------------------------------------------------------- *
*  [硬件说明]                                              *
*   处理器：    STM32F103VBT6                              *
*   系统时钟：  外部8M/PLL = 72M                           *
* -------------------------------------------------------- *
*  [支 持 库]                                              *
*   库名称：    PF_Config.h                                *
*   需要版本：  -----                                      *
*   支持库说明：硬件平台配置声明库                         *
* -------------------------------------------------------- *
*  [版本更新]                                              *
*   修改：                                                 *
*   修改日期：                                             *
*   版本：                                                 *
* -------------------------------------------------------- *
*  [版本历史]                                              *
* -------------------------------------------------------- *
*  [使用说明]                                              *
***********************************************************/

/********************
* 头 文 件 配 置 区 *
********************/

# include "PF_Config.h"
//# include "LIB_Config.h"

/********************
*   系 统 宏 定 义  *
********************/

/*------------------*
*   常 数 宏 定 义  *
*------------------*/

/*------------------*
*   动 作 宏 定 义  *
*------------------*/

/********************
*  模块结构体定义区 *
********************/

/********************
*   函 数 声 明 区  *
********************/
void System_Init(void);

/********************
*   模块函数声明区  *
********************/

/********************
*   模块变量声明区  *
********************/

/********************
*   全局变量声明区  *
********************/

/***********************************************************
*   函数说明：系统初始化函数                               *
*   输入：    无                                           *
*   输出：    无                                           *
*   调用函数：Device_Init() Driver_Init()                  *
***********************************************************/
void System_Init(void)
{    
        Driver_Init();
        Device_Init();
    
        //*在这里插入你的系统环境变量初始化代码*//
        //LED_WORK = LED_FLASH_SLOW;
}

