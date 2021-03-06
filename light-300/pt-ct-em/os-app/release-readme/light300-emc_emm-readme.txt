    请先阅读“00README.txt”。
    电表采集器可以分为emc和emm。
    emc可分为emc-m（单电表采集器主设备），emc-s设备（单电表采集器从设备）。
    emm可分为emm-m（多电表采集器主设备），emm-s设备（多电表采集器从设备）。
    0.5.0是新light300系统的的第一个版本。
-------------------------------------------------------------------------------------------------------------------


====================================================================
light300-emm-m_1024k_0.6.2.20150515_Alpha_0
====================================================================
arm-none-eabi-size light300-emm-m_1024k_0.6.2.20150515_Alpha_0.axf
   text	   data	    bss	    dec	    hex	filename
 507936	   8072	  41040	 557048	  87ff8	light300-emm-m_1024k_0.6.2.20150515_Alpha_0.axf

新增：
1、增加手动配置电表信息trap功能（更改电表、pt、ct地址发送trap；更改表规约、485接口速率发送trap）

修复：
1、修复关口电能表调试bug


优化：
1、不再采集电表的谐波、铁损
2、ip参数配置错误时，提示


====================================================================
light300-emm-m_1024k_0.6.1.20150507_Alpha_0 / light300-emm-m_512k_0.6.1.20150507_Alpha_0
====================================================================
新增：


修复：
1、fix使用version()命令时版本不一致问题
2、解决不同平台编译时版本号问题
3、修复上位机调试硬件检测中的bug

优化：
1、整理isr代码


====================================================================
light300-emm-m_1024k_0.6.0.20150427_Alpha_0
====================================================================
新增：
1、增加电表有功、无功脉冲检测状态trap
2、增加通过485sw访问电表的方式，并且，可以通过命令行来配置，外部是否使用了485sw（命令connect_485sw(0)为直接连电表，命令connect_485sw(1)为通过485SW连接电表；协商波特率失败时,延时300ms后再尝试，协商时,携带规约类型）
3、修改线路或者电表发生变化时发送trap函数
4、自动升级数据库(pt/ct(主从)设备共用一个db，em(主从)设备共用一个db),只能自动升级相邻版本的数据库
5、电压及电流有效值加入求平均值


修复：
1、修复无功功率长时间运行数据出错问题
2、修复遗漏掉的无功功率转换函数
3、修复一处内存泄漏bug


优化：
1、修改电能脉冲超时判断：如果104s内没有脉冲沿超时，或者312s内没有一个完整的周期超时
2、优化与上位机调试相关的部分代码(7880)
3、pt,ct,emc统一配置数据表格；添加sink_info测试电表规约模式的代码
4、在do_set_rs232cfg中对stm32的uart的databits做处理
5、使用set_regem_pinfo来配置电表规约相关信息
6、使用update_elctric_meter_info来更新规约模块使用的电表规约信息
7、将其他地方的databit按照常规
8、修改enum ammeter_protocal_e与485sw中的一致
9、与485SW规约枚举变量保持一致
10、解决电表规约模块同一个结构体/枚举在多个头文件定义的问题
11、edmi返回无法识别时,尝试login




====================================================================
light300-emm-m_0.5.27.20141226_Alpha_0/light300-emm-s_0.5.21.20141226_Alpha_0
====================================================================
新增：
1:增加相关调试上位机对应的函数


修复：
1:修复7880由于hsdc时序问题导致首次采集无功功率和波形采样数据错位的问题


优化：


====================================================================
light300-emm-m_0.5.26.20141217_Alpha_0/light300-emm-s_0.5.20.20141217_Alpha_0
====================================================================
新增：
1:加入上位机调试相关接口函数


修复：

优化：
1:更改三相三和三相四线接线比较阈值
2:延长切换电流通道时的延迟


====================================================================
light300-emm-m_0.5.25.20141204_Alpha_0 / light300-emm-s_0.5.19.20141204_Alpha_0
====================================================================
新增：
1、增加事件trap函数读取电表信息的打印
2、增加设置电表时间的FINSH函数
3、加入接线方式打印函数
4、加入整体调试精度写入和读出函数
5、EDMI规约增加ABC三相视在功率数据
6、增加读取485数据字节之间的间隔时间


修复：
1、修复多线程调用读表函数时，因波特率切换导致的读表不成功的BUG
2、修复事件上报函数不停上报电表清零的BUG
3、解决事件trap不能稳定上传的问题
4、修改瞬时冻结trap机制
5、修复不能读取MK6E电表常数的BUG
6、修复上电自动检测接线方式中由切换通道引起的信号延时问题


优化：
1、完善485测试代码
2、修复读表函数中读取电能量函数的BUG
3、完善获取电表接线方式函数
4、屏蔽掉串口数据写入flash的代码
5、优化读表函数
6、优化电表函数
7、pt/ct统一数据表格,所有的em统一数据表格, NOTE：原表格数据会损坏




====================================================================
light300-emm-m_0.5.23.20141107_Alpha_0 / light300-emm-s_0.5.17.20141107_Alpha_0
====================================================================

新增：
1、当读取三相三线电表时，不读取B相的相关数据，直接设为无效值

修复：

优化：



====================================================================
light300-emm-m_0.5.22.20141106_Alpha_0 / light300-emm-s_0.5.16.20141106_Alpha_0
====================================================================

新增：
1、增加读表函数中的输入电表地址限制为000000000000~999999999999之间
2、增加有功脉冲调试相关寄存器数据的命令写入
3、sinkinfo代码使用打印开关机制

修复：
1、修复由于编辑错误导致不能分发pt数据的bug
2、修改mibPTCT索引节点问题

优化：
1、优化EDMI读表函数


注意：未使用与light300-emm-m_0.5.19.20141029_Alpha_0 / light300-emm-s_0.5.14.20141029_Alpha_0之间的版本。



====================================================================
light300-emm-m_0.5.19.20141029_Alpha_0 / light300-emm-s_0.5.14.20141029_Alpha_0
====================================================================
新增：
1、添加命令行控制打印的机制。
2、电表协议模块使用“命令行控制打印的机制”。
3、一个线路对应2个ct（与优化的第二条相关，sinkinfo、mib的代码都需变动）。
4、支持虚拟电表功能。
5、硬件未使用运放，启用7880内部PGA16倍放大。
6、增加电表连接状态变更检测程序，并trap给网管，通知其刷新。
7、增加冻结命令状态检测。
8、增加瞬时冻结和定时冻结数据trap函数。

修复：
1、修复7880没有处理动态内存申请失败的bug。
2、同样的事件不断上报trap的方式改为只上报一次。
3、修改冻结函数，使其可以返回冻结命令的结果，是成功或失败。

优化：
1、去除没有必要的打印。
2、将struct em_distrib更新完善为slave_emm_collector_info_st（1、添加、删除、查看命令；2、分发数据时的查找代码；3、去除无用代码）。
3、清理从em对应的pt/ct数据结构（数据结构及函数变动）。
4、精简sinkinfo初始化代码。


====================================================================
light300-emm-m_0.5.18.20141010_Alpha_0 / light300-emm-s_0.5.13.20141010_Alpha_0
====================================================================
新增：
1、增加电表规约的调试信息打印
2、添加上传trap事件函数
3、增加读取电表数据函数所支持的波特率
4、增加处理EDMI数据符号位的函数
5、增加EDMI规约mib数据上报
*6、为主em添加通过IP接收pt/ct分发数据的功能(light300-emm-m_0.5.18.20141009_Alpha_0)


修复：
1、修复645-97函数有功功率移位错误
2、修改可能造成数组越界的操作
3、修复EDMI数据由浮点数转成BCD码而出现的BUG
4、调整EDMI数据的精度
5、修复EDMI不能读取有无功电能的bug
6、将被调函数认为时字符串的缓冲区,修改为字符串@do_get_em_data()


优化：
1、修改485相关线程名



====================================================================
light300-emm-m_0.5.17.20140919_Alpha_0
====================================================================
1、修复读取电表数据失败的BUG


====================================================================
light300-emm-s_0.5.12.20140919_Alpha_0
====================================================================
1、修复读取电表数据失败的BUG


====================================================================
light300-emm-m_0.5.16.20140911_Alpha_0
====================================================================
1.增加EDMI电能表通信规约程序，修改645文件夹名称为electric_meter_protocol
2.修复EDMI电表常数不能读取的BUG
3.添加EDMI正反向有功总最大需量及发生时间的数据读取
4.修改规约的传输编号
5.改正EDMI日期时间不能读取的BUG
6.优化读表函数
====================================================================
light300-emm-s_0.5.11.20140911_Alpha_0
====================================================================
1.增加EDMI电能表通信规约程序，修改645文件夹名称为electric_meter_protocol
2.修复EDMI电表常数不能读取的BUG
3.添加EDMI正反向有功总最大需量及发生时间的数据读取
4.修改规约的传输编号
5.改正EDMI日期时间不能读取的BUG
6.优化读表函数

====================================================================
light300-emm-m_0.5.16.20140901_Alpha_0
====================================================================
1.修改由于7880初始化配置时间太长引起的看门狗复位的问题
2.增加定时冻结和瞬时冻结的正反相无功电能数据的读取
3.修改7880配置时被狗咬死问题

====================================================================
light300-emm-s_0.5.11.20140901_Alpha_0
====================================================================
1.修改由于7880初始化配置时间太长引起的看门狗复位的问题
2.增加定时冻结和瞬时冻结的正反相无功电能数据的读取
3.修改7880配置时被狗咬死问题

====================================================================
light300-emm-m_0.5.15.20140828_Alpha_0
====================================================================
1.修改em设备的看门狗时间为2s,并调整采集数据间隔时间
2.增加ABC三相正反向有功电能
3.增加正方向有功无功电能，增加组合有功电能。
4.增加更改适应97和07电表的通信速率函数
5.修正07电表波特率为2400
6.优化修改电表波特率函数
7.修复645解析函数可能出现的内存改写情况
8.优化645函数
9.增加读取645帧各位之间的超时时间
10.屏蔽透传功能
11.设定接收帧每位之间的超时时间为100ms
12.改正上传规约和网管显示规约不对应的BUG

====================================================================
light300-emm-s_0.5.10.20140828_Alpha_0
====================================================================
1.修改em设备的看门狗时间为2s,并调整采集数据间隔时间
2.增加ABC三相正反向有功电能
3.增加正方向有功无功电能，增加组合有功电能。
4.增加更改适应97和07电表的通信速率函数
5.修正07电表波特率为2400
6.优化修改电表波特率函数
7.修复645解析函数可能出现的内存改写情况
8.优化645函数
9.增加读取645帧各位之间的超时时间
10.屏蔽透传功能
11.设定接收帧每位之间的超时时间为100ms
12.改正上传规约和网管显示规约不对应的BUG

====================================================================
light300-emm-m_0.5.14.20140820_Alpha_0
====================================================================
645模块的新增、优化以及bug修复：
1.删除非必要代码
2.不建立645的线程
3.全部初始化未使用645-97规约
4.修改字符串转bcd函数
5.在无sn时，不获取电表常数
6.将645使用的485的波特率从2400修改为1200
7.去除宋工添加的97规约不支持的命令调用
8.增加 645-97，645-07兼容处理
9.修改电表时间反问题
10.恢复645-2007程序代码
11.去掉电表读取失败返回，填充无效值。
12.修改表内温度值错误
13.增加读取645-2007电表的电网频率
14.修改判断电表规约顺序：先判断是否为07，不是07后判断是否为97
15.获取电网频率
16.谐波获取时间间隔
17.07规约也应该获取无功电能
18.修改定时冻结函数出现的BUG
19.优化冻结函数
20.修改冻结数据参数设置无效问题。
21.修改定时冻结时间设置
22.改正定时冻结出现的BUG
23.修改广播校时时间设置
24.增加正反向有无功总电能的费率1-4，增加了组合有无功总电能及1-4费率
25.去掉组合无功总电能

snmp模块的新增、优化以及bug修复：
1.修改网络字节序。
2.增加trap测试节点
3.修改trap配置节

7880模块的新增、优化以及bug修复：
1.更改数据汇集部分中电压电流采样函数
2.解决B相采样波形数据没有上传BUG
3.加入波形采样数据获取函数
4.修改三相三相下视在功率数据越界问题
5.加入三相三接线下B相电压电流采样值为零
6.增加扫描通道接线方式功能
7.去除7880获取电能的相关代码
8.7880使用I2C时，添加超时打印
9.修改扫描通道接线方式函数，加入未接入电表识别
10.重写用于7880通信的i2c代码，以避免死等问题
11.优化相位自动调试部分代码。
12.修复谐波获取过程中计算中数据类型的问题
13.修复切换通道后相位获取问题
14.增加手动更改参数接口
15.B相频率增加接线方式判断。
16.修改em从设备调试参数写入错误问题
17.加入调试单通道互感器相移功能

database模块的新增、优化以及bug修复：
1.修复数据库表格中未字对齐的bug
2.加强信号量保护数据库表格操作
3.提前初始化数据库表格
4.采用多线程获取数据，线程间使用信号量以及事件进行同步
5.电能精度检测使用独立的线程来完成
6.将测试单一脉冲周期，修改为测量多个脉冲周期，直到这些周期的和大于5秒
7.完成一轮采集后，停顿时间改为100ms，使用7880采集谐波的时间间隔为5分钟
8.切换通道时,建立100ms的死区
9.采集7880数据前，延时1s

RS485模块的新增、优化以及bug修复：
1.增加RS485读数据时的超时时间。
2.给用于接收无线数据的485接收数据，添加超时判断
3.修改释放信号量的位置，在数据处理完后再释放信号量
4.增加RS485接收超时时长，解决因系统繁忙导致RS485接收数据超时问题
5.由于RS485发送波特率太低，导致看门口复位，所以在发送函数中加入喂狗操作

TCP/IP数据分发模块的新增、优化以及bug修复：
1.完善TCP数据分发
2.修改网络包中的数据存放位置
3.完善TCP数据包分发程序

其他模块的新增、优化以及bug修复：
其他模块的新增、优化以及bug修复：
1.修复b相电压电流采用应答命令未设置bug;使能实时无功电能测试代码
2.用printf_syn代替rt_kprintf,以避免打印交错
3.修改无功功率带符号运算错误问题
4.增加采集7880的有功功率、电压、电流、视在功率的采集并传输。
5.修改因7880数据采集结构体的改变引起的TCP分发和RS485传输。
6.将应用线程的初始化放到初始化线程中
7.修改代码，使其在未配置数据之前不获取数据
8.修改清空无线白名单函数
9.增加新增485接口的相关代码
10.调整7880使用的引脚
11.修改关于透传函数的相关代码
12.开启独立看门狗
13.新硬件的em与pt、ct板上的7880使用的引脚不同
14.独立看门狗超时时间为1220ms,只在led线程中喂狗
15.解决从EM数据传不到网管的问题
16.流模式时，也需要喂狗去掉宏定义，将UART5初始化编译进入所有工程，防止shell线程工作不正常
17.将em的看门狗时间延长到10s



====================================================================
light300-emm-s_0.5.9.20140820_Alpha_0
====================================================================
645模块的新增、优化以及bug修复：
1.删除非必要代码
2.不建立645的线程
3.全部初始化未使用645-97规约
4.修改字符串转bcd函数
5.在无sn时，不获取电表常数
6.将645使用的485的波特率从2400修改为1200
7.去除宋工添加的97规约不支持的命令调用
8.增加 645-97，645-07兼容处理
9.修改电表时间反问题
10.恢复645-2007程序代码
11.去掉电表读取失败返回，填充无效值。
12.修改表内温度值错误
13.增加读取645-2007电表的电网频率
14.修改判断电表规约顺序：先判断是否为07，不是07后判断是否为97
15.获取电网频率
16.谐波获取时间间隔
17.07规约也应该获取无功电能
18.修改定时冻结函数出现的BUG
19.优化冻结函数
20.修改冻结数据参数设置无效问题。
21.修改定时冻结时间设置
22.改正定时冻结出现的BUG
23.修改广播校时时间设置
24.增加正反向有无功总电能的费率1-4，增加了组合有无功总电能及1-4费率
25.去掉组合无功总电能

snmp模块的新增、优化以及bug修复：
1.修改网络字节序。
2.增加trap测试节点
3.修改trap配置节

7880模块的新增、优化以及bug修复：
1.更改数据汇集部分中电压电流采样函数
2.解决B相采样波形数据没有上传BUG
3.加入波形采样数据获取函数
4.修改三相三相下视在功率数据越界问题
5.加入三相三接线下B相电压电流采样值为零
6.增加扫描通道接线方式功能
7.去除7880获取电能的相关代码
8.7880使用I2C时，添加超时打印
9.修改扫描通道接线方式函数，加入未接入电表识别
10.重写用于7880通信的i2c代码，以避免死等问题
11.优化相位自动调试部分代码。
12.修复谐波获取过程中计算中数据类型的问题
13.修复切换通道后相位获取问题
14.增加手动更改参数接口
15.B相频率增加接线方式判断。
16.修改em从设备调试参数写入错误问题
17.加入调试单通道互感器相移功能

database模块的新增、优化以及bug修复：
1.修复数据库表格中未字对齐的bug
2.加强信号量保护数据库表格操作
3.提前初始化数据库表格
4.采用多线程获取数据，线程间使用信号量以及事件进行同步
5.电能精度检测使用独立的线程来完成
6.将测试单一脉冲周期，修改为测量多个脉冲周期，直到这些周期的和大于5秒
7.完成一轮采集后，停顿时间改为100ms，使用7880采集谐波的时间间隔为5分钟
8.切换通道时,建立100ms的死区
9.采集7880数据前，延时1s

TCP/IP数据分发模块的新增、优化以及bug修复：
1.完善TCP数据分发
2.修改网络包中的数据存放位置
3.完善TCP数据包分发程序

其他模块的新增、优化以及bug修复：
1.修复b相电压电流采用应答命令未设置bug;使能实时无功电能测试代码
2.用printf_syn代替rt_kprintf,以避免打印交错
3.修改无功功率带符号运算错误问题
4.增加采集7880的有功功率、电压、电流、视在功率的采集并传输。
5.修改因7880数据采集结构体的改变引起的TCP分发和RS485传输。
6.将应用线程的初始化放到初始化线程中
7.修改代码，使其在未配置数据之前不获取数据
8.修改清空无线白名单函数
9.增加新增485接口的相关代码
10.调整7880使用的引脚
11.修改关于透传函数的相关代码
12.开启独立看门狗
13.新硬件的em与pt、ct板上的7880使用的引脚不同
14.独立看门狗超时时间为1220ms,只在led线程中喂狗
15.解决从EM数据传不到网管的问题
16.流模式时，也需要喂狗去掉宏定义，将UART5初始化编译进入所有工程，防止shell线程工作不正常
17.将em的看门狗时间延长到10s


====================================================================
light300-emm_0.5.14.20140820_Alpha_0
====================================================================
主要功能概述如下：
1、操作系统使用rt-thread-v1.0.4。
2、支持文件系统，片外spi-flash为W25X40BV(4M-bit)。
3、支持RTC功能。
4、具有网口，通过snmp将需要的数据传输至网管。
5、使用485接口可以从遵守645规约的电表中读取以下数据：电压、电流、有功功率、无功功率、功率因数、总有功电能、总无功电能。
6、用ade7880可以读取电表侧的以下信息：电压、电流、频率、相位、有功功率、视在功率、功率因数、电压失真、电流失真、电压波形采样、电流波形采样。
7、EM主设备通过RS485总线汇聚无线数据。
8、EM主设备通过TCP/IP协议将数据分发到EM从设备。


====================================================================
light300-emm-m_0.5.24.20141111_Alpha_0 / light300-emm-s_0.5.18.20141111_Alpha_0
====================================================================
修复：
1：有功功率的符号问题。


====================================================================
light300-emm-m_0.5.7.20140604_Alpha_0
====================================================================
新增：
1.打开chech_electric_energy()功能函数
2.加入波形采样数据获取函数
3.增加采集7880的有功功率、电压、电流、视在功率的采集并传输
4.增加扫描通道接线方式功能
5.增加将组网信息写入flash的命令
6.增加组网失败时手动配置组网信息的命令
优化：
1.sink_info.c中修改收集数据时间间隔为3S
2.修改打印信息
3.645代码修改
4.用printf_syn代替rt_kprintf,以避免打印交错
5.修改串口2波特率为2400
6.去掉电表线程
7.事件主动上报改为函数接口，调用该函数时判断是事件是否发生，如果发生，则上报
8.数据库表格相关代码优化
9.增加RS485读数据时的超时时间
10.修改扫描通道接线方式函数，加入未接入电表识别
11.重写用于7880通信的i2c代码，以避免死等问题
bug修复：
1.错误的使用了共用体，导致数据覆盖
2.变量定义时初始化为0
3.修改字节序，修改为网络序
4.处理电表sn，去除tcp分发数据的函数调用
5.去除大量数据拷贝,以及频繁的写并同步数据库(这样在访问mib时，会导致系统宕机)
6.修复b相电压电流采用应答命令未设置bug
7.解决B相采样波形数据没有上传BUG
8.修改因7880数据采集结构体的改变引起的TCP分发和RS485传输
9.修改三相三相下视在功率数据越界问题
10.加入三相三接线下B相电压电流采样值为零

====================================================================
light300-emm-m_0.5.4.20140521_Alpha_0
====================================================================
新增：

优化：
1.增加upd_si线程和get_si线程的栈空间分别到2*1024和4*1024.
2.去掉7880调试打印信息。
3.去掉mib操作成功时的打印信息。
bug修复：

====================================================================
light300-emc-m_0.5.4.20140521_Alpha_0
====================================================================
新增：

优化：
1.增加upd_si线程和get_si线程的栈空间分别到2*1024和4*1024.
2.去掉7880调试打印信息。
3.去掉mib操作成功时的打印信息。
bug修复：

====================================================================
light300-emm-m_0.5.3.20140521_Alpha_0
====================================================================
新增：
1. 增加电表连接状态节点
优化：
1. 修改meter电表索引值
bug修复：

====================================================================
light300-emc-m_0.5.3.20140521_Alpha_0
====================================================================
新增：
1. 增加电表连接状态节点
优化：
1. 修改meter电表索引值
bug修复：

====================================================================
light300-emm-m_0.5.2.20140515_Alpha_0
====================================================================
新增：
1. 7880数据：增加ABC
三项电压与电流间相位数据、增加铜损铁损数据（目前暂不支持，为无效值）、增加21
次谐波含量数据，包括ABC三相电压、电流和有功功率谐波含量。
2. 电表数据：
增加瞬时冻结数据，日月小时定时冻结数据、最大需量数据、增加铜损铁损数据、增加表内温度，时钟电池电压，抄表电池电压数据，其中相位和频率不支持为无效值。
增加21次谐波含量数据，包括ABC三相电压、电流谐波含量，其中有功功率谐波含量不支持为无效值。
3. PT、CT侧增加有功功率、功率因数、导纳、PTCT
侧温度值等数据。其中导纳由网管计算得出，底层不直接提供。PTCT
侧温度值暂不支持为无效值。
4. 增加事件trap信息，trap
信息是直接读表信息给网管，中间没有缓存和数据处理。所以编码方式是BCD
编码，字节数请按照645规约定义解析。
5. 增加MIB树支持node节点数,以及增加snmp request和response报文携带节点数。
6. 增加事件上传函数。
7. 解决波特率修改时不能正常配置7880问题。
8. 增加广播校时函数和设置冻结数据的时间函数。
9. 加入切换检测电表时自动获取电表常熟配置7880脉冲输出功能。
优化：
1. 去掉电表事件mib,节点和事件相关缓存信息，以省去内存空间。即网管不能直接读取事件数据，只能通过
   trap获取，所以网管可能需要做存储处理。
2. 优化切换检测电能表时自动配置7880过程。
3. 优化读表函数。
4. 去掉读表错误打印。
bug修复：
1. 修复rt_free(NULL)的bug。
2. 动态申请内存失败后，将相关的动态申请的内存释放掉。

====================================================================
light300-emm-s_0.5.2.20140515_Alpha_0
====================================================================
新增：
1. 7880数据：增加ABC
三项电压与电流间相位数据、增加铜损铁损数据（目前暂不支持，为无效值）、增加21
次谐波含量数据，包括ABC三相电压、电流和有功功率谐波含量。
2. 电表数据：
增加瞬时冻结数据，日月小时定时冻结数据、最大需量数据、增加铜损铁损数据、增加表内温度，时钟电池电压，抄表电池电压数据，其中相位和频率不支持为无效值。
增加21次谐波含量数据，包括ABC三相电压、电流谐波含量，其中有功功率谐波含量不支持为无效值。
3. PT、CT侧增加有功功率、功率因数、导纳、PTCT
侧温度值等数据。其中导纳由网管计算得出，底层不直接提供。PTCT
侧温度值暂不支持为无效值。
4. 增加事件trap信息，trap
信息是直接读表信息给网管，中间没有缓存和数据处理。所以编码方式是BCD
编码，字节数请按照645规约定义解析。
5. 增加MIB树支持node节点数,以及增加snmp request和response报文携带节点数。
6. 增加事件上传函数。
7. 解决波特率修改时不能正常配置7880问题。
8. 增加广播校时函数和设置冻结数据的时间函数。
9. 加入切换检测电表时自动获取电表常熟配置7880脉冲输出功能。
优化：
1. 去掉电表事件mib,节点和事件相关缓存信息，以省去内存空间。即网管不能直接读取事件数据，只能通过
   trap获取，所以网管可能需要做存储处理。
2. 优化切换检测电能表时自动配置7880过程。
3. 优化读表函数。
4. 去掉读表错误打印。
bug修复：
1. 修复rt_free(NULL)的bug。
2. 动态申请内存失败后，将相关的动态申请的内存释放掉。

====================================================================
light300-emc-m_0.5.2.20140515_Alpha_0
====================================================================
新增：
1. 7880数据：增加ABC
三项电压与电流间相位数据、增加铜损铁损数据（目前暂不支持，为无效值）、增加21
次谐波含量数据，包括ABC三相电压、电流和有功功率谐波含量。
2. 电表数据：
增加瞬时冻结数据，日月小时定时冻结数据、最大需量数据、增加铜损铁损数据、增加表内温度，时钟电池电压，抄表电池电压数据，其中相位和频率不支持为无效值。
增加21次谐波含量数据，包括ABC三相电压、电流谐波含量，其中有功功率谐波含量不支持为无效值。
3. PT、CT侧增加有功功率、功率因数、导纳、PTCT
侧温度值等数据。其中导纳由网管计算得出，底层不直接提供。PTCT
侧温度值暂不支持为无效值。
4. 增加事件trap信息，trap
信息是直接读表信息给网管，中间没有缓存和数据处理。所以编码方式是BCD
编码，字节数请按照645规约定义解析。
5. 增加MIB树支持node节点数,以及增加snmp request和response报文携带节点数。
6. 增加事件上传函数。
7. 解决波特率修改时不能正常配置7880问题。
8. 增加广播校时函数和设置冻结数据的时间函数。
9. 加入切换检测电表时自动获取电表常熟配置7880脉冲输出功能。
优化：
1. 去掉电表事件mib,节点和事件相关缓存信息，以省去内存空间。即网管不能直接读取事件数据，只能通过
   trap获取，所以网管可能需要做存储处理。
2. 优化切换检测电能表时自动配置7880过程。
3. 优化读表函数。
4. 去掉读表错误打印。
bug修复：
1. 修复rt_free(NULL)的bug。
2. 动态申请内存失败后，将相关的动态申请的内存释放掉。

====================================================================
light300-emc-s_0.5.2.20140515_Alpha_0
====================================================================
新增：
1. 7880数据：增加ABC
三项电压与电流间相位数据、增加铜损铁损数据（目前暂不支持，为无效值）、增加21
次谐波含量数据，包括ABC三相电压、电流和有功功率谐波含量。
2. 电表数据：
增加瞬时冻结数据，日月小时定时冻结数据、最大需量数据、增加铜损铁损数据、增加表内温度，时钟电池电压，抄表电池电压数据，其中相位和频率不支持为无效值。
增加21次谐波含量数据，包括ABC三相电压、电流谐波含量，其中有功功率谐波含量不支持为无效值。
3. PT、CT侧增加有功功率、功率因数、导纳、PTCT
侧温度值等数据。其中导纳由网管计算得出，底层不直接提供。PTCT
侧温度值暂不支持为无效值。
4. 增加事件trap信息，trap
信息是直接读表信息给网管，中间没有缓存和数据处理。所以编码方式是BCD
编码，字节数请按照645规约定义解析。
5. 增加MIB树支持node节点数,以及增加snmp request和response报文携带节点数。
6. 增加事件上传函数。
7. 解决波特率修改时不能正常配置7880问题。
8. 增加广播校时函数和设置冻结数据的时间函数。
9. 加入切换检测电表时自动获取电表常熟配置7880脉冲输出功能。
优化：
1. 去掉电表事件mib,节点和事件相关缓存信息，以省去内存空间。即网管不能直接读取事件数据，只能通过
   trap获取，所以网管可能需要做存储处理。
2. 优化切换检测电能表时自动配置7880过程。
3. 优化读表函数。
4. 去掉读表错误打印。
bug修复：
1. 修复rt_free(NULL)的bug。
2. 动态申请内存失败后，将相关的动态申请的内存释放掉。

====================================================================
light300-emm-m_0.5.1.20140513_Alpha_0
====================================================================
新增：
1. RS485长包数据传输。
2. TCP数据包分发。
3. 加入并优化LT-400EM侧12路通道自动调试
4. 加入1~63次谐波分析原始数据的获取
5. 加入切换检测电表时自动获取电表常数用以配置7880脉冲输出功能

优化：

bug修复：

====================================================================
light300-emm-s_0.5.1.20140513_Alpha_0
====================================================================
新增：
1. TCP数据包接收。
2. 加入并优化LT-400EM侧12路通道自动调试
3. 加入1~63次谐波分析原始数据的获取
4. 加入切换检测电表时自动获取电表常数用以配置7880脉冲输出功能

优化：

bug修复：
====================================================================
light300-emc-m_0.5.1.20140513_Alpha_0
====================================================================
新增：
1. RS485长包数据传输。
2. TCP数据包分发。
3. 加入1~63次谐波分析原始数据的获取
4. 加入切换检测电表时自动获取电表常数用以配置7880脉冲输出功能

优化：

bug修复：
====================================================================
light300-emc-s_0.5.1.20140513_Alpha_0
====================================================================
新增：
1. TCP数据包接收。
2. 加入1~63次谐波分析原始数据的获取
3. 加入切换检测电表时自动获取电表常数用以配置7880脉冲输出功能

优化：

bug修复：


====================================================================
light300-emm-m_0.5.0.20140430_Alpha_0
====================================================================
该版本是新light300系统的emm-m的第一个版本。


该版本主要功能如下：
1、emm采集器最多可以注册12个电表，系统会周期性的依次采集这些注册电表以及其对应的pt、ct的数据。
2、可以自动完成12路电表对应的ade7880参数的设置。
3、可以使用emm-m的shell接口，通过485总线与多个无线主节点（最多4个无线主节点）交互，完成无线的半自动组网。
4、emm-m设备会在内存中缓存所有采集数据，网管通过mib获取采集数据时，就是从该缓冲区中取数据。


该版本的缺陷：
1、没有实现将其他emm-s对应的pt、ct数据的分发。
2、mib接口没有更新。
3、645的新代码未合入，不能支持645-2007。
4、不能完成大于256字节的485长包传输。
5、半自动无线组网会出现失败的情形。
6、没有完成仔细的自测，软件中可能存在低级问题。
7、代码混乱，需要重新整理并重新实现部分软件模块。
8、ade7880在没有信号时，线程会死掉。




==============================================================================================================
==============================================================================================================
==============================================================================================================
==============================================================================================================





====================================================================
light300-emc_0.1.9.20131120_Alpha_0
====================================================================
新增：


优化：


bug修复：
1、解决7880电压、电流波形采样数据反相问题


====================================================================
light300-emc_0.1.8.20131118_Alpha_0
====================================================================
新增：
1、加入无功电能精度的调整参数

优化：
1、整理代码，以便硬件改动时，快速调整软件（外部中断及优先级, spi口的定义等, 集中到app-hw-resource.h中）

bug修复：
1、更正7880采集数据的符号



====================================================================
light300-emc_0.1.7.20131115_Alpha_0
====================================================================
新增：
1、测试电表的有功、无功电能输出脉冲周期与ade7880的有功、无功电能输出脉冲周期的相对误差。设t1表示电表的有功脉冲周期、t2表示ade7880的有功脉冲周期，那么，测到的相对误差是(t1-t2)*1000/t2,也就是说得到的是千分数。

注意相关中断引脚的连接：
en28j60的中断引脚	-- PB1
电表有功脉冲		-- PB8
电表无功脉冲		-- PB9
ade7880有功脉冲		-- PA11
ade7880无功脉冲		-- PA12


优化：


bug修复：



====================================================================
light300-emc_0.1.6.20131112_Alpha_0
====================================================================
新增：
1、增加测量外部脉冲周期的程序，误差可以控制在10us内。
2、加入调式CFx管脚分频器系数功能。

优化：


bug修复：
1、电表数据一bcd码存储在内存中，直接以16进制形式打印。
2、采集数据失败时，将数据置为0.


====================================================================
light300-emc_0.1.5.20131103_Alpha_0
====================================================================
新增：
1、定义系统故障、缺相的led灯


优化：
1、两轮数据更新的时间间隔修改为70ms


bug修复：
1、解决更新版本后，数据库中的版本没有更新的问题
2、解决7880获取数据失败时，数据异常的问题
3、mib重新修改字节序问题，已修改，读取电压电流值正确。



====================================================================
light300-emc_0.1.4.20131103_Alpha_0
====================================================================
新增：


优化：
1、si4432主节点过滤重复的设备类型与主节点关联。
2、电压、电流采样的一个点的数据传输3字节。


bug修复：
1、7880未能获取无功功率、有功电能、无功电能，所以使用电表中的数据。
2、7880未能获取电压、电流失真，传输的值的二进制位全是1。
3、将电表中的bcd数据转化为十进制数。
4、修改mib中数据读取字节序，使计量数据和电表数据读取正确。
5、修改mib中电表表号读取错误问题。




====================================================================
light300-emc_0.1.3.20131101_Alpha_0
====================================================================
新增：


优化：


bug修复：
1、将等待si4432线程8应答的超时时间从1s改为4s，这样可以避免主节点在发送信标帧时，命令覆盖的问题。
2、ade7880在初始化时没有设置，功率增益xPGAIN寄存器，功率偏移xWATTOS寄存器，总有功功率比较输出WTHR寄存器的问题。


====================================================================
light300-emc_0.1.2.20131101_Alpha_0
====================================================================
新增：
1. 增加视在功率，频率，采样值mib接口
2、调试参数接口函数中加入调试ade7880的功率增益xPGAIN寄存器，功率偏移xWATTOS寄存器，电压偏移xVRMSOS寄存器,电流偏移xIRMSOS寄存器，总有功功率比较输出WTHR寄存器的功能。


优化：
1、去掉采样点数据占用内存程序，防止mibbrowser获取失败。


bug修复：
1、修改mib索引获取错误问题。
2. 修改表格索引，使索引与表格对应正确。
3、明确指定ade7880工作在三相四线制模式。



====================================================================
light300-emc_0.1.1.20131031_Alpha_0
====================================================================
新增：
1、增加获取表号以及3种设备的sn号的mib接口代码。
2、添加调整7880功率、总有功功率的参数的接口函数（在快速启动7880时，在启动dsp后，再修改dsp的增益寄存器）。
3、为设置无线si4432同步字提供函数接口（同步字修改后，重启生效）。
4、增加获取表号的接口函数。


优化：
1、代码整理
2、消除si4432中可能出现的死等代码。
3、update线程连续读取数据时，中间延迟30ms。
4、read_ammeter_data只读一次，读数据失败时的处理交给上层软件。
5、si4432执行完状态机后，要延迟90ms，以防si44323异常时，导致低优先级任务无法运行。
5、修改ade7880接口函数，可以防止获取数据失败时，记录错误数据。
7、mib代码修改，使用同一个接口函数获取各种sn号。

bug修复：
1、增加信号量，解决SI4432通信中遇到收发对应不上问题。
2、修改si4432线程的工作机制，以防si4432线程一直占用CPU。
3、修改数据库bug。
4、在tcpip初始化之前，初始化sisinkifno的相关信号量。
5、将si_rxd消息邮箱的等待时间从永远等待改为等待一定时间，并对超时进行相应的处理（si4432）。
6、si4432 mailbox name缩短。
7、当电表返通过485接口返回数据时，不能正确处理前导字节的问题。



====================================================================
light300-emc_0.1.0.20131025_Alpha_0
====================================================================
主要功能概述如下：
1、操作系统使用rt-thread-v1.0.4。
2、支持文件系统，片外spi-flash为W25X40BV(4M-bit)。
3、支持RTC功能。
4、具有网口，通过snmp将需要的数据传输至网管。
5、使用485接口可以从遵守645规约的电表中读取以下数据：电压、电流、有功功率、无功功率、功率因数、总有功电能、总无功电能。
6、用ade7880可以读取电表侧的以下信息：电压、电流、频率、相位、有功功率、视在功率、功率因数、电压失真、电流失真、电压波形采样、电流波形采样。
7、通过si4432可以使用无线传输以下数据：PT负荷（视在功率）、CT负荷（视在功率）、PT副边电压。

